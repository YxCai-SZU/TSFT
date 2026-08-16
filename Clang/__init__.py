"""Standalone Clang-based C call graph and loop structure analysis."""

from .analyzer import AnalysisError, analyze_paths, discover_clang, discover_source_files
from .model import AnalysisResult

__all__ = [
    "AnalysisError",
    "AnalysisResult",
    "analyze_paths",
    "discover_clang",
    "discover_source_files",
]
