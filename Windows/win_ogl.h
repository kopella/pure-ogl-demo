#ifndef __WIN_OGL_H__
#define __WIN_OGL_H__

#include <Windows.h>

/* Initialize and finalize OpenGL */
HGLRC create_context(HDC h_dc);
void get_functions();

void delete_context(HDC h_dc, HGLRC h_rc);

#endif