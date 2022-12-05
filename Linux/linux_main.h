#ifndef __LINUX_MAIN_H__
#define __LINUX_MAIN_H__
#include <X11/Xlib.h>

/* Create and destory platform window */
Window create_window(Display* display, int* screen);

void destory_window(Display* display, Window window);

#endif