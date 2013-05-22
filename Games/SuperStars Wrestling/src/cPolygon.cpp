/* //////////////////////////////////////////////////////////////////////
 Program Name:  cPolygon.cpp
 Programmer:    Joseph E. Sutton
 Start Date:    2006-07-15
 Updated:       
 Version:       1.00
 Description:
   Collison Polygon Class Source File
   
////////////////////////////////////////////////////////////////////// */

#include "main.h"

cMultiPoly::cMultiPoly()
{
   m_psize = 0;
   m_poly = NULL;


//   m_gosize = 0;
//   m_gfxobj = NULL;
}

cMultiPoly::~cMultiPoly()
{
   if(m_poly != NULL)
   {
      uInt8 i;
      for(i = 0; i < m_psize; ++i)
      {
         if(m_poly[i].p != NULL){
            delete [] m_poly[i].p;
            m_poly[i].p = NULL;
         }

         m_poly[i].size = 0;
      }

      delete [] m_poly;
      m_poly = NULL;
      m_psize = 0;
   }
}

// loads file then calls Load with file pointer
int cMultiPoly::Load(const char *filename)
{
   int e = 0;
   FILE *fp;

   fp = fopen(filename, "r+");
   if(fp == NULL) {
      return 1; // error, could not load file
   }

   e = Load(fp);
   fclose(fp);

   return e;
}

// <number of poly's>
// [poly 0]
// <number of points in poly>
// <x> <y>
// ...
// 
// [poly 1]
// ...
// 
int cMultiPoly::Load(FILE *fp)
{
   // load polygon list of polygons with points
   if(fp == NULL) return 2;

   Int32 e = 0;
   uInt32 i, j;
   
   fscanf(fp, "%d", &m_psize);
   m_poly = new sPoly[m_psize];
   for(i = 0; i < m_psize; ++i)
   {
      fscanf(fp, "%d", &(m_poly[i].size));
      m_poly[i].p = new sPoint[ m_poly[i].size ];
      for(j = 0; j < m_poly[i].size; ++j)
      {
         fscanf(fp, "%d", &(m_poly[i].p[j].x));
         fscanf(fp, "%d", &(m_poly[i].p[j].y));
      }
   }

   return e;
}

/*
void cMultiPoly::CheckGfxObj(cGfxObj *src)
{
   uInt8 i;

   src->ResetColInfo();

   if(m_poly != NULL) {
      for(i = 0; i < m_psize; ++i)
      {
         if( CheckPoly( &(m_poly[i]), src->xhot, src->yhot) ) {
            // collide with zone
            src->AddColInfo(i, COLINFO_ZONE, NULL);
         }
      }
   }

   if(m_gfxobj != NULL) {
      sPoly tmp;
      for(i = 0; i < m_gosize; ++i)
      {
         // not same as source
         // and colliable
         if( (src != m_gfxobj[i]) &&
             (m_gfxobj[i]->IsCollidable())
           )
         {
            tmp.size = 4;

            // action
            tmp.p = m_gfxobj[i]->GetColPoints(ZONE_ACTION);
            if( CheckPoly(&tmp, src->xhot, src->yhot) ) {
               // action hit
               src->AddColInfo(i, COLINFO_GO_ACTION, m_gfxobj[i]);
            }

            // collision
            tmp.p = m_gfxobj[i]->GetColPoints(ZONE_COL);
            if( CheckPoly(&tmp, src->xhot, src->yhot) ) {
               // collide
               src->AddColInfo(i, COLINFO_GO_COL, m_gfxobj[i]);
            }

         }
      }
   }
}
*/


/*
int pnpoly(int npol, float *xp, float *yp, float x, float y)
{
   int i, j, c = 0;
   for(i = 0, j = npol-1; i < npol; j = i++) {
      if( ( 
           ( (yp[i] <= y) && (y < yp[j]) ) || ( (yp[j] <= y) && (y < yp[i]) )
          )
          &&
          ( x < (xp[j] - xp[i]) * (y - yp[i]) / (yp[j] - yp[i]) + xp[i] )
        )
        c = !c;
   }

   return c;
}
*/
bool cMultiPoly::CheckPoly(const sPoly *poly, Int32 x, Int32 y)
{
   if(poly == NULL) return false;

   uInt8 i, j;
   bool f;
   f = false;

   j = poly->size - 1;
   for(i = 0; i < poly->size; j = i++)
   {
      if( ( 
            ( (poly->p[i].y <= y) && (y < poly->p[j].y) ) ||
            ( (poly->p[j].y <= y) && (y < poly->p[i].y) )
          )
          &&
          ( x < (poly->p[j].x - poly->p[i].x) *
                (y - poly->p[i].y) /
                (poly->p[j].y - poly->p[i].y) +
                poly->p[i].x )
        )
        f = !f;
   }

   return f;
}

//