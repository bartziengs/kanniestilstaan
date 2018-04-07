# ...

# Create an additional target for assignment submission
#add_assignment(... src/...)

# Force CMake version 3.1 or above
cmake_minimum_required (VERSION 3.1)

# This project has the name: H04-points-triangles
project (H05-copy-move)

# Create an executable named 'points-triangles' from the source file 'points-triangles.cxx'
add_executable(movecopy src/movecopy.cxx)

# Define C++11 standard
set_property(TARGET movecopy PROPERTY CXX_STANDARD 11)

# Add test called "movecopy-test" based on the executable "movecopy"
add_test (movecopy-test movecopy)

# Create an additional target for assignment submission
add_assignment(movecopy src/movecopy.cxx)
