"""Rewrite ACSL logical and relational expressions."""

from __future__ import annotations

import re

from .clauses import (
    _LOGICAL_OPERATORS,
    _QUANTIFIER_WORDS,
    _REFLECTED_RELATION,
    _RELATION_OPERATORS,
    _has_named_predicate,
    _normalized_keyword,
    _predicate_clauses,
    _replace_spans,
)

def _top_level_operators(
    expression: str,
    operators: Sequence[str],
) -> list[tuple[int, str]]:
    ordered = sorted(operators, key=len, reverse=True)
    closing = {"(": ")", "[": "]", "{": "}"}
    stack: list[str] = []
    matches: list[tuple[int, str]] = []
    index = 0
    while index < len(expression):
        character = expression[index]
        if character in {'"', "'"}:
            quote = character
            index += 1
            while index < len(expression):
                if expression[index] == "\\":
                    index += 2
                    continue
                if expression[index] == quote:
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
        if not stack:
            arrow = next(
                (
                    candidate
                    for candidate in ("<==>", "==>")
                    if expression.startswith(candidate, index)
                ),
                None,
            )
            if arrow is not None and arrow not in operators:
                index += len(arrow)
                continue
            operator = next(
                (
                    candidate
                    for candidate in ordered
                    if expression.startswith(candidate, index)
                ),
                None,
            )
            if operator is not None:
                matches.append((index, operator))
                index += len(operator)
                continue
        index += 1
    return matches


def _fully_parenthesized(expression: str) -> bool:
    if len(expression) < 2 or expression[0] != "(" or expression[-1] != ")":
        return False
    depth = 0
    index = 0
    while index < len(expression):
        character = expression[index]
        if character in {'"', "'"}:
            quote = character
            index += 1
            while index < len(expression):
                if expression[index] == "\\":
                    index += 2
                    continue
                if expression[index] == quote:
                    break
                index += 1
        elif character == "(":
            depth += 1
        elif character == ")":
            depth -= 1
            if depth == 0 and index != len(expression) - 1:
                return False
        index += 1
    return depth == 0


def _leading_quantifier(expression: str) -> tuple[str, str] | None:
    if re.match(r"^\\(?:forall|exists)\b", expression) is None:
        return None
    stack: list[str] = []
    closing = {"(": ")", "[": "]", "{": "}"}
    for index, character in enumerate(expression):
        if character in closing:
            stack.append(closing[character])
        elif stack and character == stack[-1]:
            stack.pop()
        elif character == ";" and not stack:
            return expression[: index + 1].strip(), expression[index + 1 :].strip()
    return None


def _split_top_level(
    expression: str,
    operator: str,
) -> list[str] | None:
    matches = _top_level_operators(expression, (operator,))
    if not matches:
        return None
    parts: list[str] = []
    cursor = 0
    for index, _ in matches:
        parts.append(expression[cursor:index].strip())
        cursor = index + len(operator)
    parts.append(expression[cursor:].strip())
    return parts if all(parts) else None


def _relation_chain(expression: str) -> tuple[list[str], list[str]] | None:
    matches = _top_level_operators(expression, _RELATION_OPERATORS)
    if not matches:
        return None
    operands: list[str] = []
    operators: list[str] = []
    cursor = 0
    for index, operator in matches:
        operand = expression[cursor:index].strip()
        if not operand:
            return None
        operands.append(operand)
        operators.append(operator)
        cursor = index + len(operator)
    final_operand = expression[cursor:].strip()
    if not final_operand:
        return None
    operands.append(final_operand)
    return operands, operators


def _expand_relation_chain(expression: str) -> str:
    chain = _relation_chain(expression)
    if chain is None:
        return expression
    operands, operators = chain
    if len(operators) < 2 or any(
        operator not in {"<", "<=", ">", ">="} for operator in operators
    ):
        return expression
    comparisons = (
        f"({operands[index]} {operator} {operands[index + 1]})"
        for index, operator in enumerate(operators)
    )
    return " && ".join(comparisons)


def _reflected_relation(expression: str) -> str:
    chain = _relation_chain(expression)
    if chain is None:
        return expression
    operands, operators = chain
    if len(operators) > 1 and any(
        operator not in {"<", "<=", ">", ">="} for operator in operators
    ):
        return expression
    reflected_operands = list(reversed(operands))
    reflected_operators = [
        _REFLECTED_RELATION[operator] for operator in reversed(operators)
    ]
    pieces = [reflected_operands[0]]
    for operator, operand in zip(reflected_operators, reflected_operands[1:]):
        pieces.extend((operator, operand))
    return " ".join(pieces)


def _fresh_quantifier_name(expression: str, original: str) -> str | None:
    used = set(re.findall(r"(?<![A-Za-z0-9_])[A-Za-z_][A-Za-z0-9_]*", expression))
    for candidate in ("idx", "index", "j", "k", "q", f"{original}_eq"):
        if candidate != original and candidate not in used:
            return candidate
    return None


def _rename_simple_quantifier(
    prefix: str,
    body: str,
) -> tuple[str, str]:
    match = re.fullmatch(
        r"(?P<head>\\(?:forall|exists)\s+(?:integer|boolean|real)\s+)"
        r"(?P<name>[A-Za-z_][A-Za-z0-9_]*)(?P<tail>\s*;)",
        prefix,
    )
    if match is None:
        return prefix, body
    original = match.group("name")
    shadow = re.compile(
        r"\\(?:forall|exists|lambda)\b[^;]*\b"
        + re.escape(original)
        + r"\b[^;]*;",
        re.DOTALL,
    )
    if shadow.search(body):
        return prefix, body
    fresh = _fresh_quantifier_name(prefix + " " + body, original)
    if fresh is None:
        return prefix, body
    identifier = re.compile(
        r"(?<![A-Za-z0-9_])" + re.escape(original) + r"(?![A-Za-z0-9_])"
    )
    renamed_prefix = match.group("head") + fresh + match.group("tail")
    return renamed_prefix, identifier.sub(fresh, body)


def _rewrite_predicate(
    expression: str,
    *,
    normalize_implications: bool = False,
    reflect_relations: bool = False,
    rename_quantifiers: bool = False,
) -> str:
    value = expression.strip()
    if not value:
        return expression
    if _fully_parenthesized(value):
        inner = _rewrite_predicate(
            value[1:-1],
            normalize_implications=normalize_implications,
            reflect_relations=reflect_relations,
            rename_quantifiers=rename_quantifiers,
        )
        return f"({inner})"

    quantifier = _leading_quantifier(value)
    if quantifier is not None:
        prefix, body = quantifier
        if rename_quantifiers:
            prefix, body = _rename_simple_quantifier(prefix, body)
        rewritten_body = _rewrite_predicate(
            body,
            normalize_implications=normalize_implications,
            reflect_relations=reflect_relations,
            rename_quantifiers=rename_quantifiers,
        )
        return f"{prefix} {rewritten_body}"

    equivalences = _top_level_operators(value, ("<==>",))
    if len(equivalences) == 1:
        index, operator = equivalences[0]
        left = _rewrite_predicate(
            value[:index],
            normalize_implications=normalize_implications,
            reflect_relations=reflect_relations,
            rename_quantifiers=rename_quantifiers,
        )
        right = _rewrite_predicate(
            value[index + len(operator) :],
            normalize_implications=normalize_implications,
            reflect_relations=reflect_relations,
            rename_quantifiers=rename_quantifiers,
        )
        if normalize_implications:
            return f"(!({left}) || ({right})) && (!({right}) || ({left}))"
        return f"{left} <==> {right}"

    implications = _top_level_operators(value, ("==>",))
    if implications:
        index, operator = implications[0]
        left = _rewrite_predicate(
            value[:index],
            normalize_implications=normalize_implications,
            reflect_relations=reflect_relations,
            rename_quantifiers=rename_quantifiers,
        )
        right = _rewrite_predicate(
            value[index + len(operator) :],
            normalize_implications=normalize_implications,
            reflect_relations=reflect_relations,
            rename_quantifiers=rename_quantifiers,
        )
        if normalize_implications:
            return f"!({left}) || ({right})"
        return f"{left} ==> {right}"

    for operator in ("||", "&&"):
        parts = _split_top_level(value, operator)
        if parts is not None:
            rewritten = [
                _rewrite_predicate(
                    part,
                    normalize_implications=normalize_implications,
                    reflect_relations=reflect_relations,
                    rename_quantifiers=rename_quantifiers,
                )
                for part in parts
            ]
            return f" {operator} ".join(rewritten)

    if value.startswith("!") and not value.startswith("!="):
        rewritten = _rewrite_predicate(
            value[1:],
            normalize_implications=normalize_implications,
            reflect_relations=reflect_relations,
            rename_quantifiers=rename_quantifiers,
        )
        return f"!({rewritten})"
    if normalize_implications:
        return _expand_relation_chain(value)
    if reflect_relations:
        return _reflected_relation(value)
    return value


def _transform_clause_expressions(
    body: str,
    *,
    normalize_implications: bool = False,
    reflect_relations: bool = False,
    rename_quantifiers: bool = False,
) -> str:
    replacements: list[tuple[int, int, str]] = []
    for clause in _predicate_clauses(body):
        transformed = _rewrite_predicate(
            clause.expression,
            normalize_implications=normalize_implications,
            reflect_relations=reflect_relations,
            rename_quantifiers=rename_quantifiers,
        )
        if transformed != clause.expression:
            replacements.append(
                (clause.expression_start, clause.expression_end, transformed)
            )
    return _replace_spans(body, replacements)
