"""Construct and execute Frama-C/WP verification commands."""

from __future__ import annotations

import os
from pathlib import Path
import shlex
import shutil
import subprocess
import time
from typing import Sequence

from .common import VerificationReport, WP_SUMMARY

def windows_path_to_wsl(path: Path) -> str:
    resolved = path.resolve()
    drive = resolved.drive
    if not drive or len(drive) < 1:
        raise ValueError(f"cannot convert path to WSL: {resolved}")
    relative = resolved.as_posix()[2:].lstrip("/")
    return f"/mnt/{drive[0].lower()}/{relative}"


def build_frama_command(
    candidate: Path,
    *,
    frama_c: str,
    prover: str,
    wp_timeout: int,
    machdep: str | None,
    cpp_extra_args: Sequence[str],
    wsl_distribution: str | None,
) -> list[str]:
    arguments = [
        frama_c,
        "-kernel-warn-key",
        "annot-error=abort",
        "-wp",
        "-wp-prover",
        prover,
        "-wp-timeout",
        str(wp_timeout),
    ]
    if machdep:
        arguments.extend(["-machdep", machdep])
    if cpp_extra_args:
        arguments.append(f"-cpp-extra-args={' '.join(cpp_extra_args)}")
    arguments.append(
        windows_path_to_wsl(candidate) if wsl_distribution else str(candidate.resolve())
    )
    if not wsl_distribution:
        return arguments

    shell_command = "eval \"$(opam env 2>/dev/null)\"; exec " + " ".join(
        shlex.quote(item) for item in arguments
    )
    return [
        "wsl.exe",
        "-d",
        wsl_distribution,
        "--exec",
        "/bin/sh",
        "-lc",
        shell_command,
    ]


def verify_with_wp(
    candidate: Path,
    *,
    frama_c: str,
    prover: str,
    wp_timeout: int,
    file_timeout: float,
    machdep: str | None,
    cpp_extra_args: Sequence[str],
    wsl_distribution: str | None,
) -> VerificationReport:
    command = build_frama_command(
        candidate,
        frama_c=frama_c,
        prover=prover,
        wp_timeout=wp_timeout,
        machdep=machdep,
        cpp_extra_args=cpp_extra_args,
        wsl_distribution=wsl_distribution,
    )
    started = time.monotonic()
    try:
        process = subprocess.run(
            command,
            stdout=subprocess.PIPE,
            stderr=subprocess.STDOUT,
            check=False,
            timeout=file_timeout,
        )
        raw_output = process.stdout or b""
        output = raw_output.decode("utf-8", errors="replace").replace("\x00", "")
        summaries = WP_SUMMARY.findall(output)
        proved, total = (map(int, summaries[-1]) if summaries else (0, 0))
        passed = process.returncode == 0 and total > 0 and proved == total
        return VerificationReport(
            passed=passed,
            returncode=process.returncode,
            timeout=False,
            proved_goals=proved,
            total_goals=total,
            seconds=round(time.monotonic() - started, 3),
        )
    except subprocess.TimeoutExpired:
        return VerificationReport(
            passed=False,
            returncode=None,
            timeout=True,
            proved_goals=0,
            total_goals=0,
            seconds=round(time.monotonic() - started, 3),
        )


def ensure_tool_available(frama_c: str, wsl_distribution: str | None) -> None:
    if wsl_distribution:
        if shutil.which("wsl.exe") is None:
            raise RuntimeError("wsl.exe was not found")
        command = [
            "wsl.exe",
            "-d",
            wsl_distribution,
            "--exec",
            "/bin/sh",
            "-lc",
            f'eval "$(opam env 2>/dev/null)"; {shlex.quote(frama_c)} -version',
        ]
    else:
        executable = shutil.which(frama_c)
        if executable is None:
            raise RuntimeError(f"Frama-C executable was not found: {frama_c}")
        command = [executable, "-version"]
    process = subprocess.run(
        command, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, timeout=30, check=False
    )
    if process.returncode != 0:
        output = (process.stdout or b"").decode("utf-8", errors="replace")
        raise RuntimeError(f"Frama-C check failed: {output}")
