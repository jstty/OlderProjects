/* //////////////////////////////////////////////////////////////////////
 Program Name:  cScriptEnvCollision.h
 Programmer:    Joseph E. Sutton
 Start Date:    2006-08-25
 Updated:       
 Version:       1.00
 Description:   
   JavaScript Enviromental Collision Wrapper for Player Class Header File
   
////////////////////////////////////////////////////////////////////// */
#ifndef __SCRIPT_ENV_COLLISION__
#define __SCRIPT_ENV_COLLISION__

class cScriptEnvCollision
{
   public:
      cScriptEnvCollision();
      ~cScriptEnvCollision();

      // call before, calling cScriptEngine::Start()
      cZoneInfo* Init(JSContext *cx, JSObject *obj);

      //
      static JSClass js_class;
   
      //
      static JSBool js_GetProperty(JSContext *cx, JSObject *obj, jsval id, jsval *vp);
      static JSBool js_SetProperty(JSContext *cx, JSObject *obj, jsval id, jsval *vp);

      static JSBool js_Constructor(JSContext *cx, JSObject *obj, uintN argc, jsval *argv, jsval *rval);
      static void   js_Destructor(JSContext *cx, JSObject *obj);


      //
      void    SetZoneInfo(cZoneInfo* z);
      cZoneInfo* GetZoneInfo();

      JSObject *GetJSObject();

   protected:
      JSObject  *m_js_obj;
      cZoneInfo *m_zoneinfo;

      static bool js_is_init;
      static JSObject* js_Init(JSContext *cx, JSObject *obj, JSObject *proto = NULL);

   private:
      JSContext *m_cx;
      JSObject  *m_obj;

      static JSPropertySpec js_properties[];
	   static JSFunctionSpec js_methods[];

      enum {
         collidable_prop, 

         current_prop,
         previous_prop,
         changed_prop,

         line_collided_prop,
         line_num_prop,
         line_threshold_prop
	   };
};

#endif // __SCRIPT_ENV_COLLISION__
