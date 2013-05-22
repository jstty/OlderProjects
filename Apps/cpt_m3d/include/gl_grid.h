//////////////////////////////////////////////////////////////////////////////
// Program Name:	gl_grid.h
// Programmer:		Joseph E. Sutton
// Description:	OpenGL Grid Class
// Start Date:		2/13/2007
// Version:			1.00
//////////////////////////////////////////////////////////////////////////////

#ifndef __GL_GRID__
#define __GL_GRID__

// start class
class GlGrid
{
	protected:
		float front[3];
      float mid[3];
      float back[3];
      float step, zmax;
      float x, y, z, zcolorstep[3];

      void DrawAxis();

   public:
      void Init();
      void Loop();
      void Display();
      
      void SetColor(double f[3], double m[3], double b[3]);

};
// end class

#endif // END __GL_GRID__