"""Locate, merge, and reorder ACSL predicate clauses."""

from __future__ import annotations

from dataclasses import dataclass
import re

@dataclass(frozen=True, slots=True)
class _PredicateClause:
    start: int
    end: int
    expression_start: int
    expression_end: int
    keyword: str
    expression: str


_PREDICATE_CLAUSE_START = re.compile(
    r"(?im)^(?P<indent>[ \t]*)(?P<keyword>"
    r"(?:for[ \t]+[^:\r\n]+:[ \t]*)?loop[ \t]+invariant|"
    r"requires|assumes|ensures|exits|breaks|continues|returns"
    r")\b[ \t]*"
)
_MERGEABLE_PREDICATE_KEYWORDS = {
    "requires",
    "assumes",
    "ensures",
    "loop invariant",
}
_QUANTIFIER_WORDS = {"forall", "exists", "lambda", "let"}
_LOGICAL_OPERATORS = ("<==>", "==>", "||", "&&")
_RELATION_OPERATORS = ("<=", ">=", "==", "!=", "<", ">")
_REFLECTED_RELATION = {
    "<": ">",
    "<=": ">=",
    ">": "<",
    ">=": "<=",
    "==": "==",
    "!=": "!=",
}


def _normalized_keyword(keyword: str) -> str:
    return re.sub(r"\s+", " ", keyword.strip()).casefold()


def _find_clause_end(text: str, start: int) -> int | None:
    """Find the terminating semicolon without stopping at a quantifier binder."""

    closing = {"(": ")", "[": "]", "{": "}"}
    stack: list[str] = []
    pending_top_level_binders = 0
    index = start
    while index < len(text):
        character = text[index]
        if character in {'"', "'"}:
            quote = character
            index += 1
            while index < len(text):
                if text[index] == "\\":
                    index += 2
                    continue
                if text[index] == quote:
                    index += 1
                    break
                index += 1
            continue
        if character in closing:
            stack.append(closing[character])
            index += 1
            continue
        if stack and character == stack[-1]:
            stack.pop()
            index += 1
            continue
        if character == "\\":
            word_match = re.match(r"\\([A-Za-z_][A-Za-z0-9_]*)", text[index:])
            if word_match is not None:
                if not stack and word_match.group(1) in _QUANTIFIER_WORDS:
                    pending_top_level_binders += 1
                index += len(word_match.group(0))
                continue
        if character == ";" and not stack:
            if pending_top_level_binders:
                pending_top_level_binders -= 1
                index += 1
                continue
            return index + 1
        index += 1
    return None


def _predicate_clauses(body: str) -> list[_PredicateClause]:
    clauses: list[_PredicateClause] = []
    occupied_until = 0
    for match in _PREDICATE_CLAUSE_START.finditer(body):
        if match.start() < occupied_until:
            continue
        end = _find_clause_end(body, match.end())
        if end is None:
            continue
        expression_start = match.end()
        expression_end = end - 1
        clauses.append(
            _PredicateClause(
                start=match.start(),
                end=end,
                expression_start=expression_start,
                expression_end=expression_end,
                keyword=_normalized_keyword(match.group("keyword")),
                expression=body[expression_start:expression_end].strip(),
            )
        )
        occupied_until = end
    return clauses


def _replace_spans(
    text: str,
    replacements: Sequence[tuple[int, int, str]],
) -> str:
    result = text
    for start, end, replacement in sorted(replacements, reverse=True):
        result = result[:start] + replacement + result[end:]
    return result


def _contiguous_clause_runs(
    body: str,
    clauses: Sequence[_PredicateClause],
) -> list[list[_PredicateClause]]:
    runs: list[list[_PredicateClause]] = []
    current: list[_PredicateClause] = []
    for clause in clauses:
        if (
            current
            and clause.keyword == current[-1].keyword
            and not body[current[-1].end:clause.start].strip()
        ):
            current.append(clause)
            continue
        if current:
            runs.append(current)
        current = [clause]
    if current:
        runs.append(current)
    return runs


def _has_named_predicate(expression: str) -> bool:
    return bool(re.match(r"^[A-Za-z_][A-Za-z0-9_]*\s*:", expression.strip()))


def _merge_equivalent_clauses(body: str) -> str:
    replacements: list[tuple[int, int, str]] = []
    clauses = _predicate_clauses(body)
    for run in _contiguous_clause_runs(body, clauses):
        if len(run) < 2 or run[0].keyword not in _MERGEABLE_PREDICATE_KEYWORDS:
            continue
        if any(_has_named_predicate(clause.expression) for clause in run):
            continue
        header = body[run[0].start:run[0].expression_start].rstrip() + " "
        joined = " && ".join(f"({clause.expression})" for clause in run)
        replacements.append((run[0].start, run[-1].end, header + joined + ";"))
    return _replace_spans(body, replacements)

def _reverse_equivalent_clause_runs(body: str) -> str:
    replacements: list[tuple[int, int, str]] = []
    clauses = _predicate_clauses(body)
    for run in _contiguous_clause_runs(body, clauses):
        if len(run) < 2 or run[0].keyword not in _MERGEABLE_PREDICATE_KEYWORDS:
            continue
        reversed_clauses = [body[clause.start:clause.end].strip() for clause in run]
        replacements.append(
            (run[0].start, run[-1].end, "\n".join(reversed(reversed_clauses)))
        )
    return _replace_spans(body, replacements)
