/* //////////////////////////////////////////////////////////////////////
 Program Name:  cGfxObj.h
 Programmer:    Joseph E. Sutton
 Start Date:    2006-06-15
 Updated:       
 Version:       1.00
 Description:
   Basic Gfx Class Header File
   TODO, move all collison stuff to cSprite
   
////////////////////////////////////////////////////////////////////// */
#ifndef __GFX_OBJ__
#define __GFX_OBJ__

enum { OBJTYPE_GFX = 0, 
       OBJTYPE_IMAGE, 
       OBJTYPE_SPRITE
     };

class cGfxObj
{
   friend class cGfxNode;
   friend class cPlayerNode;

   public:
      cGfxObj();
      cGfxObj(const cGfxObj &src); // copy constructor
      ~cGfxObj();

      bool  show;
    
      Int32 xhot;
      Int32 yhot;

      Int32 scope;

      bool alpha_on;
      uInt8 opacity; // opacity level, only if alpha_on
                     // 0   - clear
                     // 255 - solid

      virtual Int32 GetW(); // width
      virtual Int32 GetH(); // height

      virtual Int32 GetX();
      virtual Int32 GetY();
      virtual Int32 GetZ();
      virtual void SetX(Int32 x);
      virtual void SetY(Int32 y);
      virtual void SetZ(Int32 z);

      virtual void SetXZ(Int32 x, Int32 z);
      virtual void SetXY(Int32 x, Int32 y);

      virtual void Show();
      virtual void Hide();

      virtual void        SetName(const char *name);
      virtual const char *GetName();

      virtual int Draw(ImgData *out, Int32 offset_x = 0, Int32 offset_y = 0);

      virtual void Step(); // step animation

   protected:
      Int32 xpos;
      Int32 ypos;
      Int32 zpos;

      uInt8   m_type; // object type

      char    m_name[128];
      cFrame *m_cframe;     
};

#endif // __GFX_OBJ__
