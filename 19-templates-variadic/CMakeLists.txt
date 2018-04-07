# Force CMake version 3.1 or above
cmake_minimum_required (VERSION 3.1)

# This project has the name: 19-templates-variadic
project (19-templates-variadic)

# Create an executable named 'templates-variadic' from the source file 'templates-variadic.cxx'
add_executable(templates-variadic src/templates-variadic.cxx)

# Define C++14 standard
set_property(TARGET templates-variadic PROPERTY CXX_STANDARD 14)

# Add test called "templates-variadic-test" based on the executable "templates-variadic"
add_test (templates-variadic-test templates-variadic)
