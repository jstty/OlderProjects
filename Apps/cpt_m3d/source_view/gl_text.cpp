//////////////////////////////////////////////////////////////////////////////
// Program Name:  gltext.cpp
// Programmer:    Joseph E. Sutton
// Description:	OpenGL Text Print
// Course:        
// Start Date:    10/23/2004
// Last Updated:  
// Version:       1.00
//////////////////////////////////////////////////////////////////////////////


#include <string.h>
#include "../include/gl.h"
#include "../include/gl_text.h"

GlText::GlText()
{
   font = GLUT_BITMAP_HELVETICA_18;
   font_height = 18;
   justify = GLUT_TEXT_LEFT | GLUT_TEXT_TOP;
   memset(str, '\0', 256);
   
   xpos = 0;
   ypos = 0;
   
   dir = GLUT_TEXT_DRAW_HORZ;
}

void GlText::SetPos(uInt16 x, uInt16 y)
{  
   xpos = x; ypos = y;
}

void GlText::SetFont(void *f, uInt8 fh)
{
   font = f;
   font_height = fh;
}

void GlText::SetJustify(uInt8 j)
{
   justify = j;
}

void GlText::SetDirection(uInt8 d)
{
   dir = d;
}

void GlText::SetColor(float r, float g, float b)
{
   color[0] = r; color[1] = g; color[2] = b;
}

void GlText::SetColor(double c[3])
{
   color[0] = c[0]; color[1] = c[1]; color[2] = c[2];
}


void GlText::SetText(const char *s)
{
   strncpy(str, s, 255);
}

void GlText::Draw()
{
   if(str != NULL)
   {
      x_off_set = y_off_set = 0;
      if(justify & GLUT_TEXT_RIGHT)
      {
         x_off_set = glutBitmapLength(font, (unsigned char *)str);
         if(justify & GLUT_TEXT_CENTER)
            x_off_set /= 2;
      }
      
      glColor3fv(color);
      glRasterPos2i(xpos - x_off_set, ypos - y_off_set);
      for(char *ch = str; *ch != '\0'; ch++)
      {
         if(*ch == '\n')
         {
            if(dir & GLUT_TEXT_DRAW_HORZ)
            {
               ch++;
            }
            else if(dir & GLUT_TEXT_DRAW_VERT)
            {
               y_off_set += font_height;
               
               if(justify & GLUT_TEXT_BOTTOM)
               {
                  glRasterPos2i(xpos - x_off_set, ypos - y_off_set);
               } else {
                  glRasterPos2i(xpos - x_off_set, ypos + y_off_set);
               }
               
               ch++;
            }
         }

         glutBitmapCharacter(font, *ch);
      }
   }
}
