/* //////////////////////////////////////////////////////////////////////
 Program Name:  cWrestler.h
 Programmer:    Joseph E. Sutton
 Start Date:    2006-07-15
 Updated:       
 Version:       1.00
 Description:
   Generic Wrestler Class Header File
   this is a storage place for all the styles gfx animation
   and wrestler info
   
////////////////////////////////////////////////////////////////////// */
#ifndef __WRESTLER__
#define __WRESTLER__

enum {
   WSIZE_SMALL = 0,
   WSIZE_MEDIUM,
   WSIZE_LARGE,
   WSIZE_GIANT
};

typedef struct _sStyle {
   uInt16   nframes;
   ImgData **frames;

   uInt16   nimgs;
   ImgData **imgs;

   uInt16   nlayers;
   ImgData **layers;
} sStyle;

class cWrestler : public cSprite
{
   public:
      cWrestler();
      cWrestler(const cWrestler &src);
      ~cWrestler();

      int  Load(const char *filename, cBaseWrestler *base);
      void SelectStyle(uInt8 s);

      // info
      uInt8  m_size;  // WSIZE_SMALL, ...
      char   m_sname[16]; // short name, ei. HOGAN
      char   m_mname[32]; // mid   name, ei. HULK HOGAN
      char   m_lname[64]; // long  name, ei. "THE IMMORTAL' HULK HOGAN
      char   m_tname[64]; // team  name, ei. MEGA POWERS

      uInt8 m_speed_walk; // walking speed
      uInt8 m_speed_run;  // running speed
      uInt8 m_speed_lock; // side headlock speed
      //

      ImgData *m_face;    // DON'T DELETE

      void DrawFrame(ImgData *out, Int32 offset_x = 0, Int32 offset_y = 0);
      void DrawLayer(ImgData *out, Int32 offset_x = 0, Int32 offset_y = 0);

   protected:     
      uInt8   m_nstyle; // max number of styles
      uInt8   m_cstyle; // current wrestler look style
      sStyle *m_style;  // NEED TO DELETE, one for each style

      ImgData *m_null_img;  // NEED TO DELETE
      ImgData *m_empty_img; // NEED TO DELETE

      /*
      cAnim *m_anim_list; // one for each style

      ImgData **m_face_list;   // NEED TO DELETE, one for each style

      uInt16  m_num_images;
      ImgData **m_images_list; // NEED TO DELETE, one for each style

      uInt16  m_num_layers;
      ImgData **m_layer_list;  // NEED TO DELETE, one for each style
      */
};

#endif // __WRESTLER__
