#!/usr/bin/env python3
"""Generate function and loop training records from labeled C/ACSL files.

This compatibility entry point keeps the original command and import surface;
the implementation lives in :mod:`tsft.training_data`.
"""

from __future__ import annotations

from pathlib import Path
import sys
from typing import Sequence

PROJECT_ROOT = Path(__file__).resolve().parent
SOURCE_ROOT = PROJECT_ROOT / "src"
if str(SOURCE_ROOT) not in sys.path:
    sys.path.insert(0, str(SOURCE_ROOT))

from Clang.analyzer import AnalysisError, analyze_paths
from tsft.cli import training_data_parser
from tsft.training_data import (
    BACKGROUND,
    CODE_ANNOTATION,
    FUNCTION_CONTRACT,
    LOOP_CONTRACT,
    NORMAL_COMMENT,
    AppendResult,
    BuildResult,
    ByteSpan,
    CommentSpan,
    GroundTruthLabel,
    PreprocessingError,
    SourceDocument,
    TrainingDataBuilder,
    TrainingSourceAudit,
    _atomic_write_json,
    _canonicalize_candidate_body,
    _canonicalize_ground_truth_label,
    _label_fields,
    _next_output_file,
    _progress,
    append_training_samples,
    audit_training_sources,
    build_prompt,
    build_training_samples,
    delete_invalid_source_files,
    generate_equivalent_candidates,
    scan_c_comments,
)

build_parser = training_data_parser


def main(argv: Sequence[str] | None = None) -> int:
    args = build_parser().parse_args(argv)
    input_directory = Path(args.inputdir).expanduser().resolve()
    output_directory = Path(args.outputdir).expanduser().resolve()
    if not input_directory.is_dir():
        print(f"ERROR: Input directory does not exist: {input_directory}", file=sys.stderr)
        return 2

    try:
        output_directory.mkdir(parents=True, exist_ok=True)
        analysis = analyze_paths(
            [input_directory],
            project_root=input_directory,
            recursive=True,
            extensions=(".c",),
            allow_partial_ast=True,
            clang_timeout=20.0,
            progress_callback=_progress,
        )
        build = build_training_samples(analysis, input_directory)

        failed_units = [
            unit
            for unit in analysis.translation_units
            if unit.status in {"failed", "timeout"}
        ]
        if failed_units:
            print(
                f"WARNING: {len(failed_units)} translation unit(s) produced no "
                "usable AST and were skipped without blocking other records.",
                file=sys.stderr,
            )
        partial_units = [
            unit for unit in analysis.translation_units if unit.status == "partial"
        ]
        if partial_units:
            print(
                f"INFO: Ignored host-compilation diagnostics in "
                f"{len(partial_units)} translation unit(s); their recoverable "
                "ASTs were used.",
                file=sys.stderr,
            )
        if build.test_harnesses:
            print(
                f"INFO: {len(build.test_harnesses)} unlabeled test harness "
                "function(s) were excluded from function training records.",
                file=sys.stderr,
            )
            for target_id in build.test_harnesses[:20]:
                print(f"    {target_id}", file=sys.stderr)
            if len(build.test_harnesses) > 20:
                print(
                    f"    ... {len(build.test_harnesses) - 20} more harness(es)",
                    file=sys.stderr,
                )
        if build.missing_labels:
            print(
                f"WARNING: {len(build.missing_labels)} non-harness function/loop "
                "target(s) have no ground-truth contract; "
                f"{len(build.invalid_source_files)} complete C source file(s) "
                "were excluded.",
                file=sys.stderr,
            )
            for display_path, target_ids in list(build.invalid_source_files.items())[:20]:
                print(f"    {display_path} (skipped; source kept)", file=sys.stderr)
                for target_id in target_ids:
                    print(f"        unlabeled: {target_id}", file=sys.stderr)
        if build.missing_downstream_labels:
            print(
                f"WARNING: {len(build.skipped_incomplete_samples)} target "
                "sample(s) were excluded because required direct children have "
                "no ground-truth label.",
                file=sys.stderr,
            )
            for target_id, missing_ids in list(
                build.skipped_incomplete_samples.items()
            )[:20]:
                print(f"    {target_id}", file=sys.stderr)
                for missing_id in missing_ids:
                    print(f"        missing: {missing_id}", file=sys.stderr)

        if not build.samples:
            raise PreprocessingError("No labeled function or loop samples were produced")

        output_file = _next_output_file(output_directory)
        _atomic_write_json(output_file, build.samples)
    except (AnalysisError, PreprocessingError, OSError, ValueError) as exc:
        print(f"ERROR: {exc}", file=sys.stderr)
        return 2

    stats = analysis.statistics
    print(
        "Analysis: "
        f"{stats['source_files']} file(s), {stats['functions']} function(s), "
        f"{stats['loops']} loop(s), {stats['resolved_internal_calls']} internal call(s)"
    )
    print(
        f"Output: {output_file}\n"
        f"Generated: {len(build.samples)} training record(s)"
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
