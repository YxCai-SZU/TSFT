"""Clang analysis, harness filtering, and bottom-up task scheduling."""

from __future__ import annotations

import fnmatch
import re
from pathlib import Path
from typing import Any, Iterable, Sequence

from Clang import AnalysisError, AnalysisResult, analyze_paths
from Clang.model import FunctionInfo, LoopInfo

from .constants import EvaluationPipelineError, _HARNESS_NAMES
from .source_files import _dataset_family


def _normalise_harness_policy(value: str | None) -> str:
    if value is None:
        return "entrypoint_names"
    key = re.sub(r"[^a-z0-9]+", "_", value.casefold()).strip("_")
    aliases = {
        "": "entrypoint_names",
        "auto": "entrypoint_names",
        "generic": "entrypoint_names",
        "entrypoint": "entrypoint_names",
        "entrypoints": "entrypoint_names",
        "entrypoint_name": "entrypoint_names",
        "entrypoint_names": "entrypoint_names",
        "conventional": "entrypoint_names",
        "none": "none",
        "no": "none",
        "false": "none",
        "all": "all_functions",
        "all_function": "all_functions",
        "all_functions": "all_functions",
        "true": "all_functions",
    }
    try:
        return aliases[key]
    except KeyError as exc:
        raise ValueError(
            f"Unknown harness policy {value!r}; use none, entrypoint_names, "
            "or all_functions"
        ) from exc


def _looks_like_harness_name(name: str) -> bool:
    folded = name.casefold()
    return (
        folded in _HARNESS_NAMES
        or folded.startswith(("test_", "harness_"))
        or folded.endswith(("_test", "_tests", "_harness"))
        or bool(re.match(r"^(?:Test|Harness)(?:[A-Z0-9_].*)?$", name))
    )


def _function_task_id(function: FunctionInfo) -> str:
    """Return a source-stable id for a C function in this translation unit."""

    # C does not support overloaded function definitions.  The name is thus a
    # better locator than Clang's line/column based id, which changes when a
    # contract is inserted before the definition.
    return f"function:{function.name}"


def _location_key(node: FunctionInfo | LoopInfo) -> tuple[int, int, int]:
    location = node.location
    # Offsets are only used to recover lexical order from the current AST; they
    # never become part of a task id.
    return (
        location.offset if location.offset is not None else 2**63 - 1,
        location.line,
        location.column,
    )


def _analyze_one_c_file(
    source: Path,
    *,
    clang: str | Path | None,
    clang_arguments: Sequence[str],
    clang_timeout: float | None,
) -> AnalysisResult:
    try:
        return analyze_paths(
            [source],
            clang=clang,
            project_root=source.parent,
            clang_arguments=clang_arguments,
            fail_fast=True,
            # Several benchmark files intentionally use ``void main``.  Clang
            # still emits a complete recoverable AST for those files; keeping
            # that AST is more useful than treating a host-language diagnostic
            # as a failed evaluation input.
            allow_partial_ast=True,
            clang_timeout=clang_timeout,
        )
    except AnalysisError as exc:
        raise EvaluationPipelineError(f"Clang analysis failed for {source}: {exc}") from exc


def _loop_paths(analysis: AnalysisResult) -> dict[str, tuple[int, ...]]:
    """Map Clang loop ids to lexical paths such as ``(0, 1)``.

    Child order comes from the AST traversal and is unchanged by inserting ACSL
    comments.  A path is therefore a stable selector for later source extraction.
    """

    loops = {loop.id: loop for loop in analysis.loops}
    functions = {function.id: function for function in analysis.functions}
    paths: dict[str, tuple[int, ...]] = {}

    def visit(loop_id: str, path: tuple[int, ...]) -> None:
        paths[loop_id] = path
        loop = loops[loop_id]
        children = sorted(
            (loops[child_id] for child_id in loop.child_loop_ids),
            key=_location_key,
        )
        for index, child in enumerate(children):
            visit(child.id, (*path, index))

    for function in sorted(analysis.functions, key=_location_key):
        roots = sorted(
            (
                loop
                for loop in analysis.loops
                if loop.function_id == function.id and loop.parent_loop_id is None
            ),
            key=_location_key,
        )
        for index, loop in enumerate(roots):
            visit(loop.id, (index,))
    return paths


def _stable_loop_task_id(function: FunctionInfo, loop: LoopInfo, path: tuple[int, ...]) -> str:
    path_text = ".".join(str(index) for index in path)
    return f"loop:{function.name}:{path_text}"


def _is_harness(
    function: FunctionInfo,
    *,
    harness_policy: str,
    source: Path,
    patterns: Sequence[str],
) -> tuple[bool, str]:
    qualified = f"{source.name}::{function.name}"
    for pattern in patterns:
        if fnmatch.fnmatchcase(function.name.casefold(), pattern.casefold()) or fnmatch.fnmatchcase(
            qualified.casefold(), pattern.casefold()
        ):
            return True, "explicit pattern"

    if harness_policy == "none":
        return False, "harness filtering disabled"
    if harness_policy == "all_functions":
        return True, "all functions selected by harness policy"

    # OOPSLA and SyGuS benchmark files are loop-specification datasets. Their
    # enclosing functions (including names such as ``foo``) are harnesses for
    # scheduling purposes, while their loop nodes remain eligible tasks.
    if harness_policy == "entrypoint_names" and _dataset_family(source) in {
        "oopsla",
        "sygus",
    }:
        return True, "loop-only OOPSLA/SyGuS benchmark dataset"

    # The default policy is conservative: only an uncalled conventional entry
    # point is removed.  Ordinary leaf functions remain contract tasks.
    if not function.caller_ids and _looks_like_harness_name(function.name):
        return True, "uncalled conventional entry/test function"

    # Frama-C problem files contain small driver functions with varied names
    # (for example ``check_validity`` or ``zero``). They are recognizable as
    # uncalled functions that invoke another function from the same file. Keep
    # contracts for standalone proof targets, but remove these drivers.
    if (
        harness_policy == "entrypoint_names"
        and _dataset_family(source) == "frama-c-problems"
        and not function.caller_ids
        and function.callee_ids
    ):
        return True, "uncalled Frama-C problem harness invokes an internal function"
    return False, "no harness rule matched"


def _tarjan_components(
    nodes: Iterable[str], dependencies: dict[str, set[str]]
) -> list[list[str]]:
    """Return strongly connected components in deterministic order."""

    index = 0
    indices: dict[str, int] = {}
    lowlinks: dict[str, int] = {}
    stack: list[str] = []
    on_stack: set[str] = set()
    components: list[list[str]] = []

    def visit(node: str) -> None:
        nonlocal index
        indices[node] = index
        lowlinks[node] = index
        index += 1
        stack.append(node)
        on_stack.add(node)
        for dependency in sorted(dependencies[node]):
            if dependency not in indices:
                visit(dependency)
                lowlinks[node] = min(lowlinks[node], lowlinks[dependency])
            elif dependency in on_stack:
                lowlinks[node] = min(lowlinks[node], indices[dependency])
        if lowlinks[node] == indices[node]:
            component: list[str] = []
            while True:
                item = stack.pop()
                on_stack.remove(item)
                component.append(item)
                if item == node:
                    break
            components.append(sorted(component))

    for node in sorted(nodes):
        if node not in indices:
            visit(node)
    return components


def _schedule(
    task_ids: set[str],
    dependencies: dict[str, set[str]],
    source_order: dict[str, tuple[int, int, int, str]],
) -> tuple[list[str], list[list[str]], dict[str, str | None]]:
    components = _tarjan_components(task_ids, dependencies)
    component_of = {
        task_id: component_index
        for component_index, component in enumerate(components)
        for task_id in component
    }
    component_dependencies: dict[int, set[int]] = {
        index: set() for index in range(len(components))
    }
    for task_id in task_ids:
        current = component_of[task_id]
        for dependency in dependencies[task_id]:
            other = component_of[dependency]
            if current != other:
                component_dependencies[current].add(other)

    remaining = {index: set(values) for index, values in component_dependencies.items()}
    stages: list[list[str]] = []
    processed: set[int] = set()
    cycle_groups: dict[str, str | None] = {task_id: None for task_id in task_ids}
    cycle_number = 0
    while len(processed) < len(components):
        ready = [index for index, deps in remaining.items() if index not in processed and not deps]
        if not ready:
            raise EvaluationPipelineError("Internal error while scheduling task dependencies")
        ready.sort(
            key=lambda index: min(source_order[task_id] for task_id in components[index])
        )
        stage: list[str] = []
        for component_index in ready:
            component = sorted(components[component_index], key=lambda item: source_order[item])
            is_cycle = len(component) > 1 or any(
                task_id in dependencies[task_id] for task_id in component
            )
            cycle_group = None
            if is_cycle:
                cycle_number += 1
                cycle_group = f"cycle:{cycle_number}"
                for task_id in component:
                    cycle_groups[task_id] = cycle_group
            stage.extend(component)
            processed.add(component_index)
        stages.append(stage)
        for component_index in remaining:
            remaining[component_index].difference_update(ready)

    sequence = [task_id for stage in stages for task_id in stage]
    return sequence, stages, cycle_groups


def _task_graph_ids(task_graph: dict[str, Any]) -> set[str]:
    tasks = task_graph.get("tasks")
    if isinstance(tasks, dict):
        return {str(task_id) for task_id in tasks}
    sequence = task_graph.get("sequence")
    if isinstance(sequence, list) and all(isinstance(item, str) for item in sequence):
        return set(sequence)
    raise EvaluationPipelineError("Task graph must contain a tasks dictionary or sequence list")
