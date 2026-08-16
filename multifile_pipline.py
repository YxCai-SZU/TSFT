#!/usr/bin/env python3
"""Run the unchanged recursive TSFT evaluation command.

The historical filename intentionally retains ``pipline`` for command-line
compatibility.  The implementation is organized under
:mod:`tsft.evaluation.batch`.
"""

from __future__ import annotations

from pathlib import Path
import sys

PROJECT_ROOT = Path(__file__).resolve().parent
SOURCE_ROOT = PROJECT_ROOT / "src"
if str(SOURCE_ROOT) not in sys.path:
    sys.path.insert(0, str(SOURCE_ROOT))

from tsft.evaluation.batch import (  # noqa: E402
    _average,
    _discover_c_sources,
    _file_output_root,
    _file_report_summary,
    _nonnegative_float,
    _nonnegative_int,
    _rate,
    _resolve_directory,
    _summarize_sample_report,
    run_multifile_workflow,
)
from tsft.evaluation.cli import multifile_main as _main  # noqa: E402
from tsft.evaluation.constants import (  # noqa: E402
    EvaluationPipelineError,
    _DEFAULT_MAX_INPUT_TOKENS,
    _DEFAULT_MAX_NEW_TOKENS,
)
from tsft.evaluation.runtime import (  # noqa: E402
    _atomic_write_json,
    _resolve_frama_c_executable,
)
from tsft.evaluation.workflow import run_evaluation_workflow  # noqa: E402


if __name__ == "__main__":
    raise SystemExit(_main())
