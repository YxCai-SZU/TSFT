"""Inject predicted ACSL into original C sources and run Frama-C/WP."""

from __future__ import annotations

import hashlib
import re
import subprocess
import tempfile
import time
from dataclasses import dataclass
from pathlib import Path, PurePosixPath
from typing import Any

from .data import RawExample


FUNCTION_CONTRACT = "function_contract"
LOOP_CONTRACT = "loop_contract"
OTHER = "other"
_FUNCTION_CLAUSE = re.compile(
    r"(?im)^\s*(?:requires|ensures|assigns|allocates|frees|decreases|"
    r"terminates|exits|breaks|continues|returns|behavior|complete\s+behaviors|"
    r"disjoint\s+behaviors)\b"
)
_LOOP_CLAUSE = re.compile(r"(?im)^\s*loop\s+(?:invariant|assigns|variant|behavior)\b")
_LOCATION = re.compile(r"@(\d+):(\d+)(?:#\d+)?")
_WP_SUMMARY = re.compile(r"Proved goals:\s*(\d+)\s*/\s*(\d+)", re.IGNORECASE)


@dataclass(frozen=True)
class CommentSpan:
    start: int
    end: int
    category: str


@dataclass(frozen=True)
class PreparedSource:
    path: Path
    data: bytes
    contract_start: int
    contract_end: int
    target_start: int


def _payload(raw: bytes) -> str:
    text = raw.decode("utf-8")
    if text.startswith("/*@"):
        text = text[3:-2] if text.endswith("*/") else text[3:]
    elif text.startswith("//@"):
        text = text[3:]
    lines: list[str] = []
    for line in text.splitlines():
        stripped = line.strip()
        if stripped.startswith("*"):
            stripped = stripped[1:].strip()
        lines.append(stripped)
    return "\n".join(lines).strip()


def _category(raw: bytes) -> str:
    if not (raw.startswith(b"/*@") or raw.startswith(b"//@")):
        return OTHER
    payload = _payload(raw)
    if _LOOP_CLAUSE.search(payload):
        return LOOP_CONTRACT
    if _FUNCTION_CLAUSE.search(payload):
        return FUNCTION_CONTRACT
    return OTHER


def scan_comments(data: bytes) -> list[CommentSpan]:
    comments: list[CommentSpan] = []
    index = 0
    while index < len(data):
        byte = data[index]
        if byte in (ord('"'), ord("'")):
            quote = byte
            index += 1
            while index < len(data):
                if data[index] == ord("\\"):
                    index += 2
                    continue
                if data[index] == quote:
                    index += 1
                    break
                index += 1
            continue
        if byte == ord("/") and index + 1 < len(data):
            if data[index + 1] == ord("/"):
                start = index
                index += 2
                while index < len(data) and data[index] not in (10, 13):
                    index += 1
                comments.append(CommentSpan(start, index, _category(data[start:index])))
                continue
            if data[index + 1] == ord("*"):
                start = index
                terminator = data.find(b"*/", index + 2)
                index = len(data) if terminator < 0 else terminator + 2
                comments.append(CommentSpan(start, index, _category(data[start:index])))
                continue
        index += 1
    return comments


def canonical_annotation(text: str) -> str:
    normalized = text.replace("\r\n", "\n").replace("\r", "\n").strip()
    if normalized.startswith("//@"):
        lines = [line.strip()[3:].strip() for line in normalized.splitlines() if line.strip()]
    elif normalized.startswith("/*@") and normalized.endswith("*/"):
        lines = []
        for line in normalized[3:-2].splitlines():
            stripped = line.strip()
            if stripped.startswith("*"):
                stripped = stripped[1:].strip()
            lines.append(stripped)
    else:
        raise ValueError("annotation is not one ACSL block")
    while lines and not lines[0]:
        lines.pop(0)
    while lines and not lines[-1]:
        lines.pop()
    if not lines:
        raise ValueError("empty ACSL annotation")
    return "/*@\n" + "\n".join(f"\t{line}" if line else "" for line in lines) + "\n*/"


def _line_start(data: bytes, line: int) -> int:
    if line < 1:
        raise ValueError("source line must be positive")
    offset = 0
    for _ in range(line - 1):
        newline = data.find(b"\n", offset)
        if newline < 0:
            raise ValueError(f"line {line} is past EOF")
        offset = newline + 1
    return offset


def _target_start(data: bytes, example: RawExample) -> int:
    locations = list(_LOCATION.finditer(example.sample_id))
    if not locations:
        raise ValueError("sample_id has no source location")
    location = locations[-1]
    line = int(location.group(1))
    column = int(location.group(2))
    line_start = _line_start(data, line)
    target_offset = line_start + column - 1
    line_end = data.find(b"\n", line_start)
    if line_end < 0:
        line_end = len(data)
    if target_offset < line_start or target_offset > line_end:
        raise ValueError("sample_id source column is past the target line")

    # Function IDs point at the function name, not at the declaration's return
    # type. Function contracts therefore belong at the beginning of that line.
    if example.target_type == "function":
        return line_start

    # A loop usually starts on an indented line. If it follows another token on
    # the same line, preserve that prefix and insert immediately before the loop.
    return line_start if not data[line_start:target_offset].strip() else target_offset


def _contract_groups(
    data: bytes,
    comments: list[CommentSpan],
    category: str,
) -> list[tuple[int, int]]:
    groups: list[tuple[int, int]] = []
    index = 0
    while index < len(comments):
        comment = comments[index]
        if comment.category != category:
            index += 1
            continue
        start, end = comment.start, comment.end
        index += 1
        while index < len(comments):
            following = comments[index]
            if following.category != category or data[end:following.start].strip():
                break
            end = following.end
            index += 1
        groups.append((start, end))
    return groups


def locate_contract(data: bytes, example: RawExample) -> tuple[int, int]:
    locations = list(_LOCATION.finditer(example.sample_id))
    if not locations:
        raise ValueError("sample_id has no source location")
    target_line = int(locations[-1].group(1))
    target_offset = _line_start(data, target_line)
    category = FUNCTION_CONTRACT if example.target_type == "function" else LOOP_CONTRACT
    groups = _contract_groups(data, scan_comments(data), category)
    expected = canonical_annotation(example.label)

    candidates: list[tuple[int, int]] = []
    for start, end in groups:
        try:
            if canonical_annotation(data[start:end].decode("utf-8")) == expected:
                candidates.append((start, end))
        except (UnicodeDecodeError, ValueError):
            continue
    adjacent = [
        span
        for span in candidates
        if span[1] <= target_offset and not data[span[1]:target_offset].strip()
    ]
    if adjacent:
        return max(adjacent, key=lambda span: span[1])
    if candidates:
        return min(candidates, key=lambda span: abs(target_offset - span[1]))
    raise ValueError("ground-truth contract cannot be located in source")


class SourceResolver:
    def __init__(self, source_root: str | Path) -> None:
        self.root = Path(source_root).expanduser().resolve()
        if not self.root.is_dir():
            raise FileNotFoundError(f"Evaluation source directory not found: {self.root}")
        self._cache: dict[str, PreparedSource] = {}

    def prepare(self, example: RawExample) -> PreparedSource:
        cached = self._cache.get(example.sample_id)
        if cached is not None:
            return cached
        source_path = PurePosixPath(example.source_id)
        if source_path.is_absolute() or ".." in source_path.parts:
            raise ValueError(f"unsafe source path: {example.source_id}")
        relative = Path(*source_path.parts)
        direct = self.root / relative
        candidates = [direct] if direct.is_file() else []
        if not candidates:
            candidates = [
                path
                for path in self.root.rglob(relative.name)
                if path.is_file() and path.as_posix().endswith(source_path.as_posix())
            ]
        matches: list[PreparedSource] = []
        errors: list[str] = []
        for path in candidates:
            try:
                data = path.read_bytes()
                data.decode("utf-8")
                start, end = locate_contract(data, example)
                target_start = _target_start(data, example)
                if end > target_start:
                    raise ValueError("ground-truth contract overlaps the target code")
                matches.append(
                    PreparedSource(path.resolve(), data, start, end, target_start)
                )
            except (OSError, UnicodeError, ValueError) as exc:
                errors.append(f"{path}: {exc}")
        if not matches:
            detail = "; ".join(errors[:3]) or "source file not found"
            raise ValueError(f"cannot resolve {example.source_id}: {detail}")
        hashes = {hashlib.sha256(match.data).digest() for match in matches}
        if len(hashes) > 1:
            paths = ", ".join(str(match.path) for match in matches)
            raise ValueError(f"ambiguous source {example.source_id}: {paths}")
        self._cache[example.sample_id] = matches[0]
        return matches[0]


def inject_prediction(source: PreparedSource, prediction: str) -> bytes:
    source_prefix, code_snippet = _prediction_source_parts(source)
    return combine_model_output_with_code(
        prediction,
        code_snippet,
        source_prefix=source_prefix,
    ).encode("utf-8")


def _prediction_source_parts(source: PreparedSource) -> tuple[str, str]:
    """Remove the target GT and split the full source at the target code."""

    without_ground_truth = (
        source.data[:source.contract_start] + source.data[source.contract_end:]
    )
    removed_length = source.contract_end - source.contract_start
    target_start = source.target_start - removed_length
    return (
        without_ground_truth[:target_start].decode("utf-8"),
        without_ground_truth[target_start:].decode("utf-8"),
    )


def combine_model_output_with_code(
    model_output: str,
    code_snippet: str,
    *,
    source_prefix: str = "",
) -> str:
    """Combine a model-generated ACSL block and C code with one newline."""

    for name, value in (
        ("model_output", model_output),
        ("code_snippet", code_snippet),
        ("source_prefix", source_prefix),
    ):
        if not isinstance(value, str):
            raise TypeError(f"{name} must be a string")
        if "\x00" in value:
            raise ValueError(f"{name} cannot contain a NUL byte")
    return source_prefix + model_output.rstrip("\r\n") + "\n" + code_snippet


def create_combined_c_file(
    model_output: str,
    code_snippet: str,
    *,
    source_prefix: str = "",
    output_directory: str | Path | None = None,
) -> Path:
    """Write a generated ACSL/C program and return its caller-owned path.

    With no output directory, the file is created in the operating system's
    temporary directory. The caller owns its lifetime and may either unlink it
    after verification or retain it as a real-dataset evaluation artifact.
    """

    directory: Path | None = None
    if output_directory is not None:
        directory = Path(output_directory).expanduser().resolve()
        directory.mkdir(parents=True, exist_ok=True)
        if not directory.is_dir():
            raise NotADirectoryError(f"Output path is not a directory: {directory}")
    content = combine_model_output_with_code(
        model_output,
        code_snippet,
        source_prefix=source_prefix,
    )
    temporary_path: Path | None = None
    try:
        with tempfile.NamedTemporaryFile(
            mode="w",
            encoding="utf-8",
            newline="\n",
            prefix="tsft-generated-",
            suffix=".c",
            dir=directory,
            delete=False,
        ) as handle:
            temporary_path = Path(handle.name).resolve()
            handle.write(content)
            handle.flush()
        return temporary_path
    except OSError:
        if temporary_path is not None:
            temporary_path.unlink(missing_ok=True)
        raise


def _run(command: list[str], timeout: float, cwd: Path) -> dict[str, Any]:
    started = time.monotonic()
    try:
        process = subprocess.run(
            command,
            cwd=cwd,
            capture_output=True,
            text=True,
            encoding="utf-8",
            errors="replace",
            timeout=timeout,
            check=False,
        )
        output = (process.stdout + "\n" + process.stderr).strip()
        summaries = _WP_SUMMARY.findall(output)
        result: dict[str, Any] = {
            "returncode": process.returncode,
            "timeout": False,
            "seconds": round(time.monotonic() - started, 3),
            "output": output[-4000:],
        }
        if summaries:
            proved, total = summaries[-1]
            result["wp_summary"] = {
                "proved_goals": int(proved),
                "total_goals": int(total),
            }
        return result
    except subprocess.TimeoutExpired as exc:
        output = "\n".join(
            value.decode("utf-8", errors="replace") if isinstance(value, bytes) else value or ""
            for value in (exc.stdout, exc.stderr)
        ).strip()
        return {
            "returncode": None,
            "timeout": True,
            "seconds": round(time.monotonic() - started, 3),
            "output": output[-4000:],
        }


def _command(
    executable: str,
    source_file: Path,
    original_parent: Path,
    *,
    wp: bool,
    provers: str,
    wp_timeout: int,
) -> list[str]:
    command = [
        executable,
        "-kernel-warn-key",
        "annot-error=abort",
        f"-cpp-extra-args=-I{original_parent}",
    ]
    if wp:
        command.extend(
            [
                "-wp",
                "-wp-prover",
                provers,
                "-wp-timeout",
                str(wp_timeout),
                "-wp-prop=-@variant,-@terminates,-@decreases",
            ]
        )
    command.append(str(source_file))
    return command


def verify_prediction(
    example: RawExample,
    prediction: str,
    resolver: SourceResolver,
    frama_config: Any,
) -> dict[str, Any]:
    result: dict[str, Any] = {
        "source_file": None,
        "frama_c_parse_success": False,
        "wp_all_goals_proved": False,
    }
    try:
        source = resolver.prepare(example)
        result["source_file"] = str(source.path)
        source_prefix, code_snippet = _prediction_source_parts(source)
        generated_file = create_combined_c_file(
            prediction,
            code_snippet,
            source_prefix=source_prefix,
        )
        try:
            parse_result = _run(
                _command(
                    frama_config.executable,
                    generated_file,
                    source.path.parent,
                    wp=False,
                    provers=frama_config.provers,
                    wp_timeout=frama_config.wp_timeout,
                ),
                float(frama_config.process_timeout),
                source.path.parent,
            )
            result["parse"] = parse_result
            result["frama_c_parse_success"] = bool(
                parse_result["returncode"] == 0 and not parse_result["timeout"]
            )
            if not result["frama_c_parse_success"]:
                return result
            wp_result = _run(
                _command(
                    frama_config.executable,
                    generated_file,
                    source.path.parent,
                    wp=True,
                    provers=frama_config.provers,
                    wp_timeout=frama_config.wp_timeout,
                ),
                float(frama_config.process_timeout),
                source.path.parent,
            )
            result["wp"] = wp_result
            summary = wp_result.get("wp_summary")
            result["wp_all_goals_proved"] = bool(
                wp_result["returncode"] == 0
                and not wp_result["timeout"]
                and summary
                and summary["total_goals"] > 0
                and summary["proved_goals"] == summary["total_goals"]
            )
            return result
        finally:
            generated_file.unlink(missing_ok=True)
    except (OSError, TypeError, UnicodeError, ValueError) as exc:
        result["error"] = f"{type(exc).__name__}: {exc}"
        return result
