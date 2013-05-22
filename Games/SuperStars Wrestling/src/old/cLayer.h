/* //////////////////////////////////////////////////////////////////////
 Program Name:  cLayer.h
 Programmer:    Joseph E. Sutton
 Start Date:    2006-06-22
 Updated:       
 Version:       1.00
 Description:
   Layer Class Header File
   
////////////////////////////////////////////////////////////////////// */
#ifndef __LAYER__
#define __LAYER__

typedef struct _sLayerInfo
{
   ImgData *out;

   Int32 offset_x;
   Int32 offset_y;

} sLayerInfo;


template <class Gfx_type> class cLayer
{
   public:
      cLayer();
      ~cLayer();

      void Show();
      void Hide();
      
      // writes layer temp buffer to out
      // go though list of Simple and Advanced Sprites, calling there Draw function
      int Draw(ImgData *out);

      int Add(cSprite *sprite);
      int Add(cImage  *img);
      int Add(cGfxObj *gfx);
      int Add(const char *name, cSprite *sprite);
      int Add(const char *name, cImage  *img);
      int Add(const char *name, cGfxObj *gfx);

      // go though list of Simple and Advanced Sprites, calling there Update function
      // and update fade
      int Update();

      void ShiftX(Int32 pos);
      void ShiftY(Int32 pos);
      void SetXY (Int32 x, Int32 y);  // sets x, y pos
      void SetSize(uInt32 w, uInt32 h, bool use_buffer = false);  // sets width, height

      void SetName(const char *name);
      const char *GetName();

      void FadeIn (uInt8 step, uInt8 min = 0, uInt8 max = 255);
      void FadeOut(uInt8 step, uInt8 min = 0, uInt8 max = 255);
      bool FadeDone();

      void InsertAt(int pos, cGfxObj *obj);
      void ClearList(); // clear list

   private:
      bool     m_show; // visable or not

      char     m_name[128];
      Int32    m_xpos;
      Int32    m_ypos;

      uInt32   m_width;
      uInt32   m_height;

      bool     m_use_fx;
      cFx     *m_fx;

      cSList<Gfx_type> *m_list;

      bool     m_use_buffer;
      ImgData *m_buffer; // layer temp buffer. NEED TO DELETE!

      sLayerInfo m_linfo;

      void UpdateFade();
};


// For MS VC++ 6
#ifdef WIN32
	#include "cLayer.cpp"
#endif
//

#endif // __LAYER__
