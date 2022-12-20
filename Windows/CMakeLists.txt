add_executable(pure_ogl win_main.cc win_ogl.cc win_load_func.cc)

# external - OpenGL
find_package(OpenGL REQUIRED)

target_link_libraries(pure_ogl
    ${OPENGL_LIBRARIES}
)

target_link_libraries(pure_ogl
    ogl_gfx
)