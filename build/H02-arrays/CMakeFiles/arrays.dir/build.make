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
include H02-arrays/CMakeFiles/arrays.dir/depend.make

# Include the progress variables for this target.
include H02-arrays/CMakeFiles/arrays.dir/progress.make

# Include the compile flags for this target's objects.
include H02-arrays/CMakeFiles/arrays.dir/flags.make

H02-arrays/CMakeFiles/arrays.dir/src/arrays.cxx.o: H02-arrays/CMakeFiles/arrays.dir/flags.make
H02-arrays/CMakeFiles/arrays.dir/src/arrays.cxx.o: ../H02-arrays/src/arrays.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bart/Documents/OOP_C++/tw3720tu.2017/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object H02-arrays/CMakeFiles/arrays.dir/src/arrays.cxx.o"
	cd /home/bart/Documents/OOP_C++/tw3720tu.2017/build/H02-arrays && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/arrays.dir/src/arrays.cxx.o -c /home/bart/Documents/OOP_C++/tw3720tu.2017/H02-arrays/src/arrays.cxx

H02-arrays/CMakeFiles/arrays.dir/src/arrays.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/arrays.dir/src/arrays.cxx.i"
	cd /home/bart/Documents/OOP_C++/tw3720tu.2017/build/H02-arrays && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bart/Documents/OOP_C++/tw3720tu.2017/H02-arrays/src/arrays.cxx > CMakeFiles/arrays.dir/src/arrays.cxx.i

H02-arrays/CMakeFiles/arrays.dir/src/arrays.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/arrays.dir/src/arrays.cxx.s"
	cd /home/bart/Documents/OOP_C++/tw3720tu.2017/build/H02-arrays && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bart/Documents/OOP_C++/tw3720tu.2017/H02-arrays/src/arrays.cxx -o CMakeFiles/arrays.dir/src/arrays.cxx.s

H02-arrays/CMakeFiles/arrays.dir/src/arrays.cxx.o.requires:

.PHONY : H02-arrays/CMakeFiles/arrays.dir/src/arrays.cxx.o.requires

H02-arrays/CMakeFiles/arrays.dir/src/arrays.cxx.o.provides: H02-arrays/CMakeFiles/arrays.dir/src/arrays.cxx.o.requires
	$(MAKE) -f H02-arrays/CMakeFiles/arrays.dir/build.make H02-arrays/CMakeFiles/arrays.dir/src/arrays.cxx.o.provides.build
.PHONY : H02-arrays/CMakeFiles/arrays.dir/src/arrays.cxx.o.provides

H02-arrays/CMakeFiles/arrays.dir/src/arrays.cxx.o.provides.build: H02-arrays/CMakeFiles/arrays.dir/src/arrays.cxx.o


# Object files for target arrays
arrays_OBJECTS = \
"CMakeFiles/arrays.dir/src/arrays.cxx.o"

# External object files for target arrays
arrays_EXTERNAL_OBJECTS =

H02-arrays/arrays: H02-arrays/CMakeFiles/arrays.dir/src/arrays.cxx.o
H02-arrays/arrays: H02-arrays/CMakeFiles/arrays.dir/build.make
H02-arrays/arrays: H02-arrays/CMakeFiles/arrays.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bart/Documents/OOP_C++/tw3720tu.2017/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable arrays"
	cd /home/bart/Documents/OOP_C++/tw3720tu.2017/build/H02-arrays && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/arrays.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
H02-arrays/CMakeFiles/arrays.dir/build: H02-arrays/arrays

.PHONY : H02-arrays/CMakeFiles/arrays.dir/build

H02-arrays/CMakeFiles/arrays.dir/requires: H02-arrays/CMakeFiles/arrays.dir/src/arrays.cxx.o.requires

.PHONY : H02-arrays/CMakeFiles/arrays.dir/requires

H02-arrays/CMakeFiles/arrays.dir/clean:
	cd /home/bart/Documents/OOP_C++/tw3720tu.2017/build/H02-arrays && $(CMAKE_COMMAND) -P CMakeFiles/arrays.dir/cmake_clean.cmake
.PHONY : H02-arrays/CMakeFiles/arrays.dir/clean

H02-arrays/CMakeFiles/arrays.dir/depend:
	cd /home/bart/Documents/OOP_C++/tw3720tu.2017/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bart/Documents/OOP_C++/tw3720tu.2017 /home/bart/Documents/OOP_C++/tw3720tu.2017/H02-arrays /home/bart/Documents/OOP_C++/tw3720tu.2017/build /home/bart/Documents/OOP_C++/tw3720tu.2017/build/H02-arrays /home/bart/Documents/OOP_C++/tw3720tu.2017/build/H02-arrays/CMakeFiles/arrays.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : H02-arrays/CMakeFiles/arrays.dir/depend

