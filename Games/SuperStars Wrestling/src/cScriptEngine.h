/* //////////////////////////////////////////////////////////////////////
 Program Name:  cScriptEngine.h
 Programmer:    Joseph E. Sutton
 Start Date:    2006-08-05
 Updated:       
 Version:       1.00
 Description:
   JavaScript Class Header File
   
////////////////////////////////////////////////////////////////////// */
#ifndef __SCRIPT_ENGINE__
#define __SCRIPT_ENGINE__


class cScriptEngine
{
   public:
      cScriptEngine();
      ~cScriptEngine();

      int Init();
      int Exit();

      int Load(const char *filename);

      // call after calling all cScriptObject's Init's
      int Start();

      JSRuntime *GetRuntime();
      JSContext *GetContext();
      JSObject  *GetGObject();

   protected:
      uInt32  m_script_length;
      char   *m_script_code;

      jsval m_rval;
      jsval m_argv[2];

      JSRuntime *m_rt;
      JSContext *m_cx;
      JSObject  *m_gObj;
};

#endif // __SCRIPT_ENGINE__
