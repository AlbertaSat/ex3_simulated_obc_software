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
CMAKE_SOURCE_DIR = /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native

# Include any dependencies generated for this target.
include F-Prime/Svc/GenericHub/CMakeFiles/Svc_GenericHub.dir/depend.make

# Include the progress variables for this target.
include F-Prime/Svc/GenericHub/CMakeFiles/Svc_GenericHub.dir/progress.make

# Include the compile flags for this target's objects.
include F-Prime/Svc/GenericHub/CMakeFiles/Svc_GenericHub.dir/flags.make

F-Prime/Svc/GenericHub/GenericHubComponentAc.hpp: F-Prime/Svc/GenericHub/GenericHubComponentAi.xml
F-Prime/Svc/GenericHub/GenericHubComponentAc.hpp: ../fprime/config/AcConstants.ini
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating GenericHubComponentAc.hpp, GenericHubComponentAc.cpp"
	cd /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime/Svc/GenericHub && /usr/bin/cmake -E env PYTHONPATH=/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/Autocoders/Python/src:/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/Autocoders/Python/utils BUILD_ROOT=/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime:/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test:/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native:/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime FPRIME_AC_CONSTANTS_FILE=/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/config/AcConstants.ini PYTHON_AUTOCODER_DIR=/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/Autocoders/Python /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/venv/bin/python3 /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/Autocoders/Python/bin/codegen.py -p /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime/Svc/GenericHub --build_root /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime/Svc/GenericHub/GenericHubComponentAi.xml

F-Prime/Svc/GenericHub/GenericHubComponentAc.cpp: F-Prime/Svc/GenericHub/GenericHubComponentAc.hpp
	@$(CMAKE_COMMAND) -E touch_nocreate F-Prime/Svc/GenericHub/GenericHubComponentAc.cpp

F-Prime/Svc/GenericHub/GenericHubComponentAi.xml: ../fprime/Svc/GenericHub/GenericHub.fpp
F-Prime/Svc/GenericHub/GenericHubComponentAi.xml: lib/Linux/libFw_Buffer.a
F-Prime/Svc/GenericHub/GenericHubComponentAi.xml: lib/Linux/libOs.a
F-Prime/Svc/GenericHub/GenericHubComponentAi.xml: lib/Linux/libFw_Comp.a
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating GenericHubComponentAi.xml"
	cd /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime/Svc/GenericHub && ../../../../venv/bin/fpp-to-xml -d /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime/Svc/GenericHub -i /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/Fw/Buffer/Buffer.fpp,/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/config/AcConstants.fpp /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/Svc/GenericHub/GenericHub.fpp -p /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime,/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test

F-Prime/Svc/GenericHub/CMakeFiles/Svc_GenericHub.dir/GenericHubComponentImpl.cpp.o: F-Prime/Svc/GenericHub/CMakeFiles/Svc_GenericHub.dir/flags.make
F-Prime/Svc/GenericHub/CMakeFiles/Svc_GenericHub.dir/GenericHubComponentImpl.cpp.o: ../fprime/Svc/GenericHub/GenericHubComponentImpl.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object F-Prime/Svc/GenericHub/CMakeFiles/Svc_GenericHub.dir/GenericHubComponentImpl.cpp.o"
	cd /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime/Svc/GenericHub && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -DASSERT_FILE_ID=0x9237208a -DASSERT_RELATIVE_PATH='"Svc/GenericHub/GenericHubComponentImpl.cpp"' -o CMakeFiles/Svc_GenericHub.dir/GenericHubComponentImpl.cpp.o -c /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/Svc/GenericHub/GenericHubComponentImpl.cpp

F-Prime/Svc/GenericHub/CMakeFiles/Svc_GenericHub.dir/GenericHubComponentImpl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Svc_GenericHub.dir/GenericHubComponentImpl.cpp.i"
	cd /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime/Svc/GenericHub && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -DASSERT_FILE_ID=0x9237208a -DASSERT_RELATIVE_PATH='"Svc/GenericHub/GenericHubComponentImpl.cpp"' -E /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/Svc/GenericHub/GenericHubComponentImpl.cpp > CMakeFiles/Svc_GenericHub.dir/GenericHubComponentImpl.cpp.i

F-Prime/Svc/GenericHub/CMakeFiles/Svc_GenericHub.dir/GenericHubComponentImpl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Svc_GenericHub.dir/GenericHubComponentImpl.cpp.s"
	cd /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime/Svc/GenericHub && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -DASSERT_FILE_ID=0x9237208a -DASSERT_RELATIVE_PATH='"Svc/GenericHub/GenericHubComponentImpl.cpp"' -S /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/Svc/GenericHub/GenericHubComponentImpl.cpp -o CMakeFiles/Svc_GenericHub.dir/GenericHubComponentImpl.cpp.s

F-Prime/Svc/GenericHub/CMakeFiles/Svc_GenericHub.dir/GenericHubComponentAc.cpp.o: F-Prime/Svc/GenericHub/CMakeFiles/Svc_GenericHub.dir/flags.make
F-Prime/Svc/GenericHub/CMakeFiles/Svc_GenericHub.dir/GenericHubComponentAc.cpp.o: F-Prime/Svc/GenericHub/GenericHubComponentAc.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object F-Prime/Svc/GenericHub/CMakeFiles/Svc_GenericHub.dir/GenericHubComponentAc.cpp.o"
	cd /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime/Svc/GenericHub && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -DASSERT_FILE_ID=0xfacac901 -DASSERT_RELATIVE_PATH='"build-fprime-automatic-native/F-Prime/Svc/GenericHub/GenericHubComponentAc.cpp"' -o CMakeFiles/Svc_GenericHub.dir/GenericHubComponentAc.cpp.o -c /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime/Svc/GenericHub/GenericHubComponentAc.cpp

F-Prime/Svc/GenericHub/CMakeFiles/Svc_GenericHub.dir/GenericHubComponentAc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Svc_GenericHub.dir/GenericHubComponentAc.cpp.i"
	cd /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime/Svc/GenericHub && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -DASSERT_FILE_ID=0xfacac901 -DASSERT_RELATIVE_PATH='"build-fprime-automatic-native/F-Prime/Svc/GenericHub/GenericHubComponentAc.cpp"' -E /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime/Svc/GenericHub/GenericHubComponentAc.cpp > CMakeFiles/Svc_GenericHub.dir/GenericHubComponentAc.cpp.i

F-Prime/Svc/GenericHub/CMakeFiles/Svc_GenericHub.dir/GenericHubComponentAc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Svc_GenericHub.dir/GenericHubComponentAc.cpp.s"
	cd /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime/Svc/GenericHub && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -DASSERT_FILE_ID=0xfacac901 -DASSERT_RELATIVE_PATH='"build-fprime-automatic-native/F-Prime/Svc/GenericHub/GenericHubComponentAc.cpp"' -S /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime/Svc/GenericHub/GenericHubComponentAc.cpp -o CMakeFiles/Svc_GenericHub.dir/GenericHubComponentAc.cpp.s

# Object files for target Svc_GenericHub
Svc_GenericHub_OBJECTS = \
"CMakeFiles/Svc_GenericHub.dir/GenericHubComponentImpl.cpp.o" \
"CMakeFiles/Svc_GenericHub.dir/GenericHubComponentAc.cpp.o"

# External object files for target Svc_GenericHub
Svc_GenericHub_EXTERNAL_OBJECTS =

lib/Linux/libSvc_GenericHub.a: F-Prime/Svc/GenericHub/CMakeFiles/Svc_GenericHub.dir/GenericHubComponentImpl.cpp.o
lib/Linux/libSvc_GenericHub.a: F-Prime/Svc/GenericHub/CMakeFiles/Svc_GenericHub.dir/GenericHubComponentAc.cpp.o
lib/Linux/libSvc_GenericHub.a: F-Prime/Svc/GenericHub/CMakeFiles/Svc_GenericHub.dir/build.make
lib/Linux/libSvc_GenericHub.a: F-Prime/Svc/GenericHub/CMakeFiles/Svc_GenericHub.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX static library ../../../lib/Linux/libSvc_GenericHub.a"
	cd /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime/Svc/GenericHub && $(CMAKE_COMMAND) -P CMakeFiles/Svc_GenericHub.dir/cmake_clean_target.cmake
	cd /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime/Svc/GenericHub && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Svc_GenericHub.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
F-Prime/Svc/GenericHub/CMakeFiles/Svc_GenericHub.dir/build: lib/Linux/libSvc_GenericHub.a

.PHONY : F-Prime/Svc/GenericHub/CMakeFiles/Svc_GenericHub.dir/build

F-Prime/Svc/GenericHub/CMakeFiles/Svc_GenericHub.dir/clean:
	cd /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime/Svc/GenericHub && $(CMAKE_COMMAND) -P CMakeFiles/Svc_GenericHub.dir/cmake_clean.cmake
.PHONY : F-Prime/Svc/GenericHub/CMakeFiles/Svc_GenericHub.dir/clean

F-Prime/Svc/GenericHub/CMakeFiles/Svc_GenericHub.dir/depend: F-Prime/Svc/GenericHub/GenericHubComponentAc.hpp
F-Prime/Svc/GenericHub/CMakeFiles/Svc_GenericHub.dir/depend: F-Prime/Svc/GenericHub/GenericHubComponentAc.cpp
F-Prime/Svc/GenericHub/CMakeFiles/Svc_GenericHub.dir/depend: F-Prime/Svc/GenericHub/GenericHubComponentAi.xml
	cd /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/Svc/GenericHub /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime/Svc/GenericHub /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime/Svc/GenericHub/CMakeFiles/Svc_GenericHub.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : F-Prime/Svc/GenericHub/CMakeFiles/Svc_GenericHub.dir/depend

