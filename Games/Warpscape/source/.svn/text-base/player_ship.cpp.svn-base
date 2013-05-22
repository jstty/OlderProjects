/****************************************
 filename:    player_ship.cpp
 project:     warpattack
 created by:  Joseph E. Sutton
 date:        2010/04/15
 description: 
 ****************************************/
#include "global.h"

cPlayerShip::cPlayerShip(vector<Point3D> p, PolygonType pt, uInt32 startTrack)
{
   mPath = p;
   mPathType = pt;
   mState = PlayerShip_Alive;
   
   SelectAnim("Ship");
   //PlayLoop();
   Pause();
   
   mCurrentTrack = startTrack;
   CalcRotate();
}

void cPlayerShip::Draw()
{
   glPushMatrix();     
      // Translate - to path point
      glTranslatef(mPath[mCurrentTrack].x, mPath[mCurrentTrack].y, 0.0);
   
      // Rotate - facing center
      glRotatef(mAngle, 0, 0, 1);      
      glRotatef(   -45, 1, 0, 0);   
   
      cAnimModel::Draw();
   
   glPopMatrix();
}

void cPlayerShip::Update()
{
   cAnimModel::Update();
}

void cPlayerShip::MoveLeft()
{
	if(mCurrentTrack > 1)
      mCurrentTrack -= 2;
    else if(mPathType == Polygon_Closed)
      mCurrentTrack = mPath.size()-2;

	CalcRotate();
}

void cPlayerShip::MoveRight()
{
	if(mCurrentTrack < (mPath.size()-2))
      mCurrentTrack += 2;
    else if(mPathType == Polygon_Closed)
      mCurrentTrack = 1;

	CalcRotate();
}

uInt32 cPlayerShip::GetCurrentTrack()
{
   return mCurrentTrack >> 1; // div by 2
}

void cPlayerShip::CalcRotate()
{
   float diffX, diffY;
   uInt32 lt, rt;
   
   
   if(mCurrentTrack == 0) lt = mPath.size()-1;
   else                   lt = mCurrentTrack-1;

   if(mCurrentTrack == mPath.size()-1) rt = 0;
   else                                rt = mCurrentTrack+1;

   
   diffX = mPath[lt].x - mPath[rt].x;
   diffY = mPath[lt].y - mPath[rt].y;
      
   mAngle = atan( Abs( diffY/diffX ) )*_180_PI;
   
   if(mPathType == Polygon_Closed)
   {
      if(mPath[mCurrentTrack].y > 0) mAngle = 180 - mAngle;
      if(mPath[mCurrentTrack].x < 0) mAngle *= -1;
   } else {
      if(diffX != 0)
      {
         if(diffY/diffX <= 0) mAngle *= -1;
      } else {
         if(mPath[mCurrentTrack].x < 0) mAngle *= -1;
      }      
   }
}

Point3D cPlayerShip::GetCenterPos()
{
   Point3D p;
   if(mCurrentGfx != NULL)
   {
      p.x = mPath[mCurrentTrack].x + 0.5*GetWidth();
      p.y = mPath[mCurrentTrack].y + 0.5*GetHeight();
      p.z = mPath[mCurrentTrack].z + 0.5*GetDepth();
   }
   return p;
}
