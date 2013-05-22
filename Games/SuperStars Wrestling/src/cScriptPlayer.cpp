/* //////////////////////////////////////////////////////////////////////
 Program Name:  cScriptPlayer.cpp
 Programmer:    Joseph E. Sutton
 Start Date:    2006-08-05
 Updated:       
 Version:       1.00
 Description:
   JavaScript Wrapper for Player Class Source File
   
////////////////////////////////////////////////////////////////////// */

#include "main.h"

bool cScriptPlayer::js_is_init = false;

JSPropertySpec cScriptPlayer::js_properties[] = 
{
   { "xpos",      xpos_prop,     JSPROP_ENUMERATE },
   { "ypos",      ypos_prop,     JSPROP_ENUMERATE },
   { "zpos",      zpos_prop,     JSPROP_ENUMERATE },

   { "joy_up",    joy_up_prop,     JSPROP_ENUMERATE },
   { "joy_down",  joy_down_prop,   JSPROP_ENUMERATE },
   { "joy_left",  joy_left_prop,   JSPROP_ENUMERATE },
   { "joy_right", joy_right_prop,  JSPROP_ENUMERATE },
   { "joy_b1",    joy_b1_prop,     JSPROP_ENUMERATE },
   { "joy_b2",    joy_b2_prop,     JSPROP_ENUMERATE },
   { "joy_b3",    joy_b3_prop,     JSPROP_ENUMERATE },

   { "is_slave",  is_slave_prop,   JSPROP_ENUMERATE },

   { "walkspeed", walkspeed_prop,  JSPROP_ENUMERATE },
   { "runspeed",  runspeed_prop,   JSPROP_ENUMERATE },
   { "dragspeed", dragspeed_prop,  JSPROP_ENUMERATE },

   { "prev_state", prev_state_prop, JSPROP_ENUMERATE },
   { "prev_hdir",  prev_hdir_prop,  JSPROP_ENUMERATE },
   { "prev_vdir",  prev_vdir_prop,  JSPROP_ENUMERATE },

   { "zone",       zone_prop,       JSPROP_ENUMERATE },
   { "state",      state_prop,      JSPROP_ENUMERATE },
   { "attack",     attack_prop,     JSPROP_ENUMERATE },
   { "col_type",   col_type_prop,   JSPROP_ENUMERATE },

   { "anim",       anim_prop,       JSPROP_ENUMERATE },
   { "anim_done",  anim_done_prop,  JSPROP_ENUMERATE },
   { "frame",      frame_prop,      JSPROP_ENUMERATE },
   { "frame_done", frame_done_prop, JSPROP_ENUMERATE },

   { "hdir",  hdir_prop, JSPROP_ENUMERATE },
   { "vdir",  vdir_prop, JSPROP_ENUMERATE },

   { "target", target_prop, JSPROP_ENUMERATE },
   { "slave",  slave_prop,  JSPROP_ENUMERATE },
   { "col",    col_prop,    JSPROP_ENUMERATE },

   { "hp",          hp_prop,          JSPROP_ENUMERATE },
   { "hp_max",      hp_max_prop,      JSPROP_ENUMERATE },
   { "stamina",     stamina_prop,     JSPROP_ENUMERATE },
   { "stamina_max", stamina_max_prop, JSPROP_ENUMERATE },

   { "ss",    ss_prop,    JSPROP_ENUMERATE },
   { "flags", flags_prop, JSPROP_ENUMERATE },
   
   { "draw_order", draw_order_prop, JSPROP_ENUMERATE }, // [rw]

   { 0 }
};

JSFunctionSpec cScriptPlayer::js_methods[] = 
{
   { "AnimStep",   AnimStep,   1, 0, 0 },
   { "AnimSelect", AnimSelect, 1, 0, 0 },
   { "AnimPlay",   AnimPlay,   1, 0, 0 },
   { "AnimPause",  AnimPause,  1, 0, 0 },
   { 0, 0, 0, 0, 0 }
};

JSClass cScriptPlayer::js_class = 
{ 
   "Player", JSCLASS_HAS_PRIVATE, JS_PropertyStub, JS_PropertyStub,
   cScriptPlayer::js_GetProperty,
   cScriptPlayer::js_SetProperty,
   JS_EnumerateStub, JS_ResolveStub, JS_ConvertStub, 
   cScriptPlayer::js_Destructor
};



cScriptPlayer::cScriptPlayer()
{
   m_cx = NULL;
   m_js_obj = NULL;

   m_zone = NULL;

   m_player = NULL;
}

cScriptPlayer::~cScriptPlayer()
{
   DELETE(m_player);
}

// called on Init to set private cScriptPlayer's player
void cScriptPlayer::SetPlayer(cPlayer* p)
{
   m_player = p;
}

cPlayer* cScriptPlayer::GetPlayer()
{
   return m_player;
}


//
JSBool cScriptPlayer::js_GetProperty(JSContext *cx, JSObject *obj, jsval id, jsval *vp)
{
   if(JSVAL_IS_INT(id))
	{
      char *s;
      JSString *str;

      cScriptPlayer *sp = (cScriptPlayer *)JS_GetPrivate(cx, obj);
      cPlayer *player = sp->GetPlayer();
      if(player == NULL) return JS_TRUE;

      cAnim *anim = player->m_self->Anim();

      switch(JSVAL_TO_INT(id)) 
      {
         //
         case xpos_prop:
            *vp = INT_TO_JSVAL(player->GetX());
            break;
         case ypos_prop:
            *vp = INT_TO_JSVAL(player->GetY());
            break;
         case zpos_prop:
            *vp = INT_TO_JSVAL(player->GetZ());
            break;

         //
         case joy_up_prop:
            *vp = BOOLEAN_TO_JSVAL(player->m_control[PL_UP]);
            break;
         case joy_down_prop:
            *vp = BOOLEAN_TO_JSVAL(player->m_control[PL_DOWN]);
            break;
         case joy_left_prop:
            *vp = BOOLEAN_TO_JSVAL(player->m_control[PL_LEFT]);
            break;
         case joy_right_prop:
            *vp = BOOLEAN_TO_JSVAL(player->m_control[PL_RIGHT]);
            break;
         case joy_b1_prop:
            *vp = BOOLEAN_TO_JSVAL(player->m_control[PL_A1]);
            break;
         case joy_b2_prop:
            *vp = BOOLEAN_TO_JSVAL(player->m_control[PL_A2]);
            break;
         case joy_b3_prop:
            *vp = BOOLEAN_TO_JSVAL(player->m_control[PL_A3]);
            break;

         //
         case is_slave_prop:
            *vp = BOOLEAN_TO_JSVAL(player->m_is_slave);
            break;

         //
         case walkspeed_prop:
            *vp = INT_TO_JSVAL(player->m_self->m_speed_walk);
            break;
         case runspeed_prop:
            *vp = INT_TO_JSVAL(player->m_self->m_speed_run);
            break;
         case dragspeed_prop:
            *vp = INT_TO_JSVAL(player->m_self->m_speed_lock);
            break;


         //
         case prev_state_prop:
            *vp = INT_TO_JSVAL(player->m_prev_state);
            break;
         case prev_hdir_prop:
            *vp = INT_TO_JSVAL(player->m_prev_fdir_lr);
            break;
         case prev_vdir_prop:
            *vp = INT_TO_JSVAL(player->m_prev_fdir_ud);
            break;

         //
         case state_prop:
            *vp = INT_TO_JSVAL(player->GetState());
            break;
         case attack_prop:
            *vp = INT_TO_JSVAL(player->GetAttack());
            break;
         case col_type_prop:
            *vp = INT_TO_JSVAL(player->GetColType());
            break;

         case hdir_prop:
            *vp = BOOLEAN_TO_JSVAL(player->m_fdir_lr);
            break;
         case vdir_prop:
            *vp = BOOLEAN_TO_JSVAL(player->m_fdir_ud);
            break;

         //
         case target_prop:
            *vp = OBJECT_TO_JSVAL( player->GetTargetJSObject() );
            break;

         case slave_prop:
            *vp = OBJECT_TO_JSVAL( player->GetSlaveJSObject() );
            break;

         //
         case anim_prop:
            s = anim->GetName();
            str = JS_NewStringCopyN(cx, s, sizeof(char)*(strlen(s) + 1));

            *vp = STRING_TO_JSVAL(str);
            break;
         case anim_done_prop:
            *vp = BOOLEAN_TO_JSVAL( anim->Done() );
            break;
         case frame_prop:
            *vp = INT_TO_JSVAL( anim->GetFrame() );
            break;
         case frame_done_prop:
            *vp = BOOLEAN_TO_JSVAL( anim->FrameDone() );
            break;

         case zone_prop:
            if(sp->m_zone != NULL) {
               *vp = OBJECT_TO_JSVAL( sp->m_zone->GetJSObject() );
            }
            break;

         //
         case hp_prop:
            *vp = INT_TO_JSVAL(player->m_hp);
            break;
         case hp_max_prop:
            *vp = INT_TO_JSVAL(player->m_hp_max);
            break;
         case stamina_prop:
            *vp = INT_TO_JSVAL(player->m_stamina);
            break;
         case stamina_max_prop:
            *vp = INT_TO_JSVAL(player->m_stamina_max);
            break;

         //
         case ss_prop:
            *vp = INT_TO_JSVAL(player->m_superstars);
            break;
         case flags_prop:
            *vp = INT_TO_JSVAL(player->m_combo_pts);
            break;

         //
         case draw_order_prop:
            *vp = INT_TO_JSVAL(player->m_draw_order);
            break;

      }
   }

   return JS_TRUE;
}



//
JSBool cScriptPlayer::js_SetProperty(JSContext *cx, JSObject *obj, jsval id, jsval *vp)
{
   if(JSVAL_IS_INT(id)) 
   {
      char *s;
      JSString *str;
      JSObject *js_obj = NULL;

      cScriptPlayer *sp = (cScriptPlayer *)JS_GetPrivate(cx, obj);
      cPlayer *player = sp->GetPlayer();

      switch(JSVAL_TO_INT(id)) 
      {
         //
         case xpos_prop:
            player->SetX( JSVAL_TO_INT(*vp) );
            break;
         case ypos_prop:
            player->SetY( JSVAL_TO_INT(*vp) );
            break;
         case zpos_prop:
            player->SetZ( JSVAL_TO_INT(*vp) );
            break;

         //
         case state_prop:
            player->SetState( JSVAL_TO_INT(*vp) );
            break;

         //
         case hdir_prop:
            player->m_fdir_lr = (JSVAL_TO_BOOLEAN(*vp) > 0);
            break;
         case vdir_prop:
            player->m_fdir_ud = (JSVAL_TO_BOOLEAN(*vp) > 0);
            break;

         //
         case prev_state_prop:
            player->m_prev_state = JSVAL_TO_INT(*vp);
            break;
         case prev_hdir_prop:
            player->m_prev_fdir_lr = (JSVAL_TO_BOOLEAN(*vp) > 0);
            break;
         case prev_vdir_prop:
            player->m_prev_fdir_ud = (JSVAL_TO_BOOLEAN(*vp) > 0);
            break;

         // set slave
         case slave_prop:
            js_obj = JSVAL_TO_OBJECT(*vp);

            if(js_obj == NULL) {
               player->AttachSlave(NULL);
            } else {
               if(info->pmngr != NULL)
               {
                  cPlayer *tp = info->pmngr->Find(js_obj);
                  player->AttachSlave(tp);
               }
            }
            break;

         //
         case anim_prop:
            str = JSVAL_TO_STRING(*vp);
            s = JS_GetStringBytes(str);
            player->m_self->AnimSelect(s);
            break;
         case frame_prop:
            player->m_self->AnimSetFrame( JSVAL_TO_INT(*vp) );
            break;

         //
         case hp_prop:
            player->m_hp = JSVAL_TO_INT(*vp);
            break;
         case hp_max_prop:
            player->m_hp_max = JSVAL_TO_INT(*vp);
            break;
         case stamina_prop:
            player->m_stamina = JSVAL_TO_INT(*vp);
            break;
         case stamina_max_prop:
            player->m_stamina_max = JSVAL_TO_INT(*vp);
            break;

         //
         case ss_prop:
            player->m_superstars = JSVAL_TO_INT(*vp);
            break;
         case flags_prop:
            player->m_combo_pts = JSVAL_TO_INT(*vp);
            break;

         //
         case draw_order_prop:
            player->m_draw_order = JSVAL_TO_INT(*vp);
            break;

      }
   }
   return JS_TRUE;
}



//
JSBool cScriptPlayer::js_Constructor(JSContext *cx, JSObject *obj, uintN argc, jsval *argv, jsval *rval)
{
	cScriptPlayer *sp = new cScriptPlayer();
	sp->SetPlayer(new cPlayer());
	JS_SetPrivate(cx, obj, (void *)sp);

	return JS_TRUE;
}


void cScriptPlayer::js_Destructor(JSContext *cx, JSObject *obj)
{
	cScriptPlayer *priv = (cScriptPlayer *)JS_GetPrivate(cx, obj);

   DELETE(priv);
}


JSObject *cScriptPlayer::js_Init(JSContext *cx, JSObject *obj, JSObject *proto)
{
   // make sure this function is only called once
   if(js_is_init) return NULL;

   JSObject *newProtoObj = JS_InitClass(cx, obj, proto,
                              &js_class, 
                              cScriptPlayer::js_Constructor,
                              0, NULL,
                              cScriptPlayer::js_methods,
                              NULL, NULL);
   
   JS_DefineProperties(cx, newProtoObj,
         cScriptPlayer::js_properties);

   js_is_init = true;
   return newProtoObj;
}


cPlayer *cScriptPlayer::Init(JSContext *cx, JSObject *obj)
{
   m_cx = cx;
   m_obj = obj;
   cScriptPlayer::js_Init(m_cx, m_obj);

   m_js_obj = JS_ConstructObject(m_cx, &js_class, NULL, NULL);
   
   cScriptPlayer *sp = (cScriptPlayer *)JS_GetPrivate(m_cx, m_js_obj);
   if(sp != NULL)
   {
      cPlayer *p = sp->GetPlayer();
      p->m_js_object = m_js_obj;

      // add collision object to player
      sp->m_zone = new cScriptEnvCollision();
      p->SetZoneInfo( sp->m_zone->Init(m_cx, m_obj) );

	   return p;
   } else {
      return NULL;
   }
}

int cScriptPlayer::PreUpdate()
{
   JSBool ok;
   jsval rval = 0;
   jsval argv;
   argv = OBJECT_TO_JSVAL(m_js_obj);

   cScriptPlayer *sp = (cScriptPlayer *)JS_GetPrivate(m_cx, m_js_obj);
   if(sp != NULL)
   {
      cPlayer *p = sp->GetPlayer();
      if(p != NULL)
         p->PreUpdate();
   }

   ok = JS_CallFunctionName(m_cx, m_obj, "PlayerPreUpdate", 1, &argv, &rval);
   if(ok)
   {
      JSString *str;
      str = JS_ValueToString(m_cx, rval);
		char *s = JS_GetStringBytes(str);


   } else {
      return 1;
   }

   return 0;
}

int cScriptPlayer::PostUpdate()
{
   JSBool ok;
   jsval rval = 0;
   jsval argv;
   argv = OBJECT_TO_JSVAL(m_js_obj);

   cScriptPlayer *sp = (cScriptPlayer *)JS_GetPrivate(m_cx, m_js_obj);
   if(sp != NULL)
   {
      cPlayer *p = sp->GetPlayer();
      if(p != NULL)
         p->PostUpdate();
   }

   ok = JS_CallFunctionName(m_cx, m_obj, "PlayerPostUpdate", 1, &argv, &rval);
   if(ok)
   {
      JSString *str;
      str = JS_ValueToString(m_cx, rval);
		char *s = JS_GetStringBytes(str);


   } else {
      return 1;
   }

   return 0;
}

int cScriptPlayer::PlayerInit()
{
   JSBool ok;
   jsval rval;
   jsval argv;
   argv = OBJECT_TO_JSVAL(m_js_obj);

   ok = JS_CallFunctionName(m_cx, m_obj, "PlayerInit", 1, &argv, &rval);
   if(ok)
   {
      // good
   } else {
      // bag
      return 1;
   }

   return 0;
}


JSBool cScriptPlayer::AnimStep(JSContext *cx, JSObject *obj, uintN argc, jsval *argv, jsval *rval)
{
   cScriptPlayer *sp = (cScriptPlayer *)JS_GetPrivate(cx, obj);
   if(sp != NULL)
   {
      cPlayer *p = sp->GetPlayer();
      if(p != NULL) {
         p->Step();
      } else
      return JS_FALSE;

   } else
      return JS_FALSE;

   return JS_TRUE;
}

JSBool cScriptPlayer::AnimSelect(JSContext *cx, JSObject *obj, uintN argc, jsval *argv, jsval *rval)
{
   cScriptPlayer *sp = (cScriptPlayer *)JS_GetPrivate(cx, obj);
   if(sp != NULL)
   {
      cPlayer *p = sp->GetPlayer();
      if(p != NULL) {
         JSString *str = NULL;
         char *s = NULL;
         uInt16 fnum = 0;

         if(argc > 0)
         {
            str = JSVAL_TO_STRING(argv[0]);
            s = JS_GetStringBytes(str);

            if(argc == 2) fnum = JSVAL_TO_INT(argv[1]);
         }

         if(s != NULL)
            p->m_self->AnimSelect(s, fnum);

      } else
      return JS_FALSE;

   } else
      return JS_FALSE;

   return JS_TRUE;
}


JSBool cScriptPlayer::AnimPlay(JSContext *cx, JSObject *obj, uintN argc, jsval *argv, jsval *rval)
{
   cScriptPlayer *sp = (cScriptPlayer *)JS_GetPrivate(cx, obj);
   if(sp != NULL)
   {
      cPlayer *p = sp->GetPlayer();
      if(p != NULL) {
         p->m_self->Anim()->Play();
      } else
      return JS_FALSE;

   } else
      return JS_FALSE;

   return JS_TRUE;
}

JSBool cScriptPlayer::AnimPause(JSContext *cx, JSObject *obj, uintN argc, jsval *argv, jsval *rval)
{
   cScriptPlayer *sp = (cScriptPlayer *)JS_GetPrivate(cx, obj);
   if(sp != NULL)
   {
      cPlayer *p = sp->GetPlayer();
      if(p != NULL) {
         p->m_self->Anim()->Pause();
      } else
      return JS_FALSE;

   } else
      return JS_FALSE;

   return JS_TRUE;
}