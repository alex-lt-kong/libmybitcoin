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

# Utility rule file for test.

# Include the progress variables for this target.
include chapter-test/CMakeFiles/test.dir/progress.make

test: chapter-test/CMakeFiles/test.dir/build.make
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Running test_ch01..."
	cd /root/repos/bitcoin-internals/build/chapter-test && ./test_ch01
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Running test_ch02..."
	cd /root/repos/bitcoin-internals/build/chapter-test && ./test_ch02
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Running test_ch03..."
	cd /root/repos/bitcoin-internals/build/chapter-test && ./test_ch03
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Running test_ch04..."
	cd /root/repos/bitcoin-internals/build/chapter-test && ./test_ch04
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Running test_ch05..."
	cd /root/repos/bitcoin-internals/build/chapter-test && ./test_ch05
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Running test_ch06..."
	cd /root/repos/bitcoin-internals/build/chapter-test && ./test_ch06
.PHONY : test

# Rule to build all files generated by this target.
chapter-test/CMakeFiles/test.dir/build: test

.PHONY : chapter-test/CMakeFiles/test.dir/build

chapter-test/CMakeFiles/test.dir/clean:
	cd /root/repos/bitcoin-internals/build/chapter-test && $(CMAKE_COMMAND) -P CMakeFiles/test.dir/cmake_clean.cmake
.PHONY : chapter-test/CMakeFiles/test.dir/clean

chapter-test/CMakeFiles/test.dir/depend:
	cd /root/repos/bitcoin-internals/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/repos/bitcoin-internals /root/repos/bitcoin-internals/chapter-test /root/repos/bitcoin-internals/build /root/repos/bitcoin-internals/build/chapter-test /root/repos/bitcoin-internals/build/chapter-test/CMakeFiles/test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : chapter-test/CMakeFiles/test.dir/depend

