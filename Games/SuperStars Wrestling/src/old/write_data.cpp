////////////////////////////////////////////////////////////////////////////////
//
//	Title      Super Stars of Wrestling
//	Author     Joseph E. Sutton
//	Copyright  2006
//	Version    1.0.0.0
//
////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include "Source/header.h"
#include "Source/main_header.h"
#include "write_data.h"

#define FWRITE(A, B) fwrite(&(A), sizeof(A), 1, B);

int write_data(int id)
{
	FILE *fp;
   char filename[256];
   unsigned int i, size;

   sprintf(filename, "base.frd");

	fp = fopen(filename, "w+");
   if(fp == NULL) return 2;

   size = KEYS;
   FWRITE(size, fp);
   for(i = 0; i < size; ++i)
   {
      FWRITE(GameObject[id].obj_frm[0][i], fp); //	Object Animation GFX Frame to Display

      FWRITE(GameObject[id].obj_sta[i], fp);    //	Animation State Value
      FWRITE(GameObject[id].obj_atk[i], fp);    //	Animation Attack Value
      FWRITE(GameObject[id].obj_dly[i], fp);    //	Object Animation Delay till Next Frame
      FWRITE(GameObject[id].obj_nxt[i], fp);    //	Object Animation Next Frame

      FWRITE(GameObject[id].obj_mvx[0][i], fp); //	Object X Movement (Tween) Permanent
      FWRITE(GameObject[id].obj_mvy[0][i], fp); //	Object Y Movement (Tween) Tempoary Offset
      FWRITE(GameObject[id].obj_mvz[0][i], fp); //	Object Y Movement (Tween) Permanent
      FWRITE(GameObject[id].obj_ofx[0][i], fp); //	Object Animation GFX X-Offset
      FWRITE(GameObject[id].obj_ofy[0][i], fp); //	Object Animation GFX Y-Offset
      FWRITE(GameObject[id].obj_scp[0][i], fp); //	Object Animation Horizontal Spacial Scope

      FWRITE(Wrestler[id].col_typ[i], fp);      //	Object Collision Type
      FWRITE(GameObject[id].obj_ax1[0][i], fp); // Object Attack X 1, offset from hotspot
      FWRITE(GameObject[id].obj_ax2[0][i], fp); // Object Attack X 2, offset from hotspot

      // Layer
      FWRITE(Wrestler[id].lyr_frm[0][i], fp);   //	Layer Animation GFX Frame to Display
      FWRITE(Wrestler[id].lyr_ofx[0][i], fp);   //	Object Animation GFX X-Offset
      FWRITE(Wrestler[id].lyr_ofy[0][i], fp);   //	Object Animation GFX Y-Offset
      FWRITE(Wrestler[id].lyr_trx[0][i], fp);   //	Layer X Movement (Tween) Tempoary Offset
      FWRITE(Wrestler[id].lyr_try[0][i], fp);   //	Layer Y Movement (Tween) Tempoary Offset
      //
   }
   fclose(fp);
   //

   return 0;
}

