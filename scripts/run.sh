#!/bin/bash

set -e

PROJECT_DIR="$(cd "$(dirname "$0")/.." && pwd)"
ENV_FILE="$PROJECT_DIR/config/.env"
BUILD_DIR="$PROJECT_DIR/.output"
OUTPUT="$BUILD_DIR/AstuArosSemIII"

# Load environment variables from config/.env.
if [ -f "$ENV_FILE" ]; then
    set -a
    source "$ENV_FILE"
    set +a
fi

echo "Building..."
"$PROJECT_DIR/scripts/build.sh"

echo
echo "Running..."
echo

cd "$PROJECT_DIR"
exec "$OUTPUT"