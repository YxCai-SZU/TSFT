#!/usr/bin/env python3
"""Run TSFT generation and Frama-C/WP verification for one C file.

This compatibility entry point preserves the original command and import
surface.  The implementation is organized under :mod:`tsft.evaluation`.
"""

from __future__ import annotations

from pathlib import Path
import sys

PROJECT_ROOT = Path(__file__).resolve().parent
SOURCE_ROOT = PROJECT_ROOT / "src"
if str(SOURCE_ROOT) not in sys.path:
    sys.path.insert(0, str(SOURCE_ROOT))

from tsft.evaluation import *  # noqa: E402,F403
from tsft.evaluation.cli import single_main as _main  # noqa: E402


if __name__ == "__main__":
    raise SystemExit(_main())
