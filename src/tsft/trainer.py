"""Trainer adapter that delegates objective computation to a loss strategy."""

from __future__ import annotations

from typing import Any

import torch
import torch.distributed as dist
from transformers import Trainer

from .losses import LossStrategy


class TSFTTrainer(Trainer):
    def __init__(self, *args: Any, loss_strategy: LossStrategy, **kwargs: Any) -> None:
        super().__init__(*args, **kwargs)
        self.model_accepts_loss_kwargs = False
        self.loss_strategy = loss_strategy
        self._inside_training_step = False
        self._current_training_loss: torch.Tensor | None = None
        self._latest_training_loss: torch.Tensor | None = None
        self._window_loss_sum: torch.Tensor | None = None
        self._window_local_samples = 0
        self._total_local_samples = 0

    def compute_loss(
        self,
        model: Any,
        inputs: dict[str, Any],
        return_outputs: bool = False,
        num_items_in_batch: int | None = None,
    ) -> Any:
        del num_items_in_batch
        model_inputs = dict(inputs)
        labels = model_inputs.pop("labels")
        metadata = {
            "sample_id": model_inputs.pop("sample_id", None),
            "target_type": model_inputs.pop("target_type", None),
            "equivalent_input_ids": model_inputs.pop(
                "equivalent_input_ids",
                None,
            ),
            "equivalent_labels": model_inputs.pop("equivalent_labels", None),
            "equivalent_pad_token_id": model_inputs.pop(
                "equivalent_pad_token_id",
                None,
            ),
            "epoch": self.state.epoch,
            "global_step": self.state.global_step,
        }
        loss, outputs = self.loss_strategy.forward_and_compute(
            model,
            model_inputs,
            labels,
            metadata,
        )
        if self._inside_training_step:
            self._current_training_loss = loss.detach()
        return (loss, outputs) if return_outputs else loss

    def training_step(
        self,
        model: Any,
        inputs: dict[str, Any],
        num_items_in_batch: int | None = None,
    ) -> torch.Tensor:
        batch_size = int(inputs["input_ids"].shape[0])
        self._current_training_loss = None
        self._inside_training_step = True
        try:
            scaled_loss = super().training_step(model, inputs, num_items_in_batch)
        finally:
            self._inside_training_step = False

        if self._current_training_loss is None:
            raise RuntimeError("The training loss was not captured")
        raw_loss = self._current_training_loss
        self._latest_training_loss = raw_loss
        weighted_loss = raw_loss.to(dtype=torch.float64) * batch_size
        if self._window_loss_sum is None:
            self._window_loss_sum = torch.zeros_like(weighted_loss)
        self._window_loss_sum += weighted_loss
        self._window_local_samples += batch_size
        self._total_local_samples += batch_size
        return scaled_loss

    def latest_training_loss(self) -> float | None:
        if self._latest_training_loss is None:
            return None
        return float(self._latest_training_loss.item())

    def global_samples_seen(self) -> int:
        world_size = dist.get_world_size() if dist.is_initialized() else 1
        return self._total_local_samples * world_size

    def consume_loss_window(self) -> float:
        if self._window_loss_sum is None or self._window_local_samples == 0:
            raise RuntimeError("No training samples are available for this loss checkpoint")
        stats = torch.stack(
            (
                self._window_loss_sum,
                self._window_loss_sum.new_tensor(float(self._window_local_samples)),
            )
        )
        if dist.is_initialized():
            dist.all_reduce(stats, op=dist.ReduceOp.SUM)
        training_loss = float((stats[0] / stats[1]).item())
        self._window_loss_sum = None
        self._window_local_samples = 0
        return training_loss
