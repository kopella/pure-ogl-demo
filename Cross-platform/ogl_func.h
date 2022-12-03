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
extern PFNGLATTACHSHADERPROC glAttachShader;
extern PFNGLBINDBUFFERPROC glBindBuffer;
extern PFNGLBINDVERTEXARRAYPROC glBindVertexArray;
extern PFNGLBUFFERDATAPROC glBufferData;
extern PFNGLCOMPILESHADERPROC glCompileShader;
extern PFNGLCREATEPROGRAMPROC glCreateProgram;
extern PFNGLCREATESHADERPROC glCreateShader;
extern PFNGLDELETEBUFFERSPROC glDeleteBuffers;
extern PFNGLDELETEPROGRAMPROC glDeleteProgram;
extern PFNGLDELETESHADERPROC glDeleteShader;
extern PFNGLDELETEVERTEXARRAYSPROC glDeleteVertexArrays;
extern PFNGLDETACHSHADERPROC glDetachShader;
extern PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray;
extern PFNGLGENBUFFERSPROC glGenBuffers;
extern PFNGLGENVERTEXARRAYSPROC glGenVertexArrays;
extern PFNGLGETATTRIBLOCATIONPROC glGetAttribLocation;
extern PFNGLGETPROGRAMINFOLOGPROC glGetProgramInfoLog;
extern PFNGLGETPROGRAMIVPROC glGetProgramiv;
extern PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog;
extern PFNGLGETSHADERIVPROC glGetShaderiv;
extern PFNGLLINKPROGRAMPROC glLinkProgram;
extern PFNGLSHADERSOURCEPROC glShaderSource;
extern PFNGLUSEPROGRAMPROC glUseProgram;
extern PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer;
extern PFNGLBINDATTRIBLOCATIONPROC glBindAttribLocation;
extern PFNGLGETUNIFORMLOCATIONPROC glGetUniformLocation;
extern PFNGLUNIFORMMATRIX4FVPROC glUniformMatrix4fv;
extern PFNGLACTIVETEXTUREPROC glActiveTexture;
extern PFNGLUNIFORM1IPROC glUniform1i;
extern PFNGLGENERATEMIPMAPPROC glGenerateMipmap;
extern PFNGLDISABLEVERTEXATTRIBARRAYPROC glDisableVertexAttribArray;
extern PFNGLUNIFORM3FVPROC glUniform3fv;
extern PFNGLUNIFORM4FVPROC glUniform4fv;

#endif