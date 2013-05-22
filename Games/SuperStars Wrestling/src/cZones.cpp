/* //////////////////////////////////////////////////////////////////////
 Program Name:  cZones.cpp
 Programmer:    Joseph E. Sutton
 Start Date:    2006-08-07
 Updated:       
 Version:       1.00
 Description:
   Zones Class Source File
   
////////////////////////////////////////////////////////////////////// */

#include "main.h"

///////////////////////////////////////////////////////
cZones::cZones()
{
   show_zone = 0;

   m_size = 0;
   m_list = NULL;

   m_pmngr = NULL;

   m_layers = NULL;
}


cZones::~cZones()
{
   FreeAll();
}


void cZones::FreeAll()
{
   if(m_list != NULL)
   {
      uInt16 i;
      for(i = 0; i < m_size; ++i)
      {
         m_list[i].num = 0;
         DELETE_A(m_list[i].lines);
      }

      DELETE_A(m_list);
      DELETE_A(m_layers);
      m_size = 0;
   }
}


// <num zones>
// 
// <zone name>
// <num theshold lines>
// [line]
//   <x1> <y1> <x2> <y2>
//   <good side 0=left/up 1=right/down> <threshold value 0=never cross>
//   <if cross line, enter what zone, by name>
// ...
//
// <next zone name>
// ...
int cZones::Load(const char *filename)
{
   uInt16 i, j, ti;
   sZone *tzone;
   sZoneLine *tline;

   cTextFileReader tr;
   tr.Load(filename);

   //
   tr.ReadInt(m_size);
   
   m_layers = new cLayer[m_size];
   m_list = new sZone[m_size];
   memset(m_list, 0, m_size*sizeof(sZone));

   for(i = 0; i < m_size; ++i)
   {
      tzone = &(m_list[i]);

      //
      tr.ReadString(tzone->name);
      tr.ReadInt(tzone->num);

      tzone->lines = new sZoneLine[ tzone->num ];
      memset(tzone->lines, 0, (tzone->num)*sizeof(sZoneLine));

      for(j = 0; j < tzone->num; ++j)
      {
         tline = &(tzone->lines[j]);

         //
         tr.ReadInt(tline->x1);
         tr.ReadInt(tline->y1);
         tr.ReadInt(tline->x2);
         tr.ReadInt(tline->y2);

         if(tline->x1 == tline->x2)
         {
            tline->vert = true;
            tline->m = 0;
            tline->b = tline->x1;
         } else {
            tline->vert = false;
            tline->m = ((float)(tline->y2 - tline->y1))/
                ((float)(tline->x2 - tline->x1));
            tline->b = ((float)tline->y1) - tline->m*((float)tline->x1);
         }

         tr.ReadInt(ti);
         tline->is_greater = (ti > 0);

         //
         tr.ReadInt(tline->threshold);
         
         //
         if(tline->threshold > 0) {
            tr.ReadString(tline->jumpto);
         }
      } // end line loop
   } // end zon loop

   return 0;
}


cLayer *cZones::GetLayer(uInt16 num)
{
   if(num < m_size)
   {
      return &(m_layers[num]);
   }
   
   return NULL;
}


void cZones::DrawLines(ImgData *out)
{
   uInt16 j;
   sZone *tzone;
   sZoneLine *tline;

   // error
   if(show_zone > m_size) return;

   tzone = &(m_list[show_zone]);

   for(j = 0; j < tzone->num; ++j)
   {
      tline = &(tzone->lines[j]);

      line(out, tline->x1, tline->y1, tline->x2, tline->y2, makecol(255,  0,  j*40));
   }
}


int cZones::CheckZones(cZoneInfo *info)
{
   int e;
   info->m_pressing_line = false;
   info->m_zone_changed  = false;

   // not colliable
   if(!info->m_is_colliable) return 0;


   // check pos
   e = CheckPointInZones(*(info->xpos), *(info->ypos), info);
   if(e) return e;

   // now check scope point
   Int32 tx, ty;
   tx = *(info->xpos) + *(info->scope);
   ty = *(info->ypos);

   e = CheckPointInZones(tx, ty, info);
   if(e) return e;

   // TODO fix prob
   *(info->xpos) += tx - (*(info->xpos) + *(info->scope));
   *(info->ypos) += ty - *(info->ypos);

   // if didn't press any line
   if(!info->m_pressing_line)
   {
      // reset
      info->m_cline = -1;
      info->m_threshold = 100;
   }

   return 0;
}

int cZones::CheckPointInZones(Int32 &xpos, Int32 &ypos, cZoneInfo *info)
{
   uInt16 i;
   sZone *tzone;
   sZoneLine *tline;
   Int32 x, y;
   bool over_line;

   x = xpos;
   y = ypos;

   if(info->m_czone > m_size) return 1;

   info->m_zone_changed = false;
   tzone = &(m_list[info->m_czone]);
   for(i = 0; i < tzone->num; ++i)
   {
      // done with reading of this zone
      if(info->m_zone_changed) return 0;

      over_line = false;
      tline = &(tzone->lines[i]);

      // test if went over line
      if(tline->vert) {
         // vertical line
         if(tline->is_greater) {
            if(tline->b > x)
               over_line = true;
         } else {
            if(tline->b < x)
               over_line = true;
         }
      } else {

         if(tline->is_greater) {
            if(y < (tline->m*x + tline->b) )
               over_line = true;
         } else {
            if(y > (tline->m*x + tline->b) )
               over_line = true;
         }
      }

      if(over_line) {
         over_line = FindIntersection(tline, x, y);
      }

      // one of the condistions went over THIS line
      if(over_line)
      {
         info->m_pressing_line = true;

         if(tline->threshold == 1) // walk over line
         {
            info->m_zone_changed = true;
            info->m_pzone = info->m_czone;
            info->m_czone = FindZone(tline->jumpto);
            continue;
         }
         else
         if(tline->threshold != 0) // line breakable
         {
            // pressing same line
            if(i == info->m_cline)
            {
               if(info->m_threshold > 0) {
                  --info->m_threshold; // decrease threshold by one
               }
            
               // break line
               if(info->m_threshold == 0) {
                  info->m_zone_changed = true;
                  info->m_pzone = info->m_czone;
                  info->m_czone = FindZone(tline->jumpto);
                  continue;
               }
            } else {
               info->m_cline = i;
               info->m_threshold = tline->threshold;
            }
         }

         xpos = x;
         ypos = y;
      } //

   } // end line loop

   return 0;
}

// 
bool cZones::FindIntersection(sZoneLine *line, Int32 &x, Int32 &y)
{
   Int32 ix, iy;

   if(line->vert)
   {
      iy = y;
      ix = line->b;
   } else {
      // y = mx + b
      if(line->m != 0)
      {
         iy = y;
         ix = (iy - line->b)/(line->m);
      } else {
         // m = 0
         ix = x;
         iy = line->b;
      }
   }
  
   // only if intersection point is between points
   if( ((ix >= line->x1) && (ix <= line->x2)) || ((ix <= line->x1) && (ix >= line->x2)) )
   {
      if( ((iy >= line->y1) && (iy <= line->y2)) || ((iy <= line->y1) && (iy >= line->y2)) ) 
      {
         if(line->vert)
         {

         } else {
            if(line->m != 0)
            {
               if(line->is_greater) ++ix;
               else                 --ix;
            } else {
               if(line->is_greater) ++iy;
               else                 --iy;
            }
         }

         x = ix;
         y = iy;
         return true;
      }
   }


   return false;
}


uInt16 cZones::FindZone(const char *name)
{
   uInt16 i;
   if(name == NULL) return -1;
   
   for(i = 0; i < m_size; ++i)
   {
      if(strcmp(m_list[i].name, name) == 0) {
         return i;
      }
   }

   return -1;
}

void cZones::SetPlayerMngr(cPlayerMngr *p)
{
   m_pmngr = p;
}


void cZones::CheckZones()
{
   if(m_pmngr != NULL)
   {
      cPlayer *obj;

      // walk linked list
      obj = m_pmngr->StartWalk();
      while(obj != NULL)
      {
         CheckZones( obj->m_zone_info );

         obj = m_pmngr->NextWalk();
      } //
   } //
}


void cZones::UpdateZOrder()
{
   if(m_pmngr != NULL)
   {
      // release all in list
      uInt16 i;
      for(i = 0; i < m_size; ++i)
      {
         m_layers[i].ClearList();
      }
      //

      cPlayer     *obj;
      uInt16       zn;

      // walk linked list
      obj = m_pmngr->StartWalk();
      while(obj != NULL)
      {
         zn = obj->m_zone_info->m_czone;
         m_layers[zn].Add(obj);

         obj = m_pmngr->NextWalk();
      } //
   } //
}
