# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_SOURCE_DIR = /Users/petergeras/CLionProjects/HW16

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/petergeras/CLionProjects/HW16/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/HW16.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/HW16.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/HW16.dir/flags.make

CMakeFiles/HW16.dir/psg2_hw16_q2.cpp.o: CMakeFiles/HW16.dir/flags.make
CMakeFiles/HW16.dir/psg2_hw16_q2.cpp.o: ../psg2_hw16_q2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/petergeras/CLionProjects/HW16/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/HW16.dir/psg2_hw16_q2.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/HW16.dir/psg2_hw16_q2.cpp.o -c /Users/petergeras/CLionProjects/HW16/psg2_hw16_q2.cpp

CMakeFiles/HW16.dir/psg2_hw16_q2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HW16.dir/psg2_hw16_q2.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/petergeras/CLionProjects/HW16/psg2_hw16_q2.cpp > CMakeFiles/HW16.dir/psg2_hw16_q2.cpp.i

CMakeFiles/HW16.dir/psg2_hw16_q2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HW16.dir/psg2_hw16_q2.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/petergeras/CLionProjects/HW16/psg2_hw16_q2.cpp -o CMakeFiles/HW16.dir/psg2_hw16_q2.cpp.s

CMakeFiles/HW16.dir/Queue.cpp.o: CMakeFiles/HW16.dir/flags.make
CMakeFiles/HW16.dir/Queue.cpp.o: ../Queue.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/petergeras/CLionProjects/HW16/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/HW16.dir/Queue.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/HW16.dir/Queue.cpp.o -c /Users/petergeras/CLionProjects/HW16/Queue.cpp

CMakeFiles/HW16.dir/Queue.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/HW16.dir/Queue.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/petergeras/CLionProjects/HW16/Queue.cpp > CMakeFiles/HW16.dir/Queue.cpp.i

CMakeFiles/HW16.dir/Queue.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/HW16.dir/Queue.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/petergeras/CLionProjects/HW16/Queue.cpp -o CMakeFiles/HW16.dir/Queue.cpp.s

# Object files for target HW16
HW16_OBJECTS = \
"CMakeFiles/HW16.dir/psg2_hw16_q2.cpp.o" \
"CMakeFiles/HW16.dir/Queue.cpp.o"

# External object files for target HW16
HW16_EXTERNAL_OBJECTS =

HW16: CMakeFiles/HW16.dir/psg2_hw16_q2.cpp.o
HW16: CMakeFiles/HW16.dir/Queue.cpp.o
HW16: CMakeFiles/HW16.dir/build.make
HW16: CMakeFiles/HW16.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/petergeras/CLionProjects/HW16/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable HW16"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/HW16.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/HW16.dir/build: HW16

.PHONY : CMakeFiles/HW16.dir/build

CMakeFiles/HW16.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/HW16.dir/cmake_clean.cmake
.PHONY : CMakeFiles/HW16.dir/clean

CMakeFiles/HW16.dir/depend:
	cd /Users/petergeras/CLionProjects/HW16/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/petergeras/CLionProjects/HW16 /Users/petergeras/CLionProjects/HW16 /Users/petergeras/CLionProjects/HW16/cmake-build-debug /Users/petergeras/CLionProjects/HW16/cmake-build-debug /Users/petergeras/CLionProjects/HW16/cmake-build-debug/CMakeFiles/HW16.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/HW16.dir/depend
