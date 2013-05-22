//////////////////////////////////////////////////////////////////////////////
// Program Name:	gl_plume.cpp
// Programmer:		Joseph E. Sutton
// Description:	OpenGL Plume Class
// Start Date:		2/13/2007
// Version:			1.00
//////////////////////////////////////////////////////////////////////////////

#include "../include/gl.h"
#include "../include/gl_plume.h"

GlPlume::GlPlume()
{
   ed = NULL;
	mTrans = new Point3D[3];
   mRot   = new Point3D[3];
   mColor.SetBlack();
}

GlPlume::~GlPlume()
{
   delete [] mTrans;
   delete [] mRot;
}

void GlPlume::Init()
{
}

void GlPlume::Loop()
{
}

void GlPlume::SetColor(double c[3])
{
  mColor.SetRGB((uInt8)c[0], (uInt8)c[1], (uInt8)c[2]);
}

void GlPlume::SetTranslate(int i, float x, float y, float z)
{
	mTrans[i].x = x;
	mTrans[i].y = y;
	mTrans[i].z = z;
}

void GlPlume::SetRotate(int i, float angle, float x, float y, float z)
{
	mRot[i].rad = angle;
	mRot[i].x = x;
	mRot[i].y = y;
	mRot[i].z = z;
}

void GlPlume::SetMax(Point3D m)
{
   x_max = m.x;
   y_max = m.y;
   z_max = m.z;
}

void GlPlume::SetEnvData(iEnvData *edata)
{
   ed = edata;
}

void GlPlume::Display()
{
   uInt32 i;
   Point3D p;

   if(ed == NULL) return; // error

   i = 0;
   float c;

   ed->StartChemSensorRead();
   do
   {
      glPushMatrix();
         //glTranslatef(mTrans[i].x, mTrans[i].y, mTrans[i].z);
         //glRotatef(mRot[i].rad, mRot[i].x, mRot[i].y, mRot[i].z);

         ed->StartChemPointRead();

         glPointSize(2.0);
         glBegin(GL_POINTS);
            while(ed->GetNextChemPoint(p) == 0)
            {
               c = 1.0 - 1.0*p.den;
               glColor3f(c, c, c);
               
               glVertex3f(p.x - (x_max*0.5), 
                          p.y, 
                          p.z - (z_max*0.5));
            }
         glEnd();
      glPopMatrix();
      ++i;
   } while(ed->GetNextChemSensor() == 0);
}
