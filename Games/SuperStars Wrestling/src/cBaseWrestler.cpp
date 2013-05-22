/* //////////////////////////////////////////////////////////////////////
 Program Name:  cBaseWrestler.cpp
 Programmer:    Joseph E. Sutton
 Start Date:    2006-08-16
 Updated:       
 Version:       1.00
 Description:
   Base Wrestler Data Class Header File
   
////////////////////////////////////////////////////////////////////// */

#include "main.h"

cBaseWrestler::cBaseWrestler()
{
   frame_str = new char[256];
   img_str = new char[256];
   layer_str = new char[256];
   base_str = new char[256];
}

cBaseWrestler::~cBaseWrestler()
{
   DELETE_A(frame_str);
   DELETE_A(img_str);
   DELETE_A(layer_str);
   DELETE_A(base_str);
}


// file struct
// <frame filename format> <number of frames>
// <layer filename format> <number of layers>
// <image filename format> <number of images>
// <face filename format> <number of faces>
// <base anim frame data>
// <seq data>
int cBaseWrestler::Load(const char *path)
{
   int e;
   char s[256];
   cTextFileReader fr;

   sprintf(s, "%sbase.and", path);
   e = fr.Load(s);
   if(e) return e;

   fr.ReadString(frame_str);
   fr.ReadInt(nframes);

   fr.ReadString(layer_str);
   fr.ReadInt(nlayers);

   fr.ReadString(img_str);
   fr.ReadInt(nimgs);

   fr.ReadString(base_str);

   // read seq
   anim = new cAnim();

   sprintf(s, "%s%s", path, base_str);
   anim->LoadFrames(s);
   anim->LoadSeq(&fr, 0, 0);

   return 0;
}



