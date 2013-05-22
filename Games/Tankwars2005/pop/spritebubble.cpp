#include "stdafx.h"
#include "spritebubble.h"
#include "randomizer.h"
#include "graphics.h"

#define NOPIEYET //Means the pie isn't working yet.
//#define FIXEDPIE //Comment this in if you want a fixed pie wedge accent.

IMPLEMENT_SERIAL( cSpriteBubble, cSpriteComposite, 0 );
IMPLEMENT_SERIAL( cSpriteBubbleGrayscale, cSpriteBubble, 0 );
IMPLEMENT_SERIAL( cSpriteBubblePie, cSpriteBubble, 0 );
IMPLEMENT_SERIAL( cSpriteCircle, cPolygon, 0 );

int cSpriteCircle::CIRCLESLICES = 16;
Real cSpriteBubble::ACCENTRELIEF = 0.1;
//--------------cSpriteBubble----------------------------------------

cSpriteBubble::cSpriteBubble()
{
	cPolygon *pcircle = new cPolygon(cSpriteCircle::CIRCLESLICES);
	add(pcircle);
	setAccentPoly();
}

void cSpriteBubble::setAccentPoly()
{
	if (paccentpoly())
		delete paccentpoly();
	_childspriteptr.SetSize(1);
	Real side = 0.33 * (pcirclepoly()->radius());
	cVector pverts[4] = {cVector(0.0, 0.0, 0.0), cVector(2*side, 0.0, 0.0),
		cVector(2*side, side, 0.0), cVector(0.0, side, 0.0)};
	cPolygon *prectpoly = new cPolygon(4, pverts);
	prectpoly->setSpriteAttitude(cMatrix::translation(cVector(side, 0.5*side, cSpriteBubble::ACCENTRELIEF)));
	add(prectpoly); //Decoration rectangle.
	setFillColor(pcirclepoly()->fillColor()); //Make the accent color match the circle.
} 

cPolygon* cSpriteBubble::pcirclepoly() const
{
	if (_childspriteptr.GetSize()>0)
		return (cPolygon*)(_childspriteptr[0]);
	else 
		return NULL;
}

cPolygon* cSpriteBubble::paccentpoly() const
{
	if (_childspriteptr.GetSize()>1)
		return (cPolygon*)(_childspriteptr[1]);
	else 
		return NULL;
}

void cSpriteBubble::setFillColor(COLORREF fillcolor)
{ /* We set the _accentcolor to be _brighter than the fillcolor, in about same hue.
	To build _accentcolor, we use GetRValue which is a Windows macro to get the 
	"red" byte out of the 32 bit COLORREF.  We cast it into an int so we
	can add 64 to it without it wrapping around to 0 if it becomes greater
	than 256.  Then we use the CLAMP macro from realnumber.h.  Do same for green
	and blue. */
	int red, green, blue;
	pcirclepoly()->setFillColor(fillcolor);
	red = 64 + int(GetRValue(fillcolor)); 
	CLAMP(red, 0, 255);
	green = 64 + int(GetGValue(fillcolor));
	CLAMP(green, 0, 255);
	blue = 64 + int(GetBValue(fillcolor));
	CLAMP(blue, 0, 255);
	COLORREF accentcolor = RGB(red, green, blue);
//	setLineColor(accentcolor);
	if (paccentpoly())
		paccentpoly()->setFillColor(accentcolor);
}

void cSpriteBubble::mutate(int mutationflags, Real mutationstrength)
{
	pcirclepoly()->mutate(mutationflags & ~cPolygon::MF_VERTCOUNT, mutationstrength);
	setAccentPoly();
	int red, green, blue;
	//Pick bright colors that I can add 64 to and still be in range.
	red = cRandomizer::pinstance()->random(64, 255 - 64);
	green = cRandomizer::pinstance()->random(64, 255 - 64);
	blue = cRandomizer::pinstance()->random(64, 255 - 64);
	setFillColor(RGB(red, green, blue));
}

Real cSpriteBubble::radius() const
{
	return _spriteattitude.scalefactor()*pcirclepoly()->radius();
}

//====================cSpriteBubbleGrayscale===================
cSpriteBubbleGrayscale::cSpriteBubbleGrayscale()
{
	pcirclepoly()->setFillColor(RGB(200, 200, 200)); 
	paccentpoly()->setFillColor(cColorStyle::CN_GRAY);
}

void cSpriteBubbleGrayscale::setAccentPoly()
{
	if (paccentpoly())
		delete paccentpoly();
	_childspriteptr.SetSize(1);
	Real side = 0.33 * (pcirclepoly()->radius());
	cVector pverts[4] = {cVector(0.0, -1.5*side, 0.0), cVector(1.5*side, -0.5*side, 0.0),
		cVector(1.5*side, 0.5*side, 0.0), cVector(0.0, 1.5*side, 0.0)};
	cPolygon *prectpoly = new cPolygon(4, pverts);
	prectpoly->setSpriteAttitude(
		cMatrix::translation(cVector(1.5*side, 0.0, cSpriteBubble::ACCENTRELIEF)));
	add(prectpoly); //Decoration rectangle.
	setFillColor(pcirclepoly()->fillColor()); 
		//Make the accent color match the circle.
}

void cSpriteBubbleGrayscale::setFillColor(COLORREF fillcolor)
{ // Don't allow it
	//paccentpoly()->setFillColor(fillcolor);
}

//----------------------cSpriteBubblePie ---------------------

cSpriteBubblePie::cSpriteBubblePie()
{
	//The base class constructor has put in a rectangle.  Get rid of it.
	setAccentPoly();
}

cSpriteBubblePie::cSpriteBubblePie(cSprite *psprite)
{
	if (psprite->IsKindOf(RUNTIME_CLASS(cSpriteBubble)))
		copy(psprite);
	setFillColor(cRandomizer::pinstance()->randomColor());
	setAccentPoly();	
} //Uses copy

void cSpriteBubblePie::setAccentPoly()
{
	if (paccentpoly())
		delete paccentpoly();
	_childspriteptr.SetSize(1);
	cPolygon *ppiepoly = new cPolygon(5); // 1 + (cSpriteCircle::CIRCLESLICES / 6));
	ppiepoly->setVertex(0, cVector::ZEROVECTOR);
	ppiepoly->setVertex(1, pcirclepoly()->getVertex(cSpriteCircle::CIRCLESLICES-2));
	ppiepoly->setVertex(2, pcirclepoly()->getVertex(cSpriteCircle::CIRCLESLICES-1));
	ppiepoly->setVertex(3, pcirclepoly()->getVertex(0));
	ppiepoly->setVertex(4, pcirclepoly()->getVertex(1));
	ppiepoly->setVertex(5, pcirclepoly()->getVertex(2));
		/* Here, which is unusual for how we usually make polygons, we don't call setRadius,
		as it would be a bit of a pain to write the formula for the right radius.  The vertices of
		ppiepoly are just where we want them, and we don't want to do a call to 
		ppiepoly->fixCenterAndRadius either. */
	ppiepoly->setSpriteAttitude(
		cMatrix::translation(cVector(0.0, 0.0, cSpriteBubble::ACCENTRELIEF)));
	add(ppiepoly); //Decoration rectangle.
	setFillColor(pcirclepoly()->fillColor()); //Make the accent color match the circle.
}

