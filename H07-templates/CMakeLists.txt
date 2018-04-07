# ...

# Create an additional target for assignment submission
#add_assignment(... src/...)

# Force CMake version 3.1 or above
cmake_minimum_required (VERSION 3.1)

# This project has the name: H07-templates
project (H07-templates)

# Create an executable named 'points-triangles' from the source file 'templates.cxx'
add_executable(templatesh07 src/templates.cxx)

# Define C++11 standard
set_property(TARGET templatesh07 PROPERTY CXX_STANDARD 14)

# Add test called "templates-test" based on the executable "templates"
add_test (templates-test templatesh07)

# Create an additional target for assignment submission
add_assignment(templatesh07 src/templates.cxx)
