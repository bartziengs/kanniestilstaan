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

# Utility rule file for unit-converter_assignment.

# Include the progress variables for this target.
include H08-unit-converter/CMakeFiles/unit-converter_assignment.dir/progress.make

H08-unit-converter/CMakeFiles/unit-converter_assignment: H08-unit-converter/unit-converter
	cd /home/bart/Documents/OOP_C++/tw3720tu.2017/build/H08-unit-converter && /usr/bin/cmake -E copy /home/bart/Documents/OOP_C++/tw3720tu.2017/H08-unit-converter/src/unit-converter.cxx unit-converter.log
	cd /home/bart/Documents/OOP_C++/tw3720tu.2017/build/H08-unit-converter && /usr/bin/cmake -E echo "=== Start Environment " >> unit-converter.log
	cd /home/bart/Documents/OOP_C++/tw3720tu.2017/build/H08-unit-converter && /usr/bin/cmake -E echo "PROJECT_NAME = H08-unit-converter" >> unit-converter.log
	cd /home/bart/Documents/OOP_C++/tw3720tu.2017/build/H08-unit-converter && /usr/bin/cmake -E echo "CMAKE_SYSTEM = Linux-4.10.0-37-generic" >> unit-converter.log
	cd /home/bart/Documents/OOP_C++/tw3720tu.2017/build/H08-unit-converter && /usr/bin/cmake -E echo "CMAKE_VERSION = 3.5.1" >> unit-converter.log
	cd /home/bart/Documents/OOP_C++/tw3720tu.2017/build/H08-unit-converter && /usr/bin/cmake -E echo "CMAKE_CXX_COMPILER_ID = GNU" >> unit-converter.log
	cd /home/bart/Documents/OOP_C++/tw3720tu.2017/build/H08-unit-converter && /usr/bin/cmake -E echo "CMAKE_CXX_COMPILER_VERSION = 5.4.0" >> unit-converter.log
	cd /home/bart/Documents/OOP_C++/tw3720tu.2017/build/H08-unit-converter && /usr/bin/cmake -E echo "=== End Environment " >> unit-converter.log
	cd /home/bart/Documents/OOP_C++/tw3720tu.2017/build/H08-unit-converter && /usr/bin/cmake -E echo "=== Start of output from execution of binary unit-converter" >> unit-converter.log
	cd /home/bart/Documents/OOP_C++/tw3720tu.2017/build/H08-unit-converter && ./unit-converter >> unit-converter.log
	cd /home/bart/Documents/OOP_C++/tw3720tu.2017/build/H08-unit-converter && /usr/bin/cmake -E echo "=== End of output from execution of binary unit-converter" >> unit-converter.log

unit-converter_assignment: H08-unit-converter/CMakeFiles/unit-converter_assignment
unit-converter_assignment: H08-unit-converter/CMakeFiles/unit-converter_assignment.dir/build.make

.PHONY : unit-converter_assignment

# Rule to build all files generated by this target.
H08-unit-converter/CMakeFiles/unit-converter_assignment.dir/build: unit-converter_assignment

.PHONY : H08-unit-converter/CMakeFiles/unit-converter_assignment.dir/build

H08-unit-converter/CMakeFiles/unit-converter_assignment.dir/clean:
	cd /home/bart/Documents/OOP_C++/tw3720tu.2017/build/H08-unit-converter && $(CMAKE_COMMAND) -P CMakeFiles/unit-converter_assignment.dir/cmake_clean.cmake
.PHONY : H08-unit-converter/CMakeFiles/unit-converter_assignment.dir/clean

H08-unit-converter/CMakeFiles/unit-converter_assignment.dir/depend:
	cd /home/bart/Documents/OOP_C++/tw3720tu.2017/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bart/Documents/OOP_C++/tw3720tu.2017 /home/bart/Documents/OOP_C++/tw3720tu.2017/H08-unit-converter /home/bart/Documents/OOP_C++/tw3720tu.2017/build /home/bart/Documents/OOP_C++/tw3720tu.2017/build/H08-unit-converter /home/bart/Documents/OOP_C++/tw3720tu.2017/build/H08-unit-converter/CMakeFiles/unit-converter_assignment.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : H08-unit-converter/CMakeFiles/unit-converter_assignment.dir/depend

