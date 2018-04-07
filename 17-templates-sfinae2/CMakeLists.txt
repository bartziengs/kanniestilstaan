# Force CMake version 3.1 or above
cmake_minimum_required (VERSION 3.1)

# This project has the name: 17-templates-sfinae2
project (17-templates-sfinae2)

# Create an executable named 'templates-sfinae2' from the source file 'templates-sfinae2.cxx'
add_executable(templates-sfinae2 src/templates-sfinae2.cxx)

# Define C++11 standard
set_property(TARGET templates-sfinae2 PROPERTY CXX_STANDARD 11)

# Add test called "templates-sfinae2-test" based on the executable "templates-sfinae2"
add_test (templates-sfinae2-test templates-sfinae2)
