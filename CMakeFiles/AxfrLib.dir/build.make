# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/mkoi/mgr/myDig

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/mkoi/mgr/myDig

# Include any dependencies generated for this target.
include CMakeFiles/AxfrLib.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/AxfrLib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/AxfrLib.dir/flags.make

CMakeFiles/AxfrLib.dir/digUtils/digQuery.c.o: CMakeFiles/AxfrLib.dir/flags.make
CMakeFiles/AxfrLib.dir/digUtils/digQuery.c.o: digUtils/digQuery.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mkoi/mgr/myDig/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/AxfrLib.dir/digUtils/digQuery.c.o"
	gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/AxfrLib.dir/digUtils/digQuery.c.o   -c /home/mkoi/mgr/myDig/digUtils/digQuery.c

CMakeFiles/AxfrLib.dir/digUtils/digQuery.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/AxfrLib.dir/digUtils/digQuery.c.i"
	gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/mkoi/mgr/myDig/digUtils/digQuery.c > CMakeFiles/AxfrLib.dir/digUtils/digQuery.c.i

CMakeFiles/AxfrLib.dir/digUtils/digQuery.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/AxfrLib.dir/digUtils/digQuery.c.s"
	gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/mkoi/mgr/myDig/digUtils/digQuery.c -o CMakeFiles/AxfrLib.dir/digUtils/digQuery.c.s

CMakeFiles/AxfrLib.dir/digUtils/digQuery.c.o.requires:

.PHONY : CMakeFiles/AxfrLib.dir/digUtils/digQuery.c.o.requires

CMakeFiles/AxfrLib.dir/digUtils/digQuery.c.o.provides: CMakeFiles/AxfrLib.dir/digUtils/digQuery.c.o.requires
	$(MAKE) -f CMakeFiles/AxfrLib.dir/build.make CMakeFiles/AxfrLib.dir/digUtils/digQuery.c.o.provides.build
.PHONY : CMakeFiles/AxfrLib.dir/digUtils/digQuery.c.o.provides

CMakeFiles/AxfrLib.dir/digUtils/digQuery.c.o.provides.build: CMakeFiles/AxfrLib.dir/digUtils/digQuery.c.o


CMakeFiles/AxfrLib.dir/digUtils/dighost.c.o: CMakeFiles/AxfrLib.dir/flags.make
CMakeFiles/AxfrLib.dir/digUtils/dighost.c.o: digUtils/dighost.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mkoi/mgr/myDig/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/AxfrLib.dir/digUtils/dighost.c.o"
	gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/AxfrLib.dir/digUtils/dighost.c.o   -c /home/mkoi/mgr/myDig/digUtils/dighost.c

CMakeFiles/AxfrLib.dir/digUtils/dighost.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/AxfrLib.dir/digUtils/dighost.c.i"
	gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/mkoi/mgr/myDig/digUtils/dighost.c > CMakeFiles/AxfrLib.dir/digUtils/dighost.c.i

CMakeFiles/AxfrLib.dir/digUtils/dighost.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/AxfrLib.dir/digUtils/dighost.c.s"
	gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/mkoi/mgr/myDig/digUtils/dighost.c -o CMakeFiles/AxfrLib.dir/digUtils/dighost.c.s

CMakeFiles/AxfrLib.dir/digUtils/dighost.c.o.requires:

.PHONY : CMakeFiles/AxfrLib.dir/digUtils/dighost.c.o.requires

CMakeFiles/AxfrLib.dir/digUtils/dighost.c.o.provides: CMakeFiles/AxfrLib.dir/digUtils/dighost.c.o.requires
	$(MAKE) -f CMakeFiles/AxfrLib.dir/build.make CMakeFiles/AxfrLib.dir/digUtils/dighost.c.o.provides.build
.PHONY : CMakeFiles/AxfrLib.dir/digUtils/dighost.c.o.provides

CMakeFiles/AxfrLib.dir/digUtils/dighost.c.o.provides.build: CMakeFiles/AxfrLib.dir/digUtils/dighost.c.o


CMakeFiles/AxfrLib.dir/Scanner/axfrLookup.cpp.o: CMakeFiles/AxfrLib.dir/flags.make
CMakeFiles/AxfrLib.dir/Scanner/axfrLookup.cpp.o: Scanner/axfrLookup.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mkoi/mgr/myDig/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/AxfrLib.dir/Scanner/axfrLookup.cpp.o"
	g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AxfrLib.dir/Scanner/axfrLookup.cpp.o -c /home/mkoi/mgr/myDig/Scanner/axfrLookup.cpp

CMakeFiles/AxfrLib.dir/Scanner/axfrLookup.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AxfrLib.dir/Scanner/axfrLookup.cpp.i"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mkoi/mgr/myDig/Scanner/axfrLookup.cpp > CMakeFiles/AxfrLib.dir/Scanner/axfrLookup.cpp.i

CMakeFiles/AxfrLib.dir/Scanner/axfrLookup.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AxfrLib.dir/Scanner/axfrLookup.cpp.s"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mkoi/mgr/myDig/Scanner/axfrLookup.cpp -o CMakeFiles/AxfrLib.dir/Scanner/axfrLookup.cpp.s

CMakeFiles/AxfrLib.dir/Scanner/axfrLookup.cpp.o.requires:

.PHONY : CMakeFiles/AxfrLib.dir/Scanner/axfrLookup.cpp.o.requires

CMakeFiles/AxfrLib.dir/Scanner/axfrLookup.cpp.o.provides: CMakeFiles/AxfrLib.dir/Scanner/axfrLookup.cpp.o.requires
	$(MAKE) -f CMakeFiles/AxfrLib.dir/build.make CMakeFiles/AxfrLib.dir/Scanner/axfrLookup.cpp.o.provides.build
.PHONY : CMakeFiles/AxfrLib.dir/Scanner/axfrLookup.cpp.o.provides

CMakeFiles/AxfrLib.dir/Scanner/axfrLookup.cpp.o.provides.build: CMakeFiles/AxfrLib.dir/Scanner/axfrLookup.cpp.o


CMakeFiles/AxfrLib.dir/digUtils/dig_parser.c.o: CMakeFiles/AxfrLib.dir/flags.make
CMakeFiles/AxfrLib.dir/digUtils/dig_parser.c.o: digUtils/dig_parser.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mkoi/mgr/myDig/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/AxfrLib.dir/digUtils/dig_parser.c.o"
	gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/AxfrLib.dir/digUtils/dig_parser.c.o   -c /home/mkoi/mgr/myDig/digUtils/dig_parser.c

CMakeFiles/AxfrLib.dir/digUtils/dig_parser.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/AxfrLib.dir/digUtils/dig_parser.c.i"
	gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/mkoi/mgr/myDig/digUtils/dig_parser.c > CMakeFiles/AxfrLib.dir/digUtils/dig_parser.c.i

CMakeFiles/AxfrLib.dir/digUtils/dig_parser.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/AxfrLib.dir/digUtils/dig_parser.c.s"
	gcc  $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/mkoi/mgr/myDig/digUtils/dig_parser.c -o CMakeFiles/AxfrLib.dir/digUtils/dig_parser.c.s

CMakeFiles/AxfrLib.dir/digUtils/dig_parser.c.o.requires:

.PHONY : CMakeFiles/AxfrLib.dir/digUtils/dig_parser.c.o.requires

CMakeFiles/AxfrLib.dir/digUtils/dig_parser.c.o.provides: CMakeFiles/AxfrLib.dir/digUtils/dig_parser.c.o.requires
	$(MAKE) -f CMakeFiles/AxfrLib.dir/build.make CMakeFiles/AxfrLib.dir/digUtils/dig_parser.c.o.provides.build
.PHONY : CMakeFiles/AxfrLib.dir/digUtils/dig_parser.c.o.provides

CMakeFiles/AxfrLib.dir/digUtils/dig_parser.c.o.provides.build: CMakeFiles/AxfrLib.dir/digUtils/dig_parser.c.o


CMakeFiles/AxfrLib.dir/Scanner/InputReader.cpp.o: CMakeFiles/AxfrLib.dir/flags.make
CMakeFiles/AxfrLib.dir/Scanner/InputReader.cpp.o: Scanner/InputReader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mkoi/mgr/myDig/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/AxfrLib.dir/Scanner/InputReader.cpp.o"
	g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AxfrLib.dir/Scanner/InputReader.cpp.o -c /home/mkoi/mgr/myDig/Scanner/InputReader.cpp

CMakeFiles/AxfrLib.dir/Scanner/InputReader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AxfrLib.dir/Scanner/InputReader.cpp.i"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mkoi/mgr/myDig/Scanner/InputReader.cpp > CMakeFiles/AxfrLib.dir/Scanner/InputReader.cpp.i

CMakeFiles/AxfrLib.dir/Scanner/InputReader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AxfrLib.dir/Scanner/InputReader.cpp.s"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mkoi/mgr/myDig/Scanner/InputReader.cpp -o CMakeFiles/AxfrLib.dir/Scanner/InputReader.cpp.s

CMakeFiles/AxfrLib.dir/Scanner/InputReader.cpp.o.requires:

.PHONY : CMakeFiles/AxfrLib.dir/Scanner/InputReader.cpp.o.requires

CMakeFiles/AxfrLib.dir/Scanner/InputReader.cpp.o.provides: CMakeFiles/AxfrLib.dir/Scanner/InputReader.cpp.o.requires
	$(MAKE) -f CMakeFiles/AxfrLib.dir/build.make CMakeFiles/AxfrLib.dir/Scanner/InputReader.cpp.o.provides.build
.PHONY : CMakeFiles/AxfrLib.dir/Scanner/InputReader.cpp.o.provides

CMakeFiles/AxfrLib.dir/Scanner/InputReader.cpp.o.provides.build: CMakeFiles/AxfrLib.dir/Scanner/InputReader.cpp.o


CMakeFiles/AxfrLib.dir/axfrlib.cpp.o: CMakeFiles/AxfrLib.dir/flags.make
CMakeFiles/AxfrLib.dir/axfrlib.cpp.o: axfrlib.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/mkoi/mgr/myDig/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/AxfrLib.dir/axfrlib.cpp.o"
	g++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/AxfrLib.dir/axfrlib.cpp.o -c /home/mkoi/mgr/myDig/axfrlib.cpp

CMakeFiles/AxfrLib.dir/axfrlib.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/AxfrLib.dir/axfrlib.cpp.i"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/mkoi/mgr/myDig/axfrlib.cpp > CMakeFiles/AxfrLib.dir/axfrlib.cpp.i

CMakeFiles/AxfrLib.dir/axfrlib.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/AxfrLib.dir/axfrlib.cpp.s"
	g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/mkoi/mgr/myDig/axfrlib.cpp -o CMakeFiles/AxfrLib.dir/axfrlib.cpp.s

CMakeFiles/AxfrLib.dir/axfrlib.cpp.o.requires:

.PHONY : CMakeFiles/AxfrLib.dir/axfrlib.cpp.o.requires

CMakeFiles/AxfrLib.dir/axfrlib.cpp.o.provides: CMakeFiles/AxfrLib.dir/axfrlib.cpp.o.requires
	$(MAKE) -f CMakeFiles/AxfrLib.dir/build.make CMakeFiles/AxfrLib.dir/axfrlib.cpp.o.provides.build
.PHONY : CMakeFiles/AxfrLib.dir/axfrlib.cpp.o.provides

CMakeFiles/AxfrLib.dir/axfrlib.cpp.o.provides.build: CMakeFiles/AxfrLib.dir/axfrlib.cpp.o


# Object files for target AxfrLib
AxfrLib_OBJECTS = \
"CMakeFiles/AxfrLib.dir/digUtils/digQuery.c.o" \
"CMakeFiles/AxfrLib.dir/digUtils/dighost.c.o" \
"CMakeFiles/AxfrLib.dir/Scanner/axfrLookup.cpp.o" \
"CMakeFiles/AxfrLib.dir/digUtils/dig_parser.c.o" \
"CMakeFiles/AxfrLib.dir/Scanner/InputReader.cpp.o" \
"CMakeFiles/AxfrLib.dir/axfrlib.cpp.o"

# External object files for target AxfrLib
AxfrLib_EXTERNAL_OBJECTS =

build/lib/libAxfrLib.so: CMakeFiles/AxfrLib.dir/digUtils/digQuery.c.o
build/lib/libAxfrLib.so: CMakeFiles/AxfrLib.dir/digUtils/dighost.c.o
build/lib/libAxfrLib.so: CMakeFiles/AxfrLib.dir/Scanner/axfrLookup.cpp.o
build/lib/libAxfrLib.so: CMakeFiles/AxfrLib.dir/digUtils/dig_parser.c.o
build/lib/libAxfrLib.so: CMakeFiles/AxfrLib.dir/Scanner/InputReader.cpp.o
build/lib/libAxfrLib.so: CMakeFiles/AxfrLib.dir/axfrlib.cpp.o
build/lib/libAxfrLib.so: CMakeFiles/AxfrLib.dir/build.make
build/lib/libAxfrLib.so: bind_lib/lib/dns/libdns.a
build/lib/libAxfrLib.so: bind_lib/lib/isccfg/libisccfg.a
build/lib/libAxfrLib.so: bind_lib/lib/isc/libisc-nosymtbl.a
build/lib/libAxfrLib.so: bind_lib/lib/lwres/liblwres.a
build/lib/libAxfrLib.so: bind_lib/lib/bind9/libbind9.a
build/lib/libAxfrLib.so: CMakeFiles/AxfrLib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/mkoi/mgr/myDig/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX shared library build/lib/libAxfrLib.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/AxfrLib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/AxfrLib.dir/build: build/lib/libAxfrLib.so

.PHONY : CMakeFiles/AxfrLib.dir/build

CMakeFiles/AxfrLib.dir/requires: CMakeFiles/AxfrLib.dir/digUtils/digQuery.c.o.requires
CMakeFiles/AxfrLib.dir/requires: CMakeFiles/AxfrLib.dir/digUtils/dighost.c.o.requires
CMakeFiles/AxfrLib.dir/requires: CMakeFiles/AxfrLib.dir/Scanner/axfrLookup.cpp.o.requires
CMakeFiles/AxfrLib.dir/requires: CMakeFiles/AxfrLib.dir/digUtils/dig_parser.c.o.requires
CMakeFiles/AxfrLib.dir/requires: CMakeFiles/AxfrLib.dir/Scanner/InputReader.cpp.o.requires
CMakeFiles/AxfrLib.dir/requires: CMakeFiles/AxfrLib.dir/axfrlib.cpp.o.requires

.PHONY : CMakeFiles/AxfrLib.dir/requires

CMakeFiles/AxfrLib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/AxfrLib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/AxfrLib.dir/clean

CMakeFiles/AxfrLib.dir/depend:
	cd /home/mkoi/mgr/myDig && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/mkoi/mgr/myDig /home/mkoi/mgr/myDig /home/mkoi/mgr/myDig /home/mkoi/mgr/myDig /home/mkoi/mgr/myDig/CMakeFiles/AxfrLib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/AxfrLib.dir/depend

