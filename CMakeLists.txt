cmake_minimum_required(VERSION 3.0.0)
project(pure_ogl VERSION 0.1.0)

# external
find_package(OpenGL REQUIRED)
message(STATUS "OPENGL_FOUND: ${OPENGL_FOUND}")

include_directories(External)
include_directories(Cross-platform)

add_subdirectory(Cross-platform)

if(WIN32)
    add_subdirectory(Windows)
endif(WIN32)

if(UNIX)
    add_subdirectory(Linux)
endif(UNIX)
