/* //////////////////////////////////////////////////////////////////////
 Program Name:  cFrame.cpp
 Programmer:    Joseph E. Sutton
 Start Date:    2006-06-15
 Updated:       
 Version:       1.00
 Description:
   Animation Frame Class Source File
   
////////////////////////////////////////////////////////////////////// */

#include "main.h"

cFrame::cFrame()
{
   w = 0;
   h = 0;

   frm = 0;
   state = 0;
   attack = 0;

   mvx = 0;
   mvy = 0;
   mvz = 0;
   ofx = 0;
   ofy = 0;
   scp = 0;

   col_type = 0;
   nap = 0;
   ap  = NULL;

   lyr_frm = 0;
   lyr_ofx = 0;
   lyr_ofy = 0;
   lyr_mvx = 0;
   lyr_mvy = 0;

   img = NULL;
}

cFrame::~cFrame()
{
   if(img != NULL)
   {
      destroy_bitmap(img);
      img = NULL;
   }

   if(nap > 0) {
      DELETE_A(ap);
   }
}

// all in one frame load 
int cFrame::Load(cTextFileReader *tfr, ImgData *src, uInt32 x_img_offset, uInt32 y_img_offset)
{
   tfr->ReadInt(w);
   tfr->ReadInt(h);

   img = create_bitmap(w, h);
   blit(src, img, 
        x_img_offset, y_img_offset,
        0, 0,
        w, h);
   
   return 0;
}



// multi file load
int cFrame::Load(const char *filename)
{
   img = load_bitmap(filename, NULL);
   if(img != NULL) {
      w = img->w;
      h = img->h;
   }

   return 0;
}


// multi file load
//   <type normal(0), flip_horz(1)>
//   -- if type normal, loaded from file --
//      <frame num> <shift x> <shift y> <hot x> <hot y>
//      <num of action lines>
//         <x> <length>
int cFrame::Load(cTextFileReader *tfr)
{
   tfr->ReadInt(mvx);
   tfr->ReadInt(mvy);

   tfr->ReadInt(ofx);
   tfr->ReadInt(ofy);

   tfr->ReadInt(scp);

   tfr->ReadInt(nap);
   if(nap > 0)
   {
      ap = new sAction[nap];

      uInt8 i;
      for(i = 0; i < nap; ++i)
      {
         tfr->ReadInt(ap[i].x1);
         tfr->ReadInt(ap[i].x2);
      }
   }

   return 0;
}

int cFrame::MakeMirror(cFrame *src, uInt32 last_frame, uInt32 last_layer)
{
   if(src == NULL) return 1;

   w = src->w;
   h = src->h;

   //
   if(src->img != NULL)
   {
      img = create_bitmap(w, h);
      rectfill(img, 0, 0, w, h, COLOR_TRANS);

      // flip src image
      draw_sprite_h_flip(img, src->img, 0, 0);
   } else {
      frm = src->frm + last_frame;
   }

   //
   state = src->state;
   attack = src->attack;
      
   // flip hot spot
   mvx -= src->mvx;
   ofx = w - src->ofx - 1;

   mvy = src->mvy;
   ofy = src->ofy;
   scp = -(src->scp);

   //
   col_type = src->col_type;
   nap = src->nap;
   if(nap > 0)
   {
      ap = new sAction[nap];
      uInt8 i;
      for(i = 0; i < nap; ++i)
      {
         ap[i].x1 = w - src->ap[i].x1 - 1;
         ap[i].x2 = w - src->ap[i].x2 - 1;
      }
   }

   //
   lyr_frm = src->lyr_frm + last_layer;
   lyr_ofx = src->lyr_ofx;
   lyr_ofy = src->lyr_ofy;
   lyr_mvx = src->lyr_mvx;
   lyr_mvy = src->lyr_mvy;

   return 0;
}