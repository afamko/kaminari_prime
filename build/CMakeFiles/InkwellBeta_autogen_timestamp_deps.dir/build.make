# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.28.3/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.28.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/deltonutsey/kaminari_prime

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/deltonutsey/kaminari_prime/build

# Utility rule file for InkwellBeta_autogen_timestamp_deps.

# Include any custom commands dependencies for this target.
include CMakeFiles/InkwellBeta_autogen_timestamp_deps.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/InkwellBeta_autogen_timestamp_deps.dir/progress.make

CMakeFiles/InkwellBeta_autogen_timestamp_deps: /Users/deltonutsey/Qt/6.6.2/macos/./libexec/uic
CMakeFiles/InkwellBeta_autogen_timestamp_deps: /Users/deltonutsey/Qt/6.6.2/macos/./libexec/moc
CMakeFiles/InkwellBeta_autogen_timestamp_deps: /Users/deltonutsey/Qt/6.6.2/macos/lib/QtWidgets.framework/Versions/A/QtWidgets

InkwellBeta_autogen_timestamp_deps: CMakeFiles/InkwellBeta_autogen_timestamp_deps
InkwellBeta_autogen_timestamp_deps: CMakeFiles/InkwellBeta_autogen_timestamp_deps.dir/build.make
.PHONY : InkwellBeta_autogen_timestamp_deps

# Rule to build all files generated by this target.
CMakeFiles/InkwellBeta_autogen_timestamp_deps.dir/build: InkwellBeta_autogen_timestamp_deps
.PHONY : CMakeFiles/InkwellBeta_autogen_timestamp_deps.dir/build

CMakeFiles/InkwellBeta_autogen_timestamp_deps.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/InkwellBeta_autogen_timestamp_deps.dir/cmake_clean.cmake
.PHONY : CMakeFiles/InkwellBeta_autogen_timestamp_deps.dir/clean

CMakeFiles/InkwellBeta_autogen_timestamp_deps.dir/depend:
	cd /Users/deltonutsey/kaminari_prime/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/deltonutsey/kaminari_prime /Users/deltonutsey/kaminari_prime /Users/deltonutsey/kaminari_prime/build /Users/deltonutsey/kaminari_prime/build /Users/deltonutsey/kaminari_prime/build/CMakeFiles/InkwellBeta_autogen_timestamp_deps.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/InkwellBeta_autogen_timestamp_deps.dir/depend

