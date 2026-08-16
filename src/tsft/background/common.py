"""Shared constants and result objects for background removal."""

from __future__ import annotations

import os
from pathlib import Path
import re
import tempfile
from dataclasses import dataclass

WP_SUMMARY = re.compile(r"Proved goals:\s*(\d+)\s*/\s*(\d+)", re.IGNORECASE)
IDENTIFIER = re.compile(r"[A-Za-z_]\w*")
DIRECT_DECLARATION = re.compile(r"(?<![\\\w])(?:predicate|logic|lemma)\b")
DIRECT_DEFINITION = re.compile(r"(?<![\\\w])(?:predicate|logic)\b")
FORMAL_BACKGROUND = re.compile(
    r"(?<![\\\w])(?:predicate|logic|lemma|axiomatic|axiom|inductive|type|model)\b"
)
UNSUPPORTED_DECLARATION = re.compile(
    r"(?im)^\s*(?:axiomatic|axiom|inductive|type|model|global\s+invariant)\b"
)
CONTRACT_OR_ASSERT = re.compile(
    r"(?im)^\s*(?:requires|ensures|assigns|allocates|frees|decreases|terminates|"
    r"exits|breaks|continues|returns|behavior|complete\s+behaviors|"
    r"disjoint\s+behaviors|loop\s+(?:invariant|assigns|variant|behavior)|assert)\b"
)
TRAINABLE_SPECIFICATION = re.compile(
    r"(?im)^\s*(?:requires|ensures|assigns|allocates|frees|decreases|terminates|"
    r"behavior|complete\s+behaviors|disjoint\s+behaviors|"
    r"loop\s+(?:invariant|assigns|variant|behavior))\b"
)


class TransformationError(ValueError):
    """Raised when a background declaration cannot be removed exactly."""

    def __init__(self, code: str, detail: str) -> None:
        super().__init__(detail)
        self.code = code
        self.detail = detail


@dataclass(frozen=True, slots=True)
class AnnotationSpan:
    start: int
    end: int
    style: str


@dataclass(frozen=True, slots=True)
class LogicDefinition:
    kind: str
    name: str
    parameters: tuple[str, ...]
    labels: tuple[str, ...]
    body: str


@dataclass(frozen=True, slots=True)
class TransformReport:
    source_bytes: int
    output_bytes: int
    definitions: int
    declaration_blocks_removed: int
    calls_expanded: int
    remaining_annotations: int


@dataclass(frozen=True, slots=True)
class VerificationReport:
    passed: bool
    returncode: int | None
    timeout: bool
    proved_goals: int
    total_goals: int
    seconds: float


@dataclass(frozen=True, slots=True)
class FileResult:
    relative_path: str
    status: str
    reason: str | None


def atomic_write_text(path: Path, content: str) -> None:
    path.parent.mkdir(parents=True, exist_ok=True)
    descriptor, temporary_name = tempfile.mkstemp(
        prefix=f".{path.name}.", suffix=".tmp", dir=path.parent
    )
    temporary = Path(temporary_name)
    try:
        with os.fdopen(descriptor, "w", encoding="utf-8", newline="") as handle:
            handle.write(content)
            handle.flush()
            os.fsync(handle.fileno())
        os.replace(temporary, path)
    except BaseException:
        temporary.unlink(missing_ok=True)
        raise
