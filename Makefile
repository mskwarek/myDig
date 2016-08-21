# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

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
CMAKE_SOURCE_DIR = /home/marcin/ClionProjects/myDig

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/marcin/ClionProjects/myDig

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running interactive CMake command-line interface..."
	/usr/bin/cmake -i .
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache
.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache
.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/marcin/ClionProjects/myDig/CMakeFiles /home/marcin/ClionProjects/myDig/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/marcin/ClionProjects/myDig/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean
.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named AxfrLib

# Build rule for target.
AxfrLib: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 AxfrLib
.PHONY : AxfrLib

# fast build rule for target.
AxfrLib/fast:
	$(MAKE) -f CMakeFiles/AxfrLib.dir/build.make CMakeFiles/AxfrLib.dir/build
.PHONY : AxfrLib/fast

#=============================================================================
# Target rules for targets named myDig

# Build rule for target.
myDig: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 myDig
.PHONY : myDig

# fast build rule for target.
myDig/fast:
	$(MAKE) -f CMakeFiles/myDig.dir/build.make CMakeFiles/myDig.dir/build
.PHONY : myDig/fast

GeneralUtils/ms_response_list.o: GeneralUtils/ms_response_list.c.o
.PHONY : GeneralUtils/ms_response_list.o

# target to build an object file
GeneralUtils/ms_response_list.c.o:
	$(MAKE) -f CMakeFiles/AxfrLib.dir/build.make CMakeFiles/AxfrLib.dir/GeneralUtils/ms_response_list.c.o
	$(MAKE) -f CMakeFiles/myDig.dir/build.make CMakeFiles/myDig.dir/GeneralUtils/ms_response_list.c.o
.PHONY : GeneralUtils/ms_response_list.c.o

GeneralUtils/ms_response_list.i: GeneralUtils/ms_response_list.c.i
.PHONY : GeneralUtils/ms_response_list.i

# target to preprocess a source file
GeneralUtils/ms_response_list.c.i:
	$(MAKE) -f CMakeFiles/AxfrLib.dir/build.make CMakeFiles/AxfrLib.dir/GeneralUtils/ms_response_list.c.i
	$(MAKE) -f CMakeFiles/myDig.dir/build.make CMakeFiles/myDig.dir/GeneralUtils/ms_response_list.c.i
.PHONY : GeneralUtils/ms_response_list.c.i

GeneralUtils/ms_response_list.s: GeneralUtils/ms_response_list.c.s
.PHONY : GeneralUtils/ms_response_list.s

# target to generate assembly for a file
GeneralUtils/ms_response_list.c.s:
	$(MAKE) -f CMakeFiles/AxfrLib.dir/build.make CMakeFiles/AxfrLib.dir/GeneralUtils/ms_response_list.c.s
	$(MAKE) -f CMakeFiles/myDig.dir/build.make CMakeFiles/myDig.dir/GeneralUtils/ms_response_list.c.s
.PHONY : GeneralUtils/ms_response_list.c.s

Scanner/InputReader.o: Scanner/InputReader.cpp.o
.PHONY : Scanner/InputReader.o

# target to build an object file
Scanner/InputReader.cpp.o:
	$(MAKE) -f CMakeFiles/AxfrLib.dir/build.make CMakeFiles/AxfrLib.dir/Scanner/InputReader.cpp.o
	$(MAKE) -f CMakeFiles/myDig.dir/build.make CMakeFiles/myDig.dir/Scanner/InputReader.cpp.o
.PHONY : Scanner/InputReader.cpp.o

Scanner/InputReader.i: Scanner/InputReader.cpp.i
.PHONY : Scanner/InputReader.i

# target to preprocess a source file
Scanner/InputReader.cpp.i:
	$(MAKE) -f CMakeFiles/AxfrLib.dir/build.make CMakeFiles/AxfrLib.dir/Scanner/InputReader.cpp.i
	$(MAKE) -f CMakeFiles/myDig.dir/build.make CMakeFiles/myDig.dir/Scanner/InputReader.cpp.i
.PHONY : Scanner/InputReader.cpp.i

Scanner/InputReader.s: Scanner/InputReader.cpp.s
.PHONY : Scanner/InputReader.s

# target to generate assembly for a file
Scanner/InputReader.cpp.s:
	$(MAKE) -f CMakeFiles/AxfrLib.dir/build.make CMakeFiles/AxfrLib.dir/Scanner/InputReader.cpp.s
	$(MAKE) -f CMakeFiles/myDig.dir/build.make CMakeFiles/myDig.dir/Scanner/InputReader.cpp.s
.PHONY : Scanner/InputReader.cpp.s

Scanner/axfrLookup.o: Scanner/axfrLookup.cpp.o
.PHONY : Scanner/axfrLookup.o

# target to build an object file
Scanner/axfrLookup.cpp.o:
	$(MAKE) -f CMakeFiles/AxfrLib.dir/build.make CMakeFiles/AxfrLib.dir/Scanner/axfrLookup.cpp.o
	$(MAKE) -f CMakeFiles/myDig.dir/build.make CMakeFiles/myDig.dir/Scanner/axfrLookup.cpp.o
.PHONY : Scanner/axfrLookup.cpp.o

Scanner/axfrLookup.i: Scanner/axfrLookup.cpp.i
.PHONY : Scanner/axfrLookup.i

# target to preprocess a source file
Scanner/axfrLookup.cpp.i:
	$(MAKE) -f CMakeFiles/AxfrLib.dir/build.make CMakeFiles/AxfrLib.dir/Scanner/axfrLookup.cpp.i
	$(MAKE) -f CMakeFiles/myDig.dir/build.make CMakeFiles/myDig.dir/Scanner/axfrLookup.cpp.i
.PHONY : Scanner/axfrLookup.cpp.i

Scanner/axfrLookup.s: Scanner/axfrLookup.cpp.s
.PHONY : Scanner/axfrLookup.s

# target to generate assembly for a file
Scanner/axfrLookup.cpp.s:
	$(MAKE) -f CMakeFiles/AxfrLib.dir/build.make CMakeFiles/AxfrLib.dir/Scanner/axfrLookup.cpp.s
	$(MAKE) -f CMakeFiles/myDig.dir/build.make CMakeFiles/myDig.dir/Scanner/axfrLookup.cpp.s
.PHONY : Scanner/axfrLookup.cpp.s

axfrlib.o: axfrlib.cpp.o
.PHONY : axfrlib.o

# target to build an object file
axfrlib.cpp.o:
	$(MAKE) -f CMakeFiles/AxfrLib.dir/build.make CMakeFiles/AxfrLib.dir/axfrlib.cpp.o
.PHONY : axfrlib.cpp.o

axfrlib.i: axfrlib.cpp.i
.PHONY : axfrlib.i

# target to preprocess a source file
axfrlib.cpp.i:
	$(MAKE) -f CMakeFiles/AxfrLib.dir/build.make CMakeFiles/AxfrLib.dir/axfrlib.cpp.i
.PHONY : axfrlib.cpp.i

axfrlib.s: axfrlib.cpp.s
.PHONY : axfrlib.s

# target to generate assembly for a file
axfrlib.cpp.s:
	$(MAKE) -f CMakeFiles/AxfrLib.dir/build.make CMakeFiles/AxfrLib.dir/axfrlib.cpp.s
.PHONY : axfrlib.cpp.s

digUtils/digQuery.o: digUtils/digQuery.c.o
.PHONY : digUtils/digQuery.o

# target to build an object file
digUtils/digQuery.c.o:
	$(MAKE) -f CMakeFiles/AxfrLib.dir/build.make CMakeFiles/AxfrLib.dir/digUtils/digQuery.c.o
	$(MAKE) -f CMakeFiles/myDig.dir/build.make CMakeFiles/myDig.dir/digUtils/digQuery.c.o
.PHONY : digUtils/digQuery.c.o

digUtils/digQuery.i: digUtils/digQuery.c.i
.PHONY : digUtils/digQuery.i

# target to preprocess a source file
digUtils/digQuery.c.i:
	$(MAKE) -f CMakeFiles/AxfrLib.dir/build.make CMakeFiles/AxfrLib.dir/digUtils/digQuery.c.i
	$(MAKE) -f CMakeFiles/myDig.dir/build.make CMakeFiles/myDig.dir/digUtils/digQuery.c.i
.PHONY : digUtils/digQuery.c.i

digUtils/digQuery.s: digUtils/digQuery.c.s
.PHONY : digUtils/digQuery.s

# target to generate assembly for a file
digUtils/digQuery.c.s:
	$(MAKE) -f CMakeFiles/AxfrLib.dir/build.make CMakeFiles/AxfrLib.dir/digUtils/digQuery.c.s
	$(MAKE) -f CMakeFiles/myDig.dir/build.make CMakeFiles/myDig.dir/digUtils/digQuery.c.s
.PHONY : digUtils/digQuery.c.s

digUtils/dig_parser.o: digUtils/dig_parser.c.o
.PHONY : digUtils/dig_parser.o

# target to build an object file
digUtils/dig_parser.c.o:
	$(MAKE) -f CMakeFiles/AxfrLib.dir/build.make CMakeFiles/AxfrLib.dir/digUtils/dig_parser.c.o
	$(MAKE) -f CMakeFiles/myDig.dir/build.make CMakeFiles/myDig.dir/digUtils/dig_parser.c.o
.PHONY : digUtils/dig_parser.c.o

digUtils/dig_parser.i: digUtils/dig_parser.c.i
.PHONY : digUtils/dig_parser.i

# target to preprocess a source file
digUtils/dig_parser.c.i:
	$(MAKE) -f CMakeFiles/AxfrLib.dir/build.make CMakeFiles/AxfrLib.dir/digUtils/dig_parser.c.i
	$(MAKE) -f CMakeFiles/myDig.dir/build.make CMakeFiles/myDig.dir/digUtils/dig_parser.c.i
.PHONY : digUtils/dig_parser.c.i

digUtils/dig_parser.s: digUtils/dig_parser.c.s
.PHONY : digUtils/dig_parser.s

# target to generate assembly for a file
digUtils/dig_parser.c.s:
	$(MAKE) -f CMakeFiles/AxfrLib.dir/build.make CMakeFiles/AxfrLib.dir/digUtils/dig_parser.c.s
	$(MAKE) -f CMakeFiles/myDig.dir/build.make CMakeFiles/myDig.dir/digUtils/dig_parser.c.s
.PHONY : digUtils/dig_parser.c.s

digUtils/dighost.o: digUtils/dighost.c.o
.PHONY : digUtils/dighost.o

# target to build an object file
digUtils/dighost.c.o:
	$(MAKE) -f CMakeFiles/AxfrLib.dir/build.make CMakeFiles/AxfrLib.dir/digUtils/dighost.c.o
	$(MAKE) -f CMakeFiles/myDig.dir/build.make CMakeFiles/myDig.dir/digUtils/dighost.c.o
.PHONY : digUtils/dighost.c.o

digUtils/dighost.i: digUtils/dighost.c.i
.PHONY : digUtils/dighost.i

# target to preprocess a source file
digUtils/dighost.c.i:
	$(MAKE) -f CMakeFiles/AxfrLib.dir/build.make CMakeFiles/AxfrLib.dir/digUtils/dighost.c.i
	$(MAKE) -f CMakeFiles/myDig.dir/build.make CMakeFiles/myDig.dir/digUtils/dighost.c.i
.PHONY : digUtils/dighost.c.i

digUtils/dighost.s: digUtils/dighost.c.s
.PHONY : digUtils/dighost.s

# target to generate assembly for a file
digUtils/dighost.c.s:
	$(MAKE) -f CMakeFiles/AxfrLib.dir/build.make CMakeFiles/AxfrLib.dir/digUtils/dighost.c.s
	$(MAKE) -f CMakeFiles/myDig.dir/build.make CMakeFiles/myDig.dir/digUtils/dighost.c.s
.PHONY : digUtils/dighost.c.s

main.o: main.cpp.o
.PHONY : main.o

# target to build an object file
main.cpp.o:
	$(MAKE) -f CMakeFiles/myDig.dir/build.make CMakeFiles/myDig.dir/main.cpp.o
.PHONY : main.cpp.o

main.i: main.cpp.i
.PHONY : main.i

# target to preprocess a source file
main.cpp.i:
	$(MAKE) -f CMakeFiles/myDig.dir/build.make CMakeFiles/myDig.dir/main.cpp.i
.PHONY : main.cpp.i

main.s: main.cpp.s
.PHONY : main.s

# target to generate assembly for a file
main.cpp.s:
	$(MAKE) -f CMakeFiles/myDig.dir/build.make CMakeFiles/myDig.dir/main.cpp.s
.PHONY : main.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... AxfrLib"
	@echo "... edit_cache"
	@echo "... myDig"
	@echo "... rebuild_cache"
	@echo "... GeneralUtils/ms_response_list.o"
	@echo "... GeneralUtils/ms_response_list.i"
	@echo "... GeneralUtils/ms_response_list.s"
	@echo "... Scanner/InputReader.o"
	@echo "... Scanner/InputReader.i"
	@echo "... Scanner/InputReader.s"
	@echo "... Scanner/axfrLookup.o"
	@echo "... Scanner/axfrLookup.i"
	@echo "... Scanner/axfrLookup.s"
	@echo "... axfrlib.o"
	@echo "... axfrlib.i"
	@echo "... axfrlib.s"
	@echo "... digUtils/digQuery.o"
	@echo "... digUtils/digQuery.i"
	@echo "... digUtils/digQuery.s"
	@echo "... digUtils/dig_parser.o"
	@echo "... digUtils/dig_parser.i"
	@echo "... digUtils/dig_parser.s"
	@echo "... digUtils/dighost.o"
	@echo "... digUtils/dighost.i"
	@echo "... digUtils/dighost.s"
	@echo "... main.o"
	@echo "... main.i"
	@echo "... main.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

