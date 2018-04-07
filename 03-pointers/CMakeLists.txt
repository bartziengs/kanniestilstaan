# Force CMake version 3.1 or above
cmake_minimum_required (VERSION 3.1)

# This project has the name: 03-pointers
project (03-pointers)

# Create an executable named 'pointers' from the source file 'pointers.cxx'
add_executable(pointers src/pointers.cxx)

# Define C++11 standard
set_property(TARGET pointers PROPERTY CXX_STANDARD 11)

# Add test called "pointers-test" based on the executable "pointers"
add_test (pointers-test pointers)
