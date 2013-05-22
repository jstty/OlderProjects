/* //////////////////////////////////////////////////////////////////////
 Program Name:  cGfxText.cpp
 Programmer:    Joseph E. Sutton
 Start Date:    2006-06-29
 Updated:       
 Version:       1.00
 Description:
   Basic Graphical Text Class Source File
   uses a font
   LoadFont must be called before SetSize...
   
////////////////////////////////////////////////////////////////////// */

#include "main.h"

cGfxText::cGfxText()
{
   m_width = 0;
   m_height = 0;

   m_info.font_index = 0;
   m_info.h_align = TEXT_LEFT;
   m_info.v_align = TEXT_TOP;

   m_info.h_padding = 2;
   m_info.v_padding = 2;

   m_info.str = m_str;

   m_cframe = new cFrame();
}

cGfxText::~cGfxText()
{
   // have to delete, because allocated in constructor
   DELETE(m_cframe);
}

void cGfxText::SetSize(uInt32 w, uInt32 h)
{
   if(m_cframe == NULL) return;
   
   if(m_cframe->img != NULL)
   {
      destroy_bitmap(m_cframe->img);
      m_cframe->img = NULL;
   }

   m_width  = w;
   m_height = h;

   m_cframe->img = create_bitmap(m_width, m_height);
   m_cframe->w = w;
   m_cframe->h = h;
}



void cGfxText::SetCharPadding(uInt8 hp, uInt8 vp)
{
   m_info.h_padding = hp;
   m_info.v_padding = vp;
}

void cGfxText::SetAlign(uInt8 h, uInt8 v)
{
   m_info.h_align = h;
   m_info.v_align = v;
}

void cGfxText::SetFontIndex(uInt16 font_index)
{
   m_info.font_index = font_index;
}

void cGfxText::SetString(const char *str)
{
   m_info.str_len = strlen(str);
   memcpy(m_str, str, sizeof(char)*(m_info.str_len) + 1);
}


void cGfxText::Update()
{
   if(game != NULL)
   {
      if( (game->font != NULL) &&
          (m_cframe != NULL)
        )
      {
         game->font->Draw(m_cframe->img, m_info);
      }
   }
}

/*
void cGfxText::SetString(const char *str)
{
   uInt32 i, j, x, y, w, h;
   uInt32 max_w, row_max_w, row_max_h;

   if(m_cframe == NULL) return;

   m_str_len = strlen(str);
   memcpy(m_str, str, sizeof(char)*m_str_len + 1);

   // calc total width
   max_w = 0;
   for(i = 0; i < m_str_len; ++i) {
      // replace all underscors with spaces
      if(m_str[i] == '_') m_str[i] = ' ';

      max_w += m_list[ m_str[i] ]->w + m_hpadding;
   }

   
   // fill buffer with trans color
   rectfill(m_cframe->img, 0, 0, m_width, m_height, COLOR_TRANS);

   // default, top left
   w = 0;
   h = 0;
   x = 0;
   y = 0;
   row_max_w = 0;
   row_max_h = 0;

   // this only works for single row
   if( (m_halign == TEXT_CENTER) ||
       (m_halign == TEXT_RIGHT) )
   {
      // calc start pos
      if(max_w < m_width)
      {
         if(m_halign == TEXT_CENTER) {
            row_max_w = (m_width - max_w)/2;
         } else {
            row_max_w = m_width - max_w;
         }

         x = row_max_w; // set start point
      }
   }


   // TODO
   if( (m_valign == TEXT_MIDDLE) ||
       (m_valign == TEXT_BOTTOM) )
   {
      // TODO
      if(m_valign == TEXT_MIDDLE){

      } else {

      }
   }
   //

   for(i = 0; i < m_str_len; ++i)
   {
      j = m_str[i];

      if(m_list[j] != NULL)
      {
         // if newline char or
         // if current width + next width is greater then width
         if( (j == '\n') ||
             ((row_max_w + m_list[j]->w + m_hpadding) > m_width) )
         {
            // move to next row
            h += row_max_h + m_vpadding;
            y  = h;

            x = 0;
            row_max_w = 0;
            row_max_h = 0;

            masked_blit(m_list[j], m_cframe->img, 
               0, 0, 
               x, y, 
               m_list[j]->w, m_list[j]->h
               );
         } else {
            masked_blit(m_list[j], m_cframe->img, 
               0, 0, 
               x, y, 
               m_list[j]->w, m_list[j]->h
               );

            row_max_w += m_list[j]->w + m_hpadding;
            x = row_max_w;

            // get max height
            if(m_list[j]->h > (int)row_max_h) row_max_h = m_list[j]->h;
         }
      }
   }
   //
}
*/
//