from __future__ import annotations

import argparse
import json
import sys
from pathlib import Path
from typing import Sequence

from .analyzer import AnalysisError, analyze_paths
from .render import RenderError, dot_to_svg, to_dot, to_html, write_text


def build_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        prog="tsft-callgraph",
        description=(
            "Parse C files with Clang and emit a function call graph plus nested loop locations."
        ),
    )
    parser.add_argument("paths", nargs="+", help="C file(s) or directories to scan")
    parser.add_argument(
        "-o",
        "--output",
        "--json",
        dest="json_output",
        default="callgraph.json",
        help="JSON output path (default: callgraph.json)",
    )
    parser.add_argument("--dot", dest="dot_output", help="Optional Graphviz DOT output path")
    parser.add_argument("--svg", dest="svg_output", help="Optional rendered SVG output path")
    parser.add_argument("--html", dest="html_output", help="Optional standalone HTML report path")
    parser.add_argument(
        "--clang",
        help="Path to clang executable; otherwise auto-detected",
    )
    parser.add_argument(
        "--dot-executable",
        help="Path to Graphviz dot executable; otherwise auto-detected",
    )
    parser.add_argument(
        "--compile-commands",
        help="Optional compile_commands.json providing per-file compiler flags",
    )
    parser.add_argument(
        "--clang-arg",
        action="append",
        default=[],
        help="Extra Clang argument; use --clang-arg=-Iinclude for values beginning with '-'",
    )
    parser.add_argument(
        "--project-root",
        help="Root used to make source paths and stable IDs relative",
    )
    parser.add_argument(
        "--extension",
        action="append",
        dest="extensions",
        help="Source extension to include (repeatable; default: .c)",
    )
    parser.add_argument(
        "--no-recursive",
        action="store_true",
        help="Do not recursively scan input directories",
    )
    parser.add_argument(
        "--fail-fast",
        action="store_true",
        help="Stop on the first Clang parse error instead of recording it",
    )
    parser.add_argument(
        "--no-loop-nodes",
        action="store_true",
        help="Omit loop nodes from DOT/SVG/HTML while retaining them in JSON",
    )
    parser.add_argument("--indent", type=int, default=2, help="JSON indentation (default: 2)")
    return parser


def run(argv: Sequence[str] | None = None) -> int:
    args = build_parser().parse_args(argv)
    try:
        result = analyze_paths(
            args.paths,
            clang=args.clang,
            project_root=args.project_root,
            compile_commands=args.compile_commands,
            clang_arguments=args.clang_arg,
            recursive=not args.no_recursive,
            extensions=args.extensions or (".c",),
            fail_fast=args.fail_fast,
        )
        json_text = json.dumps(
            result.to_dict(), ensure_ascii=False, indent=args.indent, sort_keys=False
        )
        json_path = write_text(args.json_output, json_text + "\n")

        dot_source: str | None = None
        if args.dot_output or args.svg_output or args.html_output:
            dot_source = to_dot(result, include_loops=not args.no_loop_nodes)
        if args.dot_output and dot_source is not None:
            write_text(args.dot_output, dot_source)

        svg: str | None = None
        if args.svg_output or args.html_output:
            try:
                svg = dot_to_svg(dot_source or "", args.dot_executable)
            except RenderError:
                if args.svg_output:
                    raise
        if args.svg_output and svg is not None:
            write_text(args.svg_output, svg)
        if args.html_output:
            write_text(args.html_output, to_html(result, svg=svg, dot_source=dot_source))
    except (AnalysisError, RenderError, OSError, ValueError) as exc:
        print(f"ERROR: {exc}", file=sys.stderr)
        return 2

    stats = result.statistics
    print(f"JSON: {json_path}")
    print(
        "Analyzed "
        f"{stats['source_files']} files, {stats['functions']} functions, "
        f"{stats['calls']} calls, and {stats['loops']} loops."
    )
    if stats["translation_units_failed"]:
        print(
            f"WARNING: {stats['translation_units_failed']} translation unit(s) had Clang errors; "
            "see translation_units[].diagnostics in JSON.",
            file=sys.stderr,
        )
        return 1
    return 0


def main() -> None:
    raise SystemExit(run())


if __name__ == "__main__":
    main()
