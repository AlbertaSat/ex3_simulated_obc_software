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

# Include any dependencies generated for this target.
include F-Prime/Fw/Comp/CMakeFiles/Fw_Comp.dir/depend.make

# Include the progress variables for this target.
include F-Prime/Fw/Comp/CMakeFiles/Fw_Comp.dir/progress.make

# Include the compile flags for this target's objects.
include F-Prime/Fw/Comp/CMakeFiles/Fw_Comp.dir/flags.make

F-Prime/Fw/Comp/CMakeFiles/Fw_Comp.dir/PassiveComponentBase.cpp.o: F-Prime/Fw/Comp/CMakeFiles/Fw_Comp.dir/flags.make
F-Prime/Fw/Comp/CMakeFiles/Fw_Comp.dir/PassiveComponentBase.cpp.o: /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/Fw/Comp/PassiveComponentBase.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/BurnwireTester/build-fprime-automatic-native/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object F-Prime/Fw/Comp/CMakeFiles/Fw_Comp.dir/PassiveComponentBase.cpp.o"
	cd /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/BurnwireTester/build-fprime-automatic-native/F-Prime/Fw/Comp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -DASSERT_FILE_ID=0xcd17a70d -DASSERT_RELATIVE_PATH='"Fw/Comp/PassiveComponentBase.cpp"' -o CMakeFiles/Fw_Comp.dir/PassiveComponentBase.cpp.o -c /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/Fw/Comp/PassiveComponentBase.cpp

F-Prime/Fw/Comp/CMakeFiles/Fw_Comp.dir/PassiveComponentBase.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Fw_Comp.dir/PassiveComponentBase.cpp.i"
	cd /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/BurnwireTester/build-fprime-automatic-native/F-Prime/Fw/Comp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -DASSERT_FILE_ID=0xcd17a70d -DASSERT_RELATIVE_PATH='"Fw/Comp/PassiveComponentBase.cpp"' -E /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/Fw/Comp/PassiveComponentBase.cpp > CMakeFiles/Fw_Comp.dir/PassiveComponentBase.cpp.i

F-Prime/Fw/Comp/CMakeFiles/Fw_Comp.dir/PassiveComponentBase.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Fw_Comp.dir/PassiveComponentBase.cpp.s"
	cd /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/BurnwireTester/build-fprime-automatic-native/F-Prime/Fw/Comp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -DASSERT_FILE_ID=0xcd17a70d -DASSERT_RELATIVE_PATH='"Fw/Comp/PassiveComponentBase.cpp"' -S /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/Fw/Comp/PassiveComponentBase.cpp -o CMakeFiles/Fw_Comp.dir/PassiveComponentBase.cpp.s

# Object files for target Fw_Comp
Fw_Comp_OBJECTS = \
"CMakeFiles/Fw_Comp.dir/PassiveComponentBase.cpp.o"

# External object files for target Fw_Comp
Fw_Comp_EXTERNAL_OBJECTS =

lib/Linux/libFw_Comp.a: F-Prime/Fw/Comp/CMakeFiles/Fw_Comp.dir/PassiveComponentBase.cpp.o
lib/Linux/libFw_Comp.a: F-Prime/Fw/Comp/CMakeFiles/Fw_Comp.dir/build.make
lib/Linux/libFw_Comp.a: F-Prime/Fw/Comp/CMakeFiles/Fw_Comp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/BurnwireTester/build-fprime-automatic-native/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library ../../../lib/Linux/libFw_Comp.a"
	cd /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/BurnwireTester/build-fprime-automatic-native/F-Prime/Fw/Comp && $(CMAKE_COMMAND) -P CMakeFiles/Fw_Comp.dir/cmake_clean_target.cmake
	cd /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/BurnwireTester/build-fprime-automatic-native/F-Prime/Fw/Comp && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Fw_Comp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
F-Prime/Fw/Comp/CMakeFiles/Fw_Comp.dir/build: lib/Linux/libFw_Comp.a

.PHONY : F-Prime/Fw/Comp/CMakeFiles/Fw_Comp.dir/build

F-Prime/Fw/Comp/CMakeFiles/Fw_Comp.dir/clean:
	cd /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/BurnwireTester/build-fprime-automatic-native/F-Prime/Fw/Comp && $(CMAKE_COMMAND) -P CMakeFiles/Fw_Comp.dir/cmake_clean.cmake
.PHONY : F-Prime/Fw/Comp/CMakeFiles/Fw_Comp.dir/clean

F-Prime/Fw/Comp/CMakeFiles/Fw_Comp.dir/depend:
	cd /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/BurnwireTester/build-fprime-automatic-native && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/BurnwireTester /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/Fw/Comp /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/BurnwireTester/build-fprime-automatic-native /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/BurnwireTester/build-fprime-automatic-native/F-Prime/Fw/Comp /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/BurnwireTester/build-fprime-automatic-native/F-Prime/Fw/Comp/CMakeFiles/Fw_Comp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : F-Prime/Fw/Comp/CMakeFiles/Fw_Comp.dir/depend
