# Force CMake version 3.1 or above
cmake_minimum_required (VERSION 3.1)

# This project has the name: 13-templates
project (13-templates)

# Create an executable named 'templates' from the source file 'templates.cxx'
add_executable(templates src/templates.cxx)

# Define C++14 standard
set_property(TARGET templates PROPERTY CXX_STANDARD 14)

# Add test called "templates-test" based on the executable "templates"
add_test (templates-test templates)
