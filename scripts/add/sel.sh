#!/bin/bash

set -e

BASE_DIR="$(cd "$(dirname "$0")" && pwd)"
PROJECT_DIR="$(cd "$BASE_DIR/../.." && pwd)"

TEMPLATE_DIR="$PROJECT_DIR/src/sels/template"
SELS_DIR="$PROJECT_DIR/src/sels"
HEADER_FILE="$SELS_DIR/header.sels.hpp"
MAIN_FILE="$PROJECT_DIR/src/main.cpp"

# Determine self-study work number.
if [ -n "$1" ]; then
	if ! [[ "$1" =~ ^[0-9]{1,2}$ ]]; then
		echo "Error: self-study work number must be from 1 to 99."
		exit 1
	fi

	NUMBER=$((10#$1))
else
	NUMBER=0

	for DIR in "$SELS_DIR"/[0-9][0-9]; do
		[ -d "$DIR" ] || continue

		NAME="$(basename "$DIR")"

		if [ "$((10#$NAME))" -gt "$NUMBER" ]; then
			NUMBER=$((10#$NAME))
		fi
	done

	NUMBER=$((NUMBER + 1))
fi

if [ "$NUMBER" -lt 1 ] || [ "$NUMBER" -gt 99 ]; then
	echo "Error: self-study work number must be from 01 to 99."
	exit 1
fi

NUMBER="$(printf '%02d' "$NUMBER")"
OUTPUT_DIR="$SELS_DIR/$NUMBER"

if [ ! -d "$TEMPLATE_DIR" ]; then
	echo "Error: template directory not found: $TEMPLATE_DIR"
	exit 1
fi

if [ ! -f "$HEADER_FILE" ]; then
	echo "Error: sels header not found: $HEADER_FILE"
	exit 1
fi

if [ ! -f "$MAIN_FILE" ]; then
	echo "Error: main file not found: $MAIN_FILE"
	exit 1
fi

if [ -e "$OUTPUT_DIR" ]; then
	echo "Error: self-study directory already exists: $OUTPUT_DIR"
	exit 1
fi

# Copy template.
cp -R "$TEMPLATE_DIR" "$OUTPUT_DIR"

# Replace placeholders in filenames.
find "$OUTPUT_DIR" -depth -name '*__NUMBER__*' -print0 |
while IFS= read -r -d '' FILE; do
	NEW_FILE="${FILE//__NUMBER__/$NUMBER}"
	mv "$FILE" "$NEW_FILE"
done

# Current date.
YEAR="$(date '+%Y')"
MONTH="$(date '+%m')"
DAY="$(date '+%d')"

# Replace placeholders in all files.
find "$OUTPUT_DIR" -type f -print0 |
while IFS= read -r -d '' FILE; do
	sed -i '' \
		-e "s/__NUMBER__/$NUMBER/g" \
		-e "s/__YEAR__/$YEAR/g" \
		-e "s/__MONTH__/$MONTH/g" \
		-e "s/__DAY__/$DAY/g" \
		"$FILE"
done

# Add namespace declaration to the common sels header.
NAMESPACE_LINE="namespace sw${NUMBER} { void index(); }"

if ! grep -Fxq "$NAMESPACE_LINE" "$HEADER_FILE"; then
	sed -i '' "/^\/\/ Declare sels$/a\\
$NAMESPACE_LINE
" "$HEADER_FILE"
fi

# Append self-study handler to the sels map.
SEL_NUMBER=$((10#$NUMBER))
SEL_ENTRY="{${SEL_NUMBER}, sw${NUMBER}::index}"

if ! grep -Fq "$SEL_ENTRY" "$MAIN_FILE"; then
	python3 - "$MAIN_FILE" "$SEL_ENTRY" <<'PY'
import sys

path = sys.argv[1]
entry = sys.argv[2]

with open(path, "r", encoding="utf-8") as file:
	content = file.read()

marker = "map<int, Handler> sels ="
start = content.find(marker)

if start == -1:
	raise SystemExit("Error: sels map not found.")

brace_start = content.find("{", start)

if brace_start == -1:
	raise SystemExit("Error: sels map opening brace not found.")

brace_end = content.find("};", brace_start)

if brace_end == -1:
	raise SystemExit("Error: sels map closing brace not found.")

body = content[brace_start + 1:brace_end].strip()

if body:
	new_body = body.rstrip(",") + ",\n\t\t" + entry + "\n"
else:
	new_body = "\n\t\t" + entry + "\n"

content = (
	content[:brace_start + 1]
	+ new_body
	+ "\t"
	+ content[brace_end:]
)

with open(path, "w", encoding="utf-8") as file:
	file.write(content)
PY
fi

echo "Created self-study work $NUMBER:"
echo "$OUTPUT_DIR"