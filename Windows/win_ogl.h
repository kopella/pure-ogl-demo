#ifndef __WIN_OGL_H__
#define __WIN_OGL_H__

#include <Windows.h>

/* Initialize and finalize OpenGL */
int get_functions();

HGLRC create_context(HDC h_dc);
void delete_context(HDC h_dc, HGLRC h_rc);

#endif