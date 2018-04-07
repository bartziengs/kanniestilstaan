# ...

# Create an additional target for assignment submission
#add_assignment(... src/...)

# Force CMake version 3.1 or above
cmake_minimum_required (VERSION 3.1)

# This project has the name: H04-points-triangles
project (H06-derivatives)

# Create an executable named 'points-triangles' from the source file 'points-triangles.cxx'
add_executable(derivatives src/derivatives.cxx)

# Define C++11 standard
set_property(TARGET derivatives PROPERTY CXX_STANDARD 11)

# Add test called "derivatives-test" based on the executable "derivatives"
add_test (derivatives-test derivatives)

# Create an additional target for assignment submission
add_assignment(derivatives src/derivatives.cxx)
