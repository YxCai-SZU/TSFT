#!/usr/bin/env python3
"""Download the configured Hugging Face base model into ./model."""

from __future__ import annotations

import os
import sys
from pathlib import Path


PROJECT_ROOT = Path(__file__).resolve().parent
SOURCE_ROOT = PROJECT_ROOT / "src"
CONFIG_PATH = PROJECT_ROOT / "configs" / "train.yaml"
MAX_WORKERS = 8
DEFAULT_ENDPOINT = "https://huggingface.co"


def _prepare_online_download() -> list[str]:
    removed: list[str] = []
    for variable in ("HF_HUB_OFFLINE", "TRANSFORMERS_OFFLINE"):
        if os.environ.pop(variable, None) is not None:
            removed.append(variable)
    os.environ.setdefault("HF_HUB_ETAG_TIMEOUT", "60")
    os.environ.setdefault("HF_HUB_DOWNLOAD_TIMEOUT", "600")
    return removed


def _print_exception_chain(exc: BaseException) -> None:
    seen: set[int] = set()
    current: BaseException | None = exc
    depth = 0
    while current is not None and id(current) not in seen and depth < 5:
        seen.add(id(current))
        if depth:
            print(
                f"Caused by: {type(current).__name__}: {current}",
                file=sys.stderr,
            )
        current = current.__cause__ or current.__context__
        depth += 1


def main() -> int:
    removed_offline_variables = _prepare_online_download()
    try:
        from huggingface_hub import snapshot_download
        from huggingface_hub.utils import validate_repo_id
        if str(SOURCE_ROOT) not in sys.path:
            sys.path.insert(0, str(SOURCE_ROOT))
        from tsft.config import load_config

        config = load_config(CONFIG_PATH)
        model_id = str(config.model.hub_id)
        revision = str(config.model.revision)
        validate_repo_id(model_id)
        destination = config.resolve(config.model.base_model)
        endpoint = os.getenv("HF_ENDPOINT", DEFAULT_ENDPOINT).rstrip("/")

        print(f"Downloading {model_id}@{revision}")
        print(f"Endpoint: {endpoint}")
        print(f"Destination: {destination}")
        if removed_offline_variables:
            print(
                "Online mode enabled; ignored: "
                + ", ".join(removed_offline_variables)
            )
        destination.mkdir(parents=True, exist_ok=True)

        snapshot_download(
            repo_id=model_id,
            repo_type="model",
            revision=revision,
            local_dir=str(destination),
            token=os.getenv("HF_TOKEN"),
            max_workers=MAX_WORKERS,
        )
        print(f"Download complete: {destination}")
        return 0
    except ModuleNotFoundError:
        print(
            "ERROR: install huggingface-hub first: "
            'python -m pip install "huggingface-hub>=1.5,<2.0"',
            file=sys.stderr,
        )
    except KeyboardInterrupt:
        print("ERROR: interrupted; run this script again to continue", file=sys.stderr)
        return 130
    except Exception as exc:
        print(f"ERROR: {type(exc).__name__}: {exc}", file=sys.stderr)
        _print_exception_chain(exc)
        if type(exc).__name__ == "LocalEntryNotFoundError":
            endpoint = os.getenv("HF_ENDPOINT", DEFAULT_ENDPOINT).rstrip("/")
            print(
                "The server could not retrieve the model from the configured "
                f"Hugging Face endpoint ({endpoint}), and no complete local "
                "snapshot exists.",
                file=sys.stderr,
            )
            print(
                "Check HTTPS connectivity/proxy settings, or set the standard "
                "HF_ENDPOINT environment variable to an accessible mirror and "
                "run this script again.",
                file=sys.stderr,
            )
    return 1


if __name__ == "__main__":
    raise SystemExit(main())
