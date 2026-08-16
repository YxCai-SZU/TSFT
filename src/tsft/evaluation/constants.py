"""Shared constants and errors for TSFT evaluation."""

from __future__ import annotations

import re
from pathlib import Path

PROJECT_ROOT = Path(__file__).resolve().parents[3]


class EvaluationPipelineError(RuntimeError):
    """Raised when an evaluation workflow cannot process its input."""


_HARNESS_NAMES = frozenset({"main", "test", "tests", "harness", "test_harness"})
_HARNESS_POLICIES = frozenset({"none", "entrypoint_names", "all_functions"})
_FRAMA_C_DATASET_DIR = "frama-c-problems"
_PROMPT_SECTIONS = (
    "===== TARGET TYPE =====",
    "===== BACKGROUND SPECIFICATION =====",
    "===== CURRENT CODE =====",
    "===== UPSTREAM CONTEXT =====",
    "===== DOWNSTREAM CONTEXT =====",
    "Generate the ACSL specification for the current target now.",
)
_WP_SUMMARY = re.compile(r"Proved goals:\s*(\d+)\s*/\s*(\d+)", re.IGNORECASE)
_DEFAULT_MAX_INPUT_TOKENS = 4096
_DEFAULT_MAX_NEW_TOKENS = 2048
