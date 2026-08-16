from __future__ import annotations

from dataclasses import dataclass
from typing import Any

import torch

from .data import IGNORE_INDEX


@dataclass
class CompletionOnlyCollator:
    pad_token_id: int
    pad_to_multiple_of: int | None = 8

    def __call__(self, features: list[dict[str, Any]]) -> dict[str, Any]:
        max_length = max(len(feature["input_ids"]) for feature in features)
        if self.pad_to_multiple_of:
            multiple = self.pad_to_multiple_of
            max_length = ((max_length + multiple - 1) // multiple) * multiple

        input_ids: list[list[int]] = []
        attention_mask: list[list[int]] = []
        labels: list[list[int]] = []
        for feature in features:
            padding = max_length - len(feature["input_ids"])
            input_ids.append(feature["input_ids"] + [self.pad_token_id] * padding)
            attention_mask.append(feature["attention_mask"] + [0] * padding)
            labels.append(feature["labels"] + [IGNORE_INDEX] * padding)

        return {
            "input_ids": torch.tensor(input_ids, dtype=torch.long),
            "attention_mask": torch.tensor(attention_mask, dtype=torch.long),
            "labels": torch.tensor(labels, dtype=torch.long),
            # Keep the four variable-length alternatives as Python lists so
            # stage-one batches do not move unused candidates onto the GPU.
            "equivalent_input_ids": [
                feature["equivalent_input_ids"] for feature in features
            ],
            "equivalent_labels": [
                feature["equivalent_labels"] for feature in features
            ],
            "equivalent_pad_token_id": self.pad_token_id,
            "sample_id": [feature["sample_id"] for feature in features],
            "target_type": [feature["target_type"] for feature in features],
        }
