/* //////////////////////////////////////////////////////////////////////
 Program Name:  cBaseWrestler.h
 Programmer:    Joseph E. Sutton
 Start Date:    2006-08-16
 Updated:       
 Version:       1.00
 Description:
   Base Wrestler Data Class Header File
   
   
////////////////////////////////////////////////////////////////////// */
#ifndef __BASE_WRESTLER__
#define __BASE_WRESTLER__

class cBaseWrestler
{
   public:
      cBaseWrestler();
      ~cBaseWrestler();

      int  Load(const char *filename);

      uInt16 nframes;
      uInt16 nlayers;
      uInt16 nimgs;

      char *frame_str;
      char *img_str;
      char *layer_str;
      char *base_str;

      cAnim *anim;

   protected:

};

#endif // __BASE_WRESTLER__
