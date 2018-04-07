# Force CMake version 3.1 or above
cmake_minimum_required (VERSION 3.1)

# This project has the name: 08-dot-product-struct2
project (08-dot-product-struct2)

# Create an executable named 'dot-product-struct2' from the source file 'dot-product-struct2.cxx'
add_executable(dot-product-struct2 src/dot-product-struct2.cxx)

# Define C++11 standard
set_property(TARGET dot-product-struct2 PROPERTY CXX_STANDARD 11)

# Add test called "dot-product-struct2-test" based on the executable "dot-product-struct2"
add_test (dot-product-struct2-test dot-product-struct2)