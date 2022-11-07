#!/usr/bin/bash

# Solution directory
SOLUTION_DIR="$PWD/solution"

# Only clean the directory if it exists
if [ -d "$SOLUTION_DIR" ]; then
  rm -rf "${SOLUTION_DIR:?}"/{,.[!.],..?}*
else
  echo "The solution directory doesn't exist."
fi
