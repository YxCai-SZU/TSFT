"""Single-file TSFT generation and verification workflow."""

from __future__ import annotations

import time
from pathlib import Path
from typing import Any, Sequence

from .constants import (
    EvaluationPipelineError,
    _DEFAULT_MAX_INPUT_TOKENS,
    _DEFAULT_MAX_NEW_TOKENS,
)
from .analysis import _analyze_one_c_file, _normalise_harness_policy
from .frama import _resolve_frama_c_executable
from .generation import (
    generate_model_output_with_stats_from_loaded_components,
    load_generation_components,
)
from .prompts import _SingleTaskPromptBuilder
from .source_files import (
    _atomic_write_json,
    _atomic_write_text,
    _combine_model_output_with_code,
    _copy_file,
    _prepare_work_root,
    _resolve_existing_c_file,
)
from .tasks import (
    _all_subtasks_passed,
    _average_attempt_metrics,
    _compact_final_result,
    _compact_task_graph,
    _task_record,
    build_subtask_sequence,
)
from .verification import (
    _attempt_directory,
    _attempt_summary,
    _step_directory,
    _step_file_name,
    verify_task_output,
)


def run_evaluation_workflow(
    *,
    file: str | Path,
    modeldir: str | Path,
    outputdir: str | Path,
    work_root: str | Path | None = None,
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
    """Run the full evaluation loop for one C file."""

    if max_attempts_per_task < 1:
        raise ValueError("max_attempts_per_task must be at least 1")

    workflow_started = time.monotonic()
    frama_c_executable = _resolve_frama_c_executable(frama_c_executable)
    source = _resolve_existing_c_file(file)
    output_root = Path(outputdir).expanduser().resolve()
    output_root.mkdir(parents=True, exist_ok=True)
    if work_root is None:
        resolved_work_root = output_root / source.stem
    else:
        resolved_work_root = Path(work_root).expanduser().resolve()
        try:
            resolved_work_root.relative_to(output_root)
        except ValueError as exc:
            raise EvaluationPipelineError(
                f"work_root must be located under outputdir: {resolved_work_root}"
            ) from exc
    _prepare_work_root(resolved_work_root)
    working_temp = resolved_work_root / _step_file_name(source)
    _copy_file(source, working_temp)
    task_graph = build_subtask_sequence(
        source,
        harness_policy=harness_policy,
        harness_patterns=harness_patterns,
        clang=clang,
        clang_arguments=clang_arguments,
        clang_timeout=clang_timeout,
    )
    _atomic_write_json(resolved_work_root / "task_graph.json", _compact_task_graph(task_graph))

    tokenizer, model = load_generation_components(
        modeldir,
        adapterdir,
        trust_remote_code=trust_remote_code,
        compute_dtype=compute_dtype,
    )

    total_prompt_tokens = 0
    total_prompt_tokens_raw = 0
    total_completion_tokens = 0
    total_attempts = 0
    total_attempt_seconds = 0.0
    total_verification_seconds = 0.0
    best_total_goals = 0
    best_proved_goals = 0
    best_goal_ratio = -1.0
    step_records: list[dict[str, Any]] = []
    attempts_per_task: list[int] = []
    completed_steps = 0
    failed_task_id: str | None = None
    failure_reason: str | None = None
    final_status = "success"
    effective_do_sample = bool(max_attempts_per_task > 1) if do_sample is None else bool(do_sample)
    generation_do_sample = effective_do_sample
    generation_enable_thinking = True
    if chat_template_kwargs and "enable_thinking" in chat_template_kwargs:
        generation_enable_thinking = bool(chat_template_kwargs["enable_thinking"])

    try:
        sequence = list(task_graph.get("sequence", []))
        if not sequence:
            raise EvaluationPipelineError("The task graph contains no subtasks")
        attempts_per_task = [0 for _ in sequence]

        for step_index, graph_task_id in enumerate(sequence, start=1):
            step_dir = _step_directory(resolved_work_root, step_index)
            step_dir.mkdir(parents=True, exist_ok=True)

            task_record = _task_record(task_graph, graph_task_id)
            step_summary: dict[str, Any] = {
                "step_index": step_index,
                "graph_task_id": graph_task_id,
                "task_type": task_record["type"],
                "task_record": task_record,
                "step_dir": str(step_dir),
                "status": "running",
                "attempts": [],
                "selected_attempt": None,
                "working_temp_before": str(working_temp),
                "working_temp_after": None,
                "selected_attempt_dir": None,
            }

            try:
                source_analysis = _analyze_one_c_file(
                    working_temp,
                    clang=clang,
                    clang_arguments=clang_arguments,
                    clang_timeout=clang_timeout,
                )
                prompt_builder = _SingleTaskPromptBuilder(
                    task_graph,
                    working_temp,
                    source_analysis,
                    require_downstream_contracts=True,
                )
                prompt = prompt_builder.build(graph_task_id)
                source_parts = prompt_builder.task_source_parts(graph_task_id)
            except Exception as exc:
                step_summary["status"] = "failed"
                step_summary["failure_reason"] = (
                    f"workflow_setup_error: {type(exc).__name__}: {exc}"
                )
                step_summary["error"] = f"{type(exc).__name__}: {exc}"
                step_summary["attempts_used"] = 0
                step_summary["verification_success"] = False
                step_summary["last_attempt"] = None
                failure_reason = step_summary["failure_reason"]
                failed_task_id = graph_task_id
                final_status = "fail"
                step_records.append(step_summary)
                _atomic_write_json(step_dir / "step.json", step_summary)
                break

            step_succeeded = False
            last_attempt_summary: dict[str, Any] | None = None
            for attempt_index in range(1, max_attempts_per_task + 1):
                attempt_dir = _attempt_directory(step_dir, attempt_index)
                attempt_dir.mkdir(parents=True, exist_ok=True)
                attempt_started = time.monotonic()
                prompt_text: str | None = None
                model_output: str | None = None
                generation: dict[str, Any] | None = None
                verification: dict[str, Any] | None = None
                merged_source_text: str | None = None
                attempt_error: str | None = None

                try:
                    prompt_text = prompt
                    generation = generate_model_output_with_stats_from_loaded_components(
                        prompt_text,
                        tokenizer,
                        model,
                        max_new_tokens=max_new_tokens,
                        do_sample=generation_do_sample,
                        num_beams=num_beams,
                        repetition_penalty=repetition_penalty,
                        chat_template_kwargs=chat_template_kwargs,
                        max_input_tokens=max_input_tokens,
                    )
                    model_output = generation["text"]
                    verification = verify_task_output(
                        task_graph,
                        graph_task_id,
                        model_output,
                        current_c_file=working_temp,
                        clang=clang,
                        clang_arguments=clang_arguments,
                        clang_timeout=clang_timeout,
                        analysis=source_analysis,
                        frama_c_executable=frama_c_executable,
                        frama_c_provers=frama_c_provers,
                        frama_c_wp_timeout=frama_c_wp_timeout,
                        frama_c_process_timeout=frama_c_process_timeout,
                        log_output_dir=None,
                    )
                    merged_source_text = _combine_model_output_with_code(
                        model_output,
                        verification["code_snippet"],
                        source_prefix=verification["source_prefix"],
                        existing_contract=verification.get("existing_contract"),
                    )
                except Exception as exc:
                    attempt_error = f"{type(exc).__name__}: {exc}"

                attempt_seconds = time.monotonic() - attempt_started
                if generation is not None:
                    generation["step_seconds"] = round(attempt_seconds, 3)
                attempt_summary = _attempt_summary(
                    step_index=step_index,
                    attempt_index=attempt_index,
                    prompt=prompt_text,
                    model_output=model_output,
                    generation=generation,
                    verification=verification,
                    merged_source_text=merged_source_text,
                    attempt_seconds=attempt_seconds,
                    attempt_dir=attempt_dir,
                )
                if attempt_error is not None:
                    attempt_summary["error"] = attempt_error
                step_summary["attempts"].append(attempt_summary)
                last_attempt_summary = attempt_summary

                total_attempt_seconds += float(attempt_seconds)
                total_attempts += 1
                if generation is not None:
                    total_prompt_tokens += int(generation["prompt_token_count"])
                    total_prompt_tokens_raw += int(generation["prompt_token_count_raw"])
                    total_completion_tokens += int(generation["completion_token_count"])
                if verification is not None:
                    total_verification_seconds += float(verification.get("seconds") or 0.0)
                    wp_summary = verification.get("wp_summary")
                    if isinstance(wp_summary, dict):
                        attempt_total_goals = int(wp_summary.get("total_goals") or 0)
                        attempt_proved_goals = int(wp_summary.get("proved_goals") or 0)
                        if (
                            attempt_total_goals > 0
                            and 0 <= attempt_proved_goals <= attempt_total_goals
                        ):
                            attempt_goal_ratio = (
                                attempt_proved_goals / attempt_total_goals
                            )
                            if (
                                attempt_goal_ratio > best_goal_ratio
                                or (
                                    attempt_goal_ratio == best_goal_ratio
                                    and attempt_total_goals > best_total_goals
                                )
                            ):
                                best_goal_ratio = attempt_goal_ratio
                                best_total_goals = attempt_total_goals
                                best_proved_goals = attempt_proved_goals

                if verification is not None and verification.get("verification_success"):
                    if (
                        prompt_text is None
                        or model_output is None
                        or generation is None
                        or merged_source_text is None
                    ):
                        raise EvaluationPipelineError(
                            "Successful verification is missing prompt, model output, "
                            "generation stats, or merged source text"
                        )
                    _atomic_write_text(working_temp, merged_source_text or "")
                    step_summary["status"] = "passed"
                    step_summary["selected_attempt"] = attempt_index
                    step_summary["selected_attempt_dir"] = str(attempt_dir)
                    step_summary["working_temp_after"] = str(working_temp)
                    step_summary["verification_reason"] = verification.get("verification_reason")
                    step_summary["verification_success"] = True
                    step_summary["attempts_used"] = attempt_index
                    step_summary["prompt_token_count"] = generation["prompt_token_count"]
                    step_summary["prompt_token_count_raw"] = generation["prompt_token_count_raw"]
                    step_summary["completion_token_count"] = generation["completion_token_count"]
                    step_summary["token_cost"] = generation["total_token_count"]
                    step_summary["frama_c_parse_success"] = verification.get("frama_c_parse_success")
                    step_summary["wp_all_goals_proved"] = verification.get("wp_all_goals_proved")
                    step_summary["attempt_seconds"] = round(attempt_seconds, 3)
                    step_summary["last_attempt"] = last_attempt_summary
                    attempts_per_task[step_index - 1] = attempt_index
                    step_records.append(step_summary)
                    completed_steps += 1
                    step_succeeded = True
                    break

            if not step_succeeded:
                step_summary["status"] = "failed"
                step_summary["selected_attempt"] = None if last_attempt_summary is None else last_attempt_summary["attempt_index"]
                step_summary["attempts_used"] = len(step_summary["attempts"])
                step_summary["failure_reason"] = (
                    None
                    if last_attempt_summary is None
                    else last_attempt_summary.get("verification_reason")
                    or last_attempt_summary.get("error")
                )
                step_summary["verification_success"] = False
                step_summary["last_attempt"] = last_attempt_summary
                attempts_per_task[step_index - 1] = len(step_summary["attempts"])
                step_records.append(step_summary)
                failed_task_id = graph_task_id
                failure_reason = step_summary["failure_reason"] or "step_failed"
                final_status = "fail"
                break

        if final_status == "success" and not _all_subtasks_passed(sequence, step_records):
            final_status = "fail"
            failure_reason = failure_reason or "incomplete_workflow"
            if failed_task_id is None and completed_steps < len(sequence):
                failed_task_id = sequence[completed_steps] if completed_steps < len(sequence) else None

        report: dict[str, Any] = {
            "status": final_status,
            "source_file": str(source),
            "file_name": source.name,
            "work_root": str(resolved_work_root),
            "working_temp_file": str(working_temp),
            "task_graph_file": str(resolved_work_root / "task_graph.json"),
            "modeldir": str(modeldir),
            "adapterdir": None if adapterdir is None else str(adapterdir),
            "harness_policy": _normalise_harness_policy(harness_policy),
            "harness_patterns": list(harness_patterns),
            "clang": None if clang is None else str(clang),
            "clang_arguments": list(clang_arguments),
            "clang_timeout": clang_timeout,
            "frama_c_executable": str(frama_c_executable),
            "frama_c_provers": frama_c_provers,
            "frama_c_wp_timeout": frama_c_wp_timeout,
            "frama_c_process_timeout": frama_c_process_timeout,
            "max_attempts_per_task": max_attempts_per_task,
            "generation": {
                "max_new_tokens": max_new_tokens,
                "do_sample": generation_do_sample,
                "enable_thinking": generation_enable_thinking,
                "num_beams": num_beams,
                "repetition_penalty": repetition_penalty,
                "compute_dtype": compute_dtype,
                "trust_remote_code": trust_remote_code,
                "max_input_tokens": max_input_tokens,
            },
            "tasks_total": len(sequence),
            "tasks_completed": completed_steps,
            "attempts_per_task": attempts_per_task,
            "failed_task_id": failed_task_id,
            "failure_reason": failure_reason,
            "total_attempts": total_attempts,
            "total_attempt_seconds": round(total_attempt_seconds, 3),
            "total_prompt_tokens": total_prompt_tokens,
            "total_prompt_tokens_raw": total_prompt_tokens_raw,
            "total_completion_tokens": total_completion_tokens,
            "input_token_cost": total_prompt_tokens,
            "output_token_cost": total_completion_tokens,
            "verification_time_seconds": round(total_verification_seconds, 3),
            "total_token_cost": total_prompt_tokens + total_completion_tokens,
            "total_goals": best_total_goals,
            "proved_goals": best_proved_goals,
            "best_goal_ratio": (
                round(best_goal_ratio, 8) if best_goal_ratio >= 0 else None
            ),
            **_average_attempt_metrics(
                total_attempts=total_attempts,
                total_prompt_tokens=total_prompt_tokens,
                total_completion_tokens=total_completion_tokens,
                total_attempt_seconds=total_attempt_seconds,
                total_verification_seconds=total_verification_seconds,
            ),
            "steps": step_records,
            "task_sequence": sequence,
            "task_graph": {
                "schema_version": task_graph.get("schema_version"),
                "statistics": task_graph.get("statistics", {}),
                "sequence": sequence,
                "stages": task_graph.get("stages", []),
                "harnesses": task_graph.get("harnesses", []),
            },
            "total_time_seconds": round(time.monotonic() - workflow_started, 3),
        }
        _atomic_write_json(resolved_work_root / "final_result.json", _compact_final_result(report))
        return report
    except Exception as exc:
        fatal_error = f"{type(exc).__name__}: {exc}"
        source_value = locals().get("source")
        work_root_value = locals().get("resolved_work_root")
        working_temp_value = locals().get("working_temp")
        task_graph_value = locals().get("task_graph")
        sequence_value = locals().get("sequence", [])
        report = {
            "status": "fail",
            "source_file": None if source_value is None else str(source_value),
            "file_name": None if source_value is None else Path(source_value).name,
            "work_root": None if work_root_value is None else str(work_root_value),
            "working_temp_file": None if working_temp_value is None else str(working_temp_value),
            "task_graph_file": None
            if work_root_value is None
            else str(Path(work_root_value) / "task_graph.json"),
            "modeldir": str(modeldir),
            "adapterdir": None if adapterdir is None else str(adapterdir),
            "harness_policy": _normalise_harness_policy(harness_policy),
            "harness_patterns": list(harness_patterns),
            "clang": None if clang is None else str(clang),
            "clang_arguments": list(clang_arguments),
            "clang_timeout": clang_timeout,
            "frama_c_executable": str(frama_c_executable),
            "frama_c_provers": frama_c_provers,
            "frama_c_wp_timeout": frama_c_wp_timeout,
            "frama_c_process_timeout": frama_c_process_timeout,
            "max_attempts_per_task": max_attempts_per_task,
            "generation": {
                "max_new_tokens": max_new_tokens,
                "do_sample": generation_do_sample,
                "enable_thinking": generation_enable_thinking,
                "num_beams": num_beams,
                "repetition_penalty": repetition_penalty,
                "compute_dtype": compute_dtype,
                "trust_remote_code": trust_remote_code,
                "max_input_tokens": max_input_tokens,
            },
            "tasks_total": len(sequence_value),
            "tasks_completed": completed_steps,
            "attempts_per_task": attempts_per_task if attempts_per_task else [],
            "failed_task_id": failed_task_id,
            "failure_reason": failure_reason or fatal_error,
            "fatal_error": fatal_error,
            "total_attempts": total_attempts,
            "total_attempt_seconds": round(total_attempt_seconds, 3),
            "total_prompt_tokens": total_prompt_tokens,
            "total_prompt_tokens_raw": total_prompt_tokens_raw,
            "total_completion_tokens": total_completion_tokens,
            "input_token_cost": total_prompt_tokens,
            "output_token_cost": total_completion_tokens,
            "verification_time_seconds": round(total_verification_seconds, 3),
            "total_token_cost": total_prompt_tokens + total_completion_tokens,
            "total_goals": best_total_goals,
            "proved_goals": best_proved_goals,
            "best_goal_ratio": (
                round(best_goal_ratio, 8) if best_goal_ratio >= 0 else None
            ),
            **_average_attempt_metrics(
                total_attempts=total_attempts,
                total_prompt_tokens=total_prompt_tokens,
                total_completion_tokens=total_completion_tokens,
                total_attempt_seconds=total_attempt_seconds,
                total_verification_seconds=total_verification_seconds,
            ),
            "steps": step_records,
            "task_sequence": sequence_value,
            "task_graph": None
            if task_graph_value is None
            else {
                "schema_version": task_graph_value.get("schema_version"),
                "statistics": task_graph_value.get("statistics", {}),
                "sequence": sequence_value,
                "stages": task_graph_value.get("stages", []),
                "harnesses": task_graph_value.get("harnesses", []),
            },
            "total_time_seconds": round(time.monotonic() - workflow_started, 3),
        }
        if work_root_value is not None:
            try:
                _atomic_write_json(Path(work_root_value) / "final_result.json", _compact_final_result(report))
            except OSError:
                pass
        return report
    finally:
        try:
            import gc
            import torch

            del model
            del tokenizer
            gc.collect()
            if torch.cuda.is_available():
                torch.cuda.empty_cache()
        except Exception:
            pass
