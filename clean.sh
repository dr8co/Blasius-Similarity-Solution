#!/bin/bash

# Run from this directory.
cd "${0%/*}" || exit 1

# Solution directory
SOLUTION_DIR="$PWD/solution"

# Only clean the directory if it exists
if [ -d "$SOLUTION_DIR" ]; then
  rm -rf "${SOLUTION_DIR:?}"/{,.[!.],..?}*
else
  echo "The solution directory doesn't exist."
fi
