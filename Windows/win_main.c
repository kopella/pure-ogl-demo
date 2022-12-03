#include "win_main.h"

static GLvoid ErrorBox(LPCSTR msg) {
  MessageBox(NULL, msg, "Error", MB_OK | MB_ICONEXCLAMATION);
  exit(EXIT_FAILURE);
}

int main(int argc, char* argv[]) {
  HINSTANCE h_inst = GetModuleHandle(0);

  HWND h_wnd = create_window(h_inst);
  HDC h_dc = GetDC(h_wnd);

  HGLRC h_rc = create_context(h_dc);
  get_functions();

  ShowWindow(h_wnd, SW_SHOW);
  UpdateWindow(h_wnd);
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

    draw_scene();
    SwapBuffers(h_dc);
  }

  delete_context(h_dc, h_rc);
  destory_window(h_inst, h_wnd, h_dc);
}

HWND create_window(HINSTANCE h_inst) {
  WNDCLASS wnd_class = {
      .style = CS_HREDRAW | CS_VREDRAW,
      .lpfnWndProc = window_callback,
      .hInstance = h_inst,
      .hCursor = LoadCursor(0, IDC_ARROW),
      .hbrBackground = 0,
      .lpszClassName = "Pure OpenGL Demo",
  };

  if (!RegisterClass(&wnd_class)) {
    ErrorBox("Failed to register window class.");
  }

  RECT rect = {
      .right = 960,
      .bottom = 540,
  };
  AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, 0);

  HWND h_wnd = CreateWindow(
      wnd_class.lpszClassName, "Pure OpenGL Demo", WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, CW_USEDEFAULT, rect.right - rect.left,
      rect.bottom - rect.top, 0, 0, h_inst, 0);

  if (!h_wnd) {
    ErrorBox("Failed to create window.");
  }

  return h_wnd;
}
LRESULT CALLBACK
window_callback(HWND h_wnd, UINT msg, WPARAM w_param, LPARAM l_param) {
  LRESULT result = 0;

  switch (msg) {
    case WM_CLOSE:
    case WM_DESTROY:
      PostQuitMessage(0);
      break;
    case WM_SIZE:
      // MyReSizeGLScene(LOWORD(l_param), HIWORD(l_param));
      break;
    default:
      result = DefWindowProc(h_wnd, msg, w_param, l_param);
      break;
  }

  return result;
}

void destory_window(HINSTANCE h_inst, HWND h_wnd, HDC h_dc) {
  if (!ReleaseDC(h_wnd, h_dc)) {
    ErrorBox("Failed to release the device context.");
  }
  if (!DestroyWindow(h_wnd)) {
    ErrorBox("Failed to destroy the window.");
  }
  if (!UnregisterClass("Pure OpenGL Demo", h_inst)) {
    ErrorBox("Failed to unregister the class.");
  }
}

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

  return h_rc;
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

void get_functions() {
  glAttachShader = (PFNGLATTACHSHADERPROC)wglGetProcAddress("glAttachShader");
  if (!glAttachShader) {
    ErrorBox("Failed to get functions.");
  }
  glBindBuffer = (PFNGLBINDBUFFERPROC)wglGetProcAddress("glBindBuffer");
  if (!glBindBuffer) {
    ErrorBox("Failed to get functions.");
  }
  glBindVertexArray =
      (PFNGLBINDVERTEXARRAYPROC)wglGetProcAddress("glBindVertexArray");
  if (!glBindVertexArray) {
    ErrorBox("Failed to get functions.");
  }
  glBufferData = (PFNGLBUFFERDATAPROC)wglGetProcAddress("glBufferData");
  if (!glBufferData) {
    ErrorBox("Failed to get functions.");
  }
  glCompileShader =
      (PFNGLCOMPILESHADERPROC)wglGetProcAddress("glCompileShader");
  if (!glCompileShader) {
    ErrorBox("Failed to get functions.");
  }
  glCreateProgram =
      (PFNGLCREATEPROGRAMPROC)wglGetProcAddress("glCreateProgram");
  if (!glCreateProgram) {
    ErrorBox("Failed to get functions.");
  }
  glCreateShader = (PFNGLCREATESHADERPROC)wglGetProcAddress("glCreateShader");
  if (!glCreateShader) {
    ErrorBox("Failed to get functions.");
  }
  glDeleteBuffers =
      (PFNGLDELETEBUFFERSPROC)wglGetProcAddress("glDeleteBuffers");
  if (!glDeleteBuffers) {
    ErrorBox("Failed to get functions.");
  }
  glDeleteProgram =
      (PFNGLDELETEPROGRAMPROC)wglGetProcAddress("glDeleteProgram");
  if (!glDeleteProgram) {
    ErrorBox("Failed to get functions.");
  }
  glDeleteShader = (PFNGLDELETESHADERPROC)wglGetProcAddress("glDeleteShader");
  if (!glDeleteShader) {
    ErrorBox("Failed to get functions.");
  }
  glDeleteVertexArrays =
      (PFNGLDELETEVERTEXARRAYSPROC)wglGetProcAddress("glDeleteVertexArrays");
  if (!glDeleteVertexArrays) {
    ErrorBox("Failed to get functions.");
  }
  glDetachShader = (PFNGLDETACHSHADERPROC)wglGetProcAddress("glDetachShader");
  if (!glDetachShader) {
    ErrorBox("Failed to get functions.");
  }
  glEnableVertexAttribArray =
      (PFNGLENABLEVERTEXATTRIBARRAYPROC)wglGetProcAddress(
          "glEnableVertexAttribArray");
  if (!glEnableVertexAttribArray) {
    ErrorBox("Failed to get functions.");
  }
  glGenBuffers = (PFNGLGENBUFFERSPROC)wglGetProcAddress("glGenBuffers");
  if (!glGenBuffers) {
    ErrorBox("Failed to get functions.");
  }
  glGenVertexArrays =
      (PFNGLGENVERTEXARRAYSPROC)wglGetProcAddress("glGenVertexArrays");
  if (!glGenVertexArrays) {
    ErrorBox("Failed to get functions.");
  }
  glGetAttribLocation =
      (PFNGLGETATTRIBLOCATIONPROC)wglGetProcAddress("glGetAttribLocation");
  if (!glGetAttribLocation) {
    ErrorBox("Failed to get functions.");
  }
  glGetProgramInfoLog =
      (PFNGLGETPROGRAMINFOLOGPROC)wglGetProcAddress("glGetProgramInfoLog");
  if (!glGetProgramInfoLog) {
    ErrorBox("Failed to get functions.");
  }
  glGetProgramiv = (PFNGLGETPROGRAMIVPROC)wglGetProcAddress("glGetProgramiv");
  if (!glGetProgramiv) {
    ErrorBox("Failed to get functions.");
  }
  glGetShaderInfoLog =
      (PFNGLGETSHADERINFOLOGPROC)wglGetProcAddress("glGetShaderInfoLog");
  if (!glGetShaderInfoLog) {
    ErrorBox("Failed to get functions.");
  }
  glGetShaderiv = (PFNGLGETSHADERIVPROC)wglGetProcAddress("glGetShaderiv");
  if (!glGetShaderiv) {
    ErrorBox("Failed to get functions.");
  }
  glLinkProgram = (PFNGLLINKPROGRAMPROC)wglGetProcAddress("glLinkProgram");
  if (!glLinkProgram) {
    ErrorBox("Failed to get functions.");
  }
  glShaderSource = (PFNGLSHADERSOURCEPROC)wglGetProcAddress("glShaderSource");
  if (!glShaderSource) {
    ErrorBox("Failed to get functions.");
  }
  glUseProgram = (PFNGLUSEPROGRAMPROC)wglGetProcAddress("glUseProgram");
  if (!glUseProgram) {
    ErrorBox("Failed to get functions.");
  }
  glVertexAttribPointer =
      (PFNGLVERTEXATTRIBPOINTERPROC)wglGetProcAddress("glVertexAttribPointer");
  if (!glVertexAttribPointer) {
    ErrorBox("Failed to get functions.");
  }
  glBindAttribLocation =
      (PFNGLBINDATTRIBLOCATIONPROC)wglGetProcAddress("glBindAttribLocation");
  if (!glBindAttribLocation) {
    ErrorBox("Failed to get functions.");
  }
  glGetUniformLocation =
      (PFNGLGETUNIFORMLOCATIONPROC)wglGetProcAddress("glGetUniformLocation");
  if (!glGetUniformLocation) {
    ErrorBox("Failed to get functions.");
  }
  glUniformMatrix4fv =
      (PFNGLUNIFORMMATRIX4FVPROC)wglGetProcAddress("glUniformMatrix4fv");
  if (!glUniformMatrix4fv) {
    ErrorBox("Failed to get functions.");
  }
  glActiveTexture =
      (PFNGLACTIVETEXTUREPROC)wglGetProcAddress("glActiveTexture");
  if (!glActiveTexture) {
    ErrorBox("Failed to get functions.");
  }
  glUniform1i = (PFNGLUNIFORM1IPROC)wglGetProcAddress("glUniform1i");
  if (!glUniform1i) {
    ErrorBox("Failed to get functions.");
  }
  glGenerateMipmap =
      (PFNGLGENERATEMIPMAPPROC)wglGetProcAddress("glGenerateMipmap");
  if (!glGenerateMipmap) {
    ErrorBox("Failed to get functions.");
  }
  glDisableVertexAttribArray =
      (PFNGLDISABLEVERTEXATTRIBARRAYPROC)wglGetProcAddress(
          "glDisableVertexAttribArray");
  if (!glDisableVertexAttribArray) {
    ErrorBox("Failed to get functions.");
  }
  glUniform3fv = (PFNGLUNIFORM3FVPROC)wglGetProcAddress("glUniform3fv");
  if (!glUniform3fv) {
    ErrorBox("Failed to get functions.");
  }
  glUniform4fv = (PFNGLUNIFORM4FVPROC)wglGetProcAddress("glUniform4fv");
  if (!glUniform4fv) {
    ErrorBox("Failed to get functions.");
  }
}

void delete_context(HDC h_dc, HGLRC h_rc) {
  if (!wglMakeCurrent(h_dc, 0)) {
    ErrorBox("Failed to detach the rendering context.");
  }
  if (!wglDeleteContext(h_rc)) {
    ErrorBox("Failed to delete the rendering context.");
  }
}

void draw_scene() {
  glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  GLuint shader_prog = load_shader();
  GLuint v_array_obj = load_vertex();

  glUseProgram(shader_prog);
  glBindVertexArray(v_array_obj);
  glDrawArrays(GL_TRIANGLES, 0, 3);
}

GLuint load_shader() {
  const char* v_shader_src =
      "#version 330 core\n"
      "layout (location = 0) in vec3 aPos;\n"
      "void main()\n"
      "{\n"
      "   gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0);\n"
      "}\n\0";
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
  glClearColor(0.1f, 0.2f, 0.3f, 1.0f);
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

  return shader_prog;
}

GLuint load_vertex() {
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