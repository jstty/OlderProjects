/****************************************
 filename:    level_title.h
 project:     warpattack
 created by:  Joseph E. Sutton
 date:        2010/04/19
 description: title level
 ****************************************/
#ifndef _LEVEL_TITLE_
#define _LEVEL_TITLE_

class cTitleLevel : public cLevel
{
   enum ZoomState { Zoom_StartIn, Zoom_MovingIn, Zoom_DoneIn,
                    Zoom_StartOut, Zoom_MovingOut, Zoom_DoneOut };

public:
   
   cTitleLevel();
   ~cTitleLevel();
   
   virtual uInt32 Enter(uInt32 level_num);
   virtual uInt32 Exit();
   virtual void   Draw();
   virtual void   Update();
   virtual void   Input(LevelInput input);
   virtual int    LoadSettings(const char *filename);

   void Clear();
   
protected:
   uInt32                i;
   
   ZoomState             mZoomState;
   cTimer                mZoomTimer;
   float                 mZoomTimerRate;
   float                 mZoomMoveRate;
   uInt32                mZoomSteps;
   float                 mZoomStartFieldOfView;
   float                 mZoomEndFieldOfView;
   float                 mZoomFieldOfView;
   float                 mZoomStartZPos;
   float                 mZoomEndZPos;
   float                 mZoomZPos;
   
   float                 mFogDensity;
   
   cModel                mTitle;
   cBackground *         mCurrentBkg;
   cTimer                mTextTimer;
   bool                  mTextColorLight;
   
   cWarpPath *           mWarpPath;
   float                 mScaleWarpPathX;
   float                 mScaleWarpPathY;

   vector<cBackground *> mBackground;   
};

#endif // _LEVEL_TITLE_
