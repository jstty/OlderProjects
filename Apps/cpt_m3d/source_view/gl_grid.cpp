//////////////////////////////////////////////////////////////////////////////
// Program Name:	gl_grid.cpp
// Programmer:		Joseph E. Sutton
// Description:	OpenGL Grid Class
// Start Date:		2/13/2007
// Version:			1.00
//////////////////////////////////////////////////////////////////////////////

#include <math.h>
#include "../include/gl.h"
#include "../include/gl_grid.h"

void GlGrid::Init()
{
   step = 20.0f;
   zmax = 40.0f;
}

void GlGrid::Loop()
{
}

void GlGrid::SetColor(double f[3], double m[3], double b[3])
{
   front[0] = f[0]/255.0f;
   front[1] = f[1]/255.0f;
   front[2] = f[2]/255.0f;
   
   mid[0]   = m[0]/255.0f;
   mid[1]   = m[1]/255.0f;
   mid[2]   = m[2]/255.0f;
   
   back[0]  = b[0]/255.0f;
   back[1]  = b[1]/255.0f;
   back[2]  = b[2]/255.0f;
}


void GlGrid::Display()
{   
   zcolorstep[0] = -(1.0f/zmax)*fabs((front[0] - back[0])*(step/zmax));
   zcolorstep[1] = -(1.0f/zmax)*fabs((front[1] - back[1])*(step/zmax));
   zcolorstep[2] = -(1.0f/zmax)*fabs((front[2] - back[2])*(step/zmax));
   
   DrawAxis();
   
   glLineWidth(1.0);
   glBegin(GL_LINES);
   for(z = 0.0f; z <= zmax; z += step)
   {      
	   for(x = -50.0f; x <= 50.0f; x += step)
	   {
         // vert lines
         glColor3f(
			 back[0] + z*zcolorstep[0],
			 back[1] + z*zcolorstep[1],
			 back[2] + z*zcolorstep[2]);
         glVertex3f(x, -50.0f, z - 5.0f);
         glVertex3f(x,  50.0f, z - 5.0f);
      
         for(y = -50.0f; y <= 50.0f; y += step)
         {
            // horz lines
            glColor3f(
				 back[0] + z*zcolorstep[0],
				 back[1] + z*zcolorstep[1],
				 back[2] + z*zcolorstep[2]);
            glVertex3f(-50.0f, y, z - 5.0f);
            glVertex3f( 50.0f, y, z - 5.0f);

            // front to back lines
            glColor3f(
				 back[0],
				 back[1],
				 back[2]);
            glVertex3f(x, y, -5.0f);
            glColor3f(
				 front[0],
				 front[1],
				 front[2]);
            glVertex3f(x, y, zmax - 5.0f);
         }
	   }
   }
   glEnd();
}

void GlGrid::DrawAxis()
{
   glLineWidth(1);
   glColor3f(1, 0, 0);
    
   glPushMatrix();
   glTranslatef(-50.0f, 0, 15.0f);
   
   glBegin(GL_LINES);
      // X arrow
      glVertex3f(0,  0, 0);
      glVertex3f(10, 0, 0);
      
      glVertex3f(10, 0, 0);
      glVertex3f(9,  1, 0);
      
      glVertex3f(10, 0, 0);
      glVertex3f(9, -1, 0);
      
      // X letter
      glVertex3f(12,  1, 0);
      glVertex3f(11, -1, 0);
      glVertex3f(11,  1, 0);
      glVertex3f(12, -1, 0);
      
      
      // Y arrow
      glVertex3f(0,  0, 0);
      glVertex3f(0, 10, 0);
      
      glVertex3f(0, 10, 0);
      glVertex3f(1,  9, 0);
      
      glVertex3f(0, 10, 0);
      glVertex3f(-1, 9, 0);
      
      // Y letter
      glVertex3f(1,  13, 0);
      glVertex3f(0,  12, 0);
      glVertex3f(0,  12, 0);
      glVertex3f(-1, 13, 0);
      glVertex3f(0,  12, 0);
      glVertex3f(0,  11, 0);
      
      
      // Z arrow
      glVertex3f(0,  0, 0);
      glVertex3f(0, 0, 10);
      
      glVertex3f(0, 0, 10);
      glVertex3f(1, 0, 9);
      
      glVertex3f(0, 0, 10);
      glVertex3f(-1, 0, 9);
      
      // Z letter
      glVertex3f(-3, 0, 8);
      glVertex3f(-1, 0, 8);
      
      glVertex3f(-1, 0, 10);
      glVertex3f(-3, 0, 8);
      
      glVertex3f(-3, 0, 10);
      glVertex3f(-1, 0, 10);
      
   glEnd();
   glPopMatrix();
}

