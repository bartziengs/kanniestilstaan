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
include 19-templates-variadic/CMakeFiles/templates-variadic.dir/depend.make

# Include the progress variables for this target.
include 19-templates-variadic/CMakeFiles/templates-variadic.dir/progress.make

# Include the compile flags for this target's objects.
include 19-templates-variadic/CMakeFiles/templates-variadic.dir/flags.make

19-templates-variadic/CMakeFiles/templates-variadic.dir/src/templates-variadic.cxx.o: 19-templates-variadic/CMakeFiles/templates-variadic.dir/flags.make
19-templates-variadic/CMakeFiles/templates-variadic.dir/src/templates-variadic.cxx.o: ../19-templates-variadic/src/templates-variadic.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bart/Documents/OOP_C++/tw3720tu.2017/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object 19-templates-variadic/CMakeFiles/templates-variadic.dir/src/templates-variadic.cxx.o"
	cd /home/bart/Documents/OOP_C++/tw3720tu.2017/build/19-templates-variadic && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/templates-variadic.dir/src/templates-variadic.cxx.o -c /home/bart/Documents/OOP_C++/tw3720tu.2017/19-templates-variadic/src/templates-variadic.cxx

19-templates-variadic/CMakeFiles/templates-variadic.dir/src/templates-variadic.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/templates-variadic.dir/src/templates-variadic.cxx.i"
	cd /home/bart/Documents/OOP_C++/tw3720tu.2017/build/19-templates-variadic && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bart/Documents/OOP_C++/tw3720tu.2017/19-templates-variadic/src/templates-variadic.cxx > CMakeFiles/templates-variadic.dir/src/templates-variadic.cxx.i

19-templates-variadic/CMakeFiles/templates-variadic.dir/src/templates-variadic.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/templates-variadic.dir/src/templates-variadic.cxx.s"
	cd /home/bart/Documents/OOP_C++/tw3720tu.2017/build/19-templates-variadic && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bart/Documents/OOP_C++/tw3720tu.2017/19-templates-variadic/src/templates-variadic.cxx -o CMakeFiles/templates-variadic.dir/src/templates-variadic.cxx.s

19-templates-variadic/CMakeFiles/templates-variadic.dir/src/templates-variadic.cxx.o.requires:

.PHONY : 19-templates-variadic/CMakeFiles/templates-variadic.dir/src/templates-variadic.cxx.o.requires

19-templates-variadic/CMakeFiles/templates-variadic.dir/src/templates-variadic.cxx.o.provides: 19-templates-variadic/CMakeFiles/templates-variadic.dir/src/templates-variadic.cxx.o.requires
	$(MAKE) -f 19-templates-variadic/CMakeFiles/templates-variadic.dir/build.make 19-templates-variadic/CMakeFiles/templates-variadic.dir/src/templates-variadic.cxx.o.provides.build
.PHONY : 19-templates-variadic/CMakeFiles/templates-variadic.dir/src/templates-variadic.cxx.o.provides

19-templates-variadic/CMakeFiles/templates-variadic.dir/src/templates-variadic.cxx.o.provides.build: 19-templates-variadic/CMakeFiles/templates-variadic.dir/src/templates-variadic.cxx.o


# Object files for target templates-variadic
templates__variadic_OBJECTS = \
"CMakeFiles/templates-variadic.dir/src/templates-variadic.cxx.o"

# External object files for target templates-variadic
templates__variadic_EXTERNAL_OBJECTS =

19-templates-variadic/templates-variadic: 19-templates-variadic/CMakeFiles/templates-variadic.dir/src/templates-variadic.cxx.o
19-templates-variadic/templates-variadic: 19-templates-variadic/CMakeFiles/templates-variadic.dir/build.make
19-templates-variadic/templates-variadic: 19-templates-variadic/CMakeFiles/templates-variadic.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bart/Documents/OOP_C++/tw3720tu.2017/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable templates-variadic"
	cd /home/bart/Documents/OOP_C++/tw3720tu.2017/build/19-templates-variadic && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/templates-variadic.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
19-templates-variadic/CMakeFiles/templates-variadic.dir/build: 19-templates-variadic/templates-variadic

.PHONY : 19-templates-variadic/CMakeFiles/templates-variadic.dir/build

19-templates-variadic/CMakeFiles/templates-variadic.dir/requires: 19-templates-variadic/CMakeFiles/templates-variadic.dir/src/templates-variadic.cxx.o.requires

.PHONY : 19-templates-variadic/CMakeFiles/templates-variadic.dir/requires

19-templates-variadic/CMakeFiles/templates-variadic.dir/clean:
	cd /home/bart/Documents/OOP_C++/tw3720tu.2017/build/19-templates-variadic && $(CMAKE_COMMAND) -P CMakeFiles/templates-variadic.dir/cmake_clean.cmake
.PHONY : 19-templates-variadic/CMakeFiles/templates-variadic.dir/clean

19-templates-variadic/CMakeFiles/templates-variadic.dir/depend:
	cd /home/bart/Documents/OOP_C++/tw3720tu.2017/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bart/Documents/OOP_C++/tw3720tu.2017 /home/bart/Documents/OOP_C++/tw3720tu.2017/19-templates-variadic /home/bart/Documents/OOP_C++/tw3720tu.2017/build /home/bart/Documents/OOP_C++/tw3720tu.2017/build/19-templates-variadic /home/bart/Documents/OOP_C++/tw3720tu.2017/build/19-templates-variadic/CMakeFiles/templates-variadic.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : 19-templates-variadic/CMakeFiles/templates-variadic.dir/depend

