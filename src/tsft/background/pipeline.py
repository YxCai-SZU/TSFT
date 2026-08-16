"""Concurrent, resumable background-removal pipeline."""

from __future__ import annotations

import argparse
from collections import Counter
from concurrent.futures import FIRST_COMPLETED, Future, ThreadPoolExecutor, wait
from datetime import datetime, timezone
import os
from pathlib import Path
import shutil
import sqlite3
import subprocess
import time
from typing import Any, Iterable, Iterator

from .common import FileResult, TransformationError, atomic_write_text
from .expansion import transform_source
from .verification import ensure_tool_available, verify_with_wp

def process_file(
    source_path: Path,
    input_root: Path,
    output_root: Path,
    work_root: Path,
    args: argparse.Namespace,
) -> FileResult:
    relative = source_path.relative_to(input_root)
    relative_text = relative.as_posix()
    candidate: Path | None = None
    try:
        raw = source_path.read_bytes()
        try:
            source = raw.decode("utf-8")
        except UnicodeDecodeError as exc:
            raise TransformationError("non_utf8_source", str(exc)) from exc
        transformed, _report = transform_source(
            source, max_expanded_chars=args.max_expanded_chars
        )

        candidate = work_root / relative
        atomic_write_text(candidate, transformed)
        verification = verify_with_wp(
            candidate,
            frama_c=args.frama_c,
            prover=args.wp_prover,
            wp_timeout=args.wp_timeout,
            file_timeout=args.file_timeout,
            machdep=args.machdep,
            cpp_extra_args=args.cpp_extra_arg,
            wsl_distribution=args.wsl_distribution,
        )
        if not verification.passed:
            if verification.timeout:
                reason = "wp_timeout"
            elif verification.returncode != 0:
                reason = "frama_c_failed"
            elif verification.total_goals <= 0:
                reason = "no_wp_goals"
            else:
                reason = "wp_not_fully_proved"
            candidate.unlink(missing_ok=True)
            return FileResult(relative_text, "rejected", reason)

        destination = output_root / relative
        destination.parent.mkdir(parents=True, exist_ok=True)
        os.replace(candidate, destination)
        return FileResult(relative_text, "accepted", None)
    except TransformationError as exc:
        if candidate is not None:
            candidate.unlink(missing_ok=True)
        return FileResult(relative_text, "rejected", exc.code)
    except (OSError, RuntimeError, ValueError, subprocess.SubprocessError):
        if candidate is not None:
            candidate.unlink(missing_ok=True)
        return FileResult(relative_text, "error", "processing_error")


def open_resume_state(path: Path) -> sqlite3.Connection:
    connection = sqlite3.connect(path)
    connection.execute(
        "CREATE TABLE IF NOT EXISTS processed ("
        "relative_path TEXT PRIMARY KEY, status TEXT NOT NULL)"
    )
    connection.commit()
    return connection


def load_completed_state(
    connection: sqlite3.Connection, output_root: Path
) -> set[str]:
    completed: set[str] = set()
    for relative, status in connection.execute(
        "SELECT relative_path, status FROM processed"
    ):
        if status == "accepted":
            if (output_root / Path(*relative.split("/"))).is_file():
                completed.add(relative)
        elif status in {"rejected", "error"}:
            completed.add(relative)
    return completed


def discover_c_files(root: Path, maximum: int | None = None) -> list[Path]:
    """Discover C files deterministically without scanning past a requested limit."""

    discovered: list[Path] = []

    def visit(directory: Path) -> bool:
        try:
            with os.scandir(directory) as iterator:
                entries = sorted(iterator, key=lambda entry: entry.name.casefold())
        except OSError as exc:
            raise RuntimeError(f"cannot scan {directory}: {exc}") from exc
        for entry in entries:
            path = Path(entry.path)
            if entry.is_dir(follow_symlinks=False):
                if visit(path):
                    return True
            elif (
                entry.is_file(follow_symlinks=False)
                and entry.name.casefold().endswith(".c")
            ):
                discovered.append(path)
                if maximum is not None and len(discovered) >= maximum:
                    return True
        return False

    visit(root)
    return discovered


def iter_bounded_results(
    files: Iterable[Path],
    worker: Any,
    workers: int,
) -> Iterator[FileResult]:
    iterator = iter(files)
    pending: set[Future[FileResult]] = set()
    with ThreadPoolExecutor(max_workers=workers) as executor:
        for _ in range(workers * 2):
            try:
                pending.add(executor.submit(worker, next(iterator)))
            except StopIteration:
                break
        while pending:
            finished, pending = wait(pending, return_when=FIRST_COMPLETED)
            for future in finished:
                yield future.result()
                try:
                    pending.add(executor.submit(worker, next(iterator)))
                except StopIteration:
                    pass


def validate_roots(input_root: Path, output_root: Path) -> None:
    if not input_root.is_dir():
        raise ValueError(f"input directory does not exist: {input_root}")
    if input_root == output_root:
        raise ValueError("input and output directories must be different")
    try:
        output_root.relative_to(input_root)
    except ValueError:
        pass
    else:
        raise ValueError("output directory cannot be inside the input directory")


def remove_stale_work_directories(output_root: Path) -> None:
    for child in output_root.iterdir():
        if not child.is_dir() or not child.name.startswith(
            ".background-removal-work-"
        ):
            continue
        resolved = child.resolve()
        if resolved.parent != output_root:
            raise RuntimeError(f"unsafe stale work directory: {resolved}")
        shutil.rmtree(resolved)


def clean_dataset(args: argparse.Namespace) -> dict[str, Any]:
    input_root = Path(args.input_directory).expanduser().resolve()
    output_root = Path(args.output_directory).expanduser().resolve()
    validate_roots(input_root, output_root)
    ensure_tool_available(args.frama_c, args.wsl_distribution)

    output_root.mkdir(parents=True, exist_ok=True)
    remove_stale_work_directories(output_root)
    state_path = output_root / ".background-removal-state.sqlite3"
    existing_c_file = discover_c_files(output_root, 1) if not args.resume else []
    if (state_path.exists() or existing_c_file) and not args.resume:
        raise RuntimeError(
            f"output is not empty: {output_root}; use --resume or choose a new directory"
        )
    state = open_resume_state(state_path)
    if args.resume:
        completed = load_completed_state(state, output_root)
        if not completed:
            completed = {
                path.relative_to(output_root).as_posix()
                for path in discover_c_files(output_root)
            }
    else:
        completed = set()

    files = discover_c_files(input_root, args.max_files)
    selected_total = len(files)
    files = [
        path
        for path in files
        if path.relative_to(input_root).as_posix() not in completed
    ]
    if not files and selected_total == 0:
        raise RuntimeError(f"no C files found below {input_root}")

    run_id = datetime.now(timezone.utc).strftime("%Y%m%dT%H%M%SZ")
    work_root = output_root / f".background-removal-work-{run_id}-{os.getpid()}"
    work_root.mkdir(parents=True, exist_ok=False)
    counters: Counter[str] = Counter()
    started = time.monotonic()

    def worker(path: Path) -> FileResult:
        return process_file(path, input_root, output_root, work_root, args)

    finished = False
    try:
        for ordinal, result in enumerate(
            iter_bounded_results(files, worker, args.workers), start=1
        ):
            counters[result.status] += 1
            state.execute(
                "INSERT OR REPLACE INTO processed(relative_path, status) VALUES (?, ?)",
                (result.relative_path, result.status),
            )
            if ordinal % args.checkpoint_every == 0 or ordinal == len(files):
                state.commit()
            if not args.quiet and (
                ordinal == 1 or ordinal % args.progress_every == 0 or ordinal == len(files)
            ):
                elapsed = time.monotonic() - started
                rate = ordinal / elapsed if elapsed else 0.0
                print(
                    f"[{ordinal}/{len(files)}] kept={counters['accepted']} "
                    f"discarded={counters['rejected'] + counters['error']} "
                    f"rate={rate:.2f} files/s",
                    flush=True,
                )
        state.commit()
        finished = True
    finally:
        state.close()
        resolved_work = work_root.resolve()
        if resolved_work.parent == output_root and resolved_work.name.startswith(
            ".background-removal-work-"
        ):
            shutil.rmtree(resolved_work, ignore_errors=True)

    if finished:
        state_path.unlink(missing_ok=True)
    summary = {
        "selected": selected_total,
        "already_done": len(completed),
        "processed": len(files),
        "kept": counters["accepted"],
        "discarded": counters["rejected"] + counters["error"],
        "seconds": round(time.monotonic() - started, 3),
    }
    return summary
