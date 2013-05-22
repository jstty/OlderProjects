/****************************************
 filename:    flipper.cpp
 project:     warpattack
 created by:  Joseph E. Sutton
 date:        2010/04/15
 description: flipper enemy
 ****************************************/
#include "global.h"

cFlipper::cFlipper(vector< vector<Point3D> > *p, PolygonType pt)
{
   mPath = p;
   mPathType = pt;
   
   mVisable = false;
   mHitable = false; // until visable

   SelectAnim("Flipper");

   mFirstTrack = 1;
   mLastTrack  = (*mPath)[0].size() - 2;
   
   // pick a random track to walk on
   mCurrentTrack = Random(mFirstTrack, mLastTrack);
	if(mCurrentTrack%2 == 0){
		mCurrentTrack++;
	}
   //mCurrentTrack = 1;

   mZ = mPath->size()-1;
   //mZ = 5;   

	CalcRotate();
   
   //mCurrentPos = (*mPath)[mZ][mCurrentTrack];
   PlayLoop();
   
   mHitable = true;
   mFlippingState = Flipping_Done;

	mEnemySpeed = 0.35;

	mStepTimer.SetExpirePerSec(mEnemySpeed);
   mStepTimer.Start();
	mCreateTimer.SetExpirePerSec(Random(0.0, 10.0));
   mCreateTimer.Start();
}

void cFlipper::Draw()
{
   glPushMatrix();

	glTranslatef((*mPath)[mZ][mCurrentTrack].x, (*mPath)[mZ][mCurrentTrack].y, (*mPath)[mZ][mCurrentTrack].z);
	glRotatef(mAngle, 0, 0, 1);
	glRotatef(   -60, 1, 0, 0);
	glScalef(mScaler, mScaler, 1);
	
   
   cEnemy::Draw();
   
   glPopMatrix();
}

void cFlipper::Update()
{ 
	mCreateTimer.Update();
	mStepTimer.Update();

	if(mCreateTimer.HasExpired())
	{
		mVisable = true;
		mHitable = true;
	}

	if(mStepTimer.HasExpired() && mCreateTimer.HasExpired())
	{
		cEnemy::Update();

		if(mState == Enemy_Dying)
		{
			mState   = Enemy_Dead;
			mVisable = false;
		}


		if(mZ <= 0 && (mFlippingState != Flip_In_Dir && mFlippingState != Done))
		{
			mZ = 0;
			mFlippingState = Flip_In_Dir;
		}

		// move along track on path, (*mPath)[z][mCurrentTrack]
		// (*mPath)[z][mCurrentTrack].x
		// only when mFlipping is done
		if(mFlippingState == Flipping_Done)
		{
			mZ--;
			mFlippingState = Flipping_Start;
		}
   
		// flip
		else if(mFlippingState == Flipping_Start)
		{
			dir = (rand() % 100 > 49) ? true :  false;
			PickDir();
			// can be killed again
			mHitable = true;
    
			// done with the flipping
			mFlippingState = Flipping_Done;
		}

		else if(mFlippingState == Flip_In_Dir || mFlippingState == Done)
		{
			if(mPathType == Polygon_Closed && mFlippingState == Flip_In_Dir)
			{
				dir = (rand() % 100 > 49) ? true :  false;
				mFlippingState = Done;
			}
			else
			{
				if((mCurrentTrack < ((*mPath)[mZ].size()-2) && mCurrentTrack > 1) || mFlippingState == Done)
				{
				}
				else
				{
					dir = !dir;
				}
			}
			PickDir();
		}

		mStepTimer.Start();
	}
   
}

void cFlipper::CalcRotate()
{
	float diffX, diffY;
   uInt32 lt, rt;
   
   
   if(mCurrentTrack == 0) lt = (*mPath)[mZ].size()-1;
   else                   lt = mCurrentTrack-1;

   if(mCurrentTrack == (*mPath)[mZ].size()-1) rt = 0;
   else                                rt = mCurrentTrack+1;

   
   diffX = (*mPath)[mZ][lt].x - (*mPath)[mZ][rt].x;
   diffY = (*mPath)[mZ][lt].y - (*mPath)[mZ][rt].y;
      
   mAngle = atan( Abs( diffY/diffX ) )*_180_PI;
   
   if(mPathType == Polygon_Closed)
   {
      if((*mPath)[mZ][mCurrentTrack].y > 0) mAngle = 180 - mAngle;
      if((*mPath)[mZ][mCurrentTrack].x < 0) mAngle *= -1;
   } 
	else 
	{
      if(diffX != 0)
      {
         if(diffY/diffX <= 0) mAngle *= -1;
      } 
		else 
		{
         if((*mPath)[mZ][mCurrentTrack].x < 0) mAngle *= -1;
      }      
   }

	CalcScale();
}

void cFlipper::PickDir()
{    
	if(dir)
   {  
      if(mCurrentTrack > 1)
			mCurrentTrack -= 2;
		else if(mPathType == Polygon_Closed)
			mCurrentTrack = (*mPath)[mZ].size()-2;
		else
			mCurrentTrack +=2;
	} 

	else 
	{
	   if(mCurrentTrack < ((*mPath)[mZ].size()-2))
			mCurrentTrack += 2;
		else if(mPathType == Polygon_Closed)
			mCurrentTrack = 1;
		else
			mCurrentTrack -=2;
   }

	CalcRotate();
      
   PlayLoop();
}

Point3D cFlipper::GetCenterPos()
{
   Point3D p;
   if(mCurrentGfx != NULL)
   {
      p.x = (*mPath)[mZ][mCurrentTrack].x;
      p.y = (*mPath)[mZ][mCurrentTrack].y;
      p.z = (*mPath)[mZ][mCurrentTrack].z;
   }
   return p;
}

uInt32 cFlipper::GetCurrentTrack()
{
   return mCurrentTrack >> 1; // div by 2
}

void cFlipper::CalcScale()
{
	float x = (*mPath)[mZ][mCurrentTrack--].x - (*mPath)[mZ][mCurrentTrack++].x;
	float y = (*mPath)[mZ][mCurrentTrack--].y - (*mPath)[mZ][mCurrentTrack++].y;
	mScaler = sqrt(y*y+x*x);
}
