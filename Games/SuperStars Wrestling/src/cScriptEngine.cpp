/* //////////////////////////////////////////////////////////////////////
 Program Name:  cScriptEngine.cpp
 Programmer:    Joseph E. Sutton
 Start Date:    2006-08-05
 Updated:       
 Version:       1.00
 Description:
   JavaScript Class Source File
   
////////////////////////////////////////////////////////////////////// */

#include "main.h"


JSClass _js_globalClass = 
{
  "Global", 0,
  JS_PropertyStub,  JS_PropertyStub,JS_PropertyStub, JS_PropertyStub,
  JS_EnumerateStub, JS_ResolveStub, JS_ConvertStub,  JS_FinalizeStub
};


cScriptEngine::cScriptEngine()
{
   m_rt = NULL;
   m_cx = NULL;
   m_gObj = NULL;
}

cScriptEngine::~cScriptEngine()
{
}

int cScriptEngine::Exit()
{
   if(m_cx != NULL)
   {
      JS_DestroyContext(m_cx);
      m_cx = NULL;
   }

	if(m_rt != NULL)
   {
      JS_Finish(m_rt);
      m_rt = NULL;
   }

   DELETE_A(m_script_code);

   return 0;
}

int cScriptEngine::Init()
{
   m_rt = JS_Init(0x100000);
	if(m_rt != NULL) {
		m_cx = JS_NewContext(m_rt, 0x1000);
   }

   if(m_cx != NULL) {
      m_gObj = JS_NewObject(m_cx, &_js_globalClass, 0, 0);
   }

   if(m_gObj != NULL) {
	   JS_InitStandardClasses(m_cx, m_gObj);
   }


   return 0;
}

int cScriptEngine::Load(const char *filename)
{
   FILE *fp;
   char tmp[256];
   Int32 p = 0;

   fp = fopen(filename, "r+");
   if(fp == NULL) return 1;

   //
   p = 0;
   while( !feof(fp) )
   {
      p += fread( tmp, sizeof(char), 255, fp);
   }
   m_script_length = p + 1;
   //

   // allocate string
   m_script_code = new char[m_script_length];
   memset(m_script_code, 0, m_script_length*sizeof(char) );
   
   // reset back to start
   fseek(fp, 0, SEEK_SET);

   // read data
   p = 0;
   while( !feof(fp) )
   {
      p += fread( &(m_script_code[p]), sizeof(char), m_script_length - p, fp);
   }
   //
   m_script_length = p;

   // close
   fclose(fp);

   return 0;
}

int cScriptEngine::Start()
{
   JSBool ok = 0;
   m_rval = 0;

   ok = JS_EvaluateScript(m_cx, m_gObj, m_script_code, m_script_length, "", 0, &m_rval);
	if(ok == JS_TRUE)
	{
      JSString *str;
		str = JS_ValueToString(m_cx, m_rval);
		char *s = JS_GetStringBytes(str);
		
	} else {
      JSString *str;
		str = JS_ValueToString(m_cx, m_rval);
		char *s = JS_GetStringBytes(str);

		// error
      return 2;
	}

   return 0;
}


JSRuntime *cScriptEngine::GetRuntime()
{
   return m_rt;
}


JSContext *cScriptEngine::GetContext()
{
   return m_cx;
}

JSObject  *cScriptEngine::GetGObject()
{
   return m_gObj;
}