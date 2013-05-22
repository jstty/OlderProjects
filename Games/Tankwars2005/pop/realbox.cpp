#include "stdafx.h"
#include "realbox.h"
#include "randomizer.h" //For cRandomizer in randomVector
#include "graphics.h"
#include "spritepolygon.h"
#include "critter.h"
#include "popview.h" //For DF_ flags

IMPLEMENT_SERIAL(cRealBox2, CObject, 0);
IMPLEMENT_SERIAL(cRealBox3, CObject, 0);

Real cRealBox2::MINSIZE = 0.001; 
Real cRealBox3::MINSIZE = 0.001; /*It messes up our outcode computations for surface points 
	if we can have boxes with any degenerate 0 size, so we enforce a minimum
	of about a thousandth. We need to remember this in our cCritter::in3DWorld()
	code. */

//----TWO DIMENSIONAL -----
//Private field mutators================
void cRealBox2::_arrange()
{ //Helper function
	Real temp;
	if (_lox > _hix)
	{
		temp = _lox;
		_lox = _hix;
		_hix = temp;
	}
	if (_loy > _hiy)  //In Real land loy IS < hiy.
	{
		temp = _loy;
		_loy = _hiy;
		_hiy = temp;
	}
	if (_lox == _hix)
	{
		_lox -= 0.5*cRealBox2::MINSIZE;
		_hix += 0.5*cRealBox2::MINSIZE;
	}
	if (_loy == _hiy)
	{
		_loy -= 0.5*cRealBox2::MINSIZE;
		_hiy += 0.5*cRealBox2::MINSIZE;
	}
}

void cRealBox2::_initialize(Real px, Real py, Real qx, Real qy)
{
	_lox = px;
	_loy = py;
	_hix = qx;
	_hiy = qy;
	_arrange();
}

void cRealBox2::_copy(const cRealBox2 &box)
{
	_initialize(box.lox(), box.loy(), box.hix(), box.hiy());
}

void cRealBox2::_copy(const cRealBox3 &box)
{
	_initialize(box.lox(), box.loy(), box.hix(), box.hiy());
}

void cRealBox2::_copy(cRealBox2 *pbox)
{
	_initialize(pbox->lox(), pbox->loy(), pbox->hix(), pbox->hiy());
}

void cRealBox2::_copy(cRealBox3 *pbox)
{
	_initialize(pbox->lox(), pbox->loy(), pbox->hix(), pbox->hiy());
}


//==============Constructors===============

cRealBox2::cRealBox2(Real xsize, Real ysize, Real zsize)
{
	set(xsize, ysize, zsize);
}

cRealBox2::cRealBox2(Real lox, Real loy, Real hix, Real hiy)
{
	_initialize(lox, loy, hix, hiy);
}

cRealBox2::cRealBox2(const cVector2 &locorner, const cVector2 &hicorner)
{
	set(locorner, hicorner);
}

cRealBox2::cRealBox2(const cVector2 &center, Real xsize,
	Real ysize, Real zsize)
{
	set(center, xsize, ysize, zsize);
}

cRealBox2::cRealBox2(const cVector2 &center, Real edge)
{
	set(center, edge, edge);
}

void cRealBox2::Serialize(CArchive &ar)
{
	if (ar.IsStoring()) //Writing data.
		ar << _lox << _hix << _loy << _hiy;
	else //Reading data.
	{
		ar >> _lox >> _hix >> _loy >> _hiy;
	}
}

CArchive& operator<<(CArchive& ar, cRealBox2 &realbox)
{
	realbox.Serialize(ar);
	return ar;
}

CArchive& operator>>(CArchive& ar, cRealBox2 &realbox)
{
	realbox.Serialize(ar);
	return ar;
}

//Field Mutators===================

void cRealBox2::set(const cVector2 &locorner, const cVector2 &hicorner)
{
	_initialize(locorner.x(), locorner.y(), hicorner.x(), hicorner.y());
}

void cRealBox2::set(const cVector2 &center, Real xsize, Real ysize, Real zsize)
{
	if (xsize < 0.0)
		xsize = -xsize;
	if (ysize < 0.0)
		ysize = -ysize;
	Real lox, loy, hix, hiy;
	lox = center.x() - xsize/2.0;
	loy = center.y() - ysize/2.0;
	hix = center.x() + xsize/2.0;
	hiy = center.y() + ysize/2.0;
	_initialize(lox, loy, hix, hiy);
}

void cRealBox2::set(Real xsize, Real ysize, Real zsize)
{
	set(cVector2::ZEROVECTOR, xsize, ysize, zsize);
}

//Mutators

void cRealBox2::matchAspect(int cx, int cy)
{
	Real oldaspect, newaspect, centery;

	if (!(_hiy - _loy) || !cy)
		return;
	oldaspect = (_hix - _lox)/(_hiy - _loy);
	if (!oldaspect)
		return;
	newaspect = (Real)cx/(Real)cy;
	if (!newaspect)
		return;
	centery = (_hiy - _loy)/2.0;
	//stretch or shrink the box vertically
	_hiy = centery + (oldaspect/newaspect)*(_hiy - centery);
	_loy = centery - (oldaspect/newaspect)*(centery - _loy);
/*  If we instead wanted to stretch or shrink the box horizontally:
	_hix = centerx + (newaspect/oldaspect)*(_hix - centerx);
	_lox = centerx - (newaspect/oldaspect)*(centerx - _lox);
*/
}

cRealBox2 cRealBox2::innerBox(Real radius)const
{ // Return a box offset inward by radius
	Real xoffset, yoffset;
	xoffset = yoffset = radius;
	CLAMP(xoffset, 0.0, xsize()/2.0); //Don't offset further than there's room for.
	CLAMP(yoffset, 0.0, ysize()/2.0); 
	cRealBox2 returnbox(*this);
	returnbox._initialize(_lox+xoffset, _loy+yoffset, _hix-xoffset, _hiy-yoffset);
	return returnbox;
}

cRealBox2 cRealBox2::outerBox(Real radius)const
{ // Return a box offset outward by radius
	cRealBox2 returnbox(*this);
	returnbox._initialize(_lox-radius, _loy-radius, _hix+radius, _hiy+radius);
	return returnbox;
}

cVector2 cRealBox2::randomVector()const
{
	return cVector2(cRandomizer::pinstance()->randomReal(_lox, _hix),
		cRandomizer::pinstance()->randomReal(_loy, _hiy));
}

BOOL cRealBox2::inside(const cVector2 &testpos)const
{
/* We prefer to think of the surface as still outside. */
	return (_lox < testpos.x() && testpos.x() < _hix &&
		_loy < testpos.y() && testpos.y() < _hiy);
}

int cRealBox2::outcode(const cVector2 &testpos) const
{ /* This tells you which of the nine possible positions testpos has
relative to the cRealBox2.  We think of the surface as outside.*/
	int outcode = BOX_INSIDE; //This is 0.

	if (testpos.x() <= _lox)
		outcode |= BOX_LOX;
	if (testpos.x() >= _hix)
		outcode |= BOX_HIX;
	if (testpos.y() <= _loy)
		outcode |= BOX_LOY;
	if (testpos.y() >= _hiy)
		outcode |= BOX_HIY;
	return outcode;
}

Real cRealBox2::distanceTo(const cVector2 &testpos) const
{
	int dummy;
	return distanceToOutcode(testpos, dummy);
}

Real cRealBox2::distanceToOutcode(const cVector2 &testpos, int &posoutcode) const
{ /*This gives the distance from testpos to the closest point of the
cRealBox3.  If you are in a "side" zone your nearest distance is a point
on the side.  If you are in a "corner" zone your nearest distance is a
corner.  If you are inside, we call the distance 0.*/
	posoutcode = outcode(testpos);
	Real dx, dy;
	dx=dy=0.0;
	if (posoutcode & BOX_LOX)
		dx = _lox - testpos.x();
	if (posoutcode & BOX_HIX)
		dx = testpos.x() - _hix;
	if (posoutcode & BOX_LOY)
		dy = _loy - testpos.y();
	if (posoutcode & BOX_HIY)
		dy = testpos.y() - _hiy;
	return sqrt(dx*dx + dy*dy);
}

Real cRealBox2::maxDistanceToCorner(const cVector2 &testpos) const
{ /*This gives the distance from testpos to the furthest corner of the
cRealBox2. */
	int posoutcode = outcode(testpos);
	Real dx, dy;
	if (posoutcode & BOX_LOX)
		dx = _hix - testpos.x();
	else if (posoutcode & BOX_HIX)
		dx = testpos.x() - _lox;
	else
		dx = __max(testpos.x() - _lox, _hix - testpos.x());
	if (posoutcode & BOX_LOY)
		dy = _hiy - testpos.y();
	else if (posoutcode & BOX_HIY)
		dy = testpos.y() - _loy;
	else
		dy = __max(testpos.y() - _loy, _hiy - testpos.y());
	return sqrt(dx*dx + dy*dy);
}

cVector2 cRealBox2::corner(int i)const
{
	ASSERT(0 <= i && i <= 3);
	switch(i)
	{
		case 0:
			return cVector2(_lox, _loy);
		case 1:
			return cVector2(_lox, _hiy);
		case 2:
			return cVector2(_hix, _loy);
		default: //case 3
			return cVector2(_hix, _hiy);
	}
}

int cRealBox2::wrap(cVector2 &position) const
{
	int outcode = BOX_INSIDE;
	if (position.x() <= _lox)
	{
		outcode |= BOX_LOX;
		position.set(_hix - _lox + position.x(), position.y());
	}
	if (position.x() >= _hix)
	{
		outcode |= BOX_HIX;
		position.set(_lox - _hix + position.x(), position.y());
	}
	if (position.y() <= _loy)
	{
		outcode |= BOX_LOY;
		position.set(position.x(), _hiy - _loy + position.y());
	}
	if (position.y() >= _hiy)
	{
		outcode |= BOX_HIY;
		position.set(position.x(), _loy - _hiy + position.y());
	}
	return outcode;
}

int cRealBox2::wrap(cVector2 &position, cVector2 &wrapposition1,
	 cVector2 &wrapposition2, cVector2 &wrapposition3, Real radius) const
{
	wrapposition3 = wrapposition2 = wrapposition1 = position;
	int outcode = wrap(position);
	cRealBox2 smallbox = this->innerBox(radius);
//First wrap the x
	if (position.x() <= smallbox._lox)
	{
		outcode |= BOX_LOX;
		wrapposition1.set(_hix - _lox + position.x(),position.y());
	}
	if (position.x() >= smallbox._hix)
	{
		outcode |= BOX_HIX;
		wrapposition1.set(_lox - _hix + position.x(), position.y());
	}
//If there's no x wrap, wrap the y for wrapposition1
	if (wrapposition1 == position)
	{
		if (position.y() <= smallbox._loy)
		{
			outcode |= BOX_LOY;
			wrapposition1.set(position.x(), _hiy - _loy + position.y());
		}
		if (position.y() >= smallbox._hiy)
		{
			outcode |= BOX_HIY;
			wrapposition1.set(position.x(), _loy - _hiy + position.y());
		}
	}
//If there's x wrap in wrapposition1, do the y wrap of position and wrapposition1
	else //wrapposition1 not equal to position
	{
		if (position.y() <= smallbox._loy)
		{
			outcode |= BOX_LOY;
			wrapposition2.set(position.x(), _hiy - _loy + position.y());
			wrapposition3.set(wrapposition1.x(), _hiy - _loy + position.y());
		}
		if (position.y() >= smallbox._hiy)
		{
			outcode |= BOX_HIY;
			wrapposition2.set(position.x(), _loy - _hiy + position.y());
			wrapposition3.set(wrapposition1.x(), _loy - _hiy + position.y());
		}
	}
	//Don't bother doing this for z.
	return outcode;
}

int cRealBox2::clamp(cVector2 &position) const
{
	int outcode = BOX_INSIDE;
	if (position.x() < _lox)
	{
		outcode |= BOX_LOX;
		position.set(_lox, position.y());
	}
	if (position.x() > _hix)
	{
		outcode |= BOX_HIX;
		position.set(_hix, position.y());
	}
	if (position.y() < _loy)
	{
		outcode |= BOX_LOY;
		position.set(position.x(), _loy);
	}
	if (position.y() > _hiy)
	{
		outcode |= BOX_HIY;
		position.set(position.x(), _hiy);
	}
	return outcode;
}

int cRealBox2::clamp(cVector2 &position, cVector2 &velocity) const
{
	int outcode = clamp(position);
	if (outcode & BOX_LOX) //If you hit a LO X wall, zero out any neg X velocity.
		velocity.set(__max(0.0, velocity.x()), velocity.y());
	if (outcode & BOX_HIX) //If you hit an HI X wall, zero out any pos X velocity.
		velocity.set(__min(0.0, velocity.x()), velocity.y());
	if (outcode & BOX_LOY) //Same deal for Y.
		velocity.set( velocity.x(), __max(0.0, velocity.y()) );
	if (outcode & BOX_HIY) 
		velocity.set( velocity.x(), __min(0.0, velocity.y()) );
	return outcode;
}

int cRealBox2::addBounce(cVector2 &position, cVector2 &velocity, Real bounciness)const
{
	int outcode = BOX_INSIDE;

	position += velocity;
	/* The basic idea is to reverse appropriate velocity component if you've passed an edge,
	and reflect the motion past the edge into motion away from the edge.  Reflection means
	at the right newx would be _hix - (position.x()-_hix), or 2*_hix - position.x()
	and at the newx would be _lox + (_lox - position.x()), or 2*_lox - position.x(). 
		Now add in the notion of a bounciness between 0.0 and 1.0.  First of all the
	reflected newvel is attentuated to -bounciness*oldvel.  Second, the reflected
	position should take into account the fact that the object is moving slower after
	the reflection, so we get, on the right, 
	newx  = _hix - bounciness*(position.x()-_hix) and on the left 
	newx = _lox + bounciness*(_lox - position.x())	*/
#ifdef USEBOUNCINESS
	if (position.x() >= _hix)
	{
		velocity.set(-bounciness*velocity.x(), velocity.y());
		position.set(_hix - bounciness*(position.x()-_hix), position.y());
		outcode |= BOX_HIX;
	}
	if (position.x() <= _lox)
	{
     	velocity.set(-bounciness*velocity.x(), velocity.y());
		position.set(_lox - bounciness*(position.x()-_lox), position.y());
		outcode |= BOX_LOX;
	}
	if (position.y() >= _hiy)
	{
     	velocity.set(velocity.x(), -bounciness*velocity.y());
		position.set(position.x(), _hiy - bounciness*(position.y()-_hiy));
		outcode |= BOX_HIY;
	}
	if (position.y() <= _loy)
	{
     	velocity.set(velocity.x(), -bounciness*velocity.y());
		position.set(position.x(), _loy - bounciness*(position.y()-_loy));
		outcode |= BOX_LOY;
	}
	if (outcode != BOX_INSIDE)
		clamp(position); /* Just so some screwy high velocity bounce can't 
			leave you outside the box */
    return outcode;
#else //old way, not USEBOUNCINESS
	if (position.x() >= _hix)
	{
		velocity.set(-velocity.x(), velocity.y());
		position.set(2*_hix - position.x(), position.y());
		outcode |= BOX_HIX;
	}
	if (position.x() <= _lox)
	{
     	velocity.set(-velocity.x(), velocity.y());
		position.set(2*_lox - position.x(), position.y());
		outcode |= BOX_LOX;
	}
	if (position.y() >= _hiy)
	{
     	velocity.set(velocity.x(), -velocity.y());
		position.set(position.x(), 2*_hiy - position.y());
		outcode |= BOX_HIY;
	}
	if (position.y() <= _loy )
	{
     	velocity.set(velocity.x(), -velocity.y());
		position.set(position.x(), 2*_loy - position.y());
		outcode |= BOX_LOY;
	}
	if (outcode != BOX_INSIDE)
		clamp(position); /* Just so some screwy high velocity bounce can't 
			leave you outside the box */
    return outcode;
#endif //USEBOUNCINESS
}

int cRealBox2::addBounce(cVector2 &position, cVector2 &velocity, Real bounciness, Real dt)const
{
	if (fabs(dt)<SMALL_REAL)
		return BOX_INSIDE; //You're not moving.
	cVector2 dtvelocity = dt*velocity;
	int outcode = addBounce(position, dtvelocity, bounciness);
	velocity = dtvelocity/dt;
	return outcode;
}

/*CRect cRealBox2::realToPixel(const cRealPixelConverter &crealpixelconverter)const
{
	int left, top, right, bottom;	
	crealpixelconverter.realToPixel(_lox, _loy, &left, &bottom);
	crealpixelconverter.realToPixel(_hix, _hiy, &right, &top);
	return CRect(left, top, right, bottom);
}
*/

void cRealBox2::draw(cGraphics *pgraphics, int drawflags)
{ 
	cColorStyle dummy;
	pgraphics->drawXYrectangle(locorner(), hicorner(), &dummy, drawflags);
}

cRealBox2 operator*(Real scale, const cRealBox2 &box)
{
	return cRealBox2(box.center(), scale*box.xsize(),
		scale*box.ysize());
}

BOOL operator==(const cRealBox2 arect, const cRealBox2 brect)
{
	return (arect._lox==brect._lox && arect._loy==brect._loy && 
		arect._hix==brect._hix && arect._hiy==brect._hiy);
}

BOOL operator!=(const cRealBox2 arect, const cRealBox2 brect)
{ return !(arect==brect);}

//3D =============================================================

//Private field mutators================
void cRealBox3::_arrange()
{ //Helper function
	Real temp;
	if (_lox > _hix)
	{
		temp = _lox;
		_lox = _hix;
		_hix = temp;
	}
	if (_loy > _hiy)  
	{
		temp = _loy;
		_loy = _hiy;
		_hiy = temp;
	}
	if (_loz > _hiz)  
	{
		temp = _loz;
		_loz = _hiz;
		_hiz = temp;
	}
	if (_lox == _hix)
	{
		_lox -= 0.5*cRealBox3::MINSIZE;
		_hix += 0.5*cRealBox3::MINSIZE;
	}
	if (_loy == _hiy)
	{
		_loy -= 0.5*cRealBox3::MINSIZE;
		_hiy += 0.5*cRealBox3::MINSIZE;
	}
	if (_loz == _hiz)
	{
		_loz -= 0.5*cRealBox3::MINSIZE;
		_hiz += 0.5*cRealBox3::MINSIZE;
	}
}

void cRealBox3::_initialize(Real px, Real py, Real pz, Real qx, Real qy, Real qz)
{
	_lox = px;
	_loy = py;
	_loz = pz;
	_hix = qx;
	_hiy = qy;
	_hiz = qz;
	_arrange();
}

void cRealBox3::_copy(const cRealBox2 &box)
{
	_initialize(box.lox(), box.loy(), 0.0, box.hix(), box.hiy(), 0.0);
}

void cRealBox3::_copy(const cRealBox3 &box)
{
	_initialize(box.lox(), box.loy(), box.loz(), box.hix(), box.hiy(), box.hiz());
}

void cRealBox3::_copy(cRealBox2 *pbox)
{
	_initialize(pbox->lox(), pbox->loy(), 0, pbox->hix(), pbox->hiy(), 0);
}

void cRealBox3::_copy(cRealBox3 *pbox)
{
	_initialize(pbox->lox(), pbox->loy(), pbox->loz(), pbox->hix(), pbox->hiy(), pbox->hiz());
}

//==============Constructors===============

cRealBox3::cRealBox3(Real xsize, Real ysize, Real zsize)
{
	set(xsize, ysize, zsize);
}

cRealBox3::cRealBox3(const cVector3 &locorner, const cVector3 &hicorner)
{
	set(locorner, hicorner);
}

cRealBox3::cRealBox3(const cVector3 &center, Real xsize,
	Real ysize, Real zsize)
{
	set(center, xsize, ysize, zsize);
}

cRealBox3::cRealBox3(const cVector3 &center, Real edge)
{
	set(center, edge, edge, edge);
}

void cRealBox3::Serialize(CArchive &ar)
{
	if (ar.IsStoring()) //Writing data.
		ar << _lox << _hix << _loy << _hiy << _loz << _hiz;
	else //Reading data.
	{
		ar >> _lox >> _hix >> _loy >> _hiy >> _loz >> _hiz;
	}
}

CArchive& operator<<(CArchive& ar, cRealBox3 &realbox)
{
	realbox.Serialize(ar);
	return ar;
}

CArchive& operator>>(CArchive& ar, cRealBox3 &realbox)
{
	realbox.Serialize(ar);
	return ar;
}

//Field Mutators===================

void cRealBox3::set(const cVector3 &locorner, const cVector3 &hicorner)
{
	_initialize(locorner.x(), locorner.y(), locorner.z(), hicorner.x(), hicorner.y(), hicorner.z());
}

void cRealBox3::set(const cVector3 &center, Real xsize, Real ysize, Real zsize)
{
	if (xsize < 0.0)
		xsize = -xsize;
	if (ysize < 0.0)
		ysize = -ysize;
	if (zsize < 0.0)
		zsize = -zsize;
	Real lox, loy, hix, hiy, loz, hiz;
	lox = center.x() - xsize/2.0;
	loy = center.y() - ysize/2.0;
	loz = center.z() - zsize/2.0;
	hix = center.x() + xsize/2.0;
	hiy = center.y() + ysize/2.0;
	hiz = center.z() + zsize/2.0;
	_initialize(lox, loy, loz, hix, hiy, hiz);
}

void cRealBox3::set(Real xsize, Real ysize, Real zsize)
{
	set(cVector3::ZEROVECTOR, xsize, ysize, zsize);
}

//Other mutators  

void cRealBox3::matchAspect(int cx, int cy)
{
	Real oldaspect, newaspect, centery;

	if (!(_hiy - _loy) || !cy)
		return;
	oldaspect = (_hix - _lox)/(_hiy - _loy);
	if (!oldaspect)
		return;
	newaspect = (Real)cx/(Real)cy;
	if (!newaspect)
		return;
	centery = (_hiy - _loy)/2.0;
	//stretch or shrink the box vertically
	_hiy = centery + (oldaspect/newaspect)*(_hiy - centery);
	_loy = centery - (oldaspect/newaspect)*(centery - _loy);
/*  If we instead wanted to stretch or shrink the box horizontally:
	_hix = centerx + (newaspect/oldaspect)*(_hix - centerx);
	_lox = centerx - (newaspect/oldaspect)*(centerx - _lox);
*/
}

Real cRealBox3::minsize()const
{
	if (zsize())
		return __min(__min(xsize(), ysize()), zsize());
	else
		return __min(xsize(), ysize());
}

cRealBox3 cRealBox3::innerBox(Real radius)const
{ // Return a box offset inward by radius, but don't offset more than would fit.
	Real xoffset, yoffset, zoffset;
	xoffset = yoffset = zoffset = radius;
	CLAMP(xoffset, 0.0, xsize()/2.0); //Don't offset further than there's room for.
	CLAMP(yoffset, 0.0, ysize()/2.0); 
	CLAMP(zoffset, 0.0, zsize()/2.0); 
	cRealBox3 returnbox(*this);
	returnbox._initialize(_lox+xoffset, _loy+yoffset, _loz+zoffset,
		_hix-xoffset, _hiy-yoffset, _hiz-zoffset);
	return returnbox;
}

cRealBox3 cRealBox3::outerBox(Real radius)const
{ // Return a box offset outward by radius
	cRealBox3 returnbox(*this);
	returnbox._initialize(_lox-radius, _loy-radius, _loz-radius,
		 _hix+radius, _hiy+radius, _hiz+radius);
	return returnbox;
}

cRealBox2 cRealBox3::side(int iside)
{
	switch(iside) 
	{
		case LOX:
		case HIX:
			return (cRealBox2(_loy, _loz, _hiy, _hiz));
		case LOY:
		case HIY:
			return (cRealBox2(_lox, _loz, _hix, _hiz));
		case LOZ:
		case HIZ:
		default:
			return (cRealBox2(_lox, _loy, _hix, _hiy));
	}			
}


cVector3 cRealBox3::randomVector()const
{
	return cVector3(cRandomizer::pinstance()->randomReal(_lox, _hix),
	 cRandomizer::pinstance()->randomReal(_loy, _hiy),
	 cRandomizer::pinstance()->randomReal(_loz, _hiz));
}

BOOL cRealBox3::inside(const cVector3 &testpos)const
{
	return (_lox < testpos.x() && testpos.x() < _hix &&
		_loy < testpos.y() && testpos.y() < _hiy &&
		_loz < testpos.z() && testpos.z() < _hiz );
}

int cRealBox3::outcode(const cVector3 &testpos) const
{ /* This tells you which of the nine possible positions testpos has
relative to the cRealBox3 */
	int outcode = BOX_INSIDE; //This is 0.

	if (testpos.x() <= _lox)
		outcode |= BOX_LOX;
	if (testpos.x() >= _hix)
		outcode |= BOX_HIX;
	if (testpos.y() <= _loy)
		outcode |= BOX_LOY;
	if (testpos.y() >= _hiy)
		outcode |= BOX_HIY;
	if (testpos.z() <= _loz)
		outcode |= BOX_LOZ;
	if (testpos.z() >= _hiz)
		outcode |= BOX_HIZ;
	return outcode;
}

Real cRealBox3::distanceTo(const cVector3 &testpos) const
{
	int dummy;
	return distanceToOutcode(testpos, dummy);
}

Real cRealBox3::distanceToOutcode(const cVector3 &testpos, int &posoutcode) const
{ /*This gives the distance from testpos to the closest point of the
cRealBox3.  If you are in a "side" zone your nearest distance is a point
on the side.  If you are in a "corner" zone your nearest distance is a
corner.  If you are inside, we call the distance 0.*/
	posoutcode = outcode(testpos);
	Real dx, dy, dz;
	dx=dy=dz=0.0;
	if (posoutcode & BOX_LOX)
		dx = _lox - testpos.x();
	if (posoutcode & BOX_HIX)
		dx = testpos.x() - _hix;
	if (posoutcode & BOX_LOY)
		dy = _loy - testpos.y();
	if (posoutcode & BOX_HIY)
		dy = testpos.y() - _hiy;
	if (posoutcode & BOX_LOZ)
		dz = _loz - testpos.z();
	if (posoutcode & BOX_HIZ)
		dz = testpos.z() - _hiz;
	return sqrt(dx*dx + dy*dy + dz*dz);
}

cVector3 cRealBox3::closestSurfacePoint(cVector oldpos, 
	int oldoutcode, cVector newpos, int newoutcode,
	BOOL crossedwall)const
{
		/* closestSurfacePoint will move the newpos
		from the far new side (or inside, or overlapping) of the box back to 
		the surface on the old near	side, edge, or corner given by oldoutcode.
		This would prevent going through the wall, but it isn't quite satisfactory
		in the following case:
			If oldoutcode is a corner position and you are in fact heading
		towards a face near the corner, our method bounces you off the corner
		even though visually you can see you should bounce off the
		face.  This has the effect of making a scooter player get hung up on
		a corner sometimes.
			So to avoid this situation, we consider change oldoutcode before
		we start, if oldoutcode is in a corner or edge zone, we can pick a
		surface point on the side that the critter meant to get to.  */
//We do an if condition here, starting with newpos not being inside.
	if ((newoutcode != BOX_INSIDE) && !crossedwall && (oldoutcode != BOX_INSIDE) &&
		!isFaceOutcode(oldoutcode))
				/*If we're in a mild case, with newoutcode  reasonable, 
				we'll use newoutcode if oldoutcode is corneror edge.
				we'll use newoutcode whenever oldoutcode is corner or edge.
				This will prevent getting hung up on corners.
				Go ahead and move out of the corner or edge zone and use the
				the closest surface point to the newpos in the newoutcode zone.
				I have found that if I do this in gameAirHockey I can drag
				the player thorugh the goal wall, so I have a kludge fix
				in cCritterWall::collide, to pass in crossedwall = FALSE
				whenever the listener is a cListerCursor */
			oldoutcode = newoutcode;
		/* Base your surface point on the newpos so you can slide along.
		 I worry about case where we crossedwall, tho.  In this case we'll still
		be using the unchanged oldoutcode, so the surface point we get 
		from newpos should still be on the correct side of the box. 
		Should I even so set newpos to oldpos in the crossedwall case?
		Turns out, NO, I shouoldn't because if I do, then when I try and
		scoot my player along a wall, he doesn't budge, as his newpos is
		always on the otherside of the wall.  */
	Real px = newpos.x(), py = newpos.y(), pz = newpos.z();
	if (oldoutcode & BOX_LOX)
		px = _lox;
	if (oldoutcode & BOX_HIX)
		px = _hix;
	if (oldoutcode & BOX_LOY)
		py = _loy;
	if (oldoutcode & BOX_HIY)
		py = _hiy;
	if (oldoutcode & BOX_LOZ)
		pz = _loz;
	if (oldoutcode & BOX_HIZ)
		pz = _hiz;
	if (oldoutcode != BOX_INSIDE) //You've already hit one of the cases
		return cVector(px, py, pz);
		//Otherwise you're in a pathological case where the oldoutcode was
		//inside.  You need to find a point on the surface.
		//I never enter the following code as of Feb, 2004,because when I call this
		//method from cCritterWall, I've alrady fixed oldoutcode if it was INSIDE.
	Real mindist, newmindist;
	newmindist = mindist = fabs(px - _lox);
	cVector ev(-newmindist, 0, 0);
	if ((newmindist = fabs(px - _hix)) < mindist)
	{
		ev.set(newmindist,0,0);
		mindist = newmindist;
	}
	if ((newmindist = fabs(py - _loy)) < mindist)
	{
		ev.set(0,-newmindist,0);
		mindist = newmindist;
	}
	if ((newmindist = fabs(py - _hiy)) < mindist)
	{
		ev.set(0,newmindist,0);
		mindist = newmindist;
	}
	if ((newmindist = fabs(pz - _loz)) < mindist)
	{
		ev.set(0,0,-newmindist);
		mindist = newmindist;
	}
	if ((newmindist = fabs(pz - _hiz)) < mindist)
	{
		ev.set(0,0,newmindist);
		mindist = newmindist;
	}
	return newpos + ev;
}

cVector3 cRealBox3::escapeVector(const cVector3 &testpos, int posoutcode)const
{
	if (posoutcode == BOX_INVALIDOUTCODE)
		posoutcode = outcode(testpos);
	cVector3 escape;
	cVector3 surfacepoint = closestSurfacePoint(testpos, posoutcode, testpos,
		posoutcode, FALSE);
	if (surfacepoint != testpos)
	{
		if (posoutcode != BOX_INSIDE)
			escape = testpos - surfacepoint;
		else
			escape = surfacepoint - testpos;
		return escape.normalize();
	}
	//surfacepoint == testpos case
	Real ex = 0, ey = 0, ez = 0;
	if (posoutcode & BOX_LOX)
		ex = -1;
	if (posoutcode & BOX_HIX)
		ex = 1;
	if (posoutcode & BOX_LOY)
		ey = -1;
	if (posoutcode & BOX_HIY)
		ey = 1;
	if (posoutcode & BOX_LOZ)
		ez = -1;
	if (posoutcode & BOX_HIZ)
		ez = 1;
	escape.set(ex, ey, ez);
	return escape.normalize();
}

void cRealBox3::reflect(cVector3 &velocity, int posoutcode)const
{
/* The idea here is that we have a critter with posoutcode hitting this cRealBox from the
outside with a velocity and we want to reflect the velocity off the box.  Idea is
to combine two or three reflections if you hit an edge or a corner. Assume you already
calculated posoutcode. Be sure to use the fabs function in the code as every now and then
the velocity will in fact be pointing the wrong way due to other collisions. 
	Added Feb 22, 2004: My player is getting hung up trying to bounce off
edges of 3D Walls. This is because if, for instance, I'm bouncing off an 
xz edge, my old code reversed both vx and vz, and if vy happens to be 0,
this means you reverse your velocity no matter what angle you hit the edge 
from.  I'm going to try only reversing the SMALLER of the two components
at edges, and the SMALLEST of the three at corners.   My approach is to 
keep only the outcode flag of the smallest velocity component, and then
do the outcode-based component changes.*/

	Real vx = velocity.x(), vy = velocity.y(), vz = velocity.z();
	Real avx = fabs(vx), avy = fabs(vy), avz = fabs(vz);
//xyz corner
	if ((posoutcode & BOX_X) && (posoutcode & BOX_Y) && (posoutcode & BOX_Z))
	{
		Real minval = avx;
		if (avy < minval)
			minval = avy;
		if (avz < minval)
			minval = avz;
		if (avx == minval)
		{
			posoutcode &= ~BOX_Y; //Ignore the Y collide
			posoutcode &= ~BOX_Z; //Ignore the Z collide
		}
		else if (avy == minval)
		{
			posoutcode &= ~BOX_X; //Ignore the X collide
			posoutcode &= ~BOX_Z; //Ignore the Z collide
		}
		else
		{
			posoutcode &= ~BOX_X; //Ignore the X collide
			posoutcode &= ~BOX_Y; //Ignore the Y collide
		}
	}
//xy edge
	else if ((posoutcode & BOX_X) && (posoutcode & BOX_Y))
	{
		if (avx < avy)
			posoutcode &= ~BOX_Y; //Ignore the Y collide
		else
			posoutcode &= ~BOX_X; //Ignore the X collide
	}
//xz edge
	else if ((posoutcode & BOX_X) && (posoutcode & BOX_Z))
	{
		if (avx < avz)
			posoutcode &= ~BOX_Z; //Ignore the Z collide
		else
			posoutcode &= ~BOX_X; //Ignore the X collide
	}
//yz edge
	else if ((posoutcode & BOX_Y) && (posoutcode & BOX_Z))
	{
		if (avy < avz)
			posoutcode &= ~BOX_Z; //Ignore the Z collide
		else
			posoutcode &= ~BOX_Y; //Ignore the Y collide
	}
//Now do the bounce by changing one velocity component.  Rather than flipping 
//the sign of the velocity component, I actually use a signed version of the
// absolute value to be sure I'm going in the correct direction.
	if (posoutcode & BOX_LOX)
		vx = -avx;
	else if (posoutcode & BOX_HIX)
		vx = avx;
	else if (posoutcode & BOX_LOY)
		vy = -avy;
	else if (posoutcode & BOX_HIY)
		vy = avy;
	else if (posoutcode & BOX_LOZ)
		vz = -avz;
	else if (posoutcode & BOX_HIZ)
		vz = avz;

	velocity.set(vx, vy, vz);
}

Real cRealBox3::maxDistanceToCorner(const cVector3 &testpos) const
{ /*This gives the distance from testpos to the furthest corenr of the
cRealBox3. */
	int posoutcode = outcode(testpos);
	Real dx, dy, dz;
	if (posoutcode & BOX_LOX)
		dx = _hix - testpos.x();
	else if (posoutcode & BOX_HIX)
		dx = testpos.x() - _lox;
	else
		dx = __max(testpos.x() - _lox, _hix - testpos.x());
	if (posoutcode & BOX_LOY)
		dy = _hiy - testpos.y();
	else if (posoutcode & BOX_HIY)
		dy = testpos.y() - _loy;
	else
		dy = __max(testpos.y() - _loy, _hiy - testpos.y());
	if (posoutcode & BOX_LOZ)
		dz = _hiz - testpos.z();
	else if (posoutcode & BOX_HIZ)
		dz = testpos.z() - _loz;
	else
		dz = __max(testpos.z() - _loz, _hiz - testpos.z());
	return sqrt(dx*dx + dy*dy + dz*dz);
}

cVector3 cRealBox3::corner(int i)const
{
	ASSERT(0 <= i && i <= 7);
	switch(i)
	{
		case 0:
			return cVector3(_lox, _loy ,_loz);
		case 1:
			return cVector3(_lox, _loy ,_hiz);
		case 2:
			return cVector3(_lox, _hiy ,_loz);
		case 3:
			return cVector3(_lox, _hiy ,_hiz);
		case 4:
			return cVector3(_hix, _loy ,_loz);
		case 5:
			return cVector3(_hix, _loy ,_hiz);
		case 6:
			return cVector3(_hix, _hiy ,_loz);
		default: //case 7
			return cVector3(_hix, _hiy ,_hiz);
	}
}

int cRealBox3::wrap(cVector3 &position) const
{
	/* There's a slight chance you might have a very thin world where a critter
has raced out so far past the edge that if you wrap it, then the wrapped position
is still past the edge. This would be particulary likely if you have a zero
zsize cRealBox3.  In this wrap code, we call our CLAMP macro after 
finding our wrapped positions. */
	int outcode = BOX_INSIDE;
	Real newx, newy, newz;
	newx = position.x(); newy = position.y(); newz = position.z();
	if (position.x() <= _lox)
	{
		outcode |= BOX_LOX;
		newx = _hix - _lox + position.x();
		CLAMP(newx, _lox, _hix);
	}
	else if (position.x() >= _hix)
	{
		outcode |= BOX_HIX;
		newx = _lox - _hix + position.x();
		CLAMP(newx, _lox, _hix);
	}
	if (position.y() <= _loy)
	{
		outcode |= BOX_LOY;
		newy = _hiy - _loy + position.y();
		CLAMP(newy, _loy, _hiy);
	}
	else if (position.y() >= _hiy)
	{
		outcode |= BOX_HIY;
		newy = _loy - _hiy + position.y();
		CLAMP(newy, _loy, _hiy);
	}
	if (position.z() <= _loz)
	{
		outcode |= BOX_LOZ;
		newz = _hiz - _loz + position.z();
		CLAMP(newz, _loz, _hiz);
	}
	else if (position.z() >= _hiz)
	{
 		outcode |= BOX_HIZ;
		newz =  _loz - _hiz + position.z();
		CLAMP(newz, _loz, _hiz);
	}
	position.set(newx, newy, newz);
	return outcode;
}

int cRealBox3::wrap(cVector3 &position, cVector3 &wrapposition1,
	 cVector3 &wrapposition2, cVector3 &wrapposition3, Real radius) const
{
	wrapposition3 = wrapposition2 = wrapposition1 = position;
	int outcode = wrap(position);
	cRealBox3 smallbox = this->innerBox(radius);
//First wrap the x
	if (position.x() <= smallbox._lox)
	{
		outcode |= BOX_LOX;
		wrapposition1.set(_hix - _lox + position.x(),position.y(),position.z());
	}
	if (position.x() >= smallbox._hix)
	{
		outcode |= BOX_HIX;
		wrapposition1.set(_lox - _hix + position.x(), position.y(),position.z());
	}
//If there's no x wrap, wrap the y for wrapposition1
	if (wrapposition1 == position)
	{
		if (position.y() <= smallbox._loy)
		{
			outcode |= BOX_LOY;
			wrapposition1.set(position.x(), _hiy - _loy + position.y(),position.z());
		}
		if (position.y() >= smallbox._hiy)
		{
			outcode |= BOX_HIY;
			wrapposition1.set(position.x(), _loy - _hiy + position.y(),position.z());
		}
	}
//If there's x wrap in wrapposition1, do the y wrap of position and wrapposition1
	else //wrapposition1 not equal to position
	{
		if (position.y() <= smallbox._loy)
		{
			outcode |= BOX_LOY;
			wrapposition2.set(position.x(), _hiy - _loy + position.y(),position.z());
			wrapposition3.set(wrapposition1.x(), _hiy - _loy + position.y(),position.z());
		}
		if (position.y() >= smallbox._hiy)
		{
			outcode |= BOX_HIY;
			wrapposition2.set(position.x(), _loy - _hiy + position.y(),position.z());
			wrapposition3.set(wrapposition1.x(), _loy - _hiy + position.y(),position.z());
		}
	}
	if (position.z() <= _loz)
	{
		outcode |= BOX_LOZ;
		position.set(position.x(), position.y(), _hiz - _loz + position.z());
	}
	if (position.z() >= _hiz)
	{
		outcode |= BOX_HIZ;
		position.set(position.x(), position.y(), _loz - _hiz + position.z());
	}
	return outcode;
}

int cRealBox3::clamp(cVector3 &position) const
{
	int outcode = BOX_INSIDE;
	if (position.x() < _lox)
	{
		outcode |= BOX_LOX;
		position.set(_lox, position.y(), position.z());
	}
	if (position.x() > _hix)
	{
		outcode |= BOX_HIX;
		position.set(_hix, position.y(), position.z());
	}
	if (position.y() < _loy)
	{
		outcode |= BOX_LOY;
		position.set(position.x(), _loy, position.z());
	}
	if (position.y() > _hiy)
	{
		outcode |= BOX_HIY;
		position.set(position.x(), _hiy, position.z());
	}
	if (position.z() < _loz)
	{
		outcode |= BOX_LOY;
		position.set(position.x(), position.y(), _loz);
	}
	if (position.z() > _hiz)
	{
		outcode |= BOX_HIY;
		position.set(position.x(), position.y(), _hiz);
	}
	return outcode;
}

int cRealBox3::clamp(cVector3 &position, cVector3 &velocity) const
{
	int outcode = clamp(position);
	if (outcode & BOX_LOX) //If you hit a LO X wall, zero out any neg X velocity.
		velocity.set(__max(0.0, velocity.x()), velocity.y());
	if (outcode & BOX_HIX) //If you hit an HI X wall, zero out any pos X velocity.
		velocity.set(__min(0.0, velocity.x()), velocity.y());
	if (outcode & BOX_LOY) //Same deal for Y.
		velocity.set( velocity.x(), 0.0);//__max(0.0, velocity.y()) );
	if (outcode & BOX_HIY) 
		velocity.set( velocity.x(), __min(0.0, velocity.y()) );
	if (outcode & BOX_LOZ) //Same deal for Z.
		velocity.set( velocity.x(),  velocity.y(), __max(0.0, velocity.z()) );
	if (outcode & BOX_HIZ) 
		velocity.set( velocity.x(),  velocity.y(), __min(0.0, velocity.z()) );
	return outcode;
}

int cRealBox3::addBounce(cVector3 &position, cVector3 &velocity, Real bounciness)const
{
	int outcode = BOX_INSIDE;

	position += velocity;
	/* The basic idea is to reverse appropriate velocity component if you've passed an edge,
	and reflect the motion past the edge into motion away from the edge.  Reflection means
	at the right newx would be _hix - (position.x()-_hix), or 2*_hix - position.x()
	and at the newx would be _lox + (_lox - position.x()), or 2*_lox - position.x(). 
		Now add in the notion of a bounciness between 0.0 and 1.0.  First of all the
	reflected newvel is attentuated to -bounciness*oldvel.  Second, the reflected
	position should take into account the fact that the object is moving slower after
	the reflection, so we get, on the right, 
	newx  = _hix - bounciness*(position.x()-_hix) and on the left 
	newx = _lox + bounciness*(_lox - position.x()) or
	newx = 	_lox - bounciness*(position.x() - _lox)*/
#ifdef USEBOUNCINESS
	if (position.x() >= _hix)
	{
		velocity.set(-bounciness*velocity.x(), velocity.y());
		position.set(_hix - bounciness*(position.x()-_hix), position.y());
		outcode |= BOX_HIX;
	}
	if (position.x() <= _lox)
	{
     	velocity.set(-bounciness*velocity.x(), velocity.y());
		position.set(_lox - bounciness*(position.x()-_lox), position.y());
		outcode |= BOX_LOX;
	}
	if (position.y() >= _hiy)
	{
     	velocity.set(velocity.x(), -bounciness*velocity.y());
		position.set(position.x(), _hiy - bounciness*(position.y()-_hiy));
		outcode |= BOX_HIY;
	}
	if (position.y() <= _loy)
	{
     	velocity.set(velocity.x(), -bounciness*velocity.y());
		position.set(position.x(), _loy - bounciness*(position.y()-_loy));
		outcode |= BOX_LOY;
	}
	if (position.z() >= _hiz)
	{
     	velocity.set(velocity.x(), velocity.y(), -bounciness*velocity.z());
		position.set(position.x(), position.y(), _hiz - bounciness*(position.z()-_hiz));
		outcode |= BOX_HIZ;
	}
	if (position.z() <= _loz)
	{
     	velocity.set(velocity.x(), velocity.y(), -bounciness*velocity.z());
		position.set(position.x(), position.y(), _loz - bounciness*(position.z()-_loz));
		outcode |= BOX_LOZ;
	}
	if (outcode != BOX_INSIDE)
		clamp(position); /* Just so some screwy high velocity bounce can't 
			leave you outside the box */
    return outcode;
#else //not USEBOUNCINESS, do it the old way
	if (position.x() >= _hix)
	{
		velocity.set(-velocity.x(), velocity.y());
		position.set(2*_hix - position.x(), position.y());
		outcode |= BOX_HIX;
	}
	if (position.x() <= _lox)
	{
     	velocity.set(-velocity.x(), velocity.y());
		position.set(2*_lox - position.x(), position.y());
		outcode |= BOX_LOX;
	}
	if (position.y() >= _hiy)
	{
     	velocity.set(velocity.x(), -velocity.y());
		position.set(position.x(), 2*_hiy - position.y());
		outcode |= BOX_HIY;
	}
	if (position.y() <= _loy)
	{
     	velocity.set(velocity.x(), -velocity.y());
		position.set(position.x(), 2*_loy - position.y());
		outcode |= BOX_LOY;
	}
	if (position.z() >= _hiz)
	{
     	velocity.set(velocity.x(), velocity.y(), -velocity.z());
		position.set(position.x(), position.y(), 2*_hiz - position.z());
		outcode |= BOX_HIZ;
	}
	if (position.z() <= _loz)
	{
     	velocity.set(velocity.x(), velocity.y(), -velocity.z());
		position.set(position.x(), position.y(), 2*_loz - position.z());
		outcode |= BOX_LOZ;
	}
	if (outcode != BOX_INSIDE)
		clamp(position); /* Just so some screwy high velocity bounce can't 
			leave you outside the box */
    return outcode;
#endif //USEBOUNCINESS switch
}

int cRealBox3::addBounce(cVector3 &position, cVector3 &velocity, Real bounciness, Real dt)const
{
	if (fabs(dt)<SMALL_REAL)
		return BOX_INSIDE; //You're not moving.
	cVector3 dtvelocity = dt*velocity;
	int outcode = addBounce(position, dtvelocity, bounciness);
	velocity = dtvelocity/dt;
	return outcode;
}

/*CRect cRealBox3::realToPixel(const cRealPixelConverter &crealpixelconverter)
{
	int left, top, right, bottom;	
	crealpixelconverter.realToPixel(_lox, _loy, &left, &bottom);
	crealpixelconverter.realToPixel(_hix, _hiy, &right, &top);
	return CRect(left, top, right, bottom);
}
*/

void cRealBox3::draw(cGraphics *pgraphics, int drawflags)
{ 
		/*Draw a basic unfilled rectangle at z=0. */
		cRealBox2 pgbox(*this);
		pgbox.draw(pgraphics, drawflags);
}

cRealBox3 operator*(Real scale, const cRealBox3 &box)
{
	return cRealBox3(box.center(), scale*box.xsize(),
		scale*box.ysize(), scale*box.zsize());
}

BOOL operator==(const cRealBox3 arect, const cRealBox3 brect)
{
	return (arect._lox==brect._lox && arect._loy==brect._loy && 
		arect._hix==brect._hix && arect._hiy==brect._hiy);
}

BOOL operator!=(const cRealBox3 arect, const cRealBox3 brect)
{ return !(arect==brect);}


