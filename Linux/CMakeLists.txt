add_executable(pure_ogl linux_main.c)

# external - OpenGL
set(OpenGL_GL_PREFERENCE "GLVND")
find_package(OpenGL REQUIRED)
message(STATUS "OPENGL_FOUND: ${OPENGL_FOUND}")

# external - X11
find_package(X11 REQUIRED)
message(STATUS "X11_FOUND: ${X11_FOUND}")

target_link_libraries(pure_ogl
    ${OPENGL_LIBRARIES}
    ${X11_LIBRARIES}
)

target_link_libraries(pure_ogl
    ogl_gfx
)