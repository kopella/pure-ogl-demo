#include "win_main.h"

static GLvoid ErrorBox(LPCSTR msg) {
  MessageBox(NULL, msg, "Error", MB_OK | MB_ICONEXCLAMATION);
  exit(EXIT_FAILURE);
}

int main() {
  HINSTANCE h_wgl_inst = GetModuleHandle(0);
  HWND h_wgl_wnd = MyCreateWnd(h_wgl_inst);
  HDC h_wgl_dc = GetDC(h_wgl_wnd);

  HGLRC h_wgl_rc = MyInitOgl(h_wgl_dc);

  ShowWindow(h_wgl_wnd, SW_SHOW);
  UpdateWindow(h_wgl_wnd);

  GLuint shader_prog = MyOglLoadShader();
  GLuint v_array_obj = MyOglLoadVertex();

  boolean running = 1;
  while (running) {
    MSG msg;
    while (PeekMessage(&msg, 0, 0, 0, PM_REMOVE)) {
      if (msg.message == WM_QUIT) {
        running = 0;
      } else {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
      }
    }

    glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    MyOglDrawScene(shader_prog, v_array_obj);

    SwapBuffers(h_wgl_dc);
  }

  MyKillWgl(h_wgl_inst, h_wgl_wnd, h_wgl_dc, h_wgl_rc);
  return 0;
}

HWND MyCreateWnd(HINSTANCE h_inst) {
  WNDCLASS wnd_class = {
      .style = CS_HREDRAW | CS_VREDRAW,
      .lpfnWndProc = MyWndCallback,
      .hInstance = h_inst,
      .hCursor = LoadCursor(0, IDC_ARROW),
      .hbrBackground = 0,
      .lpszClassName = "Pure WGL Demo",
  };

  if (!RegisterClass(&wnd_class)) {
    ErrorBox("Failed to register window class.");
  }

  RECT rect = {
      .right = 960,
      .bottom = 540,
  };
  AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, 0);

  HWND h_wnd = CreateWindow(wnd_class.lpszClassName, "Pure WGL Demo",
                            WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT,
                            rect.right - rect.left, rect.bottom - rect.top, 0,
                            0, h_inst, 0);

  if (!h_wnd) {
    ErrorBox("Failed to create window.");
  }

  return h_wnd;
}

LRESULT CALLBACK MyWndCallback(HWND h_wnd, UINT msg, WPARAM w_param,
                               LPARAM l_param) {
  LRESULT result = 0;

  switch (msg) {
    case WM_CLOSE:
    case WM_DESTROY:
      PostQuitMessage(0);
      break;
    case WM_SIZE:
      MyReSizeGLScene(LOWORD(l_param), HIWORD(l_param));
      break;
    default:
      result = DefWindowProcA(h_wnd, msg, w_param, l_param);
      break;
  }

  return result;
}

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

BOOL MyLoadOglFunc(GLvoid) {
  glAttachShader = (PFNGLATTACHSHADERPROC)wglGetProcAddress("glAttachShader");
  if (!glAttachShader) {
    return 0;
  }
  glBindBuffer = (PFNGLBINDBUFFERPROC)wglGetProcAddress("glBindBuffer");
  if (!glBindBuffer) {
    return 0;
  }
  glBindVertexArray =
      (PFNGLBINDVERTEXARRAYPROC)wglGetProcAddress("glBindVertexArray");
  if (!glBindVertexArray) {
    return 0;
  }
  glBufferData = (PFNGLBUFFERDATAPROC)wglGetProcAddress("glBufferData");
  if (!glBufferData) {
    return 0;
  }
  glCompileShader =
      (PFNGLCOMPILESHADERPROC)wglGetProcAddress("glCompileShader");
  if (!glCompileShader) {
    return 0;
  }
  glCreateProgram =
      (PFNGLCREATEPROGRAMPROC)wglGetProcAddress("glCreateProgram");
  if (!glCreateProgram) {
    return 0;
  }
  glCreateShader = (PFNGLCREATESHADERPROC)wglGetProcAddress("glCreateShader");
  if (!glCreateShader) {
    return 0;
  }
  glDeleteBuffers =
      (PFNGLDELETEBUFFERSPROC)wglGetProcAddress("glDeleteBuffers");
  if (!glDeleteBuffers) {
    return 0;
  }
  glDeleteProgram =
      (PFNGLDELETEPROGRAMPROC)wglGetProcAddress("glDeleteProgram");
  if (!glDeleteProgram) {
    return 0;
  }
  glDeleteShader = (PFNGLDELETESHADERPROC)wglGetProcAddress("glDeleteShader");
  if (!glDeleteShader) {
    return 0;
  }
  glDeleteVertexArrays =
      (PFNGLDELETEVERTEXARRAYSPROC)wglGetProcAddress("glDeleteVertexArrays");
  if (!glDeleteVertexArrays) {
    return 0;
  }
  glDetachShader = (PFNGLDETACHSHADERPROC)wglGetProcAddress("glDetachShader");
  if (!glDetachShader) {
    return 0;
  }
  glEnableVertexAttribArray =
      (PFNGLENABLEVERTEXATTRIBARRAYPROC)wglGetProcAddress(
          "glEnableVertexAttribArray");
  if (!glEnableVertexAttribArray) {
    return 0;
  }
  glGenBuffers = (PFNGLGENBUFFERSPROC)wglGetProcAddress("glGenBuffers");
  if (!glGenBuffers) {
    return 0;
  }
  glGenVertexArrays =
      (PFNGLGENVERTEXARRAYSPROC)wglGetProcAddress("glGenVertexArrays");
  if (!glGenVertexArrays) {
    return 0;
  }
  glGetAttribLocation =
      (PFNGLGETATTRIBLOCATIONPROC)wglGetProcAddress("glGetAttribLocation");
  if (!glGetAttribLocation) {
    return 0;
  }
  glGetProgramInfoLog =
      (PFNGLGETPROGRAMINFOLOGPROC)wglGetProcAddress("glGetProgramInfoLog");
  if (!glGetProgramInfoLog) {
    return 0;
  }
  glGetProgramiv = (PFNGLGETPROGRAMIVPROC)wglGetProcAddress("glGetProgramiv");
  if (!glGetProgramiv) {
    return 0;
  }
  glGetShaderInfoLog =
      (PFNGLGETSHADERINFOLOGPROC)wglGetProcAddress("glGetShaderInfoLog");
  if (!glGetShaderInfoLog) {
    return 0;
  }
  glGetShaderiv = (PFNGLGETSHADERIVPROC)wglGetProcAddress("glGetShaderiv");
  if (!glGetShaderiv) {
    return 0;
  }
  glLinkProgram = (PFNGLLINKPROGRAMPROC)wglGetProcAddress("glLinkProgram");
  if (!glLinkProgram) {
    return 0;
  }
  glShaderSource = (PFNGLSHADERSOURCEPROC)wglGetProcAddress("glShaderSource");
  if (!glShaderSource) {
    return 0;
  }
  glUseProgram = (PFNGLUSEPROGRAMPROC)wglGetProcAddress("glUseProgram");
  if (!glUseProgram) {
    return 0;
  }
  glVertexAttribPointer =
      (PFNGLVERTEXATTRIBPOINTERPROC)wglGetProcAddress("glVertexAttribPointer");
  if (!glVertexAttribPointer) {
    return 0;
  }
  glBindAttribLocation =
      (PFNGLBINDATTRIBLOCATIONPROC)wglGetProcAddress("glBindAttribLocation");
  if (!glBindAttribLocation) {
    return 0;
  }
  glGetUniformLocation =
      (PFNGLGETUNIFORMLOCATIONPROC)wglGetProcAddress("glGetUniformLocation");
  if (!glGetUniformLocation) {
    return 0;
  }
  glUniformMatrix4fv =
      (PFNGLUNIFORMMATRIX4FVPROC)wglGetProcAddress("glUniformMatrix4fv");
  if (!glUniformMatrix4fv) {
    return 0;
  }
  glActiveTexture =
      (PFNGLACTIVETEXTUREPROC)wglGetProcAddress("glActiveTexture");
  if (!glActiveTexture) {
    return 0;
  }
  glUniform1i = (PFNGLUNIFORM1IPROC)wglGetProcAddress("glUniform1i");
  if (!glUniform1i) {
    return 0;
  }
  glGenerateMipmap =
      (PFNGLGENERATEMIPMAPPROC)wglGetProcAddress("glGenerateMipmap");
  if (!glGenerateMipmap) {
    return 0;
  }
  glDisableVertexAttribArray =
      (PFNGLDISABLEVERTEXATTRIBARRAYPROC)wglGetProcAddress(
          "glDisableVertexAttribArray");
  if (!glDisableVertexAttribArray) {
    return 0;
  }
  glUniform3fv = (PFNGLUNIFORM3FVPROC)wglGetProcAddress("glUniform3fv");
  if (!glUniform3fv) {
    return 0;
  }
  glUniform4fv = (PFNGLUNIFORM4FVPROC)wglGetProcAddress("glUniform4fv");
  if (!glUniform4fv) {
    return 0;
  }
  return 1;
}

HGLRC MyInitOgl(HDC h_dc) {
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
    ErrorBox("Failed to find a suitable pixel format.");
  }
  if (!SetPixelFormat(h_dc, n_pf, &des_pf)) {
    ErrorBox("Failed to set the pixel format.");
  }
  HGLRC h_rc = wglCreateContext(h_dc);
  if (!h_rc) {
    ErrorBox("Failed to create a OpenGL rendering context.");
  }
  if (!wglMakeCurrent(h_dc, h_rc)) {
    ErrorBox("Failed to activate the OpenGL rendering context.");
  }
  if (!MyLoadOglFunc()) {
    ErrorBox("Failed to load OpenGL's function.");
  }

  return h_rc;
}

GLvoid MyKillWgl(HINSTANCE h_inst, HWND h_wnd, HDC h_dc, HGLRC h_rc) {
  if (!wglMakeCurrent(h_dc, 0)) {
    ErrorBox("Failed to detach the rendering context.");
  }
  if (!wglDeleteContext(h_rc)) {
    ErrorBox("Failed to delete the rendering context.");
  }
  if (!ReleaseDC(h_wnd, h_dc)) {
    ErrorBox("Failed to release the device context.");
  }
  if (!DestroyWindow(h_wnd)) {
    ErrorBox("Failed to destroy the window.");
  }
  if (!UnregisterClass("Pure WGL Demo", h_inst)) {
    ErrorBox("Failed to unregister the class.");
  }
}

GLvoid MyReSizeGLScene(GLsizei width, GLsizei height) {
  glViewport(0, 0, width, height);
}

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

GLuint MyOglLoadShader() {
  const char* v_shader_src =
      "#version 330 core\n"
      "layout (location = 0) in vec3 aPos;\n"
      "void main()\n"
      "{\n"
      "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
      "}\0";
  const char* f_shader_src =
      "#version 330 core\n"
      "out vec4 FragColor;\n"
      "void main()\n"
      "{\n"
      "   FragColor = vec4(1.0f, 0.5f, 0.2f, 1.0f);\n"
      "}\n\0";

  GLuint v_shader = glCreateShader(GL_VERTEX_SHADER);
  glShaderSource(v_shader, 1, &v_shader_src, NULL);
  glCompileShader(v_shader);

  GLuint f_shader = glCreateShader(GL_FRAGMENT_SHADER);
  glShaderSource(f_shader, 1, &f_shader_src, NULL);
  glCompileShader(f_shader);

  GLuint shader_prog = glCreateProgram();
  glAttachShader(shader_prog, v_shader);
  glAttachShader(shader_prog, f_shader);
  glLinkProgram(shader_prog);

  glDeleteShader(v_shader);
  glDeleteShader(f_shader);

  return shader_prog;
}

GLuint MyOglLoadVertex() {
  float vertices[] = {
      -0.5f, -0.5f, 0.0f,  // left
      0.5f,  -0.5f, 0.0f,  // right
      0.0f,  0.5f,  0.0f   // top
  };

  GLuint v_buffer_obj, v_array_obj;
  glGenVertexArrays(1, &v_array_obj);
  glGenBuffers(1, &v_buffer_obj);

  glBindVertexArray(v_array_obj);

  glBindBuffer(GL_ARRAY_BUFFER, v_buffer_obj);
  glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

  glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
  glEnableVertexAttribArray(0);

  glBindBuffer(GL_ARRAY_BUFFER, 0);

  glBindVertexArray(0);

  return v_array_obj;
}

GLvoid MyOglDrawScene(GLuint shader_prog, GLuint v_array_obj) {
  glUseProgram(shader_prog);
  glBindVertexArray(v_array_obj);
  glDrawArrays(GL_TRIANGLES, 0, 3);
}