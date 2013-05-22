#include "stdafx.h"
#include "spritetexturebox.h"
#include "spritepolygon.h"
#include "spriteicon.h"
#include "graphics.h"
#include "popview.h"

IMPLEMENT_SERIAL(cSpriteTextureBox, cSprite, 0)

cSpriteTextureBox::cSpriteTextureBox(
		const cVector3 &locorner,
		const cVector3 &hicorner,
		int resourceID, int xtilecount):
	cSpriteComposite()
{
	_pskeleton = new cRealBox(locorner, hicorner);
	_initialize();
	if (resourceID != -1)
		setAllSidesTexture(resourceID, xtilecount);
}

void cSpriteTextureBox::setSkeleton(const cRealBox3 &skeleton)
{
	delete _pskeleton;
	_pskeleton = NULL;
	_pskeleton = new cRealBox(skeleton);
	_initialize(); //Puts default blank rectangles in each face.
}

cSpriteTextureBox::cSpriteTextureBox(
	cRealBox *pskeleton, int resourceID, int xtilecount):
	cSpriteComposite()
{
	_pskeleton = new cRealBox(pskeleton->locorner(),
			pskeleton->hicorner());
	_initialize();
	setAllSidesTexture(resourceID, xtilecount);
}

cSpriteTextureBox::~cSpriteTextureBox()
{
	delete _pskeleton;
}

void cSpriteTextureBox::_initialize()
{
	cSpriteRectangle *prect;
	for (int i=0; i< _childspriteptr.GetSize(); i++)
		delete _childspriteptr[i];
	_childspriteptr.RemoveAll();
	for (int boxside = 0; boxside < 6; boxside++)
//	for (int boxside = 0; boxside < 1; boxside++) //Used this instead for debuggin
		//Force in 6 sprites.
	switch(boxside)
	{
	case LOX:
		prect = new cSpriteRectangle(loy(), loz(), hiy(), hiz());
		add(prect);
		break;
	case HIX:
		prect = new cSpriteRectangle(loy(), loz(), hiy(), hiz());
		add(prect);
		break;
	case LOY:
		prect = new cSpriteRectangle(lox(), loz(), hix(), hiz());
		add(prect);
		break;
	case HIY:
		prect = new cSpriteRectangle(lox(), loz(), hix(), hiz());
		add(prect);
		break;
	case LOZ:
		prect = new cSpriteRectangle(lox(), loy(), hix(), hiy());
		add(prect);
		break;
	case HIZ:
	default:
		prect = new cSpriteRectangle(lox(), loy(), hix(), hiy());
		add(prect);
		break;
	}
//	prect->setColorStyle(pcolorstyle()->clone()); //Use the base class colorstyle.
	_fixspriteattitudes();
}

cSprite* cSpriteTextureBox::pside(int boxside)
{ 
	if (!(_childspriteptr.GetSize()>boxside))
		return NULL;
	return _childspriteptr[boxside];
}

void cSpriteTextureBox::setPlainRectangle(int boxside)
{
	if (!(_childspriteptr.GetSize()>boxside))
		return;
	delete _childspriteptr[boxside];
	cSpriteRectangle *prect;
	switch(boxside)
	{
	case LOX:
		prect = new cSpriteRectangle(loy(), loz(), hiy(), hiz());
		_childspriteptr.SetAt(boxside, prect);;
		break;
	case HIX:
		prect = new cSpriteRectangle(loy(), loz(), hiy(), hiz());
		_childspriteptr.SetAt(boxside, prect);;
		break;
	case LOY:
		prect = new cSpriteRectangle(lox(), loz(), hix(), hiz());
		_childspriteptr.SetAt(boxside, prect);;
		break;
	case HIY:
		prect = new cSpriteRectangle(lox(), loz(), hix(), hiz());
		_childspriteptr.SetAt(boxside, prect);;
		break;
	case LOZ:
		prect = new cSpriteRectangle(lox(), loy(), hix(), hiy());
		_childspriteptr.SetAt(boxside, prect);;
		break;
	case HIZ:
	default:
		prect = new cSpriteRectangle(lox(), loy(), hix(), hiy());
		_childspriteptr.SetAt(boxside, prect);;
		break;
	}
	prect->setColorStyle(pcolorstyle()->clone()); //Use the base class colorstyle.
	_fixspriteattitude(boxside);
	fixResourceID();
}

void cSpriteTextureBox::_fixspriteattitudes()
{
	for (int boxside=0; boxside<_childspriteptr.GetSize(); boxside++)
		_fixspriteattitude(boxside);
}

void cSpriteTextureBox::_fixspriteattitude(int boxside)
{
	/* Adjust each case so the z-axis direction faces out. */
	switch(boxside)
	{
	case LOX:
		_childspriteptr[0]->setSpriteAttitude(
			cMatrix::translation(cVector(lox(), midy(), midz())) *
				cMatrix::xRotation(-PI/2.0)*
				cMatrix::yRotation(PI/2.0)*
				cMatrix::zRotation(PI));
		break;
	case HIX:
		_childspriteptr[1]->setSpriteAttitude(
			cMatrix::translation(cVector(hix(), midy(), midz())) *
				cMatrix::xRotation(PI/2.0)*
				cMatrix::yRotation(PI/2.0));
		break;
	case LOY:
		_childspriteptr[2]->setSpriteAttitude(
			cMatrix::translation(cVector(midx(),loy(),midz())) *
				cMatrix::zRotation(PI/2.0) *
				cMatrix::yRotation(PI/2.0) *
				cMatrix::zRotation(PI/2.0)
				);
		break;
	case HIY:
		_childspriteptr[3]->setSpriteAttitude(
			cMatrix::translation(cVector(midx(), hiy(), midz())) *
				cMatrix::zRotation(3*PI/2.0) *
				cMatrix::yRotation(PI/2.0) *
				cMatrix::zRotation(PI/2.0)
				);
		break;
	case LOZ:
		_childspriteptr[4]->setSpriteAttitude(
			cMatrix::translation(cVector(midx(), midy(), loz())) *
			cMatrix::yRotation(PI));
		break;
	case HIZ:
		_childspriteptr[5]->setSpriteAttitude(
			cMatrix::translation(cVector(midx(), midy(), hiz())));
		break;
	}
}

void cSpriteTextureBox::setSideInvisible(int boxside)
{
	setPlainRectangle(boxside);
	_childspriteptr[boxside]->pcolorstyle()->setFilled(FALSE); 
	_childspriteptr[boxside]->pcolorstyle()->setEdged(FALSE); 
	fixResourceID();
}

void cSpriteTextureBox::setSideSolidColor(int boxside, COLORREF color)
{
	setPlainRectangle(boxside); //Copies the composite's colorstyle to the rect.
	_childspriteptr[boxside]->pcolorstyle()->setFillColor(color); 
	fixResourceID();
}

void cSpriteTextureBox::setSideColors(COLORREF color)
{
	for (int boxside=0; boxside<_childspriteptr.GetSize(); boxside++)
		_childspriteptr[boxside]->pcolorstyle()->setFillColor(color); 
}

void cSpriteTextureBox::setAllSidesTexture(int resourceID, int xtilecount)
{
	for (int i=0; i<_childspriteptr.GetSize(); i++)
		setSideTexture(i, resourceID, xtilecount);
	fixResourceID();
}

void cSpriteTextureBox::setSideTexture(int boxside, int resourceID, int
	xtilecount)
{
	if (boxside < 0 || boxside >= _childspriteptr.GetSize() || resourceID == -1)
		return;
	delete _childspriteptr[boxside];
	_childspriteptr.SetAt(boxside, 
		new cSpriteIconBackground(resourceID,
			_pskeleton->side(boxside), xtilecount)); 
	_fixspriteattitudes();
	_newgeometryflag = TRUE;
	fixResourceID();
}

void cSpriteTextureBox::draw(cGraphics *pgraphics, int drawflags)
{ /* Use the base _spriteattitude and then walk the array of child sprites and call their
	imagedraw methods.   */
	pgraphics->pushMatrix();
	pgraphics->multMatrix(_spriteattitude);
	if (!pgraphics->is3D() && (LOZ <= _childspriteptr.GetSize())) 
	{
		//Just draw bottom face for 2D, assuming your box has one.
		/* A complicating factor is that if the box isn't 
		aligned along the coordinate axes, if, for instance, 
		it's a textured wall, we can't properly draw the bottom
		face as a cSpriteBackground, as this won't be oriented
		properly */
		cSprite *pspritebottom = _childspriteptr[LOZ];
		if (pspritebottom->IsKindOf(RUNTIME_CLASS(cSpriteIcon)) &&
			! (drawflags & CPopView::DF_DRAWING_SKYBOX))
		{
			cSpriteIcon *pspriteicon = (cSpriteIcon*)pspritebottom;
			pspritebottom = new cSpriteRectangle(
				pspriteicon->locorner().x(),
				pspriteicon->locorner().y(),
				pspriteicon->hicorner().x(),
				pspriteicon->hicorner().y());
			pspritebottom->draw(pgraphics, drawflags); 
			delete pspritebottom;
		}
		else
			pspritebottom->draw(pgraphics, drawflags); 

	}
		//Otherwise you're in the expected 3D case.
	else
		for (int i=0; i< _childspriteptr.GetSize(); i++)
		_childspriteptr[i]->draw(pgraphics, drawflags); 
	pgraphics->popMatrix();
}

void cSpriteTextureBox::copy(cSprite *psprite) //Use this in copy constructor and operator=
{
	cSpriteComposite::copy(psprite);
	if (!psprite->IsKindOf(RUNTIME_CLASS(cSpriteTextureBox)))
		return; //You're done if psprite isn't a cSpriteTextureBox*.
	cSpriteTextureBox *ptexturebox = (cSpriteTextureBox *)(psprite); /* I know it is a
		cSpriteTextureBox at this point, but I need to do a cast, so the compiler will 
		let me call cSpriteTextureBox methods. */
	delete _pskeleton;
	_pskeleton = ptexturebox->_pskeleton->clone();
}	

void cSpriteTextureBox::Serialize(CArchive &ar)
{
/* We don't serialize _imageloaded, as that gets set when the texturebox is first drawn. */
	cSpriteComposite::Serialize(ar);
	if (ar.IsStoring()) //Writing data.
		ar << _pskeleton;
	else //Reading data.
	/* Whenever you  load into a pointer variable ptr, we have to call delete on the pointer 
	first, otherwise we'll have a memory leak caused by the "orphaned" object that the pointer
	pointed to before you overwrote it with the load. */
	{
		delete _pskeleton;
		ar >> _pskeleton;
	}
}
