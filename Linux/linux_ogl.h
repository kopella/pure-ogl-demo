#ifndef __LINUX_OGL_H__
#define __LINUX_OGL_H__

#include <GL/glx.h>

/* Initialize and finalize OpenGL */
// TODO: Functions about initialize and finalize OpenGL in Linux.
void create_context();
void get_functions();

void delete_context();

#endif