# Force CMake version 3.1 or above
cmake_minimum_required (VERSION 3.1)

# This project has the name: 24-maps
project (24-maps)

# Create an executable named 'maps' from the source file 'maps.cxx'
include_directories(src)
add_executable(maps src/maps.cxx)

# Define C++11 standard
set_property(TARGET maps PROPERTY CXX_STANDARD 11)

# Add test called "maps-test" based on the executable "maps"
add_test (maps-test maps)