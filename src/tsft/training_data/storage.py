"""Atomic JSON storage and progress reporting for generated records."""

from __future__ import annotations

import json
import os
from pathlib import Path
import sys
import tempfile
from typing import Any, Iterable, Sequence

from .builder import _resolve_display_path
from .common import AppendResult, PreprocessingError

def _load_existing_records(output_file: Path) -> list[dict[str, Any]]:
    if not output_file.exists():
        return []
    if not output_file.is_file():
        raise PreprocessingError(f"Output path is not a file: {output_file}")
    try:
        text = output_file.read_text(encoding="utf-8")
        payload = [] if not text.strip() else json.loads(text)
    except (OSError, json.JSONDecodeError) as exc:
        raise PreprocessingError(f"Cannot read existing output {output_file}: {exc}") from exc
    if not isinstance(payload, list):
        raise PreprocessingError(
            f"Existing output must contain a JSON array: {output_file}"
        )
    records: list[dict[str, Any]] = []
    for index, record in enumerate(payload):
        if not isinstance(record, dict) or not isinstance(record.get("sample_id"), str):
            raise PreprocessingError(
                f"Existing output record {index} must be an object with a string sample_id"
            )
        records.append(record)
    return records


def _atomic_write_json(output_file: Path, records: list[dict[str, Any]]) -> None:
    output_file.parent.mkdir(parents=True, exist_ok=True)
    temporary_path: Path | None = None
    try:
        with tempfile.NamedTemporaryFile(
            mode="w",
            encoding="utf-8",
            newline="\n",
            prefix=f".{output_file.name}.",
            suffix=".tmp",
            dir=output_file.parent,
            delete=False,
        ) as handle:
            temporary_path = Path(handle.name)
            json.dump(records, handle, ensure_ascii=False, indent=2)
            handle.write("\n")
            handle.flush()
            os.fsync(handle.fileno())
        os.replace(temporary_path, output_file)
    except OSError as exc:
        if temporary_path is not None:
            temporary_path.unlink(missing_ok=True)
        raise PreprocessingError(f"Cannot write output {output_file}: {exc}") from exc


def _next_output_file(output_directory: Path) -> Path:
    output_directory.mkdir(parents=True, exist_ok=True)
    if not output_directory.is_dir():
        raise PreprocessingError(
            f"Output directory path is not a directory: {output_directory}"
        )

    index = 1
    while True:
        candidate = output_directory / f"trainingData_{index}.json"
        if not candidate.exists():
            return candidate
        index += 1


def append_training_samples(
    output_file: str | Path,
    samples: Sequence[dict[str, Any]],
    *,
    excluded_source_files: Sequence[str] = (),
    id_prefix: str = "",
) -> AppendResult:
    path = Path(output_file).expanduser().resolve()
    existing = _load_existing_records(path)
    normalized_prefix = id_prefix.strip(":")
    excluded_prefixes = [
        (
            f"{normalized_prefix}::{display_path}::"
            if normalized_prefix
            else f"{display_path}::"
        )
        for display_path in excluded_source_files
    ]
    retained_existing = [
        record
        for record in existing
        if not any(
            record["sample_id"].startswith(prefix) for prefix in excluded_prefixes
        )
    ]
    removed = len(existing) - len(retained_existing)
    by_id: dict[str, dict[str, Any]] = {}
    for record in retained_existing:
        sample_id = record["sample_id"]
        if sample_id in by_id:
            raise PreprocessingError(
                f"Existing output contains duplicate sample_id: {sample_id}"
            )
        by_id[sample_id] = record

    additions: list[dict[str, Any]] = []
    skipped = 0
    for sample in samples:
        sample_id = sample.get("sample_id")
        if not isinstance(sample_id, str):
            raise PreprocessingError("Every new record must contain a string sample_id")
        previous = by_id.get(sample_id)
        if previous is not None:
            if previous != sample:
                raise PreprocessingError(
                    f"Conflicting record for sample_id {sample_id}. "
                    "Use a different output file or --id-prefix for another dataset."
                )
            skipped += 1
            continue
        by_id[sample_id] = sample
        additions.append(sample)

    combined = [*retained_existing, *additions]
    if additions or removed or not path.exists():
        _atomic_write_json(path, combined)
    return AppendResult(
        added=len(additions),
        skipped=skipped,
        total=len(combined),
        removed=removed,
    )


def _validated_invalid_source_paths(
    input_directory: Path,
    display_paths: Iterable[str],
) -> list[Path]:
    root = input_directory.resolve()
    paths: list[Path] = []
    for display_path in sorted(display_paths, key=str.casefold):
        path = _resolve_display_path(root, display_path).resolve()
        try:
            path.relative_to(root)
        except ValueError as exc:
            raise PreprocessingError(
                f"Refusing to delete invalid source outside input directory: {path}"
            ) from exc
        if path.suffix.casefold() != ".c":
            raise PreprocessingError(
                f"Refusing to delete invalid non-C source path: {path}"
            )
        if not path.is_file():
            raise PreprocessingError(
                f"Invalid source selected for deletion no longer exists: {path}"
            )
        paths.append(path)
    return paths


def delete_invalid_source_files(
    input_directory: str | Path,
    display_paths: Iterable[str],
) -> list[Path]:
    paths = _validated_invalid_source_paths(
        Path(input_directory).expanduser().resolve(),
        display_paths,
    )
    for path in paths:
        path.unlink()
    return paths


def _progress(event: str, current: int, total: int, source: Path, diagnostics: str) -> None:
    prefix = f"[{current}/{total}]"
    if event == "start":
        print(f"{prefix} Clang parsing: {source}", flush=True)
        return
    if event == "ok":
        print(f"{prefix} OK: {source.name}", flush=True)
        return
    print(f"{prefix} {event.upper()}: {source}", file=sys.stderr, flush=True)
    lines = [line.strip() for line in diagnostics.splitlines() if line.strip()]
    for line in lines[:5]:
        print(f"    {line}", file=sys.stderr)
    if len(lines) > 5:
        print(f"    ... {len(lines) - 5} more diagnostic line(s)", file=sys.stderr)
