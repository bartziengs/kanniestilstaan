# Force CMake version 3.1 or above
cmake_minimum_required (VERSION 3.1)

# This project has the name: 09-copy-move
project (09-copy-move)

# Create an executable named 'copy-move' from the source file 'copy-move.cxx'
add_executable(copy-move src/copy-move.cxx)

# Define C++11 standard
set_property(TARGET copy-move PROPERTY CXX_STANDARD 11)

# Add test called "copy-move-test" based on the executable "copy-move"
add_test (copy-move-test copy-move)
