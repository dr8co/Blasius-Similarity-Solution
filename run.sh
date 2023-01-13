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

# Compile the code using GNU compiler.
c++ -Wall -Wextra -pedantic -Ofast -std=c++23 ./*.cpp -o "$SOLUTION_DIR/blasius"

cd "$SOLUTION_DIR" || exit 1

# Run the compiled executable.
if [ -f blasius ]; then
  ./blasius
else
  echo "Something went wrong."
fi
