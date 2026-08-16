from __future__ import annotations

from dataclasses import asdict, dataclass, field
from typing import Any


@dataclass(slots=True, frozen=True)
class SourceLocation:
    """A one-based source location plus Clang's optional byte offset."""

    file: str
    line: int
    column: int
    offset: int | None = None
    token_length: int | None = None

    def to_dict(self) -> dict[str, Any]:
        return asdict(self)


@dataclass(slots=True, frozen=True)
class SourceRange:
    start: SourceLocation
    end: SourceLocation

    def to_dict(self) -> dict[str, Any]:
        return {"start": self.start.to_dict(), "end": self.end.to_dict()}


@dataclass(slots=True, frozen=True)
class ParameterInfo:
    name: str | None
    type: str

    def to_dict(self) -> dict[str, Any]:
        return asdict(self)


@dataclass(slots=True)
class FunctionInfo:
    id: str
    name: str
    qualified_type: str
    return_type: str
    parameters: list[ParameterInfo]
    storage_class: str | None
    is_static: bool
    is_inline: bool
    is_variadic: bool
    location: SourceLocation
    range: SourceRange
    body_range: SourceRange
    translation_unit: str
    caller_ids: list[str] = field(default_factory=list)
    callee_ids: list[str] = field(default_factory=list)
    external_callees: list[str] = field(default_factory=list)
    call_site_ids: list[str] = field(default_factory=list)
    loop_ids: list[str] = field(default_factory=list)

    def to_dict(self) -> dict[str, Any]:
        return {
            "id": self.id,
            "name": self.name,
            "qualified_type": self.qualified_type,
            "return_type": self.return_type,
            "parameters": [parameter.to_dict() for parameter in self.parameters],
            "storage_class": self.storage_class,
            "is_static": self.is_static,
            "is_inline": self.is_inline,
            "is_variadic": self.is_variadic,
            "location": self.location.to_dict(),
            "range": self.range.to_dict(),
            "body_range": self.body_range.to_dict(),
            "translation_unit": self.translation_unit,
            "caller_ids": self.caller_ids,
            "callee_ids": self.callee_ids,
            "external_callees": self.external_callees,
            "call_site_ids": self.call_site_ids,
            "loop_ids": self.loop_ids,
        }


@dataclass(slots=True)
class CallSiteInfo:
    id: str
    caller_id: str
    callee_name: str | None
    callee_id: str | None
    kind: str
    resolution: str
    function_type: str | None
    location: SourceLocation
    range: SourceRange
    loop_ids: list[str]
    referenced_decl_id: str | None = field(default=None, repr=False)

    def to_dict(self) -> dict[str, Any]:
        return {
            "id": self.id,
            "caller_id": self.caller_id,
            "callee_name": self.callee_name,
            "callee_id": self.callee_id,
            "kind": self.kind,
            "resolution": self.resolution,
            "function_type": self.function_type,
            "location": self.location.to_dict(),
            "range": self.range.to_dict(),
            "loop_ids": self.loop_ids,
        }


@dataclass(slots=True)
class LoopInfo:
    id: str
    function_id: str
    kind: str
    depth: int
    location: SourceLocation
    range: SourceRange
    body_range: SourceRange
    parent_loop_id: str | None
    child_loop_ids: list[str] = field(default_factory=list)
    call_site_ids: list[str] = field(default_factory=list)

    def to_dict(self) -> dict[str, Any]:
        return {
            "id": self.id,
            "function_id": self.function_id,
            "kind": self.kind,
            "depth": self.depth,
            "location": self.location.to_dict(),
            "range": self.range.to_dict(),
            "body_range": self.body_range.to_dict(),
            "parent_loop_id": self.parent_loop_id,
            "child_loop_ids": self.child_loop_ids,
            "call_site_ids": self.call_site_ids,
        }


@dataclass(slots=True, frozen=True)
class EdgeInfo:
    caller_id: str
    callee_id: str
    call_site_ids: list[str]

    def to_dict(self) -> dict[str, Any]:
        return {
            "caller_id": self.caller_id,
            "callee_id": self.callee_id,
            "count": len(self.call_site_ids),
            "call_site_ids": self.call_site_ids,
        }


@dataclass(slots=True, frozen=True)
class TranslationUnitInfo:
    file: str
    status: str
    clang_arguments: list[str]
    diagnostics: str

    def to_dict(self) -> dict[str, Any]:
        return asdict(self)


@dataclass(slots=True)
class AnalysisResult:
    schema_version: str
    generator: dict[str, str]
    project_root: str
    source_files: list[str]
    translation_units: list[TranslationUnitInfo]
    functions: list[FunctionInfo]
    calls: list[CallSiteInfo]
    loops: list[LoopInfo]
    edges: list[EdgeInfo]

    @property
    def statistics(self) -> dict[str, int]:
        return {
            "source_files": len(self.source_files),
            "translation_units_succeeded": sum(
                unit.status in {"ok", "partial"} for unit in self.translation_units
            ),
            "translation_units_partial": sum(
                unit.status == "partial" for unit in self.translation_units
            ),
            "translation_units_failed": sum(
                unit.status in {"failed", "timeout"}
                for unit in self.translation_units
            ),
            "functions": len(self.functions),
            "calls": len(self.calls),
            "resolved_internal_calls": sum(
                call.resolution == "internal" for call in self.calls
            ),
            "external_calls": sum(call.resolution == "external" for call in self.calls),
            "ambiguous_calls": sum(call.resolution == "ambiguous" for call in self.calls),
            "indirect_calls": sum(call.kind == "indirect" for call in self.calls),
            "loops": len(self.loops),
            "for_loops": sum(loop.kind == "for" for loop in self.loops),
            "while_loops": sum(loop.kind == "while" for loop in self.loops),
            "do_while_loops": sum(loop.kind == "do_while" for loop in self.loops),
        }

    def to_dict(self) -> dict[str, Any]:
        return {
            "schema_version": self.schema_version,
            "generator": self.generator,
            "project_root": self.project_root,
            "source_files": self.source_files,
            "statistics": self.statistics,
            "translation_units": [unit.to_dict() for unit in self.translation_units],
            "functions": [function.to_dict() for function in self.functions],
            "calls": [call.to_dict() for call in self.calls],
            "loops": [loop.to_dict() for loop in self.loops],
            "edges": [edge.to_dict() for edge in self.edges],
        }
