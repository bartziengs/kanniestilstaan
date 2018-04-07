# Force CMake version 3.1 or above
cmake_minimum_required (VERSION 3.1)

# This project has the name: 15-templates-sfinae
project (15-templates-sfinae)

# Create an executable named 'templates-sfinae' from the source file 'templates-sfinae.cxx'
add_executable(templates-sfinae src/templates-sfinae.cxx)

# Define C++11 standard
set_property(TARGET templates-sfinae PROPERTY CXX_STANDARD 11)

# Add test called "templates-sfinae-test" based on the executable "templates-sfinae"
add_test (templates-sfinae-test templates-sfinae)
