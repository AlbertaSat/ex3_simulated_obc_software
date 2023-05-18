####
# 
####
cmake_minimum_required(VERSION 3.13)
project(cubics-obc-test C CXX)

###
# F' Core Setup
# This includes all of the F prime core components, and imports the make-system.
###
include("${CMAKE_CURRENT_LIST_DIR}/fprime/cmake/FPrime.cmake")
# NOTE: register custom targets between these two lines
include("${FPRIME_FRAMEWORK_PATH}/cmake/FPrime-Code.cmake")

#Had to add this line for the compiler to add debug symbols so we could use gdb to step through Fprime code
# added the ' -O0' arg to compile without any optimizations so the code is easier to debug 
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -g -O0")

# This includes project-wide objects
include("${CMAKE_CURRENT_LIST_DIR}/project.cmake")
