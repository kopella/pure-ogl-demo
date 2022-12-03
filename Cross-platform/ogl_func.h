#ifndef __OGL_FUNC_H__
#define __OGL_FUNC_H__

#ifdef _WIN32
#include <Windows.h>
#define APICALL WINAPI

#elif __linux__
#define APICALL

#else
#error "Unknown compiler"
#endif

#include <gl/gl.h>

/* OpenGL functions type defines */
typedef GLvoid(APICALL* PFNGLATTACHSHADERPROC)(GLuint program, GLuint shader);
typedef GLvoid(APICALL* PFNGLBINDBUFFERPROC)(GLenum target, GLuint buffer);
typedef GLvoid(APICALL* PFNGLBINDVERTEXARRAYPROC)(GLuint array);
typedef GLvoid(APICALL* PFNGLBUFFERDATAPROC)(
    GLenum target, ptrdiff_t size, const GLvoid* data, GLenum usage);
typedef GLvoid(APICALL* PFNGLCOMPILESHADERPROC)(GLuint shader);
typedef GLuint(APICALL* PFNGLCREATEPROGRAMPROC)(GLvoid);
typedef GLuint(APICALL* PFNGLCREATESHADERPROC)(GLenum type);
typedef GLvoid(APICALL* PFNGLDELETEBUFFERSPROC)(
    GLsizei n, const GLuint* buffers);
typedef GLvoid(APICALL* PFNGLDELETEPROGRAMPROC)(GLuint program);
typedef GLvoid(APICALL* PFNGLDELETESHADERPROC)(GLuint shader);
typedef GLvoid(APICALL* PFNGLDELETEVERTEXARRAYSPROC)(
    GLsizei n, const GLuint* arrays);
typedef GLvoid(APICALL* PFNGLDETACHSHADERPROC)(GLuint program, GLuint shader);
typedef GLvoid(APICALL* PFNGLENABLEVERTEXATTRIBARRAYPROC)(GLuint index);
typedef GLvoid(APICALL* PFNGLGENBUFFERSPROC)(GLsizei n, GLuint* buffers);
typedef GLvoid(APICALL* PFNGLGENVERTEXARRAYSPROC)(GLsizei n, GLuint* arrays);
typedef GLint(APICALL* PFNGLGETATTRIBLOCATIONPROC)(
    GLuint program, const char* name);
typedef GLvoid(APICALL* PFNGLGETPROGRAMINFOLOGPROC)(
    GLuint program, GLsizei bufSize, GLsizei* length, char* infoLog);
typedef GLvoid(APICALL* PFNGLGETPROGRAMIVPROC)(
    GLuint program, GLenum pname, GLint* params);
typedef GLvoid(APICALL* PFNGLGETSHADERINFOLOGPROC)(
    GLuint shader, GLsizei bufSize, GLsizei* length, char* infoLog);
typedef GLvoid(APICALL* PFNGLGETSHADERIVPROC)(
    GLuint shader, GLenum pname, GLint* params);
typedef GLvoid(APICALL* PFNGLLINKPROGRAMPROC)(GLuint program);
typedef GLvoid(APICALL* PFNGLSHADERSOURCEPROC)(
    GLuint shader, GLsizei count, const char** string, const GLint* length);
typedef GLvoid(APICALL* PFNGLUSEPROGRAMPROC)(GLuint program);
typedef GLvoid(APICALL* PFNGLVERTEXATTRIBPOINTERPROC)(
    GLuint index, GLint size, GLenum type, GLboolean normalized, GLsizei stride,
    const GLvoid* pointer);
typedef GLvoid(APICALL* PFNGLBINDATTRIBLOCATIONPROC)(
    GLuint program, GLuint index, const char* name);
typedef GLint(APICALL* PFNGLGETUNIFORMLOCATIONPROC)(
    GLuint program, const char* name);
typedef GLvoid(APICALL* PFNGLUNIFORMMATRIX4FVPROC)(
    GLint location, GLsizei count, GLboolean transpose, const GLfloat* value);
typedef GLvoid(APICALL* PFNGLACTIVETEXTUREPROC)(GLenum texture);
typedef GLvoid(APICALL* PFNGLUNIFORM1IPROC)(GLint location, GLint v0);
typedef GLvoid(APICALL* PFNGLGENERATEMIPMAPPROC)(GLenum target);
typedef GLvoid(APICALL* PFNGLDISABLEVERTEXATTRIBARRAYPROC)(GLuint index);
typedef GLvoid(APICALL* PFNGLUNIFORM3FVPROC)(
    GLint location, GLsizei count, const GLfloat* value);
typedef GLvoid(APICALL* PFNGLUNIFORM4FVPROC)(
    GLint location, GLsizei count, const GLfloat* value);

/* OpenGL functions */
PFNGLATTACHSHADERPROC glAttachShader;
PFNGLBINDBUFFERPROC glBindBuffer;
PFNGLBINDVERTEXARRAYPROC glBindVertexArray;
PFNGLBUFFERDATAPROC glBufferData;
PFNGLCOMPILESHADERPROC glCompileShader;
PFNGLCREATEPROGRAMPROC glCreateProgram;
PFNGLCREATESHADERPROC glCreateShader;
PFNGLDELETEBUFFERSPROC glDeleteBuffers;
PFNGLDELETEPROGRAMPROC glDeleteProgram;
PFNGLDELETESHADERPROC glDeleteShader;
PFNGLDELETEVERTEXARRAYSPROC glDeleteVertexArrays;
PFNGLDETACHSHADERPROC glDetachShader;
PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray;
PFNGLGENBUFFERSPROC glGenBuffers;
PFNGLGENVERTEXARRAYSPROC glGenVertexArrays;
PFNGLGETATTRIBLOCATIONPROC glGetAttribLocation;
PFNGLGETPROGRAMINFOLOGPROC glGetProgramInfoLog;
PFNGLGETPROGRAMIVPROC glGetProgramiv;
PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog;
PFNGLGETSHADERIVPROC glGetShaderiv;
PFNGLLINKPROGRAMPROC glLinkProgram;
PFNGLSHADERSOURCEPROC glShaderSource;
PFNGLUSEPROGRAMPROC glUseProgram;
PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer;
PFNGLBINDATTRIBLOCATIONPROC glBindAttribLocation;
PFNGLGETUNIFORMLOCATIONPROC glGetUniformLocation;
PFNGLUNIFORMMATRIX4FVPROC glUniformMatrix4fv;
PFNGLACTIVETEXTUREPROC glActiveTexture;
PFNGLUNIFORM1IPROC glUniform1i;
PFNGLGENERATEMIPMAPPROC glGenerateMipmap;
PFNGLDISABLEVERTEXATTRIBARRAYPROC glDisableVertexAttribArray;
PFNGLUNIFORM3FVPROC glUniform3fv;
PFNGLUNIFORM4FVPROC glUniform4fv;

#endif