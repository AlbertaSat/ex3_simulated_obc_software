# Install script for directory: /home/fprime-dev/obc_software_nextgen_test/cubics-obc-test

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-artifacts")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

# Set default install directory permissions.
if(NOT DEFINED CMAKE_OBJDUMP)
  set(CMAKE_OBJDUMP "/usr/bin/objdump")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/prescan/F-Prime/Autocoders/cmake_install.cmake")
  include("/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/prescan/config/cmake_install.cmake")
  include("/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/prescan/F-Prime/Fw/cmake_install.cmake")
  include("/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/prescan/F-Prime/Svc/cmake_install.cmake")
  include("/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/prescan/F-Prime/Os/cmake_install.cmake")
  include("/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/prescan/F-Prime/Drv/cmake_install.cmake")
  include("/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/prescan/F-Prime/CFDP/cmake_install.cmake")
  include("/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/prescan/F-Prime/Utils/cmake_install.cmake")
  include("/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/prescan/Components/Burnwire/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/fprime-dev/obc_software_nextgen_test/cubics-obc-test/build-fprime-automatic-native/prescan/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
