/* //////////////////////////////////////////////////////////////////////
 Program Name:  cFontMngr.cpp
 Programmer:    Joseph E. Sutton
 Start Date:    2006-08-03
 Updated:       
 Version:       1.00
 Description:
   Font Manager Class Source File
   
////////////////////////////////////////////////////////////////////// */

#include "main.h"

cFontMngr::cFontMngr()
{
   m_size = 0;

   m_list = NULL;
}


cFontMngr::~cFontMngr()
{
   FreeAll();
}


void cFontMngr::FreeAll()
{
   if(m_list != NULL)
   {
      uInt32 i, j;
      sFont tmp;
      for(i = 0; i < m_size; ++i)
      {
         tmp = m_list[i];

         for(j = 0; j < tmp.list_size; ++j)
         {
            if(tmp.img_list != NULL)
            {
               if( (tmp.img_list[j] != NULL) &&
                   (tmp.img_list[j] != tmp.error_char_img) ) {
                  destroy_bitmap(tmp.img_list[j]);
               }

               tmp.img_list[j] = NULL;
            }
         } // end for loop
         DELETE_A(tmp.img_list);
         tmp.list_size = 0;

         if(tmp.error_char_img != NULL) {
            destroy_bitmap(tmp.error_char_img);
            tmp.error_char_img = NULL;
         }
      } // end for loop
      DELETE_A(m_list);
      m_size = 0;

   }  // end if m_list != NULL
}

int cFontMngr::Init()
{
   int e;
   uInt16 i;
   FILE *fp;
   char filename[256];

   strcpy(filename, "data/fonts/info");
   fp = fopen(filename, "r+");
   if(fp == NULL) {
      return 1;
   }

   FreeAll();
   fscanf(fp, "%d", &m_size);

   // allocat font
   m_list = new sFont[m_size];
   memset(m_list, 0, m_size*sizeof(sFont));
   
   // load ALL fonts
   e = 0;
   for(i = 0; i < m_size; ++i)
   {
      e = LoadFont(i);
      if(e) {
         FreeAll();
         return e;
      }
   }

   return 0;
}



// file struct
// <width> <height>  // of each font
int cFontMngr::LoadFont(uInt16 font_index)
{
   uInt16 i;
   uInt32 w, h, xpos;
   char filename[256];
   FILE *fp;
   ImgData *tmp_font;
   sFont *tmp;

   tmp = &(m_list[font_index]);

   //
   sprintf(filename, "data/fonts/%0.2d.bmp", font_index);
   tmp_font = load_bitmap(filename, NULL);
   if(tmp_font == NULL) {
      return 2;
   }

   sprintf(filename, "data/fonts/%0.2d.font", font_index);
   fp = fopen(filename, "r+");
   if(fp == NULL) {
      return 1;
   }


   tmp->list_size = 255;
   tmp->img_list = new ImgData*[tmp->list_size];
   memset(tmp->img_list, 0, tmp->list_size*sizeof(ImgData*));

   // composite font file
   xpos = 0;
   for(i = 0; i < tmp->list_size ; ++i)
   {
      fscanf(fp, "%d", &w);
      fscanf(fp, "%d", &h);

      if(i == 0) {
         tmp->error_char_img = create_bitmap(w, h);
         blit(tmp_font, tmp->error_char_img, xpos, 0, 0, 0, w, h);
         w = tmp->error_char_img->w;
         h = tmp->error_char_img->h;
         // and set first to error char
         tmp->img_list[i] = tmp->error_char_img;
      } else {

         if(w != 0)
         {
            tmp->img_list[i] = create_bitmap(w, h);
            blit(tmp_font, tmp->img_list[i], xpos, 0, 0, 0, w, h);
         } else {
            tmp->img_list[i] = tmp->error_char_img;
            w = tmp->error_char_img->w;
            h = tmp->error_char_img->h;
         }
      }

      xpos += w;
   }

   destroy_bitmap(tmp_font);
   fclose(fp);
   
   return 0;
}



int cFontMngr::Draw(ImgData *out, const sTextInfo &text_info)
{
   uInt32 i, j, x, y, w, h;
   uInt32 max_w, row_max_w, row_max_h;
   uInt32 out_width, out_height;

   char str[256];
   uInt8 str_len, hpadding, vpadding, halign, valign;
   uInt16 size;
   ImgData **list;

   // error check
   if(text_info.font_index > m_size) return 1;
   if(out == NULL) return 2;
   //

   // copy for local
   str_len = text_info.str_len;
   strcpy(str, text_info.str);
   hpadding = text_info.h_padding;
   vpadding = text_info.v_padding;
   halign = text_info.h_align;
   valign = text_info.v_align;

   size = m_list[ text_info.font_index ].list_size;
   list = m_list[ text_info.font_index ].img_list;

   // calc total width
   max_w = 0;
   for(i = 0; i < str_len; ++i) {
      // replace all underscors with spaces
      if(str[i] == '_') str[i] = ' ';

      max_w += list[ str[i] ]->w + hpadding;
   }

   
   // fill buffer with trans color
   out_width = out->w;
   out_height = out->h;
   rectfill(out, 0, 0, out_width, out_height, COLOR_TRANS);

   // default, top left
   w = 0;
   h = 0;
   x = 0;
   y = 0;
   row_max_w = 0;
   row_max_h = 0;

   // this only works for single row
   if( (halign == TEXT_CENTER) ||
       (halign == TEXT_RIGHT) )
   {
      // calc start pos
      if((Int32)max_w < out->w)
      {
         if(halign == TEXT_CENTER) {
            row_max_w = (out_width - max_w)/2;
         } else {
            row_max_w = out_width - max_w;
         }

         x = row_max_w; // set start point
      }
   }


   // TODO
   if( (valign == TEXT_MIDDLE) ||
       (valign == TEXT_BOTTOM) )
   {
      // TODO
      if(valign == TEXT_MIDDLE){

      } else {

      }
   }
   //

   for(i = 0; i < str_len; ++i)
   {
      j = str[i];

      if(list[j] != NULL)
      {
         // if newline char or
         // if current width + next width is greater then width
         if( (j == '\n') ||
             ((row_max_w + list[j]->w + hpadding) > out_width) )
         {
            // move to next row
            h += row_max_h + vpadding;
            y  = h;

            x = 0;
            row_max_w = 0;
            row_max_h = 0;

            masked_blit(list[j], out, 
               0, 0, 
               x, y, 
               list[j]->w, list[j]->h
               );
         } else {
            masked_blit(list[j], out, 
               0, 0, 
               x, y, 
               list[j]->w, list[j]->h
               );

            row_max_w += list[j]->w + hpadding;
            x = row_max_w;

            // get max height
            if(list[j]->h > (int)row_max_h) row_max_h = list[j]->h;
         }
      }
   }
   //

   return 0;
}



//////////////////////////////////////////////////////////////////////
// 
//////////////////////////////////////////////////////////////////////
int cFontMngr::CompileFontDir(const char *dir)
{
   uInt16 i;
   char tmp_file[256];
   char dirname[256];
   FILE *info_fp, *tmp_fp;
   Int32 dirname_pos, dirname_len;
   uInt32 w, h;

   // temp should be deleted at end
   uInt32    size = 0;
   ImgData  *error_char_img = NULL;
   ImgData **list = NULL;


   dirname_pos = (Int32)(strrchr(dir, '/') - dir + 1);
   if(dirname_pos < 1) {
      dirname_pos = 0;
   }
   dirname_len = strlen(dir) - dirname_pos;

   strncpy(dirname, &(dir[dirname_pos]), sizeof(char)*dirname_len);
   dirname[dirname_len] = '\0';

   FreeAll();

   sprintf(tmp_file, "%s/%s", dir, "xx.bmp");
   error_char_img = load_bitmap(tmp_file, NULL);
   if(error_char_img == NULL) {
      return 2;
   }

   // allocate
   size = 255;
   list = new ImgData*[size];

   // load and get max info
   w = 0;
   h = 0;
   for(i = 0; i < size; ++i)
   {
      // build filename
      sprintf(tmp_file, "%s/fnt_%d.bmp", dir, i);

      // test if file exists
      tmp_fp = fopen(tmp_file, "r+");
      if(tmp_fp == NULL) {
         // if not use def
         list[i] = error_char_img;
      } else {
         // if so load bitmap
         fclose(tmp_fp);

         list[i] = load_bitmap(tmp_file, NULL);     
         // if could not load image
         if(list[i] == NULL) {
            list[i] = error_char_img;
         }
      }

      w += list[i]->w;
      if((uInt32)list[i]->h > h) h = list[i]->h;
   }

   sprintf(tmp_file, "%s/%s.font", dir, dirname);
   info_fp = fopen(tmp_file, "w+");
   
   ImgData *out_font = create_bitmap(w, h);
   rectfill(out_font, 0, 0, w, h, COLOR_TRANS);


   uInt32 xpos = 0;
   for(i = 0; i < 255; ++i)
   {
      if( (list[i] != error_char_img) ||
          (i == 0)
        )
      {
         fprintf(info_fp, "%d %d\n", list[i]->w, list[i]->h);
      } else {
         fprintf(info_fp, "%d %d\n", 0, 0);
      }

      blit(list[i], out_font, 0, 0, xpos, 0, list[i]->w, list[i]->h);
      xpos += list[i]->w;
   }

   sprintf(tmp_file, "%s/%s.bmp", dir, dirname);
   save_bitmap(tmp_file, out_font, NULL);

   fclose(info_fp);


   // clean up
   if(list != NULL)
   {
      for(i = 0; i < size; ++i)
      {
         if( (list[i] != NULL) &&
             (list[i] != error_char_img) ) {
            destroy_bitmap(list[i]);
         }

         list[i] = NULL;
      } // end for loop
      DELETE_A(list);
      size = 0;
   }

   if(error_char_img != NULL) {
      destroy_bitmap(error_char_img);
      error_char_img = NULL;
   }
   //

   return 0;
}