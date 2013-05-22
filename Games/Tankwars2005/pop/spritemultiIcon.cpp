// SpriteMultiIcon.cpp: implementation of the cSpriteShowOneChild, cSpriteLoop and cSpriteDirectional classes.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "spritemultiicon.h"
#include "Critter.h" //Only need this for the  cCritter static constants.
#include "graphics.h"

IMPLEMENT_SERIAL(cSpriteShowOneChild, cSpriteComposite, 0);
IMPLEMENT_SERIAL(cSpriteDirectional, cSpriteShowOneChild, 0);
IMPLEMENT_SERIAL(cSpriteLoop, cSpriteShowOneChild, 0);

//------------------ cSpriteDirectional construction ---------------------------
void cSpriteShowOneChild::copy(cSprite *psprite)
{
	cSpriteComposite::copy(psprite);
 /* does _center, _angle, _rotationspeed.  And if
		psprite is a cSpriteLoop, it copies the cSpriteLoop
		fields as well. */
	if (!psprite->IsKindOf(RUNTIME_CLASS(cSpriteShowOneChild)))
		return; //You're done if psprite isn't a cPolyPolygon*.
	cSpriteShowOneChild *pspriteshowonechild = (cSpriteShowOneChild *)(psprite); /* I know it is a
		cPolyPolygon at this point, but I need to do a cast, so the compiler will 
		let me call cPolyPolygon methods. */
	_showindex = pspriteshowonechild->_showindex;
}

void cSpriteShowOneChild::Serialize(CArchive &ar)
{
	cSpriteComposite::Serialize(ar);
	if (ar.IsStoring())
		ar << _showindex;
	else
		ar >> _showindex;
}

void cSpriteShowOneChild::add(cSprite *psprite)
{
	cSpriteComposite::add(psprite); //adds to _childspriteptr
	_showindex = 0; //signal that you have some valid child indices to play with.
}

void cSpriteShowOneChild::add(int resourceid)
{
	cSpriteComposite::add(resourceid); //adds to _childspriteptr
	_showindex = 0; //signal that you have some valid child indices to play with.
}

/* Still need to sort this out, but it seems that for methods that are just changing something about
the currently visible sprite we only need to do it to the _showindex sprite, while for other methods
like setting things, we need to do it to all. The default in cSpriteComposite should be to do it to all children,
actually. */

void cSpriteShowOneChild::draw(cGraphics *pgraphics, int drawflags)
{ 
	pgraphics->pushMatrix();
	pgraphics->multMatrix(_spriteattitude);
		/* For now, let's not try and use display lists for the composite, but only for the
		individual pieces. */
	if (_showindex != cBiota::NOINDEX)
		_childspriteptr[_showindex]->draw(pgraphics, drawflags);
	else
		cSprite::draw(pgraphics, drawflags); //Just to show something, a hollow circle.
	pgraphics->popMatrix();
}

void cSpriteShowOneChild::setShowIndex(int index)
{
	if (index < 0 || index >= _childspriteptr.GetSize())
		_showindex = cBiota::NOINDEX;
	else
		_showindex = index;
}

void cSpriteShowOneChild::animate(Real dt, cCritter *powner)
{
	if (_showindex != cBiota::NOINDEX)
		_childspriteptr[_showindex]->animate(dt, powner);
}

/* Universal Mutators.  For some of these we mutate all of the children, at least for now, though maybe
later we can get by with only mutating the _showindex guy. */

void cSpriteShowOneChild::setRadius(Real radius)
{
	cSprite::setRadius(radius);
	for (int i = 0; i < _childspriteptr.GetSize(); i++)
		_childspriteptr[i]->setRadius(radius);
}

//====================== cSpriteDirectional =================

void cSpriteDirectional::animate(Real dt, cCritter *powner)
{ 
	Real angle = powner->tangent().angle(); //cVector::angle returns value in [0, 2*PI).
	if (!_childspriteptr.GetSize())
		return;
	angle += PI/_childspriteptr.GetSize(); /* This is a correction term,
		so that the _showindex 0 will correspond to vectors 
		lying between - and + (2*PI / _childspriteptr.GetSize), that is
		a sector centered on the x-axis. */
	if (angle >= 2.0*PI)
		angle -= 2.0*PI;
	int oldshowindex = _showindex;
	_showindex =  
		int((angle*_childspriteptr.GetSize())/(2.0*PI));
	//We shouldn't need this next check, but let's be safe.
	if (_showindex >= _childspriteptr.GetSize() || _showindex < 0) //Just to be safe.
		_showindex = 0;
	if (_showindex != oldshowindex)
		_newgeometryflag = TRUE;
	_childspriteptr[_showindex]->animate(dt, powner); 
		//Often won't want to do this align, like if you're using bitmaps.
}

//===================== cSpriteLoop =======================

 //Statics
Real cSpriteLoop::FLIPWAIT = 0.2; // can be tweaked to smooth

//------------------ cSpriteLoop construction ---------------------------
cSpriteLoop::cSpriteLoop():
_flipwait(cSpriteLoop::FLIPWAIT),
_imageage(0.0)
{}

void cSpriteLoop::copy(cSprite *psprite)
{
	cSpriteShowOneChild::copy(psprite);
 /* does _center, _angle, _rotationspeed, and _showindex.  And if
		psprite is a cSpriteLoop, it copies the cSpriteLoop
		fields as well. */
	if (!psprite->IsKindOf(RUNTIME_CLASS(cSpriteLoop)))
		return; //You're done if psprite isn't a cPolyPolygon*.
	cSpriteLoop *pspriteloop = (cSpriteLoop *)(psprite); /* I know it is a
		cPolyPolygon at this point, but I need to do a cast, so the compiler will 
		let me call cPolyPolygon methods. */
	_flipwait = pspriteloop->_flipwait;
	_imageage = pspriteloop->_imageage;
}

void cSpriteLoop::animate(Real dt, cCritter *powner)
{
	_imageage += dt;
	if (_imageage > _flipwait && _showindex != cBiota::NOINDEX)
	{
		_imageage = 0.0;
		_showindex++;
		if (_showindex >= _childspriteptr.GetSize())
			_showindex = 0;
		_newgeometryflag = TRUE;
	}
	if (_showindex != cBiota::NOINDEX)
		_childspriteptr[_showindex]->animate(dt, powner);
}

void cSpriteLoop::Serialize(CArchive &ar)
{
	cSpriteShowOneChild::Serialize(ar);
	if (ar.IsStoring())
		ar << _imageage << _flipwait;
	else
		ar >> _imageage >> _flipwait;
}


