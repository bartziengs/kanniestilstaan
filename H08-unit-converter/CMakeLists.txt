# ...

# Create an additional target for assignment submission
#add_assignment(... src/...)

# Force CMake version 3.1 or above
cmake_minimum_required (VERSION 3.1)

# This project has the name: H07-templates
project (H08-unit-converter)

# Create an executable named 'points-triangles' from the source file 'templates.cxx'
add_executable(unit-converter src/unit-converter)

# Define C++11 standard
set_property(TARGET unit-converter PROPERTY CXX_STANDARD 14)

# Add test called "templates-test" based on the executable "templates"
add_test (unit-converter-test unit-converter)

# Create an additional target for assignment submission
add_assignment(unit-converter src/unit-converter.cxx)
