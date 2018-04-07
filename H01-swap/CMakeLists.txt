# Force CMake version 3.1 or above
cmake_minimum_required (VERSION 3.1)

# This project has the name: H01-swap
project (H01-swap)

# Create an executable named 'swap' from the source file 'swap.cxx'
add_executable(swap src/swap.cxx)

# Define C++11 standard
set_property(TARGET swap PROPERTY CXX_STANDARD 11)

# Add test called "swap-test" based on the executable "swap"
add_test (swap-test swap)

# Create an additional target for assignment submission
add_assignment(swap src/swap.cxx)
