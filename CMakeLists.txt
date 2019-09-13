cmake_minimum_required(VERSION 2.8)

project(zwm)

set(CMAKE_BINARY_DIR  ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR}/lib)

include_directories("${PROJECT_SOURCE_DIR}")


add_executable(zwm ${PROJECT_SOURCE_DIR}/main.cpp)