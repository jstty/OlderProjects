/****************************************
 filename:    level_title.cpp
 project:     warpattack
 created by:  Joseph E. Sutton
 date:        2010/04/19
 description: title level
 ****************************************/
#include "global.h"

cTitleLevel::cTitleLevel()
{      
   mBackground.push_back(new cStarfield());
}

cTitleLevel::~cTitleLevel()
{
   Clear();
}

void cTitleLevel::Clear()
{
   if(mWarpPath != NULL)   delete mWarpPath;

}

uInt32 cTitleLevel::Enter(uInt32 level_num) 
{
   cLevel::Enter(level_num);
   
   // Settings
   mFogDensity           = 0.08;
   
   mZoomStartFieldOfView = 160.0;
   mZoomEndFieldOfView   =  60.0;
   mZoomStartZPos        =   4.0;
   mZoomEndZPos          =   0.0;
   mZoomMoveRate         =   4.5;
   mZoomTimerRate        =   0.001;
  
   //
   glFogf(GL_FOG_DENSITY, mFogDensity);

   
   mWarpPath = new cWarpPath();
   mWarpPath->Load(MODEL_DIR"/warp/v.poly");
   
   // scale using poly width and height
   float height;
   height = mWarpPath->GetHeight();
   if(height < 4) height = 4;
   mScaleWarpPathY = ((game->mHeight)/height)*0.002;
   mScaleWarpPathX = mScaleWarpPathY;
   
   mTitle.Load(MODEL_DIR"/title.model");
   
   mTextColorLight = true;
   mTextTimer.SetExpirePerSec(0.8);
   mTextTimer.Start();

   // 
   mZoomState = Zoom_StartIn;
   mLevelState = LevelState_Running;
   mCurrentBkg = mBackground[0];
   
   return mLevelNum;
}

uInt32 cTitleLevel::Exit()
{
   return (++mLevelNum);
}

void cTitleLevel::Draw()
{
   glLineWidth(1.10);
   if(mZoomState == Zoom_StartIn)
   {
      return;
   }

   if(mCurrentBkg != NULL)
      mCurrentBkg->Draw();

   glPushMatrix();
   glEnable(GL_FOG);
   glFogf(GL_FOG_DENSITY, mFogDensity);
   
   // scale and translate for warp path
   glScalef(mScaleWarpPathX, mScaleWarpPathY, 1.0); // scale polygon so all fit in the same area
   glTranslatef(0.0, 0, -2.0);
   
   if((mZoomState == Zoom_MovingIn) ||
      (mZoomState == Zoom_MovingOut))
   {
      glTranslatef(0, 0, mZoomZPos);
   }

   if(mWarpPath != NULL)
   {
      glLineWidth(1.5);
      mWarpPath->Draw();
      glLineWidth(1.10);
   }
   
   glDisable(GL_FOG);
   glPopMatrix();
   
   if(mZoomState == Zoom_DoneIn)
   {
      glPushMatrix();
      
      glLineWidth(1.5);
      glScalef(0.03, 0.03, 1.0);
      glTranslatef(-18.0, 14.0, -1.0);
      mTitle.Draw(true, false, 0.5);
      
      glPopMatrix();
      
      glLineWidth(1.5);
      if(mTextColorLight)
         game->mText->SetColor(1, 1, 0);
      else
         game->mText->SetColor(0.7, 0.7, 0);
      
      game->mText->DrawLines(0.205, 0.040, 0.03, "press any key to start");
      glLineWidth(1.10);
   }
}

void cTitleLevel::Update()
{
   if(mLevelState == LevelState_Running)
   {
      // Zoom Start IN
      if(mZoomState == Zoom_StartIn)
      {
         mWarpPath->SetCurrentSelectedTrack(-1);
         mZoomState = Zoom_MovingIn;
         
         mZoomFieldOfView = mZoomStartFieldOfView;
         mZoomSteps       = mZoomStartFieldOfView-mZoomEndFieldOfView;
         mZoomZPos        = mZoomStartZPos;

         game->ChangePerspective(mZoomFieldOfView);

         mZoomTimer.SetExpirePerSec(mZoomTimerRate);
         mZoomTimer.Start();
         
         if(mCurrentBkg != NULL) mCurrentBkg->Update();
         if(mWarpPath != NULL)   mWarpPath->Update();
      }
      // Zoom Moving IN
      if(mZoomState == Zoom_MovingIn)
      {
         mZoomTimer.Update();
         if(mZoomTimer.HasExpired())
         {
            game->ChangePerspective(mZoomFieldOfView);

            mZoomFieldOfView -= mZoomMoveRate;
            mZoomZPos += (mZoomEndZPos - mZoomStartZPos)/((mZoomStartFieldOfView - mZoomEndFieldOfView)/mZoomMoveRate);

            if(mZoomZPos <= mZoomEndZPos)
            {
               mZoomState = Zoom_DoneIn;

               mZoomZPos = 0;
               game->ChangePerspective(mZoomEndFieldOfView);
            }
         }
      }
      
      // Zoom Done IN
      if(mZoomState == Zoom_DoneIn)
      {
         if(mCurrentBkg != NULL)
            mCurrentBkg->Update();
         
         if(mWarpPath != NULL)
            mWarpPath->Update();

         mTextTimer.Update();
         if(mTextTimer.HasExpired())
         {
            mTextTimer.Start();
            mTextColorLight = !mTextColorLight;
         }
         
      }
      
      // Zoom Start OUT
      if(mZoomState == Zoom_StartOut)
      {
         mWarpPath->SetCurrentSelectedTrack(-1);
         mZoomState = Zoom_MovingOut;
         
         mZoomFieldOfView = mZoomEndFieldOfView;
         mZoomSteps       = (mZoomStartFieldOfView-mZoomEndFieldOfView)*0.60;
         mZoomZPos        = mZoomEndZPos;
         mZoomMoveRate    = 3.5;
         
         mZoomTimer.SetExpirePerSec( GAME_FRAME_TIME );
         mZoomTimer.Start();
         
         if(mCurrentBkg != NULL) mCurrentBkg->Update();
         if(mWarpPath != NULL)   mWarpPath->Update();
      }
      // Zoom Moving OUT
      if(mZoomState == Zoom_MovingOut)
      {
         mZoomTimer.Update();
         if(mZoomTimer.HasExpired())
         {
            mZoomTimer.Start();
            game->ChangePerspective(mZoomFieldOfView);
         
            mZoomFieldOfView -= mZoomMoveRate;
            mZoomZPos += ((float)(mZoomEndZPos - mZoomStartZPos)/
                         ((float)mZoomSteps/(float)mZoomMoveRate));
         
            if(mZoomFieldOfView < 0)
            {
               mZoomState  = Zoom_DoneOut;
               mLevelState = LevelState_Exit;
            }
         }
      }
      
   }
}

void cTitleLevel::Input(LevelInput input)
{
   if(input.Key == 'r')
   {
      Enter(mLevelNum);
      return;
   }

   // any key
   if( (input.Key != 0) || (input.SKey != 0) )
   {
      mZoomState = Zoom_StartOut;
      mWarpPath->ResetBackToStart();
   }

}

int  cTitleLevel::LoadSettings(const char *filename)
{
   // TODO
   
   return 0;
}
