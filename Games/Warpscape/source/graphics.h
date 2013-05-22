/****************************************
 filename:    graphics.h
 project:     warpattack
 created by:  Joseph E. Sutton
 date:        2010/04/18
 description: 
 ****************************************/
#ifndef _GRAPHICS_
#define _GRAPHICS_

#define MAX_GLOW 4

struct TextureGfx
{
   char   name[256];
   GLuint id;
};

struct Shader
{
   char   name[256];
   GLuint id;
};

struct OSBuffer
{
   uInt32 width;
   uInt32 height;

   GLfloat modelview[16];
   GLfloat projection[16];

   GLuint texture;
   GLuint fbo;
   GLuint depth;
};

class cGraphics
{
protected:
   uInt32  i;
   GLfloat c[4];
   
   GLfloat mLightDiffuse[4], mLightPosition[4];
   float   mBackgroundColor[4];
   
   
   vector<TextureGfx> mTextureList;
   cAnimModelBank    *mAnimModelBank;

   OSBuffer         mWindow;
   OSBuffer         mScene;
   vector<OSBuffer> mTemp1;
   vector<OSBuffer> mTemp2;
   Shader           mCurrentShaderProgram;

   vector<Shader>   mVertexList;
   vector<Shader>   mFragmentList;
   vector<Shader>   mShaderProgramList;

   int  CreateOSBuffer(OSBuffer &osb, uInt32 width, uInt32 height, GLenum format, GLenum type, GLenum filter);
   void BindOSB(OSBuffer osb, bool changeView = true);
   void DrawOSTextureQuard(OSBuffer osb);
   void DrawOSBlur(vector<OSBuffer> src, vector<OSBuffer> des, bool horz);

   void SelectShaderProgram(const char *name);
   void SetShaderValue1i(const char *name, GLint value);
   void SetShaderValue1f(const char *name, GLfloat value);
   void SetShaderValue1iv(const char *name, int size, GLint *value);
   void SetShaderValue1fv(const char *name, int size, GLfloat *value);
   void SetShaderValue4fv(const char *name, GLfloat value[4]);

   void PrintShaderError(GLuint shaderID);

   void FreeOSBuffers();

public:
   cGraphics();
   ~cGraphics();
   
   void Init();
   void StartDraw();
   void EndDraw();

   void DrawSolid(vector<Point3D> vertices, Color4D color);
   void Draw     (vector<Point3D> vertices, Color4D color);
   void Draw     (Point3D *points, uInt32 num_points, Point3D normal, Color4D color);
   void Draw     (Line3D *lines, uInt32 num_lines);
   
   void DrawTextureLine();
   
   int  LoadTexture(const char *name, const char *filename, uInt32 width);
   void SelectTexture(const char *name);
   
   // interface to AnimModelBank
   int            LoadAnimModel(const char *filename);
   cAnimModelGfx *FindAnimModel(const char *name);

   int            LoadVertexShader(const char *name, const char *filename);
   int            LoadFragmentShader(const char *name, const char *filename);
   int            LoadShaderProgram(const char *name, const char *vertex, const char *frag);

   bool  mGlowEnabled;
   float mGlowMag;
   int   InitHDR();
};

#endif // _GRAPHICS_
