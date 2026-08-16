"""Local model loading and prompt generation for evaluation."""

from __future__ import annotations

from pathlib import Path
from typing import Any

from .constants import (
    PROJECT_ROOT as _PROJECT_ROOT,
    EvaluationPipelineError,
    _DEFAULT_MAX_INPUT_TOKENS,
    _DEFAULT_MAX_NEW_TOKENS,
)
from .prompts import _split_prompt_sections
from .source_files import _extract_final_generation_text


def _model_device(model: Any):
    for parameter in model.parameters():
        if parameter.device.type != "meta":
            return parameter.device
    raise EvaluationPipelineError("The generation model has no materialized parameters")


def load_generation_components(
    modeldir: str | Path,
    adapterdir: str | Path | None = None,
    *,
    trust_remote_code: bool = False,
    compute_dtype: str = "bfloat16",
) -> tuple[Any, Any]:
    """Load the tokenizer and model for single-prompt generation."""

    try:
        from tsft.config import AppConfig
        from tsft.modeling import load_evaluation_model, load_tokenizer
    except ModuleNotFoundError as exc:
        raise EvaluationPipelineError(
            "Model generation dependencies are not available in this environment"
        ) from exc

    resolved_modeldir = Path(modeldir).expanduser().resolve()
    if not resolved_modeldir.is_dir():
        raise FileNotFoundError(f"Base model not found: {resolved_modeldir}")

    config = AppConfig(
        {
            "model": {
                "base_model": str(modeldir),
                "finetune_method": "lora",
                "compute_dtype": compute_dtype,
                "trust_remote_code": trust_remote_code,
            }
        },
        _PROJECT_ROOT,
    )
    resolved_modeldir = config.resolve(config.model.base_model)
    if not resolved_modeldir.is_dir():
        raise FileNotFoundError(f"Base model not found: {resolved_modeldir}")
    tokenizer = load_tokenizer(config)
    adapter_path = None
    if adapterdir is not None and str(adapterdir).strip():
        adapter_path = config.resolve(str(adapterdir))
    if adapter_path is not None and not adapter_path.is_dir():
        raise FileNotFoundError(f"Adapter not found: {adapter_path}")
    model = load_evaluation_model(config, adapter_path)
    return tokenizer, model


def generate_model_output_from_loaded_components(
    prompt: str,
    tokenizer: Any,
    model: Any,
    *,
    max_new_tokens: int = _DEFAULT_MAX_NEW_TOKENS,
    do_sample: bool = False,
    num_beams: int = 1,
    repetition_penalty: float = 1.05,
    chat_template_kwargs: dict[str, Any] | None = None,
    max_input_tokens: int | None = _DEFAULT_MAX_INPUT_TOKENS,
) -> str:
    """Generate one completion for a preloaded tokenizer/model pair."""

    return generate_model_output_with_stats_from_loaded_components(
        prompt,
        tokenizer,
        model,
        max_new_tokens=max_new_tokens,
        do_sample=do_sample,
        num_beams=num_beams,
        repetition_penalty=repetition_penalty,
        chat_template_kwargs=chat_template_kwargs,
        max_input_tokens=max_input_tokens,
    )["text"]


def generate_model_output_with_stats_from_loaded_components(
    prompt: str,
    tokenizer: Any,
    model: Any,
    *,
    max_new_tokens: int = _DEFAULT_MAX_NEW_TOKENS,
    do_sample: bool = False,
    num_beams: int = 1,
    repetition_penalty: float = 1.05,
    chat_template_kwargs: dict[str, Any] | None = None,
    max_input_tokens: int | None = _DEFAULT_MAX_INPUT_TOKENS,
) -> dict[str, Any]:
    """Generate one completion and report the token counts used for it.

    ``max_input_tokens`` limits only the prompt sent to the model.  The
    separate ``max_new_tokens`` budget covers the complete generated sequence,
    including Qwen's hidden thinking tokens and the visible ACSL answer.
    Consequently, the maximum context consumed by one request is the sum of
    these two values.
    """

    try:
        from tsft.data import chat_template_token_ids
        import torch
    except ModuleNotFoundError as exc:
        raise EvaluationPipelineError(
            "Model generation dependencies are not available in this environment"
        ) from exc

    system_content, user_content = _split_prompt_sections(prompt)
    # Enable Qwen's hidden reasoning channel for evaluation. The chat
    # template controls this at generation time; it is not added to the
    # visible specification prompt, and only the final text after ``</think>``
    # is returned below.
    template_kwargs = {"enable_thinking": True}
    if chat_template_kwargs:
        template_kwargs.update(chat_template_kwargs)

    prompt_ids = chat_template_token_ids(
        tokenizer,
        [
            {"role": "system", "content": system_content},
            {"role": "user", "content": user_content},
        ],
        template_kwargs,
    )
    raw_prompt_tokens = len(prompt_ids)

    if max_new_tokens <= 0:
        raise EvaluationPipelineError("max_new_tokens must be positive")
    if max_input_tokens is None:
        token_limit = getattr(tokenizer, "model_max_length", None)
        if (
            not isinstance(token_limit, int)
            or token_limit <= 0
            or token_limit > 100000
        ):
            token_limit = _DEFAULT_MAX_INPUT_TOKENS
        max_input_tokens = token_limit

    max_input_tokens = int(max_input_tokens)
    if max_input_tokens <= 0:
        raise EvaluationPipelineError(
            "max_input_tokens must be positive"
        )
    prompt_truncated = False
    if len(prompt_ids) > max_input_tokens:
        prefix = max_input_tokens // 2
        suffix = max_input_tokens - prefix
        prompt_ids = prompt_ids[:prefix] + prompt_ids[-suffix:]
        prompt_truncated = True

    device = _model_device(model)
    input_ids = torch.tensor([prompt_ids], dtype=torch.long, device=device)
    attention_mask = torch.ones_like(input_ids)
    with torch.inference_mode():
        generated = model.generate(
            input_ids=input_ids,
            attention_mask=attention_mask,
            max_new_tokens=max_new_tokens,
            do_sample=do_sample,
            num_beams=num_beams,
            repetition_penalty=repetition_penalty,
            eos_token_id=tokenizer.eos_token_id,
            pad_token_id=tokenizer.pad_token_id,
        )
    generated_ids = generated[0, len(prompt_ids) :]
    decoded_text = tokenizer.decode(generated_ids, skip_special_tokens=True)
    text = _extract_final_generation_text(decoded_text)
    completion_tokens = int(generated_ids.shape[0])
    prompt_tokens = int(len(prompt_ids))
    return {
        "text": text,
        "prompt_token_count": prompt_tokens,
        "prompt_token_count_raw": raw_prompt_tokens,
        "completion_token_count": completion_tokens,
        "total_token_count": prompt_tokens + completion_tokens,
        "prompt_truncated": prompt_truncated,
        "max_input_tokens": int(max_input_tokens),
        "max_new_tokens": int(max_new_tokens),
    }


def generate_model_output(
    prompt: str,
    modeldir: str | Path,
    adapterdir: str | Path | None = None,
    *,
    trust_remote_code: bool = False,
    compute_dtype: str = "bfloat16",
    max_new_tokens: int = _DEFAULT_MAX_NEW_TOKENS,
    do_sample: bool = False,
    num_beams: int = 1,
    repetition_penalty: float = 1.05,
    chat_template_kwargs: dict[str, Any] | None = None,
    max_input_tokens: int | None = _DEFAULT_MAX_INPUT_TOKENS,
) -> str:
    """Load a model and return the generated completion for one prompt."""

    tokenizer, model = load_generation_components(
        modeldir,
        adapterdir,
        trust_remote_code=trust_remote_code,
        compute_dtype=compute_dtype,
    )
    try:
        return generate_model_output_from_loaded_components(
            prompt,
            tokenizer,
            model,
            max_new_tokens=max_new_tokens,
            do_sample=do_sample,
            num_beams=num_beams,
            repetition_penalty=repetition_penalty,
            chat_template_kwargs=chat_template_kwargs,
            max_input_tokens=max_input_tokens,
        )
    finally:
        try:
            import gc
            import torch

            del model
            del tokenizer
            gc.collect()
            if torch.cuda.is_available():
                torch.cuda.empty_cache()
        except Exception:
            pass
