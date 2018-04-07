# Force CMake version 3.1 or above
cmake_minimum_required (VERSION 3.1)

# This project has the name: 22-stack-queue
project (22-stack-queue)

# Create an executable named 'stack-queue' from the source file 'stack-queue.cxx'
add_executable(stack-queue src/stack-queue.cxx)

# Define C++11 standard
set_property(TARGET stack-queue PROPERTY CXX_STANDARD 11)

# Add test called "stack-queue-test" based on the executable "stack-queue"
add_test (stack-queue-test stack-queue)
