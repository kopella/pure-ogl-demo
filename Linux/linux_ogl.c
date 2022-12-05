#include "linux_ogl.h"
#include "ogl_func.h"

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

PFNGLGENERATEMIPMAPPROC glGenerateMipmap;

PFNGLXCREATECONTEXTATTRIBSARBPROC glXCreateContextAttribsARB;

void get_functions() {
  glXCreateContextAttribsARB =
      (PFNGLXCREATECONTEXTATTRIBSARBPROC)glXGetProcAddressARB(
          (const GLubyte*)"glXCreateContextAttribsARB");
  glAttachShader = (PFNGLATTACHSHADERPROC)glXGetProcAddressARB(
      (const GLubyte*)"glAttachShader");
  glBindBuffer =
      (PFNGLBINDBUFFERPROC)glXGetProcAddressARB((const GLubyte*)"glBindBuffer");
  glBindVertexArray = (PFNGLBINDVERTEXARRAYPROC)glXGetProcAddressARB(
      (const GLubyte*)"glBindVertexArray");
  glBufferData =
      (PFNGLBUFFERDATAPROC)glXGetProcAddressARB((const GLubyte*)"glBufferData");
  glCompileShader = (PFNGLCOMPILESHADERPROC)glXGetProcAddressARB(
      (const GLubyte*)"glCompileShader");
  glCreateProgram = (PFNGLCREATEPROGRAMPROC)glXGetProcAddressARB(
      (const GLubyte*)"glCreateProgram");
  glCreateShader = (PFNGLCREATESHADERPROC)glXGetProcAddressARB(
      (const GLubyte*)"glCreateShader");
  glDeleteBuffers = (PFNGLDELETEBUFFERSPROC)glXGetProcAddressARB(
      (const GLubyte*)"glDeleteBuffers");
  glDeleteProgram = (PFNGLDELETEPROGRAMPROC)glXGetProcAddressARB(
      (const GLubyte*)"glDeleteProgram");
  glDeleteShader = (PFNGLDELETESHADERPROC)glXGetProcAddressARB(
      (const GLubyte*)"glDeleteShader");
  glDeleteVertexArrays = (PFNGLDELETEVERTEXARRAYSPROC)glXGetProcAddressARB(
      (const GLubyte*)"glDeleteVertexArrays");
  glDetachShader = (PFNGLDETACHSHADERPROC)glXGetProcAddressARB(
      (const GLubyte*)"glDetachShader");
  glEnableVertexAttribArray =
      (PFNGLENABLEVERTEXATTRIBARRAYPROC)glXGetProcAddressARB(
          (const GLubyte*)"glEnableVertexAttribArray");
  glGenBuffers =
      (PFNGLGENBUFFERSPROC)glXGetProcAddressARB((const GLubyte*)"glGenBuffers");
  glGenVertexArrays = (PFNGLGENVERTEXARRAYSPROC)glXGetProcAddressARB(
      (const GLubyte*)"glGenVertexArrays");
  glGetAttribLocation = (PFNGLGETATTRIBLOCATIONPROC)glXGetProcAddressARB(
      (const GLubyte*)"glGetAttribLocation");
  glGetProgramInfoLog = (PFNGLGETPROGRAMINFOLOGPROC)glXGetProcAddressARB(
      (const GLubyte*)"glGetProgramInfoLog");
  glGetProgramiv = (PFNGLGETPROGRAMIVPROC)glXGetProcAddressARB(
      (const GLubyte*)"glGetProgramiv");
  glGetShaderInfoLog = (PFNGLGETSHADERINFOLOGPROC)glXGetProcAddressARB(
      (const GLubyte*)"glGetShaderInfoLog");
  glGetShaderiv = (PFNGLGETSHADERIVPROC)glXGetProcAddressARB(
      (const GLubyte*)"glGetShaderiv");
  glLinkProgram = (PFNGLLINKPROGRAMPROC)glXGetProcAddressARB(
      (const GLubyte*)"glLinkProgram");
  glShaderSource = (PFNGLSHADERSOURCEPROC)glXGetProcAddressARB(
      (const GLubyte*)"glShaderSource");
  glUseProgram =
      (PFNGLUSEPROGRAMPROC)glXGetProcAddressARB((const GLubyte*)"glUseProgram");
  glVertexAttribPointer = (PFNGLVERTEXATTRIBPOINTERPROC)glXGetProcAddressARB(
      (const GLubyte*)"glVertexAttribPointer");
  glBindAttribLocation = (PFNGLBINDATTRIBLOCATIONPROC)glXGetProcAddressARB(
      (const GLubyte*)"glBindAttribLocation");
  glGetUniformLocation = (PFNGLGETUNIFORMLOCATIONPROC)glXGetProcAddressARB(
      (const GLubyte*)"glGetUniformLocation");
  glUniformMatrix4fv = (PFNGLUNIFORMMATRIX4FVPROC)glXGetProcAddressARB(
      (const GLubyte*)"glUniformMatrix4fv");
  glUniform1i =
      (PFNGLUNIFORM1IPROC)glXGetProcAddressARB((const GLubyte*)"glUniform1i");
  glGenerateMipmap = (PFNGLGENERATEMIPMAPPROC)glXGetProcAddressARB(
      (const GLubyte*)"glGenerateMipmap");
  glDisableVertexAttribArray =
      (PFNGLDISABLEVERTEXATTRIBARRAYPROC)glXGetProcAddressARB(
          (const GLubyte*)"glDisableVertexAttribArray");
  glUniform3fv =
      (PFNGLUNIFORM3FVPROC)glXGetProcAddressARB((const GLubyte*)"glUniform3fv");
  glUniform4fv =
      (PFNGLUNIFORM4FVPROC)glXGetProcAddressARB((const GLubyte*)"glUniform4fv");
}

GLXContext create_context(Display* display, Window window, int screen) {
  get_functions();

  static int visual_attribs[] = {
      GLX_RENDER_TYPE,
      GLX_RGBA_BIT,
      GLX_DRAWABLE_TYPE,
      GLX_WINDOW_BIT,
      GLX_DOUBLEBUFFER,
      1,
      GLX_RED_SIZE,
      1,
      GLX_GREEN_SIZE,
      1,
      GLX_BLUE_SIZE,
      1,
      None};

  int n_config;
  GLXFBConfig* config =
      glXChooseFBConfig(display, screen, visual_attribs, &n_config);

  XVisualInfo* visualInfo = glXGetVisualFromFBConfig(display, *config);

  static int context_attribs[] = {
      GLX_CONTEXT_MAJOR_VERSION_ARB, 4, GLX_CONTEXT_MINOR_VERSION_ARB, 2, None};

  GLXContext context = glXCreateContextAttribsARB(
      display, config[0], NULL, GL_TRUE, context_attribs);

  glXMakeCurrent(display, window, context);

  return context;
}