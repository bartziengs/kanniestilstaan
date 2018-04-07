# Force CMake version 3.1 or above
cmake_minimum_required (VERSION 3.1)

# This project has the name: 14-templates-partial-specialisation
project (14-templates-partial-specialisation)

# Create an executable named 'templates-partial-specialisation' from the source file 'templates-partial-specialisation.cxx'
add_executable(templates-partial-specialisation src/templates-partial-specialisation.cxx)

# Define C++14 standard
set_property(TARGET templates-partial-specialisation PROPERTY CXX_STANDARD 14)

# Add test called "templates-partial-specialisation-test" based on the executable "templates-partial-specialisation"
add_test (templates-partial-specialisation-test templates-partial-specialisation)
