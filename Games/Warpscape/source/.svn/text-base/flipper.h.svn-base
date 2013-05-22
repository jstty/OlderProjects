/****************************************
 filename:    flipper.h
 project:     warpattack
 created by:  Joseph E. Sutton
 date:        2010/04/15
 description: flipper enemy
 ****************************************/
#ifndef _FLIPPER_
#define _FLIPPER_

enum FlippingState { Flipping_Start, Flipping_Moving, Flipping_Done, Flip_In_Dir, Done };

class cFlipper : public cEnemy
{
public:
   FlippingState               mFlippingState;
   
   cFlipper(vector< vector<Point3D> > *p, PolygonType pt);
   
   virtual void Draw();
   virtual void Update();
	
	void CalcRotate();
	void PickDir();
	void CalcScale();

   virtual Point3D GetCenterPos();
   virtual uInt32  GetCurrentTrack();
   
protected:
   bool dir;
   uInt32 mFirstTrack, mLastTrack, mNextTrack, mZ, mPrevTrack;
	float					mAngle, mScaler, mEnemySpeed;
	cTimer				mStepTimer, mCreateTimer;
};

#endif // _FLIPPER_
