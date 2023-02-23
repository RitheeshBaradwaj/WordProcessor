#!/bin/bash

# Define variables
CLEANUP=false

# Parse command-line arguments
while getopts "c" opt; do
  case $opt in
    c) CLEANUP=true ;;
    *) echo "Invalid option: -$OPTARG" >&2; exit 1 ;;
  esac
done

if [ "$CLEANUP" = true ]; then
  # Cleanup
  rm -rf _*
fi

# Create a build directory and navigate into it
if [ ! -d "_build" ]; then
  mkdir _build
fi
cd _build

# Run CMake to generate the build files
cmake -DCODE_COVERAGE=ON -DCMAKE_C_COMPILER=gcc -DCMAKE_CXX_COMPILER=g++ ..

# Build the project using make
cmake --build . --target all test

# Generate the coverage report using lcov
make coverage

cd ..
