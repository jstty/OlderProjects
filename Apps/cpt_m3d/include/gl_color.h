//////////////////////////////////////////////////////////////////////////////
// Program Name:	gl_color.h
// Programmer:		Joseph E. Sutton
// Description:	OpenGL Color Class
// Start Date:		2/13/2007
// Version:			1.00
//////////////////////////////////////////////////////////////////////////////

#ifndef __GL_COLOR__
#define __GL_COLOR__

#include "types_structs.h"

// start class
class GlColor
{
	protected:
		Color c;

   public:
      GlColor();

      void SetRGB(unsigned char R, 
                  unsigned char G,
                  unsigned char B);
      
      void Set(Color cr);
                  
      void Apply();

      void SetBlack();
      void SetWhite();
};
// end class

#endif // END __GL_COLOR__
