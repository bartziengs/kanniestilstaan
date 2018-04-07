# Force CMake version 3.1 or above
cmake_minimum_required (VERSION 3.1)

# This project has the name: 15-traits
project (15-traits)

# Create an executable named 'traits' from the source file 'traits.cxx'
add_executable(traits src/traits.cxx)

# Define C++11 standard
set_property(TARGET traits PROPERTY CXX_STANDARD 11)

# Add test called "traits-test" based on the executable "traits"
add_test (traits-test traits)