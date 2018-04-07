# Force CMake version 3.1 or above
cmake_minimum_required (VERSION 3.1)

# This project has the name: H04-points-triangles
project (H04-points-triangles)

# Create an executable named 'points-triangles' from the source file 'points-triangles.cxx'
add_executable(points-triangles src/points-triangles.cxx)

# Define C++11 standard
set_property(TARGET points-triangles PROPERTY CXX_STANDARD 11)

# Add test called "points-triangles-test" based on the executable "points-triangles"
add_test (points-triangles-test points-triangles)

# Create an additional target for assignment submission
add_assignment(points-triangles src/points-triangles.cxx)
