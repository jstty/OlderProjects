/* //////////////////////////////////////////////////////////////////////
 Program Name:  cGfxText.h
 Programmer:    Joseph E. Sutton
 Start Date:    2006-06-29
 Updated:       
 Version:       1.00
 Description:
   Basic Graphical Text Class Source File
   uses a font
   
////////////////////////////////////////////////////////////////////// */
#ifndef __GFX_TEXT__
#define __GFX_TEXT__

class cGfxText : public cGfxObj
{
   public:
      cGfxText();
      ~cGfxText();

      void SetSize(uInt32 w, uInt32 h);
    
      void SetAlign(uInt8 h = TEXT_LEFT, uInt8 v = TEXT_TOP);
      void SetCharPadding(uInt8 hp, uInt8 vp);

      void SetFontIndex(uInt16 font_index);

      void SetString(const char *str);

      void Update(); // call to update img

   protected:
      char      m_str[256];

      uInt32    m_width;
      uInt32    m_height;

      sTextInfo m_info;
};

#endif // __GFX_TEXT__