#!/bin/bash

BASE_DIR="$(cd "$(dirname "$0")" && pwd)"
PROJECT_DIR="$(cd "$BASE_DIR/.." && pwd)"

SELS_DIR="$PROJECT_DIR/docs/sels"
OUTPUT_DIR="$PROJECT_DIR/docs/output"
REFERENCE="$PROJECT_DIR/docs/config/reference.docx"
ENV_FILE="$PROJECT_DIR/docs/config/.env"

set -a
source "$ENV_FILE"
set +a

mkdir -p "$OUTPUT_DIR"

shopt -s nullglob

FOUND=0

for INPUT in "$SELS_DIR"/*/report.md; do
  if [ ! -f "$INPUT" ]; then
    continue
  fi

  FOUND=1

  SW_DIR="$(dirname "$INPUT")"
  SW_NAME="$(basename "$SW_DIR")"

  OUTPUT_FILE="$OUTPUT_DIR/${SW_NAME}.docx"

  envsubst < "$INPUT" | pandoc \
    -o "$OUTPUT_FILE" \
    --reference-doc="$REFERENCE" \
    --from markdown \
    --standalone \
    --syntax-highlighting=pygments \
    --resource-path="$SW_DIR:." \
    --lua-filter="$BASE_DIR/lua/remove-hr.lua"

  echo "Generated: $OUTPUT_FILE"
done

if [ "$FOUND" -eq 0 ]; then
  echo "No sels/*/report.md files found in $SELS_DIR"
fi