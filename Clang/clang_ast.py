from __future__ import annotations

import bisect
import json
import subprocess
from dataclasses import dataclass
from pathlib import Path
from typing import Any, Iterable

from .model import SourceLocation, SourceRange


class ClangInvocationError(RuntimeError):
    def __init__(
        self,
        source: Path,
        command: list[str],
        returncode: int,
        diagnostics: str,
        *,
        timed_out: bool = False,
    ) -> None:
        self.source = source
        self.command = command
        self.returncode = returncode
        self.diagnostics = diagnostics
        self.timed_out = timed_out
        if timed_out:
            message = f"Clang timed out while parsing {source}"
        else:
            message = f"Clang failed for {source} with exit code {returncode}"
        if diagnostics.strip():
            message += f":\n{diagnostics.strip()}"
        super().__init__(message)


@dataclass(slots=True, frozen=True)
class AstDump:
    root: dict[str, Any]
    command: list[str]
    arguments: list[str]
    diagnostics: str
    returncode: int


class SourceIndex:
    """Resolve omitted Clang line/column fields from byte offsets."""

    def __init__(self, source: Path) -> None:
        self.path = source.resolve()
        data = self.path.read_bytes()
        self._line_starts = [0]
        self._line_starts.extend(index + 1 for index, byte in enumerate(data) if byte == 10)

    def line_column(self, offset: int) -> tuple[int, int]:
        line_index = bisect.bisect_right(self._line_starts, offset) - 1
        line_index = max(line_index, 0)
        return line_index + 1, offset - self._line_starts[line_index] + 1


def dump_ast(
    clang: Path,
    source: Path,
    arguments: Iterable[str],
    *,
    cwd: Path | None = None,
    timeout_seconds: float | None = None,
) -> AstDump:
    source = source.resolve()
    clang_arguments = list(arguments)
    command = [
        str(clang),
        *clang_arguments,
        "-fsyntax-only",
        "-fno-color-diagnostics",
        "-Wno-everything",
        "-ferror-limit=20",
        "-Xclang",
        "-ast-dump=json",
        str(source),
    ]
    try:
        completed = subprocess.run(
            command,
            cwd=cwd,
            check=False,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True,
            encoding="utf-8",
            errors="replace",
            timeout=timeout_seconds,
        )
    except subprocess.TimeoutExpired as exc:
        stderr = exc.stderr or ""
        if isinstance(stderr, bytes):
            stderr = stderr.decode("utf-8", errors="replace")
        timeout_text = (
            f"Clang exceeded the per-file timeout of {timeout_seconds:g} seconds."
            if timeout_seconds is not None
            else "Clang timed out."
        )
        diagnostics = f"{timeout_text}\n{stderr.strip()}".strip()
        raise ClangInvocationError(
            source,
            command,
            124,
            diagnostics,
            timed_out=True,
        ) from exc
    diagnostics = completed.stderr.strip()
    if not completed.stdout.strip():
        raise ClangInvocationError(source, command, completed.returncode, diagnostics)
    try:
        root = json.loads(completed.stdout)
    except json.JSONDecodeError as exc:
        raise ClangInvocationError(
            source,
            command,
            completed.returncode,
            f"{diagnostics}\nInvalid AST JSON: {exc}",
        ) from exc
    return AstDump(
        root=root,
        command=command,
        arguments=clang_arguments,
        diagnostics=diagnostics,
        returncode=completed.returncode,
    )


def unwrap_location(raw: dict[str, Any] | None) -> dict[str, Any]:
    if not raw:
        return {}
    if "expansionLoc" in raw:
        return unwrap_location(raw["expansionLoc"])
    if "spellingLoc" in raw:
        return unwrap_location(raw["spellingLoc"])
    return raw


class LocationResolver:
    def __init__(self, main_file: Path, project_root: Path) -> None:
        self.main_file = main_file.resolve()
        self.project_root = project_root.resolve()
        self._indexes: dict[Path, SourceIndex] = {}

    def display_path(self, path: Path) -> str:
        path = path.resolve()
        try:
            return path.relative_to(self.project_root).as_posix()
        except ValueError:
            return path.as_posix()

    def _path(self, raw: dict[str, Any], default_file: Path | None) -> Path:
        file_value = raw.get("file")
        if file_value:
            return Path(file_value).resolve()
        return (default_file or self.main_file).resolve()

    def location(
        self,
        raw: dict[str, Any] | None,
        *,
        default_file: Path | None = None,
    ) -> SourceLocation:
        point = unwrap_location(raw)
        path = self._path(point, default_file)
        offset_value = point.get("offset")
        offset = int(offset_value) if offset_value is not None else None
        token_length_value = point.get("tokLen")
        token_length = int(token_length_value) if token_length_value is not None else None
        line = point.get("line")
        column = point.get("col")
        if (line is None or column is None) and offset is not None and path.exists():
            index = self._indexes.setdefault(path, SourceIndex(path))
            derived_line, derived_column = index.line_column(offset)
            line = derived_line if line is None else line
            column = derived_column if column is None else column
        return SourceLocation(
            file=self.display_path(path),
            line=int(line or 0),
            column=int(column or 0),
            offset=offset,
            token_length=token_length,
        )

    def source_range(
        self,
        raw: dict[str, Any] | None,
        *,
        default_file: Path | None = None,
    ) -> SourceRange:
        raw = raw or {}
        start = self.location(raw.get("begin"), default_file=default_file)
        end = self.location(raw.get("end"), default_file=default_file)
        return SourceRange(start=start, end=end)
