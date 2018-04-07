# Force CMake version 3.1 or above
cmake_minimum_required (VERSION 3.1)

# This project has the name: 04-passing-arguments
project (04-passing-arguments)

# Create an executable named 'passing-arguments' from the source file 'passing-arguments.cxx'
add_executable(passing-arguments src/passing-arguments.cxx)

# Define C++11 standard
set_property(TARGET passing-arguments PROPERTY CXX_STANDARD 11)

# Add test called "passing-arguments-test" based on the executable "passing-arguments"
add_test (passing-arguments-test passing-arguments)
