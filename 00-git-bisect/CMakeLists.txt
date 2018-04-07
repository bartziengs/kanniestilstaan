# Force CMake version 3.1 or above
cmake_minimum_required (VERSION 3.1)

# This project has the name: 00-git-bisect
project (00-git-bisect)

# Create an executable named 'git-bisect' from the source file 'git-bisect.cxx'
add_executable(git-bisect src/git-bisect.cxx)

# Add test called "git-bisect-test" based on the executable "git-bisect"
add_test (git-bisect-test git-bisect)
