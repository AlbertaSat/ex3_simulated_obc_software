# This CMake file is intended to register project-wide objects so they can be
# reused easily between deployments, but also by other projects.
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/Components/Burnwire/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/SimulationDeployment/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/Components/DeployablesInterface/")
add_fprime_subdirectory("${CMAKE_CURRENT_LIST_DIR}/Components/DeployablesService/")
