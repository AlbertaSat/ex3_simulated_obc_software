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
include F-Prime/Svc/CmdDispatcher/CMakeFiles/Svc_CmdDispatcher.dir/depend.make

# Include the progress variables for this target.
include F-Prime/Svc/CmdDispatcher/CMakeFiles/Svc_CmdDispatcher.dir/progress.make

# Include the compile flags for this target's objects.
include F-Prime/Svc/CmdDispatcher/CMakeFiles/Svc_CmdDispatcher.dir/flags.make

F-Prime/Svc/CmdDispatcher/CommandDispatcherComponentAc.hpp: F-Prime/Svc/CmdDispatcher/CommandDispatcherComponentAi.xml
F-Prime/Svc/CmdDispatcher/CommandDispatcherComponentAc.hpp: ../fprime/config/AcConstants.ini
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating CommandDispatcherComponentAc.hpp, CommandDispatcherComponentAc.cpp"
	cd /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime/Svc/CmdDispatcher && /usr/bin/cmake -E env PYTHONPATH=/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/Autocoders/Python/src:/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/Autocoders/Python/utils BUILD_ROOT=/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime:/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test:/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native:/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime FPRIME_AC_CONSTANTS_FILE=/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/config/AcConstants.ini PYTHON_AUTOCODER_DIR=/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/Autocoders/Python /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/venv/bin/python3 /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/Autocoders/Python/bin/codegen.py -p /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime/Svc/CmdDispatcher --build_root /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime/Svc/CmdDispatcher/CommandDispatcherComponentAi.xml

F-Prime/Svc/CmdDispatcher/CommandDispatcherComponentAc.cpp: F-Prime/Svc/CmdDispatcher/CommandDispatcherComponentAc.hpp
	@$(CMAKE_COMMAND) -E touch_nocreate F-Prime/Svc/CmdDispatcher/CommandDispatcherComponentAc.cpp

F-Prime/Svc/CmdDispatcher/CommandDispatcherComponentAi.xml: ../fprime/Svc/CmdDispatcher/CmdDispatcher.fpp
F-Prime/Svc/CmdDispatcher/CommandDispatcherComponentAi.xml: lib/Linux/libFw_Cmd.a
F-Prime/Svc/CmdDispatcher/CommandDispatcherComponentAi.xml: lib/Linux/libFw_Com.a
F-Prime/Svc/CmdDispatcher/CommandDispatcherComponentAi.xml: lib/Linux/libFw_Log.a
F-Prime/Svc/CmdDispatcher/CommandDispatcherComponentAi.xml: lib/Linux/libFw_Tlm.a
F-Prime/Svc/CmdDispatcher/CommandDispatcherComponentAi.xml: lib/Linux/libFw_Types.a
F-Prime/Svc/CmdDispatcher/CommandDispatcherComponentAi.xml: lib/Linux/libSvc_Ping.a
F-Prime/Svc/CmdDispatcher/CommandDispatcherComponentAi.xml: lib/Linux/libFw_CompQueued.a
F-Prime/Svc/CmdDispatcher/CommandDispatcherComponentAi.xml: lib/Linux/libOs.a
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating CommandDispatcherComponentAi.xml"
	cd /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime/Svc/CmdDispatcher && ../../../../venv/bin/fpp-to-xml -d /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime/Svc/CmdDispatcher -i /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/Fw/Cmd/Cmd.fpp,/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/Fw/Com/Com.fpp,/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/Fw/Log/Log.fpp,/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/Fw/Time/Time.fpp,/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/Fw/Tlm/Tlm.fpp,/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/Fw/Types/Types.fpp,/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/Svc/Ping/Ping.fpp,/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/config/AcConstants.fpp,/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/config/FpConfig.fpp /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/Svc/CmdDispatcher/CmdDispatcher.fpp -p /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime,/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test

F-Prime/Svc/CmdDispatcher/CMakeFiles/Svc_CmdDispatcher.dir/CommandDispatcherImpl.cpp.o: F-Prime/Svc/CmdDispatcher/CMakeFiles/Svc_CmdDispatcher.dir/flags.make
F-Prime/Svc/CmdDispatcher/CMakeFiles/Svc_CmdDispatcher.dir/CommandDispatcherImpl.cpp.o: ../fprime/Svc/CmdDispatcher/CommandDispatcherImpl.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object F-Prime/Svc/CmdDispatcher/CMakeFiles/Svc_CmdDispatcher.dir/CommandDispatcherImpl.cpp.o"
	cd /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime/Svc/CmdDispatcher && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -DASSERT_FILE_ID=0xeb6bfe7c -DASSERT_RELATIVE_PATH='"Svc/CmdDispatcher/CommandDispatcherImpl.cpp"' -o CMakeFiles/Svc_CmdDispatcher.dir/CommandDispatcherImpl.cpp.o -c /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/Svc/CmdDispatcher/CommandDispatcherImpl.cpp

F-Prime/Svc/CmdDispatcher/CMakeFiles/Svc_CmdDispatcher.dir/CommandDispatcherImpl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Svc_CmdDispatcher.dir/CommandDispatcherImpl.cpp.i"
	cd /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime/Svc/CmdDispatcher && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -DASSERT_FILE_ID=0xeb6bfe7c -DASSERT_RELATIVE_PATH='"Svc/CmdDispatcher/CommandDispatcherImpl.cpp"' -E /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/Svc/CmdDispatcher/CommandDispatcherImpl.cpp > CMakeFiles/Svc_CmdDispatcher.dir/CommandDispatcherImpl.cpp.i

F-Prime/Svc/CmdDispatcher/CMakeFiles/Svc_CmdDispatcher.dir/CommandDispatcherImpl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Svc_CmdDispatcher.dir/CommandDispatcherImpl.cpp.s"
	cd /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime/Svc/CmdDispatcher && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -DASSERT_FILE_ID=0xeb6bfe7c -DASSERT_RELATIVE_PATH='"Svc/CmdDispatcher/CommandDispatcherImpl.cpp"' -S /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/Svc/CmdDispatcher/CommandDispatcherImpl.cpp -o CMakeFiles/Svc_CmdDispatcher.dir/CommandDispatcherImpl.cpp.s

F-Prime/Svc/CmdDispatcher/CMakeFiles/Svc_CmdDispatcher.dir/CommandDispatcherComponentAc.cpp.o: F-Prime/Svc/CmdDispatcher/CMakeFiles/Svc_CmdDispatcher.dir/flags.make
F-Prime/Svc/CmdDispatcher/CMakeFiles/Svc_CmdDispatcher.dir/CommandDispatcherComponentAc.cpp.o: F-Prime/Svc/CmdDispatcher/CommandDispatcherComponentAc.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object F-Prime/Svc/CmdDispatcher/CMakeFiles/Svc_CmdDispatcher.dir/CommandDispatcherComponentAc.cpp.o"
	cd /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime/Svc/CmdDispatcher && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -DASSERT_FILE_ID=0xf8270abd -DASSERT_RELATIVE_PATH='"build-fprime-automatic-native/F-Prime/Svc/CmdDispatcher/CommandDispatcherComponentAc.cpp"' -o CMakeFiles/Svc_CmdDispatcher.dir/CommandDispatcherComponentAc.cpp.o -c /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime/Svc/CmdDispatcher/CommandDispatcherComponentAc.cpp

F-Prime/Svc/CmdDispatcher/CMakeFiles/Svc_CmdDispatcher.dir/CommandDispatcherComponentAc.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Svc_CmdDispatcher.dir/CommandDispatcherComponentAc.cpp.i"
	cd /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime/Svc/CmdDispatcher && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -DASSERT_FILE_ID=0xf8270abd -DASSERT_RELATIVE_PATH='"build-fprime-automatic-native/F-Prime/Svc/CmdDispatcher/CommandDispatcherComponentAc.cpp"' -E /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime/Svc/CmdDispatcher/CommandDispatcherComponentAc.cpp > CMakeFiles/Svc_CmdDispatcher.dir/CommandDispatcherComponentAc.cpp.i

F-Prime/Svc/CmdDispatcher/CMakeFiles/Svc_CmdDispatcher.dir/CommandDispatcherComponentAc.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Svc_CmdDispatcher.dir/CommandDispatcherComponentAc.cpp.s"
	cd /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime/Svc/CmdDispatcher && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -DASSERT_FILE_ID=0xf8270abd -DASSERT_RELATIVE_PATH='"build-fprime-automatic-native/F-Prime/Svc/CmdDispatcher/CommandDispatcherComponentAc.cpp"' -S /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime/Svc/CmdDispatcher/CommandDispatcherComponentAc.cpp -o CMakeFiles/Svc_CmdDispatcher.dir/CommandDispatcherComponentAc.cpp.s

# Object files for target Svc_CmdDispatcher
Svc_CmdDispatcher_OBJECTS = \
"CMakeFiles/Svc_CmdDispatcher.dir/CommandDispatcherImpl.cpp.o" \
"CMakeFiles/Svc_CmdDispatcher.dir/CommandDispatcherComponentAc.cpp.o"

# External object files for target Svc_CmdDispatcher
Svc_CmdDispatcher_EXTERNAL_OBJECTS =

lib/Linux/libSvc_CmdDispatcher.a: F-Prime/Svc/CmdDispatcher/CMakeFiles/Svc_CmdDispatcher.dir/CommandDispatcherImpl.cpp.o
lib/Linux/libSvc_CmdDispatcher.a: F-Prime/Svc/CmdDispatcher/CMakeFiles/Svc_CmdDispatcher.dir/CommandDispatcherComponentAc.cpp.o
lib/Linux/libSvc_CmdDispatcher.a: F-Prime/Svc/CmdDispatcher/CMakeFiles/Svc_CmdDispatcher.dir/build.make
lib/Linux/libSvc_CmdDispatcher.a: F-Prime/Svc/CmdDispatcher/CMakeFiles/Svc_CmdDispatcher.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX static library ../../../lib/Linux/libSvc_CmdDispatcher.a"
	cd /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime/Svc/CmdDispatcher && $(CMAKE_COMMAND) -P CMakeFiles/Svc_CmdDispatcher.dir/cmake_clean_target.cmake
	cd /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime/Svc/CmdDispatcher && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Svc_CmdDispatcher.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
F-Prime/Svc/CmdDispatcher/CMakeFiles/Svc_CmdDispatcher.dir/build: lib/Linux/libSvc_CmdDispatcher.a

.PHONY : F-Prime/Svc/CmdDispatcher/CMakeFiles/Svc_CmdDispatcher.dir/build

F-Prime/Svc/CmdDispatcher/CMakeFiles/Svc_CmdDispatcher.dir/clean:
	cd /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime/Svc/CmdDispatcher && $(CMAKE_COMMAND) -P CMakeFiles/Svc_CmdDispatcher.dir/cmake_clean.cmake
.PHONY : F-Prime/Svc/CmdDispatcher/CMakeFiles/Svc_CmdDispatcher.dir/clean

F-Prime/Svc/CmdDispatcher/CMakeFiles/Svc_CmdDispatcher.dir/depend: F-Prime/Svc/CmdDispatcher/CommandDispatcherComponentAc.hpp
F-Prime/Svc/CmdDispatcher/CMakeFiles/Svc_CmdDispatcher.dir/depend: F-Prime/Svc/CmdDispatcher/CommandDispatcherComponentAc.cpp
F-Prime/Svc/CmdDispatcher/CMakeFiles/Svc_CmdDispatcher.dir/depend: F-Prime/Svc/CmdDispatcher/CommandDispatcherComponentAi.xml
	cd /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/Svc/CmdDispatcher /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime/Svc/CmdDispatcher /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime/Svc/CmdDispatcher/CMakeFiles/Svc_CmdDispatcher.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : F-Prime/Svc/CmdDispatcher/CMakeFiles/Svc_CmdDispatcher.dir/depend

