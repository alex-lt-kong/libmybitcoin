# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /root/repos/bitcoin-internals

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/repos/bitcoin-internals/build

# Include any dependencies generated for this target.
include chapter-test/CMakeFiles/test_ch04.dir/depend.make

# Include the progress variables for this target.
include chapter-test/CMakeFiles/test_ch04.dir/progress.make

# Include the compile flags for this target's objects.
include chapter-test/CMakeFiles/test_ch04.dir/flags.make

chapter-test/CMakeFiles/test_ch04.dir/test_ch04.cpp.o: chapter-test/CMakeFiles/test_ch04.dir/flags.make
chapter-test/CMakeFiles/test_ch04.dir/test_ch04.cpp.o: ../chapter-test/test_ch04.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/repos/bitcoin-internals/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object chapter-test/CMakeFiles/test_ch04.dir/test_ch04.cpp.o"
	cd /root/repos/bitcoin-internals/build/chapter-test && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/test_ch04.dir/test_ch04.cpp.o -c /root/repos/bitcoin-internals/chapter-test/test_ch04.cpp

chapter-test/CMakeFiles/test_ch04.dir/test_ch04.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test_ch04.dir/test_ch04.cpp.i"
	cd /root/repos/bitcoin-internals/build/chapter-test && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /root/repos/bitcoin-internals/chapter-test/test_ch04.cpp > CMakeFiles/test_ch04.dir/test_ch04.cpp.i

chapter-test/CMakeFiles/test_ch04.dir/test_ch04.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test_ch04.dir/test_ch04.cpp.s"
	cd /root/repos/bitcoin-internals/build/chapter-test && /usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /root/repos/bitcoin-internals/chapter-test/test_ch04.cpp -o CMakeFiles/test_ch04.dir/test_ch04.cpp.s

# Object files for target test_ch04
test_ch04_OBJECTS = \
"CMakeFiles/test_ch04.dir/test_ch04.cpp.o"

# External object files for target test_ch04
test_ch04_EXTERNAL_OBJECTS =

chapter-test/test_ch04: chapter-test/CMakeFiles/test_ch04.dir/test_ch04.cpp.o
chapter-test/test_ch04: chapter-test/CMakeFiles/test_ch04.dir/build.make
chapter-test/test_ch04: src/mybitcoin/libmybitcoin.a
chapter-test/test_ch04: chapter-test/CMakeFiles/test_ch04.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/repos/bitcoin-internals/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_ch04"
	cd /root/repos/bitcoin-internals/build/chapter-test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test_ch04.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
chapter-test/CMakeFiles/test_ch04.dir/build: chapter-test/test_ch04

.PHONY : chapter-test/CMakeFiles/test_ch04.dir/build

chapter-test/CMakeFiles/test_ch04.dir/clean:
	cd /root/repos/bitcoin-internals/build/chapter-test && $(CMAKE_COMMAND) -P CMakeFiles/test_ch04.dir/cmake_clean.cmake
.PHONY : chapter-test/CMakeFiles/test_ch04.dir/clean

chapter-test/CMakeFiles/test_ch04.dir/depend:
	cd /root/repos/bitcoin-internals/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/repos/bitcoin-internals /root/repos/bitcoin-internals/chapter-test /root/repos/bitcoin-internals/build /root/repos/bitcoin-internals/build/chapter-test /root/repos/bitcoin-internals/build/chapter-test/CMakeFiles/test_ch04.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : chapter-test/CMakeFiles/test_ch04.dir/depend

