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
include H08-unit-converter/CMakeFiles/unit-converter.dir/depend.make

# Include the progress variables for this target.
include H08-unit-converter/CMakeFiles/unit-converter.dir/progress.make

# Include the compile flags for this target's objects.
include H08-unit-converter/CMakeFiles/unit-converter.dir/flags.make

H08-unit-converter/CMakeFiles/unit-converter.dir/src/unit-converter.cxx.o: H08-unit-converter/CMakeFiles/unit-converter.dir/flags.make
H08-unit-converter/CMakeFiles/unit-converter.dir/src/unit-converter.cxx.o: ../H08-unit-converter/src/unit-converter.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bart/Documents/OOP_C++/tw3720tu.2017/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object H08-unit-converter/CMakeFiles/unit-converter.dir/src/unit-converter.cxx.o"
	cd /home/bart/Documents/OOP_C++/tw3720tu.2017/build/H08-unit-converter && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/unit-converter.dir/src/unit-converter.cxx.o -c /home/bart/Documents/OOP_C++/tw3720tu.2017/H08-unit-converter/src/unit-converter.cxx

H08-unit-converter/CMakeFiles/unit-converter.dir/src/unit-converter.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/unit-converter.dir/src/unit-converter.cxx.i"
	cd /home/bart/Documents/OOP_C++/tw3720tu.2017/build/H08-unit-converter && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bart/Documents/OOP_C++/tw3720tu.2017/H08-unit-converter/src/unit-converter.cxx > CMakeFiles/unit-converter.dir/src/unit-converter.cxx.i

H08-unit-converter/CMakeFiles/unit-converter.dir/src/unit-converter.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/unit-converter.dir/src/unit-converter.cxx.s"
	cd /home/bart/Documents/OOP_C++/tw3720tu.2017/build/H08-unit-converter && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bart/Documents/OOP_C++/tw3720tu.2017/H08-unit-converter/src/unit-converter.cxx -o CMakeFiles/unit-converter.dir/src/unit-converter.cxx.s

H08-unit-converter/CMakeFiles/unit-converter.dir/src/unit-converter.cxx.o.requires:

.PHONY : H08-unit-converter/CMakeFiles/unit-converter.dir/src/unit-converter.cxx.o.requires

H08-unit-converter/CMakeFiles/unit-converter.dir/src/unit-converter.cxx.o.provides: H08-unit-converter/CMakeFiles/unit-converter.dir/src/unit-converter.cxx.o.requires
	$(MAKE) -f H08-unit-converter/CMakeFiles/unit-converter.dir/build.make H08-unit-converter/CMakeFiles/unit-converter.dir/src/unit-converter.cxx.o.provides.build
.PHONY : H08-unit-converter/CMakeFiles/unit-converter.dir/src/unit-converter.cxx.o.provides

H08-unit-converter/CMakeFiles/unit-converter.dir/src/unit-converter.cxx.o.provides.build: H08-unit-converter/CMakeFiles/unit-converter.dir/src/unit-converter.cxx.o


# Object files for target unit-converter
unit__converter_OBJECTS = \
"CMakeFiles/unit-converter.dir/src/unit-converter.cxx.o"

# External object files for target unit-converter
unit__converter_EXTERNAL_OBJECTS =

H08-unit-converter/unit-converter: H08-unit-converter/CMakeFiles/unit-converter.dir/src/unit-converter.cxx.o
H08-unit-converter/unit-converter: H08-unit-converter/CMakeFiles/unit-converter.dir/build.make
H08-unit-converter/unit-converter: H08-unit-converter/CMakeFiles/unit-converter.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bart/Documents/OOP_C++/tw3720tu.2017/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable unit-converter"
	cd /home/bart/Documents/OOP_C++/tw3720tu.2017/build/H08-unit-converter && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/unit-converter.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
H08-unit-converter/CMakeFiles/unit-converter.dir/build: H08-unit-converter/unit-converter

.PHONY : H08-unit-converter/CMakeFiles/unit-converter.dir/build

H08-unit-converter/CMakeFiles/unit-converter.dir/requires: H08-unit-converter/CMakeFiles/unit-converter.dir/src/unit-converter.cxx.o.requires

.PHONY : H08-unit-converter/CMakeFiles/unit-converter.dir/requires

H08-unit-converter/CMakeFiles/unit-converter.dir/clean:
	cd /home/bart/Documents/OOP_C++/tw3720tu.2017/build/H08-unit-converter && $(CMAKE_COMMAND) -P CMakeFiles/unit-converter.dir/cmake_clean.cmake
.PHONY : H08-unit-converter/CMakeFiles/unit-converter.dir/clean

H08-unit-converter/CMakeFiles/unit-converter.dir/depend:
	cd /home/bart/Documents/OOP_C++/tw3720tu.2017/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bart/Documents/OOP_C++/tw3720tu.2017 /home/bart/Documents/OOP_C++/tw3720tu.2017/H08-unit-converter /home/bart/Documents/OOP_C++/tw3720tu.2017/build /home/bart/Documents/OOP_C++/tw3720tu.2017/build/H08-unit-converter /home/bart/Documents/OOP_C++/tw3720tu.2017/build/H08-unit-converter/CMakeFiles/unit-converter.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : H08-unit-converter/CMakeFiles/unit-converter.dir/depend

