cmake_minimum_required(VERSION 3.0.0)
project(pure_ogl VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(External)
include_directories(Cross-platform)

add_subdirectory(Cross-platform)

if(WIN32)
    add_subdirectory(Windows)
endif(WIN32)

if(UNIX)
    add_subdirectory(Linux)
endif(UNIX)
