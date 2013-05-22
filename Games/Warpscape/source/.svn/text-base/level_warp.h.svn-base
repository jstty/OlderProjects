/****************************************
 filename:    level_warp.h
 project:     warpattack
 created by:  Joseph E. Sutton
 date:        2010/04/08
 description: warp level
 ****************************************/
#ifndef _LEVEL_WARP_
#define _LEVEL_WARP_

class cWarpLevel : public cLevel
{
   enum ZoomState { Zoom_StartIn, Zoom_MovingIn, Zoom_DoneIn,
                    Zoom_StartOut, Zoom_ResetMovingOut, Zoom_MovingOut, Zoom_DoneOut };
   
public:
   
   cWarpLevel();
   ~cWarpLevel();
   
   virtual uInt32 Enter(uInt32 level_num);
   virtual uInt32 Exit();
   virtual void   Draw();
   virtual void   Update();
   virtual void   Input(LevelInput input);
   virtual int    LoadSettings(const char *filename);

   void Clear();
   
protected:
   uInt32                i, j;
   cPlayerShipBullet *   mTmpBullet;

   uInt8                 mLevelMax;
   uInt32                mScore;
   uInt32                mLives;
   cPolygon              mLivesPoly;
   
   ZoomState             mZoomState;
   cTimer                mZoomTimer;
   float                 mZoomMoveRate;
   uInt32                mZoomSteps;
   float                 mZoomStartFieldOfView;
   float                 mZoomEndFieldOfView;
   float                 mZoomFieldOfView;
   float                 mZoomStartZPos;
   float                 mZoomEndZPos;
   float                 mZoomZPos;
   
   cBackground *         mCurrentBkg;

   cWarpPath *           mWarpPath;
   float                 mScaleWarpPathX;
   float                 mScaleWarpPathY;

   cPlayerShip *         mPlayerShip;
   
   float                 mFogDensity;
   
   vector<cEnemy *>      mEnemies;
   uInt32                mMaxNumEnemies;

   vector<cBackground *> mBackground;
   
   vector<cPlayerShipBullet *> mBullets;
   uInt32                      mMaxNumBullets;
   uInt32                      mMaxBulletRate;
   cTimer                      mBulletRateTimer;
   
   bool CollisionTest(Point3D p, PointBox3D b);

   void DestroyBullet(uInt32 index);
   void DrawPaused();
};

#endif // _LEVEL_WARP_
