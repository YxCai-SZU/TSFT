"""Command-line interfaces for single-file and recursive evaluation."""

from __future__ import annotations

import argparse
import json
from pathlib import Path
from typing import Sequence

from .batch import run_multifile_workflow
from .constants import _DEFAULT_MAX_INPUT_TOKENS, _DEFAULT_MAX_NEW_TOKENS
from .workflow import run_evaluation_workflow


SINGLE_DESCRIPTION = """Build a stable, bottom-up subtask sequence for one C evaluation file.

The project already has the Clang AST collector in :mod:`Clang`.  This module
keeps the first evaluation-pipeline step deliberately independent from model
inference and ACSL insertion: it turns that analysis into a dependency graph
whose task identifiers do not contain source line numbers.

The public entry points are :func:`build_subtask_sequence` and
:func:`build_task_prompt`, plus the prompt-only generation and Frama-C
verification helpers used by the evaluation control flow.
"""

BATCH_DESCRIPTION = """Recursive batch driver for the single-file evaluation pipeline.

This wrapper discovers ``.c`` files under one input directory and invokes the
existing single-file workflow once per source file.  Each source file gets its
own output directory under ``--outputdir``:

``outputdir/<relative-parent>/<filename>/``

The single-file workflow then writes its usual ``xxx_temp.c`` and ``StepN``
artifacts inside that per-file directory.
"""


def _add_model_and_runtime_arguments(
    parser: argparse.ArgumentParser,
    *,
    required_paths: bool,
    frama_c_help: str,
) -> None:
    """Add the options shared by both legacy evaluation commands."""

    parser.add_argument(
        "--modeldir",
        type=Path,
        required=required_paths,
        help="base model directory",
    )
    parser.add_argument(
        "--adapterdir",
        type=Path,
        default=None,
        help="optional LoRA adapter directory",
    )
    parser.add_argument(
        "--outputdir",
        type=Path,
        required=required_paths,
        help=(
            "output directory for batch artifacts"
            if required_paths
            else "output directory for evaluation artifacts"
        ),
    )
    parser.add_argument(
        "--attempts",
        "--max-attempts-per-task",
        dest="max_attempts_per_task",
        type=int,
        default=1,
        help="max generation attempts per task",
    )
    parser.add_argument(
        "--harness-policy",
        default="entrypoint_names",
        help=(
            "harness filtering policy: none, entrypoint_names, or all_functions "
            "(default: entrypoint_names)"
        ),
    )
    parser.add_argument(
        "--harness",
        dest="harness_patterns",
        action="append",
        default=[],
        help="additional harness glob (repeatable)",
    )
    parser.add_argument("--clang", help="optional clang executable")
    parser.add_argument(
        "--clang-arg",
        dest="clang_arguments",
        action="append",
        default=[],
        help="extra argument passed to clang",
    )
    parser.add_argument(
        "--frama-c-executable",
        default="frama-c",
        help=frama_c_help,
    )
    parser.add_argument(
        "--frama-c-provers",
        default="alt-ergo,z3",
        help="comma-separated WP prover list",
    )
    parser.add_argument(
        "--frama-c-wp-timeout",
        type=int,
        default=30,
        help="WP timeout in seconds",
    )
    parser.add_argument(
        "--frama-c-process-timeout",
        type=float,
        default=120.0,
        help="process timeout for each Frama-C call",
    )
    parser.add_argument(
        "--trust-remote-code",
        action="store_true",
        help="allow transformers trust_remote_code",
    )
    parser.add_argument(
        "--compute-dtype",
        default="bfloat16",
        help="compute dtype for model loading",
    )
    parser.add_argument(
        "--max-new-tokens",
        type=int,
        default=_DEFAULT_MAX_NEW_TOKENS,
        help=(
            "maximum generated tokens per attempt, including hidden thinking "
            f"(default: {_DEFAULT_MAX_NEW_TOKENS})"
        ),
    )
    thinking_group = parser.add_mutually_exclusive_group()
    thinking_group.add_argument(
        "--enable-thinking",
        dest="enable_thinking",
        action="store_true",
        help="enable Qwen hidden reasoning and keep only the final answer",
    )
    thinking_group.add_argument(
        "--disable-thinking",
        dest="enable_thinking",
        action="store_false",
        help="disable Qwen hidden reasoning",
    )
    parser.set_defaults(enable_thinking=True)

    sampling_group = parser.add_mutually_exclusive_group()
    sampling_group.add_argument(
        "--do-sample",
        dest="do_sample",
        action="store_true",
        help="enable sampling during generation",
    )
    sampling_group.add_argument(
        "--no-do-sample",
        dest="do_sample",
        action="store_false",
        help="disable sampling during generation",
    )
    parser.set_defaults(do_sample=None)
    parser.add_argument(
        "--num-beams",
        type=int,
        default=1,
        help="beam count for generation",
    )
    parser.add_argument(
        "--repetition-penalty",
        type=float,
        default=1.05,
        help="repetition penalty for generation",
    )
    parser.add_argument(
        "--max-input-tokens",
        type=int,
        default=_DEFAULT_MAX_INPUT_TOKENS,
        help=(
            "maximum prompt input tokens; output tokens are configured "
            f"separately (default: {_DEFAULT_MAX_INPUT_TOKENS})"
        ),
    )


def single_file_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description=SINGLE_DESCRIPTION)
    parser.add_argument(
        "--file",
        dest="file",
        type=Path,
        required=False,
        help="one C source file",
    )
    parser.add_argument("c_file", nargs="?", type=Path, help=argparse.SUPPRESS)
    _add_model_and_runtime_arguments(
        parser,
        required_paths=False,
        frama_c_help="Frama-C executable to invoke",
    )
    return parser


def multifile_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(description=BATCH_DESCRIPTION)
    parser.add_argument(
        "--file",
        dest="file",
        type=Path,
        required=True,
        help="input directory that contains one or more C files",
    )
    _add_model_and_runtime_arguments(
        parser,
        required_paths=True,
        frama_c_help=(
            "Frama-C executable to invoke; a bare frama-c prefers the "
            "project-local frama-c-setup/bin launcher, then PATH"
        ),
    )
    return parser


def _workflow_arguments(args: argparse.Namespace) -> dict[str, object]:
    """Translate the unchanged CLI namespace into workflow keyword arguments."""

    return {
        "modeldir": args.modeldir,
        "adapterdir": args.adapterdir,
        "outputdir": args.outputdir,
        "max_attempts_per_task": args.max_attempts_per_task,
        "harness_policy": args.harness_policy,
        "harness_patterns": args.harness_patterns,
        "clang": args.clang,
        "clang_arguments": args.clang_arguments,
        "frama_c_executable": args.frama_c_executable,
        "frama_c_provers": args.frama_c_provers,
        "frama_c_wp_timeout": args.frama_c_wp_timeout,
        "frama_c_process_timeout": args.frama_c_process_timeout,
        "trust_remote_code": args.trust_remote_code,
        "compute_dtype": args.compute_dtype,
        "max_new_tokens": args.max_new_tokens,
        "do_sample": args.do_sample,
        "num_beams": args.num_beams,
        "repetition_penalty": args.repetition_penalty,
        "chat_template_kwargs": {"enable_thinking": args.enable_thinking},
        "max_input_tokens": args.max_input_tokens,
    }


def _single_summary(result: dict[str, object]) -> dict[str, object]:
    generation = result.get("generation")
    generation = generation if isinstance(generation, dict) else {}
    work_root = result.get("work_root")
    return {
        "status": result.get("status"),
        "source_file": result.get("source_file"),
        "work_root": work_root,
        "max_input_tokens": generation.get("max_input_tokens"),
        "max_new_tokens": generation.get("max_new_tokens"),
        "tasks_completed": result.get("tasks_completed"),
        "tasks_total": result.get("tasks_total"),
        "failed_task_id": result.get("failed_task_id"),
        "failure_reason": result.get("failure_reason"),
        "total_attempts": result.get("total_attempts"),
        "total_attempt_seconds": result.get("total_attempt_seconds"),
        "total_token_cost": result.get("total_token_cost"),
        "average_attempt_seconds": result.get("average_attempt_seconds"),
        "average_token_cost_per_attempt": result.get(
            "average_token_cost_per_attempt"
        ),
        "total_time_seconds": result.get("total_time_seconds"),
        "final_result_file": (
            None if work_root is None else str(Path(str(work_root)) / "final_result.json")
        ),
    }


def _batch_summary(report: dict[str, object]) -> dict[str, object]:
    keys = (
        "status",
        "input_root",
        "output_root",
        "attempts",
        "max_input_tokens",
        "max_new_tokens",
        "samples_total",
        "samples_passed",
        "sample_pass_rate",
        "subtasks_total",
        "function_tasks_total",
        "loop_tasks_total",
        "function_tasks_passed",
        "loop_tasks_passed",
        "function_task_pass_rate",
        "loop_task_pass_rate",
        "total_input_token_cost",
        "total_output_token_cost",
        "total_solve_time_seconds",
        "average_sample_input_token_cost",
        "average_sample_output_token_cost",
        "average_sample_token_cost",
        "average_sample_solve_time_seconds",
        "average_subtask_input_token_cost",
        "average_subtask_output_token_cost",
        "average_subtask_token_cost",
        "average_subtask_solve_time_seconds",
        "files_total",
        "files_succeeded",
        "files_failed",
        "tasks_total",
        "tasks_completed",
        "total_attempts",
        "total_attempt_seconds",
        "total_token_cost",
        "average_attempt_seconds",
        "average_token_cost_per_attempt",
        "total_time_seconds",
    )
    summary = {key: report.get(key) for key in keys}
    summary["batch_result_file"] = str(
        Path(str(report["output_root"])) / "batch_result.json"
    )
    return summary


def single_main(argv: Sequence[str] | None = None) -> int:
    parser = single_file_parser()
    args = parser.parse_args(argv)
    source_file = args.file or args.c_file
    if source_file is None:
        parser.error("--file is required")
    if args.modeldir is None:
        parser.error("--modeldir is required")
    if args.outputdir is None:
        parser.error("--outputdir is required")

    result = run_evaluation_workflow(file=source_file, **_workflow_arguments(args))
    print(json.dumps(_single_summary(result), ensure_ascii=False, indent=2))
    return 0 if result.get("status") == "success" else 1


def multifile_main(argv: Sequence[str] | None = None) -> int:
    args = multifile_parser().parse_args(argv)
    report = run_multifile_workflow(file=args.file, **_workflow_arguments(args))
    print(json.dumps(_batch_summary(report), ensure_ascii=False, indent=2))
    return 0 if report["status"] == "success" else 1
