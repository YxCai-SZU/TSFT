"""Shared constants and value objects for training-data generation."""

from __future__ import annotations

import re
from dataclasses import dataclass
from typing import Any

FUNCTION_CONTRACT = "function_contract"
LOOP_CONTRACT = "loop_contract"
CODE_ANNOTATION = "code_annotation"
BACKGROUND = "background"
NORMAL_COMMENT = "normal_comment"

_LOOP_CLAUSE = re.compile(
    r"(?im)^\s*loop\s+(?:invariant|assigns|variant|behavior)\b"
)
_FUNCTION_CLAUSE = re.compile(
    r"(?im)^\s*(?:"
    r"requires|ensures|assigns|allocates|frees|decreases|terminates|"
    r"exits|breaks|continues|returns|behavior|complete\s+behaviors|"
    r"disjoint\s+behaviors"
    r")\b"
)
_CODE_ANNOTATION = re.compile(
    r"(?is)^\s*(?:assert|check|admit|ghost|unreachable)\b"
)

PROMPT_TEMPLATE = r"""You are given a target C function or loop for which an ACSL specification must be generated.

ACSL (ANSI/ISO C Specification Language) is a behavioral specification language embedded in C comments. An ACSL annotation starts with /*@ and ends with */. Depending on the target, it may contain clauses such as requires, ensures, assigns, behavior, loop invariant, loop assigns, and loop variant. ACSL specifications and C source code together form a complete verification input for tools such as Frama-C/WP.

Your task is to generate the ACSL specification for exactly the target function or target loop shown below.

The input may contain the following information:

- Background specification: File-level documentation, function descriptions, predicates, logic definitions, axiomatic declarations, and other non-target specification context.
- Current code: The implementation of the target function or loop. Existing local ACSL assertions may appear in the code and must be treated as proof obligations or proof guidance.
- Upstream context: Relevant code from a caller or an enclosing function/loop before control reaches the target.
- Downstream context: Contracts of directly called functions and specifications of directly nested loops.

Use the context only as supporting information. Generate a specification for the current target only. Do not reproduce specifications or assertions that already appear in the current code or context.

Specification requirements:

1. The specification must accurately describe the real behavior of the target code.

2. Use the background, upstream context, downstream contracts, nested-loop specifications, and existing local assertions whenever they provide useful semantic or verification information.

3. Preconditions must be as weak as reasonably possible. Do not use requires \false, contradictory conditions, impossible conditions, or unjustified restrictions merely to make verification succeed.

4. The specification must be strong enough to support all relevant verification obligations, including local assertions, callee preconditions, caller expectations, function postconditions, loop preservation, memory safety, and other reachable proof goals.

5. For every array or pointer access, include the necessary and precise \valid or \valid_read conditions. Do not require a larger valid memory region than the code actually needs unless the implementation or downstream contracts require it.

6. assigns or loop assigns clauses must accurately describe every memory location and program variable that may be modified. Do not omit modified locations and do not include unrelated locations.

7. For a function target, generate one function contract. Use requires, assigns, ensures, behavior, or other function-contract clauses only when appropriate.

8. For a loop target, generate one loop specification with the loop invariant and loop assigns clauses needed to establish initialization, preservation, safety, and the properties required after the loop. A loop variant is optional: include it only when it is appropriate and useful for expressing or proving termination; it is not mandatory for every loop.

9. Existing local assert annotations are part of the provided code. Use them as verification requirements or hints, but do not copy them into the generated specification.

10. Downstream callee contracts and nested-loop specifications are trusted context. Use them when reasoning about the target, but do not repeat them in the output.

11. Do not generate a specification for any caller, callee, enclosing loop, or nested loop. Generate a specification for the current target only.

12. Do not output C code, Markdown fences, explanations, analysis, headings, or any text outside the ACSL annotation.

13. The output must contain exactly one syntactically valid ACSL annotation. It must start with /*@ and end with */.

===== TARGET TYPE =====
{target_type}

===== BACKGROUND SPECIFICATION =====
{background_spec}

===== CURRENT CODE =====
{current_code}

===== UPSTREAM CONTEXT =====
{upstream_context}

===== DOWNSTREAM CONTEXT =====
{downstream_context}

Generate the ACSL specification for the current target now."""


class PreprocessingError(RuntimeError):
    """Raised when labeled source data cannot be converted safely."""


@dataclass(frozen=True, slots=True)
class ByteSpan:
    start: int
    end: int


@dataclass(frozen=True, slots=True)
class CommentSpan:
    start: int
    end: int
    raw: bytes
    category: str


@dataclass(frozen=True, slots=True)
class GroundTruthLabel:
    span: ByteSpan
    text: str


@dataclass(slots=True)
class BuildResult:
    samples: list[dict[str, Any]]
    missing_labels: list[str]
    missing_downstream_labels: list[str]
    test_harnesses: list[str]
    skipped_incomplete_samples: dict[str, list[str]]
    invalid_source_files: dict[str, list[str]]


@dataclass(frozen=True, slots=True)
class TrainingSourceAudit:
    test_harnesses: list[str]
    invalid_source_files: dict[str, list[str]]
    labeled_functions: int
    labeled_loops: int


@dataclass(frozen=True, slots=True)
class AppendResult:
    added: int
    skipped: int
    total: int
    removed: int = 0


def _normalized_acsl_payload(raw: bytes) -> str:
    text = raw.decode("utf-8")
    if text.startswith("/*@"):
        text = text[3:-2] if text.endswith("*/") else text[3:]
    elif text.startswith("//@"):
        text = text[3:]
    lines: list[str] = []
    for line in text.splitlines() or [text]:
        line = re.sub(r"^\s*@\s?", "", line)
        lines.append(line)
    return "\n".join(lines).strip()


_ACSL_LABEL_PART = re.compile(r"/\*@(?P<block>.*?)\*/|//@(?P<line>[^\r\n]*)", re.DOTALL)


def _canonicalize_ground_truth_label(text: str) -> str:
    """Return one loss-ready ACSL block with one tab per non-empty body line."""

    normalized = text.replace("\r\n", "\n").replace("\r", "\n").strip()
    matches = list(_ACSL_LABEL_PART.finditer(normalized))
    if not matches:
        raise PreprocessingError("Ground-truth label contains no ACSL annotation")

    body_lines: list[str] = []
    cursor = 0
    for match in matches:
        if normalized[cursor:match.start()].strip():
            raise PreprocessingError(
                "Ground-truth label contains text outside ACSL annotations"
            )
        block = match.group("block")
        raw_lines = block.split("\n") if block is not None else [match.group("line") or ""]
        for raw_line in raw_lines:
            line = raw_line.strip()
            while line == "*" or line.startswith(("* ", "@ ")):
                line = "" if line == "*" else line[2:].strip()
            body_lines.append(line)
        cursor = match.end()
    if normalized[cursor:].strip():
        raise PreprocessingError(
            "Ground-truth label contains text outside ACSL annotations"
        )

    while body_lines and not body_lines[0]:
        body_lines.pop(0)
    while body_lines and not body_lines[-1]:
        body_lines.pop()
    if not body_lines or not any(body_lines):
        raise PreprocessingError("Ground-truth label body is empty")

    # Keep conjunctions on the same logical line in every loss target. Source
    # annotations often wrap immediately after && for display purposes.
    normalized_body = "\n".join(body_lines)
    normalized_body = re.sub(r"&&[ \t]*\n[ \t]*", "&& ", normalized_body)
    body_lines = normalized_body.split("\n")
    body = "\n".join(f"\t{line}" if line else "" for line in body_lines)
    return f"/*@\n{body}\n*/"

def _comment_category(raw: bytes) -> str:
    if not (raw.startswith(b"/*@") or raw.startswith(b"//@")):
        return NORMAL_COMMENT
    payload = _normalized_acsl_payload(raw)
    if _CODE_ANNOTATION.search(payload):
        return CODE_ANNOTATION
    if _LOOP_CLAUSE.search(payload):
        return LOOP_CONTRACT
    if _FUNCTION_CLAUSE.search(payload):
        return FUNCTION_CONTRACT
    return BACKGROUND
