"""Load generated JSON records and prepare completion-only training tensors."""

from __future__ import annotations

import json
import numbers
import random
import re
from collections.abc import Mapping
from dataclasses import dataclass
from pathlib import Path
from typing import Any, Sequence

from torch.utils.data import Dataset

from .config import ConfigSection


IGNORE_INDEX = -100
PROMPT_SECTIONS = (
    "===== TARGET TYPE =====",
    "===== BACKGROUND SPECIFICATION =====",
    "===== CURRENT CODE =====",
    "===== UPSTREAM CONTEXT =====",
    "===== DOWNSTREAM CONTEXT =====",
    "Generate the ACSL specification for the current target now.",
)


@dataclass(frozen=True)
class RawExample:
    sample_id: str
    target_type: str
    prompt: str
    label: str
    source_id: str
    cand1: str | None = None
    cand2: str | None = None
    cand3: str | None = None

    @property
    def equivalent_labels(self) -> tuple[str, str, str, str]:
        return (
            self.label,
            self.cand1 if self.cand1 is not None else self.label,
            self.cand2 if self.cand2 is not None else self.label,
            self.cand3 if self.cand3 is not None else self.label,
        )


@dataclass(frozen=True)
class DatasetSplits:
    train: tuple[RawExample, ...]
    validation: tuple[RawExample, ...]
    test: tuple[RawExample, ...]


def _parse_record(row: Any, path: Path, ordinal: int) -> RawExample:
    if not isinstance(row, dict):
        raise ValueError(f"{path}:{ordinal}: each training record must be an object")

    sample_id = row.get("sample_id")
    target_type = row.get("type")
    prompt = row.get("prompt")
    label = row.get("label")
    if not isinstance(sample_id, str) or not sample_id:
        raise ValueError(f"{path}:{ordinal}: sample_id must be a non-empty string")
    if target_type not in {"function", "loop"}:
        raise ValueError(f"{path}:{ordinal}: type must be function or loop")
    if not isinstance(prompt, str) or not prompt:
        raise ValueError(f"{path}:{ordinal}: prompt must be a non-empty string")
    if not isinstance(label, str) or not label:
        raise ValueError(f"{path}:{ordinal}: label must be a non-empty string")

    errors = normalized_acsl_errors(label)
    if errors:
        raise ValueError(f"{path}:{ordinal}: invalid label: {'; '.join(errors)}")

    candidates: list[str] = []
    for field in ("cand1", "cand2", "cand3"):
        candidate = row.get(field, label)
        if not isinstance(candidate, str) or not candidate:
            raise ValueError(f"{path}:{ordinal}: {field} must be a non-empty string")
        errors = normalized_acsl_errors(candidate)
        if errors:
            raise ValueError(
                f"{path}:{ordinal}: invalid {field}: {'; '.join(errors)}"
            )
        candidates.append(candidate)

    source_id = sample_id.split("::", 1)[0]
    return RawExample(
        sample_id,
        target_type,
        prompt,
        label,
        source_id,
        candidates[0],
        candidates[1],
        candidates[2],
    )


def normalized_acsl_errors(label: str) -> list[str]:
    errors: list[str] = []
    if "\r" in label:
        errors.append("label must use LF newlines")
    if not label.startswith("/*@\n"):
        errors.append("label must start with /*@ followed by a newline")
    if not label.endswith("\n*/"):
        errors.append("label must end with a newline followed by */")
    if label.count("/*@") != 1 or label.count("*/") != 1:
        errors.append("label must contain exactly one ACSL annotation")
    if re.search(r"&&[ \t]*\n", label):
        errors.append("logical && must be followed by a space, not a newline")
    if not errors:
        body = label[4:-3]
        if not body:
            errors.append("label body cannot be empty")
        elif any(line and not line.startswith("\t") for line in body.split("\n")):
            errors.append("every non-empty label body line must start with a tab")
    return errors


def load_records(input_directory: str | Path) -> tuple[RawExample, ...]:
    root = Path(input_directory).expanduser().resolve()
    if not root.is_dir():
        raise FileNotFoundError(f"Training data directory not found: {root}")

    json_files = sorted(root.rglob("*.json"), key=lambda path: path.as_posix().casefold())
    if not json_files:
        raise FileNotFoundError(f"No JSON training files found under: {root}")

    records: list[RawExample] = []
    sample_ids: set[str] = set()
    for path in json_files:
        try:
            payload = json.loads(path.read_text(encoding="utf-8"))
        except (OSError, json.JSONDecodeError) as exc:
            raise ValueError(f"Cannot read training data {path}: {exc}") from exc
        if not isinstance(payload, list):
            raise ValueError(f"{path}: the top-level JSON value must be an array")
        for ordinal, row in enumerate(payload, start=1):
            example = _parse_record(row, path, ordinal)
            if example.sample_id in sample_ids:
                raise ValueError(f"Duplicate sample_id: {example.sample_id}")
            sample_ids.add(example.sample_id)
            records.append(example)

    if not records:
        raise ValueError(f"No training records found under: {root}")
    return tuple(records)


def split_records(records: Sequence[RawExample], config: ConfigSection) -> DatasetSplits:
    """Create configured deterministic splits without separating a C source file."""

    ratio_total = config.train_ratio + config.validation_ratio + config.test_ratio
    if abs(ratio_total - 1.0) > 1e-9:
        raise ValueError("data split ratios must sum to 1.0")
    if min(config.train_ratio, config.validation_ratio, config.test_ratio) < 0:
        raise ValueError("data split ratios cannot be negative")

    groups: dict[str, list[RawExample]] = {}
    for record in records:
        groups.setdefault(record.source_id, []).append(record)

    grouped_records = list(groups.values())
    random.Random(config.split_seed).shuffle(grouped_records)
    train_target = int(len(records) * config.train_ratio)
    validation_target = int(len(records) * config.validation_ratio)

    train: list[RawExample] = []
    validation: list[RawExample] = []
    test: list[RawExample] = []
    for group in grouped_records:
        if len(train) < train_target:
            train.extend(group)
        elif len(validation) < validation_target:
            validation.extend(group)
        else:
            test.extend(group)

    if not train:
        raise ValueError("The training split is empty")
    return DatasetSplits(tuple(train), tuple(validation), tuple(test))


def fixed_subset(
    records: Sequence[RawExample],
    maximum: int | None,
) -> tuple[RawExample, ...]:
    """Select one deterministic, evenly spaced monitoring subset."""

    if maximum is None or maximum >= len(records):
        return tuple(records)
    if maximum <= 0:
        raise ValueError("monitoring.validation_max_samples must be positive or null")
    if maximum == 1:
        return (records[0],)
    indices = (
        round(index * (len(records) - 1) / (maximum - 1))
        for index in range(maximum)
    )
    return tuple(records[index] for index in indices)


def split_prompt(example: RawExample) -> tuple[str, str]:
    positions = [example.prompt.find(section) for section in PROMPT_SECTIONS]
    if any(position < 0 for position in positions) or positions != sorted(positions):
        raise ValueError(f"{example.sample_id}: prompt sections are missing or reordered")
    if example.prompt.count(PROMPT_SECTIONS[0]) != 1:
        raise ValueError(f"{example.sample_id}: prompt must contain one target section")

    boundary = positions[0]
    system_content = example.prompt[:boundary].strip()
    user_content = example.prompt[boundary:].strip()
    if not system_content or not user_content:
        raise ValueError(f"{example.sample_id}: system and user prompts cannot be empty")
    if not user_content.endswith(PROMPT_SECTIONS[-1]):
        raise ValueError(f"{example.sample_id}: prompt has an invalid ending")

    type_end = positions[1] - boundary
    parsed_type = user_content[len(PROMPT_SECTIONS[0]) : type_end].strip()
    if parsed_type != example.target_type:
        raise ValueError(
            f"{example.sample_id}: prompt type {parsed_type!r} does not match "
            f"record type {example.target_type!r}"
        )
    return system_content, user_content


def encode_example(
    tokenizer: Any,
    example: RawExample,
    config: ConfigSection,
) -> dict[str, Any]:
    system_content, user_content = split_prompt(example)
    chat_template_kwargs = getattr(config, "chat_template_kwargs", {})
    prompt_ids = chat_template_token_ids(
        tokenizer,
        [
            {"role": "system", "content": system_content},
            {"role": "user", "content": user_content},
        ],
        chat_template_kwargs,
    )
    encoded_equivalents = [
        _encode_completion(
            tokenizer,
            prompt_ids,
            completion,
            config.max_seq_length,
            example.sample_id,
            field,
        )
        for field, completion in zip(
            ("label", "cand1", "cand2", "cand3"),
            example.equivalent_labels,
        )
    ]
    input_ids, labels = encoded_equivalents[0]
    return {
        "input_ids": input_ids,
        "attention_mask": [1] * len(input_ids),
        "labels": labels,
        "equivalent_input_ids": [item[0] for item in encoded_equivalents],
        "equivalent_labels": [item[1] for item in encoded_equivalents],
        "sample_id": example.sample_id,
        "target_type": example.target_type,
    }


def chat_template_token_ids(
    tokenizer: Any,
    messages: Sequence[dict[str, str]],
    chat_template_kwargs: Mapping[str, Any],
) -> list[int]:
    encoded = tokenizer.apply_chat_template(
        messages,
        tokenize=True,
        add_generation_prompt=True,
        return_dict=False,
        **dict(chat_template_kwargs),
    )
    if isinstance(encoded, Mapping):
        if "input_ids" not in encoded:
            raise ValueError("Chat template output does not contain input_ids")
        encoded = encoded["input_ids"]
    if hasattr(encoded, "tolist"):
        encoded = encoded.tolist()
    if (
        isinstance(encoded, Sequence)
        and len(encoded) == 1
        and isinstance(encoded[0], Sequence)
        and not isinstance(encoded[0], (str, bytes))
    ):
        encoded = encoded[0]
    if not isinstance(encoded, Sequence) or isinstance(encoded, (str, bytes)):
        raise TypeError("Chat template must return token IDs or an input_ids mapping")
    if not encoded or any(
        isinstance(token_id, bool) or not isinstance(token_id, numbers.Integral)
        for token_id in encoded
    ):
        raise ValueError("Chat template input_ids must be a non-empty integer sequence")
    return [int(token_id) for token_id in encoded]


def _encode_completion(
    tokenizer: Any,
    prompt_ids: Sequence[int],
    completion: str,
    maximum: int,
    sample_id: str,
    field: str,
) -> tuple[list[int], list[int]]:
    completion_ids = tokenizer.encode(completion, add_special_tokens=False)
    if not completion_ids or completion_ids[-1] != tokenizer.eos_token_id:
        completion_ids.append(tokenizer.eos_token_id)

    available_prompt_tokens = maximum - len(completion_ids)
    if available_prompt_tokens <= 0:
        raise ValueError(
            f"{sample_id}: {field} exceeds max_seq_length={maximum}"
        )
    truncated_prompt = list(prompt_ids)
    if len(truncated_prompt) > available_prompt_tokens:
        prefix = available_prompt_tokens // 2
        suffix = available_prompt_tokens - prefix
        truncated_prompt = truncated_prompt[:prefix] + truncated_prompt[-suffix:]

    input_ids = truncated_prompt + completion_ids
    labels = [IGNORE_INDEX] * len(truncated_prompt) + completion_ids
    return input_ids, labels


class TrainingDataset(Dataset):
    def __init__(
        self,
        records: Sequence[RawExample],
        tokenizer: Any,
        config: ConfigSection,
    ) -> None:
        self.records = tuple(records)
        self.tokenizer = tokenizer
        self.config = config

    def __len__(self) -> int:
        return len(self.records)

    def __getitem__(self, index: int) -> dict[str, Any]:
        return encode_example(self.tokenizer, self.records[index], self.config)
