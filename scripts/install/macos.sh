#!/bin/bash

set -e

BASE_DIR="$(cd "$(dirname "$0")" && pwd)"
PROJECT_DIR="$(cd "$BASE_DIR/../.." && pwd)"
REQUIREMENTS_FILE="$PROJECT_DIR/docs/config/requirements"

if ! command -v brew >/dev/null 2>&1; then
  echo "Homebrew is not installed."
  echo "Install it from https://brew.sh"
  exit 1
fi

if [ ! -f "$REQUIREMENTS_FILE" ]; then
  echo "Requirements file not found: $REQUIREMENTS_FILE"
  exit 1
fi

echo "Installing dependencies from $REQUIREMENTS_FILE"

while IFS= read -r package || [ -n "$package" ]; do
  package="$(echo "$package" | xargs)"

  if [ -z "$package" ]; then
    continue
  fi

  echo "Installing: $package"
  brew install "$package"
done < "$REQUIREMENTS_FILE"

echo "Done."
