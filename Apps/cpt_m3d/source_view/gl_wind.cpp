//////////////////////////////////////////////////////////////////////////////
// Program Name:	gl_wind.cpp
// Programmer:		Joseph E. Sutton
// Description:	OpenGL Wind Class
// Start Date:		2/13/2007
// Version:			1.00
//////////////////////////////////////////////////////////////////////////////

#include "../include/gl.h"
#include "../include/gl_wind.h"

void GlWind::Init()
{
   ed = NULL;
   p.z = 0;
   p.den = 2.5;
   dir.x = 1.0;
   dir.y = 0.0;
   dir.z = 0.0;
}

void GlWind::Loop()
{
}

void GlWind::SetEnvData(iEnvData *edata)
{
   ed = edata;
}

void GlWind::SetMax(Point3D m)
{
   x_max = m.x;
   y_max = m.y;
   z_max = m.z;
}


void GlWind::SetColor(double c[3])
{
   color[0] = c[0];
   color[1] = c[1];
   color[2] = c[2];
}

void GlWind::Display()
{
   glColor3f( color[0], color[1], color[2]);
   glLineWidth(1.5);

   for(x = 0; x < x_max+1; x += 10)
   {
      for(y = 0; y < y_max+1; y += 10)
      {
         p.x = x;
         p.y = y;
         if(ed != NULL)
            ed->GetWindDir(dir, p);

         glBegin(GL_LINES);
         glVertex3f(p.x - (x_max*0.5), 
                    p.y - (y_max*0.5), 
                    p.z - (z_max*0.5));

         glVertex3f(p.x + p.den*dir.x - (x_max*0.5), 
                    p.y + p.den*dir.y - (y_max*0.5), 
                    p.z + p.den*dir.z - (z_max*0.5));
         
         glEnd();
      }
   }
}