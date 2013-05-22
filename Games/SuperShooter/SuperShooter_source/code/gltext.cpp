//////////////////////////////////////////////////////////////////////////////
// Program Name:  gltext.cpp
// Programmer:    Joseph E. Sutton
// Description:	OpenGL Text Print
// Course:        cs371
// Start Date:    10/23/2004
// Last Updated:  
// Version:       1.00
//////////////////////////////////////////////////////////////////////////////

#include "gltext.h"

glText::glText()
{
   font = GLUT_BITMAP_HELVETICA_18;
   font_height = 18;
   justify = GLUT_TEXT_RIGHT | GLUT_TEXT_TOP;
   memset(str, '\0', 256);
}


void glText::SetText(const char *s)
{
   strncpy(str, s, 255);
}

void glText::Draw()
{
   if(str != NULL)
   {
      x_off_set = y_off_set = 0;
      if(!(justify & GLUT_TEXT_RIGHT))
      {
         x_off_set = glutBitmapLength(font, (unsigned char *)str);
         if(justify & GLUT_TEXT_CENTER)
            x_off_set /= 2;
      }

      //
      if(!(justify & GLUT_TEXT_TOP))
      {
         y_off_set = font_height;
         if(justify & GLUT_TEXT_MID)
            y_off_set /= 2;
      }
      //
      
      glColor3fv(color);
      glRasterPos2i(xpos - x_off_set, ypos - y_off_set);
      for(char *ch = str; *ch != '\0'; ch++)
      {
         /*
         if(*ch == '\n')
         {
            y_off_set -= font_height;
            glRasterPos2i(xpos - x_off_set, ypos - y_off_set);
         }
         */

         glutBitmapCharacter(font, *ch);
      }
   }
}
