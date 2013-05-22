/* //////////////////////////////////////////////////////////////////////
 Program Name:  cZoneInfo.h
 Programmer:    Joseph E. Sutton
 Start Date:    2006-08-07
 Updated:       
 Version:       1.00
 Description:
   ZoneInfo Class Header File
   
////////////////////////////////////////////////////////////////////// */
#ifndef __ZONE_INFO__
#define __ZONE_INFO__


// per player has this zone info class
class cZoneInfo
{
   friend class cZones;  // allows cZones to change private info
   
   public:
      cZoneInfo() : m_pzone(0), m_czone(0) {}

      bool PosChanged() { return m_pos_changed; }
      bool ZoneChanged(){ return m_zone_changed; }

      uInt16 GetPrevZone(){ return m_pzone; }
      uInt16 GetZone()    { return m_czone; }
      void SetZone(uInt16 z)
      {
         m_pzone = m_czone;
         m_czone = z;
      }

      bool   PressingLine(){ return m_pressing_line; }
      uInt16 GetLine()     { return m_cline; }

      Int32  *xpos;    // current pos
      Int32  *ypos;    // current pos
      Int32  *scope;   // horz scope

      //
      bool   m_is_colliable;

      bool   m_zone_changed;
      uInt16 m_pzone; // previous zone
      uInt16 m_czone; // current  zone

      Int32  m_pxpos; // previous pos
      Int32  m_pypos; // previous pos

      //
      bool   m_pressing_line; //
      uInt16 m_cline; // current line pressing
      uInt16 m_threshold;
      
      bool m_pos_changed;
};


#endif // __ZONE_INFO__
