# Force CMake version 3.1 or above
cmake_minimum_required (VERSION 3.1)

# This project has the name: 21-algorithm
project (21-algorithm)

# Create an executable named 'algorithm' from the source file 'algorithm.cxx'
add_executable(algorithm src/algorithm.cxx)

# Define C++11 standard
set_property(TARGET algorithm PROPERTY CXX_STANDARD 11)

# Add test called "algorithm-test" based on the executable "algorithm"
add_test (algorithm-test algorithm)
