# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_SOURCE_DIR = /home/ilia/repos/lcd_st7066

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/ilia/repos/lcd_st7066/build

# Include any dependencies generated for this target.
include src/uapi/uapi_common/CMakeFiles/uapi_common.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include src/uapi/uapi_common/CMakeFiles/uapi_common.dir/compiler_depend.make

# Include the progress variables for this target.
include src/uapi/uapi_common/CMakeFiles/uapi_common.dir/progress.make

# Include the compile flags for this target's objects.
include src/uapi/uapi_common/CMakeFiles/uapi_common.dir/flags.make

src/uapi/uapi_common/CMakeFiles/uapi_common.dir/uapi_common.c.o: src/uapi/uapi_common/CMakeFiles/uapi_common.dir/flags.make
src/uapi/uapi_common/CMakeFiles/uapi_common.dir/uapi_common.c.o: /home/ilia/repos/lcd_st7066/src/uapi/uapi_common/uapi_common.c
src/uapi/uapi_common/CMakeFiles/uapi_common.dir/uapi_common.c.o: src/uapi/uapi_common/CMakeFiles/uapi_common.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/ilia/repos/lcd_st7066/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object src/uapi/uapi_common/CMakeFiles/uapi_common.dir/uapi_common.c.o"
	cd /home/ilia/repos/lcd_st7066/build/src/uapi/uapi_common && /usr/bin/arm-none-eabi-gcc --sysroot=/usr/arm-none-eabi $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT src/uapi/uapi_common/CMakeFiles/uapi_common.dir/uapi_common.c.o -MF CMakeFiles/uapi_common.dir/uapi_common.c.o.d -o CMakeFiles/uapi_common.dir/uapi_common.c.o -c /home/ilia/repos/lcd_st7066/src/uapi/uapi_common/uapi_common.c

src/uapi/uapi_common/CMakeFiles/uapi_common.dir/uapi_common.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/uapi_common.dir/uapi_common.c.i"
	cd /home/ilia/repos/lcd_st7066/build/src/uapi/uapi_common && /usr/bin/arm-none-eabi-gcc --sysroot=/usr/arm-none-eabi $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/ilia/repos/lcd_st7066/src/uapi/uapi_common/uapi_common.c > CMakeFiles/uapi_common.dir/uapi_common.c.i

src/uapi/uapi_common/CMakeFiles/uapi_common.dir/uapi_common.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/uapi_common.dir/uapi_common.c.s"
	cd /home/ilia/repos/lcd_st7066/build/src/uapi/uapi_common && /usr/bin/arm-none-eabi-gcc --sysroot=/usr/arm-none-eabi $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/ilia/repos/lcd_st7066/src/uapi/uapi_common/uapi_common.c -o CMakeFiles/uapi_common.dir/uapi_common.c.s

# Object files for target uapi_common
uapi_common_OBJECTS = \
"CMakeFiles/uapi_common.dir/uapi_common.c.o"

# External object files for target uapi_common
uapi_common_EXTERNAL_OBJECTS =

lib/libuapi_common.a: src/uapi/uapi_common/CMakeFiles/uapi_common.dir/uapi_common.c.o
lib/libuapi_common.a: src/uapi/uapi_common/CMakeFiles/uapi_common.dir/build.make
lib/libuapi_common.a: src/uapi/uapi_common/CMakeFiles/uapi_common.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/ilia/repos/lcd_st7066/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library ../../../lib/libuapi_common.a"
	cd /home/ilia/repos/lcd_st7066/build/src/uapi/uapi_common && $(CMAKE_COMMAND) -P CMakeFiles/uapi_common.dir/cmake_clean_target.cmake
	cd /home/ilia/repos/lcd_st7066/build/src/uapi/uapi_common && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/uapi_common.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/uapi/uapi_common/CMakeFiles/uapi_common.dir/build: lib/libuapi_common.a
.PHONY : src/uapi/uapi_common/CMakeFiles/uapi_common.dir/build

src/uapi/uapi_common/CMakeFiles/uapi_common.dir/clean:
	cd /home/ilia/repos/lcd_st7066/build/src/uapi/uapi_common && $(CMAKE_COMMAND) -P CMakeFiles/uapi_common.dir/cmake_clean.cmake
.PHONY : src/uapi/uapi_common/CMakeFiles/uapi_common.dir/clean

src/uapi/uapi_common/CMakeFiles/uapi_common.dir/depend:
	cd /home/ilia/repos/lcd_st7066/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/ilia/repos/lcd_st7066 /home/ilia/repos/lcd_st7066/src/uapi/uapi_common /home/ilia/repos/lcd_st7066/build /home/ilia/repos/lcd_st7066/build/src/uapi/uapi_common /home/ilia/repos/lcd_st7066/build/src/uapi/uapi_common/CMakeFiles/uapi_common.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : src/uapi/uapi_common/CMakeFiles/uapi_common.dir/depend

