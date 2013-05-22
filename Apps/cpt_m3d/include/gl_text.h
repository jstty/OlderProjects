//////////////////////////////////////////////////////////////////////////////
// Program Name:  gltext.h
// Programmer:    Joseph E. Sutton
// Description:	OpenGL Text Print
// Course:        
// Start Date:    10/23/2004
// Last Updated:  
// Version:       1.00
//////////////////////////////////////////////////////////////////////////////

#ifndef _GLTEXT_
#define _GLTEXT_

#include "types_structs.h"

enum
{ 
   GLUT_TEXT_RIGHT  = 1,
   GLUT_TEXT_LEFT   = 2,
   GLUT_TEXT_CENTER = 4,

   GLUT_TEXT_TOP    = 8,
   GLUT_TEXT_MID    = 16,
   GLUT_TEXT_BOTTOM = 32,
};

enum
{
   GLUT_TEXT_DRAW_HORZ = 1,
   GLUT_TEXT_DRAW_VERT = 2
};

class GlText
{
public:
   GlText();

   void SetPos(uInt16 x, uInt16 y);
   void SetFont(void *f, uInt8 fh);
   void SetText(const char *s);
   void SetJustify(uInt8 j);
   void SetDirection(uInt8 d);
   void SetColor(float r, float g, float b);
   void SetColor(double c[3]);

   void Draw();

protected:
   uInt8 justify, font_height, dir;
   void *font;
   char str[256];
   uInt16 xpos, ypos;
   float color[3];

   // temp
   uInt16 x_off_set, y_off_set;
};

#endif
