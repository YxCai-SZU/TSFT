#!/usr/bin/env python3
"""Check all local prerequisites required by the training launcher."""

from __future__ import annotations

import importlib
import subprocess
import sys
from pathlib import Path
from typing import Any


PROJECT_ROOT = Path(__file__).resolve().parent
CONFIG_PATH = PROJECT_ROOT / "configs" / "train.yaml"
SOURCE_ROOT = PROJECT_ROOT / "src"
LOCAL_FRAMA_C = PROJECT_ROOT / "frama-c-setup" / "bin" / "frama-c"
REQUIRED_MODULES = (
    "torch",
    "transformers",
    "accelerate",
    "peft",
    "bitsandbytes",
    "yaml",
    "safetensors",
    "sentencepiece",
    "psutil",
    "tqdm",
    "torchvision",
    "PIL",
)


def check_python_dependencies() -> bool:
    missing: list[str] = []
    for module_name in REQUIRED_MODULES:
        try:
            importlib.import_module(module_name)
        except (ImportError, OSError, RuntimeError):
            missing.append(module_name)
    if missing:
        print(f"Missing or unusable Python modules: {', '.join(missing)}")
        print("Install the project requirements in the active environment:")
        print("  python -m pip install -r requirements.txt")
        return False
    transformers = importlib.import_module("transformers")
    if not hasattr(transformers, "Qwen3_5ForCausalLM"):
        print(
            "The installed Transformers build does not provide "
            "Qwen3_5ForCausalLM."
        )
        print("Install the Qwen3.5-compatible versions from requirements.txt.")
        return False
    print("Python training dependencies are installed.")
    return True


def load_training_config() -> Any | None:
    if str(SOURCE_ROOT) not in sys.path:
        sys.path.insert(0, str(SOURCE_ROOT))
    try:
        from tsft.config import load_config

        config = load_config(CONFIG_PATH)
    except (ImportError, OSError, ValueError) as exc:
        print(f"Training configuration is invalid: {exc}")
        return None
    print(f"Training configuration is valid: {CONFIG_PATH}")
    return config


def check_configured_model(config: Any) -> bool:
    model_path = config.resolve(config.model.base_model)
    config_file = model_path / "config.json"
    weight_files = [
        *model_path.glob("*.safetensors"),
        *model_path.glob("pytorch_model*.bin"),
    ]
    if not model_path.is_dir() or not config_file.is_file() or not weight_files:
        print(f"The configured base model is incomplete or missing: {model_path}")
        print("Set model.base_model in configs/train.yaml, then run:")
        print("  python ./download_model.py")
        return False
    print(f"Base model is available: {model_path}")
    return True


def check_training_data(config: Any) -> bool:
    input_directory = config.resolve(config.data.input_dir)
    if not input_directory.is_dir():
        print(f"Training data directory does not exist: {input_directory}")
        print("Generate the JSON training data before starting training.")
        return False
    first_json = next(input_directory.rglob("*.json"), None)
    if first_json is None:
        print(f"No JSON training files were found under: {input_directory}")
        return False
    print(f"Training data is available: {input_directory}")
    return True


def check_cuda() -> bool:
    try:
        import torch
    except (ImportError, OSError) as exc:
        print(f"PyTorch could not be loaded: {exc}")
        return False
    if not torch.cuda.is_available():
        print("CUDA is not available in the active Python environment.")
        return False
    device_count = torch.cuda.device_count()
    if device_count < 1:
        print("No CUDA GPU is visible to the training process.")
        return False
    names = [torch.cuda.get_device_name(index) for index in range(device_count)]
    print(f"CUDA GPUs available: {device_count} ({', '.join(names)})")
    return True


def check_frama_c() -> bool:
    if not LOCAL_FRAMA_C.is_file():
        print(f"Project-local Frama-C is not installed: {LOCAL_FRAMA_C}")
        print("Install it inside this project with:")
        print("  bash ./frama-c-setup/install_frama_c.sh")
        return False
    try:
        result = subprocess.run(
            [str(LOCAL_FRAMA_C), "--version"],
            capture_output=True,
            text=True,
            timeout=20,
            check=False,
        )
    except FileNotFoundError:
        print(f"Project-local Frama-C could not be found: {LOCAL_FRAMA_C}")
        print("Run: bash ./frama-c-setup/install_frama_c.sh")
        return False
    except (OSError, subprocess.SubprocessError) as exc:
        print(f"Project-local Frama-C could not be executed: {exc}")
        return False
    if result.returncode != 0:
        output = (result.stdout + result.stderr).strip()
        print(f"Project-local Frama-C failed its version check: {output}")
        return False
    version = (result.stdout + result.stderr).strip().splitlines()[0]
    print(f"Project-local Frama-C is available: {version}")
    return True


def main() -> int:
    dependencies_ready = check_python_dependencies()
    config = load_training_config() if dependencies_ready else None
    checks = [dependencies_ready, config is not None]
    if config is not None:
        checks.extend(
            (
                check_configured_model(config),
                check_training_data(config),
                check_cuda(),
            )
        )
    checks.append(check_frama_c())
    if all(checks):
        print("Environment check passed.")
        return 0
    print("Environment check failed.", file=sys.stderr)
    return 1


if __name__ == "__main__":
    raise SystemExit(main())
