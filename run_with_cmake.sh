#!/bin/bash

# Run from this directory.
cd "${0%/*}" || exit 1

# Directory to compile to and to store the solution
SOLUTION_DIR="$PWD/solution"

# Clean the solution directory if it exists, or create it if it doesn't.
if [ -d "$SOLUTION_DIR" ]; then
  ./clean.sh
  else
    mkdir -p "$SOLUTION_DIR"
fi

# Generate build files using CMake and Ninja
"$(command -v cmake)" -DCMAKE_BUILD_TYPE=Release -DCMAKE_MAKE_PROGRAM="$(command -v ninja)" -G Ninja -S "$PWD" -B "$SOLUTION_DIR"

# Build the solution
"$(command -v cmake)" --build "$SOLUTION_DIR" --target blasius -j 4

# Run the compiled executable
cd "$SOLUTION_DIR" && ./blasius
