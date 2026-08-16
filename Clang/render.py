from __future__ import annotations

import hashlib
import html
import os
import shutil
import subprocess
from pathlib import Path

from .model import AnalysisResult, CallSiteInfo, FunctionInfo, LoopInfo


class RenderError(RuntimeError):
    pass


def discover_dot(explicit: str | Path | None = None) -> Path | None:
    candidates: list[str | Path] = []
    if explicit:
        candidates.append(explicit)
    if os.environ.get("GRAPHVIZ_DOT"):
        candidates.append(os.environ["GRAPHVIZ_DOT"])
    on_path = shutil.which("dot")
    if on_path:
        candidates.append(on_path)
    if os.name == "nt":
        program_files = Path(os.environ.get("ProgramFiles", r"C:\Program Files"))
        candidates.append(program_files / "Graphviz" / "bin" / "dot.exe")
        candidates.extend(program_files.glob("Graphviz*/bin/dot.exe"))
    for candidate in candidates:
        path = Path(candidate).expanduser()
        if not path.is_absolute():
            located = shutil.which(str(path))
            if located:
                path = Path(located)
        if path.is_file():
            return path.resolve()
    return None


def _dot_id(prefix: str, value: str) -> str:
    digest = hashlib.sha1(value.encode("utf-8")).hexdigest()[:16]
    return f"{prefix}_{digest}"


def _quote(value: str) -> str:
    escaped = value.replace("\\", "\\\\").replace('"', '\\"').replace("\n", "\\n")
    return f'"{escaped}"'


def _function_label(function: FunctionInfo) -> str:
    return (
        f"{function.name}\n{function.location.file}:{function.location.line}\n"
        f"loops: {len(function.loop_ids)}"
    )


def _loop_label(loop: LoopInfo) -> str:
    return f"{loop.kind} loop\nline {loop.location.line}\ndepth {loop.depth}"


def to_dot(result: AnalysisResult, *, include_loops: bool = True) -> str:
    lines = [
        "digraph callgraph {",
        "  graph [rankdir=LR, bgcolor=\"#fbfcfe\", pad=\"0.25\", nodesep=\"0.35\"];",
        "  node [fontname=\"Segoe UI\", fontsize=10, style=\"rounded,filled\", color=\"#64748b\"];",
        "  edge [fontname=\"Segoe UI\", fontsize=9, color=\"#64748b\"];",
    ]
    function_ids = {function.id: _dot_id("function", function.id) for function in result.functions}
    loop_ids = {loop.id: _dot_id("loop", loop.id) for loop in result.loops}
    for function in result.functions:
        lines.append(
            f"  {function_ids[function.id]} [shape=box, fillcolor=\"#e0f2fe\", "
            f"label={_quote(_function_label(function))}, tooltip={_quote(function.id)}];"
        )

    external_nodes: dict[tuple[str, str], str] = {}
    for call in result.calls:
        if call.resolution == "internal" or not call.callee_name:
            continue
        key = (call.resolution, call.callee_name)
        if key in external_nodes:
            continue
        node_id = _dot_id("target", f"{key[0]}::{key[1]}")
        external_nodes[key] = node_id
        fill = "#fef3c7" if call.resolution == "external" else "#fee2e2"
        lines.append(
            f"  {node_id} [shape=ellipse, style=\"dashed,filled\", fillcolor=\"{fill}\", "
            f"label={_quote(f'{call.callee_name}\n{call.resolution}')}];"
        )

    for edge in result.edges:
        label = f"{len(edge.call_site_ids)} call" + ("s" if len(edge.call_site_ids) != 1 else "")
        lines.append(
            f"  {function_ids[edge.caller_id]} -> {function_ids[edge.callee_id]} "
            f"[color=\"#2563eb\", penwidth=1.6, label={_quote(label)}];"
        )
    for call in result.calls:
        if call.resolution == "internal" or not call.callee_name:
            continue
        target_id = external_nodes[(call.resolution, call.callee_name)]
        lines.append(
            f"  {function_ids[call.caller_id]} -> {target_id} "
            f"[style=dashed, label={_quote(f'line {call.location.line}')}];"
        )

    if include_loops:
        loops_by_id = {loop.id: loop for loop in result.loops}
        for loop in result.loops:
            lines.append(
                f"  {loop_ids[loop.id]} [shape=component, fillcolor=\"#dcfce7\", "
                f"color=\"#16a34a\", label={_quote(_loop_label(loop))}, tooltip={_quote(loop.id)}];"
            )
            if loop.parent_loop_id:
                parent_id = loop_ids[loop.parent_loop_id]
            else:
                parent_id = function_ids[loop.function_id]
            lines.append(
                f"  {parent_id} -> {loop_ids[loop.id]} "
                "[color=\"#16a34a\", style=dotted, arrowhead=none, label=\"contains\"];"
            )
        for call in result.calls:
            if not call.loop_ids:
                continue
            deepest_loop = loops_by_id[call.loop_ids[-1]]
            target_id: str | None = None
            if call.resolution == "internal" and call.callee_id:
                target_id = function_ids[call.callee_id]
            elif call.callee_name:
                target_id = external_nodes.get((call.resolution, call.callee_name))
            if target_id:
                lines.append(
                    f"  {loop_ids[deepest_loop.id]} -> {target_id} "
                    f"[constraint=false, color=\"#9333ea\", style=dashed, "
                    f"label={_quote(f'calls @ {call.location.line}')}];"
                )
    lines.append("}")
    return "\n".join(lines) + "\n"


def dot_to_svg(
    dot_source: str,
    dot_executable: str | Path | None = None,
    *,
    timeout_seconds: float | None = 60.0,
) -> str:
    executable = discover_dot(dot_executable)
    if executable is None:
        raise RenderError(
            "Cannot find Graphviz 'dot'. Install Graphviz or pass --dot-executable."
        )
    if timeout_seconds is not None and timeout_seconds <= 0:
        raise RenderError("Graphviz timeout must be greater than zero")
    try:
        completed = subprocess.run(
            [str(executable), "-Tsvg"],
            input=dot_source,
            check=False,
            stdout=subprocess.PIPE,
            stderr=subprocess.PIPE,
            text=True,
            encoding="utf-8",
            errors="replace",
            timeout=timeout_seconds,
        )
    except subprocess.TimeoutExpired as exc:
        raise RenderError(
            f"Graphviz exceeded the rendering timeout of {timeout_seconds:g} seconds"
        ) from exc
    if completed.returncode != 0:
        raise RenderError(f"Graphviz failed: {completed.stderr.strip()}")
    return completed.stdout


def _function_rows(result: AnalysisResult) -> str:
    rows = []
    for function in result.functions:
        callees = ", ".join(
            [
                *(
                    next(item.name for item in result.functions if item.id == callee_id)
                    for callee_id in function.callee_ids
                ),
                *function.external_callees,
            ]
        )
        search = " ".join(
            [function.name, function.location.file, callees, function.qualified_type]
        ).casefold()
        rows.append(
            f'<tr data-search="{html.escape(search, quote=True)}">'
            f"<td><code>{html.escape(function.name)}</code></td>"
            f"<td>{html.escape(function.qualified_type)}</td>"
            f"<td>{html.escape(function.location.file)}:{function.location.line}</td>"
            f"<td>{len(function.loop_ids)}</td>"
            f"<td>{html.escape(callees) or '—'}</td></tr>"
        )
    return "".join(rows)


def _loop_rows(result: AnalysisResult) -> str:
    functions = {function.id: function for function in result.functions}
    rows = []
    for loop in result.loops:
        function = functions[loop.function_id]
        search = f"{function.name} {loop.kind} {loop.location.file}".casefold()
        rows.append(
            f'<tr data-search="{html.escape(search, quote=True)}">'
            f"<td><code>{html.escape(function.name)}</code></td>"
            f"<td>{html.escape(loop.kind)}</td>"
            f"<td>{html.escape(loop.location.file)}:{loop.location.line}</td>"
            f"<td>{loop.range.end.line}</td>"
            f"<td>{loop.depth}</td>"
            f"<td>{len(loop.call_site_ids)}</td></tr>"
        )
    return "".join(rows)


def to_html(
    result: AnalysisResult,
    *,
    svg: str | None = None,
    dot_source: str | None = None,
) -> str:
    stats = result.statistics
    graph_content = svg or (
        f"<p>Graphviz is unavailable. The DOT source is shown below.</p>"
        f"<pre>{html.escape(dot_source or '')}</pre>"
    )
    cards = "".join(
        f'<div class="card"><strong>{value}</strong><span>{html.escape(label.replace("_", " "))}</span></div>'
        for label, value in (
            ("source_files", stats["source_files"]),
            ("functions", stats["functions"]),
            ("calls", stats["calls"]),
            ("loops", stats["loops"]),
            ("indirect_calls", stats["indirect_calls"]),
        )
    )
    return f"""<!doctype html>
<html lang="en">
<head>
<meta charset="utf-8">
<meta name="viewport" content="width=device-width, initial-scale=1">
<title>TSFT C Call Graph</title>
<style>
:root {{ color-scheme: light; font-family: "Segoe UI", system-ui, sans-serif; color: #0f172a; }}
body {{ margin: 0; background: #f8fafc; }}
header {{ padding: 1.25rem 2rem; color: white; background: linear-gradient(120deg,#0f172a,#1d4ed8); }}
header h1 {{ margin: 0 0 .25rem; font-size: 1.5rem; }}
main {{ max-width: 1500px; margin: auto; padding: 1.25rem; }}
.cards {{ display: grid; grid-template-columns: repeat(auto-fit,minmax(150px,1fr)); gap: .75rem; }}
.card, section {{ background: white; border: 1px solid #e2e8f0; border-radius: .65rem; box-shadow: 0 1px 3px #0f172a12; }}
.card {{ padding: .9rem 1rem; display: flex; flex-direction: column; }}
.card strong {{ font-size: 1.5rem; }} .card span {{ color: #64748b; }}
section {{ margin-top: 1rem; padding: 1rem; overflow: auto; }}
section h2 {{ margin: 0 0 .75rem; font-size: 1.15rem; }}
.graph svg {{ min-width: 900px; height: auto; }}
input {{ width: min(34rem,90%); padding: .6rem .7rem; border: 1px solid #94a3b8; border-radius: .35rem; }}
table {{ width: 100%; border-collapse: collapse; margin-top: .7rem; font-size: .9rem; }}
th,td {{ padding: .55rem; border-bottom: 1px solid #e2e8f0; text-align: left; vertical-align: top; }}
th {{ position: sticky; top: 0; background: #f1f5f9; }} code {{ color: #1d4ed8; }}
pre {{ white-space: pre-wrap; font-size: .78rem; }}
</style>
</head>
<body>
<header><h1>TSFT C call graph and loop map</h1><div>{html.escape(result.project_root)}</div></header>
<main>
<div class="cards">{cards}</div>
<section class="graph"><h2>Call graph and loop containment</h2>{graph_content}</section>
<section><h2>Functions</h2><input class="filter" data-table="functions" placeholder="Filter functions, files, or callees…">
<table id="functions"><thead><tr><th>Function</th><th>Type</th><th>Definition</th><th>Loops</th><th>Callees</th></tr></thead><tbody>{_function_rows(result)}</tbody></table></section>
<section><h2>Loops</h2><input class="filter" data-table="loops" placeholder="Filter loops by function, kind, or file…">
<table id="loops"><thead><tr><th>Function</th><th>Kind</th><th>Start</th><th>End line</th><th>Depth</th><th>Calls in loop</th></tr></thead><tbody>{_loop_rows(result)}</tbody></table></section>
</main>
<script>
for (const input of document.querySelectorAll('.filter')) {{
  input.addEventListener('input', () => {{
    const query = input.value.toLocaleLowerCase();
    for (const row of document.querySelectorAll(`#${{input.dataset.table}} tbody tr`)) {{
      row.hidden = !row.dataset.search.includes(query);
    }}
  }});
}}
</script>
</body>
</html>
"""


def write_text(path: str | Path, content: str) -> Path:
    output = Path(path).expanduser().resolve()
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(content, encoding="utf-8")
    return output
