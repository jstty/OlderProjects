/* //////////////////////////////////////////////////////////////////////
 Program Name:  cSuperStars.cpp
 Programmer:    Joseph E. Sutton
 Start Date:    2006-06-14
 Updated:       
 Version:       1.00
 Description:
   SuperStars Class Source File
   
////////////////////////////////////////////////////////////////////// */

#include "main.h"

cSuperStars::cSuperStars()
{
   m_lvlmngr = NULL;

   m_display = NULL;
   m_sound = NULL;
   m_controls = NULL;

   hotspot = NULL;

   font = NULL;
}


cSuperStars::~cSuperStars()
{

}

int cSuperStars::Exit()
{
   // init variables
   DELETE(m_lvlmngr);

   DELETE(m_intro);
   DELETE(m_ring01);

   DELETE(m_slowmo);

   DELETE(m_pause);
   DELETE(m_step);

   DELETE(m_player);

   DELETE(m_player_play);
   DELETE(m_player_load);
   DELETE(m_player_save);
   DELETE(m_pause_text);
   DELETE(m_player_text);

   if(hotspot != NULL) {
      destroy_bitmap(hotspot);
      hotspot = NULL;
   }

   //
   if(m_controls != NULL) m_controls->Exit();
   if(m_sound != NULL)    m_sound->Exit();
   if(m_display != NULL)  m_display->Exit();

   DELETE(m_controls);
   DELETE(m_sound);
   DELETE(m_display);

   DELETE(font);

   allegro_exit();

   return 0;
}

int cSuperStars::Init()
{
   srand(time(NULL)); // seed random

   //	initialize allegro objects
   allegro_init();
   install_timer();

   // init variables
   m_lvlmngr  = new cLevelMngr();

   m_display  = new cDisplay();
   m_sound    = new cSound();
   m_controls = new cControls();
   font       = new cFontMngr();
   
   // Display
      m_display->Init();
      info->display = m_display; // add display to info
   //

   // Sound
      m_sound->Init();
   //

   // Controls
      m_controls->Init();

      // load controls config
      m_controls->Load("config/controls.dat");
   //

   // Font Manager
   font->Init();
   //

   // Levels
      m_intro  = new cLvl_Intro();
      m_ring01 = new cLvl_Ring01();
   //

   // Level Manager
      m_lvlmngr->Init(5);

      m_lvlmngr->AddLevel(m_intro);
      m_lvlmngr->AddLevel(m_ring01);

      m_lvlmngr->FirstLevel();

      // jump to ring level
      m_lvlmngr->NextLevel();
   //


   // DEBUG
   hotspot   = load_bitmap("data/misc/hotspot.bmp", NULL);
   scopespot = load_bitmap("data/misc/scopespot.bmp", NULL);
   //


   //
   m_pause_text = new cGfxText();
   m_pause_text->SetFontIndex(2);
   m_pause_text->SetSize(70, 50);
   m_pause_text->SetXY(140, 115);
   m_pause_text->SetCharPadding(1, 2);
   m_pause_text->SetString("PAUSE");
   m_pause_text->Update();
   //

   //
   m_player_text = new cGfxText();
   m_player_text->SetFontIndex(2);
   m_player_text->SetSize(70, 20);
   m_player_text->SetXY(250, 220);
   m_player_text->SetCharPadding(1, 2);
   m_player_text->SetString("PLAYER");
   m_player_text->Hide();
   m_player_text->Update();
   //

   //
   m_fps_want = 50;
   //m_fps_want = 128;
   m_clock_start = clock();
   m_clock_diff_got = 0;
   m_loop_ticks = 0;
   m_clock_diff_want = 1000/m_fps_want;
   m_clock_diff_want_slowmo = 4000/m_fps_want;

   //
   m_pause = new cToggleAction();
   m_step = new cToggleAction();

   info->paused = false;
   m_pause->SetAction( &(info->g[ GAME_KEY_PAUSE ]) );
   m_step->SetAction( &(info->g[ GAME_KEY_STEP ]), 1 );


   m_player      = new cActionPlayer();
   m_player_play = new cToggleAction();
   m_player_load = new cToggleAction();
   m_player_save = new cToggleAction();

   m_player_state = 0;
   m_player_play->SetAction(  &(info->g[ GAME_KEY_PLAYER_PLAY ]) );
   m_player_load->SetAction(  &(info->g[ GAME_KEY_PLAYER_LOAD ]) );
   m_player_save->SetAction(  &(info->g[ GAME_KEY_PLAYER_SAVE ]) );


   m_reset = new cToggleAction();
   m_slowmo = new cToggleAction();
   m_reset->SetAction(   &(info->g[ GAME_KEY_RESET_LEVEL ]), 1 );
   m_slowmo->SetAction(  &(info->g[ GAME_KEY_SLOW_MOTION ]), 1 );

   return 0;
}

int cSuperStars::MainLoop()
{
   uInt32 count = 0;

// debug
#ifdef DEBUG
//  
   char s[256];
   int ticks_per_sec = 0;
   int loop_ticks = 0;
   clock_t last_sec_time = clock();
//         
#endif
//

   if( (m_lvlmngr == NULL) ||

       (m_display == NULL) ||
       (m_sound == NULL) ||
       (m_controls == NULL)
       ) {
      return 1;
   }

   m_controls->ProcessActions();
   while( !info->g[ GAME_KEY_ESC ] )
   {
      count++;

      m_clock_diff_got = clock() - m_clock_start;

      //////////////////////////////////////////////////////////
      if(m_clock_diff_got > m_clock_diff_want )
      {
// debug
#ifdef DEBUG
//         
         ++loop_ticks;

         if(clock() >= (last_sec_time + 1000) )
         {
            ticks_per_sec = loop_ticks;
            loop_ticks = 0;
            last_sec_time = clock();

            m_fps_got = (1000.0f)/((float)m_clock_diff_got);
            sprintf(s, "ticks  per sec %2d\nframes per sec %0.1f\n", 
                       ticks_per_sec, m_fps_got 
                   );

            system("CLS");
            printf(s);

            printf("count %d\ncount avg %0.1f\n", count, ((float)count)/m_fps_got );
            count = 0;
         }

         //m_info->DisplayActions();
         //m_controls->DisplayJoyStick();
//         
#endif
//
         //////////////////////////////////////////////////////////


         // pause, step
         m_pause->Update();
         if(m_pause->Get() != 0)
         {
            if(!info->paused)
            {
               info->paused = true;
               DrawPause();
               m_display->DrawUpdate();
            }

            m_controls->ProcessActions();

            if( m_step->Get() ) {
               info->paused = false;
            }
         } else if(info->paused) {
            info->paused = false;
         }
         //


         ///////////////////////////////////////////////////////
         m_player_load->Update();
         m_player_save->Update();
         if(m_player_load->Get() != 0) {
            //
            if(m_player_state == 0)
            {
               m_player_state = 1;
               m_player_text->Show();
               m_player_text->SetString("PLAYING");

               m_player->SetPlaying();
               m_player->Load("recordings/000.dat");
               m_player->UnPause();
            }
         } else {
            if(m_player_state == 1) {
               m_player_state = 0;
               m_player_text->Hide();
               m_player->Close();
            }
         }
      
         ///////////////////////////////////////////////////////
         if(m_player_save->Get() != 0) {
            //
            if(m_player_state == 0)
            {
               m_player_state = 2;
               m_player_text->Show();
               m_player_text->SetString("RECORDING");

               m_player->SetRecording();
               m_player->Save("recordings/000.dat");
               m_player->UnPause();
            }
         } else {
            if(m_player_state == 2) {
               m_player_state = 0;
               m_player_text->Hide();
               m_player->Close();
            }
         }

         ///////////////////////////////////////////////////////
         m_player_play->Update();
         if(m_player_play->Get() == 0) {

            if(m_player_state == 1) {
               m_player_text->SetString("PLAYING");
            } else 
            if(m_player_state == 2) {
               m_player_text->SetString("RECORDING");
            }

            m_player->UnPause();

         } else 
         if(m_player_play->Get() != 0) {
            m_player_text->SetString("PAUSED");
            m_player->Pause();
         }

         ///////////////////////////////////////////////////////
         // if reset pressed
         if(m_reset->Get()) {
            m_lvlmngr->ResetLevel();
         }
         ///////////////////////////////////////////////////////


         ///////////////////////////////////////////////////////
         // if slow motion pressed
         if(m_slowmo->Get()) {
            // swap slowmo and wanted
            uInt32 tmp = m_clock_diff_want_slowmo;
            m_clock_diff_want_slowmo = m_clock_diff_want;
            m_clock_diff_want = tmp;

            if(m_clock_diff_want > m_clock_diff_want_slowmo)
            {
               m_player_text->Show();
               m_player_text->SetString("SLOW MO");
            } else {
               m_player_text->Hide();
            }
         }
         ///////////////////////////////////////////////////////


         // if playing do animation...
         if(!info->paused)
         {
            m_controls->ProcessActions();
            m_player->Update();

            m_lvlmngr->UpdateLevel(); // exits, old level and starts new one, could take a while!

            m_lvlmngr->LevelLoop();
            m_lvlmngr->LevelDraw();
            m_lvlmngr->LevelSound();

            //
            DrawPlayerText();
            m_display->DrawUpdate();
         } // end play


         //////////////////////////////////////////////////////////
         m_clock_diff_got = 0;
         m_clock_start = clock();
      } // end frame loop
      //////////////////////////////////////////////////////////

   } // end while loop

   return 0;
}


float cSuperStars::GetFPS()
{
   return m_fps_got;
}


int cSuperStars::NextLevel()
{
   if(m_lvlmngr != NULL)  return m_lvlmngr->NextLevel();
   else                   return 100;
}

int cSuperStars::PrevLevel()
{
   if(m_lvlmngr != NULL)  return m_lvlmngr->PrevLevel();
   else                   return 100;
}

int cSuperStars::JumpLevel(uInt16 num)
{
   if(m_lvlmngr != NULL)  return m_lvlmngr->JumpLevel(num);
   else                   return 100;
}



void cSuperStars::DrawPause()
{
   m_display->Draw( m_pause_text );
}


void cSuperStars::DrawPlayerText()
{
   if(m_player_text->show) {
      m_display->Draw( m_player_text );
   }
}

