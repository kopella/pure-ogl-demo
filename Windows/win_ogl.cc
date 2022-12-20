#include "win_ogl.h"

#include "ogl_func.h"
#include "utils.h"

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

void delete_context(HDC h_dc, HGLRC h_rc) {
  if (!wglMakeCurrent(h_dc, 0)) {
    error_to_console("Failed to detach the rendering context.");
  }
  if (!wglDeleteContext(h_rc)) {
    error_to_console("Failed to delete the rendering context.");
  }
}
