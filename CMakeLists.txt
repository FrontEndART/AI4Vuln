cmake_minimum_required (VERSION 3.22.0)

# Set the default build type to release
if (NOT CMAKE_BUILD_TYPE )
  set (CMAKE_BUILD_TYPE Release CACHE STRING "Build Type: Release or Debug" FORCE)
endif()

set (CMAKE_CONFIGURATION_TYPES ${CMAKE_BUILD_TYPE} CACHE INTERNAL "Configuration" FORCE)

project (Columbus VERSION 10.2.0)

set (EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY_RELEASE ${EXECUTABLE_OUTPUT_PATH})
set (CMAKE_RUNTIME_OUTPUT_DIRECTORY_DEBUG ${EXECUTABLE_OUTPUT_PATH})
set (LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY_RELEASE  ${LIBRARY_OUTPUT_PATH})
set (CMAKE_LIBRARY_OUTPUT_DIRECTORY_DEBUG  ${LIBRARY_OUTPUT_PATH})
set (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMake")
set (CMAKE_SUPPORT_FOLDER_NAME CMakeSupportTargets)

set_property (GLOBAL PROPERTY USE_FOLDERS ON)

include (UtilityFunctions)
include (BuildInfo)
include (PlatformOptions)
include (CodebaseOptions)
include (Common)



add_subdirectory (cl/AI4VULN)

add_subdirectory (lib/symbolic)
add_subdirectory (lib/symbolic_java)


add_subdirectory (3rdparty)

add_subdirectory (demo)
