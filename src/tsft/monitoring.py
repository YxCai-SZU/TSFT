"""Sparse loss checkpoints, best-adapter selection, and console progress."""

from __future__ import annotations

import json
import math
import os
import tempfile
from pathlib import Path
from typing import Any

from tqdm.auto import tqdm
from transformers import TrainerCallback, TrainerControl, TrainerState, TrainingArguments

from .config import AppConfig
from .data import TrainingDataset
from .trainer import TSFTTrainer


class TrainingMonitorCallback(TrainerCallback):
    def __init__(
        self,
        config: AppConfig,
        monitoring_dataset: TrainingDataset,
        full_validation_dataset: TrainingDataset,
    ) -> None:
        self.config = config
        self.monitoring_dataset = monitoring_dataset
        self.full_validation_dataset = full_validation_dataset
        self.trainer: TSFTTrainer | None = None
        self.log_directory = config.resolve(config.monitoring.log_dir)
        loss_name = Path(config.monitoring.loss_file)
        if loss_name.name != str(loss_name):
            raise ValueError("monitoring.loss_file must be a file name, not a path")
        self.loss_path = self.log_directory / loss_name
        final_validation_name = Path(config.monitoring.final_validation_file)
        if final_validation_name.name != str(final_validation_name):
            raise ValueError(
                "monitoring.final_validation_file must be a file name, not a path"
            )
        self.final_validation_path = self.log_directory / final_validation_name
        self.sample_interval = int(config.monitoring.sample_interval)
        self.progress_update_steps = int(config.monitoring.progress_update_steps)
        if self.sample_interval <= 0 or self.progress_update_steps <= 0:
            raise ValueError("Monitoring intervals must be positive")

        self.history: dict[str, dict[str, float]] = {}
        self.checkpoint_index = 1
        self.next_sample_checkpoint = self.sample_interval
        self.best_validation_loss = math.inf
        self.best_checkpoint: str | None = None
        self.best_adapter_saved = False
        self.progress: tqdm[Any] | None = None

    def attach(self, trainer: TSFTTrainer) -> None:
        self.trainer = trainer

    def on_train_begin(
        self,
        args: TrainingArguments,
        state: TrainerState,
        control: TrainerControl,
        **kwargs: Any,
    ) -> TrainerControl:
        trainer = self._trainer()
        if trainer.is_world_process_zero():
            self.log_directory.mkdir(parents=True, exist_ok=True)
            self.loss_path.unlink(missing_ok=True)
            self.final_validation_path.unlink(missing_ok=True)
        if trainer.is_world_process_zero():
            self.progress = tqdm(
                total=state.max_steps,
                initial=state.global_step,
                dynamic_ncols=True,
                unit="batch",
                desc=self._epoch_label(state),
            )
        return control

    def on_step_end(
        self,
        args: TrainingArguments,
        state: TrainerState,
        control: TrainerControl,
        **kwargs: Any,
    ) -> TrainerControl:
        trainer = self._trainer()
        if state.global_step % self.progress_update_steps == 0:
            self._update_progress(state)

        samples_seen = trainer.global_samples_seen()
        if samples_seen >= self.next_sample_checkpoint:
            training_loss = trainer.consume_loss_window()
            validation_metrics = trainer.evaluate(
                eval_dataset=self.monitoring_dataset,
                metric_key_prefix="monitor_validation",
            )
            validation_loss = float(validation_metrics["monitor_validation_loss"])
            self._record(training_loss, validation_loss)
            if validation_loss < self.best_validation_loss:
                self.best_validation_loss = validation_loss
                self.best_checkpoint = f"checkpoint{self.checkpoint_index - 1}"
                trainer.save_model(
                    str(self.config.resolve(self.config.training.output_dir))
                )
                trainer.accelerator.wait_for_everyone()
                self.best_adapter_saved = True
            while self.next_sample_checkpoint <= samples_seen:
                self.next_sample_checkpoint += self.sample_interval
            self._update_progress(state, validation_loss=validation_loss)
        return control

    def on_train_end(
        self,
        args: TrainingArguments,
        state: TrainerState,
        control: TrainerControl,
        **kwargs: Any,
    ) -> TrainerControl:
        self._update_progress(state)
        if self.progress is not None:
            self.progress.close()
            self.progress = None
        if not self.best_adapter_saved:
            raise RuntimeError(
                "Training ended before a monitored adapter checkpoint was created; "
                "reduce monitoring.sample_interval"
            )
        self._compare_with_final_full_validation()
        return control

    def _compare_with_final_full_validation(self) -> None:
        trainer = self._trainer()
        if trainer.is_world_process_zero():
            print(
                "Running one final loss evaluation on the complete "
                "validation split...",
                flush=True,
            )
        metrics = trainer.evaluate(
            eval_dataset=self.full_validation_dataset,
            metric_key_prefix="full_validation",
        )
        final_full_validation_loss = float(metrics["full_validation_loss"])
        final_model_selected = final_full_validation_loss < self.best_validation_loss
        if final_model_selected:
            trainer.save_model(
                str(self.config.resolve(self.config.training.output_dir))
            )
            trainer.accelerator.wait_for_everyone()

        if self.best_checkpoint is None:
            raise RuntimeError("The best mini-validation checkpoint is unavailable")
        selected_model = "final_model" if final_model_selected else self.best_checkpoint
        selected_loss = (
            final_full_validation_loss
            if final_model_selected
            else self.best_validation_loss
        )

        if trainer.is_world_process_zero():
            report = {
                "mini_validation_samples": len(self.monitoring_dataset),
                "full_validation_samples": len(self.full_validation_dataset),
                "best_mini_validation_checkpoint": self.best_checkpoint,
                "best_mini_validation_loss": round(self.best_validation_loss, 8),
                "final_model_full_validation_loss": round(
                    final_full_validation_loss,
                    8,
                ),
                "selected_model": selected_model,
                "selected_loss": round(selected_loss, 8),
            }
            _atomic_write_json(self.final_validation_path, report)
            print(
                "Selected LoRA adapter: "
                f"{selected_model} "
                f"(selection loss "
                f"{selected_loss:.8f})",
                flush=True,
            )

    def _record(self, training_loss: float, validation_loss: float) -> None:
        trainer = self._trainer()
        if trainer.is_world_process_zero():
            self.history[f"checkpoint{self.checkpoint_index}"] = {
                "training_loss": round(training_loss, 8),
                "validation_loss": round(validation_loss, 8),
            }
            self.log_directory.mkdir(parents=True, exist_ok=True)
            _atomic_write_json(self.loss_path, self.history)
        self.checkpoint_index += 1

    def _update_progress(
        self,
        state: TrainerState,
        *,
        validation_loss: float | None = None,
    ) -> None:
        trainer = self._trainer()
        if self.progress is None or not trainer.is_world_process_zero():
            return
        delta = state.global_step - self.progress.n
        if delta > 0:
            self.progress.update(delta)

        total_epochs = max(1, math.ceil(float(self.config.training.num_train_epochs)))
        steps_per_epoch = max(1, math.ceil(state.max_steps / total_epochs))
        epoch_number = min(
            total_epochs,
            max(1, math.ceil(float(state.epoch or 0.0))),
        )
        batch_number = state.global_step - (epoch_number - 1) * steps_per_epoch
        batch_number = min(steps_per_epoch, max(1, batch_number))
        postfix: dict[str, Any] = {
            "batch": f"{batch_number}/{steps_per_epoch}",
            "samples": trainer.global_samples_seen(),
        }
        training_loss = trainer.latest_training_loss()
        if training_loss is not None:
            postfix["loss"] = f"{training_loss:.4f}"
        if trainer.optimizer is not None and trainer.optimizer.param_groups:
            postfix["lr"] = f"{trainer.optimizer.param_groups[0]['lr']:.3e}"
        if validation_loss is not None:
            postfix["val_loss"] = f"{validation_loss:.4f}"
        self.progress.set_description(self._epoch_label(state))
        self.progress.set_postfix(postfix, refresh=True)

    def _epoch_label(self, state: TrainerState) -> str:
        total = max(1, math.ceil(float(self.config.training.num_train_epochs)))
        current = min(total, max(1, math.ceil(float(state.epoch or 0.0))))
        return f"Epoch {current}/{total}"

    def _trainer(self) -> TSFTTrainer:
        if self.trainer is None:
            raise RuntimeError("Training monitor is not attached to a trainer")
        return self.trainer


def _atomic_write_json(path: Path, payload: dict[str, Any]) -> None:
    temporary: Path | None = None
    try:
        with tempfile.NamedTemporaryFile(
            mode="w",
            encoding="utf-8",
            newline="\n",
            prefix=f".{path.name}.",
            suffix=".tmp",
            dir=path.parent,
            delete=False,
        ) as handle:
            temporary = Path(handle.name)
            json.dump(payload, handle, ensure_ascii=False, indent=2)
            handle.write("\n")
            handle.flush()
            os.fsync(handle.fileno())
        os.replace(temporary, path)
    except OSError:
        if temporary is not None:
            temporary.unlink(missing_ok=True)
        raise
