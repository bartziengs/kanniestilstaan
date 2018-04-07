# Force CMake version 3.1 or above
cmake_minimum_required (VERSION 3.1)

# This project has the name: H02-arrays
project (H02-arrays)

# Create an executable named 'arrays' from the source file 'arrays.cxx'
add_executable(arrays src/arrays.cxx)

# Define C++11 standard
set_property(TARGET arrays PROPERTY CXX_STANDARD 11)

# Add test called "arrays-test" based on the executable "arrays"
add_test (arrays-test arrays)

# Create an additional target for assignment submission
add_assignment(arrays src/arrays.cxx)
