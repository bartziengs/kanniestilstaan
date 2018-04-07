# Force CMake version 3.1 or above
cmake_minimum_required (VERSION 3.1)

# This project has the name: 11-polymorphism
project (11-polymorphism)

# Create an executable named 'polymorphism' from the source file 'polymorphism.cxx'
add_executable(polymorphism src/polymorphism.cxx)

# Define C++11 standard
set_property(TARGET polymorphism PROPERTY CXX_STANDARD 11)

# Add test called "polymorphism-test" based on the executable "polymorphism"
add_test (polymorphism-test polymorphism)
