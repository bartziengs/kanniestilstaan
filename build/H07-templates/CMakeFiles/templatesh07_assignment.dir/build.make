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

# Utility rule file for templatesh07_assignment.

# Include the progress variables for this target.
include H07-templates/CMakeFiles/templatesh07_assignment.dir/progress.make

H07-templates/CMakeFiles/templatesh07_assignment: H07-templates/templatesh07
	cd /home/bart/Documents/OOP_C++/tw3720tu.2017/build/H07-templates && /usr/bin/cmake -E copy /home/bart/Documents/OOP_C++/tw3720tu.2017/H07-templates/src/templates.cxx templatesh07.log
	cd /home/bart/Documents/OOP_C++/tw3720tu.2017/build/H07-templates && /usr/bin/cmake -E echo "=== Start Environment " >> templatesh07.log
	cd /home/bart/Documents/OOP_C++/tw3720tu.2017/build/H07-templates && /usr/bin/cmake -E echo "PROJECT_NAME = H07-templates" >> templatesh07.log
	cd /home/bart/Documents/OOP_C++/tw3720tu.2017/build/H07-templates && /usr/bin/cmake -E echo "CMAKE_SYSTEM = Linux-4.10.0-37-generic" >> templatesh07.log
	cd /home/bart/Documents/OOP_C++/tw3720tu.2017/build/H07-templates && /usr/bin/cmake -E echo "CMAKE_VERSION = 3.5.1" >> templatesh07.log
	cd /home/bart/Documents/OOP_C++/tw3720tu.2017/build/H07-templates && /usr/bin/cmake -E echo "CMAKE_CXX_COMPILER_ID = GNU" >> templatesh07.log
	cd /home/bart/Documents/OOP_C++/tw3720tu.2017/build/H07-templates && /usr/bin/cmake -E echo "CMAKE_CXX_COMPILER_VERSION = 5.4.0" >> templatesh07.log
	cd /home/bart/Documents/OOP_C++/tw3720tu.2017/build/H07-templates && /usr/bin/cmake -E echo "=== End Environment " >> templatesh07.log
	cd /home/bart/Documents/OOP_C++/tw3720tu.2017/build/H07-templates && /usr/bin/cmake -E echo "=== Start of output from execution of binary templatesh07" >> templatesh07.log
	cd /home/bart/Documents/OOP_C++/tw3720tu.2017/build/H07-templates && ./templatesh07 >> templatesh07.log
	cd /home/bart/Documents/OOP_C++/tw3720tu.2017/build/H07-templates && /usr/bin/cmake -E echo "=== End of output from execution of binary templatesh07" >> templatesh07.log

templatesh07_assignment: H07-templates/CMakeFiles/templatesh07_assignment
templatesh07_assignment: H07-templates/CMakeFiles/templatesh07_assignment.dir/build.make

.PHONY : templatesh07_assignment

# Rule to build all files generated by this target.
H07-templates/CMakeFiles/templatesh07_assignment.dir/build: templatesh07_assignment

.PHONY : H07-templates/CMakeFiles/templatesh07_assignment.dir/build

H07-templates/CMakeFiles/templatesh07_assignment.dir/clean:
	cd /home/bart/Documents/OOP_C++/tw3720tu.2017/build/H07-templates && $(CMAKE_COMMAND) -P CMakeFiles/templatesh07_assignment.dir/cmake_clean.cmake
.PHONY : H07-templates/CMakeFiles/templatesh07_assignment.dir/clean

H07-templates/CMakeFiles/templatesh07_assignment.dir/depend:
	cd /home/bart/Documents/OOP_C++/tw3720tu.2017/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bart/Documents/OOP_C++/tw3720tu.2017 /home/bart/Documents/OOP_C++/tw3720tu.2017/H07-templates /home/bart/Documents/OOP_C++/tw3720tu.2017/build /home/bart/Documents/OOP_C++/tw3720tu.2017/build/H07-templates /home/bart/Documents/OOP_C++/tw3720tu.2017/build/H07-templates/CMakeFiles/templatesh07_assignment.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : H07-templates/CMakeFiles/templatesh07_assignment.dir/depend

