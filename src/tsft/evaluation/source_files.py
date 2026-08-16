"""C/ACSL source manipulation and atomic evaluation artifacts."""

from __future__ import annotations

import json
import os
import re
import shutil
import tempfile
import textwrap
from pathlib import Path
from typing import Any

from .constants import (
    PROJECT_ROOT as _PROJECT_ROOT,
    EvaluationPipelineError,
    _FRAMA_C_DATASET_DIR,
)

_ACSL_ANNOTATION = re.compile(
    r"/\*@(?P<block>.*?)\*/|//@(?P<line>[^\r\n]*)",
    re.DOTALL,
)


def _task_file_slug(task_id: str) -> str:
    slug = re.sub(r"[^A-Za-z0-9._-]+", "_", task_id).strip("._-")
    return slug or "task"


def _source_work_slug(source: Path) -> str:
    resolved = source.expanduser().resolve()
    try:
        relative = resolved.relative_to(_PROJECT_ROOT)
    except ValueError:
        relative = resolved
    slug = re.sub(
        r"[^A-Za-z0-9._-]+",
        "_",
        relative.with_suffix("").as_posix(),
    ).strip("._-")
    return slug or resolved.stem or "source"


def _dataset_family(source: Path) -> str | None:
    """Identify benchmark-specific scheduling rules from path components.

    The checked-in datasets use ``*_Clean``/``*_GroundTruth`` directory names,
    while callers commonly pass a directory named simply ``oopsla`` or
    ``sygus``.  Matching components instead of the complete path keeps the
    rule independent of the checkout location.
    """

    for part in source.expanduser().resolve().parts:
        folded = part.casefold()
        if folded.replace("_", "-") == _FRAMA_C_DATASET_DIR:
            return "frama-c-problems"
        if (
            folded in {"oopsla_clean", "oopsla_groundtruth"}
            or folded == "oopsla"
            or folded.startswith("oopsla_")
        ):
            return "oopsla"
        if (
            folded in {"sygus_clean", "sygus_groundtruth"}
            or folded == "sygus"
            or folded.startswith("sygus_")
        ):
            return "sygus"
    return None


def _prepare_work_root(work_root: Path) -> Path:
    """Create a clean per-file work root for the current evaluation run."""

    if work_root.exists():
        if work_root.is_file() or work_root.is_symlink():
            work_root.unlink()
        else:
            shutil.rmtree(work_root)
    work_root.mkdir(parents=True, exist_ok=True)
    return work_root


def _combine_model_output_with_code(
    model_output: str,
    code_snippet: str,
    *,
    source_prefix: str = "",
    existing_contract: str | None = None,
) -> str:
    """Combine ACSL contract text and C source with one boundary newline.

    ``source_prefix`` should end immediately before the insertion point. The
    leading indentation of ``code_snippet`` is preserved by placing the ACSL
    block at the same indentation level as the target statement and then
    reattaching the original code line unchanged.  When ``existing_contract``
    is provided, its clauses and the generated clauses are emitted inside one
    ACSL annotation; adjacent standalone function contracts are not valid input
    for the target Frama-C configuration.
    """

    for name, value in (
        ("model_output", model_output),
        ("code_snippet", code_snippet),
        ("source_prefix", source_prefix),
        ("existing_contract", existing_contract),
    ):
        if value is not None and not isinstance(value, str):
            raise TypeError(f"{name} must be a string")
        if value is not None and "\x00" in value:
            raise ValueError(f"{name} cannot contain a NUL byte")

    if not code_snippet:
        raise ValueError("code_snippet cannot be empty")

    # Thinking mode is a generation-time chat-template feature. If a caller
    # passes raw text here, strip the private reasoning block before the text
    # reaches Frama-C or is persisted into the working source.
    final_model_output = _extract_final_generation_text(model_output)
    stripped_contract = (
        _merge_acsl_annotations(existing_contract, final_model_output)
        if existing_contract is not None
        else final_model_output
    )
    stripped_contract = textwrap.dedent(stripped_contract.strip())
    if not stripped_contract:
        raise ValueError("model_output cannot be empty after removing thinking text")
    code_indent = ""
    for code_line in code_snippet.splitlines():
        if code_line.strip():
            code_indent_match = re.match(r"[ \t]*", code_line)
            code_indent = "" if code_indent_match is None else code_indent_match.group(0)
            break
    indented_contract = "\n".join(
        (code_indent + line) if line.strip() else line
        for line in stripped_contract.splitlines()
    )
    return source_prefix + indented_contract + "\n" + code_snippet


def _acsl_annotation_body(annotation: str) -> str:
    """Extract the bodies of one or more adjacent ACSL annotations."""

    normalized = annotation.replace("\r\n", "\n").replace("\r", "\n").strip()
    matches = list(_ACSL_ANNOTATION.finditer(normalized))
    if not matches:
        raise ValueError("ACSL contract must contain an annotation")
    bodies: list[str] = []
    cursor = 0
    for match in matches:
        if normalized[cursor : match.start()].strip():
            raise ValueError("ACSL contract contains text outside annotations")
        block = match.group("block")
        raw_body = block if block is not None else (match.group("line") or "")
        lines = []
        for line in raw_body.splitlines() or [raw_body]:
            cleaned = re.sub(r"^\s*\* ?", "", line).rstrip()
            lines.append(cleaned)
        bodies.append("\n".join(lines).strip())
        cursor = match.end()
    if normalized[cursor:].strip():
        raise ValueError("ACSL contract contains text outside annotations")
    body = "\n".join(part for part in bodies if part).strip()
    if not body:
        raise ValueError("ACSL contract body is empty")
    return body


def _merge_acsl_annotations(
    existing_contract: str | None,
    generated_contract: str,
) -> str:
    if existing_contract is None:
        return generated_contract
    existing_body = _acsl_annotation_body(existing_contract)
    generated_body = _acsl_annotation_body(generated_contract)
    return f"/*@\n{existing_body}\n{generated_body}\n*/"


def _extract_final_generation_text(text: str) -> str:
    """Drop Qwen thinking blocks and return only the final completion."""

    if not isinstance(text, str):
        raise TypeError("text must be a string")
    final_text = text
    closing_tag = "</think>"
    if closing_tag in final_text:
        final_text = final_text.rsplit(closing_tag, 1)[1]
    else:
        # A malformed/incomplete thinking block must not be sent to Frama-C as
        # if it were an ACSL completion.  Keep ordinary non-thinking output
        # unchanged, but discard an unmatched leading block when detectable.
        opening_tag = "<think>"
        if final_text.lstrip().startswith(opening_tag):
            return ""
    return final_text.strip()


def _c_brace_depth(source: bytes) -> int:
    """Return the unmatched C compound-brace depth in ``source``.

    Comments and string/character literals are ignored so braces in ACSL
    text, diagnostics, or string constants do not affect the synthetic
    verification fragment's closing braces.
    """

    depth = 0
    state = "code"
    escaped = False
    index = 0
    while index < len(source):
        current = source[index]
        following = source[index + 1] if index + 1 < len(source) else None
        if state == "code":
            if current == ord("/") and following == ord("/"):
                state = "line_comment"
                index += 2
                continue
            if current == ord("/") and following == ord("*"):
                state = "block_comment"
                index += 2
                continue
            if current == ord('"'):
                state = "string"
                escaped = False
            elif current == ord("'"):
                state = "character"
                escaped = False
            elif current == ord("{"):
                depth += 1
            elif current == ord("}"):
                depth -= 1
            index += 1
            continue
        if state == "line_comment":
            if current in {ord("\n"), ord("\r")}:
                state = "code"
            index += 1
            continue
        if state == "block_comment":
            if current == ord("*") and following == ord("/"):
                state = "code"
                index += 2
            else:
                index += 1
            continue
        if escaped:
            escaped = False
        elif current == ord("\\"):
            escaped = True
        elif (state == "string" and current == ord('"')) or (
            state == "character" and current == ord("'")
        ):
            state = "code"
        index += 1
    return depth


def _create_c_file(content: str, output_directory: str | Path | None = None) -> Path:
    """Write one ephemeral C verification file and return its path."""

    directory: Path | None = None
    if output_directory is not None:
        directory = Path(output_directory).expanduser().resolve()
        directory.mkdir(parents=True, exist_ok=True)
        if not directory.is_dir():
            raise NotADirectoryError(f"Output path is not a directory: {directory}")

    temporary_path: Path | None = None
    try:
        with tempfile.NamedTemporaryFile(
            mode="w",
            encoding="utf-8",
            newline="\n",
            prefix="scf-verification-",
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


def _create_combined_c_file(
    model_output: str,
    code_snippet: str,
    *,
    source_prefix: str = "",
    existing_contract: str | None = None,
    output_directory: str | Path | None = None,
) -> Path:
    """Create the ephemeral C file used as Frama-C verification input."""

    content = _combine_model_output_with_code(
        model_output,
        code_snippet,
        source_prefix=source_prefix,
        existing_contract=existing_contract,
    )
    return _create_c_file(content, output_directory)


def _create_task_verification_c_file(
    model_output: str,
    source_parts: dict[str, Any],
    *,
    output_directory: str | Path | None = None,
) -> Path:
    """Create a minimal fragment containing only the current target context.

    The persistent working copy still uses ``source_prefix`` and
    ``code_snippet`` from ``task_source_parts``.  Frama-C receives the
    separate verification fields, which stop at the current function target
    (or at the current loop, followed by synthetic closing braces) and omit
    unrelated functions later in the translation unit.
    """

    target_code = source_parts.get("verification_target_code")
    if not isinstance(target_code, str) or not target_code:
        raise EvaluationPipelineError(
            "task source parts do not contain verification_target_code"
        )
    verification_prefix = source_parts.get("verification_source_prefix", "")
    code_prefix = source_parts.get("verification_code_prefix", "")
    if not isinstance(verification_prefix, str) or not isinstance(code_prefix, str):
        raise TypeError("verification source prefixes must be strings")
    combined_target = _combine_model_output_with_code(
        model_output,
        target_code,
        source_prefix=code_prefix,
        existing_contract=source_parts.get("existing_contract"),
    )
    return _create_c_file(verification_prefix + combined_target, output_directory)


def _atomic_write_text(path: str | Path, content: str) -> Path:
    target = Path(path).expanduser().resolve()
    target.parent.mkdir(parents=True, exist_ok=True)
    temporary: Path | None = None
    try:
        with tempfile.NamedTemporaryFile(
            mode="w",
            encoding="utf-8",
            newline="\n",
            prefix=f".{target.name}.",
            suffix=".tmp",
            dir=target.parent,
            delete=False,
        ) as handle:
            temporary = Path(handle.name)
            handle.write(content)
            handle.flush()
            os.fsync(handle.fileno())
        os.replace(temporary, target)
        return target
    except OSError:
        if temporary is not None:
            temporary.unlink(missing_ok=True)
        raise


def _atomic_write_json(path: str | Path, payload: dict[str, Any]) -> Path:
    target = Path(path).expanduser().resolve()
    target.parent.mkdir(parents=True, exist_ok=True)
    temporary: Path | None = None
    try:
        with tempfile.NamedTemporaryFile(
            mode="w",
            encoding="utf-8",
            newline="\n",
            prefix=f".{target.name}.",
            suffix=".tmp",
            dir=target.parent,
            delete=False,
        ) as handle:
            temporary = Path(handle.name)
            json.dump(payload, handle, ensure_ascii=False, indent=2)
            handle.write("\n")
            handle.flush()
            os.fsync(handle.fileno())
        os.replace(temporary, target)
        return target
    except OSError:
        if temporary is not None:
            temporary.unlink(missing_ok=True)
        raise


def _copy_file(src: str | Path, dst: str | Path) -> Path:
    source = Path(src).expanduser().resolve()
    target = Path(dst).expanduser().resolve()
    target.parent.mkdir(parents=True, exist_ok=True)
    shutil.copy2(source, target)
    return target


def _resolve_existing_c_file(c_file: str | Path) -> Path:
    source = Path(c_file).expanduser().resolve()
    if not source.exists() or not source.is_file():
        raise EvaluationPipelineError(f"C source file does not exist: {source}")
    if source.suffix.casefold() != ".c":
        raise EvaluationPipelineError(f"Expected one .c source file, got: {source}")
    return source


def _write_json_artifact(directory: str | Path, prefix: str, payload: dict[str, Any]) -> Path:
    target_directory = Path(directory).expanduser().resolve()
    target_directory.mkdir(parents=True, exist_ok=True)
    if not target_directory.is_dir():
        raise NotADirectoryError(f"Output path is not a directory: {target_directory}")

    temporary: Path | None = None
    try:
        with tempfile.NamedTemporaryFile(
            mode="w",
            encoding="utf-8",
            newline="\n",
            prefix=prefix,
            suffix=".json",
            dir=target_directory,
            delete=False,
        ) as handle:
            temporary = Path(handle.name)
            json.dump(payload, handle, ensure_ascii=False, indent=2)
            handle.write("\n")
            handle.flush()
            os.fsync(handle.fileno())
        return temporary
    except OSError:
        if temporary is not None:
            temporary.unlink(missing_ok=True)
        raise
