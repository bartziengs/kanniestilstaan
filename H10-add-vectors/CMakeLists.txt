# Force CMake version 3.1 or above
cmake_minimum_required (VERSION 3.1)

# This project has the name: H10-add-vectors
project (H10-add-vectors)

# Create an executable named 'add-vectors' from the source file 'add-vectors.cxx'
add_executable(add-vectors src/add-vectors.cxx)

# Define C++11 standard
set_property(TARGET add-vectors PROPERTY CXX_STANDARD 14)

# Create an additional target for assignment submission
add_assignment(add-vectors src/add-vectors.cxx)