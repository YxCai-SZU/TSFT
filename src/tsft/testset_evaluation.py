"""Evaluate the base and fine-tuned models on the held-out test split."""

from __future__ import annotations

import gc
import json
import os
import re
import shutil
import tempfile
from concurrent.futures import ThreadPoolExecutor
from pathlib import Path
from typing import Any, Sequence

import torch
import torch.nn.functional as F
from tqdm.auto import tqdm

from .collator import CompletionOnlyCollator
from .config import AppConfig, load_config
from .data import (
    IGNORE_INDEX,
    RawExample,
    TrainingDataset,
    chat_template_token_ids,
    load_records,
    split_prompt,
    split_records,
)
from .modeling import load_evaluation_model, load_tokenizer
from .source_verification import SourceResolver, verify_prediction


_FUNCTION_CLAUSE = re.compile(
    r"(?im)^\s*(?:requires|ensures|assigns|allocates|frees|decreases|"
    r"terminates|exits|breaks|continues|returns|behavior|complete\s+behaviors|"
    r"disjoint\s+behaviors)\b"
)
_LOOP_INVARIANT = re.compile(r"(?im)^\s*loop\s+invariant\b")
_LOOP_CLAUSE = re.compile(r"(?im)^\s*loop\s+(?:invariant|assigns|variant|behavior)\b")
_GROUPS = ("function", "loop", "overall")


def _model_device(model: Any) -> torch.device:
    for parameter in model.parameters():
        if parameter.device.type != "meta":
            return parameter.device
    raise RuntimeError("The evaluation model has no materialized parameters")


def _per_sample_ground_truth_losses(
    model: Any,
    tokenizer: Any,
    records: Sequence[RawExample],
    config: AppConfig,
) -> dict[str, float]:
    dataset = TrainingDataset(records, tokenizer, config.data)
    collator = CompletionOnlyCollator(
        tokenizer.pad_token_id,
        config.data.pad_to_multiple_of,
    )
    device = _model_device(model)
    batch_size = int(config.evaluation.batch_size)
    losses: dict[str, float] = {}
    with torch.inference_mode():
        for start in tqdm(
            range(0, len(dataset), batch_size),
            desc="Ground-truth loss",
            unit="batch",
            dynamic_ncols=True,
        ):
            features = [
                dataset[index]
                for index in range(start, min(start + batch_size, len(dataset)))
            ]
            batch = collator(features)
            sample_ids = batch["sample_id"]
            labels = batch["labels"].to(device)
            model_inputs = {
                key: batch[key].to(device)
                for key in ("input_ids", "attention_mask")
            }
            logits = model(**model_inputs).logits
            shift_logits = logits[:, :-1, :].contiguous().float()
            shift_labels = labels[:, 1:].contiguous()
            mask = shift_labels.ne(IGNORE_INDEX)
            counts = mask.sum(dim=1)
            if counts.eq(0).any():
                raise ValueError("A test sample has no ground-truth completion tokens")
            token_losses = F.cross_entropy(
                shift_logits.reshape(-1, shift_logits.shape[-1]),
                shift_labels.reshape(-1),
                ignore_index=IGNORE_INDEX,
                reduction="none",
            ).view_as(shift_labels)
            sample_losses = (token_losses * mask).sum(dim=1) / counts
            for sample_id, loss in zip(sample_ids, sample_losses.tolist(), strict=True):
                losses[sample_id] = float(loss)
    return losses


def _prompt_ids(tokenizer: Any, example: RawExample, config: AppConfig) -> list[int]:
    system_content, user_content = split_prompt(example)
    chat_template_kwargs = getattr(config.data, "chat_template_kwargs", {})
    prompt_ids = chat_template_token_ids(
        tokenizer,
        [
            {"role": "system", "content": system_content},
            {"role": "user", "content": user_content},
        ],
        chat_template_kwargs,
    )
    available = int(config.data.max_seq_length) - int(config.evaluation.max_new_tokens)
    if available <= 0:
        raise ValueError(
            "evaluation.max_new_tokens must be smaller than data.max_seq_length"
        )
    if len(prompt_ids) > available:
        prefix = available // 2
        suffix = available - prefix
        prompt_ids = prompt_ids[:prefix] + prompt_ids[-suffix:]
    return prompt_ids


def _generate_predictions(
    model: Any,
    tokenizer: Any,
    records: Sequence[RawExample],
    config: AppConfig,
) -> dict[str, str]:
    device = _model_device(model)
    batch_size = int(config.evaluation.batch_size)
    predictions: dict[str, str] = {}
    with torch.inference_mode():
        for start in tqdm(
            range(0, len(records), batch_size),
            desc="Generating ACSL",
            unit="batch",
            dynamic_ncols=True,
        ):
            examples = records[start : start + batch_size]
            prompts = [_prompt_ids(tokenizer, example, config) for example in examples]
            width = max(len(prompt) for prompt in prompts)
            input_ids: list[list[int]] = []
            attention_masks: list[list[int]] = []
            for prompt in prompts:
                padding = width - len(prompt)
                input_ids.append([tokenizer.pad_token_id] * padding + prompt)
                attention_masks.append([0] * padding + [1] * len(prompt))
            generated = model.generate(
                input_ids=torch.tensor(input_ids, dtype=torch.long, device=device),
                attention_mask=torch.tensor(
                    attention_masks,
                    dtype=torch.long,
                    device=device,
                ),
                max_new_tokens=int(config.evaluation.max_new_tokens),
                do_sample=bool(config.evaluation.do_sample),
                num_beams=int(config.evaluation.num_beams),
                repetition_penalty=float(config.evaluation.repetition_penalty),
                eos_token_id=tokenizer.eos_token_id,
                pad_token_id=tokenizer.pad_token_id,
            )
            for example, sequence in zip(examples, generated, strict=True):
                predictions[example.sample_id] = tokenizer.decode(
                    sequence[width:],
                    skip_special_tokens=True,
                ).strip()
    return predictions


def _protocol_metrics(prediction: str, target_type: str) -> dict[str, bool]:
    stripped = prediction.strip()
    wrapper_valid = bool(
        stripped.startswith("/*@")
        and stripped.endswith("*/")
        and stripped.count("/*@") == 1
        and stripped.count("*/") == 1
    )
    payload = ""
    if wrapper_valid:
        lines: list[str] = []
        for line in stripped[3:-2].splitlines():
            normalized = line.strip()
            if normalized.startswith("*"):
                normalized = normalized[1:].strip()
            lines.append(normalized)
        payload = "\n".join(lines)
    has_function_clause = bool(_FUNCTION_CLAUSE.search(payload))
    has_loop_clause = bool(_LOOP_CLAUSE.search(payload))
    has_loop_invariant = bool(_LOOP_INVARIANT.search(payload))
    if target_type == "function":
        target_type_valid = has_function_clause and not has_loop_clause
    else:
        target_type_valid = has_loop_invariant and not has_function_clause
    return {
        "wrapper_valid": wrapper_valid,
        "target_type_structure_valid": target_type_valid,
        "protocol_compliant": wrapper_valid and target_type_valid,
    }


def _verify_predictions(
    records: Sequence[RawExample],
    predictions: dict[str, str],
    config: AppConfig,
) -> list[dict[str, Any]]:
    resolver = SourceResolver(config.resolve(config.evaluation.source_dir))

    def verify(example: RawExample) -> dict[str, Any]:
        return verify_prediction(
            example,
            predictions[example.sample_id],
            resolver,
            config.evaluation.frama_c,
        )

    with ThreadPoolExecutor(max_workers=int(config.evaluation.frama_c.workers)) as executor:
        return list(
            tqdm(
                executor.map(verify, records),
                total=len(records),
                desc="Frama-C/WP",
                unit="sample",
                dynamic_ncols=True,
            )
        )


def _members(rows: Sequence[dict[str, Any]], group: str) -> list[dict[str, Any]]:
    return list(rows) if group == "overall" else [row for row in rows if row["type"] == group]


def _rates(rows: Sequence[dict[str, Any]], field: str) -> dict[str, dict[str, float | int]]:
    result: dict[str, dict[str, float | int]] = {}
    for group in _GROUPS:
        members = _members(rows, group)
        passed = sum(bool(row[field]) for row in members)
        result[group] = {
            "passed": passed,
            "total": len(members),
            "rate": round(passed / len(members), 8) if members else 0.0,
        }
    return result


def _loss_summary(rows: Sequence[dict[str, Any]]) -> dict[str, float | None]:
    result: dict[str, float | None] = {}
    for group in ("overall", "function", "loop"):
        members = _members(rows, group)
        result[group] = (
            round(sum(float(row["ground_truth_loss"]) for row in members) / len(members), 8)
            if members
            else None
        )
    return result


def _build_report(
    records: Sequence[RawExample],
    losses: dict[str, float],
    predictions: dict[str, str],
    verification: Sequence[dict[str, Any]],
) -> dict[str, Any]:
    rows: list[dict[str, Any]] = []
    for example, frama in zip(records, verification, strict=True):
        protocol = _protocol_metrics(predictions[example.sample_id], example.target_type)
        row: dict[str, Any] = {
            "sample_id": example.sample_id,
            "type": example.target_type,
            "prediction": predictions[example.sample_id],
            "ground_truth_loss": round(losses[example.sample_id], 8),
            **protocol,
            **frama,
        }
        row["target_type_correct"] = bool(
            row["target_type_structure_valid"] and row["frama_c_parse_success"]
        )
        rows.append(row)

    report: dict[str, Any] = {}
    report["full_test_ground_truth_loss"] = _loss_summary(rows)
    report["group_statistics"] = {
        group: {"samples": len(_members(rows, group))}
        for group in _GROUPS
    }
    report["output_protocol_compliance_rate"] = _rates(rows, "protocol_compliant")
    report["frama_c_parse_success_rate"] = _rates(rows, "frama_c_parse_success")
    report["target_type_correctness_rate"] = _rates(rows, "target_type_correct")
    report["wp_all_goals_proved_rate"] = _rates(rows, "wp_all_goals_proved")
    report["samples"] = rows
    return report


def _evaluate_one_model(
    name: str,
    config: AppConfig,
    tokenizer: Any,
    test_records: Sequence[RawExample],
    adapter_path: Path | None,
) -> dict[str, Any]:
    print(f"\nEvaluating {name}...", flush=True)
    model = load_evaluation_model(config, adapter_path)
    try:
        losses = _per_sample_ground_truth_losses(model, tokenizer, test_records, config)
        predictions = _generate_predictions(model, tokenizer, test_records, config)
    finally:
        del model
        gc.collect()
        if torch.cuda.is_available():
            torch.cuda.empty_cache()
    verification = _verify_predictions(test_records, predictions, config)
    return _build_report(test_records, losses, predictions, verification)


def _validate_evaluation_environment(config: AppConfig) -> tuple[Path, Path]:
    if not torch.cuda.is_available():
        raise RuntimeError("Test-set evaluation requires a CUDA GPU")
    adapter = config.resolve(config.evaluation.adapter_dir)
    if not (adapter / "adapter_config.json").is_file():
        raise FileNotFoundError(f"Best trained adapter not found: {adapter}")
    source_dir = config.resolve(config.evaluation.source_dir)
    if not source_dir.is_dir():
        raise FileNotFoundError(f"Evaluation source directory not found: {source_dir}")
    executable = str(config.evaluation.frama_c.executable)
    if shutil.which(executable) is None:
        raise FileNotFoundError(f"Frama-C executable not found: {executable}")
    output_dir = config.resolve(config.evaluation.output_dir)
    output_dir.mkdir(parents=True, exist_ok=True)
    return adapter, output_dir


def run(config_path: str | Path) -> None:
    os.environ.setdefault("HF_HUB_OFFLINE", "1")
    os.environ.setdefault("TRANSFORMERS_OFFLINE", "1")
    os.environ.setdefault("TOKENIZERS_PARALLELISM", "false")
    config = load_config(config_path)
    adapter, output_dir = _validate_evaluation_environment(config)
    records = load_records(config.resolve(config.data.input_dir))
    test_records = split_records(records, config.data).test
    if not test_records:
        raise ValueError("The configured test split is empty")
    print(f"Held-out test records: {len(test_records)}", flush=True)
    tokenizer = load_tokenizer(config)

    base_report = _evaluate_one_model(
        "base model",
        config,
        tokenizer,
        test_records,
        None,
    )
    _atomic_write_json(output_dir / "base_model.json", base_report)

    finetuned_report = _evaluate_one_model(
        "base model + trained adapter",
        config,
        tokenizer,
        test_records,
        adapter,
    )
    _atomic_write_json(output_dir / "finetuned_model.json", finetuned_report)
    print(f"Evaluation results: {output_dir}", flush=True)


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
