"""Loss strategies for ground-truth and nearest-equivalent training phases."""

from __future__ import annotations

from abc import ABC, abstractmethod
from dataclasses import dataclass
import math
from typing import Any, Callable, Mapping, Sequence

import torch
import torch.nn.functional as F

from .data import IGNORE_INDEX


@dataclass(frozen=True)
class LossContext:
    model: Any
    model_inputs: dict[str, Any]
    outputs: Any
    labels: torch.Tensor
    metadata: dict[str, Any]


class LossStrategy(ABC):
    """Interface shared by ground-truth and future semantic objectives."""

    @abstractmethod
    def compute(self, context: LossContext) -> torch.Tensor:
        raise NotImplementedError

    def forward_and_compute(
        self,
        model: Any,
        model_inputs: dict[str, Any],
        labels: torch.Tensor,
        metadata: dict[str, Any],
    ) -> tuple[torch.Tensor, Any]:
        outputs = model(**model_inputs)
        loss = self.compute(
            LossContext(model, model_inputs, outputs, labels, metadata)
        )
        return loss, outputs


def _completion_mean_losses(
    logits: torch.Tensor,
    labels: torch.Tensor,
) -> torch.Tensor:
    if logits.ndim != 3 or labels.ndim != 2 or logits.shape[:2] != labels.shape:
        raise ValueError("Logits and labels have incompatible dimensions")
    if labels.shape[1] < 2:
        raise ValueError("Each sequence must contain at least two tokens")

    shift_logits = logits[:, :-1, :].contiguous().float()
    shift_labels = labels[:, 1:].contiguous()
    target_mask = shift_labels.ne(IGNORE_INDEX)
    target_counts = target_mask.sum(dim=1)
    if target_counts.eq(0).any():
        raise ValueError("Every sample must contain completion tokens")

    token_losses = F.cross_entropy(
        shift_logits.reshape(-1, shift_logits.shape[-1]),
        shift_labels.reshape(-1),
        ignore_index=IGNORE_INDEX,
        reduction="none",
    ).view_as(shift_labels)
    return (token_losses * target_mask).sum(dim=1) / target_counts


class GroundTruthCrossEntropyLoss(LossStrategy):
    """Per-sample mean CE over the ground-truth ACSL completion."""

    def compute(self, context: LossContext) -> torch.Tensor:
        return _completion_mean_losses(context.outputs.logits, context.labels).mean()


class NearestEquivalentCrossEntropyLoss(LossStrategy):
    """Select the highest-likelihood equivalent and train against it with CE."""

    candidate_count = 4

    def compute(self, context: LossContext) -> torch.Tensor:
        return _completion_mean_losses(context.outputs.logits, context.labels).mean()

    def forward_and_compute(
        self,
        model: Any,
        model_inputs: dict[str, Any],
        labels: torch.Tensor,
        metadata: dict[str, Any],
    ) -> tuple[torch.Tensor, Any]:
        del labels
        equivalent_input_ids = metadata.get("equivalent_input_ids")
        equivalent_labels = metadata.get("equivalent_labels")
        pad_token_id = metadata.get("equivalent_pad_token_id")
        batch_size = int(model_inputs["input_ids"].shape[0])
        self._validate_equivalents(
            equivalent_input_ids,
            equivalent_labels,
            pad_token_id,
            batch_size,
        )
        device = model_inputs["input_ids"].device

        score_columns: list[torch.Tensor] = []
        was_training = bool(model.training)
        try:
            model.eval()
            with torch.no_grad():
                for candidate_index in range(self.candidate_count):
                    candidate_inputs, candidate_labels = self._padded_batch(
                        equivalent_input_ids,
                        equivalent_labels,
                        [candidate_index] * batch_size,
                        int(pad_token_id),
                        device,
                    )
                    candidate_outputs = model(**candidate_inputs)
                    score_columns.append(
                        _completion_mean_losses(
                            candidate_outputs.logits,
                            candidate_labels,
                        )
                    )
        finally:
            model.train(was_training)

        scores = torch.stack(score_columns, dim=1)
        if not torch.isfinite(scores).all():
            raise FloatingPointError("Equivalent-candidate scores contain NaN or Inf")
        # torch.argmin returns the first index on ties, giving the stable order
        # label, cand1, cand2, cand3.
        selected_indices = scores.argmin(dim=1).tolist()
        selected_inputs, selected_labels = self._padded_batch(
            equivalent_input_ids,
            equivalent_labels,
            selected_indices,
            int(pad_token_id),
            device,
        )
        outputs = model(**selected_inputs)
        selected_metadata = dict(metadata)
        selected_metadata["selected_equivalent_index"] = selected_indices
        loss = self.compute(
            LossContext(
                model,
                selected_inputs,
                outputs,
                selected_labels,
                selected_metadata,
            )
        )
        return loss, outputs

    def _validate_equivalents(
        self,
        input_ids: Any,
        labels: Any,
        pad_token_id: Any,
        batch_size: int,
    ) -> None:
        if isinstance(pad_token_id, bool) or not isinstance(pad_token_id, int):
            raise ValueError("equivalent_pad_token_id must be an integer")
        if not isinstance(input_ids, Sequence) or not isinstance(labels, Sequence):
            raise ValueError("Equivalent candidates are missing from the batch")
        if len(input_ids) != batch_size or len(labels) != batch_size:
            raise ValueError("Equivalent candidates do not match the batch size")
        for row_input_ids, row_labels in zip(input_ids, labels):
            if (
                not isinstance(row_input_ids, Sequence)
                or not isinstance(row_labels, Sequence)
                or len(row_input_ids) != self.candidate_count
                or len(row_labels) != self.candidate_count
            ):
                raise ValueError("Every sample must provide label, cand1, cand2, cand3")
            for candidate_ids, candidate_labels in zip(row_input_ids, row_labels):
                if (
                    not isinstance(candidate_ids, Sequence)
                    or not isinstance(candidate_labels, Sequence)
                    or not candidate_ids
                    or len(candidate_ids) != len(candidate_labels)
                ):
                    raise ValueError("Equivalent candidate ids and labels are invalid")

    def _padded_batch(
        self,
        equivalent_input_ids: Sequence[Sequence[Sequence[int]]],
        equivalent_labels: Sequence[Sequence[Sequence[int]]],
        selected_indices: Sequence[int],
        pad_token_id: int,
        device: torch.device,
    ) -> tuple[dict[str, torch.Tensor], torch.Tensor]:
        selected_input_ids = [
            list(row[index])
            for row, index in zip(equivalent_input_ids, selected_indices)
        ]
        selected_labels = [
            list(row[index])
            for row, index in zip(equivalent_labels, selected_indices)
        ]
        maximum = max(len(sequence) for sequence in selected_input_ids)
        batch_size = len(selected_input_ids)
        input_tensor = torch.full(
            (batch_size, maximum),
            pad_token_id,
            dtype=torch.long,
            device=device,
        )
        attention_tensor = torch.zeros(
            (batch_size, maximum),
            dtype=torch.long,
            device=device,
        )
        label_tensor = torch.full(
            (batch_size, maximum),
            IGNORE_INDEX,
            dtype=torch.long,
            device=device,
        )
        for row, (candidate_ids, candidate_labels) in enumerate(
            zip(selected_input_ids, selected_labels)
        ):
            length = len(candidate_ids)
            input_tensor[row, :length] = torch.tensor(
                candidate_ids,
                dtype=torch.long,
                device=device,
            )
            attention_tensor[row, :length] = 1
            label_tensor[row, :length] = torch.tensor(
                candidate_labels,
                dtype=torch.long,
                device=device,
            )
        return {
            "input_ids": input_tensor,
            "attention_mask": attention_tensor,
        }, label_tensor


class ScheduledLossStrategy(LossStrategy):
    """Select a registered loss from YAML-defined epoch proportions."""

    def __init__(
        self,
        phases: list[tuple[float, LossStrategy]],
        total_epochs: float,
    ) -> None:
        if (
            not phases
            or isinstance(total_epochs, bool)
            or not isinstance(total_epochs, (int, float))
            or not math.isfinite(total_epochs)
            or total_epochs <= 0
        ):
            raise ValueError("A loss schedule requires phases and positive total epochs")
        self.phases = phases
        self.total_epochs = float(total_epochs)

    def compute(self, context: LossContext) -> torch.Tensor:
        return self._active_strategy(context.metadata).compute(context)

    def forward_and_compute(
        self,
        model: Any,
        model_inputs: dict[str, Any],
        labels: torch.Tensor,
        metadata: dict[str, Any],
    ) -> tuple[torch.Tensor, Any]:
        return self._active_strategy(metadata).forward_and_compute(
            model,
            model_inputs,
            labels,
            metadata,
        )

    def _active_strategy(self, metadata: Mapping[str, Any]) -> LossStrategy:
        epoch = metadata.get("epoch")
        progress = float(epoch or 0.0) / self.total_epochs
        for end_ratio, strategy in self.phases:
            if progress < end_ratio:
                return strategy
        return self.phases[-1][1]


LossFactory = Callable[[], LossStrategy]
_LOSS_REGISTRY: dict[str, LossFactory] = {
    "ground_truth_ce": GroundTruthCrossEntropyLoss,
    "nearest_equivalent_ce": NearestEquivalentCrossEntropyLoss,
}


def register_loss(name: str, factory: LossFactory) -> None:
    """Register a new objective without changing the Trainer implementation."""

    if not name or name in _LOSS_REGISTRY:
        raise ValueError(f"Loss strategy is empty or already registered: {name!r}")
    _LOSS_REGISTRY[name] = factory


def build_loss_strategy(name: str) -> LossStrategy:
    try:
        return _LOSS_REGISTRY[name]()
    except KeyError as exc:
        available = ", ".join(sorted(_LOSS_REGISTRY))
        raise ValueError(f"Unknown loss strategy {name!r}; available: {available}") from exc


def build_loss_schedule(
    schedule: Mapping[str, Any],
    total_epochs: float,
) -> LossStrategy:
    phases: list[tuple[float, LossStrategy]] = []
    cumulative_ratio = 0.0
    for phase_name in ("stage1", "stage2"):
        phase = schedule[phase_name]
        raw_ratio = phase["ratio"]
        if isinstance(raw_ratio, bool) or not isinstance(raw_ratio, (int, float)):
            raise ValueError(f"{phase_name} loss ratio must be a number")
        ratio = float(raw_ratio)
        if not math.isfinite(ratio) or ratio < 0:
            raise ValueError(f"{phase_name} loss ratio must be finite and non-negative")
        if ratio == 0:
            continue
        name = phase.get("name")
        if not isinstance(name, str) or not name:
            raise ValueError(f"{phase_name} loss name is required when ratio is positive")
        cumulative_ratio += ratio
        phases.append((cumulative_ratio, build_loss_strategy(name)))
    if abs(cumulative_ratio - 1.0) > 1e-9:
        raise ValueError("Training loss-stage ratios must sum to 1.0")
    return ScheduledLossStrategy(phases, total_epochs)
