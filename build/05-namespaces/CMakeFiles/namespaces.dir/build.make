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
include 05-namespaces/CMakeFiles/namespaces.dir/depend.make

# Include the progress variables for this target.
include 05-namespaces/CMakeFiles/namespaces.dir/progress.make

# Include the compile flags for this target's objects.
include 05-namespaces/CMakeFiles/namespaces.dir/flags.make

05-namespaces/CMakeFiles/namespaces.dir/src/namespaces.cxx.o: 05-namespaces/CMakeFiles/namespaces.dir/flags.make
05-namespaces/CMakeFiles/namespaces.dir/src/namespaces.cxx.o: ../05-namespaces/src/namespaces.cxx
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/bart/Documents/OOP_C++/tw3720tu.2017/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object 05-namespaces/CMakeFiles/namespaces.dir/src/namespaces.cxx.o"
	cd /home/bart/Documents/OOP_C++/tw3720tu.2017/build/05-namespaces && /usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/namespaces.dir/src/namespaces.cxx.o -c /home/bart/Documents/OOP_C++/tw3720tu.2017/05-namespaces/src/namespaces.cxx

05-namespaces/CMakeFiles/namespaces.dir/src/namespaces.cxx.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/namespaces.dir/src/namespaces.cxx.i"
	cd /home/bart/Documents/OOP_C++/tw3720tu.2017/build/05-namespaces && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/bart/Documents/OOP_C++/tw3720tu.2017/05-namespaces/src/namespaces.cxx > CMakeFiles/namespaces.dir/src/namespaces.cxx.i

05-namespaces/CMakeFiles/namespaces.dir/src/namespaces.cxx.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/namespaces.dir/src/namespaces.cxx.s"
	cd /home/bart/Documents/OOP_C++/tw3720tu.2017/build/05-namespaces && /usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/bart/Documents/OOP_C++/tw3720tu.2017/05-namespaces/src/namespaces.cxx -o CMakeFiles/namespaces.dir/src/namespaces.cxx.s

05-namespaces/CMakeFiles/namespaces.dir/src/namespaces.cxx.o.requires:

.PHONY : 05-namespaces/CMakeFiles/namespaces.dir/src/namespaces.cxx.o.requires

05-namespaces/CMakeFiles/namespaces.dir/src/namespaces.cxx.o.provides: 05-namespaces/CMakeFiles/namespaces.dir/src/namespaces.cxx.o.requires
	$(MAKE) -f 05-namespaces/CMakeFiles/namespaces.dir/build.make 05-namespaces/CMakeFiles/namespaces.dir/src/namespaces.cxx.o.provides.build
.PHONY : 05-namespaces/CMakeFiles/namespaces.dir/src/namespaces.cxx.o.provides

05-namespaces/CMakeFiles/namespaces.dir/src/namespaces.cxx.o.provides.build: 05-namespaces/CMakeFiles/namespaces.dir/src/namespaces.cxx.o


# Object files for target namespaces
namespaces_OBJECTS = \
"CMakeFiles/namespaces.dir/src/namespaces.cxx.o"

# External object files for target namespaces
namespaces_EXTERNAL_OBJECTS =

05-namespaces/namespaces: 05-namespaces/CMakeFiles/namespaces.dir/src/namespaces.cxx.o
05-namespaces/namespaces: 05-namespaces/CMakeFiles/namespaces.dir/build.make
05-namespaces/namespaces: 05-namespaces/CMakeFiles/namespaces.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/bart/Documents/OOP_C++/tw3720tu.2017/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable namespaces"
	cd /home/bart/Documents/OOP_C++/tw3720tu.2017/build/05-namespaces && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/namespaces.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
05-namespaces/CMakeFiles/namespaces.dir/build: 05-namespaces/namespaces

.PHONY : 05-namespaces/CMakeFiles/namespaces.dir/build

05-namespaces/CMakeFiles/namespaces.dir/requires: 05-namespaces/CMakeFiles/namespaces.dir/src/namespaces.cxx.o.requires

.PHONY : 05-namespaces/CMakeFiles/namespaces.dir/requires

05-namespaces/CMakeFiles/namespaces.dir/clean:
	cd /home/bart/Documents/OOP_C++/tw3720tu.2017/build/05-namespaces && $(CMAKE_COMMAND) -P CMakeFiles/namespaces.dir/cmake_clean.cmake
.PHONY : 05-namespaces/CMakeFiles/namespaces.dir/clean

05-namespaces/CMakeFiles/namespaces.dir/depend:
	cd /home/bart/Documents/OOP_C++/tw3720tu.2017/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/bart/Documents/OOP_C++/tw3720tu.2017 /home/bart/Documents/OOP_C++/tw3720tu.2017/05-namespaces /home/bart/Documents/OOP_C++/tw3720tu.2017/build /home/bart/Documents/OOP_C++/tw3720tu.2017/build/05-namespaces /home/bart/Documents/OOP_C++/tw3720tu.2017/build/05-namespaces/CMakeFiles/namespaces.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : 05-namespaces/CMakeFiles/namespaces.dir/depend

