/* //////////////////////////////////////////////////////////////////////
 Program Name:  cLvl_Intro.cpp
 Programmer:    Joseph E. Sutton
 Start Date:    2006-06-16
 Updated:       
 Version:       1.00
 Description:   
   Level Class Source File
   
////////////////////////////////////////////////////////////////////// */

#include "main.h"

cLvl_Intro::cLvl_Intro()
{
   m_intro = NULL;

   m_logo = NULL;

   m_prev_selection = 0;
   m_current_selection = 0;
}

cLvl_Intro::~cLvl_Intro()
{
}

int cLvl_Intro::Init()
{
   if(info != NULL)
   {
      if(info->display == NULL) return 2;
      m_display = info->display;

      int i;
      char s[256];
      m_stage = 0;

      //      
      m_star = new cImage*[NUM_STARS];
      m_star_delay = new uInt32[NUM_STARS];

      m_selection = new cGfxText*[NUM_SELECTIONS];
      for(i = 0; i < NUM_SELECTIONS; ++i)
      {
         m_selection[i] = new cGfxText[2];
      }
      m_layer_mngr = new cLayerMngr();


      //
      m_main_layer.SetName("main");
      m_main_layer.SetSize(320, 240, 1);
         m_intro = new cImage();
         m_intro->Load("data/intro/intro.anim");
         m_main_layer.Add("intro", m_intro);

      //
      m_select_layer.SetName("select");
      m_select_layer.SetSize(320, 240, 1);
         m_logo = new cImage();
         m_logo->LoadImage("data/intro/title.bmp");

         m_bkg = new cImage();
         m_bkg->LoadImage("data/intro/stadium.bmp");
         m_select_layer.Add("bkg",  m_bkg);

         for(i = 0; i < NUM_STARS; ++i)
         {
            m_star[i] = new cImage;
            m_star[i]->Load("data/intro/star_a.anim");
            
            sprintf(s, "star%d", i);
            m_star[i]->SetName(s);
            m_star[i]->Hide();

            m_select_layer.Add(s, m_star[i]);

            m_star_delay[i] = (rand() % STAR_DELAY);
            PickRandomStarPos(i);

            m_star[i]->Anim()->Pause();
         }

         m_select_layer.Add("logo", m_logo);

      // add layer to display
      m_layer_mngr->Add(&m_select_layer);
      m_layer_mngr->Add(&m_main_layer);
      
      //
      m_intro->Anim()->Play();

      m_select_layer.Hide();
      m_main_layer.Show();
      m_main_layer.FadeIn(10);

      m_logo->SetXY(40, 5);

      // selection
      InitSelection();

      m_selection_delay = 0;
      m_current_selection = 1;
      PrevSelection();

      return 0;
   }

   return 1;
}

int cLvl_Intro::Exit()
{
   int i;

   if(m_intro != NULL) { delete m_intro; m_intro = NULL; }

   if(m_logo != NULL)  { delete m_logo;  m_logo = NULL;  }
   if(m_bkg != NULL)   { delete m_bkg;   m_bkg = NULL;   }

   if(m_star != NULL)
   {
      for(i = 0; i < NUM_STARS; ++i)
      {
         if(m_star[i] != NULL) {
            delete m_star[i];
            m_star[i] = NULL;
         }
      }
      delete [] m_star;
      m_star = NULL;
   }

   if(m_selection != NULL)
   {
      for(i = 0; i < NUM_SELECTIONS; ++i)
      {
         if(m_selection[i] != NULL) {
            delete [] m_selection[i];
            m_selection[i] = NULL;
         }
      }

      delete [] m_selection;
      m_selection = NULL;
   }

   if(m_layer_mngr != NULL) {
      m_layer_mngr->FreeAllLayers();
      delete m_layer_mngr;
      m_layer_mngr = NULL;
   }

   return 0;
}


int cLvl_Intro::Loop()
{
   // intro fade in/out transistions
   if(m_stage < 10)
   {
       // if any key press, jump to m_stage 5
      if( keypressed() ||
          (info->p[PL_1][PL_A1]) ||
          (info->p[PL_1][PL_A2]) )
      {
         m_action1_key_was_up = false;

         m_stage = 10;
         m_main_layer.Hide();
         m_select_layer.Show();
      }

      // update ALL sprites and image animations in layer
      m_main_layer.Update();

      switch(m_stage)
      {
         case 0:
            if(m_main_layer.FadeDone())
            {
               if(m_intro->Anim()->FrameDone())
               {
                  m_intro->Anim()->Pause();
                  m_main_layer.FadeOut(10);
                  m_stage = 1;
               }
            }
            break;

         case 1:
            if(m_main_layer.FadeDone())
            {
               m_intro->Anim()->Play();
               m_main_layer.FadeIn(10);
               m_stage = 2;
            }
            break;

         case 2:
            if((m_main_layer.FadeDone()) && (m_intro->Anim()->FrameDone()) )
            {
               m_intro->Anim()->Pause();
               m_main_layer.FadeOut(10);
               m_stage = 3;
            }
            break;
      
         case 3:
            if(m_main_layer.FadeDone())
            {
               m_intro->Anim()->Pause();
               m_main_layer.Hide();

               m_select_layer.Show();
               m_select_layer.FadeIn(10);

               m_stage = 4;
            }
            break;

         case 4:
            m_select_layer.Update();

            if(m_select_layer.FadeDone())
            {
               m_stage = 10;
            }
            break;
      }
   }
   //

   // selection screen
   if(m_stage == 10)
   {
      int i;

      m_select_layer.Update();

      if(info->p[PL_1][PL_DOWN]) {
         NextSelection();
      }
      else if(info->p[PL_1][PL_UP]) {
         PrevSelection();
      } else {
         m_selection_delay = 0;
      }

      if( info->p[PL_1][PL_A1] && 
          m_action1_key_was_up )
      {
         for(i = 0; i < NUM_STARS; ++i) {
            m_star[i]->Anim()->Pause();
         }

         printf("Selected %d\n", m_current_selection);
         m_select_layer.FadeOut(10);
         m_stage = 11;

         return 0;
      } else if( !info->p[PL_1][PL_A1] ) {
         m_action1_key_was_up = true;
      }

      for(i = 0; i < NUM_STARS; ++i)
      {
         if(m_star_delay[i] > 0)  { --m_star_delay[i]; }

         if(m_star_delay[i] == 0) {

            if(!m_star[i]->Anim()->IsPlaying())
            {
               m_star[i]->Show();
               m_star[i]->Anim()->Play();
            } 
            else if(m_star[i]->Anim()->Done())
            {
               m_star[i]->Hide();
               m_star[i]->Anim()->Pause();

               m_star_delay[i] = (rand() % STAR_DELAY);
               PickRandomStarPos(i);

            }
         }
         
      }
   }
   else if(m_stage == 11) // final
   {
      m_select_layer.Update();

      if(m_select_layer.FadeDone())
      {
         m_stage = 12;

         // m_current_selection

         game->NextLevel();
      }
   }
   
   return 0;
}


int cLvl_Intro::Draw()
{
   if( (m_layer_mngr != NULL) &&
       (m_display != NULL) )
   {
      return m_display->Draw(m_layer_mngr, 1);
   }
   

   return 1;
}


void cLvl_Intro::PickRandomStarPos(int num)
{
   if( (num < 0) || (num >= NUM_STARS) ) return;
   if(m_star[num] == NULL) return;

   uInt32 x = (rand() % 310) + 5;
   uInt32 y = (rand() % 230) + 5;

   m_star[num]->SetXY(x, y);
}

void cLvl_Intro::InitSelection()
{
   char s[NUM_SELECTIONS][256];
   memset(s, '\0', NUM_SELECTIONS*255*sizeof(char));

   //strcpy(s[0], TEST_STR);
   //strcpy(s[1], " ");

   strcpy(s[0], "CLASSIC P1 TAG");
   strcpy(s[1], "CLASSIC P1 & P2 TAG");
   strcpy(s[2], "CLASSIC P1 vs P2 TAG");
   strcpy(s[3], "CUSTOM");
   strcpy(s[4], "NETWORK");
   strcpy(s[5], "OPTIONS");

   uInt16 w = 200;
   uInt16 h = 25;
   uInt8 spacing = 15;
   uInt8 start_x = 100;
   uInt8 start_y = 130;
   char tmp[256];

   uInt8 i;
   for(i = 0; i < NUM_SELECTIONS; ++i)
   {
      // off
      m_selection[i][0].SetSize(w, h);
      m_selection[i][0].SetFontIndex(2);
      m_selection[i][0].SetXY(start_x, start_y);
      m_selection[i][0].SetCharPadding(1, 2);
      m_selection[i][0].SetString(s[i]);

      sprintf(tmp, "sel_%d_off", i);
      m_select_layer.Add(tmp, (cGfxObj *)(&(m_selection[i][0])) );

      // on
      m_selection[i][1].SetSize(w, h);
      m_selection[i][1].SetFontIndex(4);
      m_selection[i][1].SetXY(start_x, start_y);
      m_selection[i][1].SetCharPadding(1, 2);
      m_selection[i][1].SetString(s[i]);

      sprintf(tmp, "sel_%d_on", i);
      m_select_layer.Add(tmp, (cGfxObj *)(&(m_selection[i][1])) );
     
      m_selection[i][0].Show();
      m_selection[i][1].Hide();

      start_y += spacing;
   }
}


void cLvl_Intro::NextSelection()
{
   if(m_selection_delay == 0)
   {
      m_selection_delay = SELECT_DELAY;
      m_prev_selection = m_current_selection;

      ++m_current_selection;
      if(m_current_selection >= NUM_SELECTIONS) {
         m_current_selection = 0;
      }

      UpdateSelection();
   } else {
      --m_selection_delay;
   }
}

void cLvl_Intro::PrevSelection()
{
   if(m_selection_delay == 0)
   {
      m_selection_delay = SELECT_DELAY;
      m_prev_selection = m_current_selection;

      --m_current_selection;
      if(m_current_selection == (uInt8)-1) {
         m_current_selection = NUM_SELECTIONS - 1;
      }

      UpdateSelection();
   } else {
      --m_selection_delay;
   }
}


void cLvl_Intro::UpdateSelection()
{
   m_selection[m_prev_selection][0].Show();
   m_selection[m_prev_selection][1].Hide();

   m_selection[m_current_selection][0].Hide();
   m_selection[m_current_selection][1].Show();
}
