# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/marchaubenstock/Workspace/C++/ImageLib

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/marchaubenstock/Workspace/C++/ImageLib/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ImageLib.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ImageLib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ImageLib.dir/flags.make

CMakeFiles/ImageLib.dir/src/image.cpp.o: CMakeFiles/ImageLib.dir/flags.make
CMakeFiles/ImageLib.dir/src/image.cpp.o: ../src/image.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/marchaubenstock/Workspace/C++/ImageLib/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ImageLib.dir/src/image.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ImageLib.dir/src/image.cpp.o -c /Users/marchaubenstock/Workspace/C++/ImageLib/src/image.cpp

CMakeFiles/ImageLib.dir/src/image.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ImageLib.dir/src/image.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/marchaubenstock/Workspace/C++/ImageLib/src/image.cpp > CMakeFiles/ImageLib.dir/src/image.cpp.i

CMakeFiles/ImageLib.dir/src/image.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ImageLib.dir/src/image.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/marchaubenstock/Workspace/C++/ImageLib/src/image.cpp -o CMakeFiles/ImageLib.dir/src/image.cpp.s

# Object files for target ImageLib
ImageLib_OBJECTS = \
"CMakeFiles/ImageLib.dir/src/image.cpp.o"

# External object files for target ImageLib
ImageLib_EXTERNAL_OBJECTS =

libImageLib.dylib: CMakeFiles/ImageLib.dir/src/image.cpp.o
libImageLib.dylib: CMakeFiles/ImageLib.dir/build.make
libImageLib.dylib: /opt/X11/lib/libSM.dylib
libImageLib.dylib: /opt/X11/lib/libICE.dylib
libImageLib.dylib: /opt/X11/lib/libX11.dylib
libImageLib.dylib: /opt/X11/lib/libXext.dylib
libImageLib.dylib: CMakeFiles/ImageLib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/marchaubenstock/Workspace/C++/ImageLib/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libImageLib.dylib"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ImageLib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ImageLib.dir/build: libImageLib.dylib

.PHONY : CMakeFiles/ImageLib.dir/build

CMakeFiles/ImageLib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ImageLib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ImageLib.dir/clean

CMakeFiles/ImageLib.dir/depend:
	cd /Users/marchaubenstock/Workspace/C++/ImageLib/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/marchaubenstock/Workspace/C++/ImageLib /Users/marchaubenstock/Workspace/C++/ImageLib /Users/marchaubenstock/Workspace/C++/ImageLib/cmake-build-debug /Users/marchaubenstock/Workspace/C++/ImageLib/cmake-build-debug /Users/marchaubenstock/Workspace/C++/ImageLib/cmake-build-debug/CMakeFiles/ImageLib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ImageLib.dir/depend

