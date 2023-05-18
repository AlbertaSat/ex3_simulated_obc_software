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
include F-Prime/Svc/Deframer/CMakeFiles/Svc_Deframer.dir/depend.make

# Include the progress variables for this target.
include F-Prime/Svc/Deframer/CMakeFiles/Svc_Deframer.dir/progress.make

# Include the compile flags for this target's objects.
include F-Prime/Svc/Deframer/CMakeFiles/Svc_Deframer.dir/flags.make

F-Prime/Svc/Deframer/DeframerComponentAc.hpp: F-Prime/Svc/Deframer/DeframerComponentAi.xml
F-Prime/Svc/Deframer/DeframerComponentAc.hpp: ../fprime/config/AcConstants.ini
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating DeframerComponentAc.hpp, DeframerComponentAc.cpp"
	cd /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime/Svc/Deframer && /usr/bin/cmake -E env PYTHONPATH=/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/Autocoders/Python/src:/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/Autocoders/Python/utils BUILD_ROOT=/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime:/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test:/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native:/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime FPRIME_AC_CONSTANTS_FILE=/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/config/AcConstants.ini PYTHON_AUTOCODER_DIR=/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/Autocoders/Python /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/venv/bin/python3 /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/Autocoders/Python/bin/codegen.py -p /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime/Svc/Deframer --build_root /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime/Svc/Deframer/DeframerComponentAi.xml

F-Prime/Svc/Deframer/DeframerComponentAc.cpp: F-Prime/Svc/Deframer/DeframerComponentAc.hpp
	@$(CMAKE_COMMAND) -E touch_nocreate F-Prime/Svc/Deframer/DeframerComponentAc.cpp

F-Prime/Svc/Deframer/DeframerComponentAi.xml: ../fprime/Svc/Deframer/Deframer.fpp
F-Prime/Svc/Deframer/DeframerComponentAi.xml: lib/Linux/libDrv_ByteStreamDriverModel.a
F-Prime/Svc/Deframer/DeframerComponentAi.xml: lib/Linux/libFw_Cmd.a
F-Prime/Svc/Deframer/DeframerComponentAi.xml: lib/Linux/libFw_Com.a
F-Prime/Svc/Deframer/DeframerComponentAi.xml: lib/Linux/libSvc_Sched.a
F-Prime/Svc/Deframer/DeframerComponentAi.xml: lib/Linux/libOs.a
F-Prime/Svc/Deframer/DeframerComponentAi.xml: lib/Linux/libFw_Comp.a
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating DeframerComponentAi.xml"
	cd /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime/Svc/Deframer && ../../../../venv/bin/fpp-to-xml -d /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime/Svc/Deframer -i /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/Drv/ByteStreamDriverModel/ByteStreamDriverModel.fpp,/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/Fw/Buffer/Buffer.fpp,/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/Fw/Cmd/Cmd.fpp,/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/Fw/Com/Com.fpp,/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/Svc/Sched/Sched.fpp,/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/config/FpConfig.fpp /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/Svc/Deframer/Deframer.fpp -p /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime,/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test

F-Prime/Svc/Deframer/CMakeFiles/Svc_Deframer.dir/Deframer.cpp.o: F-Prime/Svc/Deframer/CMakeFiles/Svc_Deframer.dir/flags.make
F-Prime/Svc/Deframer/CMakeFiles/Svc_Deframer.dir/Deframer.cpp.o: ../fprime/Svc/Deframer/Deframer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object F-Prime/Svc/Deframer/CMakeFiles/Svc_Deframer.dir/Deframer.cpp.o"
	cd /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime/Svc/Deframer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -DASSERT_FILE_ID=0x5211ffca -DASSERT_RELATIVE_PATH='"Svc/Deframer/Deframer.cpp"' -o CMakeFiles/Svc_Deframer.dir/Deframer.cpp.o -c /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/Svc/Deframer/Deframer.cpp

F-Prime/Svc/Deframer/CMakeFiles/Svc_Deframer.dir/Deframer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Svc_Deframer.dir/Deframer.cpp.i"
	cd /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime/Svc/Deframer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -DASSERT_FILE_ID=0x5211ffca -DASSERT_RELATIVE_PATH='"Svc/Deframer/Deframer.cpp"' -E /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/Svc/Deframer/Deframer.cpp > CMakeFiles/Svc_Deframer.dir/Deframer.cpp.i

F-Prime/Svc/Deframer/CMakeFiles/Svc_Deframer.dir/Deframer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Svc_Deframer.dir/Deframer.cpp.s"
	cd /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime/Svc/Deframer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -DASSERT_FILE_ID=0x5211ffca -DASSERT_RELATIVE_PATH='"Svc/Deframer/Deframer.cpp"' -S /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/Svc/Deframer/Deframer.cpp -o CMakeFiles/Svc_Deframer.dir/Deframer.cpp.s

F-Prime/Svc/Deframer/CMakeFiles/Svc_Deframer.dir/DeframerComponentAc.cpp.o: F-Prime/Svc/Deframer/CMakeFiles/Svc_Deframer.dir/flags.make
F-Prime/Svc/Deframer/CMakeFiles/Svc_Deframer.dir/DeframerComponentAc.cpp.o: F-Prime/Svc/Deframer/DeframerComponentAc.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object F-Prime/Svc/Deframer/CMakeFiles/Svc_Deframer.dir/DeframerComponentAc.cpp.o"
	cd /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime/Svc/Deframer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -DASSERT_FILE_ID=0x0a287edd -DASSERT_RELATIVE_PATH='"build-fprime-automatic-native/F-Prime/Svc/Deframer/DeframerComponentAc.cpp"' -o CMakeFiles/Svc_Deframer.dir/DeframerComponentAc.cpp.o -c /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime/Svc/Deframer/DeframerComponentAc.cpp

F-Prime/Svc/Deframer/CMakeFiles/Svc_Deframer.dir/DeframerComponentAc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Svc_Deframer.dir/DeframerComponentAc.cpp.i"
	cd /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime/Svc/Deframer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -DASSERT_FILE_ID=0x0a287edd -DASSERT_RELATIVE_PATH='"build-fprime-automatic-native/F-Prime/Svc/Deframer/DeframerComponentAc.cpp"' -E /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime/Svc/Deframer/DeframerComponentAc.cpp > CMakeFiles/Svc_Deframer.dir/DeframerComponentAc.cpp.i

F-Prime/Svc/Deframer/CMakeFiles/Svc_Deframer.dir/DeframerComponentAc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Svc_Deframer.dir/DeframerComponentAc.cpp.s"
	cd /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime/Svc/Deframer && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -DASSERT_FILE_ID=0x0a287edd -DASSERT_RELATIVE_PATH='"build-fprime-automatic-native/F-Prime/Svc/Deframer/DeframerComponentAc.cpp"' -S /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime/Svc/Deframer/DeframerComponentAc.cpp -o CMakeFiles/Svc_Deframer.dir/DeframerComponentAc.cpp.s

# Object files for target Svc_Deframer
Svc_Deframer_OBJECTS = \
"CMakeFiles/Svc_Deframer.dir/Deframer.cpp.o" \
"CMakeFiles/Svc_Deframer.dir/DeframerComponentAc.cpp.o"

# External object files for target Svc_Deframer
Svc_Deframer_EXTERNAL_OBJECTS =

lib/Linux/libSvc_Deframer.a: F-Prime/Svc/Deframer/CMakeFiles/Svc_Deframer.dir/Deframer.cpp.o
lib/Linux/libSvc_Deframer.a: F-Prime/Svc/Deframer/CMakeFiles/Svc_Deframer.dir/DeframerComponentAc.cpp.o
lib/Linux/libSvc_Deframer.a: F-Prime/Svc/Deframer/CMakeFiles/Svc_Deframer.dir/build.make
lib/Linux/libSvc_Deframer.a: F-Prime/Svc/Deframer/CMakeFiles/Svc_Deframer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX static library ../../../lib/Linux/libSvc_Deframer.a"
	cd /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime/Svc/Deframer && $(CMAKE_COMMAND) -P CMakeFiles/Svc_Deframer.dir/cmake_clean_target.cmake
	cd /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime/Svc/Deframer && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Svc_Deframer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
F-Prime/Svc/Deframer/CMakeFiles/Svc_Deframer.dir/build: lib/Linux/libSvc_Deframer.a

.PHONY : F-Prime/Svc/Deframer/CMakeFiles/Svc_Deframer.dir/build

F-Prime/Svc/Deframer/CMakeFiles/Svc_Deframer.dir/clean:
	cd /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime/Svc/Deframer && $(CMAKE_COMMAND) -P CMakeFiles/Svc_Deframer.dir/cmake_clean.cmake
.PHONY : F-Prime/Svc/Deframer/CMakeFiles/Svc_Deframer.dir/clean

F-Prime/Svc/Deframer/CMakeFiles/Svc_Deframer.dir/depend: F-Prime/Svc/Deframer/DeframerComponentAc.hpp
F-Prime/Svc/Deframer/CMakeFiles/Svc_Deframer.dir/depend: F-Prime/Svc/Deframer/DeframerComponentAc.cpp
F-Prime/Svc/Deframer/CMakeFiles/Svc_Deframer.dir/depend: F-Prime/Svc/Deframer/DeframerComponentAi.xml
	cd /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/Svc/Deframer /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime/Svc/Deframer /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime/Svc/Deframer/CMakeFiles/Svc_Deframer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : F-Prime/Svc/Deframer/CMakeFiles/Svc_Deframer.dir/depend

