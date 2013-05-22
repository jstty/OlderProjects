//////////////////////////////////////////////////////////////////////////////
// Program Name:	gl_info.cpp
// Programmer:		Joseph E. Sutton
// Description:	OpenGL Info Class
// Start Date:		5/29/2007
// Version:			1.00
//////////////////////////////////////////////////////////////////////////////

#include <string.h>
#include <stdio.h>

#include "../include/gl.h"
#include "../include/gl_info.h"

GlInfo::GlInfo()
{
   strcpy(info, "");
   
   //text.SetColor(settings->color.text);
   text.SetColor(0, 0, 0);
   text.SetFont(GLUT_BITMAP_8_BY_13, 16);
   text.SetDirection(GLUT_TEXT_DRAW_VERT);
}

GlInfo::~GlInfo()
{
}

void GlInfo::Init()
{
}

void GlInfo::Loop()
{
}

void GlInfo::SetSize(uInt32 w, uInt32 h)
{
   width = w;
   height = h;
}

void GlInfo::SetEnvData(iEnvData *edata)
{   
   ed = edata;
}

void GlInfo::SetVehicleData(iVehicleData *vdata)
{
   vd = vdata;
}

void GlInfo::Display()
{
   uInt32 i;
   Point3D p, vehp;
   uInt32 boxHeight, padding;
   
   glLineWidth(1.0);
   
   padding = 4;
   boxHeight = 100;
   
   // draw box
   glColor3f(0, 0, 0);
   glBegin(GL_LINES);
      // left line
      glVertex2f(0, 0);
      glVertex2f(0, height);
      
      // right line
      glVertex2f(width - 1, 0);
      glVertex2f(width - 1, height);
      
      // bottom line
      glVertex2f(0, height);
      glVertex2f(width - 1, height);
   glEnd();
   
   
   // for each vehicle
   vd->StartVehicleRead();
   
   i = 0;
   p.x = padding;
   p.y = padding;

   do
   {
      vd->GetColor(c);
      color.Set(c);
      color.Apply();
   
      // draw box
      glBegin(GL_LINES);
         // left line
         glVertex2f(p.x, p.y);
         glVertex2f(p.x, p.y + boxHeight);
      
         // right line
         glVertex2f(width - 2*p.x + 2, p.y);
         glVertex2f(width - 2*p.x + 2, p.y + boxHeight);
      
         // top line
         glVertex2f(p.x, p.y);
         glVertex2f(width - 2*p.x + 3, p.y);
      
         // bottom line
         glVertex2f(p.x, p.y + boxHeight);
         glVertex2f(width - 2*p.x + 3, p.y + boxHeight);
      
      glEnd();
   
      vd->GetPosDir(vehp);
      sprintf(info, "--- Vehicle %d ---\nx: %0.3f\ny: %0.3f\nz: %0.3f\nh: %0.3f\nb: %s", 
            i, vehp.x, vehp.y, vehp.z, vehp.heading,
            vd->GetCurrentBehaviorName());
      text.SetText(info);
         
      glPushMatrix();
         glTranslatef(p.x + padding, p.y + 14, 0);
         text.Draw();
      glPopMatrix();
      
      p.y += boxHeight + padding;
      ++i;
   } while(vd->NextVehicle() == 0);
   
}

