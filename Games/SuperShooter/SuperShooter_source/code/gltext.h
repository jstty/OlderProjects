//////////////////////////////////////////////////////////////////////////////
// Program Name:  gltext.h
// Programmer:    Joseph E. Sutton
// Description:	OpenGL Text Print
// Course:        cs371
// Start Date:    10/23/2004
// Last Updated:  
// Version:       1.00
//////////////////////////////////////////////////////////////////////////////
#ifndef _GLTEXT_
#define _GLTEXT_

#include "main.h"

enum
{ 
   GLUT_TEXT_RIGHT  = 1,
   GLUT_TEXT_LEFT   = 2,
   GLUT_TEXT_CENTER = 4,

   GLUT_TEXT_TOP    = 8,
   GLUT_TEXT_MID    = 16,
   GLUT_TEXT_BOTTOM = 32,
};

class glText
{
public:
   glText();

   void SetPos(uInt16 x, uInt16 y) { xpos = x; ypos = y; }
   void SetFont(void *f, uInt8 fh) { font = f; font_height = fh; }
   void SetText(const char *s);
   void SetJustify(uInt8 j) { justify = j; }
   void SetColor(float r, float g, float b) { color[0] = r; color[1] = g; color[2] = b; }

   void Draw();

protected:
   uInt8 justify, font_height;
   void *font;
   char str[256];
   uInt16 xpos, ypos;
   float color[3];

   // temp
   uInt16 x_off_set, y_off_set;
};

#endif
