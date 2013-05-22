/* //////////////////////////////////////////////////////////////////////
 Program Name:  cFontMngr.h
 Programmer:    Joseph E. Sutton
 Start Date:    2006-08-03
 Updated:       
 Version:       1.00
 Description:
   Font Manager Class Header File
   
////////////////////////////////////////////////////////////////////// */
#ifndef __FONT_MNGR__
#define __FONT_MNGR__

#define TEST_STR "1234567890ABCDEFGHIJKLMNOPQRSTUVWXYZ abcdefghijklmnopqrstuvwxyz_!@#$%^&*()_+|{}:\"<>?-=\\[];',./"

enum { TEXT_LEFT = 0,
       TEXT_CENTER,
       TEXT_RIGHT
     };

enum { TEXT_TOP = 0,
       TEXT_MIDDLE,
       TEXT_BOTTOM
     };


typedef struct _sText{
   uInt8      str_len;
   const char *str;

   uInt16    font_index;
   
   uInt8     h_align;    // horz, 0=left, 1=center, 2=right
   uInt8     v_align;    // vert, 0=top,  1=middle, 2=bottom

   uInt8     h_padding;  // padding after each charafter each char
   uInt8     v_padding;  // padding between each line
} sTextInfo;


typedef struct _sFont{
   ImgData  *error_char_img;

   uInt32    list_size;
   ImgData **img_list;
} sFont;


class cFontMngr
{
   public:
      cFontMngr();
      ~cFontMngr();

      int  Init(); // should only done once
      void FreeAll();

      int Draw(ImgData *out, const sTextInfo &text_info);

      int CompileFontDir(const char *dir);

   private:
      uInt16 m_size;
      sFont *m_list;

      int LoadFont(uInt16 font_index);
};

#endif // __FONT_MNGR__
