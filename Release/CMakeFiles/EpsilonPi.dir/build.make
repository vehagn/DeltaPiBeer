# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/delta/DeltaPi

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/delta/DeltaPi/Release

# Include any dependencies generated for this target.
include CMakeFiles/EpsilonPi.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/EpsilonPi.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/EpsilonPi.dir/flags.make

CMakeFiles/EpsilonPi.dir/EpsilonPi.cpp.o: CMakeFiles/EpsilonPi.dir/flags.make
CMakeFiles/EpsilonPi.dir/EpsilonPi.cpp.o: ../EpsilonPi.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/delta/DeltaPi/Release/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/EpsilonPi.dir/EpsilonPi.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/EpsilonPi.dir/EpsilonPi.cpp.o -c /home/delta/DeltaPi/EpsilonPi.cpp

CMakeFiles/EpsilonPi.dir/EpsilonPi.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/EpsilonPi.dir/EpsilonPi.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/delta/DeltaPi/EpsilonPi.cpp > CMakeFiles/EpsilonPi.dir/EpsilonPi.cpp.i

CMakeFiles/EpsilonPi.dir/EpsilonPi.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/EpsilonPi.dir/EpsilonPi.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/delta/DeltaPi/EpsilonPi.cpp -o CMakeFiles/EpsilonPi.dir/EpsilonPi.cpp.s

CMakeFiles/EpsilonPi.dir/EpsilonPi.cpp.o.requires:
.PHONY : CMakeFiles/EpsilonPi.dir/EpsilonPi.cpp.o.requires

CMakeFiles/EpsilonPi.dir/EpsilonPi.cpp.o.provides: CMakeFiles/EpsilonPi.dir/EpsilonPi.cpp.o.requires
	$(MAKE) -f CMakeFiles/EpsilonPi.dir/build.make CMakeFiles/EpsilonPi.dir/EpsilonPi.cpp.o.provides.build
.PHONY : CMakeFiles/EpsilonPi.dir/EpsilonPi.cpp.o.provides

CMakeFiles/EpsilonPi.dir/EpsilonPi.cpp.o.provides.build: CMakeFiles/EpsilonPi.dir/EpsilonPi.cpp.o

# Object files for target EpsilonPi
EpsilonPi_OBJECTS = \
"CMakeFiles/EpsilonPi.dir/EpsilonPi.cpp.o"

# External object files for target EpsilonPi
EpsilonPi_EXTERNAL_OBJECTS =

EpsilonPi: CMakeFiles/EpsilonPi.dir/EpsilonPi.cpp.o
EpsilonPi: CMakeFiles/EpsilonPi.dir/build.make
EpsilonPi: libclasses.a
EpsilonPi: libfunctions.a
EpsilonPi: libmysql.a
EpsilonPi: /usr/lib/librpihw.so
EpsilonPi: /usr/lib/libGraphicsMagick++.so
EpsilonPi: CMakeFiles/EpsilonPi.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable EpsilonPi"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/EpsilonPi.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/EpsilonPi.dir/build: EpsilonPi
.PHONY : CMakeFiles/EpsilonPi.dir/build

CMakeFiles/EpsilonPi.dir/requires: CMakeFiles/EpsilonPi.dir/EpsilonPi.cpp.o.requires
.PHONY : CMakeFiles/EpsilonPi.dir/requires

CMakeFiles/EpsilonPi.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/EpsilonPi.dir/cmake_clean.cmake
.PHONY : CMakeFiles/EpsilonPi.dir/clean

CMakeFiles/EpsilonPi.dir/depend:
	cd /home/delta/DeltaPi/Release && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/delta/DeltaPi /home/delta/DeltaPi /home/delta/DeltaPi/Release /home/delta/DeltaPi/Release /home/delta/DeltaPi/Release/CMakeFiles/EpsilonPi.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/EpsilonPi.dir/depend
