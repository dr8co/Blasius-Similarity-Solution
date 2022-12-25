#!/usr/bin/bash

# Directory to compile to and to store the solution
SOLUTION_DIR="$PWD/solution"

# Create the solution directory if it doesn't exist already
if [ ! -d "$SOLUTION_DIR" ]; then
  mkdir -p "$SOLUTION_DIR"
fi

# Generate build files using CMake and Ninja
"$(command -v cmake)" -DCMAKE_BUILD_TYPE=Debug -DCMAKE_MAKE_PROGRAM="$(command -v ninja)" -G Ninja -S "$PWD" -B "$SOLUTION_DIR"

# Build the solution
"$(command -v cmake)" --build "$SOLUTION_DIR" --target blasius -j 3

# Run the compiled executable
cd "$SOLUTION_DIR" && ./blasius
