# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = "C:/Program Files/CMake/bin/cmake.exe"

# The command to remove a file.
RM = "C:/Program Files/CMake/bin/cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:/Users/andri/Documents/GitHub/CMake-engine

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:/Users/andri/Documents/GitHub/CMake-engine/build

# Utility rule file for uninstall.

# Include any custom commands dependencies for this target.
include lib/enschin/lib/glfw/CMakeFiles/uninstall.dir/compiler_depend.make

# Include the progress variables for this target.
include lib/enschin/lib/glfw/CMakeFiles/uninstall.dir/progress.make

lib/enschin/lib/glfw/CMakeFiles/uninstall:
	cd C:/Users/andri/Documents/GitHub/CMake-engine/build/lib/enschin/lib/glfw && "C:/Program Files/CMake/bin/cmake.exe" -P C:/Users/andri/Documents/GitHub/CMake-engine/build/lib/enschin/lib/glfw/cmake_uninstall.cmake

uninstall: lib/enschin/lib/glfw/CMakeFiles/uninstall
uninstall: lib/enschin/lib/glfw/CMakeFiles/uninstall.dir/build.make
.PHONY : uninstall

# Rule to build all files generated by this target.
lib/enschin/lib/glfw/CMakeFiles/uninstall.dir/build: uninstall
.PHONY : lib/enschin/lib/glfw/CMakeFiles/uninstall.dir/build

lib/enschin/lib/glfw/CMakeFiles/uninstall.dir/clean:
	cd C:/Users/andri/Documents/GitHub/CMake-engine/build/lib/enschin/lib/glfw && $(CMAKE_COMMAND) -P CMakeFiles/uninstall.dir/cmake_clean.cmake
.PHONY : lib/enschin/lib/glfw/CMakeFiles/uninstall.dir/clean

lib/enschin/lib/glfw/CMakeFiles/uninstall.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" C:/Users/andri/Documents/GitHub/CMake-engine C:/Users/andri/Documents/GitHub/CMake-engine/lib/enschin/lib/glfw C:/Users/andri/Documents/GitHub/CMake-engine/build C:/Users/andri/Documents/GitHub/CMake-engine/build/lib/enschin/lib/glfw C:/Users/andri/Documents/GitHub/CMake-engine/build/lib/enschin/lib/glfw/CMakeFiles/uninstall.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : lib/enschin/lib/glfw/CMakeFiles/uninstall.dir/depend
