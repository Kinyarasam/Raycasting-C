# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.29

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.29.3/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.29.3/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/vivo/Code/Challenges/challenges/Raycasting-C

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/vivo/Code/Challenges/challenges/Raycasting-C/build

# Include any dependencies generated for this target.
include CMakeFiles/raycasting.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/raycasting.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/raycasting.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/raycasting.dir/flags.make

CMakeFiles/raycasting.dir/src/main.c.o: CMakeFiles/raycasting.dir/flags.make
CMakeFiles/raycasting.dir/src/main.c.o: /Users/vivo/Code/Challenges/challenges/Raycasting-C/src/main.c
CMakeFiles/raycasting.dir/src/main.c.o: CMakeFiles/raycasting.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/vivo/Code/Challenges/challenges/Raycasting-C/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/raycasting.dir/src/main.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/raycasting.dir/src/main.c.o -MF CMakeFiles/raycasting.dir/src/main.c.o.d -o CMakeFiles/raycasting.dir/src/main.c.o -c /Users/vivo/Code/Challenges/challenges/Raycasting-C/src/main.c

CMakeFiles/raycasting.dir/src/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/raycasting.dir/src/main.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/vivo/Code/Challenges/challenges/Raycasting-C/src/main.c > CMakeFiles/raycasting.dir/src/main.c.i

CMakeFiles/raycasting.dir/src/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/raycasting.dir/src/main.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/vivo/Code/Challenges/challenges/Raycasting-C/src/main.c -o CMakeFiles/raycasting.dir/src/main.c.s

CMakeFiles/raycasting.dir/src/maze.c.o: CMakeFiles/raycasting.dir/flags.make
CMakeFiles/raycasting.dir/src/maze.c.o: /Users/vivo/Code/Challenges/challenges/Raycasting-C/src/maze.c
CMakeFiles/raycasting.dir/src/maze.c.o: CMakeFiles/raycasting.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/vivo/Code/Challenges/challenges/Raycasting-C/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/raycasting.dir/src/maze.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/raycasting.dir/src/maze.c.o -MF CMakeFiles/raycasting.dir/src/maze.c.o.d -o CMakeFiles/raycasting.dir/src/maze.c.o -c /Users/vivo/Code/Challenges/challenges/Raycasting-C/src/maze.c

CMakeFiles/raycasting.dir/src/maze.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/raycasting.dir/src/maze.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/vivo/Code/Challenges/challenges/Raycasting-C/src/maze.c > CMakeFiles/raycasting.dir/src/maze.c.i

CMakeFiles/raycasting.dir/src/maze.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/raycasting.dir/src/maze.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/vivo/Code/Challenges/challenges/Raycasting-C/src/maze.c -o CMakeFiles/raycasting.dir/src/maze.c.s

CMakeFiles/raycasting.dir/src/player.c.o: CMakeFiles/raycasting.dir/flags.make
CMakeFiles/raycasting.dir/src/player.c.o: /Users/vivo/Code/Challenges/challenges/Raycasting-C/src/player.c
CMakeFiles/raycasting.dir/src/player.c.o: CMakeFiles/raycasting.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/vivo/Code/Challenges/challenges/Raycasting-C/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/raycasting.dir/src/player.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/raycasting.dir/src/player.c.o -MF CMakeFiles/raycasting.dir/src/player.c.o.d -o CMakeFiles/raycasting.dir/src/player.c.o -c /Users/vivo/Code/Challenges/challenges/Raycasting-C/src/player.c

CMakeFiles/raycasting.dir/src/player.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/raycasting.dir/src/player.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/vivo/Code/Challenges/challenges/Raycasting-C/src/player.c > CMakeFiles/raycasting.dir/src/player.c.i

CMakeFiles/raycasting.dir/src/player.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/raycasting.dir/src/player.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/vivo/Code/Challenges/challenges/Raycasting-C/src/player.c -o CMakeFiles/raycasting.dir/src/player.c.s

CMakeFiles/raycasting.dir/src/raycasting.c.o: CMakeFiles/raycasting.dir/flags.make
CMakeFiles/raycasting.dir/src/raycasting.c.o: /Users/vivo/Code/Challenges/challenges/Raycasting-C/src/raycasting.c
CMakeFiles/raycasting.dir/src/raycasting.c.o: CMakeFiles/raycasting.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/vivo/Code/Challenges/challenges/Raycasting-C/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/raycasting.dir/src/raycasting.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/raycasting.dir/src/raycasting.c.o -MF CMakeFiles/raycasting.dir/src/raycasting.c.o.d -o CMakeFiles/raycasting.dir/src/raycasting.c.o -c /Users/vivo/Code/Challenges/challenges/Raycasting-C/src/raycasting.c

CMakeFiles/raycasting.dir/src/raycasting.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/raycasting.dir/src/raycasting.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/vivo/Code/Challenges/challenges/Raycasting-C/src/raycasting.c > CMakeFiles/raycasting.dir/src/raycasting.c.i

CMakeFiles/raycasting.dir/src/raycasting.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/raycasting.dir/src/raycasting.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/vivo/Code/Challenges/challenges/Raycasting-C/src/raycasting.c -o CMakeFiles/raycasting.dir/src/raycasting.c.s

CMakeFiles/raycasting.dir/src/renderer.c.o: CMakeFiles/raycasting.dir/flags.make
CMakeFiles/raycasting.dir/src/renderer.c.o: /Users/vivo/Code/Challenges/challenges/Raycasting-C/src/renderer.c
CMakeFiles/raycasting.dir/src/renderer.c.o: CMakeFiles/raycasting.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/vivo/Code/Challenges/challenges/Raycasting-C/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/raycasting.dir/src/renderer.c.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/raycasting.dir/src/renderer.c.o -MF CMakeFiles/raycasting.dir/src/renderer.c.o.d -o CMakeFiles/raycasting.dir/src/renderer.c.o -c /Users/vivo/Code/Challenges/challenges/Raycasting-C/src/renderer.c

CMakeFiles/raycasting.dir/src/renderer.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/raycasting.dir/src/renderer.c.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/vivo/Code/Challenges/challenges/Raycasting-C/src/renderer.c > CMakeFiles/raycasting.dir/src/renderer.c.i

CMakeFiles/raycasting.dir/src/renderer.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/raycasting.dir/src/renderer.c.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/vivo/Code/Challenges/challenges/Raycasting-C/src/renderer.c -o CMakeFiles/raycasting.dir/src/renderer.c.s

# Object files for target raycasting
raycasting_OBJECTS = \
"CMakeFiles/raycasting.dir/src/main.c.o" \
"CMakeFiles/raycasting.dir/src/maze.c.o" \
"CMakeFiles/raycasting.dir/src/player.c.o" \
"CMakeFiles/raycasting.dir/src/raycasting.c.o" \
"CMakeFiles/raycasting.dir/src/renderer.c.o"

# External object files for target raycasting
raycasting_EXTERNAL_OBJECTS =

bin/raycasting: CMakeFiles/raycasting.dir/src/main.c.o
bin/raycasting: CMakeFiles/raycasting.dir/src/maze.c.o
bin/raycasting: CMakeFiles/raycasting.dir/src/player.c.o
bin/raycasting: CMakeFiles/raycasting.dir/src/raycasting.c.o
bin/raycasting: CMakeFiles/raycasting.dir/src/renderer.c.o
bin/raycasting: CMakeFiles/raycasting.dir/build.make
bin/raycasting: /opt/homebrew/Cellar/sdl2/2.30.3/lib/libSDL2.dylib
bin/raycasting: CMakeFiles/raycasting.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/vivo/Code/Challenges/challenges/Raycasting-C/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable bin/raycasting"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/raycasting.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/raycasting.dir/build: bin/raycasting
.PHONY : CMakeFiles/raycasting.dir/build

CMakeFiles/raycasting.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/raycasting.dir/cmake_clean.cmake
.PHONY : CMakeFiles/raycasting.dir/clean

CMakeFiles/raycasting.dir/depend:
	cd /Users/vivo/Code/Challenges/challenges/Raycasting-C/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/vivo/Code/Challenges/challenges/Raycasting-C /Users/vivo/Code/Challenges/challenges/Raycasting-C /Users/vivo/Code/Challenges/challenges/Raycasting-C/build /Users/vivo/Code/Challenges/challenges/Raycasting-C/build /Users/vivo/Code/Challenges/challenges/Raycasting-C/build/CMakeFiles/raycasting.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/raycasting.dir/depend

