#!/bin/bash

# Directory to compile to and to store the solution
SOLUTION_DIR="$PWD/solution"

# Create the solution directory if it doesn't exist already
if [ ! -d "$SOLUTION_DIR" ]; then
  mkdir -p "$SOLUTION_DIR"
fi

# Compile the code using GNU compiler
c++ ./*.cpp headers/*.h -std=c++17 -o "$SOLUTION_DIR/blasius"

cd "$SOLUTION_DIR"

# Run the compiled executable
if [ -f blasius ]; then
  ./blasius
else
  echo "Something went wrong."
fi
