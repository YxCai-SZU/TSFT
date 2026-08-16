"""Minimal distributed QLoRA training entry point."""

from __future__ import annotations

from pathlib import Path

import torch
from transformers import PrinterCallback, ProgressCallback, TrainingArguments, set_seed

from .collator import CompletionOnlyCollator
from .cli import training_parser
from .config import AppConfig, load_config
from .data import TrainingDataset, fixed_subset, load_records, split_records
from .losses import build_loss_schedule
from .modeling import load_tokenizer, load_trainable_model
from .monitoring import TrainingMonitorCallback
from .trainer import TSFTTrainer


def parse_args():
    return training_parser().parse_args()


def _tf32_supported() -> bool:
    if not torch.cuda.is_available():
        return False
    major, _minor = torch.cuda.get_device_capability(torch.cuda.current_device())
    return major >= 8


def _warmup_arguments(ratio: float) -> dict[str, float]:
    warmup_steps_field = TrainingArguments.__dataclass_fields__["warmup_steps"]
    if warmup_steps_field.type is float or warmup_steps_field.type == "float":
        return {"warmup_steps": ratio}
    return {"warmup_ratio": ratio}


def build_training_arguments(config: AppConfig) -> TrainingArguments:
    values = config.training
    output_dir = config.resolve(values.output_dir)
    return TrainingArguments(
        output_dir=str(output_dir),
        run_name=output_dir.name,
        seed=values.seed,
        data_seed=values.seed,
        num_train_epochs=values.num_train_epochs,
        per_device_train_batch_size=values.per_device_train_batch_size,
        per_device_eval_batch_size=values.per_device_eval_batch_size,
        gradient_accumulation_steps=values.gradient_accumulation_steps,
        learning_rate=values.learning_rate,
        weight_decay=values.weight_decay,
        **_warmup_arguments(values.warmup_ratio),
        lr_scheduler_type=values.lr_scheduler_type,
        logging_strategy="no",
        eval_strategy="no",
        save_strategy="no",
        gradient_checkpointing=values.gradient_checkpointing,
        gradient_checkpointing_kwargs={
            "use_reentrant": values.gradient_checkpointing_use_reentrant
        },
        max_grad_norm=values.max_grad_norm,
        bf16=config.model.compute_dtype == "bfloat16",
        fp16=config.model.compute_dtype == "float16",
        tf32=values.tf32 and _tf32_supported(),
        optim=values.optimizer,
        report_to=values.report_to,
        disable_tqdm=True,
        remove_unused_columns=False,
        dataloader_num_workers=values.dataloader_num_workers,
        dataloader_persistent_workers=values.dataloader_persistent_workers,
        include_num_input_tokens_seen=values.include_num_input_tokens_seen,
        ddp_find_unused_parameters=(
            values.ddp_find_unused_parameters
            if torch.cuda.device_count() > 1
            else None
        ),
    )


def run(config_path: str | Path) -> None:
    config = load_config(config_path)
    set_seed(config.training.seed)

    tokenizer = load_tokenizer(config)
    records = load_records(config.resolve(config.data.input_dir))
    splits = split_records(records, config.data)
    train_dataset = TrainingDataset(splits.train, tokenizer, config.data)
    validation_dataset = (
        TrainingDataset(splits.validation, tokenizer, config.data)
        if splits.validation
        else None
    )
    if validation_dataset is None:
        raise ValueError("The validation split is empty; monitoring requires validation data")
    monitoring_records = fixed_subset(
        splits.validation,
        config.monitoring.validation_max_samples,
    )
    monitoring_dataset = TrainingDataset(monitoring_records, tokenizer, config.data)

    print(f"Training records: {len(splits.train)}")
    print(f"Validation records: {len(splits.validation)}")
    print(f"Mini validation records: {len(monitoring_records)}")
    print(f"Held-out test records: {len(splits.test)}")

    model = load_trainable_model(config)
    arguments = build_training_arguments(config)
    trainer = TSFTTrainer(
        model=model,
        args=arguments,
        train_dataset=train_dataset,
        eval_dataset=monitoring_dataset,
        data_collator=CompletionOnlyCollator(
            tokenizer.pad_token_id,
            config.data.pad_to_multiple_of,
        ),
        processing_class=tokenizer,
        loss_strategy=build_loss_schedule(
            config.training.loss_schedule,
            config.training.num_train_epochs,
        ),
    )
    for callback in list(trainer.callback_handler.callbacks):
        if isinstance(callback, (PrinterCallback, ProgressCallback)):
            trainer.remove_callback(type(callback))

    monitor = TrainingMonitorCallback(
        config,
        monitoring_dataset,
        validation_dataset,
    )
    monitor.attach(trainer)
    trainer.add_callback(monitor)

    output_directory = config.resolve(config.training.output_dir)
    if trainer.is_world_process_zero():
        output_directory.mkdir(parents=True, exist_ok=True)
        tokenizer.save_pretrained(output_directory)
    trainer.accelerator.wait_for_everyone()

    trainer.train()


def main() -> None:
    args = parse_args()
    run(args.config)


if __name__ == "__main__":
    main()
