/* //////////////////////////////////////////////////////////////////////
 Program Name:  cGfxNode.h
 Programmer:    Joseph E. Sutton
 Start Date:    2006-06-22
 Updated:       
 Version:       1.00
 Description:
   Graphics Node Class Header File
   
////////////////////////////////////////////////////////////////////// */
#ifndef __GFX_NODE__
#define __GFX_NODE__

class cGfxNode
{
   public:
      cGfxNode(const char name[128] = "");
      cGfxNode(const char name[128], cGfxObj *gfx);
      cGfxNode(const char name[128], cImage  *img);
      cGfxNode(const char name[128], cSprite *sprite);
      ~cGfxNode();

      bool operator ==(cGfxNode &src); // for sort
      bool operator !=(cGfxNode &src); // for sort
      bool operator  >(const cGfxNode &src); // for sort
      bool operator  <(const cGfxNode &src); // for sort

      uInt8    GetType();
      cGfxObj *GetGfxObj();
      cImage  *GetImage();  // type 1
      cSprite *GetSprite(); // type 2

   private:
      char   m_name[128];

      uInt8  m_type;
      union {
         cGfxObj *m_gfx;
         cImage  *m_img; // type 1
         cSprite *m_spr; // type 2
      };
};


#endif // __GFX_NODE__
