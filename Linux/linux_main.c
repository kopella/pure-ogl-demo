#include "linux_main.h"
#include "linux_ogl.h"
#include "ogl_gfx.h"

int main(int argc, char* argv[]) {
  Display* display = XOpenDisplay(NULL);
  Window window = create_window(display);

  XMapWindow(display, window);

  int event_mask = (1 << 25) - 1;
  XSelectInput(display, window, event_mask);  // listen to all types of events

  Atom wmDelete = XInternAtom(display, "WM_DELETE_WINDOW", True);
  XSetWMProtocols(display, window, &wmDelete, 1);

  char running = 1;
  while (running) {
    XEvent e;
    XNextEvent(display, &e);
    switch (e.type) {
      case Expose:
        // Render();
        break;
      case ClientMessage:
        running = 0;
        break;
      default:
        break;
    }
  }

  destory_window(display, window);

  XCloseDisplay(display);
  return 0;
}

Window create_window(Display* display) {
  int screen = DefaultScreen(display);
  int width = 640;
  int height = 480;
  int screen_width = DisplayWidth(display, screen);
  int screen_height = DisplayHeight(display, screen);

  return XCreateWindow(
      display, XRootWindow(display, screen), (screen_width - width) / 2,
      (screen_height - height) / 2, width, height, 0, CopyFromParent,
      InputOutput, DefaultVisual(display, screen), 0, 0);
}

void destory_window(Display* display, Window window) {
  XDestroyWindow(display, window);
}