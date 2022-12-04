add_executable(pure_ogl linux_main.c)

# external - OpenGL
find_package(OpenGL REQUIRED)

# external - GLX
find_package(X11 REQUIRED)

target_link_libraries(pure_ogl
    ${OPENGL_LIBRARIES}
    ${X11_LIBRARIES}
)