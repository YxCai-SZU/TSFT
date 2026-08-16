"""Generate project-level Clang call-graph data and visualizations.

The command accepts C files, directories, or a compilation database. Run
``python generate_callgraph.py --help`` for the stable command-line API.
"""


from __future__ import annotations

import argparse
import json
import os
import sys
import webbrowser
from pathlib import Path
from typing import Sequence

from Clang.analyzer import AnalysisError, analyze_paths
from Clang.render import RenderError, dot_to_svg, to_dot, to_html, write_text


# Debug switch: True opens the generated SVG after every successful run.
# The SVG and HTML files are always generated, regardless of this value.
DEBUG_SHOW_GRAPH = False

DEFAULT_OUTPUT_DIRECTORY = "ClangOutput"
DEFAULT_CLANG_TIMEOUT_SECONDS = 20.0
DEFAULT_RENDER_TIMEOUT_SECONDS = 60.0
OUTPUT_FILES = {
    "json": "callgraph.json",
    "dot": "callgraph.dot",
    "svg": "callgraph.svg",
    "html": "callgraph.html",
}


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        description=(
            "Run Clang over one C file, multiple C files, or directories and "
            "generate call-graph JSON plus DOT/SVG/HTML visualizations."
        )
    )
    parser.add_argument(
        "inputs",
        nargs="+",
        help="One or more C files/directories to analyze",
    )
    parser.add_argument(
        "-o",
        "--output-dir",
        default=DEFAULT_OUTPUT_DIRECTORY,
        help=f"Output directory (default: {DEFAULT_OUTPUT_DIRECTORY})",
    )
    parser.add_argument(
        "--project-root",
        help="Root used for stable relative source paths and function IDs",
    )
    parser.add_argument(
        "--compile-commands",
        help="Optional path to compile_commands.json",
    )
    parser.add_argument(
        "--clang",
        help="Optional path to clang.exe; auto-detected when omitted",
    )
    parser.add_argument(
        "--dot-executable",
        help="Optional path to Graphviz dot.exe; auto-detected when omitted",
    )
    parser.add_argument(
        "--clang-arg",
        action="append",
        default=[],
        help="Extra Clang argument; use --clang-arg=-Iinclude for leading '-'",
    )
    parser.add_argument(
        "--extension",
        action="append",
        dest="extensions",
        help="Source extension to scan; repeat as needed (default: .c)",
    )
    parser.add_argument(
        "--no-recursive",
        action="store_true",
        help="Do not recursively scan input directories",
    )
    parser.add_argument(
        "--fail-fast",
        action="store_true",
        help="Stop immediately when Clang cannot parse an input file",
    )
    parser.add_argument(
        "--clang-timeout",
        type=float,
        default=DEFAULT_CLANG_TIMEOUT_SECONDS,
        metavar="SECONDS",
        help=(
            "Maximum time for each C translation unit "
            f"(default: {DEFAULT_CLANG_TIMEOUT_SECONDS:g} seconds)"
        ),
    )
    parser.add_argument(
        "--render-timeout",
        type=float,
        default=DEFAULT_RENDER_TIMEOUT_SECONDS,
        metavar="SECONDS",
        help=(
            "Maximum Graphviz rendering time "
            f"(default: {DEFAULT_RENDER_TIMEOUT_SECONDS:g} seconds)"
        ),
    )
    parser.add_argument(
        "--no-loop-nodes",
        action="store_true",
        help="Keep loops in JSON but omit loop nodes from the rendered graph",
    )
    parser.add_argument(
        "--show",
        action=argparse.BooleanOptionalAction,
        default=DEBUG_SHOW_GRAPH,
        help=(
            "Open the SVG after generation; the default is controlled by "
            "DEBUG_SHOW_GRAPH inside this file"
        ),
    )
    return parser


def output_paths(output_directory: str | Path) -> dict[str, Path]:
    directory = Path(output_directory).expanduser().resolve()
    return {name: directory / filename for name, filename in OUTPUT_FILES.items()}


def clear_previous_outputs(paths: dict[str, Path]) -> None:
    """Remove only files owned by this script so stale graphs cannot survive."""

    output_directory = next(iter(paths.values())).parent
    output_directory.mkdir(parents=True, exist_ok=True)
    for path in paths.values():
        if path.parent != output_directory:
            raise ValueError(f"Refusing to clean output outside {output_directory}: {path}")
        if path.exists():
            if not path.is_file():
                raise ValueError(f"Expected an output file but found a directory: {path}")
            path.unlink()


def open_graph(path: Path) -> None:
    if os.name == "nt":
        os.startfile(str(path))  # type: ignore[attr-defined]
    else:
        webbrowser.open(path.as_uri())


def diagnostic_summary(diagnostics: str, maximum_lines: int = 8) -> str:
    lines = [line.strip() for line in diagnostics.splitlines() if line.strip()]
    visible = lines[:maximum_lines]
    if len(lines) > maximum_lines:
        visible.append(f"... {len(lines) - maximum_lines} more diagnostic line(s) in JSON")
    return "\n".join(f"        {line}" for line in visible)


def report_progress(
    event: str,
    current: int,
    total: int,
    source: Path,
    diagnostics: str,
) -> None:
    prefix = f"[{current}/{total}]"
    if event == "start":
        print(f"{prefix} Clang parsing: {source}", flush=True)
        return
    if event == "ok":
        print(f"{prefix} OK: {source.name}", flush=True)
        return
    label = "TIMEOUT" if event == "timeout" else "FAILED"
    print(f"{prefix} {label}: {source}", file=sys.stderr, flush=True)
    summary = diagnostic_summary(diagnostics)
    if summary:
        print(summary, file=sys.stderr, flush=True)


def generate(args: argparse.Namespace) -> tuple[dict[str, Path], int]:
    paths = output_paths(args.output_dir)
    print(f"Cleaning previous outputs in: {paths['json'].parent}", flush=True)
    clear_previous_outputs(paths)

    # Clang parses each C translation unit separately. analyze_paths then combines every
    # discovered definition and call site before resolving one project-wide call graph.
    result = analyze_paths(
        args.inputs,
        clang=args.clang,
        project_root=args.project_root,
        compile_commands=args.compile_commands,
        clang_arguments=args.clang_arg,
        recursive=not args.no_recursive,
        extensions=args.extensions or (".c",),
        fail_fast=args.fail_fast,
        clang_timeout=args.clang_timeout,
        progress_callback=report_progress,
    )

    print("Building the combined project call graph...", flush=True)
    dot_source = to_dot(result, include_loops=not args.no_loop_nodes)
    print("Rendering SVG with Graphviz...", flush=True)
    svg_source = dot_to_svg(
        dot_source,
        args.dot_executable,
        timeout_seconds=args.render_timeout,
    )
    html_source = to_html(result, svg=svg_source, dot_source=dot_source)
    json_source = json.dumps(result.to_dict(), ensure_ascii=False, indent=2)

    print("Writing JSON, DOT, SVG, and HTML outputs...", flush=True)
    write_text(paths["json"], json_source + "\n")
    write_text(paths["dot"], dot_source)
    write_text(paths["svg"], svg_source)
    write_text(paths["html"], html_source)

    if args.show:
        open_graph(paths["svg"])

    return paths, result.statistics["translation_units_failed"]


def main(argv: Sequence[str] | None = None) -> int:
    args = build_parser().parse_args(argv)
    try:
        paths, failed_units = generate(args)
    except (AnalysisError, RenderError, OSError, ValueError) as exc:
        print(f"ERROR: {exc}", file=sys.stderr)
        return 2

    print(f"Call information: {paths['json']}")
    print(f"DOT graph:        {paths['dot']}")
    print(f"SVG graph:        {paths['svg']}")
    print(f"HTML report:      {paths['html']}")
    if failed_units:
        print(
            f"WARNING: {failed_units} input file(s) had Clang errors. "
            "See translation_units in callgraph.json.",
            file=sys.stderr,
        )
        return 1
    return 0


if __name__ == "__main__":
    raise SystemExit(main())
