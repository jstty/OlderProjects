/* //////////////////////////////////////////////////////////////////////
 Program Name:  cScriptEnvCollision.cpp
 Programmer:    Joseph E. Sutton
 Start Date:    2006-08-25
 Updated:       
 Version:       1.00
 Description:
   JavaScript Enviromental Collision Wrapper for Player Class Source File
   
////////////////////////////////////////////////////////////////////// */

#include "main.h"

bool cScriptEnvCollision::js_is_init = false;

JSPropertySpec cScriptEnvCollision::js_properties[] = 
{
   { "collidable",     collidable_prop,     JSPROP_ENUMERATE }, // rw

   { "current",        current_prop,        JSPROP_ENUMERATE }, // rw
   { "previous",       previous_prop,       JSPROP_ENUMERATE }, // r
   { "changed",        changed_prop,        JSPROP_ENUMERATE }, // r

   { "line_collided",  line_collided_prop,  JSPROP_ENUMERATE }, // r
   { "line_num",       line_num_prop,       JSPROP_ENUMERATE }, // r
   { "line_threshold", line_threshold_prop, JSPROP_ENUMERATE }, // rw
  
   { 0 }
};


JSFunctionSpec cScriptEnvCollision::js_methods[] = 
{
   { 0, 0, 0, 0, 0 }
};


/*
JSFunctionSpec cScriptEnvCollision::js_methods[] = 
{
   { "SelectAnim", SelectAnim, 1, 0, 0 },
   { 0, 0, 0, 0, 0 }
};
*/

JSClass cScriptEnvCollision::js_class = 
{ 
   "EnvCollision", JSCLASS_HAS_PRIVATE, JS_PropertyStub, JS_PropertyStub,
   cScriptEnvCollision::js_GetProperty,
   cScriptEnvCollision::js_SetProperty,
   JS_EnumerateStub, JS_ResolveStub, JS_ConvertStub, 
   cScriptEnvCollision::js_Destructor
};



cScriptEnvCollision::cScriptEnvCollision()
{
   m_zoneinfo = NULL;
}

cScriptEnvCollision::~cScriptEnvCollision()
{
   DELETE(m_zoneinfo);
}

// called on Init to set private cScriptEnvCollision's ZoneInfo
void cScriptEnvCollision::SetZoneInfo(cZoneInfo* z)
{
   m_zoneinfo = z;
}

cZoneInfo* cScriptEnvCollision::GetZoneInfo()
{
   return m_zoneinfo;
}


JSObject *cScriptEnvCollision::GetJSObject()
{
   return m_js_obj;
}

//
JSBool cScriptEnvCollision::js_GetProperty(JSContext *cx, JSObject *obj, jsval id, jsval *vp)
{
   if(JSVAL_IS_INT(id))
	{
      //char *s;
      //JSString *str;

      cScriptEnvCollision *sec = (cScriptEnvCollision *)JS_GetPrivate(cx, obj);
      cZoneInfo *zi = sec->GetZoneInfo();

      switch(JSVAL_TO_INT(id)) 
      {
         //
         case collidable_prop:
            *vp = BOOLEAN_TO_JSVAL(zi->m_is_colliable);
            break;

         //
         case current_prop:
            *vp = INT_TO_JSVAL(zi->GetZone());
            break;
         case previous_prop:
            *vp = INT_TO_JSVAL(zi->GetPrevZone());
            break;
         case changed_prop:
            *vp = BOOLEAN_TO_JSVAL(zi->ZoneChanged());
            break;

         //
         case line_collided_prop:
            *vp = BOOLEAN_TO_JSVAL(zi->m_pressing_line);
            break;
         case line_num_prop:
            *vp = INT_TO_JSVAL(zi->m_cline);
            break;
         case line_threshold_prop:
            *vp = INT_TO_JSVAL(zi->m_threshold);
            break;
      }
   }

   return JS_TRUE;
}



//
JSBool cScriptEnvCollision::js_SetProperty(JSContext *cx, JSObject *obj, jsval id, jsval *vp)
{
   if(JSVAL_IS_INT(id)) 
   {
      //char *s;
      //JSString *str;

      cScriptEnvCollision *sec = (cScriptEnvCollision *)JS_GetPrivate(cx, obj);
      cZoneInfo *zi = sec->GetZoneInfo();

      switch(JSVAL_TO_INT(id)) 
      {
         //
         case collidable_prop:
            zi->m_is_colliable = (JSVAL_TO_BOOLEAN(*vp) > 0);
            break;

         //
         case current_prop:
            zi->m_czone = JSVAL_TO_INT(*vp);
            break;

         //
         case line_threshold_prop:
            zi->m_threshold = JSVAL_TO_INT(*vp);
            break;
      }
   }
   return JS_TRUE;
}



//
JSBool cScriptEnvCollision::js_Constructor(JSContext *cx, JSObject *obj, uintN argc, jsval *argv, jsval *rval)
{
	cScriptEnvCollision *sec = new cScriptEnvCollision();
	sec->SetZoneInfo(new cZoneInfo());
   sec->m_js_obj = obj;

	JS_SetPrivate(cx, obj, (void *)sec);

	return JS_TRUE;
}


void cScriptEnvCollision::js_Destructor(JSContext *cx, JSObject *obj)
{
	cScriptEnvCollision *priv = (cScriptEnvCollision *)JS_GetPrivate(cx, obj);

   DELETE(priv);
}


JSObject *cScriptEnvCollision::js_Init(JSContext *cx, JSObject *obj, JSObject *proto)
{
   // make sure this function is only called once
   if(js_is_init) return NULL;

   JSObject *newProtoObj = JS_InitClass(cx, obj, proto,
                              &js_class, 
                              cScriptEnvCollision::js_Constructor,
                              0, NULL,
                              cScriptEnvCollision::js_methods,
                              NULL, NULL);
   
   JS_DefineProperties(cx, newProtoObj,
         cScriptEnvCollision::js_properties);

   js_is_init = true;
   return newProtoObj;
}


cZoneInfo *cScriptEnvCollision::Init(JSContext *cx, JSObject *obj)
{
   m_cx = cx;
   m_obj = obj;
   cScriptEnvCollision::js_Init(m_cx, m_obj);

   m_js_obj = JS_ConstructObject(m_cx, &js_class, NULL, NULL);
   
   cScriptEnvCollision *sec = (cScriptEnvCollision *)JS_GetPrivate(m_cx, m_js_obj);
   if(sec != NULL)
   {
      cZoneInfo *zi = sec->GetZoneInfo();

	   return zi;
   } else {
      return NULL;
   }
}


