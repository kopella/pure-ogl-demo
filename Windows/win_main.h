#ifndef __WIN_MAIN_H__
#define __WIN_MAIN_H__

#include <Windows.h>

/* Create and destory platform window */
HWND create_window(HINSTANCE h_inst);
void destory_window(HINSTANCE h_inst, HWND h_wnd, HDC h_dc);

#endif