/* //////////////////////////////////////////////////////////////////////
 Program Name:  cRingStatusMenu.cpp
 Programmer:    Joseph E. Sutton
 Start Date:    2006-07-19
 Updated:       
 Version:       1.00
 Description:
   Ring Status Menu Class Source File
   
////////////////////////////////////////////////////////////////////// */

#include "main.h"


cRingStatusMenu::cRingStatusMenu()
{
   m_status_buff = NULL;

   m_frame = NULL;

   m_hpsize = 4;
   m_flagsize = 5;

   memset(pstat, 0, 2*sizeof(sPlayerStatus));
}

cRingStatusMenu::~cRingStatusMenu()
{
}


void cRingStatusMenu::Init()
{
   uInt8 i;

   m_status_w = info->display->GetWidth();
   m_status_h = info->display->GetHeight();

   m_status_buff = create_bitmap(m_status_w, m_status_h);

   m_frame = load_bitmap("data/status/both_sides.bmp", NULL);

   //
   i = 0;
      pstat[i].name = new cGfxText();
      pstat[i].name->SetFontIndex(0);
      pstat[i].name->SetSize(102, 9);
      pstat[i].name->SetCharPadding(0, 0);
      pstat[i].name->SetXY(41,7);
      pstat[i].name->SetAlign(TEXT_LEFT);

      pstat[i].star_text = new cGfxText();
      pstat[i].star_text->SetFontIndex(2);
      pstat[i].star_text->SetSize(9, 9);
      pstat[i].star_text->SetCharPadding(0, 0);
      pstat[i].star_text->SetXY(146,17);
      pstat[i].star_text->SetAlign(TEXT_CENTER);

      pstat[i].color_box = load_bitmap("data/status/color_box.bmp", NULL);

   //
   i = 1;
      pstat[i].name = new cGfxText();
      pstat[i].name->SetFontIndex(2);
      pstat[i].name->SetSize(102, 9);
      pstat[i].name->SetCharPadding(0, 0);
      pstat[i].name->SetXY(177,7);
      pstat[i].name->SetAlign(TEXT_RIGHT);

      pstat[i].star_text = new cGfxText();
      pstat[i].star_text->SetFontIndex(2);
      pstat[i].star_text->SetSize(9, 9);
      pstat[i].star_text->SetCharPadding(0, 0);
      pstat[i].star_text->SetXY(167,17);
      pstat[i].star_text->SetAlign(TEXT_CENTER);

      pstat[i].color_box = load_bitmap("data/status/color_box.bmp", NULL);

   //
   m_clock = new cRingClock();
   m_clock->SetTime(180);
}

void cRingStatusMenu::SetPlayer(uInt8 pn, cPlayer *p, uInt8 style, uInt8 type)
{
   if((pn >= 0) && (pn < 2))
   {
      pstat[pn].style = style;
      pstat[pn].type = type;

      pstat[pn].face = p->m_self->m_face;
      pstat[pn].fname = p->m_self->m_mname;
      pstat[pn].nhp   = &(p->m_hp);
      pstat[pn].nhp_max = &(p->m_hp_max);

      pstat[pn].nflags = &(p->m_combo_pts);
      pstat[pn].nstars = &(p->m_superstars);

      if(pstat[pn].fname != NULL) {
         pstat[pn].name->SetString(pstat[pn].fname);
         pstat[pn].name->Update();
      }

      if(pstat[pn].nstars != NULL) {
         pstat[pn].prev_nstars = pstat[pn].nstars[0];

         char s[256];
         sprintf(s, "%d", pstat[pn].prev_nstars);
         pstat[pn].star_text->SetString(s);
         pstat[pn].star_text->Update();
      }

   }

}

void cRingStatusMenu::Exit()
{
   if(m_status_buff != NULL) {
      destroy_bitmap(m_status_buff);
      m_status_buff = NULL;
   }

   FreeAll();

   int i;
   for(i = 0; i < 2; ++i)
   {
      if(pstat[i].color_box != NULL) {
         destroy_bitmap(pstat[i].color_box);
      }

      if(pstat[i].player_type != NULL) {
         destroy_bitmap(pstat[i].player_type);
      }

      DELETE(pstat[i].name);
   }

   //
   DELETE(m_clock);
}

void cRingStatusMenu::FreeAll()
{
   int i;
   for(i = 0; i < 2; ++i)
   {
      if(pstat[i].hp != NULL) {
         destroy_bitmap(pstat[i].hp);
         pstat[i].hp = NULL;
      }

      if(pstat[i].star != NULL) {
         destroy_bitmap(pstat[i].star);
         pstat[i].star = NULL;
      }

      if(pstat[i].player_type != NULL) {
         destroy_bitmap(pstat[i].player_type);
         pstat[i].player_type = NULL;
      }
   }

}

void cRingStatusMenu::Update()
{
   //
   m_clock->Update();
}

void cRingStatusMenu::Draw()
{
   if(m_status_buff != NULL)
   {
      int i;
      Int16 w;
      // clear
      rectfill(m_status_buff, 0, m_frame->h, m_status_w, m_status_h, COLOR_TRANS);

      // draw top
      blit(m_frame, m_status_buff, 
           0, 0,
           0, 0,
           m_frame->w, m_frame->h);
      
      //////////////////////////////////////////////////////////
      // player 1
      //////////////////////////////////////////////////////////
      i = 0;
         // face
         if(pstat[i].face != NULL)
         {
            blit(pstat[i].face, m_status_buff, 
                 0, 0,
                 0, 0,
                 pstat[i].face->w, pstat[i].face->h);
         }

         // color box
         if(pstat[i].color_box != NULL)
         {
            rectfill(pstat[i].color_box, 0, 0, 
                     pstat[i].color_box->w, pstat[i].color_box->h,
                     pstat[i].color);

            blit(pstat[i].color_box, m_status_buff, 
                 0, 0,
                 26, 5,
                 pstat[i].color_box->w, pstat[i].color_box->h);
         }

         // player type
         if(pstat[i].player_type != NULL)
         {
            blit(pstat[i].player_type, m_status_buff, 
                 0, 0,
                 27, 6,
                 pstat[i].player_type->w, pstat[i].player_type->h);
         }

         // energy
         if(pstat[i].hp != NULL) {
            w = ( ( (float)pstat[i].nhp[0]/(float)pstat[i].nhp_max[0] )*pstat[i].hp->w );
            w = (w + 1)/m_hpsize;
            w *= m_hpsize;
      
            blit(pstat[i].hp, m_status_buff, 
                 0, 0,
                 41, 17,
                 w, pstat[i].hp->h);
         }

         // star
         if(pstat[i].star != NULL) {
            blit(pstat[i].star, m_status_buff, 
                 0, 0,
                 145, 6,
                 pstat[i].star->w, pstat[i].star->h);
         }

         // name
         pstat[i].name->Draw(m_status_buff);


         // star text
         // update only when number of stars change
         if(pstat[i].prev_nstars != pstat[i].nstars[0]) {
            pstat[i].prev_nstars = pstat[i].nstars[0];

            char s[256];
            sprintf(s, "%d", pstat[i].prev_nstars);
            pstat[i].star_text->SetString(s);
            pstat[i].star_text->Update();
         }
         pstat[i].star_text->Draw(m_status_buff);
         //


      //////////////////////////////////////////////////////////
      // player 2
      //////////////////////////////////////////////////////////
      i = 1;
         // face
         if(pstat[i].face != NULL)
         {
            draw_sprite_h_flip(m_status_buff, pstat[i].face, 
               294, 0);
         }

         // color box
         if(pstat[i].color_box != NULL)
         {
            rectfill(pstat[i].color_box, 0, 0, 
                     pstat[i].color_box->w, pstat[i].color_box->h,
                     pstat[i].color);

            blit(pstat[i].color_box, m_status_buff, 
                 0, 0,
                 282, 5,
                 pstat[i].color_box->w, pstat[i].color_box->h);
         }

         // player type
         if(pstat[i].player_type != NULL)
         {
            blit(pstat[i].player_type, m_status_buff, 
                 0, 0,
                 283, 6,
                 pstat[i].player_type->w, pstat[i].player_type->h);
         }

         // energy
         if(pstat[i].hp != NULL) {
            w = ( ( (float)pstat[i].nhp[0]/(float)pstat[i].nhp_max[0] )*pstat[i].hp->w );
            w = (w + 1)/m_hpsize;
            w *= m_hpsize;
            w = pstat[i].hp->w - w;
      
            blit(pstat[i].hp, m_status_buff, 
                 w, 0,
                 200 + w, 17,
                 pstat[i].hp->w - w, pstat[i].hp->h);
         }

         // star
         if(pstat[i].star != NULL) {
            blit(pstat[i].star, m_status_buff, 
                 0, 0,
                 166, 6,
                 pstat[i].star->w, pstat[i].star->h);
         }

         // name
         pstat[i].name->Draw(m_status_buff);

         // star text
         // update only when number of stars change
         if(pstat[i].prev_nstars != pstat[i].nstars[0]) {
            pstat[i].prev_nstars = pstat[i].nstars[0];

            char s[256];
            sprintf(s, "%d", pstat[i].prev_nstars);
            pstat[i].star_text->SetString(s);
            pstat[i].star_text->Update();
         }
         pstat[i].star_text->Draw(m_status_buff);
         //

      //////////////////////////////////////////////////////////
      // draw clock
      //////////////////////////////////////////////////////////
      m_clock->Draw(m_status_buff, 105, 220);

      //////////////////////////////////////////////////////////
      // output to display
      //////////////////////////////////////////////////////////
      info->display->Draw(m_status_buff);
   }
}


int cRingStatusMenu::Load()
{
   FILE *fp;
   char filename[256], s[256];
   int r, g, b, i;
   
   // free bitmaps, incase already loaded
   FreeAll();

   for(i = 0; i < 2; ++i)
   {
      // player 1
      sprintf(filename, "data/status/%d/info", pstat[i].style);
      fp = fopen(filename, "r+");
      if(fp == NULL) {
         return 1; // error, could not load file
      }

      fscanf(fp, "%s", s);
      fscanf(fp, "%d", &r);
      fscanf(fp, "%d", &g);
      fscanf(fp, "%d", &b);
      fclose(fp);

      pstat[i].color = makecol(r, g, b);
      
      //
      sprintf(filename, "data/status/%d/health_%d.bmp", pstat[i].style, i);
      pstat[i].hp = load_bitmap(filename, NULL);

      sprintf(filename, "data/status/%d/star.bmp", pstat[i].style);
      pstat[i].star = load_bitmap(filename, NULL);

      pstat[i].name->SetString(pstat[i].fname);

      sprintf(filename, "data/status/%dp.bmp", pstat[i].type);
      pstat[i].player_type = load_bitmap(filename, NULL);
   }

   return 0;
}