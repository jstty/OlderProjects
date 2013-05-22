//////////////////////////////////////////////////////////////////////////////
// Program Name:	gl_color.cpp
// Programmer:		Joseph E. Sutton
// Description:	OpenGL Color Class
// Start Date:		2/13/2007
// Version:			1.00
//////////////////////////////////////////////////////////////////////////////

#include "../include/cpts.h"

GlColor::GlColor()
{
   c.r = 0;
   c.g = 0;
   c.b = 0;
}

void GlColor::SetRGB(unsigned char R, 
                     unsigned char G,
							unsigned char B)
{
	c.r = ((double)R)/255.0f;
	c.g = ((double)G)/255.0f;
	c.b = ((double)B)/255.0f;
}

void GlColor::Set(Color cr)
{
   c = cr;
}

void GlColor::Apply()
{
	glColor3f(c.r, c.g, c.b);
}


void GlColor::SetBlack()
{
	this->SetRGB(0, 0, 0);
}

void GlColor::SetWhite()
{
	this->SetRGB(255, 255, 255);
}
