# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/bart/Documents/OOP_C++/tw3720tu.2017

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/bart/Documents/OOP_C++/tw3720tu.2017/build

# Include any dependencies generated for this target.
include 06-dot-product/CMakeFiles/dot-product.dir/depend.make

# Include the progress variables for this target.
include 06-dot-product/CMakeFiles/dot-product.dir/progress.make

# Include the compile flags for this target's objects.
include 06-dot-product/CMakeFiles/dot-product.dir/flags.make

06-dot-product/CMakeFiles/dot-product.dir/src/dot-product.cxx.o: 06-dot-product/CMakeFiles/dot-product.dir/flags.make
06-dot-product/CMakeFiles/dot-product.dir/src/dot-product.cxx.o: ../06-dot-product/src/dot-product.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bart/Documents/OOP_C++/tw3720tu.2017/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object 06-dot-product/CMakeFiles/dot-product.dir/src/dot-product.cxx.o"
	cd /home/bart/Documents/OOP_C++/tw3720tu.2017/build/06-dot-product && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/dot-product.dir/src/dot-product.cxx.o -c /home/bart/Documents/OOP_C++/tw3720tu.2017/06-dot-product/src/dot-product.cxx

06-dot-product/CMakeFiles/dot-product.dir/src/dot-product.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/dot-product.dir/src/dot-product.cxx.i"
	cd /home/bart/Documents/OOP_C++/tw3720tu.2017/build/06-dot-product && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bart/Documents/OOP_C++/tw3720tu.2017/06-dot-product/src/dot-product.cxx > CMakeFiles/dot-product.dir/src/dot-product.cxx.i

06-dot-product/CMakeFiles/dot-product.dir/src/dot-product.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/dot-product.dir/src/dot-product.cxx.s"
	cd /home/bart/Documents/OOP_C++/tw3720tu.2017/build/06-dot-product && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bart/Documents/OOP_C++/tw3720tu.2017/06-dot-product/src/dot-product.cxx -o CMakeFiles/dot-product.dir/src/dot-product.cxx.s

06-dot-product/CMakeFiles/dot-product.dir/src/dot-product.cxx.o.requires:

.PHONY : 06-dot-product/CMakeFiles/dot-product.dir/src/dot-product.cxx.o.requires

06-dot-product/CMakeFiles/dot-product.dir/src/dot-product.cxx.o.provides: 06-dot-product/CMakeFiles/dot-product.dir/src/dot-product.cxx.o.requires
	$(MAKE) -f 06-dot-product/CMakeFiles/dot-product.dir/build.make 06-dot-product/CMakeFiles/dot-product.dir/src/dot-product.cxx.o.provides.build
.PHONY : 06-dot-product/CMakeFiles/dot-product.dir/src/dot-product.cxx.o.provides

06-dot-product/CMakeFiles/dot-product.dir/src/dot-product.cxx.o.provides.build: 06-dot-product/CMakeFiles/dot-product.dir/src/dot-product.cxx.o


# Object files for target dot-product
dot__product_OBJECTS = \
"CMakeFiles/dot-product.dir/src/dot-product.cxx.o"

# External object files for target dot-product
dot__product_EXTERNAL_OBJECTS =

06-dot-product/dot-product: 06-dot-product/CMakeFiles/dot-product.dir/src/dot-product.cxx.o
06-dot-product/dot-product: 06-dot-product/CMakeFiles/dot-product.dir/build.make
06-dot-product/dot-product: 06-dot-product/CMakeFiles/dot-product.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bart/Documents/OOP_C++/tw3720tu.2017/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable dot-product"
	cd /home/bart/Documents/OOP_C++/tw3720tu.2017/build/06-dot-product && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/dot-product.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
06-dot-product/CMakeFiles/dot-product.dir/build: 06-dot-product/dot-product

.PHONY : 06-dot-product/CMakeFiles/dot-product.dir/build

06-dot-product/CMakeFiles/dot-product.dir/requires: 06-dot-product/CMakeFiles/dot-product.dir/src/dot-product.cxx.o.requires

.PHONY : 06-dot-product/CMakeFiles/dot-product.dir/requires

06-dot-product/CMakeFiles/dot-product.dir/clean:
	cd /home/bart/Documents/OOP_C++/tw3720tu.2017/build/06-dot-product && $(CMAKE_COMMAND) -P CMakeFiles/dot-product.dir/cmake_clean.cmake
.PHONY : 06-dot-product/CMakeFiles/dot-product.dir/clean

06-dot-product/CMakeFiles/dot-product.dir/depend:
	cd /home/bart/Documents/OOP_C++/tw3720tu.2017/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bart/Documents/OOP_C++/tw3720tu.2017 /home/bart/Documents/OOP_C++/tw3720tu.2017/06-dot-product /home/bart/Documents/OOP_C++/tw3720tu.2017/build /home/bart/Documents/OOP_C++/tw3720tu.2017/build/06-dot-product /home/bart/Documents/OOP_C++/tw3720tu.2017/build/06-dot-product/CMakeFiles/dot-product.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : 06-dot-product/CMakeFiles/dot-product.dir/depend

