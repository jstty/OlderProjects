/* //////////////////////////////////////////////////////////////////////
 Program Name:  cPlayer.h
 Programmer:    Joseph E. Sutton
 Start Date:    2006-07-15
 Updated:       
 Version:       1.00
 Description:
   Generic Player Class Header File
   
////////////////////////////////////////////////////////////////////// */
#ifndef __PLAYER__
#define __PLAYER__

enum {
   PMAJ_NULL = 0,
   PMAJ_MOVE,
   PMAJ_ATTACK,
   PMAJ_HIT
};

enum {
   PMIN_NULL = 0,

   PMIN_STANDING,
   PMIN_WALKING,
   PMIN_RUNNING,
};

class cPlayer : public cGfxObj {
   public:
      cPlayer();
      ~cPlayer();

      void SetWrestler(cWrestler *w);

      virtual int Draw(ImgData *out, Int32 offset_x = 0, Int32 offset_y = 0);
      void DrawSlave(ImgData *out);
      void DrawOverLayer(ImgData *out);

      void SetAsSlave(bool s = true);
      void AttachSlave(cPlayer *slave);
      void AttachSlaveOverlay(cPlayer *slave);

      void AttachTarget(cPlayer *target);
      void AttachInput(bool *c);

      void PreUpdate();
      void PostUpdate();

      void Stand(); 

      void SetDrawOrder(uInt8 dorder);

      void SetZoneInfo(cZoneInfo *z);

      JSObject *GetSlaveJSObject();
      JSObject *GetTargetJSObject();

      Int32 GetAttack();
      Int32 GetColType();

      Int32 GetState();
      void SetState(Int32 s);

      virtual void Step(); // step animation

      /*
      void ProcessInput();
      void ProcessState();
      void ProcessCollision();
      void UpdateFocus();
      void Walk(); 
      */
      
      //
      JSObject *m_js_object; // DON'T DELETE

      //
      bool *m_control;
      bool  m_is_slave; // this wrestler is a slave of another wrestler

      //
      cWrestler *m_self;     // NEED TO DELETE
      Int8   m_hp;     // (-10) to 100
      Int8   m_hp_max; // 100

      Int16  m_stamina;     // 
      Int16  m_stamina_max; // 

      uInt8  m_superstars; // 0 to 9
      uInt8  m_combo_pts;  // 0 to 3

      bool m_fdir_lr; // facing direction left(0)/right(1)
      bool m_fdir_ud; // facing direction up(0)/down(1)

      //
      uInt16 m_state;

      cPlayer   *m_target;     // DON'T DELETE

      // prev
      uInt16 m_prev_state;
      bool   m_prev_fdir_lr;
      bool   m_prev_fdir_ud;

      
      cZoneInfo *m_zone_info; // DON'T DELETE

      uInt8 m_draw_order;

      /////////////////////////////////////////////////////////
      // Base gfx Class override
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
      /////////////////////////////////////////////////////////

   protected:
      cPlayer   *m_slave;      // DON'T DELETE

      //
      cImage    *m_over_layer; // DON'T DELETE
      cPlayer   *m_over_slave; // DON'T DELETE

};

#endif // __PLAYER__
