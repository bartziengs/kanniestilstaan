# Force CMake version 3.1 or above
cmake_minimum_required (VERSION 3.1)

# This project has the name: 01-hello
project (01-hello)

# Create an executable named 'hello' from the source file 'hello.cxx'
add_executable(hello src/hello.cxx)

# Define C++11 standard
set_property(TARGET hello PROPERTY CXX_STANDARD 11)

# Add test called "hello-test" based on the executable "hello"
add_test (hello-test hello)
