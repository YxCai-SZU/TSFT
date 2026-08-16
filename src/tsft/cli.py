"""Command-line argument definitions shared by the public entry points."""

from __future__ import annotations

import argparse
import os


def training_data_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        description=(
            "Recursively convert ground-truth ACSL C files into function and "
            "loop training records."
        )
    )
    parser.add_argument(
        "--inputdir",
        default="./data",
        metavar="DIRECTORY",
        help=(
            "Directory containing labeled C files; all subdirectories are scanned "
            "(default: ./data)"
        ),
    )
    parser.add_argument(
        "--outputdir",
        default="./trainingData",
        metavar="DIRECTORY",
        help="Directory for generated JSON files (default: ./trainingData)",
    )
    return parser


def background_removal_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        description=(
            "Inline direct ACSL predicate/logic definitions, remove formal background "
            "declarations, and retain only files fully proved by Frama-C/WP."
        )
    )
    parser.add_argument("input_directory", help="Flat or recursively nested C source tree")
    parser.add_argument("output_directory", help="Clean verified output tree")
    parser.add_argument("--frama-c", default="frama-c")
    parser.add_argument("--wp-prover", default="alt-ergo,z3")
    parser.add_argument("--wp-timeout", type=int, default=5, help="Seconds per WP goal")
    parser.add_argument("--file-timeout", type=float, default=30.0)
    parser.add_argument("--machdep", default=None)
    parser.add_argument("--cpp-extra-arg", action="append", default=[])
    parser.add_argument(
        "--wsl-distribution",
        help="Run Frama-C through this WSL distribution (for Windows hosts)",
    )
    parser.add_argument(
        "--workers",
        type=int,
        default=max(1, min(8, os.cpu_count() or 1)),
    )
    parser.add_argument("--resume", action="store_true")
    parser.add_argument("--max-files", type=int)
    parser.add_argument("--max-expanded-chars", type=int, default=1_000_000)
    parser.add_argument("--checkpoint-every", type=int, default=100)
    parser.add_argument("--progress-every", type=int, default=100)
    parser.add_argument("--quiet", action="store_true")
    return parser


def validate_background_args(args: argparse.Namespace) -> None:
    if args.workers <= 0:
        raise ValueError("--workers must be positive")
    if args.wp_timeout <= 0 or args.file_timeout <= 0:
        raise ValueError("WP and file timeouts must be positive")
    if args.max_files is not None and args.max_files <= 0:
        raise ValueError("--max-files must be positive")
    if (
        args.max_expanded_chars <= 0
        or args.checkpoint_every <= 0
        or args.progress_every <= 0
    ):
        raise ValueError("expansion and progress limits must be positive")
    if args.wsl_distribution and os.name != "nt":
        raise ValueError("--wsl-distribution is supported only on Windows")


def training_parser() -> argparse.ArgumentParser:
    parser = argparse.ArgumentParser(
        description="Fine-tune a local model for ACSL generation"
    )
    parser.add_argument("--config", default="configs/train.yaml")
    return parser
