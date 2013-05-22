/* //////////////////////////////////////////////////////////////////////
 Program Name:  cWrestler.cpp
 Programmer:    Joseph E. Sutton
 Start Date:    2006-07-15
 Updated:       
 Version:       1.00
 Description:
   Generic Wrestler Class Header File
   
////////////////////////////////////////////////////////////////////// */

#include "main.h"

cWrestler::cWrestler()
{
   cGfxObj();
   m_size   = WSIZE_SMALL;
   m_nstyle = 0;
   m_cstyle = 0;
   m_style  = NULL;

   m_null_img = NULL;
   m_empty_img = NULL;
}

cWrestler::cWrestler(const cWrestler &src) : cSprite(src)
{
   uInt32 i;
   m_size = src.m_size;
   strcpy(m_sname, src.m_sname);
   strcpy(m_mname, src.m_mname);
   strcpy(m_lname, src.m_lname);
   strcpy(m_tname, src.m_tname);

   m_speed_walk = src.m_speed_walk;
   m_speed_run  = src.m_speed_run;
   m_speed_lock = src.m_speed_lock;

   m_nstyle  = src.m_nstyle;
   m_cstyle  = src.m_cstyle;
   m_style   = new sStyle[m_nstyle];
   for(i = 0; i < m_nstyle; ++i)
   {
      m_style[i] = src.m_style[i];
   }

   m_empty_img = src.m_empty_img;
   m_null_img = src.m_null_img;

   SelectStyle(m_cstyle);
}

cWrestler::~cWrestler()
{
   uInt32 i, j;
   for(i = 0; i < m_nstyle; ++i)
   {
      for(j = 0; j < m_style[i].nframes; ++j)
      {
         if( (m_style[i].frames[j] != m_empty_img) &&
             (m_style[i].frames[j] != m_null_img)
           )
            destroy_bitmap(m_style[i].frames[j]);
      }

      for(j = 0; j < m_style[i].nimgs; ++j)
      {
         if( (m_style[i].imgs[j] != m_empty_img) &&
             (m_style[i].imgs[j] != m_null_img)
           )
            destroy_bitmap(m_style[i].imgs[j]);
      }

      for(j = 0; j < m_style[i].nlayers; ++j)
      {
         if( (m_style[i].layers[j] != m_empty_img) &&
             (m_style[i].layers[j] != m_null_img)
           )
            destroy_bitmap(m_style[i].layers[j]);
      }

      DELETE_A(m_style[i].frames);
      DELETE_A(m_style[i].imgs);
      DELETE_A(m_style[i].layers);
   }

   destroy_bitmap(m_null_img);
   destroy_bitmap(m_empty_img);

   DELETE_A(m_style);
   m_nstyle = 0;
}


// file struct
// <short name>
// <mid   name>
// <long  name>
// <team  name>
// <size>
// <walking speed> <running speed> <side headlock speed>
// <number of styles>
// <default prim move 1 name>
// <default prim move 2 name>
int cWrestler::Load(const char *filename, cBaseWrestler *base)
{
   uInt8  i;
   uInt16 j;
   uInt32 w, h, k, size;
   FILE *fp;
   char s[256], f[256], path[256];

   // get file path
   Int32 path_len = (Int32)(strrchr(filename, '/') - filename + 1);
   strncpy(path, filename, sizeof(char)*path_len);
   path[path_len] = '\0';
   //

   fp = fopen(filename, "r+");
   if(fp == NULL) {
      return 1; // could not load file
   }

   fscanf(fp, "%s", s);
   strcpy(m_sname, s);
   fscanf(fp, "%s", s);
   strcpy(m_mname, s);
   fscanf(fp, "%s", s);
   strcpy(m_lname, s);
   fscanf(fp, "%s", s);
   strcpy(m_tname, s);

   fscanf(fp, "%d", &m_size);
   fscanf(fp, "%d", &m_speed_walk);
   fscanf(fp, "%d", &m_speed_run);
   fscanf(fp, "%d", &m_speed_lock);

   fscanf(fp, "%d", &m_nstyle);
   m_cstyle = 0;

   // default prim move 1 name
   // TODO
   // default prim move 2 name
   // TODO
   fclose(fp);
   //

   sprintf(s, "%snull.bmp", path);
   m_null_img = load_bitmap(s, NULL);

   sprintf(s, "%sempty.bmp", path);
   m_empty_img = load_bitmap(s, NULL);


   m_style = new sStyle[m_nstyle];
   for(i = 0; i < m_nstyle; ++i)
   {
      // 2 times because of mirror
      m_style[i].nframes = 2*base->nframes;
      m_style[i].frames  = new ImgData*[m_style[i].nframes];

      // 2 times because of mirror
      m_style[i].nimgs = 2*base->nimgs;
      m_style[i].imgs  = new ImgData*[m_style[i].nimgs];

      // 2 times because of mirror
      m_style[i].nlayers = 2*base->nlayers;
      m_style[i].layers  = new ImgData*[m_style[i].nlayers];

      // Frames
      sprintf(s, "%s%d/%s", path, i, base->frame_str);
      size = m_style[i].nframes/2;
      for(j = 0; j < size; ++j)
      {
         sprintf(f, s, j);
         m_style[i].frames[j] = load_bitmap(f, NULL);

         k = j + size;
         if(m_style[i].frames[j] == NULL)
         {
            m_style[i].frames[j] = m_null_img;
            m_style[i].frames[k] = m_null_img;
         } else {
            // create mirror
            w = m_style[i].frames[j]->w;
            h = m_style[i].frames[j]->h;

            m_style[i].frames[k] = create_bitmap(w, h);

            rectfill(m_style[i].frames[k], 0, 0, w, h, COLOR_TRANS);
            // flip src image
            draw_sprite_h_flip(m_style[i].frames[k], 
                               m_style[i].frames[j],
                               0, 0);
         }
      }

      // Images
      sprintf(s, "%s%d/%s", path, i, base->img_str);
      size = m_style[i].nimgs/2;

      for(j = 0; j < size; ++j)
      {
         sprintf(f, s, j);
         m_style[i].imgs[j] = load_bitmap(f, NULL);

         k = j + size;
         if(m_style[i].imgs[j] == NULL)
         {
            m_style[i].imgs[j] = m_null_img;
            m_style[i].imgs[k] = m_null_img;
         } else {
            // create mirror
            w = m_style[i].imgs[j]->w;
            h = m_style[i].imgs[j]->h;
            
            m_style[i].imgs[k] = create_bitmap(w, h);
            rectfill(m_style[i].imgs[k], 0, 0, w, h, COLOR_TRANS);
            // flip src image
            draw_sprite_h_flip(m_style[i].imgs[k], 
                               m_style[i].imgs[j],
                               0, 0);
         }
      }

      // Layers
      sprintf(s, "%s%d/%s", path, i, base->layer_str);
      size = m_style[i].nlayers/2;
      for(j = 0; j < size; ++j)
      {
         sprintf(f, s, j);
         m_style[i].layers[j] = load_bitmap(f, NULL);

         k = j + size;
         if(m_style[i].layers[j] == NULL) 
         {
            m_style[i].layers[j] = m_null_img;
            m_style[i].layers[k] = m_null_img;
         } else {
            // create mirror
            w = m_style[i].layers[j]->w;
            h = m_style[i].layers[j]->h;
            
            m_style[i].layers[k] = create_bitmap(w, h);
            rectfill(m_style[i].layers[k], 0, 0, w, h, COLOR_TRANS);
            // flip src image
            draw_sprite_h_flip(m_style[i].layers[k], 
                               m_style[i].layers[j],
                               0, 0);
         }
      }
   }

   sprintf(s, "%swrestler.wad", path);

   //
   m_anim->InitFrames(base->anim);
   m_anim->LoadFrames(s, base->anim);
   m_anim->UpdateFrames(m_style[0].frames);
   m_anim->MirrorFrames(m_style[0].nframes/2, m_style[0].nlayers/2);
   
   // select first style
   SelectStyle(m_cstyle);

   return 0;
}

void cWrestler::DrawLayer(ImgData *out, Int32 offset_x, Int32 offset_y)
{
   if( (m_cframe == NULL) ||
       (m_cstyle > m_nstyle) ||
       (m_cframe->lyr_frm > m_style[m_cstyle].nlayers) )
   {
      // draw nothing
   } else {
      // set img from layer
      m_cframe->img = m_style[m_cstyle].layers[m_cframe->lyr_frm];
 
      cSprite::Draw(out, 
                    m_cframe->lyr_ofx + offset_x,
                    m_cframe->lyr_ofy + offset_y);
      
      // set to null so don't de-allocated
      m_cframe->img = NULL;
   }
}

void cWrestler::DrawFrame(ImgData *out, Int32 offset_x, Int32 offset_y)
{
   if( (m_cframe == NULL) ||
       (m_cstyle > m_nstyle) ||
       (m_cframe->frm > m_style[m_cstyle].nframes) )
   {
      masked_blit(m_empty_img, out, 
         0, 0, 
         xpos + offset_x - xhot,
         ypos + zpos + offset_y - yhot,
         m_null_img->w, m_null_img->h 
         );
   } else {
      // set img from frame
      m_cframe->img = m_style[m_cstyle].frames[m_cframe->frm];

      cSprite::Draw(out, offset_x, offset_y);
      
      // set to null so don't de-allocated
      m_cframe->img = NULL;
   }
}


void cWrestler::SelectStyle(uInt8 s)
{
   if(s < m_nstyle) {
      m_cstyle = s;

      m_face = m_style[m_cstyle].imgs[10];
   }
}

