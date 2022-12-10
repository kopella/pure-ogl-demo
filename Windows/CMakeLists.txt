add_executable(pure_ogl win_main.c win_ogl.c win_load_func.c)

# external - OpenGL
find_package(OpenGL REQUIRED)

target_link_libraries(pure_ogl
    ${OPENGL_LIBRARIES}
)

target_link_libraries(pure_ogl
    ogl_gfx
)