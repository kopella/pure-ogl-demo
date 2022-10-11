add_executable(pure_ogl linux_main.c)

# external - OpenGL
find_package(OpenGL REQUIRED)
message(STATUS "OPENGL_FOUND: ${OPENGL_FOUND}")

target_link_libraries(pure_ogl
    OpenGL::GL)