"""Parse ACSL annotations and direct predicate/logic definitions."""

from __future__ import annotations

import re

from .common import (
    CONTRACT_OR_ASSERT,
    DIRECT_DECLARATION,
    DIRECT_DEFINITION,
    IDENTIFIER,
    UNSUPPORTED_DECLARATION,
    AnnotationSpan,
    LogicDefinition,
    TransformationError,
)

def scan_acsl_annotations(source: str) -> list[AnnotationSpan]:
    """Return ACSL comment spans while ignoring markers inside C strings/comments."""

    spans: list[AnnotationSpan] = []
    index = 0
    length = len(source)
    while index < length:
        character = source[index]
        if character in {'"', "'"}:
            quote = character
            index += 1
            while index < length:
                if source[index] == "\\":
                    index += 2
                    continue
                if source[index] == quote:
                    index += 1
                    break
                index += 1
            continue
        if source.startswith("//", index):
            end = source.find("\n", index + 2)
            if end < 0:
                end = length
            if source.startswith("//@", index):
                spans.append(AnnotationSpan(index, end, "line"))
            index = end
            continue
        if source.startswith("/*", index):
            terminator = source.find("*/", index + 2)
            if terminator < 0:
                raise TransformationError(
                    "unterminated_comment", f"unterminated block comment at offset {index}"
                )
            end = terminator + 2
            if source.startswith("/*@", index):
                spans.append(AnnotationSpan(index, end, "block"))
            index = end
            continue
        index += 1
    return spans


def annotation_payload(raw: str, style: str) -> str:
    if style == "block":
        if not raw.startswith("/*@") or not raw.endswith("*/"):
            raise TransformationError("invalid_annotation", "invalid ACSL block markers")
        return raw[3:-2]
    if not raw.startswith("//@"):
        raise TransformationError("invalid_annotation", "invalid ACSL line marker")
    return raw[3:]


def mask_line_comments(text: str) -> str:
    """Mask // comments inside an ACSL block while retaining all character offsets."""

    result = list(text)
    index = 0
    while index < len(text):
        if text.startswith("//", index):
            end = text.find("\n", index + 2)
            if end < 0:
                end = len(text)
            for offset in range(index, end):
                result[offset] = " "
            index = end
        else:
            index += 1
    return "".join(result)


def skip_whitespace(text: str, index: int) -> int:
    while index < len(text) and text[index].isspace():
        index += 1
    return index


def matching_delimiter(text: str, start: int, opening: str, closing: str) -> int:
    if start >= len(text) or text[start] != opening:
        raise TransformationError(
            "unbalanced_expression", f"expected {opening!r} at offset {start}"
        )
    depth = 1
    index = start + 1
    quote: str | None = None
    while index < len(text):
        character = text[index]
        if quote is not None:
            if character == "\\":
                index += 2
                continue
            if character == quote:
                quote = None
            index += 1
            continue
        if character in {'"', "'"}:
            quote = character
        elif character == opening:
            depth += 1
        elif character == closing:
            depth -= 1
            if depth == 0:
                return index
        index += 1
    raise TransformationError(
        "unbalanced_expression", f"missing {closing!r} for offset {start}"
    )


def split_top_level(text: str, delimiter: str = ",") -> list[str]:
    parts: list[str] = []
    start = 0
    stack: list[str] = []
    pairs = {")": "(", "]": "[", "}": "{"}
    quote: str | None = None
    index = 0
    while index < len(text):
        character = text[index]
        if quote is not None:
            if character == "\\":
                index += 2
                continue
            if character == quote:
                quote = None
            index += 1
            continue
        if character in {'"', "'"}:
            quote = character
        elif character in "([{":
            stack.append(character)
        elif character in ")]} ".rstrip():
            expected = pairs[character]
            if not stack or stack.pop() != expected:
                raise TransformationError(
                    "unbalanced_expression", f"unexpected {character!r} in {text!r}"
                )
        elif character == delimiter and not stack:
            parts.append(text[start:index].strip())
            start = index + 1
        index += 1
    if stack or quote is not None:
        raise TransformationError("unbalanced_expression", f"unbalanced text: {text!r}")
    parts.append(text[start:].strip())
    return [] if len(parts) == 1 and not parts[0] else parts


def parse_parameter_names(parameters: str) -> tuple[str, ...]:
    names: list[str] = []
    for declaration in split_top_level(parameters):
        identifiers = list(IDENTIFIER.finditer(declaration))
        if not identifiers:
            raise TransformationError(
                "invalid_parameter", f"cannot find a parameter name in {declaration!r}"
            )
        # Array dimensions may contain identifiers after the declared name. Prefer the
        # identifier immediately before the first '['; otherwise use the final token.
        bracket = declaration.find("[")
        eligible = [item for item in identifiers if bracket < 0 or item.start() < bracket]
        name = (eligible or identifiers)[-1].group(0)
        if name in names:
            raise TransformationError("duplicate_parameter", f"duplicate parameter {name}")
        names.append(name)
    return tuple(names)


def parse_label_names(labels: str | None) -> tuple[str, ...]:
    if labels is None:
        return ()
    names = tuple(part.strip() for part in split_top_level(labels) if part.strip())
    if any(not IDENTIFIER.fullmatch(name) for name in names):
        raise TransformationError("invalid_label", f"invalid logic label list {labels!r}")
    if len(set(names)) != len(names):
        raise TransformationError("duplicate_label", f"duplicate labels in {labels!r}")
    return names


def definition_end(text: str, body_start: int) -> int:
    """Find a definition's final semicolon, skipping quantifier/let separators."""

    stack: list[str] = []
    pairs = {")": "(", "]": "[", "}": "{"}
    quote: str | None = None
    index = body_start
    while index < len(text):
        character = text[index]
        if quote is not None:
            if character == "\\":
                index += 2
                continue
            if character == quote:
                quote = None
            index += 1
            continue
        if character in {'"', "'"}:
            quote = character
        elif character in "([{":
            stack.append(character)
        elif character in ")]} ".rstrip():
            expected = pairs[character]
            if not stack or stack.pop() != expected:
                raise TransformationError(
                    "unbalanced_definition", f"unexpected {character!r} at offset {index}"
                )
        elif character == ";" and not stack:
            remainder = text[index + 1 :].lstrip()
            if not remainder or re.match(
                r"(?:predicate|logic|lemma)\b", remainder, re.IGNORECASE
            ):
                return index
        index += 1
    raise TransformationError("unterminated_definition", "definition has no final semicolon")


def parse_name_and_labels(prefix: str) -> tuple[str, tuple[str, ...], str]:
    stripped = prefix.strip()
    labels_text: str | None = None
    if stripped.endswith("}"):
        opening = stripped.rfind("{")
        if opening < 0:
            raise TransformationError("invalid_label", f"invalid label syntax in {prefix!r}")
        labels_text = stripped[opening + 1 : -1]
        stripped = stripped[:opening].rstrip()
    identifiers = list(IDENTIFIER.finditer(stripped))
    if not identifiers:
        raise TransformationError("invalid_definition", f"missing symbol name in {prefix!r}")
    name_match = identifiers[-1]
    name = name_match.group(0)
    before_name = stripped[: name_match.start()].strip()
    if stripped[name_match.end() :].strip():
        raise TransformationError("invalid_definition", f"invalid symbol header {prefix!r}")
    return name, parse_label_names(labels_text), before_name


def parse_definition(text: str, match: re.Match[str]) -> tuple[LogicDefinition, int]:
    kind = match.group(0).lower()
    cursor = skip_whitespace(text, match.end())
    first_paren = text.find("(", cursor)
    first_equal = text.find("=", cursor)
    first_semicolon = text.find(";", cursor)
    if first_equal < 0 or (first_semicolon >= 0 and first_semicolon < first_equal):
        raise TransformationError(
            "uninterpreted_logic", f"{kind} declaration near offset {match.start()} has no definition"
        )

    if kind == "predicate":
        if first_paren >= 0 and first_paren < first_equal:
            header = text[cursor:first_paren]
            name, labels, prefix = parse_name_and_labels(header)
            if prefix:
                raise TransformationError(
                    "invalid_definition", f"unexpected predicate header prefix {prefix!r}"
                )
            close_paren = matching_delimiter(text, first_paren, "(", ")")
            parameters = parse_parameter_names(text[first_paren + 1 : close_paren])
            equal = skip_whitespace(text, close_paren + 1)
        else:
            header = text[cursor:first_equal]
            name, labels, prefix = parse_name_and_labels(header)
            if prefix:
                raise TransformationError(
                    "invalid_definition", f"unexpected predicate header prefix {prefix!r}"
                )
            parameters = ()
            equal = first_equal
    else:
        if first_paren >= 0 and first_paren < first_equal:
            header = text[cursor:first_paren]
            name, labels, return_type = parse_name_and_labels(header)
            if not return_type:
                raise TransformationError(
                    "invalid_definition", f"logic function {name} has no return type"
                )
            close_paren = matching_delimiter(text, first_paren, "(", ")")
            parameters = parse_parameter_names(text[first_paren + 1 : close_paren])
            equal = skip_whitespace(text, close_paren + 1)
        else:
            header = text[cursor:first_equal]
            name, labels, return_type = parse_name_and_labels(header)
            if not return_type:
                raise TransformationError(
                    "invalid_definition", f"logic constant {name} has no return type"
                )
            parameters = ()
            equal = first_equal

    if equal >= len(text) or text[equal] != "=":
        raise TransformationError(
            "unsupported_logic_header",
            f"{kind} {name} has a reads clause or unsupported text before '='",
        )
    body_start = equal + 1
    end = definition_end(text, body_start)
    body = text[body_start:end].strip()
    if not body:
        raise TransformationError("empty_definition", f"{kind} {name} has an empty body")
    return LogicDefinition(kind, name, parameters, labels, body), end + 1


def definitions_from_payload(payload: str) -> list[LogicDefinition]:
    cleaned = mask_line_comments(payload)
    if UNSUPPORTED_DECLARATION.search(cleaned):
        keyword = UNSUPPORTED_DECLARATION.search(cleaned)
        assert keyword is not None
        raise TransformationError(
            "unsupported_background",
            f"cannot strictly inline declaration starting with {keyword.group(0).strip()!r}",
        )
    if CONTRACT_OR_ASSERT.search(cleaned):
        raise TransformationError(
            "mixed_background_and_target",
            "one ACSL block contains both formal declarations and a contract/assertion",
        )

    definitions: list[LogicDefinition] = []
    covered_until = -1
    for match in DIRECT_DEFINITION.finditer(cleaned):
        if match.start() < covered_until:
            continue
        definition, covered_until = parse_definition(cleaned, match)
        definitions.append(definition)

    declared_count = sum(1 for _ in DIRECT_DEFINITION.finditer(cleaned))
    if declared_count != len(definitions):
        raise TransformationError(
            "unparsed_definition",
            f"parsed {len(definitions)} of {declared_count} predicate/logic declarations",
        )
    return definitions
