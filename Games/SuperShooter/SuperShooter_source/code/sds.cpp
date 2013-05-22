//////////////////////////////   ////////////////////////////////////////////////
// Program Name:  sds.cpp
// Programmer:    Joseph E. Sutton
// Description:	Super Shooter - Game
// Course:        cs371
// Start Date:    10/23/2004
// Last Updated:  
// Version:       1.00
//////////////////////////////////////////////////////////////////////////////

#include "sds.h"

SuperShooter::SuperShooter()
{
   isLoaded = false;
   CurrentLevel = NULL;
   title = NULL;
   main = NULL;
   end = NULL;
   level_num = 0;
   last_level_num = 1;
}

SuperShooter::~SuperShooter()
{
   if(main != NULL)  delete main;
   if(title != NULL)  delete title;
}

void SuperShooter::Init()
{
   srand( (unsigned)time( NULL ) );

   lScore[0] = 0;
   lScore[1] = 0;
   lScore[2] = 0;
   title = new LevelTitle();
   main = new LevelMain();
   end = new LevelEnd();
  
   SelectTitleLevel();

   isLoaded = true;
}



void SuperShooter::PlayMusic()
{
   if(CurrentLevel != NULL)
      CurrentLevel->PlayMusic();
}


void SuperShooter::Draw()
{
   if(CurrentLevel != NULL)
      CurrentLevel->Draw();
}

void SuperShooter::Idle()
{
   UpdateLevelNum();

   if(CurrentLevel != NULL)
      CurrentLevel->Idle();
}

void SuperShooter::SetLevelNum(uInt8 ln)
{
   level_num = ln;
}

void SuperShooter::UpdateLevelNum()
{
   if( CurrentLevel != NULL)
   {
      if( CurrentLevel->isLevelOver() )
         NextLevel();

      if(last_level_num != level_num)
      {
         if( CurrentLevel != NULL)
         {
            // save previous score
            if( (last_level_num > 0) && (last_level_num < 4))
               lScore[last_level_num-1] = CurrentLevel->GetScore();

            // stop music
            CurrentLevel->StopMusic();

            // Call Exit Procedure
            CurrentLevel->Exit(0);
         }

         last_level_num = level_num;

         if( level_num == 0 )                            // 0
            SelectTitleLevel();
         else if( (level_num > 0) && (level_num < 4) )   // 1, 2, 3
            SelectMainLevel();
         else if( level_num == 4 )                       // 4
            SelectEndLevel();
         else                                            // reset back to title
            level_num = 0;
      }
   }
}

void SuperShooter::KeyPressed(bool down, bool skey, int key, int x, int y)
{
   if(CurrentLevel != NULL)
      CurrentLevel->KeyPressed(down, skey, key, x, y);
}

void SuperShooter::MouseClick(bool down, int button, int x, int y)
{
   if(CurrentLevel != NULL)
      CurrentLevel->MouseClick(down, button, x, y);
}

void SuperShooter::MouseMoved(int x, int y)
{
   if(CurrentLevel != NULL)
      CurrentLevel->MouseMoved(x, y);
}


void SuperShooter::SelectMainLevel()
{
   CurrentLevel = (Level *)main;
   CurrentLevel->Init(level_num-1);
   PlayMusic();
}

void SuperShooter::SelectTitleLevel()
{
   lScore[0] = 0;
   lScore[1] = 0;
   lScore[2] = 0;

   CurrentLevel = (Level *)title;
   CurrentLevel->Init();
   PlayMusic();
}

void SuperShooter::SelectEndLevel()
{
   CurrentLevel = (Level *)end;
   CurrentLevel->Init();
   PlayMusic();
}

//



