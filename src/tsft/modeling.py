"""Local tokenizer and QLoRA model loading for training."""

from __future__ import annotations

import os
from pathlib import Path
from typing import Any

import torch
from peft import LoraConfig as PeftLoraConfig
from peft import PeftModel, TaskType, get_peft_model, prepare_model_for_kbit_training
from transformers import AutoModelForCausalLM, AutoTokenizer, BitsAndBytesConfig

from .config import AppConfig


def _dtype(name: str) -> torch.dtype:
    return {
        "float16": torch.float16,
        "bfloat16": torch.bfloat16,
        "float32": torch.float32,
    }[name]


def load_tokenizer(config: AppConfig) -> Any:
    model_path = config.resolve(config.model.base_model)
    if not model_path.is_dir():
        raise FileNotFoundError(f"Base model not found: {model_path}")
    tokenizer = AutoTokenizer.from_pretrained(
        model_path,
        trust_remote_code=config.model.trust_remote_code,
        local_files_only=True,
    )
    if tokenizer.pad_token_id is None:
        tokenizer.pad_token = tokenizer.eos_token
    if tokenizer.chat_template is None:
        raise ValueError("The selected tokenizer does not provide a chat template")
    tokenizer.padding_side = "right"
    return tokenizer


def load_trainable_model(config: AppConfig) -> Any:
    if not torch.cuda.is_available():
        raise RuntimeError("LoRA/QLoRA training requires a CUDA GPU")

    model_path = config.resolve(config.model.base_model)
    if not model_path.is_dir():
        raise FileNotFoundError(f"Base model not found: {model_path}")

    compute_dtype = _dtype(config.model.compute_dtype)
    method = config.model.finetune_method
    model_arguments: dict[str, Any] = {
        "trust_remote_code": config.model.trust_remote_code,
        "local_files_only": True,
        "dtype": compute_dtype,
        "low_cpu_mem_usage": True,
    }
    attention_implementation = config.model.get("attention_implementation")
    if attention_implementation:
        model_arguments["attn_implementation"] = attention_implementation
    if method == "qlora":
        model_arguments["quantization_config"] = BitsAndBytesConfig(
            load_in_4bit=True,
            bnb_4bit_quant_type=config.model.quantization.type,
            bnb_4bit_use_double_quant=config.model.quantization.double_quant,
            bnb_4bit_compute_dtype=compute_dtype,
        )
        model_arguments["device_map"] = {
            "": int(os.environ.get("LOCAL_RANK", "0"))
        }

    model = AutoModelForCausalLM.from_pretrained(model_path, **model_arguments)
    model.config.use_cache = False
    if method == "qlora":
        model = prepare_model_for_kbit_training(
            model,
            use_gradient_checkpointing=config.training.gradient_checkpointing,
        )

    lora = config.model.lora
    model = get_peft_model(
        model,
        PeftLoraConfig(
            r=lora.rank,
            lora_alpha=lora.alpha,
            lora_dropout=lora.dropout,
            target_modules=list(lora.target_modules),
            bias="none",
            task_type=TaskType.CAUSAL_LM,
        ),
    )
    model.print_trainable_parameters()
    return model


def load_evaluation_model(
    config: AppConfig,
    adapter_path: str | os.PathLike[str] | None = None,
) -> Any:
    """Load the base model, optionally attaching the best trained adapter."""

    if not torch.cuda.is_available():
        raise RuntimeError("Test-set evaluation requires a CUDA GPU")
    model_path = config.resolve(config.model.base_model)
    if not model_path.is_dir():
        raise FileNotFoundError(f"Base model not found: {model_path}")

    compute_dtype = _dtype(config.model.compute_dtype)
    arguments: dict[str, Any] = {
        "trust_remote_code": config.model.trust_remote_code,
        "local_files_only": True,
        "dtype": compute_dtype,
        "low_cpu_mem_usage": True,
        "device_map": {"": 0},
    }
    attention_implementation = config.model.get("attention_implementation")
    if attention_implementation:
        arguments["attn_implementation"] = attention_implementation
    if config.model.finetune_method == "qlora":
        arguments["quantization_config"] = BitsAndBytesConfig(
            load_in_4bit=True,
            bnb_4bit_quant_type=config.model.quantization.type,
            bnb_4bit_use_double_quant=config.model.quantization.double_quant,
            bnb_4bit_compute_dtype=compute_dtype,
        )

    model = AutoModelForCausalLM.from_pretrained(model_path, **arguments)
    if adapter_path is not None:
        resolved_adapter = Path(adapter_path).expanduser().resolve()
        if not resolved_adapter.is_dir():
            raise FileNotFoundError(f"Trained adapter not found: {resolved_adapter}")
        model = PeftModel.from_pretrained(model, resolved_adapter, is_trainable=False)
    model.config.use_cache = True
    model.eval()
    return model
