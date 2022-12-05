#ifndef __LINUX_OGL_H__
#define __LINUX_OGL_H__

#include <X11/Xlib.h>
#include <GL/glx.h>
#include <GL/glxext.h>

/* Initialize and finalize OpenGL */
void get_functions();

GLXContext create_context(Display* display, Window window, int screen);

void delete_context();

#endif