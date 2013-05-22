#ifndef BUBBLE_H
#define BUBBLE_H

#include "spritepolygon.h"


class cSpriteCircle : public cPolygon
{
DECLARE_SERIAL(cSpriteCircle);
public:
	static int CIRCLESLICES; //Approximate a circle by a poly of CIRCLESLICES edges.
public:
	cSpriteCircle():cPolygon(cSpriteCircle::CIRCLESLICES){}
};

class cSpriteBubble : public cSpriteComposite //Basic bubble has a circular polygon and a rect on top.
{
DECLARE_SERIAL(cSpriteBubble); // This defines some useful CArchive serialization methods.
public:
	static Real cSpriteBubble::ACCENTRELIEF; //Raise the accent poly this much
public:
//Constructors
	cSpriteBubble();
	virtual void setAccentPoly();
//Accessors.
	cPolygon* pcirclepoly() const;
	cPolygon* paccentpoly() const;
//Overload
	virtual void mutate(int mutationflags, Real mutationstrength);
	virtual Real radius() const; //Just look at the pcirclepoly.
//Colorstyle mutators
	virtual void setFillColor(COLORREF fillcolor); /* We copy the fillcolor,
		and	then we set _accentcolor to be a brighter color of the same hue. This
		is virtual as cSpriteBubbleGrayscale must keep bubblecolor white. */
};

class cSpriteBubbleGrayscale : public cSpriteBubble // Grayscale.
{
DECLARE_SERIAL(cSpriteBubbleGrayscale);
public:
//Constructors
	cSpriteBubbleGrayscale();
//Mutator overload.
	virtual void setAccentPoly();
	virtual void setFillColor(COLORREF bubblecolor); // Just apply to accentcolor
};

class cSpriteBubblePie : public cSpriteBubble 
{
DECLARE_SERIAL(cSpriteBubblePie);
//Constructors
public:
	cSpriteBubblePie();
	cSpriteBubblePie(cSprite *psprite);//Uses copy, then fixes the accent.
	virtual void setAccentPoly();
};


#endif //BUBBLE_H