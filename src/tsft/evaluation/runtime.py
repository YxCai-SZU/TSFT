"""Compatibility imports for the refactored evaluation support modules."""

from .analysis import (
    _analyze_one_c_file,
    _function_task_id,
    _is_harness,
    _location_key,
    _looks_like_harness_name,
    _loop_paths,
    _normalise_harness_policy,
    _schedule,
    _stable_loop_task_id,
    _tarjan_components,
    _task_graph_ids,
)
from .frama import _frama_c_wp_command, _resolve_frama_c_executable, _run_command
from .source_files import (
    _acsl_annotation_body,
    _atomic_write_json,
    _atomic_write_text,
    _c_brace_depth,
    _combine_model_output_with_code,
    _copy_file,
    _create_c_file,
    _create_combined_c_file,
    _create_task_verification_c_file,
    _dataset_family,
    _extract_final_generation_text,
    _merge_acsl_annotations,
    _prepare_work_root,
    _resolve_existing_c_file,
    _source_work_slug,
    _task_file_slug,
    _write_json_artifact,
)
