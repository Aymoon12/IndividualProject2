# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.27

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2023.3.1\bin\cmake\win\x64\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2023.3.1\bin\cmake\win\x64\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\aymoo\CLionProjects\IndividualProject2\3.28.24

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\aymoo\CLionProjects\IndividualProject2\3.28.24\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/IndividualProject2.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/IndividualProject2.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/IndividualProject2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/IndividualProject2.dir/flags.make

CMakeFiles/IndividualProject2.dir/main.cpp.obj: CMakeFiles/IndividualProject2.dir/flags.make
CMakeFiles/IndividualProject2.dir/main.cpp.obj: C:/Users/aymoo/CLionProjects/IndividualProject2/3.28.24/main.cpp
CMakeFiles/IndividualProject2.dir/main.cpp.obj: CMakeFiles/IndividualProject2.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\aymoo\CLionProjects\IndividualProject2\3.28.24\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/IndividualProject2.dir/main.cpp.obj"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/IndividualProject2.dir/main.cpp.obj -MF CMakeFiles\IndividualProject2.dir\main.cpp.obj.d -o CMakeFiles\IndividualProject2.dir\main.cpp.obj -c C:\Users\aymoo\CLionProjects\IndividualProject2\3.28.24\main.cpp

CMakeFiles/IndividualProject2.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/IndividualProject2.dir/main.cpp.i"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\aymoo\CLionProjects\IndividualProject2\3.28.24\main.cpp > CMakeFiles\IndividualProject2.dir\main.cpp.i

CMakeFiles/IndividualProject2.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/IndividualProject2.dir/main.cpp.s"
	C:\PROGRA~1\JETBRA~1\CLION2~1.1\bin\mingw\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\aymoo\CLionProjects\IndividualProject2\3.28.24\main.cpp -o CMakeFiles\IndividualProject2.dir\main.cpp.s

# Object files for target IndividualProject2
IndividualProject2_OBJECTS = \
"CMakeFiles/IndividualProject2.dir/main.cpp.obj"

# External object files for target IndividualProject2
IndividualProject2_EXTERNAL_OBJECTS =

IndividualProject2.exe: CMakeFiles/IndividualProject2.dir/main.cpp.obj
IndividualProject2.exe: CMakeFiles/IndividualProject2.dir/build.make
IndividualProject2.exe: CMakeFiles/IndividualProject2.dir/linkLibs.rsp
IndividualProject2.exe: CMakeFiles/IndividualProject2.dir/objects1.rsp
IndividualProject2.exe: CMakeFiles/IndividualProject2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\aymoo\CLionProjects\IndividualProject2\3.28.24\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable IndividualProject2.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\IndividualProject2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/IndividualProject2.dir/build: IndividualProject2.exe
.PHONY : CMakeFiles/IndividualProject2.dir/build

CMakeFiles/IndividualProject2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\IndividualProject2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/IndividualProject2.dir/clean

CMakeFiles/IndividualProject2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\aymoo\CLionProjects\IndividualProject2\3.28.24 C:\Users\aymoo\CLionProjects\IndividualProject2\3.28.24 C:\Users\aymoo\CLionProjects\IndividualProject2\3.28.24\cmake-build-debug C:\Users\aymoo\CLionProjects\IndividualProject2\3.28.24\cmake-build-debug C:\Users\aymoo\CLionProjects\IndividualProject2\3.28.24\cmake-build-debug\CMakeFiles\IndividualProject2.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/IndividualProject2.dir/depend
