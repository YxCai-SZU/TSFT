"""Read YAML training settings and report missing core fields."""

from __future__ import annotations

import math
from pathlib import Path
from typing import Any, Iterator, Mapping

import yaml


class ConfigSection(Mapping[str, Any]):
    def __init__(self, values: dict[str, Any]) -> None:
        self._values = {
            key: ConfigSection(value) if isinstance(value, dict) else value
            for key, value in values.items()
        }

    def __getitem__(self, key: str) -> Any:
        return self._values[key]

    def __iter__(self) -> Iterator[str]:
        return iter(self._values)

    def __len__(self) -> int:
        return len(self._values)

    def __getattr__(self, name: str) -> Any:
        try:
            return self._values[name]
        except KeyError as exc:
            raise AttributeError(name) from exc


class AppConfig(ConfigSection):
    def __init__(self, values: dict[str, Any], project_root: Path) -> None:
        super().__init__(values)
        self.project_root = project_root

    def resolve(self, value: str) -> Path:
        path = Path(value).expanduser()
        return path.resolve() if path.is_absolute() else (self.project_root / path).resolve()


_CORE_FIELDS = (
    "model.hub_id",
    "model.revision",
    "model.base_model",
    "model.finetune_method",
    "model.compute_dtype",
    "model.lora.rank",
    "model.lora.alpha",
    "model.lora.dropout",
    "model.lora.target_modules",
    "data.input_dir",
    "data.max_seq_length",
    "data.chat_template_kwargs.enable_thinking",
    "training.output_dir",
    "training.num_train_epochs",
    "training.warmup_ratio",
    "training.loss_schedule.stage1.name",
    "training.loss_schedule.stage1.ratio",
    "training.loss_schedule.stage2.ratio",
    "monitoring.log_dir",
    "monitoring.loss_file",
    "monitoring.sample_interval",
    "monitoring.final_validation_file",
    "monitoring.progress_update_steps",
    "evaluation.source_dir",
    "evaluation.adapter_dir",
    "evaluation.output_dir",
    "evaluation.batch_size",
    "evaluation.max_new_tokens",
    "evaluation.do_sample",
    "evaluation.num_beams",
    "evaluation.repetition_penalty",
    "evaluation.frama_c.executable",
    "evaluation.frama_c.provers",
    "evaluation.frama_c.wp_timeout",
    "evaluation.frama_c.process_timeout",
    "evaluation.frama_c.workers",
)


def _lookup(
    values: dict[str, Any],
    dotted_path: str,
    *,
    allow_none: bool = False,
) -> Any:
    current: Any = values
    for part in dotted_path.split("."):
        if not isinstance(current, dict) or part not in current:
            raise ValueError(f"Required configuration field not set: {dotted_path}")
        current = current[part]
    if current is None and allow_none:
        return None
    if current is None or (isinstance(current, str) and not current.strip()):
        raise ValueError(f"Required configuration field is empty: {dotted_path}")
    if isinstance(current, (list, dict)) and not current:
        raise ValueError(f"Required configuration field is empty: {dotted_path}")
    return current


def _validate_core_fields(raw: dict[str, Any]) -> None:
    for field in _CORE_FIELDS:
        _lookup(raw, field)
    _lookup(raw, "monitoring.validation_max_samples", allow_none=True)

    method = _lookup(raw, "model.finetune_method")
    if method not in {"lora", "qlora"}:
        raise ValueError("model.finetune_method must be lora or qlora")
    if method == "qlora":
        _lookup(raw, "model.quantization.type")
        _lookup(raw, "model.quantization.double_quant")

    enable_thinking = _lookup(raw, "data.chat_template_kwargs.enable_thinking")
    if not isinstance(enable_thinking, bool):
        raise ValueError(
            "data.chat_template_kwargs.enable_thinking must be true or false"
        )

    stage1_ratio = _lookup(raw, "training.loss_schedule.stage1.ratio")
    stage2_ratio = _lookup(raw, "training.loss_schedule.stage2.ratio")
    if not all(
        not isinstance(value, bool) and isinstance(value, (int, float))
        for value in (stage1_ratio, stage2_ratio)
    ):
        raise ValueError("Training loss-stage ratios must be numbers")
    if not math.isfinite(stage1_ratio) or not math.isfinite(stage2_ratio):
        raise ValueError("Training loss-stage ratios must be finite")
    if stage1_ratio < 0 or stage2_ratio < 0:
        raise ValueError("Training loss-stage ratios cannot be negative")
    if abs(stage1_ratio + stage2_ratio - 1.0) > 1e-9:
        raise ValueError("Training loss-stage ratios must sum to 1.0")
    if stage2_ratio > 0:
        _lookup(raw, "training.loss_schedule.stage2.name")

    warmup_ratio = _lookup(raw, "training.warmup_ratio")
    if (
        isinstance(warmup_ratio, bool)
        or not isinstance(warmup_ratio, (int, float))
        or not math.isfinite(warmup_ratio)
        or not 0 <= warmup_ratio < 1
    ):
        raise ValueError("training.warmup_ratio must be in the range [0, 1)")

    positive_integers = (
        "evaluation.batch_size",
        "evaluation.max_new_tokens",
        "evaluation.num_beams",
        "evaluation.frama_c.wp_timeout",
        "evaluation.frama_c.process_timeout",
        "evaluation.frama_c.workers",
    )
    for field in positive_integers:
        value = _lookup(raw, field)
        if isinstance(value, bool) or not isinstance(value, int) or value <= 0:
            raise ValueError(f"{field} must be a positive integer")

    do_sample = _lookup(raw, "evaluation.do_sample")
    if not isinstance(do_sample, bool):
        raise ValueError("evaluation.do_sample must be true or false")
    repetition_penalty = _lookup(raw, "evaluation.repetition_penalty")
    if (
        isinstance(repetition_penalty, bool)
        or not isinstance(repetition_penalty, (int, float))
        or repetition_penalty <= 0
    ):
        raise ValueError("evaluation.repetition_penalty must be a positive number")
    if _lookup(raw, "evaluation.max_new_tokens") >= _lookup(
        raw, "data.max_seq_length"
    ):
        raise ValueError(
            "evaluation.max_new_tokens must be smaller than data.max_seq_length"
        )


def load_config(path: str | Path) -> AppConfig:
    config_path = Path(path).expanduser().resolve()
    if not config_path.is_file():
        raise FileNotFoundError(f"Training configuration not found: {config_path}")
    try:
        with config_path.open("r", encoding="utf-8") as handle:
            raw = yaml.safe_load(handle) or {}
    except yaml.YAMLError as exc:
        raise ValueError(f"Invalid YAML in {config_path}: {exc}") from exc
    if not isinstance(raw, dict):
        raise ValueError("The training configuration must be a YAML mapping")

    _validate_core_fields(raw)
    return AppConfig(raw, config_path.parent.parent)
