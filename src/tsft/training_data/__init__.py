"""Public training-data preprocessing API."""

from .builder import (
    TrainingDataBuilder,
    audit_training_sources,
    build_prompt,
    build_training_samples,
)
from .candidates import (
    _canonicalize_candidate_body,
    _label_fields,
    generate_equivalent_candidates,
)
from .common import (
    BACKGROUND,
    CODE_ANNOTATION,
    FUNCTION_CONTRACT,
    LOOP_CONTRACT,
    NORMAL_COMMENT,
    AppendResult,
    BuildResult,
    ByteSpan,
    CommentSpan,
    GroundTruthLabel,
    PreprocessingError,
    TrainingSourceAudit,
    _canonicalize_ground_truth_label,
)
from .source import SourceDocument, scan_c_comments
from .storage import (
    _atomic_write_json,
    _next_output_file,
    _progress,
    append_training_samples,
    delete_invalid_source_files,
)

__all__ = [
    "BACKGROUND",
    "CODE_ANNOTATION",
    "FUNCTION_CONTRACT",
    "LOOP_CONTRACT",
    "NORMAL_COMMENT",
    "AppendResult",
    "BuildResult",
    "ByteSpan",
    "CommentSpan",
    "GroundTruthLabel",
    "PreprocessingError",
    "SourceDocument",
    "TrainingDataBuilder",
    "TrainingSourceAudit",
    "append_training_samples",
    "audit_training_sources",
    "build_prompt",
    "build_training_samples",
    "delete_invalid_source_files",
    "generate_equivalent_candidates",
    "scan_c_comments",
]
