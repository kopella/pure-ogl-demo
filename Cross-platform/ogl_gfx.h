#ifndef __OGL_GFX_H__
#define __OGL_GFX_H__

#ifdef _WIN32
#include <Windows.h>

#elif __linux__
#define APICALL

#else
#error "Unknown compiler"
#endif

#include <GL/gl.h>

/* Operate OpenGL */
void draw_scene();
GLuint load_shader();
GLuint load_vertex();

/* OpenGL defines */
#define GL_ARRAY_BUFFER 0x8892
#define GL_STATIC_DRAW 0x88E4
#define GL_FRAGMENT_SHADER 0x8B30
#define GL_VERTEX_SHADER 0x8B31
#define GL_COMPILE_STATUS 0x8B81
#define GL_LINK_STATUS 0x8B82
#define GL_INFO_LOG_LENGTH 0x8B84
#define GL_TEXTURE0 0x84C0
#define GL_BGRA 0x80E1
#define GL_ELEMENT_ARRAY_BUFFER 0x8893

#endif