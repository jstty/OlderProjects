//////////////////////////////////////////////////////////////////////////////
// Program Name:  background.h
// Programmer:    Joseph E. Sutton
// Description:	Background
// Course:        cs371
// Start Date:    10/23/2004
// Last Updated:  
// Version:       1.00
//////////////////////////////////////////////////////////////////////////////
#ifndef _BACKGROUND_
#define _BACKGROUND_

#include "main.h"

const int bkg_max_pts = 15;
const int level_max = 3;
class Bkg
{
public:
   Bkg();
   ~Bkg();

   void Draw();
   void Scroll();
   void Reset();

protected:
   // Background
   float  *bkg_offset;
   uInt16 bkg[2][level_max][bkg_max_pts][2];
   uInt8  *bkg_pt_size;
   uInt8  *bkg_ln_length;

   // temp
   uInt32 i, x, y, level;

   //
   void Update(uInt8 bkgn, uInt8 ln);
};

#endif
