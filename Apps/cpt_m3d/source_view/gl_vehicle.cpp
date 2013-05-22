//////////////////////////////////////////////////////////////////////////////
// Program Name:	gl_vehicle.cpp
// Programmer:		Joseph E. Sutton
// Description:	OpenGL Vehicle Class
// Start Date:		2/13/2007
// Version:			1.00
//////////////////////////////////////////////////////////////////////////////

#include "../include/gl.h"
#include "../include/gl_vehicle.h"
#include "../include/types_structs.h"

GlVehicle::GlVehicle()
{
}

GlVehicle::~GlVehicle()
{
   list<Point3D> *tmp;

   for(mListIt = mList.begin(); mListIt != mList.end(); mListIt++ )
   {
      tmp = (*mListIt);
      tmp->clear();
      delete tmp;
   }
   
   mList.clear();
}

void GlVehicle::Init()
{
   vd = NULL;
   
   mMaxPoints = 30;
   mLoopSkip = 100;
   mLoopCount = 0;
}

void GlVehicle::Loop()
{
   ++mLoopCount;
   if( (mLoopCount > mLoopSkip) &&
       (vd != NULL)
      )
   {
      mLoopCount = 0;
      vd->StartVehicleRead();
      mListIt = mList.begin();
	  
      while(mListIt != mList.end())
      {
         vd->GetPosDir(p);
         
         (*mListIt)->push_back( p );
         (*mListIt)->pop_front();
         
         vd->NextVehicle();
         mListIt++;
      }
   }
}

void GlVehicle::SetVehicleData(iVehicleData *vdata)
{  
   list<Point3D> *tmp;
   vd = vdata;
    
   vd->StartVehicleRead();
   
   mList.clear();
   // reset to all zeros
   do
   {
      vd->GetPosDir(p);
      
      tmp = new list<Point3D>;
      for(j = 0; j < mMaxPoints; j++)
      {
         tmp->push_back(p);
      }
      mList.push_back(tmp);
      
   } while(vd->NextVehicle() == 0);
}

void GlVehicle::SetMax(Point3D m)
{
   x_max = m.x;
   y_max = m.y;
   z_max = m.z;
}

void GlVehicle::Display()
{
   Color c;
   Point3D vp, p;

   if(vd != NULL)
   {
      // loop
      vd->StartVehicleRead();
      mListIt = mList.begin();

      do
      {
         vd->GetPosDir(vp);
         vd->GetColor(c);
         glColor3f(c.r, c.g, c.b);
         
         //
         glLineWidth(1);
         glPointSize(1);
         glPushMatrix();
            glTranslatef(vp.x - x_max*0.5,
                         vp.y,
                         -z_max*0.5);
            glRotatef(_180_PI*vp.heading, 0.0, 0.0, 1.0);
                   
            glutSolidSphere(0.5, 8, 6);
            glBegin(GL_LINES);
               glVertex3f(0, 0, 0);
               glVertex3f(2.5, 0, 0);

               glVertex3f(2.5, 0, 0);
               glVertex3f(1.5, 0.6, 0);

               glVertex3f(2.5, 0, 0);
               glVertex3f(1.5, -0.6, 0);
            glEnd();

         glPopMatrix();
         
         //
         glPointSize(3);
         glLineWidth(2);
         glPushMatrix();
            // draw lines
            glBegin(GL_LINE_STRIP);
               for(mPoint3DIt = (*mListIt)->begin(); mPoint3DIt != (*mListIt)->end(); mPoint3DIt++ )
               {
                  p = (*mPoint3DIt);
                  //fprintf(stderr, "tp(%f, %f, %f)\n", tp[0], tp[1], tp[2]);

                  glVertex3f(p.x - x_max*0.5,
                             p.y,
                             -z_max*0.5);
               }

               glVertex3f(vp.x - x_max*0.5,
                          vp.y,
                          -z_max*0.5);
            glEnd();
            
            // draw points
            glBegin(GL_POINTS);
            for(mPoint3DIt = (*mListIt)->begin(); mPoint3DIt != (*mListIt)->end(); mPoint3DIt++ )
            {
               p = (*mPoint3DIt);
               glVertex3f(p.x - x_max*0.5,
                          p.y,
                          -z_max*0.5);
            }
            glEnd();
         glPopMatrix();
         
         
      mListIt++;
      } while( (vd->NextVehicle() == 0) &&
               (mListIt != mList.end()));
   }
}
