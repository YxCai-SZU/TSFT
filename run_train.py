#!/usr/bin/env python3
"""Check the environment and launch local distributed training."""

from __future__ import annotations

import os
import subprocess
import sys
from pathlib import Path


PROJECT_ROOT = Path(__file__).resolve().parent
CONFIG_PATH = PROJECT_ROOT / "configs" / "train.yaml"
SOURCE_ROOT = PROJECT_ROOT / "src"


def _run_environment_check() -> bool:
    print("Running the pre-training environment check...", flush=True)
    result = subprocess.run(
        [sys.executable, str(PROJECT_ROOT / "check_environment.py")],
        cwd=PROJECT_ROOT,
        check=False,
    )
    if result.returncode == 0:
        return True
    print(
        "ERROR: Environment validation failed. Training was not started. "
        "Fix the messages above and run ./run_train.py again.",
        file=sys.stderr,
    )
    return False


def _visible_gpu_count() -> int:
    import torch

    return torch.cuda.device_count()


def _training_environment() -> dict[str, str]:
    environment = os.environ.copy()
    source_path = str(SOURCE_ROOT)
    existing_python_path = environment.get("PYTHONPATH")
    environment["PYTHONPATH"] = (
        source_path
        if not existing_python_path
        else source_path + os.pathsep + existing_python_path
    )
    environment.setdefault("HF_HUB_OFFLINE", "1")
    environment.setdefault("TRANSFORMERS_OFFLINE", "1")
    environment.setdefault("WANDB_DISABLED", "true")
    environment.setdefault("TOKENIZERS_PARALLELISM", "false")
    return environment


def main() -> int:
    try:
        if not _run_environment_check():
            return 1
        gpu_count = _visible_gpu_count()
        if gpu_count < 1:
            print("ERROR: No CUDA GPU is available.", file=sys.stderr)
            return 1

        print(f"Starting training with {gpu_count} CUDA GPU process(es)...", flush=True)
        command = [
            sys.executable,
            "-m",
            "torch.distributed.run",
            "--standalone",
            f"--nproc_per_node={gpu_count}",
            "-m",
            "tsft.train",
            "--config",
            str(CONFIG_PATH),
        ]
        result = subprocess.run(
            command,
            cwd=PROJECT_ROOT,
            env=_training_environment(),
            check=False,
        )
        if result.returncode != 0:
            print(
                f"ERROR: Training exited with status {result.returncode}.",
                file=sys.stderr,
            )
        return result.returncode
    except KeyboardInterrupt:
        print("Training interrupted by the user.", file=sys.stderr)
        return 130
    except (ImportError, OSError, subprocess.SubprocessError) as exc:
        print(f"ERROR: Could not start training: {exc}", file=sys.stderr)
        return 1


if __name__ == "__main__":
    raise SystemExit(main())
