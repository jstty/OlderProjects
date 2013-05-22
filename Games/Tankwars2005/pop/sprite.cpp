// Sprite.cpp: implementation of the cSprite class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Sprite.h"
#include "Critter.h" //Only need this for the  cCritter static constants.
#include "graphics.h"
#include "spriteicon.h"
#include "popview.h"
#include "sprite3d.h"
#include "spritequake.h"

//===================== cSprite =======================

 IMPLEMENT_SERIAL(cSprite, CObject, 0 );
 IMPLEMENT_SERIAL(cSpriteComposite, cSprite, 0 );

//Statics
long unsigned int cSprite::SPRITEID = 1; //The valid IDs range from 1 to 0xFFFFFFFF
const long unsigned int cSprite::INVALIDID = 0;
//  Prism Statics==========================================
#ifdef THREEDVECTORS
//Real cCritterWall::WALLPRISMDZ = 0.75; //Define this in critterwall.cpp
Real cSprite::PLAYERPRISMDZ = 0.5;
Real cSprite::CRITTERPRISMDZ = 0.3;
Real cSprite::BULLETPRISMDZ = 0.2;
Real cSprite::MAXPRISMDZ = 1.0;
#else //not THREEDVECTOR means 2D case
Real cSprite::CRITTERPRISMDZ = 0.0;
Real cSprite::BULLETPRISMDZ = 0.0;
//Real cSprite::WALLPRISMDZ = 0.0; //do this in critterwall.cpp
Real cSprite::PLAYERPRISMDZ = 0.0;
Real cSprite::MAXPRISMDZ = 1.0;
#endif //THREEDVECTOR
//===================More cSprite Statics =====================
Real cSprite::MINANGVELOCITY = -PI/2; //These are used in cSprite::randomize(MF_ROTATION)
Real cSprite::MAXANGVELOCITY = PI/2;
Real cSprite::HIGHLIGHTRATIO = 1.1; //Used in cSprite::draw(...DF_FOCUS...)
/* We have automated the use of display list IDs.  	Using a display list for polygons gains
 me about 10% speed for polygons and 80%  speed	for polypolygons under my present test
conditions (12/4/2001). Note that the display list IDs don't help you for cSpriteIcon, so
we overload cSpriteIcon::enabledisplaylist() to retrun FALSE.  Also if you load standard
Quake meshes, you may want want to have enabledisplaylist() to retrun FALSE. */

//------------------ cSprite basics ---------------------------
cSprite::cSprite():
	_prismdz(cSprite::CRITTERPRISMDZ),
	_newgeometryflag(TRUE),
	_pcolorstyle(NULL),
	_resourceID(-1)
{
	setCenter(cVector(0.0, 0.0)); //Sets last column of _spriteattitude.
 /* We start the cSprite with a nonzero radius so that we can readily adjust
its size by scaling it, that is, by multiplying it by scale factors. Let's start
it as the average of the cCritter min and max.*/ 
	_radius = (cCritter::MINRADIUS + cCritter::MAXRADIUS) / 2.0; 
	_pcolorstyle = new cColorStyle();
	//Default constructor of _spriteattidute will be an identity matrix.
	_spriteID = cSprite::SPRITEID++; // The the first one gets a value of 1.
	ASSERT(_spriteID != cSprite::INVALIDID);
}

cSprite::~cSprite()
{
	delete _pcolorstyle;
}

void cSprite::setColorStyle(cColorStyle *pcolorstyle)
{
	delete _pcolorstyle;
	_pcolorstyle = pcolorstyle;
	_newgeometryflag = TRUE;
}		

void cSprite::Serialize(CArchive &ar)
{
	CObject::Serialize(ar);
	if (ar.IsStoring()) //Writing data.
		ar << _radius << _prismdz << _spriteattitude  << _resourceID << _pcolorstyle;
	else //Reading data.
	{
 		delete _pcolorstyle;
 			//always delete a pointer before reading into it or you have a leak.
		ar >>  _radius >> _prismdz >> _spriteattitude >>  _resourceID >> _pcolorstyle;
	}
}

//------------------ cSprite copying ---------------------------

cSprite::cSprite(cSprite &sprite)
{
	copy(&sprite);
}

cSprite::cSprite(cSprite *psprite)
{
	copy(psprite);
}

cSprite cSprite::operator=(cSprite &csprite)
{
	if (this == &csprite)
		return *this;
	copy(&csprite); //Note that copy is virtual, so this works for child classes.
	return *this;
}

cSprite* cSprite::clone()
{
/* The purpose of this method is that we may later have various child classes
cSpriteChild of the cSprite class, and to truly copy a cSpriteChild, you need
a cSpriteChild* pointer and not a cSprite* pointer.  The following will
create a cSpriteyChild* pointer.  Even though we cast psprite into a cSprite*
pointer for the return, it "really" remains a cSpriteChild, and will use the
child classes overloads of any virtual methods. */  
	CRuntimeClass *pRuntimeClass = GetRuntimeClass();
	cSprite *psprite = (cSprite*)(pRuntimeClass->CreateObject());
	psprite->copy(this);
	psprite->setNewgeometryflag(TRUE);
	return psprite;
}

void cSprite::copy(cSprite *psprite)
{ 
	_radius = psprite->_radius;
	_prismdz = psprite->_prismdz;
	_spriteattitude = psprite->_spriteattitude;
	_resourceID = psprite->_resourceID;
	setColorStyle(psprite->pcolorstyle()->clone());
}

void cSprite::setRadius(Real newradius)
{
	_radius = newradius;
	setNewgeometryflag(TRUE);
}

Real cSprite::radius() const 
{
//	return _radius;
	return _spriteattitude.scalefactor()*_radius;
} /* Size of the sprite image's
		furthest point from center(). */

//============cSprite Mutators=================
void cSprite::mutate(int mutationflags, Real mutationstrength)
{	
	if (mutationflags & cSprite::MF_RADIUS)
		setRadius(cRandomizer::pinstance()->mutate(
			_radius, cCritter::MINRADIUS, cCritter::MAXRADIUS,
			mutationstrength)); 
	if (mutationflags & MF_ROTATION)
		rotate(cRandomizer::pinstance()->mutate(angle(), 0.0, PI, mutationstrength));
	_pcolorstyle->mutate(mutationflags, mutationstrength);
	_newgeometryflag = TRUE;
}

void cSprite::draw(cGraphics *pgraphics, int drawflags)
{ /* This is an example of the Template Method.  For the primitive (non-composite)
	 sprites we only overload the imagedraw method and use this template code. */
	if (drawflags & CPopView::DF_WIREFRAME && pgraphics->is3D())
	{
		if (IsKindOf(RUNTIME_CLASS(cSpriteQuake)))
		{
			cSpriteSphere sphere(_radius, 6, 6);
			sphere.setLineColor(cColorStyle::CN_BLACK);
			sphere.draw(pgraphics, drawflags);
		}
	}
	pgraphics->pushMatrix();
	pgraphics->multMatrix(_spriteattitude);
/* If I don't have UNCONDITIONAL_ADJUSTATTRIBUTES turned on in 
cGraphicsOpenGL, then I should actually call pgraphics->adjustAttributes(this);
right here instead of down inside the display list --- see the comment where
UNCONDITIONAL_ADJUSTATTRIBUTES is defined. */
	if (enabledisplaylist() && pgraphics->supportsDisplayList())
	{
		if (!pgraphics->activateDisplayList(this))/* If you plan to use display lists,
			look if one's ready, and if not, open one and draw into it. */
		{
			pgraphics->adjustAttributes(this); //See comment above.
			imagedraw(pgraphics, drawflags); 
		}
		pgraphics->callActiveDisplayList(this); //Now call the display list.
	}
	else //Not trying to use display lists for this kind of sprite.  Just draw it.
	{
		pgraphics->adjustAttributes(this); //See comment above.
		imagedraw(pgraphics, drawflags); 
	}
	pgraphics->popMatrix();
	//After the draw, tell the sprite that its current geometry has now been drawn once.
	setNewgeometryflag(FALSE); /* This is for use by the cGraphicsOpenGL for
		knowing when it may need to change any display list id being used for the sprites.  */
}

void cSprite::imagedraw(cGraphics *pgraphics, int drawflags)
{ 
 /*This is a default approach, just draws a circle. */
	cColorStyle tempcolorstyle(TRUE, TRUE, cColorStyle::CN_BLUE, 
		cColorStyle::CN_LIGHTGRAY, radius()/4.0);
		/* Params are filled, edged, fillcolor, linecolor,
		 linewidth, etc. */
	pgraphics->drawcircle(cVector::ZEROVECTOR, _radius,
		 &tempcolorstyle, drawflags);
}

//=====================cSpriteComposite overloads ===================
void cSpriteComposite::fixResourceID()
{
	_resourceID = -1;
	for (int i=0; i<_childspriteptr.GetSize(); i++)
		if (_childspriteptr.ElementAt(i)->resourceID()!=-1)
		{
			_resourceID = _childspriteptr.ElementAt(i)->resourceID();
			break;
		}
}

void cSpriteComposite::add(cSprite *psprite)
{
	_childspriteptr.Add(psprite);
	setNewgeometryflag(TRUE);
	fixResourceID();
}

void cSpriteComposite::add(int resourceid)
{
	add(new cSpriteIcon(resourceid));
	setNewgeometryflag(TRUE);
	fixResourceID();
}

void cSpriteComposite::changeMember(int index, cSprite *psprite)
{
	if (index < 0 || index >= _childspriteptr.GetSize())
		return;
	delete _childspriteptr[index];
	_childspriteptr.SetAt(index, psprite); 
	setNewgeometryflag(TRUE);
	fixResourceID();
}

cSpriteComposite::~cSpriteComposite()
{
	for (int i=0; i< _childspriteptr.GetSize(); i++)
		delete _childspriteptr[i];
}

void cSpriteComposite::copy(cSprite *psprite)
{ 
	cSprite::copy(psprite);
	for (int i=0; i< _childspriteptr.GetSize(); i++)
		delete _childspriteptr[i]; //If there happen to be any.
	_childspriteptr.SetSize(0);
	if (!psprite->IsKindOf(RUNTIME_CLASS(cSpriteComposite)))
		return; //You're done if psprite isn't a cSpriteComposite.
	cSpriteComposite *pspritecomposite = (cSpriteComposite *)psprite; /* I know it is a
		cSpriteComposite at this point, but I need to do a cast, so the compiler will 
		let me access it's cSpriteComposite member _childspriteptr. */
	for (i = 0; i < pspritecomposite->_childspriteptr.GetSize(); i++)
		add(pspritecomposite->_childspriteptr[i]->clone());
	setNewgeometryflag(TRUE);
}

void cSpriteComposite::Serialize(CArchive &ar)
{
	cSprite::Serialize(ar);
	if (ar.IsStoring()) //Writing data.
		_childspriteptr.Serialize(ar); /* Because _childspriteptr is a
		CTypedPtrArray<CObArray, cSprite*>, it will serialize pointers
		in the proper, "smart," way.  But see the Loadingn case just below...*/
	else //Loading
	{
		/* There's a catch here.  The constructor of the base cSpriteComposite quite likely
			has initialized the _childspriteptr array. This is what cSpriteBubble consturctor
			does for instnace.  So we have to empty out _childspriteptr before we serialize
			into it. */
		for (int i=0; i<_childspriteptr.GetSize(); i++)
		{
			delete _childspriteptr[i];
			_childspriteptr[i] = NULL;
		}
		_childspriteptr.RemoveAll();
		_childspriteptr.Serialize(ar); /* Because _childspriteptr is a
		CTypedPtrArray<CObArray, cSprite*>, we expect it to serialize pointers
		in the proper, "smart," way.*/
	}
}

Real cSpriteComposite::radius() const 
{
/* This is just a start of a method that we'll need to overload for the indivdiual cases.
For now, we view a cSpriteComposite as having the radius of its largest piece.  But often we
need to think about how the radii sum up with each other.  We do this in cPolyPolygon::radius() 
for instance, which is already overloaded from this. */
	Real maxchildradius = 0.0;
	for (int i=0; i< _childspriteptr.GetSize(); i++)
		if (_childspriteptr[i]->radius() > maxchildradius)
			maxchildradius = _childspriteptr[i]->radius();
	return _spriteattitude.scalefactor()*maxchildradius;
} 

//======== cSpriteComposite Mutators =========================
/* By default the mutators only affect the base sprite.  We might want to cascade the mutators
down to all the members of _childspriteptr, or maybe just to some of them.  We let the
cSpriteComposite child classes decide.  The two classes cSpriteLoop and cSpriteDirectional
inherit from the cSpriteComposite child cSpriteShowOneChild, and this class only cascades
things to one active sprite. */

void cSpriteComposite::setLineColor(COLORREF col)
{
	cSprite::setLineColor(col);
	for (int i=0; i< _childspriteptr.GetSize(); i++)
		 _childspriteptr[i]->setLineColor(col);
} 

void cSpriteComposite::setLineWidthWeight(Real linewidthweight)
{
	cSprite::setLineColor(linewidthweight);
	for (int i=0; i< _childspriteptr.GetSize(); i++)
		 _childspriteptr[i]->setLineWidthWeight(linewidthweight);
} 

void cSpriteComposite::setLineWidth(Real linewidth)
{
	cSprite::setLineColor(linewidth);
	for (int i=0; i< _childspriteptr.GetSize(); i++)
		 _childspriteptr[i]->setLineWidthWeight(linewidth);
} 

void cSpriteComposite::setFillColor(COLORREF col)
{
	cSprite::setLineColor(col);
	for (int i=0; i< _childspriteptr.GetSize(); i++)
		 _childspriteptr[i]->setFillColor(col);
} 

void cSpriteComposite::setEdged(BOOL onoff)
{
	cSprite::setEdged(onoff);
	for (int i=0; i< _childspriteptr.GetSize(); i++)
		 _childspriteptr[i]->setEdged(onoff);
} 

void cSpriteComposite::setFilled(BOOL onoff)
{
	cSprite::setFilled(onoff);
	for (int i=0; i< _childspriteptr.GetSize(); i++)
		 _childspriteptr[i]->setFilled(onoff);
} 

void cSpriteComposite::setNewgeometryflag(BOOL onoff)
{
	cSprite::setNewgeometryflag(onoff);
	for (int i=0; i< _childspriteptr.GetSize(); i++)
		_childspriteptr[i]->setNewgeometryflag(onoff);
} 

void cSpriteComposite::setPrismDz(Real prismdz)
{
	_prismdz = prismdz;
	Real scalefactor = _spriteattitude.scalefactor();
	ASSERT(scalefactor > SMALL_REAL);
	Real scaledprismdz = _prismdz / scalefactor;
		/* We divide by the scalefactor becuase, for a composite sprite, the
		attitude scales the whole assembly from the "outside," and we want
		the prismdz thickness to be aboslute. */
	for (int i=0; i< _childspriteptr.GetSize(); i++)
		_childspriteptr[i]->setPrismDz(scaledprismdz); 
	setNewgeometryflag(TRUE);
} 

void cSpriteComposite::setRadius(Real newradius)
{
	if (!newradius)
		return; //Don't allow zero radius.
	Real oldradius = radius();
	ASSERT(oldradius); //else it's hopeless
	Real scalefactor = newradius/oldradius;
	_spriteattitude *= cMatrix::scale(scalefactor);
	setPrismDz(_prismdz); /* We need to do this so that the prismdz thickness takes
		the new scalefactor into account. */
	setNewgeometryflag(TRUE);
}

//---------- cSpriteComposite Cascades ----------------
void cSpriteComposite::animate(Real dt, cCritter *powner)
{ 
	for (int i=0; i< _childspriteptr.GetSize(); i++)
		_childspriteptr[i]->animate(dt, powner);
}

void cSpriteComposite::draw(cGraphics *pgraphics, int drawflags)
{ /* Use the base _spriteattitude and then walk the array of child sprites and call their
	imagedraw methods.  Don't try and imagedraw the base cSprite, as it's only there to hold
	the _spriteattitude.  Note that the cSpriteShowOneChild child class only cascades 
	the imagedraw to one child. */
	pgraphics->pushMatrix();
	pgraphics->multMatrix(_spriteattitude);
		/* For now, let's not try and use display lists for the composites, but only for the
		individual pieces. */
	for (int i=0; i< _childspriteptr.GetSize(); i++)
		_childspriteptr[i]->draw(pgraphics, drawflags); //If there happen to be any.
		//If you don't want to draw the first sprite, like wiht a polypoly, start with i at 1,
	pgraphics->popMatrix();
}

