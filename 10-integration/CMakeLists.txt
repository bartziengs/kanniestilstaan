# Force CMake version 3.1 or above
cmake_minimum_required (VERSION 3.1)

# This project has the name: 10-integration
project (10-integration)

# Create an executable named 'integration' from the source file 'integration.cxx'
add_executable(integration src/integration.cxx)

# Define C++11 standard
set_property(TARGET integration PROPERTY CXX_STANDARD 11)

# Add test called "integration-test" based on the executable "integration"
add_test (integration-test integration)
