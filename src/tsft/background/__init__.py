"""Public ACSL background-removal API."""

from .annotations import (
    annotation_payload,
    definitions_from_payload,
    scan_acsl_annotations,
)
from .common import (
    AnnotationSpan,
    FileResult,
    LogicDefinition,
    TransformReport,
    TransformationError,
    VerificationReport,
    atomic_write_text,
)
from .expansion import DefinitionExpander, transform_source
from .pipeline import clean_dataset, discover_c_files, process_file
from .verification import (
    build_frama_command,
    ensure_tool_available,
    verify_with_wp,
    windows_path_to_wsl,
)

__all__ = [
    "AnnotationSpan",
    "DefinitionExpander",
    "FileResult",
    "LogicDefinition",
    "TransformReport",
    "TransformationError",
    "VerificationReport",
    "atomic_write_text",
    "build_frama_command",
    "clean_dataset",
    "discover_c_files",
    "ensure_tool_available",
    "process_file",
    "transform_source",
    "verify_with_wp",
    "windows_path_to_wsl",
]
