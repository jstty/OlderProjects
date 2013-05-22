#include "stdafx.h" //includes math.h
#include "sprite3d.h"
#include "randomizer.h" 
#include "gl\gl.h"
#include "gl\glu.h"
#include "graphicsOpenGL.h"
#include "popview.h" //for DF_ flag
#include "spritepolygon.h"
#include "spritebubble.h"

IMPLEMENT_SERIAL(cSpriteSphere, cSprite,0)
IMPLEMENT_SERIAL(cSprite3DBox, cSprite,0)
//------------Constructors, Destructor, and Copiers---------------
cSprite3DBox::cSprite3DBox(Real xsize, Real ysize, Real zsize ):
cSprite()
{
	_spriteattitude = cMatrix3::scale(xsize, ysize, zsize);
} 

void cSprite3DBox::imagedraw(cGraphics *pgraphics, int drawflags)
{
	if (pgraphics->is3D())
	{
		if (drawflags & CPopView::DF_WIREFRAME)
			::glutWireCube(1.0);
		else
			::glutSolidCube(1.0);
	}		
	else
	{
		//cSprite::imagedraw(pgraphics, drawflags);
		cPolygon *ppolygon = new cPolygon(4);
		ppolygon->setEdged(TRUE);
		ppolygon->setLineWidthWeight(0.0); //Means draw a one-pixel edge line.
		ppolygon->setVertex(0, cVector(-1, -1));
		ppolygon->setVertex(1, cVector(1, -1));
		ppolygon->setVertex(2, cVector(1, 1));
		ppolygon->setVertex(3, cVector(-1, 1));
		ppolygon->fixCenterAndRadius(); /* Use this call after a bunch of
			setVertex if points are just where you want. */
		ppolygon->imagedraw(pgraphics, drawflags);
		delete ppolygon;
	}
}

//============================================================
//------------Constructors, Destructor, and Copiers---------------
cSpriteSphere::cSpriteSphere(Real radius, int slices, int stacks):
cSprite(),
_slices(slices),
_stacks(stacks)
{
	_radius = radius;
} 

void cSpriteSphere::mutate(int mutationflags, Real mutationstrength)
{
	cSprite::mutate(mutationflags, mutationstrength); 
}

void cSpriteSphere::imagedraw(cGraphics *pgraphics, int drawflags)
{
	if (pgraphics->is3D())
	{
		if ((edged() & !filled()) || (drawflags & CPopView::DF_WIREFRAME))
		/* If the sphere is filled, lets not draw its edges unless we're in wireframe
			The reason I put this in is because in many games the sprite by default is
			edged and filled for the sake of the polygonal sprites, and then if we select
			a sphere sprite and its edged as well as filled it runs too slow. */ 
		{
			pgraphics->setMaterialColor(lineColor());
			::glutWireSphere(_radius, _slices, _stacks);
		}
		if (filled() && !(drawflags & CPopView::DF_WIREFRAME))
		{
			pgraphics->setMaterialColor(fillColor());
			::glutSolidSphere(_radius, _slices, _stacks);
		}
	}		
	else
	{
		//cSprite::imagedraw(pgraphics, drawflags);
		cPolygon *pcircle = new cSpriteCircle();
		pcircle->setRadius(radius());
		pcircle->setFillColor(fillColor());
		pcircle->setEdged(TRUE);
		pcircle->setLineColor(cColorStyle::CN_WHITE);
		pcircle->imagedraw(pgraphics, drawflags);
		delete pcircle;
	}
}

