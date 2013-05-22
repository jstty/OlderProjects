/****************************************
 filename:    anim_model.cpp
 project:     warpattack
 created by:  Joseph E. Sutton
 date:        2010/04/08
 description: 
 ****************************************/
#include "global.h"

cAnimModel::cAnimModel()
{
   mCurrentPos.x = 0;
   mCurrentPos.y = 0;
   mCurrentPos.z = 0;

   mVisable = true;
   
   mLoop = false;
   mCurrentGfx = NULL;
   Stop();
}

void cAnimModel::Update()
{
   if(mCurrentGfx == NULL) return;
   
   if((mLoop) && (mCurrentState == Anim_Done))
   {
      mLoopTimer.Start();
      mLoopTimer.SetExpire( (uInt32)(mCurrentGfx->mModels[mCurrentFrame]->mDelay*1000000) );
      
      mCurrentState = Anim_Play;
   }
   
   if(mCurrentState == Anim_Play)
   {
      mLoopTimer.Update();
      if(mLoopTimer.HasExpired())
      {
         mCurrentFrame++;
         if(mCurrentFrame >= mCurrentGfx->mModels.size())
         {
            mCurrentFrame = 0;
            mCurrentState = Anim_Done;
         }
         
         mLoopTimer.Start();
         mLoopTimer.SetExpire( (uInt32)(mCurrentGfx->mModels[mCurrentFrame]->mDelay*1000000) );
      }
   }
}

void cAnimModel::Draw()
{
   if((mCurrentGfx != NULL) && mVisable)
   {
      glPushMatrix();
      
         // translate to mCurrentPos
         glTranslatef(mCurrentPos.x, mCurrentPos.y, mCurrentPos.z);
         mCurrentGfx->mModels[mCurrentFrame]->Draw();
      
      glPopMatrix();
   }
}

void cAnimModel::Play()
{
   mCurrentState = Anim_Play;
}

void cAnimModel::PlayLoop()
{
   mLoop = true;
   mCurrentState = Anim_Done;
}

void cAnimModel::Pause()
{
   mCurrentState = Anim_Pause;
}

void cAnimModel::Stop()
{
   mCurrentFrame = 0; //reset anim
   mCurrentState = Anim_Pause;
}
   
void cAnimModel::SelectAnim(const char *name)
{
   Stop();
   mCurrentGfx = game->mGraphics->FindAnimModel(name);
}

float cAnimModel::GetWidth()
{
   if(mCurrentGfx != NULL)
   {
      return mCurrentGfx->mModels[mCurrentFrame]->mWidth;
   }

   return 0;
}

float cAnimModel::GetHeight()
{
   if(mCurrentGfx != NULL)
   {
      return mCurrentGfx->mModels[mCurrentFrame]->mHeight;
   }

   return 0;
}

float cAnimModel::GetDepth()
{
   if(mCurrentGfx != NULL)
   {
      return mCurrentGfx->mModels[mCurrentFrame]->mDepth;
   }

   return 0;
}
