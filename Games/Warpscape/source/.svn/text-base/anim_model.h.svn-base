/****************************************
 filename:    anim_model.h
 project:     warpattack
 created by:  Joseph E. Sutton
 date:        2010/04/08
 description: 
 ****************************************/
#ifndef _ANIM_MODEL_
#define _ANIM_MODEL_

enum AnimModelState { Anim_Play, Anim_PlayLoop, Anim_Pause, Anim_Done };

class cAnimModel
{
protected:
   bool            mVisable;

   bool            mLoop;
   cTimer          mLoopTimer;
   
   Point3D         mCurrentPos;
   AnimModelState  mCurrentState;
   uInt32          mCurrentFrame;
   cAnimModelGfx  *mCurrentGfx;

public:
   cAnimModel();
   
   void Update();
   void Draw();  // mCurrentGfx->mModels[mCurrentFrame]->Draw();
   void Play();
   void PlayLoop();
   void Pause();
   void Stop();  // mCurrentFrame = 0; reset anim
   
   void SelectAnim(const char *name); // mCurrentGfx = game->mGfx->Find(name);

   float GetWidth();
   float GetHeight();
   float GetDepth();
};

#endif // _ANIM_MODEL_
