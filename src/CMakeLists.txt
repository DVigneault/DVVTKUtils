cmake_minimum_required(VERSION 3.3.0 FATAL_ERROR)

######################
## Project Settings ##
######################

project(DVVTKUtils)

set(DVVTKUtils_VERSION_MAJOR "0")
set(DVVTKUtils_VERSION_MINOR "0")
set(DVVTKUtils_VERSION_PATCH "1")
set(DVVTKUtils_VERSION
    "${DVVTKUtils_MAJOR_VERSION}.${DVVTKUtils_MINOR_VERSION}.${DVVTKUtils_BUILD_VERSION}")

set(VTK_DIR "$ENV{HOME}/Developer/VTK/bin" CACHE STRING "VTK Directory")
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED True)

###################
## CMake Modules ##
###################

# Find and load VTK settings.
if(NOT VTK_BINARY_DIR)
  find_package(VTK REQUIRED vtkCommonCore)
  include(${VTK_USE_FILE})
endif()

#############
## Options ##
#############

include(${VTK_CMAKE_DIR}/vtkExternalModuleMacros.cmake)

vtk_module(DVVTKUtils
  DEPENDS
  vtkCommonCore
  vtkRenderingCore
  vtkFiltersExtraction
  vtkFiltersModeling
)

include_directories(SYSTEM
  ${VTK_INCLUDE_DIRS}
)

# Source files.
file(GLOB SOURCES ./*.cxx)

# Build and link library.
vtk_module_library(DVVTKUtils ${SOURCES})
