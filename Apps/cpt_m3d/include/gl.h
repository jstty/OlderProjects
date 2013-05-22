//////////////////////////////////////////////////////////////////////////////
// Program Name:	gl.h
// Programmer:		Joseph E. Sutton
// Description:	OpenGl header
// Start Date:		5/6/2008
// Version:			2.00
//////////////////////////////////////////////////////////////////////////////
#ifndef __GL__
#define __GL__

// OpenGL
#ifdef WIN32
   #include <GL/glut.h>
#else // OS X
   #include <GLUT/glut.h>
#endif

#define GLUT_KEY_ESC 27
#define GLUT_MOUSE_SCROLL_UP 3
#define GLUT_MOUSE_SCROLL_DOWN 4


#ifndef GLUT_WHEEL_UP
   #define GLUT_WHEEL_UP   3
   #define GLUT_WHEEL_DOWN 4
#endif


#endif // __GL__
