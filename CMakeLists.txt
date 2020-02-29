cmake_minimum_required(VERSION 3.10)

# set the project name and version
project(MQAnalyzer VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# configure a header file to pass some of the CMake settings
# to the source code
configure_file(MQAnalyzerConfig.h.in MQAnalyzerConfig.h)

# add the executable
add_executable(MQAnalyzer main.cpp)

# check for NTL
message(STATUS "Detecting NTL library")
find_library(NTL_LIB ntl)
if(NOT NTL_LIB)
  message(FATAL_ERROR "NTL library not found")
endif()

# link libraries
target_link_libraries(MQAnalyzer
                    PUBLIC
                    ${NTL_LIB}
                    m
                    gmp
                    pthread
                    )

# add the binary tree to the search path for include files
# so that we will find MQAnalyzerConfig.h
target_include_directories(MQAnalyzer PUBLIC
                          "${PROJECT_BINARY_DIR}"
                          )