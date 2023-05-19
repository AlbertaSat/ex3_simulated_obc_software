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
CMAKE_SOURCE_DIR = /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/BurnwireTester

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/BurnwireTester/build-fprime-automatic-native

# Utility rule file for Svc_Cycle_impl.

# Include the progress variables for this target.
include F-Prime/Svc/Cycle/CMakeFiles/Svc_Cycle_impl.dir/progress.make

F-Prime/Svc/Cycle/CMakeFiles/Svc_Cycle_impl: F-Prime/Svc/Cycle/CyclePortAi.xml
F-Prime/Svc/Cycle/CMakeFiles/Svc_Cycle_impl: F-Prime/Svc/Cycle/CyclePortAc.cpp
F-Prime/Svc/Cycle/CMakeFiles/Svc_Cycle_impl: F-Prime/Svc/Cycle/CyclePortAc.hpp


F-Prime/Svc/Cycle/CyclePortAi.xml: /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/Svc/Cycle/Cycle.fpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/BurnwireTester/build-fprime-automatic-native/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating CyclePortAi.xml"
	cd /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/BurnwireTester/build-fprime-automatic-native/F-Prime/Svc/Cycle && /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/venv/bin/fpp-to-xml -d /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/BurnwireTester/build-fprime-automatic-native/F-Prime/Svc/Cycle /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/Svc/Cycle/Cycle.fpp -p /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime,/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test

F-Prime/Svc/Cycle/CyclePortAc.cpp: /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/Svc/Cycle/Cycle.fpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/BurnwireTester/build-fprime-automatic-native/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating CyclePortAc.cpp, CyclePortAc.hpp"
	cd /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/BurnwireTester/build-fprime-automatic-native/F-Prime/Svc/Cycle && /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/venv/bin/fpp-to-cpp -d /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/BurnwireTester/build-fprime-automatic-native/F-Prime/Svc/Cycle /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/Svc/Cycle/Cycle.fpp -p /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime,/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test,/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/BurnwireTester/build-fprime-automatic-native

F-Prime/Svc/Cycle/CyclePortAc.hpp: F-Prime/Svc/Cycle/CyclePortAc.cpp
	@$(CMAKE_COMMAND) -E touch_nocreate F-Prime/Svc/Cycle/CyclePortAc.hpp

Svc_Cycle_impl: F-Prime/Svc/Cycle/CMakeFiles/Svc_Cycle_impl
Svc_Cycle_impl: F-Prime/Svc/Cycle/CyclePortAi.xml
Svc_Cycle_impl: F-Prime/Svc/Cycle/CyclePortAc.cpp
Svc_Cycle_impl: F-Prime/Svc/Cycle/CyclePortAc.hpp
Svc_Cycle_impl: F-Prime/Svc/Cycle/CMakeFiles/Svc_Cycle_impl.dir/build.make

.PHONY : Svc_Cycle_impl

# Rule to build all files generated by this target.
F-Prime/Svc/Cycle/CMakeFiles/Svc_Cycle_impl.dir/build: Svc_Cycle_impl

.PHONY : F-Prime/Svc/Cycle/CMakeFiles/Svc_Cycle_impl.dir/build

F-Prime/Svc/Cycle/CMakeFiles/Svc_Cycle_impl.dir/clean:
	cd /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/BurnwireTester/build-fprime-automatic-native/F-Prime/Svc/Cycle && $(CMAKE_COMMAND) -P CMakeFiles/Svc_Cycle_impl.dir/cmake_clean.cmake
.PHONY : F-Prime/Svc/Cycle/CMakeFiles/Svc_Cycle_impl.dir/clean

F-Prime/Svc/Cycle/CMakeFiles/Svc_Cycle_impl.dir/depend:
	cd /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/BurnwireTester/build-fprime-automatic-native && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/BurnwireTester /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/Svc/Cycle /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/BurnwireTester/build-fprime-automatic-native /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/BurnwireTester/build-fprime-automatic-native/F-Prime/Svc/Cycle /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/BurnwireTester/build-fprime-automatic-native/F-Prime/Svc/Cycle/CMakeFiles/Svc_Cycle_impl.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : F-Prime/Svc/Cycle/CMakeFiles/Svc_Cycle_impl.dir/depend
