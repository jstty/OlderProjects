//////////////////////////////////////////////////////////////////////////////
// Program Name:  background.cpp
// Programmer:    Joseph E. Sutton
// Description:	Background
// Course:        cs371
// Start Date:    10/23/2004
// Last Updated:  
// Version:       1.00
//////////////////////////////////////////////////////////////////////////////

#include "background.h"

Bkg::Bkg()
{
   bkg_offset = new float[level_max];
   bkg_pt_size = new uInt8[level_max];
   bkg_ln_length = new uInt8[level_max];

   Reset();
}

Bkg::~Bkg()
{
   if(bkg_offset != NULL)     delete bkg_offset;
   if(bkg_pt_size != NULL)    delete bkg_pt_size;
   if(bkg_ln_length != NULL)  delete bkg_ln_length;
}

void Bkg::Reset()
{
   bkg_offset[0] = 0;
   bkg_offset[1] = 0;
   bkg_offset[2] = 0;

   bkg_pt_size[0] = 1;
   bkg_pt_size[1] = 2;
   bkg_pt_size[2] = 3;
   bkg_ln_length[0] = 10;
   bkg_ln_length[1] = 15;
   bkg_ln_length[2] = 30;
   Update(0, 0);
   Update(0, 1);
   Update(0, 2);
   Update(1, 0);
   Update(1, 1);
   Update(1, 2);
}

void Bkg::Draw()
{
   for(level=0; level < level_max; level++)
   {
      glLineWidth(bkg_pt_size[level]);

      glBegin(GL_LINES);
      for(i=0; i < bkg_max_pts; i++)
      {
         glColor4f(0.5, 0.5, 0.5, 0.0);
         glVertex2i(bkg_offset[level] + bkg[0][level][i][0], bkg[0][level][i][1]);
         glColor4f(0.0, 0.0, 0.0, 1.0);
         glVertex2i(bkg_ln_length[level] + bkg_offset[level] + bkg[0][level][i][0], bkg[0][level][i][1]);

         glColor4f(0.5, 0.5, 0.5, 0.0);
         glVertex2i(MAX_WIDTH + bkg_offset[level] + bkg[1][level][i][0], bkg[1][level][i][1]);
         glColor4f(0.0, 0.0, 0.0, 1.0);
         glVertex2i(bkg_ln_length[level] + MAX_WIDTH + bkg_offset[level] + bkg[1][level][i][0], bkg[1][level][i][1]);
      }
      glEnd();
   }
}

void Bkg::Scroll()
{
   bkg_offset[0] -= BACKGROUND_OFFSET1_SPEED;
   bkg_offset[1] -= BACKGROUND_OFFSET2_SPEED;
   bkg_offset[2] -= BACKGROUND_OFFSET3_SPEED;

   for(level=0; level < level_max; level++)
   {
      if( bkg_offset[level] <= -(MAX_WIDTH + bkg_ln_length[2]) )
      {
         bkg_offset[level] += MAX_WIDTH;
         memcpy(bkg[0][level], bkg[1][level], sizeof(uInt16)*bkg_max_pts*2);
         Update(1, level);
      }
   }
}

void Bkg::Update(uInt8 bkgn, uInt8 ln)
{
   if(bkgn == 0 || bkgn == 1)
   {
      x = MAX_WIDTH;
      y = MAX_HEIGHT-100;
      
      for(i=0; i < bkg_max_pts; i++)
      {
         bkg[bkgn][ln][i][0] = rand()%x;
         bkg[bkgn][ln][i][1] = 100 + rand()%y;
      }
   }
}

