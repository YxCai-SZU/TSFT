"""C/ACSL comment scanning and source-range operations."""

from __future__ import annotations

import re
import textwrap

from Clang.model import SourceLocation, SourceRange

from .common import (
    BACKGROUND,
    CODE_ANNOTATION,
    FUNCTION_CONTRACT,
    NORMAL_COMMENT,
    ByteSpan,
    CommentSpan,
    GroundTruthLabel,
    PreprocessingError,
    _canonicalize_ground_truth_label,
    _comment_category,
)

def scan_c_comments(data: bytes) -> list[CommentSpan]:
    """Lex C comments without mistaking comment markers inside strings for comments."""

    comments: list[CommentSpan] = []
    index = 0
    length = len(data)
    while index < length:
        byte = data[index]
        if byte in (ord('"'), ord("'")):
            quote = byte
            index += 1
            while index < length:
                if data[index] == ord("\\"):
                    index += 2
                    continue
                if data[index] == quote:
                    index += 1
                    break
                index += 1
            continue
        if byte == ord("/") and index + 1 < length:
            next_byte = data[index + 1]
            if next_byte == ord("/"):
                start = index
                index += 2
                while index < length and data[index] not in (ord("\r"), ord("\n")):
                    index += 1
                raw = data[start:index]
                comments.append(
                    CommentSpan(start, index, raw, _comment_category(raw))
                )
                continue
            if next_byte == ord("*"):
                start = index
                terminator = data.find(b"*/", index + 2)
                index = length if terminator < 0 else terminator + 2
                raw = data[start:index]
                comments.append(
                    CommentSpan(start, index, raw, _comment_category(raw))
                )
                continue
        index += 1
    return comments


class SourceDocument:
    def __init__(self, display_path: str, path: Path) -> None:
        self.display_path = display_path
        self.path = path.resolve()
        self.data = self.path.read_bytes()
        try:
            self.data.decode("utf-8")
        except UnicodeDecodeError as exc:
            raise PreprocessingError(
                f"Source file is not valid UTF-8: {self.path}: {exc}"
            ) from exc
        self.comments = scan_c_comments(self.data)

    def decode(self, start: int, end: int) -> str:
        return self.data[start:end].decode("utf-8")

    def line_start(self, offset: int) -> int:
        return self.data.rfind(b"\n", 0, offset) + 1

    def offset(self, location: SourceLocation) -> int:
        if location.offset is not None:
            return location.offset
        if location.line < 1 or location.column < 1:
            raise PreprocessingError(
                f"Invalid source location in {self.display_path}: "
                f"{location.line}:{location.column}"
            )
        line_offset = 0
        for _ in range(location.line - 1):
            newline = self.data.find(b"\n", line_offset)
            if newline < 0:
                raise PreprocessingError(
                    f"Source location is past EOF in {self.display_path}: "
                    f"{location.line}:{location.column}"
                )
            line_offset = newline + 1
        return line_offset + location.column - 1

    def source_span(self, source_range: SourceRange) -> ByteSpan:
        start = self.offset(source_range.start)
        end_offset = self.offset(source_range.end)
        token_length = source_range.end.token_length or 1
        end = min(len(self.data), end_offset + token_length)
        if not 0 <= start <= end <= len(self.data):
            raise PreprocessingError(
                f"Invalid source range in {self.display_path}: {start}..{end}"
            )
        return ByteSpan(start, end)

    def annotation_before(self, offset: int, expected_category: str) -> GroundTruthLabel | None:
        candidate_index: int | None = None
        for index in range(len(self.comments) - 1, -1, -1):
            if self.comments[index].end <= offset:
                candidate_index = index
                break
        if candidate_index is None:
            return None
        candidate = self.comments[candidate_index]
        if self.data[candidate.end:offset].strip() or candidate.category != expected_category:
            return None

        start = candidate.start
        index = candidate_index - 1
        while index >= 0:
            previous = self.comments[index]
            if previous.category != expected_category:
                break
            if self.data[previous.end:start].strip():
                break
            start = previous.start
            index -= 1
        span = ByteSpan(start, candidate.end)
        return GroundTruthLabel(
            span=span,
            text=_canonicalize_ground_truth_label(
                self.decode(span.start, span.end)
            ),
        )

    def declaration_contract_before(
        self,
        function_name: str,
        definition_offset: int,
    ) -> GroundTruthLabel | None:
        """Find a contract attached to an earlier declaration of a definition."""

        name_pattern = re.compile(
            rb"(?<![A-Za-z0-9_])"
            + re.escape(function_name.encode("utf-8"))
            + rb"\s*\("
        )
        for index in range(len(self.comments) - 1, -1, -1):
            candidate = self.comments[index]
            if candidate.end >= definition_offset or candidate.category != FUNCTION_CONTRACT:
                continue

            # Only the final annotation in an adjacent group is followed by the
            # declaration. The preceding annotations are included in its label.
            if index + 1 < len(self.comments):
                following = self.comments[index + 1]
                if (
                    following.end < definition_offset
                    and following.category == FUNCTION_CONTRACT
                    and not self.data[candidate.end:following.start].strip()
                ):
                    continue

            semicolon = self.data.find(b";", candidate.end, definition_offset)
            opening_brace = self.data.find(b"{", candidate.end, definition_offset)
            if semicolon < 0 or (opening_brace >= 0 and opening_brace < semicolon):
                continue
            declaration = self.data[candidate.end:semicolon]
            if name_pattern.search(declaration) is None:
                continue

            start = candidate.start
            previous_index = index - 1
            while previous_index >= 0:
                previous = self.comments[previous_index]
                if previous.category != FUNCTION_CONTRACT:
                    break
                if self.data[previous.end:start].strip():
                    break
                start = previous.start
                previous_index -= 1
            span = ByteSpan(start, candidate.end)
            return GroundTruthLabel(
                span=span,
                text=_canonicalize_ground_truth_label(
                    self.decode(span.start, span.end)
                ),
            )
        return None

    def background_spec(self) -> str:
        comments = [
            comment.raw.decode("utf-8").strip()
            for comment in self.comments
            if comment.category in (BACKGROUND, NORMAL_COMMENT)
        ]
        return "\n\n".join(comment for comment in comments if comment)

    def render_code(self, start: int, end: int) -> str:
        if start >= end:
            return ""
        removable = [
            comment
            for comment in self.comments
            if start <= comment.start and comment.end <= end
            and comment.category != CODE_ANNOTATION
        ]
        chunks: list[bytes] = []
        cursor = start
        for comment in removable:
            chunks.append(self.data[cursor:comment.start])
            newline_count = comment.raw.count(b"\n")
            chunks.append(b"\n" * newline_count if newline_count else b" ")
            cursor = comment.end
        chunks.append(self.data[cursor:end])
        text = b"".join(chunks).decode("utf-8")

        line_start = self.line_start(start)
        indentation = self.data[line_start:start]
        if indentation.strip() == b"":
            text = indentation.decode("utf-8") + text
        text = textwrap.dedent(text)

        cleaned: list[str] = []
        previous_blank = False
        for line in text.splitlines():
            line = line.rstrip()
            blank = not line.strip()
            if blank and previous_blank:
                continue
            cleaned.append(line)
            previous_blank = blank
        while cleaned and not cleaned[0].strip():
            cleaned.pop(0)
        while cleaned and not cleaned[-1].strip():
            cleaned.pop()
        return "\n".join(cleaned)
