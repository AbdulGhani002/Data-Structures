#!/bin/bash

# Create build directory if it doesn't exist
if [ ! -d "build" ]; then
  echo "Creating build directory..."
  mkdir build
fi

# Navigate to build directory
cd build || exit 1  # Exit if cd fails

# Run cmake to generate build files
echo "Running cmake..."
cmake .. || { echo "CMake configuration failed"; exit 1; }

# Run make to compile the project
echo "Running make to compile the project..."
make || { echo "Build failed"; exit 1; }

# Check if the runTests executable exists
if [ ! -f "./runTests" ]; then
  echo "runTests executable not found. Build might have failed."
  exit 1
fi

# Run the tests
echo "Running tests..."
./runTests || { echo "Tests failed"; exit 1; }

echo "All tests passed successfully!"

