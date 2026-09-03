#!/bin/bash

set -e

PROJECT_DIR="$(cd "$(dirname "$0")/.." && pwd)"
BUILD_DIR="$PROJECT_DIR/.output"
OUTPUT="$BUILD_DIR/main"

mkdir -p "$BUILD_DIR"

# Find all C++ source files in the project.
SOURCES=()

while IFS= read -r -d '' FILE; do
    SOURCES+=("$FILE")
done < <(
    find "$PROJECT_DIR" \
        -type f \
        -name '*.cpp' \
        ! -path "$BUILD_DIR/*" \
        ! -path "$PROJECT_DIR/src/labs/template/*" \
        ! -path "$PROJECT_DIR/src/sels/template/*" \
        -print0
)

echo "Building..."

c++ \
    -std=c++17 \
    -Wall \
    -Wextra \
    -I"$PROJECT_DIR/src" \
    -I"$PROJECT_DIR/docs/labs" \
    "${SOURCES[@]}" \
    -o "$OUTPUT"

echo "Running..."
echo

cd "$PROJECT_DIR"
exec "$OUTPUT"