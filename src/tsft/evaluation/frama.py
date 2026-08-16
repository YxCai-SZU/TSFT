"""Frama-C executable resolution and WP process execution."""

from __future__ import annotations

import os
import shutil
import subprocess
import time
from pathlib import Path
from typing import Any

from .constants import PROJECT_ROOT as _PROJECT_ROOT, _WP_SUMMARY


def _resolve_frama_c_executable(executable: str | Path) -> str:
    """Resolve Frama-C from an explicit path, ``PATH``, or this project.

    The project installer deliberately keeps its launcher under
    ``frama-c-setup/bin`` and does not modify a user's shell profile.  A bare
    ``frama-c`` therefore prefers that project-local launcher and falls back to
    ``PATH`` when no local installation exists.  Explicit paths are preserved,
    including missing paths, so their eventual startup error remains visible
    to the verifier instead of silently selecting a different executable.
    """

    raw = os.fspath(executable)
    if not raw:
        return raw

    requested = Path(raw).expanduser()
    # A path containing a directory component is an explicit user choice.
    # Keep a missing explicit path unchanged so verification can report it in
    # the per-attempt Frama-C log.
    if requested.is_absolute() or requested.parent != Path("."):
        if requested.is_file():
            return str(requested.resolve())
        return raw

    if raw.casefold() in {"frama-c", "frama-c.exe"}:
        local_bin = _PROJECT_ROOT / "frama-c-setup" / "bin"
        names = (raw, "frama-c.exe" if raw.casefold() == "frama-c" else "frama-c")
        for name in names:
            candidate = local_bin / name
            if candidate.is_file():
                return str(candidate.resolve())

    located = shutil.which(raw)
    if located:
        return located

    # Let subprocess produce a clear, persisted startup error for an unknown
    # command rather than failing during workflow setup.
    return raw


def _run_command(command: list[str], timeout: float, cwd: Path) -> dict[str, Any]:
    started = time.monotonic()
    try:
        process = subprocess.run(
            command,
            cwd=cwd,
            capture_output=True,
            text=True,
            encoding="utf-8",
            errors="replace",
            timeout=timeout,
            check=False,
        )
        output = (process.stdout + "\n" + process.stderr).strip()
        summaries = _WP_SUMMARY.findall(output)
        result: dict[str, Any] = {
            "returncode": process.returncode,
            "timeout": False,
            "seconds": round(time.monotonic() - started, 3),
            "output": output[-4000:],
            "full_output": output,
        }
        if summaries:
            proved, total = summaries[-1]
            result["wp_summary"] = {
                "proved_goals": int(proved),
                "total_goals": int(total),
            }
        return result
    except subprocess.TimeoutExpired as exc:
        output = "\n".join(
            value.decode("utf-8", errors="replace") if isinstance(value, bytes) else value or ""
            for value in (exc.stdout, exc.stderr)
        ).strip()
        return {
            "returncode": None,
            "timeout": True,
            "seconds": round(time.monotonic() - started, 3),
            "output": output[-4000:],
            "full_output": output,
        }
    except OSError as exc:
        # ``subprocess.run`` raises before a child process exists when the
        # executable cannot be found or started.  Persist the diagnostic in
        # the same fields as normal Frama-C output so ``frama-c.log`` is never
        # silently empty for this failure mode.
        output = "\n".join(
            (
                f"{type(exc).__name__}: {exc}",
                f"Command: {' '.join(str(part) for part in command)}",
                f"Working directory: {cwd}",
            )
        )
        return {
            "returncode": None,
            "timeout": False,
            "seconds": round(time.monotonic() - started, 3),
            "output": output[-4000:],
            "full_output": output,
            "error": f"{type(exc).__name__}: {exc}",
        }


def _frama_c_wp_command(
    executable: str | Path,
    source_file: Path,
    original_parent: Path,
    *,
    wp_prover: str,
    wp_timeout: int,
    wp_function: str | None = None,
    exclude_termination_goals: bool = True,
) -> list[str]:
    command = [
        str(executable),
        "-kernel-warn-key",
        "annot-error=abort",
        f"-cpp-extra-args=-I{original_parent}",
        "-wp",
        "-wp-prover",
        wp_prover,
        "-wp-timeout",
        str(wp_timeout),
    ]
    if wp_function:
        command.extend(["-wp-fct", wp_function])
    if exclude_termination_goals:
        command.append("-wp-prop=-@variant,-@terminates,-@decreases")
    command.append(str(source_file))
    return command
