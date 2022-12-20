#include "win_main.h"
#include "win_ogl.h"

#include "ogl_gfx.h"
#include "utils.h"

int main(int argc, char* argv[]) {
  HINSTANCE h_inst = GetModuleHandle(0);

  HWND h_wnd = create_window(h_inst);
  HDC h_dc = GetDC(h_wnd);

  HGLRC h_rc = create_context(h_dc);
  if (!get_functions()) {
    error_to_console("Failed to load functions of OpenGL.");
  }

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

  return 0;
}

LRESULT CALLBACK
window_callback(HWND h_wnd, UINT msg, WPARAM w_param, LPARAM l_param);

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
    error_to_console("Failed to register window class.");
  }

  RECT rect = {
      .right = 640,
      .bottom = 480,
  };
  AdjustWindowRect(&rect, WS_OVERLAPPEDWINDOW, 0);

  HWND h_wnd = CreateWindow(
      wnd_class.lpszClassName, "Pure OpenGL Demo", WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, CW_USEDEFAULT, rect.right - rect.left,
      rect.bottom - rect.top, 0, 0, h_inst, 0);

  if (!h_wnd) {
    error_to_console("Failed to create window.");
  }

  info_to_console("Window created successfully.");
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
    error_to_console("Failed to release the device context.");
  }
  if (!DestroyWindow(h_wnd)) {
    error_to_console("Failed to destroy the window.");
  }
  if (!UnregisterClass("Pure OpenGL Demo", h_inst)) {
    error_to_console("Failed to unregister the class.");
  }

  info_to_console("Window destroyed successfully.");
}
