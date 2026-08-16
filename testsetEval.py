#!/usr/bin/env python3
"""Evaluate the local base model and its best trained adapter."""

from __future__ import annotations

import os
import sys
from pathlib import Path


PROJECT_ROOT = Path(__file__).resolve().parent
SOURCE_ROOT = PROJECT_ROOT / "src"
CONFIG_PATH = PROJECT_ROOT / "configs" / "train.yaml"
LOCAL_FRAMA_C_BIN = PROJECT_ROOT / "frama-c-setup" / "bin"
LOCAL_FRAMA_C = LOCAL_FRAMA_C_BIN / "frama-c"


def configure_project_local_frama_c() -> None:
    if not LOCAL_FRAMA_C.is_file():
        raise FileNotFoundError(
            "Project-local Frama-C is missing. Run "
            "bash ./frama-c-setup/install_frama_c.sh first."
        )
    current_path = os.environ.get("PATH", "")
    os.environ["PATH"] = str(LOCAL_FRAMA_C_BIN) + (
        os.pathsep + current_path if current_path else ""
    )


def main() -> int:
    if str(SOURCE_ROOT) not in sys.path:
        sys.path.insert(0, str(SOURCE_ROOT))
    os.environ.setdefault("HF_HUB_OFFLINE", "1")
    os.environ.setdefault("TRANSFORMERS_OFFLINE", "1")
    os.environ.setdefault("TOKENIZERS_PARALLELISM", "false")

    try:
        configure_project_local_frama_c()
        from tsft.testset_evaluation import run

        run(CONFIG_PATH)
        return 0
    except KeyboardInterrupt:
        print("Test-set evaluation interrupted by the user.", file=sys.stderr)
        return 130
    except (ImportError, OSError, RuntimeError, TypeError, ValueError) as exc:
        print(f"ERROR: Test-set evaluation failed: {exc}", file=sys.stderr)
        return 1


if __name__ == "__main__":
    raise SystemExit(main())
