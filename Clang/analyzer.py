from __future__ import annotations

import json
import os
import re
import shlex
import shutil
import subprocess
from collections import defaultdict
from dataclasses import dataclass
from pathlib import Path
from typing import Any, Callable, Iterable, Sequence

from .clang_ast import (
    ClangInvocationError,
    LocationResolver,
    dump_ast,
    unwrap_location,
)
from .model import (
    AnalysisResult,
    CallSiteInfo,
    EdgeInfo,
    FunctionInfo,
    LoopInfo,
    ParameterInfo,
    TranslationUnitInfo,
)

DEFAULT_EXTENSIONS = (".c",)
LOOP_KINDS = {"ForStmt": "for", "WhileStmt": "while", "DoStmt": "do_while"}
ProgressCallback = Callable[[str, int, int, Path, str], None]


class AnalysisError(RuntimeError):
    """Raised when source discovery or a required analysis step cannot proceed."""


@dataclass(slots=True, frozen=True)
class CompileCommand:
    directory: Path
    arguments: list[str]


class CompileCommandDatabase:
    def __init__(self, path: Path) -> None:
        self.path = path.resolve()
        try:
            payload = json.loads(self.path.read_text(encoding="utf-8"))
        except (OSError, json.JSONDecodeError) as exc:
            raise AnalysisError(f"Cannot read compile command database {self.path}: {exc}") from exc
        if not isinstance(payload, list):
            raise AnalysisError(f"Compile command database must contain a JSON array: {self.path}")
        self._commands: dict[str, CompileCommand] = {}
        for entry in payload:
            if not isinstance(entry, dict) or "file" not in entry:
                continue
            directory = Path(entry.get("directory") or self.path.parent).resolve()
            source = Path(entry["file"])
            if not source.is_absolute():
                source = directory / source
            raw_arguments = entry.get("arguments")
            if isinstance(raw_arguments, list):
                arguments = [str(value) for value in raw_arguments]
            elif isinstance(entry.get("command"), str):
                arguments = shlex.split(entry["command"], posix=os.name != "nt")
                arguments = [argument.strip('"') for argument in arguments]
            else:
                continue
            self._commands[_path_key(source)] = CompileCommand(
                directory=directory,
                arguments=_sanitize_compile_arguments(arguments, source),
            )

    def get(self, source: Path) -> CompileCommand | None:
        return self._commands.get(_path_key(source))


def _path_key(path: Path) -> str:
    value = str(path.resolve())
    return value.casefold() if os.name == "nt" else value


def _sanitize_compile_arguments(arguments: Sequence[str], source: Path) -> list[str]:
    """Remove compiler/output/source operands while retaining preprocessing flags."""

    if arguments:
        arguments = arguments[1:]
    result: list[str] = []
    skip_next = False
    options_with_value = {
        "-o",
        "-MF",
        "-MT",
        "-MQ",
        "--serialize-diagnostics",
        "/Fo",
        "/Fd",
        "/Fe",
    }
    ignored_options = {"-c", "/c", "-S", "-E"}
    source_key = _path_key(source)
    for argument in arguments:
        if skip_next:
            skip_next = False
            continue
        if argument in options_with_value:
            skip_next = True
            continue
        if argument in ignored_options:
            continue
        if argument.startswith(("-o", "-MF", "-MT", "-MQ")) and len(argument) > 2:
            continue
        if argument.startswith(("/Fo", "/Fd", "/Fe")) and len(argument) > 3:
            continue
        candidate = Path(argument.strip('"'))
        if candidate.suffix.lower() in {".c", ".cc", ".cpp", ".cxx", ".m", ".mm"}:
            if not candidate.is_absolute():
                candidate = source.parent / candidate
            if _path_key(candidate) == source_key or candidate.name == source.name:
                continue
        result.append(argument)
    return result


def discover_clang(explicit: str | Path | None = None) -> Path:
    candidates: list[str | Path] = []
    if explicit:
        candidates.append(explicit)
    if os.environ.get("CLANG"):
        candidates.append(os.environ["CLANG"])
    on_path = shutil.which("clang")
    if on_path:
        candidates.append(on_path)
    if os.name == "nt":
        candidates.extend(
            [
                Path(os.environ.get("ProgramFiles", r"C:\Program Files"))
                / "LLVM"
                / "bin"
                / "clang.exe",
                Path(os.environ.get("ProgramFiles(x86)", r"C:\Program Files (x86)"))
                / "LLVM"
                / "bin"
                / "clang.exe",
            ]
        )
        visual_studio_root = Path(os.environ.get("ProgramFiles", r"C:\Program Files")) / "Microsoft Visual Studio"
        if visual_studio_root.exists():
            candidates.extend(visual_studio_root.glob("*/*/VC/Tools/Llvm/x64/bin/clang.exe"))
    for candidate in candidates:
        path = Path(candidate).expanduser()
        if not path.is_absolute():
            located = shutil.which(str(path))
            if located:
                path = Path(located)
        if path.is_file():
            return path.resolve()
    requested = f" at {explicit}" if explicit else ""
    raise AnalysisError(
        "Cannot find clang executable"
        f"{requested}. Update the project Conda environment (which includes "
        "Clang), set CLANG, or pass --clang /path/to/clang."
    )


def discover_source_files(
    paths: Iterable[str | Path],
    *,
    recursive: bool = True,
    extensions: Iterable[str] = DEFAULT_EXTENSIONS,
) -> list[Path]:
    normalized_extensions = {
        extension.lower() if extension.startswith(".") else f".{extension.lower()}"
        for extension in extensions
    }
    discovered: dict[str, Path] = {}
    for raw_path in paths:
        path = Path(raw_path).expanduser().resolve()
        if not path.exists():
            raise AnalysisError(f"Input path does not exist: {path}")
        if path.is_file():
            if path.suffix.lower() not in normalized_extensions:
                raise AnalysisError(
                    f"Unsupported source extension for {path}; expected one of "
                    f"{sorted(normalized_extensions)}"
                )
            discovered[_path_key(path)] = path
            continue
        iterator = path.rglob("*") if recursive else path.glob("*")
        for candidate in iterator:
            if candidate.is_file() and candidate.suffix.lower() in normalized_extensions:
                resolved = candidate.resolve()
                discovered[_path_key(resolved)] = resolved
    files = sorted(discovered.values(), key=lambda item: item.as_posix().casefold())
    if not files:
        raise AnalysisError("No matching C source files were found in the supplied input paths")
    return files


def _default_project_root(input_paths: Sequence[str | Path]) -> Path:
    anchors: list[str] = []
    for raw_path in input_paths:
        path = Path(raw_path).expanduser().resolve()
        anchors.append(str(path if path.is_dir() else path.parent))
    try:
        return Path(os.path.commonpath(anchors)).resolve()
    except ValueError:
        return Path.cwd().resolve()


def _clang_version(clang: Path) -> str:
    try:
        completed = subprocess.run(
            [str(clang), "--version"],
            check=False,
            stdout=subprocess.PIPE,
            stderr=subprocess.STDOUT,
            text=True,
            encoding="utf-8",
            errors="replace",
            timeout=10,
        )
    except subprocess.TimeoutExpired:
        return "unknown (version command timed out)"
    first_line = completed.stdout.strip().splitlines()
    return first_line[0] if first_line else "unknown"


def _body_node(function_node: dict[str, Any]) -> dict[str, Any] | None:
    for child in function_node.get("inner", []):
        if child.get("kind") == "CompoundStmt":
            return child
    return None


def _walk_nodes(node: dict[str, Any]) -> Iterable[dict[str, Any]]:
    yield node
    for child in node.get("inner", []):
        if isinstance(child, dict) and child.get("kind"):
            yield from _walk_nodes(child)


def _return_type(qualified_type: str) -> str:
    match = re.match(r"^(.*?)\s*\(", qualified_type)
    return match.group(1).strip() if match else qualified_type


def _raw_location_belongs_to_source(
    raw: dict[str, Any] | None,
    source: Path,
) -> bool:
    """Return whether a Clang location originates in the main source file."""

    point = unwrap_location(raw)
    file_value = point.get("file")
    if file_value:
        location_path = Path(file_value)
        if not location_path.is_absolute():
            location_path = source.parent / location_path
        return _path_key(location_path) == _path_key(source)

    # Clang omits ``file`` for consecutive locations in the same file.  For
    # main-file nodes there is no inclusion marker; header nodes instead carry
    # ``includedFrom`` even when their own file name is elided.
    return bool(point) and "includedFrom" not in point


def _raw_range_belongs_to_source(
    raw: dict[str, Any] | None,
    source: Path,
    source_size: int,
) -> bool:
    """Validate that both endpoints are byte offsets inside the main file."""

    if not raw:
        return False
    begin = unwrap_location(raw.get("begin"))
    end = unwrap_location(raw.get("end"))
    if not _raw_location_belongs_to_source(begin, source):
        return False
    if not _raw_location_belongs_to_source(end, source):
        return False
    try:
        begin_offset = int(begin["offset"])
        end_offset = int(end["offset"])
        end_token_length = int(end.get("tokLen", 0))
    except (KeyError, TypeError, ValueError):
        return False
    return (
        0 <= begin_offset <= end_offset
        and end_token_length >= 0
        and end_offset + end_token_length <= source_size
    )


def _function_id(file: str, name: str, line: int, column: int) -> str:
    return f"{file}::{name}@{line}:{column}"


def _find_decl_ref(node: dict[str, Any], kind: str | None = None) -> dict[str, Any] | None:
    if node.get("kind") == "DeclRefExpr":
        referenced = node.get("referencedDecl", {})
        if kind is None or referenced.get("kind") == kind:
            return node
    for child in node.get("inner", []):
        if isinstance(child, dict):
            found = _find_decl_ref(child, kind)
            if found is not None:
                return found
    return None


def _loop_body(node: dict[str, Any]) -> dict[str, Any]:
    children = [
        child
        for child in node.get("inner", [])
        if isinstance(child, dict) and child.get("kind")
    ]
    if not children:
        return node
    if node.get("kind") == "DoStmt":
        return children[0]
    return children[-1]


class _TranslationUnitCollector:
    def __init__(self, source: Path, project_root: Path, translation_unit: str) -> None:
        self.source = source.resolve()
        self.source_size = self.source.stat().st_size
        self.resolver = LocationResolver(self.source, project_root)
        self.translation_unit = translation_unit
        self.functions: list[FunctionInfo] = []
        self.calls: list[CallSiteInfo] = []
        self.loops: list[LoopInfo] = []

    def collect(self, root: dict[str, Any]) -> None:
        for node in _walk_nodes(root):
            if node.get("kind") != "FunctionDecl":
                continue
            body = _body_node(node)
            if body is None:
                continue
            if not _raw_location_belongs_to_source(node.get("loc"), self.source):
                continue
            if not _raw_range_belongs_to_source(
                node.get("range"), self.source, self.source_size
            ):
                continue
            if not _raw_range_belongs_to_source(
                body.get("range"), self.source, self.source_size
            ):
                continue
            self._collect_function(node, body)

    def _collect_function(self, node: dict[str, Any], body: dict[str, Any]) -> None:
        location = self.resolver.location(node.get("loc"), default_file=self.source)
        source_range = self.resolver.source_range(node.get("range"), default_file=self.source)
        body_range = self.resolver.source_range(body.get("range"), default_file=self.source)
        name = node.get("name") or "<anonymous>"
        qualified_type = node.get("type", {}).get("qualType", "")
        parameters = [
            ParameterInfo(
                name=child.get("name"),
                type=child.get("type", {}).get("qualType", ""),
            )
            for child in node.get("inner", [])
            if child.get("kind") == "ParmVarDecl"
        ]
        function = FunctionInfo(
            id=_function_id(location.file, name, location.line, location.column),
            name=name,
            qualified_type=qualified_type,
            return_type=_return_type(qualified_type),
            parameters=parameters,
            storage_class=node.get("storageClass"),
            is_static=node.get("storageClass") == "static",
            is_inline=bool(node.get("inline")),
            is_variadic=bool(node.get("variadic")),
            location=location,
            range=source_range,
            body_range=body_range,
            translation_unit=self.translation_unit,
        )
        self.functions.append(function)
        self._visit_statement(body, function, [])

    def _visit_statement(
        self,
        node: dict[str, Any],
        function: FunctionInfo,
        loop_stack: list[LoopInfo],
    ) -> None:
        kind = node.get("kind")
        if kind in LOOP_KINDS:
            source_range = self.resolver.source_range(node.get("range"), default_file=self.source)
            location = source_range.start
            loop_id = (
                f"{function.id}::loop:{LOOP_KINDS[kind]}@"
                f"{location.line}:{location.column}#{len(function.loop_ids) + 1}"
            )
            body = _loop_body(node)
            loop = LoopInfo(
                id=loop_id,
                function_id=function.id,
                kind=LOOP_KINDS[kind],
                depth=len(loop_stack),
                location=location,
                range=source_range,
                body_range=self.resolver.source_range(body.get("range"), default_file=self.source),
                parent_loop_id=loop_stack[-1].id if loop_stack else None,
            )
            if loop_stack:
                loop_stack[-1].child_loop_ids.append(loop.id)
            function.loop_ids.append(loop.id)
            self.loops.append(loop)
            for child in node.get("inner", []):
                if isinstance(child, dict) and child.get("kind"):
                    self._visit_statement(child, function, [*loop_stack, loop])
            return
        if kind == "CallExpr":
            self._collect_call(node, function, loop_stack)
        for child in node.get("inner", []):
            if isinstance(child, dict) and child.get("kind"):
                self._visit_statement(child, function, loop_stack)

    def _collect_call(
        self,
        node: dict[str, Any],
        function: FunctionInfo,
        loop_stack: list[LoopInfo],
    ) -> None:
        children = [child for child in node.get("inner", []) if isinstance(child, dict)]
        callee_expression = children[0] if children else {}
        direct_ref = _find_decl_ref(callee_expression, "FunctionDecl")
        any_ref = direct_ref or _find_decl_ref(callee_expression)
        referenced = (any_ref or {}).get("referencedDecl", {})
        callee_name = referenced.get("name")
        call_kind = "direct" if direct_ref is not None else "indirect"
        source_range = self.resolver.source_range(node.get("range"), default_file=self.source)
        location = source_range.start
        call_id = (
            f"{function.id}::call@{location.line}:{location.column}"
            f"#{len(function.call_site_ids) + 1}"
        )
        call = CallSiteInfo(
            id=call_id,
            caller_id=function.id,
            callee_name=callee_name,
            callee_id=None,
            kind=call_kind,
            resolution="pending" if call_kind == "direct" else "unresolved",
            function_type=referenced.get("type", {}).get("qualType")
            or callee_expression.get("type", {}).get("qualType"),
            location=location,
            range=source_range,
            loop_ids=[loop.id for loop in loop_stack],
            referenced_decl_id=referenced.get("id"),
        )
        self.calls.append(call)
        function.call_site_ids.append(call.id)
        for loop in loop_stack:
            loop.call_site_ids.append(call.id)


def _resolve_calls(
    functions: list[FunctionInfo], calls: list[CallSiteInfo]
) -> list[EdgeInfo]:
    functions_by_id = {function.id: function for function in functions}
    functions_by_name: dict[str, list[FunctionInfo]] = defaultdict(list)
    for function in functions:
        functions_by_name[function.name].append(function)

    edge_calls: dict[tuple[str, str], list[str]] = defaultdict(list)
    for call in calls:
        caller = functions_by_id[call.caller_id]
        if call.kind != "direct" or not call.callee_name:
            continue
        candidates = functions_by_name.get(call.callee_name, [])
        same_file = [
            function
            for function in candidates
            if function.location.file == caller.location.file
        ]
        global_candidates = [function for function in candidates if not function.is_static]
        target: FunctionInfo | None = None
        if len(same_file) == 1:
            target = same_file[0]
        elif len(global_candidates) == 1:
            target = global_candidates[0]
        elif not global_candidates:
            call.resolution = "external"
        else:
            call.resolution = "ambiguous"
        if target is None:
            if call.callee_name not in caller.external_callees:
                caller.external_callees.append(call.callee_name)
            continue
        call.callee_id = target.id
        call.resolution = "internal"
        if target.id not in caller.callee_ids:
            caller.callee_ids.append(target.id)
        if caller.id not in target.caller_ids:
            target.caller_ids.append(caller.id)
        edge_calls[(caller.id, target.id)].append(call.id)

    for function in functions:
        function.caller_ids.sort()
        function.callee_ids.sort()
        function.external_callees.sort()
    return [
        EdgeInfo(caller_id=caller, callee_id=callee, call_site_ids=sorted(site_ids))
        for (caller, callee), site_ids in sorted(edge_calls.items())
    ]


def analyze_paths(
    paths: Sequence[str | Path],
    *,
    clang: str | Path | None = None,
    project_root: str | Path | None = None,
    compile_commands: str | Path | None = None,
    clang_arguments: Sequence[str] = (),
    recursive: bool = True,
    extensions: Sequence[str] = DEFAULT_EXTENSIONS,
    fail_fast: bool = False,
    allow_partial_ast: bool = False,
    clang_timeout: float | None = 20.0,
    progress_callback: ProgressCallback | None = None,
) -> AnalysisResult:
    if not paths:
        raise AnalysisError("At least one input file or directory is required")
    if clang_timeout is not None and clang_timeout <= 0:
        raise AnalysisError("clang_timeout must be greater than zero")
    source_files = discover_source_files(paths, recursive=recursive, extensions=extensions)
    resolved_root = (
        Path(project_root).expanduser().resolve()
        if project_root is not None
        else _default_project_root(paths)
    )
    clang_path = discover_clang(clang)
    database = CompileCommandDatabase(Path(compile_commands)) if compile_commands else None
    resolver = LocationResolver(source_files[0], resolved_root)

    functions: list[FunctionInfo] = []
    calls: list[CallSiteInfo] = []
    loops: list[LoopInfo] = []
    units: list[TranslationUnitInfo] = []
    total_sources = len(source_files)
    for source_index, source in enumerate(source_files, start=1):
        display_source = resolver.display_path(source)
        command_entry = database.get(source) if database else None
        base_arguments = command_entry.arguments if command_entry else ["-std=c11"]
        arguments = [*base_arguments, *clang_arguments]
        cwd = command_entry.directory if command_entry else source.parent
        if progress_callback:
            progress_callback("start", source_index, total_sources, source, "")
        try:
            dump = dump_ast(
                clang_path,
                source,
                arguments,
                cwd=cwd,
                timeout_seconds=clang_timeout,
            )
        except ClangInvocationError as exc:
            status = "timeout" if exc.timed_out else "failed"
            units.append(
                TranslationUnitInfo(
                    file=display_source,
                    status=status,
                    clang_arguments=arguments,
                    diagnostics=exc.diagnostics,
                )
            )
            if progress_callback:
                progress_callback(status, source_index, total_sources, source, exc.diagnostics)
            if fail_fast:
                raise AnalysisError(str(exc)) from exc
            continue
        status = (
            "ok"
            if dump.returncode == 0
            else "partial"
            if allow_partial_ast
            else "failed"
        )
        units.append(
            TranslationUnitInfo(
                file=display_source,
                status=status,
                clang_arguments=arguments,
                diagnostics=dump.diagnostics,
            )
        )
        if fail_fast and dump.returncode != 0 and not allow_partial_ast:
            raise AnalysisError(
                f"Clang reported errors for {source}:\n{dump.diagnostics.strip()}"
            )
        if dump.returncode != 0 and not allow_partial_ast:
            if progress_callback:
                progress_callback(
                    "failed", source_index, total_sources, source, dump.diagnostics
                )
            # A partial AST after compiler errors can contain large amounts of invalid
            # recovery data. Keep the diagnostics, but never add that AST to the graph.
            continue
        collector = _TranslationUnitCollector(source, resolved_root, display_source)
        collector.collect(dump.root)
        functions.extend(collector.functions)
        calls.extend(collector.calls)
        loops.extend(collector.loops)
        if progress_callback:
            progress_callback(
                "partial" if dump.returncode != 0 else "ok",
                source_index,
                total_sources,
                source,
                dump.diagnostics if dump.returncode != 0 else "",
            )

    functions.sort(key=lambda item: item.id)
    calls.sort(key=lambda item: item.id)
    loops.sort(key=lambda item: item.id)
    edges = _resolve_calls(functions, calls)
    return AnalysisResult(
        schema_version="1.0",
        generator={
            "name": "tsft-callgraph",
            "version": "0.1.0",
            "clang": _clang_version(clang_path),
        },
        project_root=resolved_root.as_posix(),
        source_files=[resolver.display_path(source) for source in source_files],
        translation_units=units,
        functions=functions,
        calls=calls,
        loops=loops,
        edges=edges,
    )
