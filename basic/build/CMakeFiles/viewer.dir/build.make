# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.6

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.6.1/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.6.1/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/jean/Code/mecacell-examples/basic

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/jean/Code/mecacell-examples/basic/build

# Include any dependencies generated for this target.
include CMakeFiles/viewer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/viewer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/viewer.dir/flags.make

CMakeFiles/viewer.dir/src/mainviewer.cpp.o: CMakeFiles/viewer.dir/flags.make
CMakeFiles/viewer.dir/src/mainviewer.cpp.o: ../src/mainviewer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jean/Code/mecacell-examples/basic/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/viewer.dir/src/mainviewer.cpp.o"
	g++-6   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/viewer.dir/src/mainviewer.cpp.o -c /Users/jean/Code/mecacell-examples/basic/src/mainviewer.cpp

CMakeFiles/viewer.dir/src/mainviewer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/viewer.dir/src/mainviewer.cpp.i"
	g++-6  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jean/Code/mecacell-examples/basic/src/mainviewer.cpp > CMakeFiles/viewer.dir/src/mainviewer.cpp.i

CMakeFiles/viewer.dir/src/mainviewer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/viewer.dir/src/mainviewer.cpp.s"
	g++-6  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jean/Code/mecacell-examples/basic/src/mainviewer.cpp -o CMakeFiles/viewer.dir/src/mainviewer.cpp.s

CMakeFiles/viewer.dir/src/mainviewer.cpp.o.requires:

.PHONY : CMakeFiles/viewer.dir/src/mainviewer.cpp.o.requires

CMakeFiles/viewer.dir/src/mainviewer.cpp.o.provides: CMakeFiles/viewer.dir/src/mainviewer.cpp.o.requires
	$(MAKE) -f CMakeFiles/viewer.dir/build.make CMakeFiles/viewer.dir/src/mainviewer.cpp.o.provides.build
.PHONY : CMakeFiles/viewer.dir/src/mainviewer.cpp.o.provides

CMakeFiles/viewer.dir/src/mainviewer.cpp.o.provides.build: CMakeFiles/viewer.dir/src/mainviewer.cpp.o


CMakeFiles/viewer.dir/viewer_automoc.cpp.o: CMakeFiles/viewer.dir/flags.make
CMakeFiles/viewer.dir/viewer_automoc.cpp.o: viewer_automoc.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/jean/Code/mecacell-examples/basic/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/viewer.dir/viewer_automoc.cpp.o"
	g++-6   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/viewer.dir/viewer_automoc.cpp.o -c /Users/jean/Code/mecacell-examples/basic/build/viewer_automoc.cpp

CMakeFiles/viewer.dir/viewer_automoc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/viewer.dir/viewer_automoc.cpp.i"
	g++-6  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/jean/Code/mecacell-examples/basic/build/viewer_automoc.cpp > CMakeFiles/viewer.dir/viewer_automoc.cpp.i

CMakeFiles/viewer.dir/viewer_automoc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/viewer.dir/viewer_automoc.cpp.s"
	g++-6  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/jean/Code/mecacell-examples/basic/build/viewer_automoc.cpp -o CMakeFiles/viewer.dir/viewer_automoc.cpp.s

CMakeFiles/viewer.dir/viewer_automoc.cpp.o.requires:

.PHONY : CMakeFiles/viewer.dir/viewer_automoc.cpp.o.requires

CMakeFiles/viewer.dir/viewer_automoc.cpp.o.provides: CMakeFiles/viewer.dir/viewer_automoc.cpp.o.requires
	$(MAKE) -f CMakeFiles/viewer.dir/build.make CMakeFiles/viewer.dir/viewer_automoc.cpp.o.provides.build
.PHONY : CMakeFiles/viewer.dir/viewer_automoc.cpp.o.provides

CMakeFiles/viewer.dir/viewer_automoc.cpp.o.provides.build: CMakeFiles/viewer.dir/viewer_automoc.cpp.o


# Object files for target viewer
viewer_OBJECTS = \
"CMakeFiles/viewer.dir/src/mainviewer.cpp.o" \
"CMakeFiles/viewer.dir/viewer_automoc.cpp.o"

# External object files for target viewer
viewer_EXTERNAL_OBJECTS =

../bin/viewer: CMakeFiles/viewer.dir/src/mainviewer.cpp.o
../bin/viewer: CMakeFiles/viewer.dir/viewer_automoc.cpp.o
../bin/viewer: CMakeFiles/viewer.dir/build.make
../bin/viewer: /usr/local/Cellar/qt5/5.6.0/lib/QtQuick.framework/QtQuick
../bin/viewer: /usr/local/Cellar/qt5/5.6.0/lib/QtOpenGL.framework/QtOpenGL
../bin/viewer: /usr/local/Cellar/qt5/5.6.0/lib/QtQml.framework/QtQml
../bin/viewer: /usr/local/Cellar/qt5/5.6.0/lib/QtNetwork.framework/QtNetwork
../bin/viewer: /usr/local/Cellar/qt5/5.6.0/lib/QtWidgets.framework/QtWidgets
../bin/viewer: /usr/local/Cellar/qt5/5.6.0/lib/QtGui.framework/QtGui
../bin/viewer: /usr/local/Cellar/qt5/5.6.0/lib/QtCore.framework/QtCore
../bin/viewer: CMakeFiles/viewer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/jean/Code/mecacell-examples/basic/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable ../bin/viewer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/viewer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/viewer.dir/build: ../bin/viewer

.PHONY : CMakeFiles/viewer.dir/build

CMakeFiles/viewer.dir/requires: CMakeFiles/viewer.dir/src/mainviewer.cpp.o.requires
CMakeFiles/viewer.dir/requires: CMakeFiles/viewer.dir/viewer_automoc.cpp.o.requires

.PHONY : CMakeFiles/viewer.dir/requires

CMakeFiles/viewer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/viewer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/viewer.dir/clean

CMakeFiles/viewer.dir/depend:
	cd /Users/jean/Code/mecacell-examples/basic/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/jean/Code/mecacell-examples/basic /Users/jean/Code/mecacell-examples/basic /Users/jean/Code/mecacell-examples/basic/build /Users/jean/Code/mecacell-examples/basic/build /Users/jean/Code/mecacell-examples/basic/build/CMakeFiles/viewer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/viewer.dir/depend

