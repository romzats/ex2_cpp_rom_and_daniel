# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.8

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
CMAKE_COMMAND = /usr/local/jetbrains/clion-2017.2.2/bin/cmake/bin/cmake

# The command to remove a file.
RM = /usr/local/jetbrains/clion-2017.2.2/bin/cmake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /cs/usr/romzats/ex2_cpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /cs/usr/romzats/ex2_cpp/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ex2_cpp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ex2_cpp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ex2_cpp.dir/flags.make

CMakeFiles/ex2_cpp.dir/main.cpp.o: CMakeFiles/ex2_cpp.dir/flags.make
CMakeFiles/ex2_cpp.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/cs/usr/romzats/ex2_cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ex2_cpp.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ex2_cpp.dir/main.cpp.o -c /cs/usr/romzats/ex2_cpp/main.cpp

CMakeFiles/ex2_cpp.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ex2_cpp.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /cs/usr/romzats/ex2_cpp/main.cpp > CMakeFiles/ex2_cpp.dir/main.cpp.i

CMakeFiles/ex2_cpp.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ex2_cpp.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /cs/usr/romzats/ex2_cpp/main.cpp -o CMakeFiles/ex2_cpp.dir/main.cpp.s

CMakeFiles/ex2_cpp.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/ex2_cpp.dir/main.cpp.o.requires

CMakeFiles/ex2_cpp.dir/main.cpp.o.provides: CMakeFiles/ex2_cpp.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/ex2_cpp.dir/build.make CMakeFiles/ex2_cpp.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/ex2_cpp.dir/main.cpp.o.provides

CMakeFiles/ex2_cpp.dir/main.cpp.o.provides.build: CMakeFiles/ex2_cpp.dir/main.cpp.o


# Object files for target ex2_cpp
ex2_cpp_OBJECTS = \
"CMakeFiles/ex2_cpp.dir/main.cpp.o"

# External object files for target ex2_cpp
ex2_cpp_EXTERNAL_OBJECTS =

ex2_cpp: CMakeFiles/ex2_cpp.dir/main.cpp.o
ex2_cpp: CMakeFiles/ex2_cpp.dir/build.make
ex2_cpp: CMakeFiles/ex2_cpp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/cs/usr/romzats/ex2_cpp/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ex2_cpp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ex2_cpp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ex2_cpp.dir/build: ex2_cpp

.PHONY : CMakeFiles/ex2_cpp.dir/build

CMakeFiles/ex2_cpp.dir/requires: CMakeFiles/ex2_cpp.dir/main.cpp.o.requires

.PHONY : CMakeFiles/ex2_cpp.dir/requires

CMakeFiles/ex2_cpp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ex2_cpp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ex2_cpp.dir/clean

CMakeFiles/ex2_cpp.dir/depend:
	cd /cs/usr/romzats/ex2_cpp/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /cs/usr/romzats/ex2_cpp /cs/usr/romzats/ex2_cpp /cs/usr/romzats/ex2_cpp/cmake-build-debug /cs/usr/romzats/ex2_cpp/cmake-build-debug /cs/usr/romzats/ex2_cpp/cmake-build-debug/CMakeFiles/ex2_cpp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ex2_cpp.dir/depend
