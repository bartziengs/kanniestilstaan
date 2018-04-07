# Force CMake version 3.1 or above
cmake_minimum_required (VERSION 3.1)

# This project has the name: 23-linalg
project (23-linalg)

# Create an executable named 'linalg' from the source file 'linalg.cxx'
include_directories(src)
add_executable(linalg src/linalg.cxx src/LALib.h src/LAETLib.h)

# Define C++14 standard
set_property(TARGET linalg PROPERTY CXX_STANDARD 14)

# Add test called "linalg-test" based on the executable "linalg"
add_test (linalg-test linalg)
