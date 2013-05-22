/****************************************
 filename:    starfield_bkg.cpp
 project:     warpattack
 created by:  Joseph E. Sutton
 date:        2010/04/08
 description: warp level
 ****************************************/
#include "global.h"

cStarfield::cStarfield()
{
   uInt16 i;
   
   mNumStars = 600;
   mMoveStep = 0.7;
   mBlurLength = 3.5;
   
   mStars = new Line3D[mNumStars];
   for(i = 0; i < mNumStars; ++i)
   {
      mStars[i].p1 = RandomPoint();
      mStars[i].c1.r = 1.0;
      mStars[i].c1.g = 1.0;
      mStars[i].c1.b = 1.0;
      mStars[i].c1.a = 1.0;
      
      mStars[i].p2 = mStars[i].p1;
      mStars[i].p2.z -= mMoveStep;
      mStars[i].c2 = mStars[i].c1;
      mStars[i].c2.a = 0.0;
      
      //mStars[i].maxLength = Random(3, mBlurLength);
      
      mStars[i].normal.x = 0.0;
      mStars[i].normal.y = 0.0;
      mStars[i].normal.z = GetNormal(i);
   }
   
   // moves the stars head by 90 steps so it does not look funny
   for(i = 0; i < 90; ++i)
   {
      Update();
   }
}

cStarfield::~cStarfield()
{
   if(mStars != NULL)
   {
      delete [] mStars;
   }
}

void cStarfield::Draw()
{
   glEnable(GL_LINE_SMOOTH);
   
   game->mGraphics->Draw(mStars, mNumStars);
   
   glDisable(GL_LINE_SMOOTH);
}

void cStarfield::Update()
{
   uInt16 i;
   for(i = 0; i < mNumStars; ++i)
   {
      mStars[i].p1.z += mMoveStep;
      
      // start moving p2 with reach length
      if(mStars[i].p1.z - mStars[i].p2.z >= mBlurLength)
      //if(mStars[i].p1.z - mStars[i].p2.z >= mStars[i].maxLength)
         mStars[i].p2.z += mMoveStep;
      
      // past screen move to new random point
      if(mStars[i].p2.z > 0)
      {
         mStars[i].p1 = RandomPoint();
         mStars[i].p2 = mStars[i].p1;
         mStars[i].p2.z -= mMoveStep;
         
         mStars[i].normal.z = GetNormal(i);
      }
   }
}

float cStarfield::GetNormal(uInt16 i)
{
   float r, max;
   max = 150*0.3;
   max = max*max;
   
   r = mStars[i].p1.x*mStars[i].p1.x + mStars[i].p1.y*mStars[i].p1.y;   
   r = log(r*0.30)/log(2.0);
   
   r = PI2*r/10.0;
   r = -1.0*cos(r);
   return r;
}

Point3D cStarfield::RandomPoint()
{
   Point3D p;
   float min, max, r;
   
   min = -15;
   max = -150;
   r = min + (max - min)*((float)rand())/((float)RAND_MAX);
   p.z = r;
   
   min = -0.3*(-p.z);
   max = +0.3*(-p.z);
   p.x = min + (max - min)*((float)rand())/((float)RAND_MAX);
   p.y = min + (max - min)*((float)rand())/((float)RAND_MAX);
   
   return p;
}