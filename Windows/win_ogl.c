#include "win_ogl.h"

#include "ogl_func.h"
#include "utils.h"

/* OpenGL functions */

/* Program */
PFNGLCREATEPROGRAMPROC glCreateProgram;
PFNGLLINKPROGRAMPROC glLinkProgram;
PFNGLUSEPROGRAMPROC glUseProgram;
PFNGLDELETEPROGRAMPROC glDeleteProgram;
PFNGLGETPROGRAMIVPROC glGetProgramiv;
PFNGLGETPROGRAMINFOLOGPROC glGetProgramInfoLog;

/* Shader */
PFNGLCREATESHADERPROC glCreateShader;
PFNGLSHADERSOURCEPROC glShaderSource;
PFNGLCOMPILESHADERPROC glCompileShader;
PFNGLATTACHSHADERPROC glAttachShader;
PFNGLDETACHSHADERPROC glDetachShader;
PFNGLDELETESHADERPROC glDeleteShader;
PFNGLGETSHADERIVPROC glGetShaderiv;
PFNGLGETSHADERINFOLOGPROC glGetShaderInfoLog;

/* Vertex */
PFNGLGENVERTEXARRAYSPROC glGenVertexArrays;
PFNGLBINDVERTEXARRAYPROC glBindVertexArray;
PFNGLDELETEVERTEXARRAYSPROC glDeleteVertexArrays;
PFNGLENABLEVERTEXATTRIBARRAYPROC glEnableVertexAttribArray;
PFNGLVERTEXATTRIBPOINTERPROC glVertexAttribPointer;
PFNGLDISABLEVERTEXATTRIBARRAYPROC glDisableVertexAttribArray;

/* Buffer */
PFNGLGENBUFFERSPROC glGenBuffers;
PFNGLBINDBUFFERPROC glBindBuffer;
PFNGLBUFFERDATAPROC glBufferData;
PFNGLDELETEBUFFERSPROC glDeleteBuffers;

PFNGLGETATTRIBLOCATIONPROC glGetAttribLocation;
PFNGLBINDATTRIBLOCATIONPROC glBindAttribLocation;
PFNGLGETUNIFORMLOCATIONPROC glGetUniformLocation;
PFNGLUNIFORMMATRIX4FVPROC glUniformMatrix4fv;
PFNGLUNIFORM1IPROC glUniform1i;
PFNGLUNIFORM3FVPROC glUniform3fv;
PFNGLUNIFORM4FVPROC glUniform4fv;

PFNGLACTIVETEXTUREPROC glActiveTexture;
PFNGLGENERATEMIPMAPPROC glGenerateMipmap;

HGLRC create_context(HDC h_dc) {
  PIXELFORMATDESCRIPTOR
  des_pf = {
      .nSize = sizeof(des_pf),
      .nVersion = 1,
      .dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,
      .iPixelType = PFD_TYPE_RGBA,
      .cColorBits = 32,
      .cAlphaBits = 8,
      .cDepthBits = 24,
      .cStencilBits = 8,
      .iLayerType = PFD_MAIN_PLANE,
  };

  int n_pf = ChoosePixelFormat(h_dc, &des_pf);
  if (!n_pf) {
    error_to_console("Failed to find a suitable pixel format.");
  }
  if (!SetPixelFormat(h_dc, n_pf, &des_pf)) {
    error_to_console("Failed to set the pixel format.");
  }
  HGLRC h_rc = wglCreateContext(h_dc);
  if (!h_rc) {
    error_to_console("Failed to create a OpenGL rendering context.");
  }
  if (!wglMakeCurrent(h_dc, h_rc)) {
    error_to_console("Failed to activate the OpenGL rendering context.");
  }

  return h_rc;
}

void get_functions() {
  glAttachShader = (PFNGLATTACHSHADERPROC)wglGetProcAddress("glAttachShader");
  if (!glAttachShader) {
    error_to_console("Failed to get glAttachShader function.");
  }
  glBindBuffer = (PFNGLBINDBUFFERPROC)wglGetProcAddress("glBindBuffer");
  if (!glBindBuffer) {
    error_to_console("Failed to get functions.");
  }
  glBindVertexArray =
      (PFNGLBINDVERTEXARRAYPROC)wglGetProcAddress("glBindVertexArray");
  if (!glBindVertexArray) {
    error_to_console("Failed to get functions.");
  }
  glBufferData = (PFNGLBUFFERDATAPROC)wglGetProcAddress("glBufferData");
  if (!glBufferData) {
    error_to_console("Failed to get functions.");
  }
  glCompileShader =
      (PFNGLCOMPILESHADERPROC)wglGetProcAddress("glCompileShader");
  if (!glCompileShader) {
    error_to_console("Failed to get functions.");
  }
  glCreateProgram =
      (PFNGLCREATEPROGRAMPROC)wglGetProcAddress("glCreateProgram");
  if (!glCreateProgram) {
    error_to_console("Failed to get functions.");
  }
  glCreateShader = (PFNGLCREATESHADERPROC)wglGetProcAddress("glCreateShader");
  if (!glCreateShader) {
    error_to_console("Failed to get functions.");
  }
  glDeleteBuffers =
      (PFNGLDELETEBUFFERSPROC)wglGetProcAddress("glDeleteBuffers");
  if (!glDeleteBuffers) {
    error_to_console("Failed to get functions.");
  }
  glDeleteProgram =
      (PFNGLDELETEPROGRAMPROC)wglGetProcAddress("glDeleteProgram");
  if (!glDeleteProgram) {
    error_to_console("Failed to get functions.");
  }
  glDeleteShader = (PFNGLDELETESHADERPROC)wglGetProcAddress("glDeleteShader");
  if (!glDeleteShader) {
    error_to_console("Failed to get functions.");
  }
  glDeleteVertexArrays =
      (PFNGLDELETEVERTEXARRAYSPROC)wglGetProcAddress("glDeleteVertexArrays");
  if (!glDeleteVertexArrays) {
    error_to_console("Failed to get functions.");
  }
  glDetachShader = (PFNGLDETACHSHADERPROC)wglGetProcAddress("glDetachShader");
  if (!glDetachShader) {
    error_to_console("Failed to get functions.");
  }
  glEnableVertexAttribArray =
      (PFNGLENABLEVERTEXATTRIBARRAYPROC)wglGetProcAddress(
          "glEnableVertexAttribArray");
  if (!glEnableVertexAttribArray) {
    error_to_console("Failed to get functions.");
  }
  glGenBuffers = (PFNGLGENBUFFERSPROC)wglGetProcAddress("glGenBuffers");
  if (!glGenBuffers) {
    error_to_console("Failed to get functions.");
  }
  glGenVertexArrays =
      (PFNGLGENVERTEXARRAYSPROC)wglGetProcAddress("glGenVertexArrays");
  if (!glGenVertexArrays) {
    error_to_console("Failed to get functions.");
  }
  glGetAttribLocation =
      (PFNGLGETATTRIBLOCATIONPROC)wglGetProcAddress("glGetAttribLocation");
  if (!glGetAttribLocation) {
    error_to_console("Failed to get functions.");
  }
  glGetProgramInfoLog =
      (PFNGLGETPROGRAMINFOLOGPROC)wglGetProcAddress("glGetProgramInfoLog");
  if (!glGetProgramInfoLog) {
    error_to_console("Failed to get functions.");
  }
  glGetProgramiv = (PFNGLGETPROGRAMIVPROC)wglGetProcAddress("glGetProgramiv");
  if (!glGetProgramiv) {
    error_to_console("Failed to get functions.");
  }
  glGetShaderInfoLog =
      (PFNGLGETSHADERINFOLOGPROC)wglGetProcAddress("glGetShaderInfoLog");
  if (!glGetShaderInfoLog) {
    error_to_console("Failed to get functions.");
  }
  glGetShaderiv = (PFNGLGETSHADERIVPROC)wglGetProcAddress("glGetShaderiv");
  if (!glGetShaderiv) {
    error_to_console("Failed to get functions.");
  }
  glLinkProgram = (PFNGLLINKPROGRAMPROC)wglGetProcAddress("glLinkProgram");
  if (!glLinkProgram) {
    error_to_console("Failed to get functions.");
  }
  glShaderSource = (PFNGLSHADERSOURCEPROC)wglGetProcAddress("glShaderSource");
  if (!glShaderSource) {
    error_to_console("Failed to get functions.");
  }
  glUseProgram = (PFNGLUSEPROGRAMPROC)wglGetProcAddress("glUseProgram");
  if (!glUseProgram) {
    error_to_console("Failed to get functions.");
  }
  glVertexAttribPointer =
      (PFNGLVERTEXATTRIBPOINTERPROC)wglGetProcAddress("glVertexAttribPointer");
  if (!glVertexAttribPointer) {
    error_to_console("Failed to get functions.");
  }
  glBindAttribLocation =
      (PFNGLBINDATTRIBLOCATIONPROC)wglGetProcAddress("glBindAttribLocation");
  if (!glBindAttribLocation) {
    error_to_console("Failed to get functions.");
  }
  glGetUniformLocation =
      (PFNGLGETUNIFORMLOCATIONPROC)wglGetProcAddress("glGetUniformLocation");
  if (!glGetUniformLocation) {
    error_to_console("Failed to get functions.");
  }
  glUniformMatrix4fv =
      (PFNGLUNIFORMMATRIX4FVPROC)wglGetProcAddress("glUniformMatrix4fv");
  if (!glUniformMatrix4fv) {
    error_to_console("Failed to get functions.");
  }
  glActiveTexture =
      (PFNGLACTIVETEXTUREPROC)wglGetProcAddress("glActiveTexture");
  if (!glActiveTexture) {
    error_to_console("Failed to get functions.");
  }
  glUniform1i = (PFNGLUNIFORM1IPROC)wglGetProcAddress("glUniform1i");
  if (!glUniform1i) {
    error_to_console("Failed to get functions.");
  }
  glGenerateMipmap =
      (PFNGLGENERATEMIPMAPPROC)wglGetProcAddress("glGenerateMipmap");
  if (!glGenerateMipmap) {
    error_to_console("Failed to get functions.");
  }
  glDisableVertexAttribArray =
      (PFNGLDISABLEVERTEXATTRIBARRAYPROC)wglGetProcAddress(
          "glDisableVertexAttribArray");
  if (!glDisableVertexAttribArray) {
    error_to_console("Failed to get functions.");
  }
  glUniform3fv = (PFNGLUNIFORM3FVPROC)wglGetProcAddress("glUniform3fv");
  if (!glUniform3fv) {
    error_to_console("Failed to get functions.");
  }
  glUniform4fv = (PFNGLUNIFORM4FVPROC)wglGetProcAddress("glUniform4fv");
  if (!glUniform4fv) {
    error_to_console("Failed to get functions.");
  }
}

void delete_context(HDC h_dc, HGLRC h_rc) {
  if (!wglMakeCurrent(h_dc, 0)) {
    error_to_console("Failed to detach the rendering context.");
  }
  if (!wglDeleteContext(h_rc)) {
    error_to_console("Failed to delete the rendering context.");
  }
}
