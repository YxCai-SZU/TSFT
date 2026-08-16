#!/usr/bin/env python3
"""Remove formal ACSL background declarations from a verified source tree.

This compatibility entry point preserves every original command-line option;
the implementation lives in :mod:`tsft.background`.
"""

from __future__ import annotations

from pathlib import Path
import sys
from typing import Sequence

PROJECT_ROOT = Path(__file__).resolve().parent
SOURCE_ROOT = PROJECT_ROOT / "src"
if str(SOURCE_ROOT) not in sys.path:
    sys.path.insert(0, str(SOURCE_ROOT))

from tsft.background import (
    AnnotationSpan,
    DefinitionExpander,
    FileResult,
    LogicDefinition,
    TransformReport,
    TransformationError,
    VerificationReport,
    atomic_write_text,
    build_frama_command,
    clean_dataset,
    discover_c_files,
    ensure_tool_available,
    process_file,
    transform_source,
    verify_with_wp,
    windows_path_to_wsl,
)
from tsft.cli import background_removal_parser, validate_background_args

build_parser = background_removal_parser
validate_arguments = validate_background_args


def main(argv: Sequence[str] | None = None) -> int:
    args = build_parser().parse_args(argv)
    try:
        validate_arguments(args)
        summary = clean_dataset(args)
    except (OSError, RuntimeError, ValueError) as exc:
        print(f"ERROR: {exc}", file=sys.stderr)
        return 1
    print(
        f"Done: kept {summary['kept']} of {summary['processed']} processed C files; "
        f"discarded {summary['discarded']}."
    )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
