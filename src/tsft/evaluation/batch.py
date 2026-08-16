"""Recursive multi-file evaluation and aggregate reporting."""

from __future__ import annotations

import time
from pathlib import Path
from typing import Any, Sequence

from .constants import (
    EvaluationPipelineError,
    _DEFAULT_MAX_INPUT_TOKENS,
    _DEFAULT_MAX_NEW_TOKENS,
)
from .frama import _resolve_frama_c_executable
from .source_files import _atomic_write_json
from .workflow import run_evaluation_workflow


def _resolve_directory(path: str | Path, *, label: str) -> Path:
    resolved = Path(path).expanduser().resolve()
    if not resolved.exists():
        raise EvaluationPipelineError(f"{label} does not exist: {resolved}")
    if not resolved.is_dir():
        raise EvaluationPipelineError(f"{label} must be a directory: {resolved}")
    return resolved


def _discover_c_sources(
    input_root: Path,
    *,
    exclude_root: Path | None = None,
) -> list[Path]:
    candidates = sorted(
        input_root.rglob("*.c"),
        key=lambda path: path.relative_to(input_root).as_posix().casefold(),
    )
    sources: list[Path] = []
    for candidate in candidates:
        if not candidate.is_file():
            continue
        if exclude_root is not None:
            try:
                candidate.relative_to(exclude_root)
            except ValueError:
                pass
            else:
                continue
        sources.append(candidate)
    return sources


def _file_output_root(
    output_root: Path,
    input_root: Path,
    source: Path,
) -> Path:
    relative = source.relative_to(input_root)
    return output_root / relative.parent / source.name


def _file_report_summary(
    *,
    source: Path,
    relative_source: Path,
    work_root: Path,
    report: dict[str, Any],
) -> dict[str, Any]:
    metrics = _summarize_sample_report(report)
    return {
        "source_file": str(source),
        "relative_source_file": relative_source.as_posix(),
        "work_root": str(work_root),
        "status": report.get("status"),
        "tasks_completed": report.get("tasks_completed"),
        "tasks_total": report.get("tasks_total"),
        "failed_task_id": report.get("failed_task_id"),
        "failure_reason": report.get("failure_reason"),
        "sample_passed": metrics["passed"],
        "total_attempts": report.get("total_attempts"),
        "subtasks_total": metrics["tasks_total"],
        "function_tasks_total": metrics["function_tasks"],
        "loop_tasks_total": metrics["loop_tasks"],
        "function_tasks_passed": metrics["function_passed"],
        "loop_tasks_passed": metrics["loop_passed"],
        "input_token_cost": metrics["input_token_cost"],
        "output_token_cost": metrics["output_token_cost"],
        "total_token_cost": metrics["total_token_cost"],
        "solve_time_seconds": metrics["solve_time_seconds"],
        "total_time_seconds": report.get("total_time_seconds"),
        "final_result_file": str(work_root / "final_result.json"),
    }


def _nonnegative_int(value: Any) -> int:
    try:
        number = int(value or 0)
    except (TypeError, ValueError):
        return 0
    return max(number, 0)


def _nonnegative_float(value: Any) -> float:
    try:
        number = float(value or 0.0)
    except (TypeError, ValueError):
        return 0.0
    return max(number, 0.0)


def _rate(passed: int, total: int) -> float:
    return round(passed / total, 8) if total else 0.0


def _average(total: int | float, count: int) -> float:
    return round(float(total) / count, 3) if count else 0.0


def _summarize_sample_report(report: dict[str, Any]) -> dict[str, Any]:
    """Extract sample-level and task-type metrics from one workflow report."""

    task_graph = report.get("task_graph")
    statistics = task_graph.get("statistics", {}) if isinstance(task_graph, dict) else {}
    steps = report.get("steps")
    steps = steps if isinstance(steps, list) else []

    function_tasks = _nonnegative_int(statistics.get("function_tasks"))
    loop_tasks = _nonnegative_int(statistics.get("loop_tasks"))
    if not function_tasks and not loop_tasks:
        for step in steps:
            if not isinstance(step, dict):
                continue
            task_type = step.get("task_type")
            if task_type == "function":
                function_tasks += 1
            elif task_type == "loop":
                loop_tasks += 1

    function_passed = 0
    loop_passed = 0
    for step in steps:
        if not isinstance(step, dict):
            continue
        if step.get("status") != "passed":
            continue
        task_type = step.get("task_type")
        if task_type == "function":
            function_passed += 1
        elif task_type == "loop":
            loop_passed += 1

    input_token_cost = _nonnegative_int(
        report.get("input_token_cost", report.get("total_prompt_tokens"))
    )
    output_token_cost = _nonnegative_int(
        report.get("output_token_cost", report.get("total_completion_tokens"))
    )
    total_token_cost = _nonnegative_int(
        report.get("total_token_cost", input_token_cost + output_token_cost)
    )
    # ``total_time_seconds`` is the complete per-sample workflow duration,
    # which is the sample-level solve time used by the batch summary.
    solve_time_seconds = _nonnegative_float(
        report.get("total_time_seconds", report.get("total_attempt_seconds"))
    )
    tasks_total = _nonnegative_int(
        report.get("tasks_total", function_tasks + loop_tasks)
    )
    return {
        "passed": report.get("status") == "success",
        "tasks_total": tasks_total,
        "function_tasks": function_tasks,
        "loop_tasks": loop_tasks,
        "function_passed": function_passed,
        "loop_passed": loop_passed,
        "input_token_cost": input_token_cost,
        "output_token_cost": output_token_cost,
        "total_token_cost": total_token_cost,
        "solve_time_seconds": solve_time_seconds,
    }


def run_multifile_workflow(
    *,
    file: str | Path,
    modeldir: str | Path,
    outputdir: str | Path,
    adapterdir: str | Path | None = None,
    max_attempts_per_task: int = 1,
    harness_policy: str | None = "entrypoint_names",
    harness_patterns: Sequence[str] = (),
    clang: str | Path | None = None,
    clang_arguments: Sequence[str] = (),
    clang_timeout: float | None = 20.0,
    frama_c_executable: str | Path = "frama-c",
    frama_c_provers: str = "alt-ergo,z3",
    frama_c_wp_timeout: int = 30,
    frama_c_process_timeout: float = 120.0,
    trust_remote_code: bool = False,
    compute_dtype: str = "bfloat16",
    max_new_tokens: int = _DEFAULT_MAX_NEW_TOKENS,
    do_sample: bool | None = None,
    num_beams: int = 1,
    repetition_penalty: float = 1.05,
    chat_template_kwargs: dict[str, Any] | None = None,
    max_input_tokens: int | None = _DEFAULT_MAX_INPUT_TOKENS,
) -> dict[str, Any]:
    """Run the evaluation workflow for every ``.c`` file under one directory."""

    started = time.monotonic()
    input_root = _resolve_directory(file, label="--file")
    output_root = Path(outputdir).expanduser().resolve()
    output_root.mkdir(parents=True, exist_ok=True)
    frama_c_executable = _resolve_frama_c_executable(frama_c_executable)

    sources = _discover_c_sources(input_root, exclude_root=output_root)
    if not sources:
        raise EvaluationPipelineError(f"No .c files were found under {input_root}")

    file_reports: list[dict[str, Any]] = []
    total_tasks = 0
    total_completed = 0
    total_attempts = 0
    total_prompt_tokens = 0
    total_prompt_tokens_raw = 0
    total_completion_tokens = 0
    total_token_cost = 0
    total_solve_time_seconds = 0.0
    total_function_tasks = 0
    total_loop_tasks = 0
    total_function_tasks_passed = 0
    total_loop_tasks_passed = 0
    success_count = 0
    failure_count = 0

    for index, source in enumerate(sources, start=1):
        relative_source = source.relative_to(input_root)
        work_root = _file_output_root(output_root, input_root, source)
        work_root.mkdir(parents=True, exist_ok=True)
        print(
            f"[{index}/{len(sources)}] {relative_source.as_posix()} -> {work_root}",
            flush=True,
        )

        try:
            report = run_evaluation_workflow(
                file=source,
                modeldir=modeldir,
                outputdir=work_root,
                work_root=work_root,
                adapterdir=adapterdir,
                max_attempts_per_task=max_attempts_per_task,
                harness_policy=harness_policy,
                harness_patterns=harness_patterns,
                clang=clang,
                clang_arguments=clang_arguments,
                clang_timeout=clang_timeout,
                frama_c_executable=frama_c_executable,
                frama_c_provers=frama_c_provers,
                frama_c_wp_timeout=frama_c_wp_timeout,
                frama_c_process_timeout=frama_c_process_timeout,
                trust_remote_code=trust_remote_code,
                compute_dtype=compute_dtype,
                max_new_tokens=max_new_tokens,
                do_sample=do_sample,
                num_beams=num_beams,
                repetition_penalty=repetition_penalty,
                chat_template_kwargs=chat_template_kwargs,
                max_input_tokens=max_input_tokens,
            )
        except Exception as exc:
            report = {
                "status": "fail",
                "source_file": str(source),
                "work_root": str(work_root),
                "failed_task_id": None,
                "failure_reason": f"{type(exc).__name__}: {exc}",
                "tasks_total": None,
                "tasks_completed": None,
                "total_attempts": None,
                "total_token_cost": None,
                "total_time_seconds": None,
                "fatal_error": f"{type(exc).__name__}: {exc}",
            }

        file_report = _file_report_summary(
            source=source,
            relative_source=relative_source,
            work_root=work_root,
            report=report,
        )
        file_reports.append(file_report)

        sample_metrics = _summarize_sample_report(report)

        status = report.get("status")
        if status == "success":
            success_count += 1
        else:
            failure_count += 1

        total_tasks += int(sample_metrics["tasks_total"])
        total_completed += int(report.get("tasks_completed") or 0)
        total_attempts += int(report.get("total_attempts") or 0)
        total_prompt_tokens += int(sample_metrics["input_token_cost"])
        total_prompt_tokens_raw += int(report.get("total_prompt_tokens_raw") or 0)
        total_completion_tokens += int(sample_metrics["output_token_cost"])
        total_token_cost += int(sample_metrics["total_token_cost"])
        total_solve_time_seconds += float(sample_metrics["solve_time_seconds"])
        total_function_tasks += int(sample_metrics["function_tasks"])
        total_loop_tasks += int(sample_metrics["loop_tasks"])
        total_function_tasks_passed += int(sample_metrics["function_passed"])
        total_loop_tasks_passed += int(sample_metrics["loop_passed"])

    if failure_count == 0:
        batch_status = "success"
    elif success_count == 0:
        batch_status = "fail"
    else:
        batch_status = "partial"

    batch_report = {
        "status": batch_status,
        "input_root": str(input_root),
        "output_root": str(output_root),
        "modeldir": str(modeldir),
        "adapterdir": None if adapterdir is None else str(adapterdir),
        "attempts": max_attempts_per_task,
        "max_attempts_per_task": max_attempts_per_task,
        "max_input_tokens": max_input_tokens,
        "max_new_tokens": max_new_tokens,
        "samples_total": len(sources),
        "samples_passed": success_count,
        "samples_failed": failure_count,
        "sample_pass_rate": _rate(success_count, len(sources)),
        "subtasks_total": total_tasks,
        "subtasks_passed": total_completed,
        "subtask_pass_rate": _rate(total_completed, total_tasks),
        "function_tasks_total": total_function_tasks,
        "function_contract_tasks_total": total_function_tasks,
        "loop_tasks_total": total_loop_tasks,
        "function_tasks_passed": total_function_tasks_passed,
        "function_contract_tasks_passed": total_function_tasks_passed,
        "loop_tasks_passed": total_loop_tasks_passed,
        "function_task_pass_rate": _rate(
            total_function_tasks_passed, total_function_tasks
        ),
        "function_contract_task_pass_rate": _rate(
            total_function_tasks_passed, total_function_tasks
        ),
        "loop_task_pass_rate": _rate(total_loop_tasks_passed, total_loop_tasks),
        "total_input_token_cost": total_prompt_tokens,
        "total_output_token_cost": total_completion_tokens,
        "total_solve_time_seconds": round(total_solve_time_seconds, 3),
        "average_sample_input_token_cost": _average(total_prompt_tokens, len(sources)),
        "average_sample_output_token_cost": _average(
            total_completion_tokens, len(sources)
        ),
        "average_sample_token_cost": _average(total_token_cost, len(sources)),
        "average_sample_total_token_cost": _average(
            total_token_cost, len(sources)
        ),
        "average_sample_solve_time_seconds": _average(
            total_solve_time_seconds, len(sources)
        ),
        "average_subtask_input_token_cost": _average(
            total_prompt_tokens, total_tasks
        ),
        "average_subtask_output_token_cost": _average(
            total_completion_tokens, total_tasks
        ),
        "average_subtask_token_cost": _average(total_token_cost, total_tasks),
        "average_subtask_total_token_cost": _average(
            total_token_cost, total_tasks
        ),
        "average_subtask_solve_time_seconds": _average(
            total_solve_time_seconds, total_tasks
        ),
        "files_total": len(sources),
        "files_succeeded": success_count,
        "files_failed": failure_count,
        "tasks_total": total_tasks,
        "tasks_completed": total_completed,
        "total_attempts": total_attempts,
        "total_prompt_tokens": total_prompt_tokens,
        "total_prompt_tokens_raw": total_prompt_tokens_raw,
        "total_completion_tokens": total_completion_tokens,
        "total_token_cost": total_token_cost,
        "total_time_seconds": round(time.monotonic() - started, 3),
        "files": file_reports,
    }
    _atomic_write_json(output_root / "batch_result.json", batch_report)
    return batch_report
