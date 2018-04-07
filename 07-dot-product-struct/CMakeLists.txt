# Force CMake version 3.1 or above
cmake_minimum_required (VERSION 3.1)

# This project has the name: 07-dot-product-struct
project (07-dot-product-struct)

# Create an executable named 'dot-product-struct' from the source file 'dot-product-struct.cxx'
add_executable(dot-product-struct src/dot-product-struct.cxx)

# Define C++11 standard
set_property(TARGET dot-product-struct PROPERTY CXX_STANDARD 11)

# Add test called "dot-product-struct-test" based on the executable "dot-product-struct"
add_test (dot-product-struct-test dot-product-struct)
