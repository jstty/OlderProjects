/* //////////////////////////////////////////////////////////////////////
 Program Name:  cSprite.h
 Programmer:    Joseph E. Sutton
 Start Date:    2006-06-15
 Updated:       
 Version:       1.00
 Description:
   Sprite Class Header File
   Sprite can only collide with objects

   Not for use with a single image, or non colliable objects. use cImage
   
////////////////////////////////////////////////////////////////////// */
#ifndef __SPRITE__
#define __SPRITE__

class cColInfoNode
{
   public:
      cColInfoNode();
      cColInfoNode(const sColInfo & ci);
      ~cColInfoNode();

      //bool operator ==(const cLayerNode &src) const;
      //bool operator !=(const cLayerNode &src) const;
      //bool operator  >(const cLayerNode &src) const;
      //bool operator  <(const cLayerNode &src) const;

      sColInfo colinfo;

   private:

};

class cSprite : public cImage
{
   public:
      cSprite();
      ~cSprite();

      //int Load(const char *filename); // loads sprite file, animations, gfx, sound...

      virtual void    Collidable();
      virtual void    NotCollidable();
      virtual bool    IsCollidable();
      virtual sPoint *GetColPoints(uInt8 num);

      virtual void ResetColInfo();
      virtual int  AddColInfo(uInt32 id, uInt16 type, void *data);

   protected:
      //
      bool   m_collidable;

      cLList<cColInfoNode> *m_list;
};

#endif // __SPRITE__
