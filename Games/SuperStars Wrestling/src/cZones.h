/* //////////////////////////////////////////////////////////////////////
 Program Name:  cZones.h
 Programmer:    Joseph E. Sutton
 Start Date:    2006-08-07
 Updated:       
 Version:       1.00
 Description:
   Zones Class Header File
   
////////////////////////////////////////////////////////////////////// */
#ifndef __ZONES__
#define __ZONES__

//
typedef struct _sZoneLine
{
   Int32 x1, y1;
   Int32 x2, y2;

   uInt16 threshold;  // at what point the lines breaks
   char   jumpto[32]; // zone to jump to when line breaks

   bool is_greater; // if true, y > m*x + b
                    // else     y < m*x + b

   // if true, eq. "x = b"
   bool  vert; // vert = (x1 == x2), b = x1

   // if false, eq. "y = m*x + b", "x = (y - b)/m"
   float m; // m = ((float)(y2 - y1))/((float)(x2 - x1))
   float b; // b = y1 - m*x1

} sZoneLine;


typedef struct _sZone
{
   char name[32];

   uInt16     num;
   sZoneLine *lines;

} sZone;


//
class cZones
{
   public:
      cZones();
      ~cZones();

      uInt8 show_zone;

      int Load(const char *filename);

      int CheckZones(cZoneInfo *info);
      void DrawLines(ImgData *out);

      cLayer *GetLayer(uInt16 num);
      void CheckZones();

      void UpdateZOrder();

      void SetPlayerMngr(cPlayerMngr *p);

   protected:
      uInt16   m_size;
      sZone   *m_list;   // NEED TO DELETE
      cLayer  *m_layers; // NEED TO DELETE

      cPlayerMngr *m_pmngr;

      // find zone index from name
      uInt16 FindZone(const char *name);

      bool FindIntersection(sZoneLine *line, Int32 &x, Int32 &y);
      int CheckPointInZones(Int32 &xpos, Int32 &ypos, cZoneInfo *info);

      void FreeAll();
};

#endif // __ZONES__
