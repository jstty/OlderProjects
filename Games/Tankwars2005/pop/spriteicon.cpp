#include "stdafx.h"
#include "spriteicon.h"
#include "graphics.h"
#include "popview.h" //for WIREFRAME flag

IMPLEMENT_SERIAL(cSpriteIcon, cSprite, 0)
IMPLEMENT_SERIAL(cSpriteIconBackground, cSpriteIcon, 0)


cSpriteIcon::cSpriteIcon():
	_transparent(TRUE),
	_tiled(FALSE),
	_xtilecount(1),
	_imageloaded(FALSE),
	_presetaspect(FALSE)
{
	setFilled(FALSE);
	setAspect(1.0); //Sets _sizex and _sizey to match _radius which was set in cSprite::cSprite.
}

cSpriteIcon::cSpriteIcon(int resourceID, BOOL transparent, BOOL presetaspect):
	_transparent(transparent),
	_tiled(FALSE),
	_xtilecount(1),
	_imageloaded(FALSE),
	_presetaspect(FALSE),
	_visualradius(1.0)
{
	_resourceID = resourceID;
	setFilled(FALSE);
	setAspect(1.0); 
		//Sets _sizex, _sizey, _visualradius to match _radius which was set in cSprite::cSprite.
}

void cSpriteIcon::setAspect(Real aspect)
{
	/* We write the code to preserve two equations: (a) sizex/sizey = aspect and
	(b) sqrt(sizex^2 + sizey^2) = diameter = 2 * radius;
	(a) says sizex = aspect * sizey.  Substituting this into (b) and squaring both 
	sides I get (aspect^2 + 1)*sizey^2 = 4 * radius^2.  Solving this, I get
	sizey = 2 * radius * sqrt(1/(1+aspect^2))
	 */
	_aspect = fabs(aspect); //Don't allow negative aspect.
	_sizey = 2.0 * _radius * sqrt(1.0/(1.0 + _aspect*_aspect));
	_sizex = _aspect * _sizey; 
//	_visualradius = 0.5 * (0.5 * __min(_sizex, _sizey)) + _radius);
	_visualradius = 0.25*(_sizex + _sizey); //Avg of distances to sides.
	_newgeometryflag = TRUE;
}

void cSpriteIcon::setRadius(Real radius)
{
	/* Let's assume that when you call this, your goal is to match the visualradius to 
	the radius argument. */
	ASSERT(_visualradius);
	Real radiustovisual = _radius/_visualradius;
	_radius = radiustovisual*radius;
	setAspect(_aspect); //Fix _sizex and _sizey.
}

void cSpriteIcon::setSize(Real sizex, Real sizey)
{
	if (sizey < SMALL_REAL)
		return;
	_sizex = sizex;
	_sizey = sizey;
	_radius = sqrt(_sizex*_sizex + _sizey*_sizey);
	_aspect = _sizex / _sizey;
	setAspect(_aspect); //Fix _visualradius.
}

Real cSpriteIcon::radius() const 
{
	return _spriteattitude.scalefactor() * _visualradius;
} 

void cSpriteIcon::imagedraw(cGraphics *pgraphics, int drawflags)
{
	if (!(drawflags & CPopView::DF_WIREFRAME))
		pgraphics->drawbitmap(this, drawflags);
	else //we're in wireframe mode
		pgraphics->drawXYrectangle(locorner(), hicorner(),
			pcolorstyle(), drawflags);
}

void cSpriteIcon::copy(cSprite *psprite) //Use this in copy constructor and operator=
{
	cSprite::copy(psprite);
	if (!psprite->IsKindOf(RUNTIME_CLASS(cSpriteIcon)))
		return; //You're done if psprite isn't a cSpriteIcon*.
	cSpriteIcon *picon = (cSpriteIcon *)(psprite); /* I know it is a
		cSpriteIcon at this point, but I need to do a cast, so the compiler will 
		let me call cSpriteIcon methods. */
	_transparent = picon->_transparent;
	setAspect(picon->_aspect); //Sets _aspect, _sizex, _sizey, _visualradius
	_presetaspect = picon->_presetaspect;
}	

void cSpriteIcon::Serialize(CArchive &ar)
{
/* We don't serialize _imageloaded, as that gets set when the icon is first drawn. */
	cSprite::Serialize(ar);
	if (ar.IsStoring()) //Writing data.
		ar << _transparent << _tiled << _presetaspect << _aspect << _sizex << _sizey <<
			_visualradius;
	else //Reading data.
		ar >> _transparent >> _tiled >> _presetaspect >> _aspect >> _sizex >> _sizey >>
			_visualradius;
}

//==============cSpriteIconBackground==========

cSpriteIconBackground::cSpriteIconBackground(
	int resourceID, const cRealBox2 &borderrect, int xtilecount)
{
	_xtilecount = xtilecount;
	if (_xtilecount > 1)
		_tiled = TRUE;
	_transparent = FALSE;
	_presetaspect = TRUE;
	_resourceID = resourceID;
	_radius = borderrect.radius();
	_sizex= borderrect.xsize();
	_sizey = borderrect.ysize();
	_aspect = (Real)_sizex/(Real)_sizey;
	_visualradius = 0.25*(_sizex + _sizey); //Avg of distances to sides.
}
