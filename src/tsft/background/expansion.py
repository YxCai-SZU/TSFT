"""Expand direct logic definitions and remove background declarations."""

from __future__ import annotations

import re

from .annotations import (
    annotation_payload,
    definitions_from_payload,
    mask_line_comments,
    matching_delimiter,
    scan_acsl_annotations,
    skip_whitespace,
    split_top_level,
)
from .common import (
    FORMAL_BACKGROUND,
    IDENTIFIER,
    TRAINABLE_SPECIFICATION,
    AnnotationSpan,
    LogicDefinition,
    TransformReport,
    TransformationError,
)

def substitute_identifier(text: str, name: str, replacement: str, *, wrap: bool) -> str:
    pattern = re.compile(rf"(?<![\\A-Za-z0-9_]){re.escape(name)}(?![A-Za-z0-9_])")
    value = f"({replacement})" if wrap else replacement
    return pattern.sub(lambda _match: value, text)


class DefinitionExpander:
    def __init__(self, definitions: dict[str, LogicDefinition], max_chars: int) -> None:
        self.definitions = definitions
        self.max_chars = max_chars
        self.calls_expanded = 0
        if definitions:
            alternatives = "|".join(
                re.escape(name) for name in sorted(definitions, key=len, reverse=True)
            )
            self.symbol_pattern: re.Pattern[str] | None = re.compile(
                rf"(?<![\\A-Za-z0-9_])(?:{alternatives})(?![A-Za-z0-9_])"
            )
        else:
            self.symbol_pattern = None

    def _instantiate(
        self,
        definition: LogicDefinition,
        arguments: Sequence[str],
        actual_labels: Sequence[str],
        stack: tuple[str, ...],
    ) -> str:
        if definition.name in stack:
            cycle = " -> ".join((*stack, definition.name))
            raise TransformationError("recursive_definition", f"recursive definition: {cycle}")
        if len(arguments) != len(definition.parameters):
            raise TransformationError(
                "argument_count",
                f"{definition.name} expects {len(definition.parameters)} arguments, "
                f"received {len(arguments)}",
            )

        labels = tuple(actual_labels)
        if definition.labels and not labels:
            if len(definition.labels) == 1:
                labels = ("Here",)
            else:
                raise TransformationError(
                    "logic_label_count",
                    f"{definition.name} requires {len(definition.labels)} explicit labels",
                )
        if len(labels) != len(definition.labels):
            raise TransformationError(
                "logic_label_count",
                f"{definition.name} expects {len(definition.labels)} labels, received {len(labels)}",
            )

        instantiated = definition.body
        for formal, actual in zip(definition.parameters, arguments, strict=True):
            instantiated = substitute_identifier(instantiated, formal, actual, wrap=True)
        for formal, actual in zip(definition.labels, labels, strict=True):
            instantiated = substitute_identifier(instantiated, formal, actual, wrap=False)
        expanded = self.expand(instantiated, (*stack, definition.name))
        self.calls_expanded += 1
        return f"({expanded})"

    def expand(self, expression: str, stack: tuple[str, ...] = ()) -> str:
        if self.symbol_pattern is None:
            return expression
        output: list[str] = []
        cursor = 0
        while True:
            match = self.symbol_pattern.search(expression, cursor)
            if match is None:
                output.append(expression[cursor:])
                break
            output.append(expression[cursor : match.start()])
            name = match.group(0)
            definition = self.definitions[name]
            after = skip_whitespace(expression, match.end())
            labels: list[str] = []
            if after < len(expression) and expression[after] == "{":
                label_end = matching_delimiter(expression, after, "{", "}")
                labels = split_top_level(expression[after + 1 : label_end])
                after = skip_whitespace(expression, label_end + 1)

            if after < len(expression) and expression[after] == "(":
                call_end = matching_delimiter(expression, after, "(", ")")
                arguments = split_top_level(expression[after + 1 : call_end])
                expanded_arguments = [self.expand(item, stack) for item in arguments]
                replacement = self._instantiate(
                    definition, expanded_arguments, labels, stack
                )
                output.append(replacement)
                cursor = call_end + 1
            elif not definition.parameters:
                replacement = self._instantiate(definition, (), labels, stack)
                output.append(replacement)
                cursor = after
            else:
                # Leave the token in place; the final residual-symbol check reports it.
                output.append(expression[match.start() : match.end()])
                cursor = match.end()

            if sum(len(part) for part in output) > self.max_chars:
                raise TransformationError(
                    "expansion_too_large",
                    f"expanded annotation exceeds {self.max_chars} characters",
                )
        result = "".join(output)
        if len(result) > self.max_chars:
            raise TransformationError(
                "expansion_too_large",
                f"expanded annotation exceeds {self.max_chars} characters",
            )
        return result


def background_removal_bounds(source: str, span: AnnotationSpan) -> tuple[int, int]:
    """Expand a declaration span to whole lines and remove following blank lines."""

    line_start = source.rfind("\n", 0, span.start) + 1
    start = line_start if not source[line_start : span.start].strip() else span.start

    newline = source.find("\n", span.end)
    if newline >= 0 and not source[span.end:newline].strip():
        end = newline + 1
    else:
        end = span.end

    while end < len(source):
        next_newline = source.find("\n", end)
        if next_newline < 0:
            if not source[end:].strip():
                end = len(source)
            break
        if source[end:next_newline].strip():
            break
        end = next_newline + 1
    return start, end


def transform_source(source: str, *, max_expanded_chars: int = 1_000_000) -> tuple[str, TransformReport]:
    spans = scan_acsl_annotations(source)
    background_spans: set[tuple[int, int]] = set()
    definitions: dict[str, LogicDefinition] = {}

    for span in spans:
        raw = source[span.start : span.end]
        payload = annotation_payload(raw, span.style)
        cleaned = mask_line_comments(payload)
        if not FORMAL_BACKGROUND.search(cleaned):
            continue
        background_spans.add((span.start, span.end))
        for definition in definitions_from_payload(payload):
            previous = definitions.get(definition.name)
            if previous is not None:
                raise TransformationError(
                    "duplicate_definition", f"multiple definitions of {definition.name}"
                )
            definitions[definition.name] = definition

    expander = DefinitionExpander(definitions, max_expanded_chars)
    pieces: list[str] = []
    cursor = 0
    remaining_annotations = 0
    for span in spans:
        raw = source[span.start : span.end]
        if (span.start, span.end) in background_spans:
            removal_start, removal_end = background_removal_bounds(source, span)
            pieces.append(source[cursor : max(cursor, removal_start)])
            cursor = max(cursor, removal_end)
            continue
        else:
            pieces.append(source[cursor : span.start])
            payload = annotation_payload(raw, span.style)
            expanded = expander.expand(payload)
            if span.style == "block":
                pieces.append("/*@" + expanded + "*/")
            else:
                if "\n" in expanded or "\r" in expanded:
                    expanded = " ".join(expanded.splitlines())
                pieces.append("//@" + expanded)
            remaining_annotations += 1
        cursor = span.end
    pieces.append(source[cursor:])
    transformed = "".join(pieces)

    for span in scan_acsl_annotations(transformed):
        payload = annotation_payload(transformed[span.start : span.end], span.style)
        if FORMAL_BACKGROUND.search(mask_line_comments(payload)):
            raise TransformationError(
                "background_remains", "formal background declaration remains after rewriting"
            )
    kept_payload = "\n".join(
        annotation_payload(transformed[item.start : item.end], item.style)
        for item in scan_acsl_annotations(transformed)
    )
    if not TRAINABLE_SPECIFICATION.search(mask_line_comments(kept_payload)):
        raise TransformationError(
            "no_trainable_target",
            "no function contract or loop specification remains after background removal",
        )

    return transformed, TransformReport(
        source_bytes=len(source.encode("utf-8")),
        output_bytes=len(transformed.encode("utf-8")),
        definitions=len(definitions),
        declaration_blocks_removed=len(background_spans),
        calls_expanded=expander.calls_expanded,
        remaining_annotations=remaining_annotations,
    )
