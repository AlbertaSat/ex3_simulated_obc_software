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

# Utility rule file for Svc_TlmChan_impl.

# Include the progress variables for this target.
include F-Prime/Svc/TlmChan/CMakeFiles/Svc_TlmChan_impl.dir/progress.make

F-Prime/Svc/TlmChan/CMakeFiles/Svc_TlmChan_impl: F-Prime/Svc/TlmChan/TlmChanComponentAi.xml
F-Prime/Svc/TlmChan/CMakeFiles/Svc_TlmChan_impl: ../fprime/Svc/TlmChan/TlmChanComponentImpl.hpp-template
F-Prime/Svc/TlmChan/CMakeFiles/Svc_TlmChan_impl: ../fprime/Svc/TlmChan/TlmChanComponentImpl.cpp-template


F-Prime/Svc/TlmChan/TlmChanComponentAi.xml: ../fprime/Svc/TlmChan/TlmChan.fpp
F-Prime/Svc/TlmChan/TlmChanComponentAi.xml: lib/Linux/libFw_Com.a
F-Prime/Svc/TlmChan/TlmChanComponentAi.xml: lib/Linux/libFw_Tlm.a
F-Prime/Svc/TlmChan/TlmChanComponentAi.xml: lib/Linux/libSvc_Ping.a
F-Prime/Svc/TlmChan/TlmChanComponentAi.xml: lib/Linux/libSvc_Sched.a
F-Prime/Svc/TlmChan/TlmChanComponentAi.xml: lib/Linux/libFw_CompQueued.a
F-Prime/Svc/TlmChan/TlmChanComponentAi.xml: lib/Linux/libOs.a
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating TlmChanComponentAi.xml"
	cd /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime/Svc/TlmChan && ../../../../venv/bin/fpp-to-xml -d /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime/Svc/TlmChan -i /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/Fw/Com/Com.fpp,/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/Fw/Time/Time.fpp,/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/Fw/Tlm/Tlm.fpp,/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/Svc/Ping/Ping.fpp,/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/Svc/Sched/Sched.fpp,/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/config/FpConfig.fpp /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/Svc/TlmChan/TlmChan.fpp -p /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime,/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test

../fprime/Svc/TlmChan/TlmChanComponentImpl.hpp-template: F-Prime/Svc/TlmChan/TlmChanComponentAi.xml
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating ../../../../fprime/Svc/TlmChan/TlmChanComponentImpl.hpp-template, ../../../../fprime/Svc/TlmChan/TlmChanComponentImpl.cpp-template"
	cd /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime/Svc/TlmChan && /usr/bin/cmake -E env PYTHONPATH=/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/Autocoders/Python/src:/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/Autocoders/Python/utils BUILD_ROOT=/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime:/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test:/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native:/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime FPRIME_AC_CONSTANTS_FILE=/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/config/AcConstants.ini PYTHON_AUTOCODER_DIR=/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/Autocoders/Python /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/venv/bin/python3 /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/Autocoders/Python/bin/codegen.py -p /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/Svc/TlmChan --build_root -t /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime/Svc/TlmChan/TlmChanComponentAi.xml

../fprime/Svc/TlmChan/TlmChanComponentImpl.cpp-template: ../fprime/Svc/TlmChan/TlmChanComponentImpl.hpp-template
	@$(CMAKE_COMMAND) -E touch_nocreate ../fprime/Svc/TlmChan/TlmChanComponentImpl.cpp-template

Svc_TlmChan_impl: F-Prime/Svc/TlmChan/CMakeFiles/Svc_TlmChan_impl
Svc_TlmChan_impl: F-Prime/Svc/TlmChan/TlmChanComponentAi.xml
Svc_TlmChan_impl: ../fprime/Svc/TlmChan/TlmChanComponentImpl.hpp-template
Svc_TlmChan_impl: ../fprime/Svc/TlmChan/TlmChanComponentImpl.cpp-template
Svc_TlmChan_impl: F-Prime/Svc/TlmChan/CMakeFiles/Svc_TlmChan_impl.dir/build.make

.PHONY : Svc_TlmChan_impl

# Rule to build all files generated by this target.
F-Prime/Svc/TlmChan/CMakeFiles/Svc_TlmChan_impl.dir/build: Svc_TlmChan_impl

.PHONY : F-Prime/Svc/TlmChan/CMakeFiles/Svc_TlmChan_impl.dir/build

F-Prime/Svc/TlmChan/CMakeFiles/Svc_TlmChan_impl.dir/clean:
	cd /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime/Svc/TlmChan && $(CMAKE_COMMAND) -P CMakeFiles/Svc_TlmChan_impl.dir/cmake_clean.cmake
.PHONY : F-Prime/Svc/TlmChan/CMakeFiles/Svc_TlmChan_impl.dir/clean

F-Prime/Svc/TlmChan/CMakeFiles/Svc_TlmChan_impl.dir/depend:
	cd /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/fprime/Svc/TlmChan /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime/Svc/TlmChan /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/F-Prime/Svc/TlmChan/CMakeFiles/Svc_TlmChan_impl.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : F-Prime/Svc/TlmChan/CMakeFiles/Svc_TlmChan_impl.dir/depend
