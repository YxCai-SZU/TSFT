"""Prompt construction for function and loop specification tasks."""

from __future__ import annotations

from pathlib import Path
from typing import Any, Iterable, Sequence

from Clang import AnalysisResult
from Clang.model import FunctionInfo, LoopInfo
from tsft.training_data import (
    FUNCTION_CONTRACT as _FUNCTION_CONTRACT,
    LOOP_CONTRACT as _LOOP_CONTRACT,
    SourceDocument as _PromptSourceDocument,
    build_prompt as _training_build_prompt,
)

from .constants import EvaluationPipelineError, _PROMPT_SECTIONS
from .analysis import (
    _analyze_one_c_file,
    _function_task_id,
    _loop_paths,
    _stable_loop_task_id,
    _task_graph_ids,
)
from .source_files import _c_brace_depth, _resolve_existing_c_file


def _evaluation_background_spec(document: _PromptSourceDocument) -> str:
    """Return source-level context shared by every task prompt.

    The training-data ``SourceDocument.background_spec`` intentionally omits
    function and loop contracts because those are labels during training. For
    evaluation, however, contracts already present in the input file are
    trusted source context. Include them in one frozen background string so a
    function precondition, for example, is available to every child-loop task
    as well as to the function task itself.
    """

    parts: list[str] = []
    base = document.background_spec().strip()
    if base:
        parts.append(base)
    for comment in document.comments:
        if comment.category not in {_FUNCTION_CONTRACT, _LOOP_CONTRACT}:
            continue
        text = document.decode(comment.start, comment.end).strip()
        if text:
            parts.append(text)
    return "\n\n".join(parts)


class _SingleTaskPromptBuilder:
    def __init__(
        self,
        task_graph: dict[str, Any],
        source: Path,
        analysis: AnalysisResult,
        *,
        require_downstream_contracts: bool,
    ) -> None:
        self.task_graph = task_graph
        self.source = source
        self.analysis = analysis
        self.require_downstream_contracts = require_downstream_contracts
        self.graph_task_ids = _task_graph_ids(task_graph)
        self.document = _PromptSourceDocument(source.name, source)
        source_background = task_graph.get("source_background_spec")
        self.source_background_spec = (
            source_background
            if isinstance(source_background, str)
            else _evaluation_background_spec(self.document)
        )
        self.functions = {function.id: function for function in analysis.functions}
        self.loops = {loop.id: loop for loop in analysis.loops}
        self.calls = {call.id: call for call in analysis.calls}
        self.loop_paths = _loop_paths(analysis)
        self.function_task_ids = {
            function_id: _function_task_id(function)
            for function_id, function in self.functions.items()
        }
        self.loop_task_ids = {
            loop_id: _stable_loop_task_id(
                self.functions[loop.function_id],
                loop,
                self.loop_paths[loop_id],
            )
            for loop_id, loop in self.loops.items()
        }
        self.function_by_task = {
            task_id: self.functions[function_id]
            for function_id, task_id in self.function_task_ids.items()
        }
        self.loop_by_task = {
            task_id: self.loops[loop_id]
            for loop_id, task_id in self.loop_task_ids.items()
        }

    def build(self, task_id: str) -> str:
        if task_id not in self.graph_task_ids:
            raise EvaluationPipelineError(f"Task id is not in the subtask graph: {task_id}")
        function = self.function_by_task.get(task_id)
        if function is not None:
            return self._function_prompt(task_id, function)
        loop = self.loop_by_task.get(task_id)
        if loop is not None:
            return self._loop_prompt(task_id, loop)
        raise EvaluationPipelineError(
            f"Task id {task_id!r} cannot be located in the current C file. "
            "The function name or loop lexical path may have changed."
        )

    def task_source_parts(self, task_id: str) -> dict[str, Any]:
        """Return raw current-file parts for inserting a contract before a task.

        Unlike prompt construction, this method does not remove already
        verified child-task annotations from the current working copy.  It
        returns both the full-file split required for persistent write-back and
        a bounded verification fragment ending at the current target.
        """

        if task_id not in self.graph_task_ids:
            raise EvaluationPipelineError(f"Task id is not in the subtask graph: {task_id}")
        function = self.function_by_task.get(task_id)
        if function is not None:
            span = self.document.source_span(function.range)
            target_type = "function"
        else:
            loop = self.loop_by_task.get(task_id)
            if loop is None:
                raise EvaluationPipelineError(
                    f"Task id {task_id!r} cannot be located in the current C file. "
                    "The function name or loop lexical path may have changed."
                )
            span = self.document.source_span(loop.range)
            target_type = "loop"

        data = self.document.data
        expected_category = (
            _FUNCTION_CONTRACT if target_type == "function" else _LOOP_CONTRACT
        )
        attached_contract = self.document.annotation_before(span.start, expected_category)
        if attached_contract is None and target_type == "function":
            # A C function may carry its contract on an earlier prototype
            # instead of immediately before the definition. Treat that
            # declaration contract as the existing block so the generated
            # clauses are merged into it rather than emitted as a second,
            # standalone annotation.
            attached_contract = self.document.declaration_contract_before(
                function.name,
                span.start,
            )
        if attached_contract is None:
            line_start = self.document.line_start(span.start)
            # A loop can follow a control-flow prefix on the same source line
            # (``if (ready) while (...)``). Insert at the loop token in that
            # case; placing the annotation at the line start would annotate
            # the ``if`` statement and produce invalid ACSL/C syntax.
            insertion_start = (
                span.start
                if target_type == "loop"
                and self.document.data[line_start:span.start].strip()
                else line_start
            )
            existing_contract = None
        else:
            # Keep the original annotation as a separate input to the merger;
            # the source suffix excludes it so only one combined block is
            # emitted at this location.
            insertion_start = self.document.line_start(attached_contract.span.start)
            existing_contract = data[
                attached_contract.span.start : attached_contract.span.end
            ].decode("utf-8")
        # Keep the complete suffix only for persistent write-back after a
        # successful proof.  Frama-C uses the bounded verification fields
        # constructed below instead of this full-file split.
        if attached_contract is None:
            code_snippet = data[insertion_start:]
        else:
            # Remove the old annotation from the code suffix only long enough
            # to let the combiner place the merged annotation at its location.
            code_snippet = (
                data[insertion_start : attached_contract.span.start]
                + data[attached_contract.span.end :]
            )

        enclosing_function = function
        if enclosing_function is None:
            enclosing_function = self.functions[loop.function_id]
        enclosing_span = self.document.source_span(enclosing_function.range)

        # Build an independent, bounded input for Frama-C.  The full-file
        # split above remains intentionally unchanged because it is needed to
        # merge a verified contract back into the persistent working copy.
        # Verification itself only needs the file-level prefix and the current
        # enclosing function; later functions in the source must not create
        # unrelated proof obligations.
        verification_source_prefix = data[: enclosing_span.start]
        if (
            attached_contract is not None
            and attached_contract.span.start < enclosing_span.start
            and attached_contract.span.end <= enclosing_span.start
        ):
            verification_source_prefix = (
                data[: attached_contract.span.start]
                + data[attached_contract.span.end : enclosing_span.start]
            )

        if target_type == "function":
            verification_code_prefix = b""
            verification_target_code = data[
                enclosing_span.start : enclosing_span.end
            ]
        else:
            verification_code_prefix = data[
                enclosing_span.start : insertion_start
            ]
            target_code_start = (
                attached_contract.span.end
                if attached_contract is not None
                else insertion_start
            )
            verification_target_code = data[target_code_start : span.end]
            open_scopes = _c_brace_depth(
                data[enclosing_span.start : span.end]
            )
            if open_scopes <= 0:
                raise EvaluationPipelineError(
                    f"Could not determine enclosing scopes for loop task {task_id}"
                )
            verification_target_code += (
                b"\n" + b"\n".join(b"}" for _ in range(open_scopes)) + b"\n"
            )

        return {
            "task_id": task_id,
            "target_type": target_type,
            "source_prefix": data[:insertion_start].decode("utf-8"),
            "code_snippet": code_snippet.decode("utf-8"),
            "verification_source_prefix": verification_source_prefix.decode("utf-8"),
            "verification_code_prefix": verification_code_prefix.decode("utf-8"),
            "verification_target_code": verification_target_code.decode("utf-8"),
            "existing_contract": existing_contract,
            "task_start": span.start,
            "task_end": span.end,
            "line_start": insertion_start,
        }

    def _function_prompt(self, task_id: str, function: FunctionInfo) -> str:
        span = self.document.source_span(function.range)
        current_code = self.document.render_code(span.start, span.end)
        upstream_context = self._function_upstream(function)
        downstream_context = self._function_downstream(task_id, function)
        return _training_build_prompt(
            "function",
            self.source_background_spec,
            current_code,
            upstream_context,
            downstream_context,
        )

    def _loop_prompt(self, task_id: str, loop: LoopInfo) -> str:
        span = self.document.source_span(loop.range)
        current_code = self.document.render_code(span.start, span.end)
        upstream_context = self._loop_upstream(loop)
        downstream_context = self._loop_downstream(task_id, loop)
        return _training_build_prompt(
            "loop",
            self.source_background_spec,
            current_code,
            upstream_context,
            downstream_context,
        )

    def _function_downstream(
        self,
        current_task_id: str,
        function: FunctionInfo,
    ) -> list[dict[str, Any]]:
        events: list[tuple[int, int, str, str, str]] = []
        for loop in self.analysis.loops:
            if loop.function_id != function.id or loop.parent_loop_id is not None:
                continue
            task_id = self.loop_task_ids[loop.id]
            if task_id in self.graph_task_ids:
                events.append(
                    (
                        self.document.offset(loop.location),
                        0,
                        "loop",
                        task_id,
                        "direct_child_loop",
                    )
                )

        seen_callees: set[str] = set()
        direct_calls = sorted(
            (
                call
                for call in self.analysis.calls
                if call.caller_id == function.id
                and call.resolution == "internal"
                and call.callee_id is not None
            ),
            key=lambda call: self.document.offset(call.location),
        )
        for call in direct_calls:
            callee_id = call.callee_id
            if callee_id == function.id or callee_id in seen_callees:
                continue
            seen_callees.add(callee_id)
            task_id = self.function_task_ids.get(callee_id)
            if task_id in self.graph_task_ids:
                events.append(
                    (
                        self.document.offset(call.location),
                        1,
                        "function",
                        task_id,
                        "direct_callee",
                    )
                )
        return self._downstream_entries(current_task_id, events)

    def _loop_downstream(
        self,
        current_task_id: str,
        loop: LoopInfo,
    ) -> list[dict[str, Any]]:
        events: list[tuple[int, int, str, str, str]] = []
        for child_id in loop.child_loop_ids:
            child = self.loops[child_id]
            task_id = self.loop_task_ids[child.id]
            if task_id in self.graph_task_ids:
                events.append(
                    (
                        self.document.offset(child.location),
                        0,
                        "loop",
                        task_id,
                        "direct_child_loop",
                    )
                )

        seen_callees: set[str] = set()
        for call in sorted(
            (self.calls[call_id] for call_id in loop.call_site_ids),
            key=lambda item: self.document.offset(item.location),
        ):
            if not call.loop_ids or call.loop_ids[-1] != loop.id:
                continue
            if call.resolution != "internal" or call.callee_id is None:
                continue
            if call.callee_id in seen_callees:
                continue
            seen_callees.add(call.callee_id)
            task_id = self.function_task_ids.get(call.callee_id)
            if task_id in self.graph_task_ids:
                events.append(
                    (
                        self.document.offset(call.location),
                        1,
                        "function",
                        task_id,
                        "direct_callee",
                    )
                )
        return self._downstream_entries(current_task_id, events)

    def _downstream_entries(
        self,
        current_task_id: str,
        events: Iterable[tuple[int, int, str, str, str]],
    ) -> list[dict[str, Any]]:
        entries: list[dict[str, Any]] = []
        missing: list[str] = []
        for _, _, target_type, task_id, relation in sorted(events):
            if task_id == current_task_id:
                continue
            label = self._label_for_task(task_id)
            if label is None:
                missing.append(task_id)
                continue
            entries.append(
                {
                    "target_id": task_id,
                    "target_type": target_type,
                    "relation": relation,
                    "label": label,
                }
            )
        if missing and self.require_downstream_contracts:
            missing_text = ", ".join(sorted(missing))
            raise EvaluationPipelineError(
                f"Downstream contract(s) not found in current file: {missing_text}"
            )
        return entries

    def _label_for_task(self, task_id: str) -> str | None:
        function = self.function_by_task.get(task_id)
        if function is not None:
            return self._function_label(function)
        loop = self.loop_by_task.get(task_id)
        if loop is not None:
            return self._loop_label(loop)
        return None

    def _function_label(self, function: FunctionInfo) -> str | None:
        span = self.document.source_span(function.range)
        label = self.document.annotation_before(span.start, _FUNCTION_CONTRACT)
        if label is None:
            label = self.document.declaration_contract_before(function.name, span.start)
        return None if label is None else label.text

    def _loop_label(self, loop: LoopInfo) -> str | None:
        span = self.document.source_span(loop.range)
        label = self.document.annotation_before(span.start, _LOOP_CONTRACT)
        return None if label is None else label.text

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
                self.document.offset(call.location),
            ),
        )
        for call in incoming_calls:
            caller = self.functions[call.caller_id]
            caller_span = self.document.source_span(caller.range)
            boundary = self.document.line_start(self.document.offset(call.location))
            key = (caller.id, boundary)
            if key in seen:
                continue
            seen.add(key)
            code = self.document.render_code(caller_span.start, boundary)
            if not code:
                continue
            contexts.append(
                {
                    "source_id": self.function_task_ids[caller.id],
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
        function_span = self.document.source_span(function.range)
        first_boundary = self._loop_intro_offset(chain[0])
        contexts: list[dict[str, Any]] = []
        function_code = self.document.render_code(function_span.start, first_boundary)
        if function_code:
            contexts.append(
                {
                    "source_id": self.function_task_ids[function.id],
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
            ancestor_span = self.document.source_span(ancestor.range)
            boundary = self._loop_intro_offset(child)
            code = self.document.render_code(ancestor_span.start, boundary)
            if not code:
                continue
            contexts.append(
                {
                    "source_id": self.loop_task_ids[ancestor.id],
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

    def _loop_intro_offset(self, loop: LoopInfo) -> int:
        span = self.document.source_span(loop.range)
        label = self.document.annotation_before(span.start, _LOOP_CONTRACT)
        return span.start if label is None else label.span.start


def build_task_prompt(
    task_graph: dict[str, Any],
    task_id: str,
    *,
    current_c_file: str | Path | None = None,
    clang: str | Path | None = None,
    clang_arguments: Sequence[str] = (),
    clang_timeout: float | None = 20.0,
    require_downstream_contracts: bool = True,
) -> str:
    """Build the prompt for exactly one task in the current C working copy.

    ``task_graph`` is the dictionary returned by :func:`build_subtask_sequence`.
    ``task_id`` must be one of its stable ids, such as ``function:foo`` or
    ``loop:foo:0.1``.  ``current_c_file`` should point at the temporary file
    that has accumulated already verified ACSL annotations; when omitted, the
    original ``source_file`` recorded in ``task_graph`` is used.
    """

    source_value = current_c_file or task_graph.get("source_file")
    if source_value is None:
        raise EvaluationPipelineError(
            "current_c_file was not provided and task_graph has no source_file"
        )
    source = _resolve_existing_c_file(source_value)
    analysis = _analyze_one_c_file(
        source,
        clang=clang,
        clang_arguments=clang_arguments,
        clang_timeout=clang_timeout,
    )
    return _SingleTaskPromptBuilder(
        task_graph,
        source,
        analysis,
        require_downstream_contracts=require_downstream_contracts,
    ).build(task_id)


def _split_prompt_sections(prompt: str) -> tuple[str, str]:
    positions = [prompt.find(section) for section in _PROMPT_SECTIONS]
    if any(position < 0 for position in positions) or positions != sorted(positions):
        raise EvaluationPipelineError("Prompt sections are missing or reordered")
    if prompt.count(_PROMPT_SECTIONS[0]) != 1:
        raise EvaluationPipelineError("Prompt must contain one target section")

    boundary = positions[0]
    system_content = prompt[:boundary].strip()
    user_content = prompt[boundary:].strip()
    if not system_content or not user_content:
        raise EvaluationPipelineError("System and user prompt content cannot be empty")
    if not user_content.endswith(_PROMPT_SECTIONS[-1]):
        raise EvaluationPipelineError("Prompt has an invalid ending")

    type_end = positions[1] - boundary
    parsed_type = user_content[len(_PROMPT_SECTIONS[0]) : type_end].strip()
    if parsed_type not in {"function", "loop"}:
        raise EvaluationPipelineError(f"Unsupported prompt target type: {parsed_type!r}")
    return system_content, user_content
