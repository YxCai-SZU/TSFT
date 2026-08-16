"""Per-task ACSL insertion, Frama-C/WP verification, and artifacts."""

from __future__ import annotations

from pathlib import Path
from typing import Any, Sequence

from Clang import AnalysisResult

from .analysis import _analyze_one_c_file
from .constants import EvaluationPipelineError
from .frama import _frama_c_wp_command, _resolve_frama_c_executable, _run_command
from .prompts import _SingleTaskPromptBuilder
from .source_files import (
    _atomic_write_json,
    _atomic_write_text,
    _create_task_verification_c_file,
    _resolve_existing_c_file,
    _task_file_slug,
    _write_json_artifact,
)
from .tasks import _task_record, _verification_reason


def verify_task_output(
    task_graph: dict[str, Any],
    task_id: str,
    model_output: str,
    *,
    current_c_file: str | Path | None = None,
    clang: str | Path | None = None,
    clang_arguments: Sequence[str] = (),
    clang_timeout: float | None = 20.0,
    analysis: AnalysisResult | None = None,
    frama_c_executable: str | Path = "frama-c",
    frama_c_provers: str = "alt-ergo,z3",
    frama_c_wp_timeout: int = 30,
    frama_c_process_timeout: float = 120.0,
    log_output_dir: str | Path | None = None,
) -> dict[str, Any]:
    """Verify one model-generated ACSL block against the current task.

    The input source is the current temporary working copy, e.g. ``1_temp.c``.
    The function re-analyzes that file, locates ``task_id`` by the stable task
    graph locator, and extracts a bounded verification fragment directly from
    the latest working copy.  The generated contract is inserted immediately
    before the current task, while already verified nested-task contracts stay
    at their original positions.  Frama-C/WP runs only on that fragment and
    the ephemeral file is deleted afterwards.

    Frama-C is invoked with the requested WP settings by default:
    ``-wp -wp-prover alt-ergo,z3 -wp-timeout 30``.  Termination-oriented proof
    goals are excluded from the selected WP obligations.

    This function deliberately does not modify ``current_c_file``.  The later
    control flow can use ``verification_success`` plus the returned
    ``task_start`` insertion offset to decide whether to persist the contract
    into the working copy.
    """

    result: dict[str, Any] = {
        "task_id": task_id,
        "task_type": None,
        "task_record": None,
        "source_file": None,
        "source_prefix": None,
        "code_snippet": None,
        "existing_contract": None,
        "task_start": None,
        "task_end": None,
        "line_start": None,
        "verification_file": None,
        "verification_input": None,
        "verification_file_removed": False,
        "command": None,
        "returncode": None,
        "timeout": False,
        "seconds": None,
        "output": "",
        "full_output": "",
        "wp_summary": None,
        "frama_c_parse_success": False,
        "wp_all_goals_proved": False,
        "verification_success": False,
        "verification_reason": None,
        "error": None,
        "log_file": None,
    }
    verification_file: Path | None = None

    try:
        task_record = _task_record(task_graph, task_id)
        result["task_record"] = task_record

        source_value = current_c_file or task_graph.get("source_file")
        if source_value is None:
            raise EvaluationPipelineError(
                "current_c_file was not provided and task_graph has no source_file"
            )
        source = _resolve_existing_c_file(source_value)
        result["source_file"] = str(source)

        if analysis is None:
            analysis = _analyze_one_c_file(
                source,
                clang=clang,
                clang_arguments=clang_arguments,
                clang_timeout=clang_timeout,
            )
        source_parts = _SingleTaskPromptBuilder(
            task_graph,
            source,
            analysis,
            require_downstream_contracts=False,
        ).task_source_parts(task_id)

        target_type = source_parts["target_type"]
        if task_record.get("type") != target_type:
            raise EvaluationPipelineError(
                f"Task type mismatch for {task_id}: graph has "
                f"{task_record.get('type')!r}, current file has {target_type!r}"
            )
        result["task_type"] = target_type
        result["source_prefix"] = source_parts["source_prefix"]
        result["code_snippet"] = source_parts["code_snippet"]
        result["existing_contract"] = source_parts.get("existing_contract")
        result["task_start"] = source_parts["task_start"]
        result["task_end"] = source_parts["task_end"]
        result["line_start"] = source_parts["line_start"]

        verification_file = _create_task_verification_c_file(
            model_output,
            source_parts,
        )
        result["verification_file"] = str(verification_file)
        result["verification_input"] = verification_file.read_text(encoding="utf-8")

        command = _frama_c_wp_command(
            _resolve_frama_c_executable(frama_c_executable),
            verification_file,
            source.parent,
            wp_prover=frama_c_provers,
            wp_timeout=frama_c_wp_timeout,
            wp_function=str(task_record.get("function") or ""),
            exclude_termination_goals=True,
        )
        result["command"] = command
        command_result = _run_command(
            command,
            float(frama_c_process_timeout),
            source.parent,
        )
        result.update(command_result)

        wp_summary = command_result.get("wp_summary")
        reason = _verification_reason(command_result, wp_summary)
        result["verification_reason"] = reason
        result["frama_c_parse_success"] = bool(
            wp_summary
            or (command_result["returncode"] == 0 and not command_result["timeout"])
        )
        result["wp_all_goals_proved"] = reason is None
        result["verification_success"] = reason is None
    except (EvaluationPipelineError, OSError, TypeError, UnicodeError, ValueError) as exc:
        error_text = f"{type(exc).__name__}: {exc}"
        result["error"] = error_text
        # Preserve setup/IO failures in the same log consumed by
        # ``_attempt_summary``.  Previously this branch left ``full_output``
        # empty, producing a blank frama-c.log on remote hosts.
        if not result.get("output"):
            result["output"] = error_text
        if not result.get("full_output"):
            result["full_output"] = error_text
        result["verification_reason"] = "exception"
    finally:
        if verification_file is not None:
            try:
                verification_file.unlink(missing_ok=True)
                result["verification_file_removed"] = True
            except OSError as exc:
                result["cleanup_error"] = f"{type(exc).__name__}: {exc}"
        if log_output_dir is not None:
            try:
                log_path = _write_json_artifact(
                    log_output_dir,
                    f"{_task_file_slug(task_id)}-",
                    result,
                )
                result["log_file"] = str(log_path)
            except OSError as exc:
                result["log_write_error"] = f"{type(exc).__name__}: {exc}"

    return result


def _step_directory(work_root: str | Path, step_index: int) -> Path:
    return Path(work_root).expanduser().resolve() / f"Step{step_index}"


def _attempt_directory(step_directory: str | Path, attempt_index: int) -> Path:
    return Path(step_directory).expanduser().resolve() / f"attempt_{attempt_index:02d}"


def _step_file_name(source: Path) -> str:
    return f"{source.stem}_temp.c"


def _attempt_summary(
    *,
    step_index: int,
    attempt_index: int,
    prompt: str | None,
    model_output: str | None,
    generation: dict[str, Any] | None,
    verification: dict[str, Any] | None,
    merged_source_text: str | None,
    attempt_seconds: float,
    attempt_dir: Path,
) -> dict[str, Any]:
    generation_artifact: dict[str, Any] | None = None
    if generation is not None:
        generation_artifact = {
            "text": generation.get("text"),
            "input_token_count": generation.get("prompt_token_count"),
            "input_token_count_raw": generation.get("prompt_token_count_raw"),
            "output_token_count": generation.get("completion_token_count"),
            "total_token_count": generation.get("total_token_count"),
            "max_input_tokens": generation.get("max_input_tokens"),
            "max_new_tokens": generation.get("max_new_tokens"),
            "prompt_truncated": generation.get("prompt_truncated"),
        }
        if "step_seconds" in generation:
            generation_artifact["step_seconds"] = generation.get("step_seconds")

    verification_artifact: dict[str, Any] | None = None
    if verification is not None:
        wp_summary = verification.get("wp_summary")
        proved_goals = 0
        total_goals = 0
        if isinstance(wp_summary, dict):
            proved_goals = int(wp_summary.get("proved_goals") or 0)
            total_goals = int(wp_summary.get("total_goals") or 0)
        verification_artifact = {
            "command": verification.get("command"),
            "input_slice": verification.get("verification_input"),
            "proved_goals": proved_goals,
            "total_goals": total_goals,
            "result": "pass" if verification.get("verification_success") else "fail",
            "verification_seconds": verification.get("seconds"),
        }

    summary: dict[str, Any] = {
        "step_index": step_index,
        "attempt_index": attempt_index,
        "attempt_seconds": round(attempt_seconds, 3),
        "attempt_dir": str(attempt_dir),
        "prompt_file": None,
        "model_output_file": None,
        "merged_c_file": None,
        "generation_json": None,
        "verification_json": None,
        "verification_input_file": None,
        "frama_c_log": None,
        "prompt_token_count": None,
        "prompt_token_count_raw": None,
        "completion_token_count": None,
        "token_cost": None,
        "verification_success": False,
        "verification_reason": None,
        "frama_c_parse_success": False,
        "wp_all_goals_proved": False,
        "error": None,
    }

    if prompt is not None:
        prompt_path = attempt_dir / "prompt.txt"
        _atomic_write_text(prompt_path, prompt)
        summary["prompt_file"] = str(prompt_path)
    if model_output is not None:
        output_path = attempt_dir / "model_output.txt"
        _atomic_write_text(output_path, model_output.rstrip("\n") + "\n")
        summary["model_output_file"] = str(output_path)
    if merged_source_text is not None:
        merged_path = attempt_dir / "merged.c"
        _atomic_write_text(merged_path, merged_source_text)
        summary["merged_c_file"] = str(merged_path)
    if generation_artifact is not None:
        generation_path = attempt_dir / "generation.json"
        _atomic_write_json(generation_path, generation_artifact)
        summary["generation_json"] = str(generation_path)
        summary["prompt_token_count"] = generation.get("prompt_token_count")
        summary["prompt_token_count_raw"] = generation.get("prompt_token_count_raw")
        summary["completion_token_count"] = generation.get("completion_token_count")
        summary["token_cost"] = generation.get("total_token_count")
    if verification_artifact is not None:
        verification_input = verification.get("verification_input")
        if isinstance(verification_input, str):
            verification_input_path = attempt_dir / "verification_input.c"
            _atomic_write_text(verification_input_path, verification_input)
            summary["verification_input_file"] = str(verification_input_path)
        verification_path = attempt_dir / "verification.json"
        _atomic_write_json(verification_path, verification_artifact)
        summary["verification_json"] = str(verification_path)
        log_path = attempt_dir / "frama-c.log"
        _atomic_write_text(log_path, verification.get("full_output", ""))
        summary["frama_c_log"] = str(log_path)
        summary["verification_success"] = bool(verification.get("verification_success"))
        summary["verification_reason"] = verification.get("verification_reason")
        summary["frama_c_parse_success"] = bool(verification.get("frama_c_parse_success"))
        summary["wp_all_goals_proved"] = bool(verification.get("wp_all_goals_proved"))
    return summary
