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
CMAKE_SOURCE_DIR = /home/canoi/cross_gl

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/canoi/cross_gl/build

# Include any dependencies generated for this target.
include CMakeFiles/cross_gl.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/cross_gl.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cross_gl.dir/flags.make

CMakeFiles/cross_gl.dir/main.c.o: CMakeFiles/cross_gl.dir/flags.make
CMakeFiles/cross_gl.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/canoi/cross_gl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/cross_gl.dir/main.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cross_gl.dir/main.c.o -c /home/canoi/cross_gl/main.c

CMakeFiles/cross_gl.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cross_gl.dir/main.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/canoi/cross_gl/main.c > CMakeFiles/cross_gl.dir/main.c.i

CMakeFiles/cross_gl.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cross_gl.dir/main.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/canoi/cross_gl/main.c -o CMakeFiles/cross_gl.dir/main.c.s

CMakeFiles/cross_gl.dir/glad/src/glad.c.o: CMakeFiles/cross_gl.dir/flags.make
CMakeFiles/cross_gl.dir/glad/src/glad.c.o: ../glad/src/glad.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/canoi/cross_gl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/cross_gl.dir/glad/src/glad.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/cross_gl.dir/glad/src/glad.c.o -c /home/canoi/cross_gl/glad/src/glad.c

CMakeFiles/cross_gl.dir/glad/src/glad.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/cross_gl.dir/glad/src/glad.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/canoi/cross_gl/glad/src/glad.c > CMakeFiles/cross_gl.dir/glad/src/glad.c.i

CMakeFiles/cross_gl.dir/glad/src/glad.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/cross_gl.dir/glad/src/glad.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/canoi/cross_gl/glad/src/glad.c -o CMakeFiles/cross_gl.dir/glad/src/glad.c.s

# Object files for target cross_gl
cross_gl_OBJECTS = \
"CMakeFiles/cross_gl.dir/main.c.o" \
"CMakeFiles/cross_gl.dir/glad/src/glad.c.o"

# External object files for target cross_gl
cross_gl_EXTERNAL_OBJECTS =

cross_gl: CMakeFiles/cross_gl.dir/main.c.o
cross_gl: CMakeFiles/cross_gl.dir/glad/src/glad.c.o
cross_gl: CMakeFiles/cross_gl.dir/build.make
cross_gl: /usr/lib/x86_64-linux-gnu/libGL.so
cross_gl: /usr/lib/x86_64-linux-gnu/libGLU.so
cross_gl: CMakeFiles/cross_gl.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/canoi/cross_gl/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking C executable cross_gl"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cross_gl.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cross_gl.dir/build: cross_gl

.PHONY : CMakeFiles/cross_gl.dir/build

CMakeFiles/cross_gl.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cross_gl.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cross_gl.dir/clean

CMakeFiles/cross_gl.dir/depend:
	cd /home/canoi/cross_gl/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/canoi/cross_gl /home/canoi/cross_gl /home/canoi/cross_gl/build /home/canoi/cross_gl/build /home/canoi/cross_gl/build/CMakeFiles/cross_gl.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/cross_gl.dir/depend

