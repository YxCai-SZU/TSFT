"""Construct the three equivalent ACSL supervision candidates."""

from __future__ import annotations

from .clauses import _merge_equivalent_clauses, _reverse_equivalent_clause_runs
from .common import (
    FUNCTION_CONTRACT,
    LOOP_CONTRACT,
    _canonicalize_ground_truth_label,
    _comment_category,
    _normalized_acsl_payload,
)
from .expressions import _transform_clause_expressions

def _canonicalize_candidate_body(body: str) -> str:
    return _canonicalize_ground_truth_label(f"/*@\n{body.strip()}\n*/")


def generate_equivalent_candidates(
    label: str,
    target_type: str,
) -> tuple[str, str, str]:
    """Generate three conservative, loss-ready equivalents of one GT label.

    A transformation that has no applicable rule intentionally returns the
    canonical ground-truth label for that candidate.
    """

    if target_type not in {"function", "loop"}:
        raise ValueError("target_type must be function or loop")
    canonical_label = _canonicalize_ground_truth_label(label)
    body = _normalized_acsl_payload(canonical_label.encode("utf-8"))

    candidate_bodies = (
        _merge_equivalent_clauses(body),
        _transform_clause_expressions(body, normalize_implications=True),
        _reverse_equivalent_clause_runs(
            _transform_clause_expressions(
                body,
                reflect_relations=True,
                rename_quantifiers=True,
            )
        ),
    )
    expected_category = FUNCTION_CONTRACT if target_type == "function" else LOOP_CONTRACT
    candidates: list[str] = []
    for candidate_body in candidate_bodies:
        candidate = _canonicalize_candidate_body(candidate_body)
        if _comment_category(candidate.encode("utf-8")) != expected_category:
            candidate = canonical_label
        candidates.append(candidate)
    return candidates[0], candidates[1], candidates[2]


def _label_fields(label: str, target_type: str) -> dict[str, str]:
    canonical_label = _canonicalize_ground_truth_label(label)
    cand1, cand2, cand3 = generate_equivalent_candidates(
        canonical_label,
        target_type,
    )
    return {
        "label": canonical_label,
        "cand1": cand1,
        "cand2": cand2,
        "cand3": cand3,
    }
