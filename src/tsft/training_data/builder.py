"""Build structured function and loop records from Clang analysis."""

from __future__ import annotations

from fnmatch import fnmatchcase
from pathlib import Path, PurePosixPath
import re
import textwrap
from typing import Any, Sequence

from Clang.model import AnalysisResult, CallSiteInfo, FunctionInfo, LoopInfo

from .candidates import _label_fields
from .common import (
    FUNCTION_CONTRACT,
    LOOP_CONTRACT,
    PROMPT_TEMPLATE,
    BuildResult,
    PreprocessingError,
    TrainingSourceAudit,
)
from .source import SourceDocument

def _resolve_display_path(project_root: Path, display_path: str) -> Path:
    candidate = Path(display_path)
    if candidate.is_absolute():
        return candidate.resolve()
    return (project_root / Path(*PurePosixPath(display_path).parts)).resolve()


def _sample_id(target_id: str, target_type: str, id_prefix: str) -> str:
    suffix = FUNCTION_CONTRACT if target_type == "function" else LOOP_CONTRACT
    base = f"{target_id}::{suffix}"
    return f"{id_prefix}::{base}" if id_prefix else base


def _looks_like_test_harness_name(name: str) -> bool:
    folded = name.casefold()
    if folded in {"main", "test", "tests", "harness", "test_harness"}:
        return True
    return (
        folded.startswith(("test_", "harness_"))
        or folded.endswith(("_test", "_tests", "_harness"))
        or bool(re.match(r"^(?:Test|Harness)(?:[A-Z0-9_].*)?$", name))
    )


def build_prompt(
    target_type: str,
    background_spec: str,
    current_code: str,
    upstream_context: Sequence[dict[str, Any]],
    downstream_context: Sequence[dict[str, Any]],
) -> str:
    background = background_spec if background_spec.strip() else "(none)"
    upstream = _format_prompt_contexts(upstream_context, "Upstream Context", "code")
    downstream = _format_prompt_contexts(
        downstream_context,
        "Downstream Context",
        "label",
    )
    return PROMPT_TEMPLATE.format(
        target_type=target_type,
        background_spec=background,
        current_code=current_code,
        upstream_context=upstream,
        downstream_context=downstream,
    )


def _format_prompt_contexts(
    contexts: Sequence[dict[str, Any]],
    context_name: str,
    multiline_field: str,
) -> str:
    if not contexts:
        return "[]"
    blocks: list[str] = []
    for index, context in enumerate(contexts, start=1):
        lines = [f"[{context_name} {index}]"]
        for key, value in context.items():
            if key == multiline_field:
                lines.append(f"{key}:\n{value}")
            else:
                lines.append(f"{key}: {value}")
        blocks.append("\n".join(lines))
    return "\n\n".join(blocks)


class TrainingDataBuilder:
    def __init__(
        self,
        analysis: AnalysisResult,
        project_root: str | Path,
        *,
        id_prefix: str = "",
        test_harness_patterns: Sequence[str] = (),
        allow_incomplete_context: bool = False,
    ) -> None:
        self.analysis = analysis
        self.project_root = Path(project_root).expanduser().resolve()
        self.id_prefix = id_prefix.strip(":")
        self.test_harness_patterns = tuple(
            pattern for pattern in test_harness_patterns if pattern
        )
        self.allow_incomplete_context = allow_incomplete_context
        self.functions = {function.id: function for function in analysis.functions}
        self.loops = {loop.id: loop for loop in analysis.loops}
        self.calls = {call.id: call for call in analysis.calls}
        self.documents: dict[str, SourceDocument] = {}
        self.function_labels: dict[str, GroundTruthLabel] = {}
        self.loop_labels: dict[str, GroundTruthLabel] = {}
        self.missing_labels: list[str] = []
        self.missing_downstream_labels: set[str] = set()
        self.test_harnesses: list[str] = []
        self.skipped_incomplete_samples: dict[str, list[str]] = {}
        self.invalid_source_files: dict[str, set[str]] = {}
        self._load_documents_and_labels()

    def document(self, display_path: str) -> SourceDocument:
        try:
            return self.documents[display_path]
        except KeyError as exc:
            raise PreprocessingError(f"No source document loaded for {display_path}") from exc

    def _load_documents_and_labels(self) -> None:
        source_paths = {
            node.location.file for node in [*self.analysis.functions, *self.analysis.loops]
        }
        for display_path in sorted(source_paths, key=str.casefold):
            self.documents[display_path] = SourceDocument(
                display_path,
                _resolve_display_path(self.project_root, display_path),
            )

        for function in self.analysis.functions:
            document = self.document(function.location.file)
            definition_start = document.source_span(function.range).start
            label = document.annotation_before(
                definition_start,
                FUNCTION_CONTRACT,
            )
            if label is None:
                label = document.declaration_contract_before(
                    function.name,
                    definition_start,
                )
            if label is None:
                if self._is_test_harness(function):
                    self.test_harnesses.append(function.id)
                else:
                    self.missing_labels.append(function.id)
                    self._invalidate_source(function.location.file, function.id)
            else:
                self.function_labels[function.id] = label

        for loop in self.analysis.loops:
            document = self.document(loop.location.file)
            label = document.annotation_before(
                document.source_span(loop.range).start,
                LOOP_CONTRACT,
            )
            if label is None:
                if loop.function_id not in self.test_harnesses:
                    self.missing_labels.append(loop.id)
                    self._invalidate_source(loop.location.file, loop.id)
            else:
                self.loop_labels[loop.id] = label

    def _invalidate_source(self, display_path: str, target_id: str) -> None:
        self.invalid_source_files.setdefault(display_path, set()).add(target_id)

    def _is_test_harness(self, function: FunctionInfo) -> bool:
        qualified_name = f"{function.location.file}::{function.name}"
        explicitly_selected = any(
            fnmatchcase(function.name.casefold(), pattern.casefold())
            or fnmatchcase(qualified_name.casefold(), pattern.casefold())
            for pattern in self.test_harness_patterns
        )
        if explicitly_selected:
            return True
        return not function.caller_ids and _looks_like_test_harness_name(function.name)

    def build(self) -> BuildResult:
        samples: list[dict[str, Any]] = []
        for function in self.analysis.functions:
            if function.location.file in self.invalid_source_files:
                continue
            if function.id in self.function_labels:
                sample = self._function_sample(function)
                if sample is not None:
                    samples.append(sample)
        for loop in self.analysis.loops:
            if loop.location.file in self.invalid_source_files:
                continue
            if loop.id in self.loop_labels:
                sample = self._loop_sample(loop)
                if sample is not None:
                    samples.append(sample)
        samples.sort(key=lambda sample: sample["sample_id"].casefold())
        return BuildResult(
            samples=samples,
            missing_labels=sorted(self.missing_labels),
            missing_downstream_labels=sorted(self.missing_downstream_labels),
            test_harnesses=sorted(self.test_harnesses),
            skipped_incomplete_samples={
                target_id: sorted(missing_ids)
                for target_id, missing_ids in sorted(
                    self.skipped_incomplete_samples.items()
                )
            },
            invalid_source_files={
                display_path: sorted(target_ids)
                for display_path, target_ids in sorted(
                    self.invalid_source_files.items()
                )
            },
        )

    def _function_sample(self, function: FunctionInfo) -> dict[str, Any] | None:
        document = self.document(function.location.file)
        span = document.source_span(function.range)
        label_fields = _label_fields(
            self.function_labels[function.id].text,
            "function",
        )
        background_spec = document.background_spec()
        current_code = document.render_code(span.start, span.end)
        downstream_context, missing_downstream = self._function_downstream(function)
        if missing_downstream and not self.allow_incomplete_context:
            self.skipped_incomplete_samples[function.id] = missing_downstream
            return None
        upstream_context = self._function_upstream(function)
        return {
            "sample_id": _sample_id(function.id, "function", self.id_prefix),
            "type": "function",
            "background_spec": background_spec,
            "current_code": current_code,
            "upstream_context": upstream_context,
            "downstream_context": downstream_context,
            "prompt": build_prompt(
                "function",
                background_spec,
                current_code,
                upstream_context,
                downstream_context,
            ),
            **label_fields,
        }

    def _loop_sample(self, loop: LoopInfo) -> dict[str, Any] | None:
        document = self.document(loop.location.file)
        span = document.source_span(loop.range)
        label_fields = _label_fields(
            self.loop_labels[loop.id].text,
            "loop",
        )
        background_spec = document.background_spec()
        current_code = document.render_code(span.start, span.end)
        downstream_context, missing_downstream = self._loop_downstream(loop)
        if missing_downstream and not self.allow_incomplete_context:
            self.skipped_incomplete_samples[loop.id] = missing_downstream
            return None
        upstream_context = self._loop_upstream(loop)
        return {
            "sample_id": _sample_id(loop.id, "loop", self.id_prefix),
            "type": "loop",
            "background_spec": background_spec,
            "current_code": current_code,
            "upstream_context": upstream_context,
            "downstream_context": downstream_context,
            "prompt": build_prompt(
                "loop",
                background_spec,
                current_code,
                upstream_context,
                downstream_context,
            ),
            **label_fields,
        }

    def _function_downstream(
        self,
        function: FunctionInfo,
    ) -> tuple[list[dict[str, Any]], list[str]]:
        events: list[tuple[int, int, str, str]] = []
        for loop in self.analysis.loops:
            if loop.function_id == function.id and loop.parent_loop_id is None:
                offset = self.document(loop.location.file).offset(loop.location)
                events.append((offset, 0, "loop", loop.id))

        seen_callees: set[str] = set()
        direct_calls = sorted(
            (
                call
                for call in self.analysis.calls
                if call.caller_id == function.id
                and call.resolution == "internal"
                and call.callee_id is not None
            ),
            key=lambda call: self.document(call.location.file).offset(call.location),
        )
        for call in direct_calls:
            callee_id = call.callee_id
            if callee_id == function.id or callee_id in seen_callees:
                continue
            seen_callees.add(callee_id)
            offset = self.document(call.location.file).offset(call.location)
            events.append((offset, 1, "function", callee_id))
        return self._downstream_entries(events)

    def _loop_downstream(
        self,
        loop: LoopInfo,
    ) -> tuple[list[dict[str, Any]], list[str]]:
        events: list[tuple[int, int, str, str]] = []
        for child_id in loop.child_loop_ids:
            child = self.loops[child_id]
            offset = self.document(child.location.file).offset(child.location)
            events.append((offset, 0, "loop", child.id))

        seen_callees: set[str] = set()
        for call in sorted(
            (self.calls[call_id] for call_id in loop.call_site_ids),
            key=lambda item: self.document(item.location.file).offset(item.location),
        ):
            if not call.loop_ids or call.loop_ids[-1] != loop.id:
                continue
            if call.resolution != "internal" or call.callee_id is None:
                continue
            if call.callee_id in seen_callees:
                continue
            seen_callees.add(call.callee_id)
            offset = self.document(call.location.file).offset(call.location)
            events.append((offset, 1, "function", call.callee_id))
        return self._downstream_entries(events)

    def _downstream_entries(
        self, events: Iterable[tuple[int, int, str, str]]
    ) -> tuple[list[dict[str, Any]], list[str]]:
        entries: list[dict[str, Any]] = []
        missing: set[str] = set()
        for _, _, target_type, target_id in sorted(events):
            if target_type == "function":
                target_file = self.functions[target_id].location.file
                label = (
                    None
                    if target_file in self.invalid_source_files
                    else self.function_labels.get(target_id)
                )
                relation = "direct_callee"
            else:
                target_file = self.loops[target_id].location.file
                label = (
                    None
                    if target_file in self.invalid_source_files
                    else self.loop_labels.get(target_id)
                )
                relation = "direct_child_loop"
            if label is None:
                self.missing_downstream_labels.add(target_id)
                missing.add(target_id)
                continue
            entries.append(
                {
                    "target_id": target_id,
                    "target_type": target_type,
                    "relation": relation,
                    "label": label.text,
                }
            )
        return entries, sorted(missing)

    def _function_upstream(self, function: FunctionInfo) -> list[dict[str, Any]]:
        contexts: list[dict[str, Any]] = []
        seen: set[tuple[str, int]] = set()
        incoming_calls = sorted(
            (
                call
                for call in self.analysis.calls
                if call.resolution == "internal" and call.callee_id == function.id
            ),
            key=lambda call: (
                call.location.file.casefold(),
                self.document(call.location.file).offset(call.location),
            ),
        )
        for call in incoming_calls:
            caller = self.functions[call.caller_id]
            if caller.location.file in self.invalid_source_files:
                continue
            document = self.document(caller.location.file)
            caller_span = document.source_span(caller.range)
            boundary = document.line_start(document.offset(call.location))
            key = (caller.id, boundary)
            if key in seen:
                continue
            seen.add(key)
            code = document.render_code(caller_span.start, boundary)
            if not code:
                continue
            contexts.append(
                {
                    "source_id": caller.id,
                    "source_type": "function",
                    "relation": "caller_prefix_before_call",
                    "call_site_id": call.id,
                    "code": code,
                }
            )
        return contexts

    def _loop_upstream(self, loop: LoopInfo) -> list[dict[str, Any]]:
        chain: list[LoopInfo] = [loop]
        cursor = loop
        while cursor.parent_loop_id is not None:
            cursor = self.loops[cursor.parent_loop_id]
            chain.append(cursor)
        chain.reverse()

        function = self.functions[loop.function_id]
        document = self.document(function.location.file)
        function_span = document.source_span(function.range)
        first_boundary = self.loop_labels[chain[0].id].span.start
        contexts: list[dict[str, Any]] = []
        function_code = document.render_code(function_span.start, first_boundary)
        if function_code:
            contexts.append(
                {
                    "source_id": function.id,
                    "source_type": "function",
                    "relation": (
                        "lexical_parent_prefix"
                        if len(chain) == 1
                        else "lexical_ancestor_prefix"
                    ),
                    "code": function_code,
                }
            )

        for index, ancestor in enumerate(chain[:-1]):
            child = chain[index + 1]
            ancestor_span = document.source_span(ancestor.range)
            boundary = self.loop_labels[child.id].span.start
            code = document.render_code(ancestor_span.start, boundary)
            if not code:
                continue
            contexts.append(
                {
                    "source_id": ancestor.id,
                    "source_type": "loop",
                    "relation": (
                        "lexical_parent_prefix"
                        if index == len(chain) - 2
                        else "lexical_ancestor_prefix"
                    ),
                    "code": code,
                }
            )
        return contexts


def build_training_samples(
    analysis: AnalysisResult,
    project_root: str | Path,
    *,
    id_prefix: str = "",
    test_harness_patterns: Sequence[str] = (),
    allow_incomplete_context: bool = False,
) -> BuildResult:
    return TrainingDataBuilder(
        analysis,
        project_root,
        id_prefix=id_prefix,
        test_harness_patterns=test_harness_patterns,
        allow_incomplete_context=allow_incomplete_context,
    ).build()


def audit_training_sources(
    analysis: AnalysisResult,
    project_root: str | Path,
    *,
    test_harness_patterns: Sequence[str] = (),
) -> TrainingSourceAudit:
    builder = TrainingDataBuilder(
        analysis,
        project_root,
        test_harness_patterns=test_harness_patterns,
    )
    return TrainingSourceAudit(
        test_harnesses=sorted(builder.test_harnesses),
        invalid_source_files={
            display_path: sorted(target_ids)
            for display_path, target_ids in sorted(
                builder.invalid_source_files.items()
            )
        },
        labeled_functions=len(builder.function_labels),
        labeled_loops=len(builder.loop_labels),
    )
