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
include CMakeFiles/InkwellBeta.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/InkwellBeta.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/InkwellBeta.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/InkwellBeta.dir/flags.make

qrc_myresources.cpp: /Users/AfamObioha/kaminari_prime/myresources.qrc
qrc_myresources.cpp: /Users/AfamObioha/kaminari_prime/assets/icons/folder_icon.png
qrc_myresources.cpp: /Users/AfamObioha/kaminari_prime/assets/icons/wifi_icon.png
qrc_myresources.cpp: /Users/AfamObioha/kaminari_prime/assets/icons/battery_icon.png
qrc_myresources.cpp: /Users/AfamObioha/kaminari_prime/assets/icons/action_icon.png
qrc_myresources.cpp: /Users/AfamObioha/kaminari_prime/assets/icons/sketch_icon.png
qrc_myresources.cpp: /Users/AfamObioha/kaminari_prime/assets/icons/settings_icon.png
qrc_myresources.cpp: /Users/AfamObioha/kaminari_prime/assets/icons/search_icon.png
qrc_myresources.cpp: /Users/AfamObioha/kaminari_prime/assets/icons/sticky_note_icon.png
qrc_myresources.cpp: /Users/AfamObioha/kaminari_prime/assets/icons/d_icon.png
qrc_myresources.cpp: /Users/AfamObioha/kaminari_prime/assets/icons/g_icon.png
qrc_myresources.cpp: /Users/AfamObioha/kaminari_prime/assets/icons/o_icon.png
qrc_myresources.cpp: /Users/AfamObioha/kaminari_prime/assets/icons/trashcan_icon.png
qrc_myresources.cpp: /Users/AfamObioha/kaminari_prime/assets/fonts/Roboto-Bold.ttf
qrc_myresources.cpp: myresources.qrc.depends
qrc_myresources.cpp: /Users/AfamObioha/Qt/6.6.2/macos/./libexec/rcc
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/AfamObioha/kaminari_prime/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating qrc_myresources.cpp"
	/Users/AfamObioha/Qt/6.6.2/macos/libexec/rcc --no-zstd --name myresources --output /Users/AfamObioha/kaminari_prime/build/qrc_myresources.cpp /Users/AfamObioha/kaminari_prime/myresources.qrc

InkwellBeta_autogen/timestamp: /Users/AfamObioha/Qt/6.6.2/macos/./libexec/moc
InkwellBeta_autogen/timestamp: /Users/AfamObioha/Qt/6.6.2/macos/./libexec/uic
InkwellBeta_autogen/timestamp: CMakeFiles/InkwellBeta.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/AfamObioha/kaminari_prime/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Automatic MOC and UIC for target InkwellBeta"
	/opt/homebrew/Cellar/cmake/3.28.3/bin/cmake -E cmake_autogen /Users/AfamObioha/kaminari_prime/build/CMakeFiles/InkwellBeta_autogen.dir/AutogenInfo.json Debug
	/opt/homebrew/Cellar/cmake/3.28.3/bin/cmake -E touch /Users/AfamObioha/kaminari_prime/build/InkwellBeta_autogen/timestamp

CMakeFiles/InkwellBeta.dir/InkwellBeta_autogen/mocs_compilation.cpp.o: CMakeFiles/InkwellBeta.dir/flags.make
CMakeFiles/InkwellBeta.dir/InkwellBeta_autogen/mocs_compilation.cpp.o: InkwellBeta_autogen/mocs_compilation.cpp
CMakeFiles/InkwellBeta.dir/InkwellBeta_autogen/mocs_compilation.cpp.o: CMakeFiles/InkwellBeta.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/AfamObioha/kaminari_prime/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/InkwellBeta.dir/InkwellBeta_autogen/mocs_compilation.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/InkwellBeta.dir/InkwellBeta_autogen/mocs_compilation.cpp.o -MF CMakeFiles/InkwellBeta.dir/InkwellBeta_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/InkwellBeta.dir/InkwellBeta_autogen/mocs_compilation.cpp.o -c /Users/AfamObioha/kaminari_prime/build/InkwellBeta_autogen/mocs_compilation.cpp

CMakeFiles/InkwellBeta.dir/InkwellBeta_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/InkwellBeta.dir/InkwellBeta_autogen/mocs_compilation.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/AfamObioha/kaminari_prime/build/InkwellBeta_autogen/mocs_compilation.cpp > CMakeFiles/InkwellBeta.dir/InkwellBeta_autogen/mocs_compilation.cpp.i

CMakeFiles/InkwellBeta.dir/InkwellBeta_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/InkwellBeta.dir/InkwellBeta_autogen/mocs_compilation.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/AfamObioha/kaminari_prime/build/InkwellBeta_autogen/mocs_compilation.cpp -o CMakeFiles/InkwellBeta.dir/InkwellBeta_autogen/mocs_compilation.cpp.s

CMakeFiles/InkwellBeta.dir/main.cpp.o: CMakeFiles/InkwellBeta.dir/flags.make
CMakeFiles/InkwellBeta.dir/main.cpp.o: /Users/AfamObioha/kaminari_prime/main.cpp
CMakeFiles/InkwellBeta.dir/main.cpp.o: CMakeFiles/InkwellBeta.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/AfamObioha/kaminari_prime/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/InkwellBeta.dir/main.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/InkwellBeta.dir/main.cpp.o -MF CMakeFiles/InkwellBeta.dir/main.cpp.o.d -o CMakeFiles/InkwellBeta.dir/main.cpp.o -c /Users/AfamObioha/kaminari_prime/main.cpp

CMakeFiles/InkwellBeta.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/InkwellBeta.dir/main.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/AfamObioha/kaminari_prime/main.cpp > CMakeFiles/InkwellBeta.dir/main.cpp.i

CMakeFiles/InkwellBeta.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/InkwellBeta.dir/main.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/AfamObioha/kaminari_prime/main.cpp -o CMakeFiles/InkwellBeta.dir/main.cpp.s

CMakeFiles/InkwellBeta.dir/mainwindow.cpp.o: CMakeFiles/InkwellBeta.dir/flags.make
CMakeFiles/InkwellBeta.dir/mainwindow.cpp.o: /Users/AfamObioha/kaminari_prime/mainwindow.cpp
CMakeFiles/InkwellBeta.dir/mainwindow.cpp.o: CMakeFiles/InkwellBeta.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/AfamObioha/kaminari_prime/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/InkwellBeta.dir/mainwindow.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/InkwellBeta.dir/mainwindow.cpp.o -MF CMakeFiles/InkwellBeta.dir/mainwindow.cpp.o.d -o CMakeFiles/InkwellBeta.dir/mainwindow.cpp.o -c /Users/AfamObioha/kaminari_prime/mainwindow.cpp

CMakeFiles/InkwellBeta.dir/mainwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/InkwellBeta.dir/mainwindow.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/AfamObioha/kaminari_prime/mainwindow.cpp > CMakeFiles/InkwellBeta.dir/mainwindow.cpp.i

CMakeFiles/InkwellBeta.dir/mainwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/InkwellBeta.dir/mainwindow.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/AfamObioha/kaminari_prime/mainwindow.cpp -o CMakeFiles/InkwellBeta.dir/mainwindow.cpp.s

CMakeFiles/InkwellBeta.dir/FolderWidget.cpp.o: CMakeFiles/InkwellBeta.dir/flags.make
CMakeFiles/InkwellBeta.dir/FolderWidget.cpp.o: /Users/AfamObioha/kaminari_prime/FolderWidget.cpp
CMakeFiles/InkwellBeta.dir/FolderWidget.cpp.o: CMakeFiles/InkwellBeta.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/AfamObioha/kaminari_prime/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/InkwellBeta.dir/FolderWidget.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/InkwellBeta.dir/FolderWidget.cpp.o -MF CMakeFiles/InkwellBeta.dir/FolderWidget.cpp.o.d -o CMakeFiles/InkwellBeta.dir/FolderWidget.cpp.o -c /Users/AfamObioha/kaminari_prime/FolderWidget.cpp

CMakeFiles/InkwellBeta.dir/FolderWidget.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/InkwellBeta.dir/FolderWidget.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/AfamObioha/kaminari_prime/FolderWidget.cpp > CMakeFiles/InkwellBeta.dir/FolderWidget.cpp.i

CMakeFiles/InkwellBeta.dir/FolderWidget.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/InkwellBeta.dir/FolderWidget.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/AfamObioha/kaminari_prime/FolderWidget.cpp -o CMakeFiles/InkwellBeta.dir/FolderWidget.cpp.s

CMakeFiles/InkwellBeta.dir/qrc_myresources.cpp.o: CMakeFiles/InkwellBeta.dir/flags.make
CMakeFiles/InkwellBeta.dir/qrc_myresources.cpp.o: qrc_myresources.cpp
CMakeFiles/InkwellBeta.dir/qrc_myresources.cpp.o: CMakeFiles/InkwellBeta.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/AfamObioha/kaminari_prime/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/InkwellBeta.dir/qrc_myresources.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/InkwellBeta.dir/qrc_myresources.cpp.o -MF CMakeFiles/InkwellBeta.dir/qrc_myresources.cpp.o.d -o CMakeFiles/InkwellBeta.dir/qrc_myresources.cpp.o -c /Users/AfamObioha/kaminari_prime/build/qrc_myresources.cpp

CMakeFiles/InkwellBeta.dir/qrc_myresources.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/InkwellBeta.dir/qrc_myresources.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/AfamObioha/kaminari_prime/build/qrc_myresources.cpp > CMakeFiles/InkwellBeta.dir/qrc_myresources.cpp.i

CMakeFiles/InkwellBeta.dir/qrc_myresources.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/InkwellBeta.dir/qrc_myresources.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/AfamObioha/kaminari_prime/build/qrc_myresources.cpp -o CMakeFiles/InkwellBeta.dir/qrc_myresources.cpp.s

# Object files for target InkwellBeta
InkwellBeta_OBJECTS = \
"CMakeFiles/InkwellBeta.dir/InkwellBeta_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/InkwellBeta.dir/main.cpp.o" \
"CMakeFiles/InkwellBeta.dir/mainwindow.cpp.o" \
"CMakeFiles/InkwellBeta.dir/FolderWidget.cpp.o" \
"CMakeFiles/InkwellBeta.dir/qrc_myresources.cpp.o"

# External object files for target InkwellBeta
InkwellBeta_EXTERNAL_OBJECTS =

InkwellBeta: CMakeFiles/InkwellBeta.dir/InkwellBeta_autogen/mocs_compilation.cpp.o
InkwellBeta: CMakeFiles/InkwellBeta.dir/main.cpp.o
InkwellBeta: CMakeFiles/InkwellBeta.dir/mainwindow.cpp.o
InkwellBeta: CMakeFiles/InkwellBeta.dir/FolderWidget.cpp.o
InkwellBeta: CMakeFiles/InkwellBeta.dir/qrc_myresources.cpp.o
InkwellBeta: CMakeFiles/InkwellBeta.dir/build.make
InkwellBeta: /Users/AfamObioha/Qt/6.6.2/macos/lib/QtWidgets.framework/Versions/A/QtWidgets
InkwellBeta: /Users/AfamObioha/Qt/6.6.2/macos/lib/QtGui.framework/Versions/A/QtGui
InkwellBeta: /Users/AfamObioha/Qt/6.6.2/macos/lib/QtCore.framework/Versions/A/QtCore
InkwellBeta: CMakeFiles/InkwellBeta.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/AfamObioha/kaminari_prime/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable InkwellBeta"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/InkwellBeta.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/InkwellBeta.dir/build: InkwellBeta
.PHONY : CMakeFiles/InkwellBeta.dir/build

CMakeFiles/InkwellBeta.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/InkwellBeta.dir/cmake_clean.cmake
.PHONY : CMakeFiles/InkwellBeta.dir/clean

CMakeFiles/InkwellBeta.dir/depend: InkwellBeta_autogen/timestamp
CMakeFiles/InkwellBeta.dir/depend: qrc_myresources.cpp
	cd /Users/AfamObioha/kaminari_prime/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/AfamObioha/kaminari_prime /Users/AfamObioha/kaminari_prime /Users/AfamObioha/kaminari_prime/build /Users/AfamObioha/kaminari_prime/build /Users/AfamObioha/kaminari_prime/build/CMakeFiles/InkwellBeta.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/InkwellBeta.dir/depend

