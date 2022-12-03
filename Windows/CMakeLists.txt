add_executable(pure_ogl win_main.c win_ogl.c)

target_link_libraries(pure_ogl
    OpenGL::GL
    ogl_gfx
)