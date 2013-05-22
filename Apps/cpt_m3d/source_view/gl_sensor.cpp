//////////////////////////////////////////////////////////////////////////////
// Program Name:	gl_sensor.cpp
// Programmer:		Joseph E. Sutton
// Description:	OpenGL Sensor Class
// Start Date:		5/9/2007
// Version:			1.00
//////////////////////////////////////////////////////////////////////////////

#include "../include/gl.h"
#include "../include/gl_sensor.h"

GlSensor::GlSensor()
{
}

GlSensor::~GlSensor()
{
   list<double> *tmp;

   for(mListIt = mList.begin(); mListIt != mList.end(); mListIt++ )
   {
      tmp = (*mListIt);
      tmp->clear();
      delete tmp;
   }
   
   mList.clear();
}

void GlSensor::Init()
{
   ed = NULL;
   
   mColor.SetBlack();
   mMaxPoints = 100;
   mStep = 1;
   mMaxChemDensity = 1e-5;
   width = 800;
   height = 100;
   
   offset_x = 55;
   offset_y = 25;
   padding_x = 10;
   padding_y = 10;
   grid_nrows = 10;
   grid_ncols = 7;
   
   text.SetColor(0, 0, 0);
   text.SetFont(GLUT_BITMAP_8_BY_13, 20);
   text.SetJustify(GLUT_TEXT_LEFT | GLUT_TEXT_BOTTOM);
   
   time_start = getHiResTime();
   
   mList.clear();
   UpdateMaxChemDensity();
}

void GlSensor::SetSize(uInt32 w, uInt32 h)
{
   width = w;
   height = h;
   
   mStep = (double)(width - offset_x - padding_x)/((double)mMaxPoints - 1);
   grid_nrows = ((width - offset_x - padding_x)/mStep) + 1;
}

void GlSensor::SetColor(double c[3])
{
}

void GlSensor::SetEnvData(iEnvData *edata)
{   
   ed = edata;
}

void GlSensor::SetVehicleData(iVehicleData *vdata)
{
   list<double> *tmp;
   vd = vdata;
   
   mList.clear();
   // reset to all zeros
   for(i = 0; i < vd->GetNumVehicle(); i++)
   {
      tmp = new list<double>;
      for(j = 0; j < mMaxPoints; j++)
      {
         tmp->push_back(0);
      }
      
      mList.push_back(tmp);
   }
}

void GlSensor::SetTimeRate(double rate)
{
   time_rate = rate;
}

void GlSensor::Loop()
{
   if( (vd != NULL) &&
       (ed != NULL)
     )
   {
	  vd->StartVehicleRead();
	  mListIt = mList.begin();
	  
      while(mListIt != mList.end())
      {
         vd->GetPosDir(p);
         mChemDensity = ed->GetChemDensity(p);
         
         (*mListIt)->push_back( mChemDensity );
         (*mListIt)->pop_front();
         
         UpdateMaxChemDensity();
         
         vd->NextVehicle();
         mListIt++;
      }
   }
}

void GlSensor::UpdateMaxChemDensity()
{
   double step, tmax = 0, time = 0;
   list< list<double> * >::iterator It;
   
   for(It = mList.begin(); It != mList.end(); It++ )
   {
      for(mDoubleIt = (*It)->begin(); mDoubleIt != (*It)->end(); mDoubleIt++ )
      {
         if((*mDoubleIt) > mMaxChemDensity) mMaxChemDensity = (*mDoubleIt);
         if((*mDoubleIt) > tmax) tmax = (*mDoubleIt);
      }
   }
   
   
   // if after two second
   time_end = getHiResTime();
   if(time_end - time_start >= 2.00)
   {
      time_start = getHiResTime();
      // if max in list is less then current used max, reset current max
      if(tmax < mMaxChemDensity*0.5)
      {
         mMaxChemDensity = tmax + 1e-5;
      }
   }
   
   step = mMaxChemDensity*0.2;
   sprintf(yaxis_str, "    c\n0.000\n%0.3f\n%0.3f\n%0.3f\n%0.3f\n%0.3f",
      step*1, 
      step*2, 
      step*3, 
      step*4,
      mMaxChemDensity);
   
   time = 0;
   if(ed != NULL) time = ed->GetSimTime();
   
   sprintf(xaxis_str, "t %0.3f", time - mMaxPoints*time_rate);
   sprintf(time_str,  "%0.3f",   time);
}

void GlSensor::Display()
{
   Color c;
   glPointSize(4);
   glLineWidth(1);
   
   
   // draw axis, plus lines
   glBegin(GL_LINES);
      // bottom line
      glVertex2f(0, height);
      glVertex2f(width, height);
   
      // x axis
      glVertex2f(offset_x - 5, height - offset_y);
      glVertex2f(width - padding_x, height - offset_y);
      
      for(i = 1; i < grid_nrows; i++)
      {
         glVertex2f(offset_x + i*mStep, height - offset_y + 5);
         glVertex2f(offset_x + i*mStep, height - offset_y);
      }
      
      // y axis
      glVertex2f(offset_x, height - offset_y + 5);
      glVertex2f(offset_x, padding_y);
      
      for(i = 1; i < grid_ncols; i++)
      {
         glVertex2f(offset_x - 5, height - offset_y - i*20 - 2);
         glVertex2f(offset_x, height - offset_y - i*20 - 2);
      }
      
      // top line
      glVertex2f(offset_x, padding_y);
      glVertex2f(width - padding_x + 1, padding_y);
      
      // right line
      glVertex2f(width - padding_x, height - offset_y);
      glVertex2f(width - padding_x, padding_y);
      
      glColor3f(0.8, 0.8, 0.8);
      // inner grid
      for(i = 1; i < grid_nrows; i++)
      {
         glVertex2f(offset_x + i*mStep, padding_y);
         glVertex2f(offset_x + i*mStep, height - offset_y);
      }
      
      for(i = 1; i < grid_ncols; i++)
      {
         glVertex2f(offset_x, height - offset_y - i*20 - 2);
         glVertex2f(width - padding_x, height - offset_y - i*20 - 2);
      }
      //
      
   glEnd();
   
   
   // draw y axis text
   glPushMatrix();
      glTranslatef(5, height - offset_y + 2, 0);
      text.SetText(yaxis_str);
      text.SetDirection(GLUT_TEXT_DRAW_VERT);
      text.Draw();
   glPopMatrix();
   //
   
   // draw x axis text
   glPushMatrix();
      glTranslatef(offset_x - 3, height - offset_y + 18, 0);
      text.SetText(xaxis_str);
      text.SetDirection(GLUT_TEXT_DRAW_HORZ);
      text.Draw();
   glPopMatrix();
   
   // draw current time
   glPushMatrix();
      glTranslatef(width - padding_x - 40, height - offset_y + 18, 0);
      text.SetText(time_str);
      text.SetDirection(GLUT_TEXT_DRAW_HORZ);
      text.Draw();
   glPopMatrix();
   //
   
   
   // loop all vehicles here
   vd->StartVehicleRead();
   for(mListIt = mList.begin(); mListIt != mList.end(); mListIt++ )
   {
      vd->GetColor(c);
      mColor.Set(c);
      mColor.Apply();
   
      glPushMatrix();
         glTranslatef(offset_x, height - offset_y - 23, 0);
      
         // draw sensor lines
         i = 0;
         glBegin(GL_LINE_STRIP);
         for(mDoubleIt = (*mListIt)->begin(); mDoubleIt != (*mListIt)->end(); mDoubleIt++ )
         {
            p.y = (-100.0)*((*mDoubleIt)/mMaxChemDensity); // normalize the desity to max 100
            p.x = i*mStep;
         
            glVertex3f(p.x, p.y, 0.1f);
            ++i;
         }
         glEnd();
      
         // draw sensor points
         i = 0;
         glBegin(GL_POINTS);
         for(mDoubleIt = (*mListIt)->begin(); mDoubleIt != (*mListIt)->end(); mDoubleIt++ )
         {
            p.y = (-100.0)*((*mDoubleIt)/mMaxChemDensity); // normalize the desity to max 100
            p.x = i*mStep;
     
            glVertex3f(p.x, p.y, 0.1f);
            ++i;
         }
         glEnd();

      glPopMatrix();
      
      vd->NextVehicle();
   }
   //
   
}

