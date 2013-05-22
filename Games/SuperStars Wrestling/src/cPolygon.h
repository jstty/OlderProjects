/* //////////////////////////////////////////////////////////////////////
 Program Name:  cPolygon.h
 Programmer:    Joseph E. Sutton
 Start Date:    2006-07-15
 Updated:       
 Version:       1.00
 Description:
   Collison Polygon Class Header File
   
////////////////////////////////////////////////////////////////////// */
#ifndef __POLYGON__
#define __POLYGON__

class cGfxObj;


// colinfo types
enum { COLINFO_ZONE = 0,
       COLINFO_GO_ACTION,
       COLINFO_GO_COL
      }; 

typedef struct _sColInfo
{
   uInt32 id;
   uInt16 type;
   void   *data;
} sColInfo;


typedef struct _sPoly
{
   uInt8   size; // number of points
   sPoint *p;
} sPoly;


class cMultiPoly
{
   public:
      cMultiPoly();
      ~cMultiPoly();

      // load function
      int Load(FILE *fp);
      int Load(const char *filename);

      //int  AddGfxObj(cGfxObj *obj);
      //void CheckGfxObj(cGfxObj *src);

   private:
      uInt8     m_psize; // number of polygons
      sPoly    *m_poly;

      // should be in linked list
      //uInt8     m_gosize;
      //cGfxObj **m_gfxobj; // list of cGfxObj Points, DELETE list only, DON'T DELETE cGfxObj pointer

      bool CheckPoly(const sPoly *poly, Int32 x, Int32 y);
      bool CheckRect(sPoint p[4], Int32 x, Int32 y);
};


#endif // __POLYGON__

