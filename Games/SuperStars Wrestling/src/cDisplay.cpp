/* //////////////////////////////////////////////////////////////////////
 Program Name:  cDisplay.cpp
 Programmer:    Joseph E. Sutton
 Start Date:    2006-06-18
 Updated:       
 Version:       1.00
 Description:
   Controls Class Source File
   
////////////////////////////////////////////////////////////////////// */

#include "main.h"


cDisplay::cDisplay()
{
   //m_layer_mngr = NULL;
   m_exited = false;
}


cDisplay::~cDisplay()
{
   Exit();
}

int cDisplay::Init()
{
   int e;
   // load display config
   m_width  = GAME_WIDTH;
   m_height = GAME_HEIGHT;

   set_color_depth(32);

#ifdef DEBUG
   m_scale = GAME_DEBUG_SCALE;
   e = set_gfx_mode(GFX_AUTODETECT_WINDOWED, m_scale*m_width, m_scale*m_height, 0, 0);
#else
   m_scale = 1;
   e = set_gfx_mode(GFX_SAFE, m_width, m_height, 0, 0);
#endif

   if(e != 0) {
      // error
      return 1;
   }

   m_buffer = create_bitmap(m_width, m_height);

   return 0;
}

int cDisplay::Exit()
{
   if(!m_exited)
   {
      if(m_buffer != NULL)
      {
         destroy_bitmap(m_buffer);
         m_buffer = NULL;
      }

      m_exited = true;
   }

   return 0;
}


uInt32 cDisplay::GetWidth()
{
   return m_width;
}


uInt32 cDisplay::GetHeight()
{
   return m_height;
}


uInt8 cDisplay::GetScale()
{
   return m_scale;
}

int cDisplay::Draw(cLayerMngr *lm, bool clear_buffer)
{ 
   if( (m_buffer == NULL) ||
       (lm == NULL) ) {
      return 1;
   }

   // clear buffer
   if(clear_buffer) {
      rectfill(m_buffer, 0, 0, m_width, m_height, COLOR_BLACK);
   }

   lm->Draw(m_buffer, clear_buffer);

   return 0;
}

int cDisplay::Draw(ImgData *src, uInt32 x, uInt32 y, bool clear_buffer)
{
   if( (m_buffer == NULL) ||
       (src == NULL) ) {
      return 1;
   }

   // clear buffer
   if(clear_buffer) {
      rectfill(m_buffer, x, y, m_width, m_height, COLOR_BLACK);
   }

   //draw_sprite(m_buffer, src, x, y);
   masked_blit(src, m_buffer, 
         0, 0, 
         x, y, 
         src->w, src->h
         );

   return 0;
}

int cDisplay::DrawUpdate()
{
   acquire_screen();
   if(m_scale > 1)
   {
      stretch_blit(m_buffer, screen, 
        0, 0, m_width, m_height, 
        0, 0, m_scale*m_width, m_scale*m_height
        );
   } else {
      // write buffer to screen
      blit(m_buffer, screen, 
           0, 0, 
           0, 0, 
           m_width, m_height);
   }
   release_screen();

   return 0;
}


int cDisplay::Draw(cGfxObj *gfxobj)
{
   if(gfxobj != NULL)
   {
      gfxobj->Draw(m_buffer, 0, 0);
      DrawUpdate();
   }

   return 0;
}