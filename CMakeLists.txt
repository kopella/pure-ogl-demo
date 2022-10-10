cmake_minimum_required(VERSION 3.0.0)
project(pure_ogl VERSION 0.1.0)

if(WIN32)
    add_subdirectory(Windows)
endif(WIN32)