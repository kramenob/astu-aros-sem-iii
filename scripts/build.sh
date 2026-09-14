#!/bin/bash

set -e

PROJECT_DIR="$(cd "$(dirname "$0")/.." && pwd)"
BUILD_DIR="$PROJECT_DIR/.output"

echo "Configuring CMake..."
cmake -S "$PROJECT_DIR/src" -B "$BUILD_DIR" \
    -DCMAKE_OSX_ARCHITECTURES=x86_64

echo "Building..."
cmake --build "$BUILD_DIR"

echo
echo "Build complete."