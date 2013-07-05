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
   
   // initialize the array of stars
   // a star is a line with the first point being the front facing light color and 
   //   the second being farther in Z axes with an alpha of zero (fully transparent)
   mStars = new Line3D[mNumStars];
   for(i = 0; i < mNumStars; ++i)
   {
      // first point in star
      mStars[i].p1 = RandomPoint();
      mStars[i].c1.r = 1.0;
      mStars[i].c1.g = 1.0;
      mStars[i].c1.b = 1.0;
      mStars[i].c1.a = 1.0; // fully visable
      
      // second point in star
      mStars[i].p2 = mStars[i].p1;
      mStars[i].p2.z -= mMoveStep;
      mStars[i].c2 = mStars[i].c1;
      mStars[i].c2.a = 0.0; // fully transparent
      
      // point normal towards the screen so color is correct     
      mStars[i].normal.x = 0.0;
      mStars[i].normal.y = 0.0;
      mStars[i].normal.z = GetNormal(i);
   }
   
   // run the star field for 90 steps to initialize the stars positions
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
      {
         mStars[i].p2.z += mMoveStep;
      }

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

// calculate the normal
float cStarfield::GetNormal(uInt16 i)
{
   float r;
   
   // point applied to an exponential model similar to a half elipsoid
   // -1 * cos( log((x^2 + y^2) * 0.30) / log(2^10) )
   r = (mStars[i].p1.x * mStars[i].p1.x) + (mStars[i].p1.y * mStars[i].p1.y);
   r = -1.0*cos( log(r * 0.30)/(10.0 * log(2.0)) );

   // point is normal
   return r;
}

// generate a 3d point within the view frustum
Point3D cStarfield::RandomPoint()
{
   Point3D p;
   float min, max;
   
   // bound Z to find in view frustum
   min = -15;
   max = -150;
   p.z = min + (max - min)*((float)rand())/((float)RAND_MAX);
   
   // bound X & Y to find in view frustum
   min = -0.3*(-p.z);
   max = +0.3*(-p.z);
   p.x = min + (max - min)*((float)rand())/((float)RAND_MAX);
   p.y = min + (max - min)*((float)rand())/((float)RAND_MAX);
   
   return p;
}