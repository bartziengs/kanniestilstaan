# Force CMake version 3.1 or above
cmake_minimum_required (VERSION 3.1)

# This project has the name: H10-add-vectors
project (H11-heat-equation)

# Create an executable named 'add-vectors' from the source file 'add-vectors.cxx'
add_executable(heat-equation src/heat-equation.cxx)

# Define C++11 standard
set_property(TARGET heat-equation PROPERTY CXX_STANDARD 14)

# Create an additional target for assignment submission
add_assignment(heat-equation src/heat-equation.cxx)