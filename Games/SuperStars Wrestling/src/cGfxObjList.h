/* //////////////////////////////////////////////////////////////////////
 Program Name:  cGfxObjList.h
 Programmer:    Joseph E. Sutton
 Start Date:    2006-15-06
 Updated:       
 Version:       1.00
 Description:
   Graphics Object List Class Header File
   
////////////////////////////////////////////////////////////////////// */
#ifndef __GFX_OBJ_LIST__
#define __GFX_OBJ_LIST__


class cGfxNode
{
   public:
      cGfxNode(const char name[128] = "");
      ~cGfxNode();

      bool operator ==(const cGfxNode &src) const; // for search
      bool operator  >(const cGfxNode &src) const; // for search
      bool operator  <(const cGfxNode &src) const; // for search

      int Load(const char *filename);

      cGfxObj *GetGfxObj();

   private:
      char m_name[128];

      uInt8 m_type;
      union {
         cGfxObj *m_gfx;
         cImage  *m_img;
         cSprite *m_spr;
      };
};


class cGfxObjList
{
   public:
      cGfxObjList();
      ~cGfxObjList();

      void Clear();

      int AddImg(const char *tagname, const char *filename);
      //int AddDir(const char *dir);

      cGfxObj *Find(const char *name);


   private:
      cSTree<cGfxNode> m_list;

};


#endif // __GFX_OBJ_LIST__
