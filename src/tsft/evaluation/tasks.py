"""Stable subtask graph construction and report compaction."""

from __future__ import annotations

from collections import defaultdict
from pathlib import Path
from typing import Any, Sequence

from tsft.training_data import SourceDocument as _PromptSourceDocument

from .constants import EvaluationPipelineError
from .prompts import _evaluation_background_spec
from .analysis import (
    _analyze_one_c_file,
    _function_task_id,
    _is_harness,
    _location_key,
    _loop_paths,
    _normalise_harness_policy,
    _schedule,
    _stable_loop_task_id,
)
from .source_files import _resolve_existing_c_file


def build_subtask_sequence(
    c_file: str | Path,
    *,
    harness_policy: str | None = "entrypoint_names",
    harness_patterns: Sequence[str] = (),
    clang: str | Path | None = None,
    clang_arguments: Sequence[str] = (),
    clang_timeout: float | None = 20.0,
) -> dict[str, Any]:
    """Analyze one C file and return its purified, bottom-up task sequence.

    ``harness_policy`` controls which function nodes are removed before
    scheduling.  In addition to the explicit policy, OOPSLA/SyGuS benchmark
    directories use loop-only scheduling under the default
    ``entrypoint_names`` policy.  ``none`` keeps every function and
    ``all_functions`` removes every function task while keeping loop tasks.
    The result contains no line-number-based task id; current source locations
    are intentionally left to the later extraction step.
    """

    source = _resolve_existing_c_file(c_file)
    normalized_policy = _normalise_harness_policy(harness_policy)
    analysis = _analyze_one_c_file(
        source,
        clang=clang,
        clang_arguments=clang_arguments,
        clang_timeout=clang_timeout,
    )
    source_background_spec = _evaluation_background_spec(
        _PromptSourceDocument(source.name, source)
    )

    functions = {function.id: function for function in analysis.functions}
    loops = {loop.id: loop for loop in analysis.loops}
    loop_paths = _loop_paths(analysis)
    stable_function_ids = {
        function_id: _function_task_id(function)
        for function_id, function in functions.items()
    }
    stable_loop_ids = {
        loop_id: _stable_loop_task_id(
            functions[loop.function_id], loop, loop_paths[loop_id]
        )
        for loop_id, loop in loops.items()
    }

    harnesses: list[dict[str, Any]] = []
    harness_function_ids: set[str] = set()
    for function in sorted(analysis.functions, key=_location_key):
        is_harness, reason = _is_harness(
            function,
            harness_policy=normalized_policy,
            source=source,
            patterns=harness_patterns,
        )
        if is_harness:
            harness_function_ids.add(function.id)
            harnesses.append(
                {
                    "function": function.name,
                    "locator": {"kind": "function", "name": function.name},
                    "reason": reason,
                }
            )

    task_records: dict[str, dict[str, Any]] = {}
    task_ids: set[str] = set()
    source_order: dict[str, tuple[int, int, int, str]] = {}
    dependencies: dict[str, set[str]] = defaultdict(set)
    calls_by_id = {call.id: call for call in analysis.calls}

    for function in sorted(analysis.functions, key=_location_key):
        if function.id in harness_function_ids:
            continue
        task_id = stable_function_ids[function.id]
        task_ids.add(task_id)
        task_records[task_id] = {
            "task_id": task_id,
            "type": "function",
            "function": function.name,
            "line_start": function.location.line,
            "locator": {"kind": "function", "name": function.name},
            "depends_on": [],
            "order": None,
            "stage": None,
            "cycle_group": None,
        }
        source_order[task_id] = (*_location_key(function), task_id)

    for loop in sorted(analysis.loops, key=_location_key):
        function = functions[loop.function_id]
        task_id = stable_loop_ids[loop.id]
        task_ids.add(task_id)
        task_records[task_id] = {
            "task_id": task_id,
            "type": "loop",
            "function": function.name,
            "loop_kind": loop.kind,
            "line_start": loop.location.line,
            "locator": {
                "kind": "loop",
                "function": function.name,
                "path": list(loop_paths[loop.id]),
                "loop_kind": loop.kind,
            },
            "depends_on": [],
            "order": None,
            "stage": None,
            "cycle_group": None,
        }
        source_order[task_id] = (*_location_key(loop), task_id)

    # Function contracts follow every directly used function and their own
    # outermost loops.  A loop follows direct calls made in that loop and all
    # of its lexical child loops.  Harness functions have no task id, but loops
    # in a harness remain visible and can still depend on normal callees.
    for function in analysis.functions:
        if function.id in harness_function_ids:
            continue
        task_id = stable_function_ids[function.id]
        for callee_id in function.callee_ids:
            if callee_id in stable_function_ids and callee_id not in harness_function_ids:
                dependencies[task_id].add(stable_function_ids[callee_id])
        for loop_id in function.loop_ids:
            if loops[loop_id].parent_loop_id is None:
                dependencies[task_id].add(stable_loop_ids[loop_id])

    for loop in analysis.loops:
        task_id = stable_loop_ids[loop.id]
        for child_id in loop.child_loop_ids:
            dependencies[task_id].add(stable_loop_ids[child_id])
        for call_id in loop.call_site_ids:
            call = calls_by_id[call_id]
            if not call.loop_ids or call.loop_ids[-1] != loop.id:
                continue
            if call.callee_id in stable_function_ids and call.callee_id not in harness_function_ids:
                dependencies[task_id].add(stable_function_ids[call.callee_id])

    # Include empty dependency sets for deterministic scheduling and expose
    # sorted dependencies in the returned JSON-friendly dictionary.
    for task_id in task_ids:
        dependencies.setdefault(task_id, set())
        task_records[task_id]["depends_on"] = sorted(dependencies[task_id])

    sequence, stages, cycle_groups = _schedule(task_ids, dependencies, source_order)
    stage_by_task = {
        task_id: stage_index for stage_index, stage in enumerate(stages) for task_id in stage
    }
    for order, task_id in enumerate(sequence, start=1):
        task_records[task_id]["order"] = order
        task_records[task_id]["stage"] = stage_by_task[task_id]
        task_records[task_id]["cycle_group"] = cycle_groups[task_id]

    ordered_tasks = {task_id: task_records[task_id] for task_id in sequence}
    return {
        "schema_version": "1.0",
        "source_file": source.as_posix(),
        "source_background_spec": source_background_spec,
        "harness_policy": normalized_policy,
        "harnesses": harnesses,
        "sequence": sequence,
        "stages": stages,
        "tasks": ordered_tasks,
        "statistics": {
            "functions": len(analysis.functions),
            "function_tasks": sum(record["type"] == "function" for record in task_records.values()),
            "harness_functions": len(harnesses),
            "loops": len(analysis.loops),
            "loop_tasks": sum(record["type"] == "loop" for record in task_records.values()),
            "stages": len(stages),
            "cyclic_tasks": sum(group is not None for group in cycle_groups.values()),
        },
    }


def _task_record(task_graph: dict[str, Any], task_id: str) -> dict[str, Any]:
    tasks = task_graph.get("tasks")
    if not isinstance(tasks, dict) or task_id not in tasks:
        raise EvaluationPipelineError(f"Task id is not in the subtask graph: {task_id}")
    record = tasks[task_id]
    if not isinstance(record, dict):
        raise EvaluationPipelineError(f"Malformed task record for task id: {task_id}")
    task_type = record.get("type")
    if task_type not in {"function", "loop"}:
        raise EvaluationPipelineError(
            f"Unsupported task type for {task_id}: {task_type!r}"
        )
    return record


def _compact_task_graph(task_graph: dict[str, Any]) -> dict[str, Any]:
    tasks = task_graph.get("tasks")
    sequence = task_graph.get("sequence")
    compact_sequence: list[dict[str, Any]] = []
    if isinstance(tasks, dict) and isinstance(sequence, list):
        for order, task_id in enumerate(sequence, start=1):
            record = tasks.get(task_id)
            if not isinstance(record, dict):
                continue
            item: dict[str, Any] = {
                "order": order,
                "task_id": task_id,
                "type": record.get("type"),
                "function": record.get("function"),
                "line_start": record.get("line_start"),
            }
            if record.get("type") == "loop":
                item["loop_kind"] = record.get("loop_kind")
            compact_sequence.append(item)

    source_file = task_graph.get("source_file")
    file_name = Path(source_file).name if isinstance(source_file, str) and source_file else None
    return {
        "file_name": file_name,
        "sequence": compact_sequence,
    }


def _compact_final_result(
    report: dict[str, Any],
) -> dict[str, Any]:
    attempts_per_task = report.get("attempts_per_task")
    if not isinstance(attempts_per_task, list):
        attempts_per_task = []
    return {
        "status": report.get("status"),
        "file_name": report.get("file_name"),
        "tasks_total": report.get("tasks_total"),
        "max_input_tokens": (
            report.get("generation", {}).get("max_input_tokens")
            if isinstance(report.get("generation"), dict)
            else None
        ),
        "max_new_tokens": (
            report.get("generation", {}).get("max_new_tokens")
            if isinstance(report.get("generation"), dict)
            else None
        ),
        "attempts_per_task": attempts_per_task,
        "total_attempts": report.get("total_attempts"),
        "total_attempt_seconds": report.get("total_attempt_seconds"),
        "input_token_cost": report.get("input_token_cost"),
        "output_token_cost": report.get("output_token_cost"),
        "average_input_token_cost": report.get("average_input_token_cost"),
        "average_output_token_cost": report.get("average_output_token_cost"),
        "avg_input_token_cost": report.get("avg_input_token_cost"),
        "avg_output_token_cost": report.get("avg_output_token_cost"),
        "verification_time_seconds": report.get("verification_time_seconds"),
        "average_verification_time_seconds": report.get(
            "average_verification_time_seconds"
        ),
        "avg_verification_time_seconds": report.get(
            "avg_verification_time_seconds"
        ),
        "avg_total_time_seconds": report.get("avg_total_time_seconds"),
        "total_time_seconds": report.get("total_time_seconds"),
        "total_goals": report.get("total_goals"),
        "proved_goals": report.get("proved_goals"),
        "best_goal_ratio": report.get("best_goal_ratio"),
    }


def _average_attempt_metrics(
    *,
    total_attempts: int,
    total_prompt_tokens: int,
    total_completion_tokens: int,
    total_attempt_seconds: float,
    total_verification_seconds: float,
) -> dict[str, float]:
    """Return explicit per-attempt averages for the final report.

    The corresponding ``input_token_cost``, ``output_token_cost``,
    ``verification_time_seconds``, and ``total_attempt_seconds`` fields remain
    cumulative totals. These fields make the denominator and the distinction
    between totals and averages unambiguous for multi-attempt runs.
    """

    if total_attempts <= 0:
        average_input = 0.0
        average_output = 0.0
        average_attempt = 0.0
        average_verification = 0.0
    else:
        denominator = float(total_attempts)
        average_input = total_prompt_tokens / denominator
        average_output = total_completion_tokens / denominator
        average_attempt = total_attempt_seconds / denominator
        average_verification = total_verification_seconds / denominator
    return {
        "average_input_token_cost": round(average_input, 3),
        "average_output_token_cost": round(average_output, 3),
        "avg_input_token_cost": round(average_input, 3),
        "avg_output_token_cost": round(average_output, 3),
        "average_verification_time_seconds": round(average_verification, 3),
        "avg_verification_time_seconds": round(average_verification, 3),
        "avg_total_time_seconds": round(average_attempt, 3),
        # Preserve the older names while making their meaning explicit.
        "average_attempt_seconds": round(average_attempt, 3),
        "average_prompt_tokens_per_attempt": round(average_input, 3),
        "average_completion_tokens_per_attempt": round(average_output, 3),
        "average_token_cost_per_attempt": round(
            average_input + average_output, 3
        ),
    }


def _verification_reason(
    command_result: dict[str, Any],
    wp_summary: dict[str, int] | None,
) -> str | None:
    # A complete WP summary is authoritative.  Frama-C can emit a non-zero
    # process status after WP has already reported that every selected goal was
    # proved; that must not turn a successful proof into a failed task.
    if wp_summary:
        total_goals = int(wp_summary["total_goals"])
        proved_goals = int(wp_summary["proved_goals"])
        if total_goals <= 0:
            return "no_proof_goals"
        if proved_goals == total_goals:
            return None
        if proved_goals < total_goals:
            return "unproved_goals"
        return "invalid_wp_summary"
    if command_result.get("timeout"):
        return "process_timeout"
    if command_result.get("error"):
        return "frama_c_start_error"
    if command_result.get("returncode") not in (0, None):
        return "frama_c_nonzero_exit"
    return "no_wp_summary"


def _all_subtasks_passed(
    sequence: Sequence[str],
    step_records: Sequence[dict[str, Any]],
) -> bool:
    if len(step_records) != len(sequence):
        return False
    return all(
        record.get("graph_task_id") == task_id
        and record.get("status") == "passed"
        and record.get("verification_success") is True
        for task_id, record in zip(sequence, step_records)
    )
