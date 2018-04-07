# Force CMake version 3.1 or above
cmake_minimum_required (VERSION 3.1)

# This project has the name: H09-symbolic-differentiation
project (H09-symbolic-differentiation)

# Create an executable named 'points-triangles' from the source file 'templates.cxx'
add_executable(symbolic-differentiation src/symbolic-differentiation)

# Define C++11 standard
set_property(TARGET symbolic-differentiation PROPERTY CXX_STANDARD 14)

# Add test called "templates-test" based on the executable "templates"
add_test (symbolic-differentiation-test symbolic-differentiation)

# Create an additional target for assignment submission
add_assignment(symbolic-differentiation src/symbolic-differentiation.cxx)
