#ifndef SPRITEMULTIPLE_H
#define SPRITEMULTIPLE_H

#include "sprite.h"
#include "spriteicon.h"
#include "biota.h"
#include "game.h"

class cSpriteShowOneChild : public cSpriteComposite
{
DECLARE_SERIAL(cSpriteShowOneChild)
protected:
	int _showindex;
public:
	cSpriteShowOneChild():_showindex(cBiota::NOINDEX){};
	virtual ~cSpriteShowOneChild(){}
	virtual void add(cSprite *psprite); //adds to _childspriteptr like cSprite AND sets _showindex.
	virtual void add(int resourceid);
	void setShowIndex(int index);
	//affect parent and all children
	virtual void copy(cSprite *psprite);
	virtual void setRadius(Real radius);
	//affect parent and only the _showindex child, if one exists.
	virtual void draw(cGraphics *pgraphics, int drawflags);
	virtual void animate(Real dt, cCritter *powner);
	virtual void Serialize(CArchive &ar);
};

class cSpriteDirectional : public cSpriteShowOneChild
{
DECLARE_SERIAL(cSpriteDirectional)
public:
	cSpriteDirectional(){};
	virtual ~cSpriteDirectional(){}
	virtual void animate(Real dt, cCritter *powner);
};

class cSpriteLoop : public cSpriteShowOneChild
{
DECLARE_SERIAL(cSpriteLoop)
public:
	static Real FLIPWAIT;
protected:
	Real _imageage;
	Real _flipwait;
public:
	cSpriteLoop();
	cSpriteLoop(const cSpriteLoop *source);
	virtual ~cSpriteLoop(){}
	void copy(cSprite *psprite);
	void setFlipwait(Real flipwait){_flipwait = flipwait;}
	virtual void animate(Real dt, cCritter *powner);
	virtual void Serialize(CArchive &ar);
};
#endif // SPRITEMULTIPLE_H