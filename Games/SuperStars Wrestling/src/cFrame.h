/* //////////////////////////////////////////////////////////////////////
 Program Name:  cFrame.h
 Programmer:    Joseph E. Sutton
 Start Date:    2006-06-15
 Updated:       
 Version:       1.00
 Description:
   Animation Frame Class Header File
   
////////////////////////////////////////////////////////////////////// */
#ifndef __FRAME__
#define __FRAME__

typedef struct _sAction {
   Int32 x1;
   Int32 x2;
} sAction;

class cFrame
{
   public:
      ImgData *img; // NEED DELETE

      uInt32 w;
      uInt32 h;

      //
      Int32 state;
      Int32 attack;

      Int32 frm;     //	Object Animation GFX Frame to Display

	   Int32 mvx;     //	Object X Movement (Tween) Permanent
	   Int32 mvy;     //	Object Y Movement (Tween) Tempoary Offset
	   Int32 mvz;     //	Object Y Movement (Tween) Permanent
	   Int32 ofx;     //	Object Animation GFX X-Offset
	   Int32 ofy;     //	Object Animation GFX Y-Offset

	   Int32 scp;	   //	Object Animation Horizontal Spacial Scope

      Int32 col_type; // Collision Type
      uInt8    nap;   // number of action points
      sAction *ap;    // action point list

      // Layer
	   Int32 lyr_frm;	//	Layer Animation GFX Frame to Display
	   Int32 lyr_ofx;	//	Layer GFX X-Offset
	   Int32 lyr_ofy;	//	Layer GFX Y-Offset
      Int32 lyr_mvx;	//	Layer X Movement (Tween) Permanent
	   Int32 lyr_mvy;	//	Layer Y Movement (Tween) Permanent
      //
      
      cFrame();
      ~cFrame();

      // all in one image
      int Load(cTextFileReader *tfr, ImgData *src, uInt32 x_img_offset, uInt32 y_img_offset);

      // multi image
      int Load(const char *filename);
      //int Load(cTextFileReader *tfr, uInt8 type, cFrame *src = NULL);

      // multi file load
      int Load(cTextFileReader *tfr);

      // load from source to make mirror
      int MakeMirror(cFrame *src, uInt32 last_frame, uInt32 last_layer = 0);

   private:

};

#endif // __FRAME__
