#!/bin/bash

LIBREOFFICE="/Applications/LibreOffice.app/Contents/MacOS/soffice"

BASE_DIR="$(cd "$(dirname "$0")" && pwd)"
PROJECT_DIR="$(cd "$BASE_DIR/.." && pwd)"
LABS_DIR="$PROJECT_DIR/src/labs"

shopt -s nullglob

FOUND=0

for INPUT in "$LABS_DIR"/*/docs/*.doc "$LABS_DIR"/*/docs/*.docx; do
	if [ ! -f "$INPUT" ]; then
		continue
	fi

	FOUND=1

	DIR="$(dirname "$INPUT")"
	FILENAME="$(basename "$INPUT")"
	NAME="${FILENAME%.*}"

	if [[ "$INPUT" == *.doc ]]; then
		TEMP_DIR="$(mktemp -d)"

		"$LIBREOFFICE" \
			--headless \
			--convert-to docx \
			--outdir "$TEMP_DIR" \
			"$INPUT" >/dev/null

		INPUT_DOCX="$TEMP_DIR/$NAME.docx"

		if [ ! -f "$INPUT_DOCX" ]; then
			echo "Failed to convert: $INPUT"
			rm -rf "$TEMP_DIR"
			continue
		fi
	else
		INPUT_DOCX="$INPUT"
		TEMP_DIR=""
	fi

	OUTPUT="$DIR/${NAME%.source}.converted.md"

	pandoc \
		"$INPUT_DOCX" \
		-o "$OUTPUT" \
		--from docx \
		--to markdown \
		--standalone \
		--extract-media="$DIR"

	chown "$(whoami)":staff "$OUTPUT"

	if [ -n "$TEMP_DIR" ]; then
		rm -rf "$TEMP_DIR"
	fi

	echo "Converted: $INPUT"
	echo "        -> $OUTPUT"
done

if [ "$FOUND" -eq 0 ]; then
	echo "No .doc or .docx files found in $LABS_DIR/*/docs"
fi