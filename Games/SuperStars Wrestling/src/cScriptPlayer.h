/* //////////////////////////////////////////////////////////////////////
 Program Name:  cScriptPlayer.h
 Programmer:    Joseph E. Sutton
 Start Date:    2006-08-05
 Updated:       
 Version:       1.00
 Description:   
   JavaScript Wrapper for Player Class Header File
   
////////////////////////////////////////////////////////////////////// */
#ifndef __SCRIPT_PLAYER__
#define __SCRIPT_PLAYER__

class cScriptPlayer
{
   public:
      cScriptPlayer();
      ~cScriptPlayer();

      // call before, calling cScriptEngine::Start()
      cPlayer* Init(JSContext *cx, JSObject *obj);

      //
      static JSClass js_class;
   
      //
      static JSBool js_GetProperty(JSContext *cx, JSObject *obj, jsval id, jsval *vp);
      static JSBool js_SetProperty(JSContext *cx, JSObject *obj, jsval id, jsval *vp);

      static JSBool js_Constructor(JSContext *cx, JSObject *obj, uintN argc, jsval *argv, jsval *rval);
      static void   js_Destructor(JSContext *cx, JSObject *obj);


      // custom functions
      static JSBool AnimStep(JSContext *cx, JSObject *obj, uintN argc, jsval *argv, jsval *rval);
      static JSBool AnimSelect(JSContext *cx, JSObject *obj, uintN argc, jsval *argv, jsval *rval);
      static JSBool AnimPlay(JSContext *cx, JSObject *obj, uintN argc, jsval *argv, jsval *rval);
      static JSBool AnimPause(JSContext *cx, JSObject *obj, uintN argc, jsval *argv, jsval *rval);


      //
      cPlayer* GetPlayer();

      // Calls Player Update function in JavaScript Code
      int PlayerInit();
      int PreUpdate();
      int PostUpdate();

   protected:
      JSObject *m_js_obj;
      cPlayer  *m_player;
      // col script object in player object
      cScriptEnvCollision *m_zone;

      void SetPlayer(cPlayer* p);

      static bool js_is_init;
      static JSObject* js_Init(JSContext *cx, JSObject *obj, JSObject *proto = NULL);

   private:
      JSContext *m_cx;
      JSObject  *m_obj;

      static JSPropertySpec js_properties[];
	   static JSFunctionSpec js_methods[];

      enum {
         xpos_prop, 
         ypos_prop,
         zpos_prop,

         joy_up_prop,
         joy_down_prop,
         joy_left_prop,
         joy_right_prop,
         joy_b1_prop,
         joy_b2_prop,
         joy_b3_prop,

         is_slave_prop,

         walkspeed_prop,
         runspeed_prop,
         dragspeed_prop,

         prev_state_prop,
         prev_hdir_prop,
         prev_vdir_prop,

         zone_prop,
         state_prop,
         attack_prop,
         col_type_prop,

         anim_prop,
         anim_done_prop,
         frame_prop,
         frame_done_prop,

         hdir_prop,
         vdir_prop,

         target_prop,
         slave_prop,
         col_prop,

         hp_prop,
         hp_max_prop,
         stamina_prop,
         stamina_max_prop,
         
         ss_prop,
         flags_prop,

         draw_order_prop,

         last_prop
	   };
};

#endif // __SCRIPT_PLAYER__
