/* //////////////////////////////////////////////////////////////////////
 Program Name:  cPlayer.cpp
 Programmer:    Joseph E. Sutton
 Start Date:    2006-07-22
 Updated:       
 Version:       1.00
 Description:
   Generic Player Class Header File
   
////////////////////////////////////////////////////////////////////// */

#include "main.h"

cPlayer::cPlayer()
{
   cGfxObj();
   m_is_slave = false;
   m_self = NULL;

   m_state = 0;

   m_hp      = 80;
   m_hp_max  = 100;

   m_stamina     = 100;
   m_stamina_max = 1000;

   m_superstars = 0;
   m_combo_pts  = 0;

   m_target = NULL;

   m_slave = NULL;
   m_over_layer = NULL;

   m_fdir_lr = false;
   m_fdir_ud = false;

   m_zone_info = NULL;
   m_draw_order = 0;
}

cPlayer::~cPlayer()
{
   DELETE(m_self);
}


void cPlayer::AttachInput(bool *c)
{
   m_control = c;
}


// before collision detection
void cPlayer::PreUpdate()
{

}


// after collision detection
void cPlayer::PostUpdate()
{
   // update self, after zone collision
   // because zone collision could have adjusted the x/z pos
   if(m_self != NULL) m_self->SetXZ(xpos, zpos);
}


/////////////////////////////////////////////////////

void cPlayer::SetZoneInfo(cZoneInfo *z)
{
   if(z != NULL)
   {
      m_zone_info = z;
      m_zone_info->SetZone(0);
      m_zone_info->xpos  = &xpos;
      m_zone_info->ypos  = &zpos;
      m_zone_info->scope = NULL;

      if(m_self != NULL) {
         m_zone_info->scope = &(m_self->scope);
      }
   }
}


void cPlayer::SetWrestler(cWrestler *w)
{
   DELETE(m_self);

   m_self = new cWrestler(*w);
   m_self->Show();
   m_zone_info->scope = NULL;
   
   if(m_zone_info != NULL) {
      m_zone_info->scope = &(m_self->scope);
   }
}


void cPlayer::SetAsSlave(bool s)
{
   m_is_slave = s;
}


void cPlayer::AttachSlave(cPlayer *slave)
{
   // set old slave as not slave anymore
   if(m_slave != NULL) {
      m_slave->SetAsSlave(false);
   }

   // set slave pointer
   m_slave = slave;

   // set new slave as slave to self
   if(m_slave != NULL) {
      m_slave->SetAsSlave(true);
   }
}


void cPlayer::AttachTarget(cPlayer *target)
{
   m_target = target;
}


void cPlayer::DrawSlave(ImgData *out)
{
   bool old_is_slave = m_is_slave;
   m_is_slave = false;
   Draw(out);
   m_is_slave = old_is_slave;
}

int cPlayer::Draw(ImgData *out, Int32 offset_x, Int32 offset_y)
{
   if(m_is_slave)     return 0;
   if(m_self == NULL) return 1;

   // draw gfx
   switch(m_draw_order)
   {
      case 0:
         m_self->DrawFrame(out, offset_x, offset_y);
         if(m_slave != NULL) m_slave->DrawSlave(out);
         break;

      case 1:
         m_self->DrawFrame(out, offset_x, offset_y);
         if(m_slave != NULL) m_slave->DrawSlave(out);
         m_self->DrawLayer(out, xpos + offset_x, ypos + offset_y);
         break;

      case 2:
         m_self->DrawLayer(out, xpos + offset_x, ypos + offset_y);
         if(m_slave != NULL) m_slave->DrawSlave(out);
         m_self->DrawFrame(out, offset_x, offset_y);
         break;
   }

//////////////////////////////////////////////////////////////////
#ifdef DEBUG
   // draw attack line
   cFrame *f = m_self->Anim()->GetCurrent();
   if(f != NULL)
   {
      if(f->ap != NULL)
      {
         line(out, 
            f->ap[0].x1 + xpos + offset_x, 
            zpos + offset_y,
            f->ap[0].x2 + xpos + offset_x,
            zpos + offset_y,
            ATTACK_LINE_COLOR);
      }
   }
   //

   // draw scope
   if(game->scopespot != NULL)
   {
      if(m_self->scope != 0)
      {
         masked_blit(game->scopespot, out, 
         0, 0, 
         xpos + m_self->scope + offset_x - game->scopespot->w/2,
         ypos + zpos + offset_y - game->scopespot->h/2, 
         game->scopespot->w, game->scopespot->h 
         );
      }
   }
   //

   // draw hotspot
   if(game->hotspot != NULL)
   {
      masked_blit(game->hotspot, out, 
      0, 0,
      xpos + offset_x - game->hotspot->w/2,
      zpos + offset_y - game->hotspot->h/2, 
      game->hotspot->w, game->hotspot->h 
      );
   }
   //

   /*
   textprintf_ex(out, font, 
         xpos + offset_x, 
         zpos + offset_y, 
         makecol(255, 100, 200), -1, 
         "x: %d  y: %d z: %d", xpos, ypos, m_zone_info->GetZone());
         */
#endif
//////////////////////////////////////////////////////////////////

   return 0;
}


Int32 cPlayer::GetX()
{
   if(m_self != NULL) return m_self->GetX();
   else               return 0;
}

Int32 cPlayer::GetY()
{
   if(m_self != NULL) return m_self->GetY();
   else               return 0;
}

Int32 cPlayer::GetZ()
{
   if(m_self != NULL) return m_self->GetZ();
   else               return 0;
}

void cPlayer::SetX(Int32 x)
{
   xpos = x;
   if(m_self != NULL) m_self->SetX(x);
}

void cPlayer::SetY(Int32 y)
{
   ypos = y;
   if(m_self != NULL) m_self->SetY(y);
}

void cPlayer::SetZ(Int32 z)
{
   zpos = z;
   if(m_self != NULL) m_self->SetZ(z);
}

void cPlayer::SetXZ(Int32 x, Int32 z)
{
   xpos = x;
   zpos = z;
   if(m_self != NULL) m_self->SetXZ(x, z);
}

void cPlayer::SetXY(Int32 x, Int32 y)
{
   xpos = x;
   ypos = y;
   if(m_self != NULL) m_self->SetXY(x, y);
}


Int32 cPlayer::GetW()
{
   if(m_self != NULL) return m_self->GetW();
   else               return 0;
}

Int32 cPlayer::GetH()
{
   if(m_self != NULL) return m_self->GetH();
   else               return 0;
}


JSObject *cPlayer::GetSlaveJSObject()
{
   return m_slave->m_js_object;
}


JSObject *cPlayer::GetTargetJSObject()
{
   return m_target->m_js_object;
}


Int32 cPlayer::GetAttack()
{
   if(m_self != NULL)
   {
      cAnim *a = m_self->Anim();
      if(a != NULL)
      {
         cFrame *f = a->GetCurrent();
         if(f != NULL)
            return f->attack;
      }
   }

   return 0;
}


Int32 cPlayer::GetColType()
{
   if(m_self != NULL)
   {
      cAnim *a = m_self->Anim();
      if(a != NULL)
      {
         cFrame *f = a->GetCurrent();
         if(f != NULL)
            return f->col_type;
      }
   }

   return 0;
}


void cPlayer::Step()
{
   m_self->Step();

   cFrame *f = m_self->Anim()->GetCurrent();
   if(f != NULL) m_state = f->state;
}


Int32 cPlayer::GetState()
{
   return m_state;
   //return m_self->Anim()->GetCurrent()->state;
}

void cPlayer::SetState(Int32 s)
{
   cFrame *f = m_self->Anim()->GetCurrent();

   if(f != NULL) {
      f->state = s;
   }

   m_state = s;
}


/////////////////////////////////////////////////////

/*
//info->p[PL_1]
// update posistion
void cPlayer::ProcessInput()
{
   m_prev_major_state = m_major_state;
   m_prev_minor_state = m_minor_state;
   m_prev_fdir_lr = m_fdir_lr;
   m_prev_fdir_ud = m_fdir_ud;

   if(m_major_state == PMAJ_MOVE)
   {
      m_minor_state = PMIN_STANDING;

      if( m_control[PL_UP] ) {
         m_fdir_ud = false;

         m_minor_state = PMIN_WALKING;
         ypos -= m_self->m_speed_walk;
      } else
      if( m_control[PL_DOWN] ) {
         m_fdir_ud = true;

         m_minor_state = PMIN_WALKING;
         ypos += m_self->m_speed_walk;
      }
      
      if( m_control[PL_LEFT] ) {
         m_fdir_lr = false;

         m_minor_state = PMIN_WALKING;
         xpos -= m_self->m_speed_walk;
      } else
      if( m_control[PL_RIGHT] ) {
         m_fdir_lr = true;

         m_minor_state = PMIN_WALKING;
         xpos += m_self->m_speed_walk;
      }
   }

   UpdateFocus();
   ProcessState();
}

// update animation
void cPlayer::ProcessState()
{
   if(m_major_state == PMAJ_MOVE) {

      if(m_minor_state == PMIN_WALKING)
      {
         if( (m_prev_minor_state != m_minor_state) ||
             (m_prev_fdir_lr != m_fdir_lr) ||
             (m_prev_fdir_ud != m_fdir_ud)
           ) {
            Walk();
         } else {
            m_self->Step();
         }
      } else 
      if(m_minor_state == PMIN_STANDING)
      {
         if( (m_prev_minor_state != m_minor_state) ||
             (m_prev_fdir_lr != m_fdir_lr) ||
             (m_prev_fdir_ud != m_fdir_ud) 
           ) {
            Stand();
         } else {
            //do nothing
         }
      }
   }
}


void cPlayer::UpdateFocus()
{
   if(m_target == NULL) return;

   if(m_major_state == PMAJ_MOVE) {
      if(
         (m_minor_state == PMIN_STANDING) ||
         (m_minor_state == PMIN_WALKING)
        )
      {
         if(xpos < m_target->xpos) {
            m_fdir_lr = true;
         } else {
            m_fdir_lr = false;
         }

         // prejeduce to facing down
         if(ypos < m_target->ypos + 10) {
            m_fdir_ud = true;
         } else {
            m_fdir_ud = false;
         }
      }
   }
}



void cPlayer::Walk()
{
   if(!m_fdir_lr && !m_fdir_ud) {  // up, left
      m_self->AnimSelect("walk_u_l");
   } else 
   if(!m_fdir_lr && m_fdir_ud) {  // down, left
      m_self->AnimSelect("walk_d_l");
   } else 
   if(m_fdir_lr && !m_fdir_ud) {  // up, right
      m_self->AnimSelect("walk_u_r");
   } else 
   if(m_fdir_lr && m_fdir_ud) {  // down, right
      m_self->AnimSelect("walk_d_r");
   }
}

void cPlayer::ProcessCollision()
{
   //
}
*/

/*
void cPlayer::Stand()
{
   if(!m_fdir_lr && !m_fdir_ud) {  // up, left
      m_self->AnimSelect("stand_u_l");
   } else 
   if(!m_fdir_lr && m_fdir_ud) {  // down, left
      m_self->AnimSelect("stand_d_l");
   } else 
   if(m_fdir_lr && !m_fdir_ud) {  // up, right
      m_self->AnimSelect("stand_u_r");
   } else 
   if(m_fdir_lr && m_fdir_ud) {  // down, right
      m_self->AnimSelect("stand_d_r");
   }
}
*/