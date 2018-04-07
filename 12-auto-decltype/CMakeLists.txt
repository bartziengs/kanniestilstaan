# Force CMake version 3.1 or above
cmake_minimum_required (VERSION 3.1)

# This project has the name: 12-auto-decltype
project (12-auto-decltype)

# Create an executable named 'auto-decltype' from the source file 'auto-decltype.cxx'
add_executable(auto-decltype src/auto-decltype.cxx)

# Define C++14 standard
set_property(TARGET auto-decltype PROPERTY CXX_STANDARD 14)

# Add test called "auto-decltype-test" based on the executable "auto-decltype"
add_test (auto-decltype-test auto-decltype)
