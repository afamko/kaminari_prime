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
CMAKE_SOURCE_DIR = /Users/AfamObioha/kaminari_prime

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/AfamObioha/kaminari_prime/build

# Include any dependencies generated for this target.
include CMakeFiles/SimpleQtApp.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/SimpleQtApp.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/SimpleQtApp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SimpleQtApp.dir/flags.make

SimpleQtApp_autogen/timestamp: /Users/AfamObioha/Qt/6.6.2/macos/./libexec/moc
SimpleQtApp_autogen/timestamp: /Users/AfamObioha/Qt/6.6.2/macos/./libexec/uic
SimpleQtApp_autogen/timestamp: CMakeFiles/SimpleQtApp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/AfamObioha/kaminari_prime/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target SimpleQtApp"
	/opt/homebrew/Cellar/cmake/3.28.3/bin/cmake -E cmake_autogen /Users/AfamObioha/kaminari_prime/build/CMakeFiles/SimpleQtApp_autogen.dir/AutogenInfo.json Debug
	/opt/homebrew/Cellar/cmake/3.28.3/bin/cmake -E touch /Users/AfamObioha/kaminari_prime/build/SimpleQtApp_autogen/timestamp

CMakeFiles/SimpleQtApp.dir/SimpleQtApp_autogen/mocs_compilation.cpp.o: CMakeFiles/SimpleQtApp.dir/flags.make
CMakeFiles/SimpleQtApp.dir/SimpleQtApp_autogen/mocs_compilation.cpp.o: SimpleQtApp_autogen/mocs_compilation.cpp
CMakeFiles/SimpleQtApp.dir/SimpleQtApp_autogen/mocs_compilation.cpp.o: CMakeFiles/SimpleQtApp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/AfamObioha/kaminari_prime/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/SimpleQtApp.dir/SimpleQtApp_autogen/mocs_compilation.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SimpleQtApp.dir/SimpleQtApp_autogen/mocs_compilation.cpp.o -MF CMakeFiles/SimpleQtApp.dir/SimpleQtApp_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/SimpleQtApp.dir/SimpleQtApp_autogen/mocs_compilation.cpp.o -c /Users/AfamObioha/kaminari_prime/build/SimpleQtApp_autogen/mocs_compilation.cpp

CMakeFiles/SimpleQtApp.dir/SimpleQtApp_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SimpleQtApp.dir/SimpleQtApp_autogen/mocs_compilation.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/AfamObioha/kaminari_prime/build/SimpleQtApp_autogen/mocs_compilation.cpp > CMakeFiles/SimpleQtApp.dir/SimpleQtApp_autogen/mocs_compilation.cpp.i

CMakeFiles/SimpleQtApp.dir/SimpleQtApp_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SimpleQtApp.dir/SimpleQtApp_autogen/mocs_compilation.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/AfamObioha/kaminari_prime/build/SimpleQtApp_autogen/mocs_compilation.cpp -o CMakeFiles/SimpleQtApp.dir/SimpleQtApp_autogen/mocs_compilation.cpp.s

CMakeFiles/SimpleQtApp.dir/main.cpp.o: CMakeFiles/SimpleQtApp.dir/flags.make
CMakeFiles/SimpleQtApp.dir/main.cpp.o: /Users/AfamObioha/kaminari_prime/main.cpp
CMakeFiles/SimpleQtApp.dir/main.cpp.o: CMakeFiles/SimpleQtApp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/AfamObioha/kaminari_prime/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/SimpleQtApp.dir/main.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SimpleQtApp.dir/main.cpp.o -MF CMakeFiles/SimpleQtApp.dir/main.cpp.o.d -o CMakeFiles/SimpleQtApp.dir/main.cpp.o -c /Users/AfamObioha/kaminari_prime/main.cpp

CMakeFiles/SimpleQtApp.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SimpleQtApp.dir/main.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/AfamObioha/kaminari_prime/main.cpp > CMakeFiles/SimpleQtApp.dir/main.cpp.i

CMakeFiles/SimpleQtApp.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SimpleQtApp.dir/main.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/AfamObioha/kaminari_prime/main.cpp -o CMakeFiles/SimpleQtApp.dir/main.cpp.s

CMakeFiles/SimpleQtApp.dir/mainwindow.cpp.o: CMakeFiles/SimpleQtApp.dir/flags.make
CMakeFiles/SimpleQtApp.dir/mainwindow.cpp.o: /Users/AfamObioha/kaminari_prime/mainwindow.cpp
CMakeFiles/SimpleQtApp.dir/mainwindow.cpp.o: CMakeFiles/SimpleQtApp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/AfamObioha/kaminari_prime/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/SimpleQtApp.dir/mainwindow.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SimpleQtApp.dir/mainwindow.cpp.o -MF CMakeFiles/SimpleQtApp.dir/mainwindow.cpp.o.d -o CMakeFiles/SimpleQtApp.dir/mainwindow.cpp.o -c /Users/AfamObioha/kaminari_prime/mainwindow.cpp

CMakeFiles/SimpleQtApp.dir/mainwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SimpleQtApp.dir/mainwindow.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/AfamObioha/kaminari_prime/mainwindow.cpp > CMakeFiles/SimpleQtApp.dir/mainwindow.cpp.i

CMakeFiles/SimpleQtApp.dir/mainwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SimpleQtApp.dir/mainwindow.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/AfamObioha/kaminari_prime/mainwindow.cpp -o CMakeFiles/SimpleQtApp.dir/mainwindow.cpp.s

CMakeFiles/SimpleQtApp.dir/FolderWidget.cpp.o: CMakeFiles/SimpleQtApp.dir/flags.make
CMakeFiles/SimpleQtApp.dir/FolderWidget.cpp.o: /Users/AfamObioha/kaminari_prime/FolderWidget.cpp
CMakeFiles/SimpleQtApp.dir/FolderWidget.cpp.o: CMakeFiles/SimpleQtApp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/AfamObioha/kaminari_prime/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/SimpleQtApp.dir/FolderWidget.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/SimpleQtApp.dir/FolderWidget.cpp.o -MF CMakeFiles/SimpleQtApp.dir/FolderWidget.cpp.o.d -o CMakeFiles/SimpleQtApp.dir/FolderWidget.cpp.o -c /Users/AfamObioha/kaminari_prime/FolderWidget.cpp

CMakeFiles/SimpleQtApp.dir/FolderWidget.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/SimpleQtApp.dir/FolderWidget.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/AfamObioha/kaminari_prime/FolderWidget.cpp > CMakeFiles/SimpleQtApp.dir/FolderWidget.cpp.i

CMakeFiles/SimpleQtApp.dir/FolderWidget.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/SimpleQtApp.dir/FolderWidget.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/AfamObioha/kaminari_prime/FolderWidget.cpp -o CMakeFiles/SimpleQtApp.dir/FolderWidget.cpp.s

# Object files for target SimpleQtApp
SimpleQtApp_OBJECTS = \
"CMakeFiles/SimpleQtApp.dir/SimpleQtApp_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/SimpleQtApp.dir/main.cpp.o" \
"CMakeFiles/SimpleQtApp.dir/mainwindow.cpp.o" \
"CMakeFiles/SimpleQtApp.dir/FolderWidget.cpp.o"

# External object files for target SimpleQtApp
SimpleQtApp_EXTERNAL_OBJECTS =

SimpleQtApp: CMakeFiles/SimpleQtApp.dir/SimpleQtApp_autogen/mocs_compilation.cpp.o
SimpleQtApp: CMakeFiles/SimpleQtApp.dir/main.cpp.o
SimpleQtApp: CMakeFiles/SimpleQtApp.dir/mainwindow.cpp.o
SimpleQtApp: CMakeFiles/SimpleQtApp.dir/FolderWidget.cpp.o
SimpleQtApp: CMakeFiles/SimpleQtApp.dir/build.make
SimpleQtApp: /Users/AfamObioha/Qt/6.6.2/macos/lib/QtWidgets.framework/Versions/A/QtWidgets
SimpleQtApp: /Users/AfamObioha/Qt/6.6.2/macos/lib/QtGui.framework/Versions/A/QtGui
SimpleQtApp: /Users/AfamObioha/Qt/6.6.2/macos/lib/QtCore.framework/Versions/A/QtCore
SimpleQtApp: CMakeFiles/SimpleQtApp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/AfamObioha/kaminari_prime/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable SimpleQtApp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SimpleQtApp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SimpleQtApp.dir/build: SimpleQtApp
.PHONY : CMakeFiles/SimpleQtApp.dir/build

CMakeFiles/SimpleQtApp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SimpleQtApp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SimpleQtApp.dir/clean

CMakeFiles/SimpleQtApp.dir/depend: SimpleQtApp_autogen/timestamp
	cd /Users/AfamObioha/kaminari_prime/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/AfamObioha/kaminari_prime /Users/AfamObioha/kaminari_prime /Users/AfamObioha/kaminari_prime/build /Users/AfamObioha/kaminari_prime/build /Users/AfamObioha/kaminari_prime/build/CMakeFiles/SimpleQtApp.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/SimpleQtApp.dir/depend
