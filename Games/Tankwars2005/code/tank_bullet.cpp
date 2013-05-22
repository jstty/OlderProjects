//////////////////////////////////////////////////////////////////////////////
// Program Name:  tank_bullet.cpp
// Programmer:    Joseph E. Sutton
// Description:	TankWars 2005
// Course:        cs335
// Start Date:    3/2/2005
// Last Updated:  
// Version:       1.00
//////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "../pop/spritepolygon.h" //For cSprite, and for Bullet shape critter
#include "../pop/pop.h" //for playSound
#include "../pop/biota.h"
#include "../pop/collider.h"
#include "../pop/critterarmed.h"

#include "tank_bullet.h"

//============================= cCritter ==========================
IMPLEMENT_SERIAL( cTankBullet, cCritter, 0 );


//=================Various Speed Statics==============
Real cTankBullet::BULLETSPEED = 10.0;
Real cTankBullet::MAXSPEED = 22.0; //HIgher than cCritterArmed::BULLETSPEED in case you
	//shoot a bullet from a moving critter.
//==================cTankBullet Statics ===============
Real cTankBullet::FIXEDLIFETIME = 3.0;
BOOL cTankBullet::DIEATEDGES = TRUE;


//==================cTankBullet===============
cTankBullet::cTankBullet():
_pshooter(NULL),
_shooterindex(cBiota::NOINDEX),
_hitstrength(1),
_dieatedges(TRUE) 
{
 	_defaultprismdz = cSprite::BULLETPRISMDZ;
	_value = 0;
	_usefixedlifetime = TRUE;
	_fixedlifetime =  cTankBullet::FIXEDLIFETIME;
	_collidepriority = cCollider::CP_BULLET; /* Don't use the setCollidePriority mutator, as that
		forces a call to pgame()->buildCollider(); */
	_maxspeed = cTankBullet::MAXSPEED;
	setSpeed(cTankBullet::BULLETSPEED);
//	cPolygon *ppolygon = new cPolygon(3);
	cPolygon *ppolygon = new cPolygon(14);
		/* Now make it a thin isosceles triangle, with the apex at the 0th vertex.
			All that matters at first is the ratios of the numbers, as we will use
			setRadius to make the thing the right size, and center it on the origin. */
//	ppolygon->setVertex(0, cVector(3.0, 0.0));
//	ppolygon->setVertex(1, cVector(0.0, 1.0));
//	ppolygon->setVertex(2, cVector(0.0, -1.0));
	ppolygon->setVertex(0, cVector(0.0, -3.0));
	ppolygon->setVertex(1, cVector(0.0, 3.0));
	ppolygon->setVertex(2, cVector(3.0, 3.0));
	ppolygon->setVertex(3, cVector(4.0, 2.0));
	ppolygon->setVertex(4, cVector(5.0, 2.0));
	ppolygon->setVertex(5, cVector(6.0, 1.0));
	ppolygon->setVertex(6, cVector(7.0, 1.0));
	ppolygon->setVertex(7, cVector(8.0, 0.0));
	ppolygon->setVertex(8, cVector(7.0, -1.0));
	ppolygon->setVertex(9, cVector(6.0, -1.0));
	ppolygon->setVertex(10, cVector(5.0, -2.0));
	ppolygon->setVertex(11, cVector(4.0, -2.0));
	ppolygon->setVertex(12, cVector(3.0, -3.0));
	ppolygon->setVertex(13, cVector(0.0, -3.0));
	ppolygon->setRadius(cCritter::BULLETRADIUS); //Make it small enough.
	ppolygon->setFillColor(cColorStyle::CN_YELLOW);
	setSprite(ppolygon); /* Also sets cSprite::_prismdz to cCritter::_defaultprismdz, which we
		set to CritterWall::BULLETPRISMDZ above. */
}

void cTankBullet::Serialize(CArchive &ar)
{
	cCritter::Serialize(ar);
	if (ar.IsStoring()) //Writing data.
	{
		if(_pownerbiota && _pshooter)		
			_shooterindex = _pownerbiota->_index((cCritter *)_pshooter);
		ar << _hitstrength << _dieatedges << _shooterindex;
	}
	else //reading data
	{
		ar >> _hitstrength >> _dieatedges >> _shooterindex;
		_pshooter = NULL; //Gets fixed by the cBiota call to fixPointerRefs.
	}
}		

void cTankBullet::fixPointerRefs()
{
	cCritter::fixPointerRefs();
	if (_pownerbiota)
		_pshooter = (cCritterArmedPlayerTank*)(_pownerbiota->GetAt(_shooterindex));
}

void cTankBullet::initialize(cCritterArmedPlayerTank *pshooter)
{
	_pshooter = pshooter;
 	setMoveBox(_pshooter->pownerbiota()->border()); /* Be sure to call setMoveBox before setVelocity,
		as setVelocity generates a call to fixNormalAndBinormal which looks at _movebox to see
		if it's ok if you happen to have a 3D velocity. */
	setDragBox(_pshooter->pownerbiota()->border());
	setAttitude(_pshooter->attitude()); //Orient the bullet like the shooter, fix position below.
	setTangent(_pshooter->aimvector()); /* This call uses the _bulletspeed set by the
			cBullet constructor and the direction of the aim.  We choose NOT to add 
			_pshooter->velocity() to the new velocity. */
#ifdef COPYPHYSICSFORCES
	copyPhysicsForces(pshooter); //Only copies the global physics forces, not the chase and evade.
#endif //COPYPHYSICSFORCES
		/* We could set the bullet velocity to the muzzle speed velocity,
			which is bulletspeed*_pshooter->aimvector().  Should we add the shooter's
			velocity, that is, add	_pshooter->velocity()?  I think most videogames do this
			for the player.  So by default we DON'T add	in this velocity, we just
			use the bullet speed that was set in the bullet constructor.
			If we #define PLAYERBULLETSPEEDUP, we overload the	cCritterArmedPlayer::shoot to add the
			_pshooter->velocity() in so the player's bullets don't seem to pile up.*/
	setTarget(_pshooter->ptarget()); 
	setWrapflag(_pshooter->wrapflag());
	cVector start = _pshooter->position(); //position()
		/* I want to start the bullet out at the tip of the gun, with the provision
			that in any case I will I start it out far enough so that it's not touching
			the shooter. */
	Real bulletdistance1 = _pshooter->gunlength() * _pshooter->radius();
	Real bulletdistance2 = pshooter->radius() + 1.5 * BULLETRADIUS; /* Need the 1.5 for enough
		room. Otherwise when the simulation is slow you may still touch. */
	Real bulletdistance = __max(bulletdistance1, bulletdistance2);
	cVector end = start + (bulletdistance * _pshooter->aimvector());
	moveTo(end); //Do this instead of just setting _position so as to fix wrapposition
//#define TRACEAIMVECTOR
/* A TRACE statment writes output to the Debug sheet of	the Output window in Visual C++. */
#ifdef TRACEAIMVECTOR
TRACE("cTankBullet::initialize has bullet direction (%f, %f, %f)\n", tangent().x(),
	tangent().y(), tangent().z()); 
#endif //TRACEAIMVECTOR
}

cTankBullet::~cTankBullet()
{
	if (_pshooter) /* The cCritteArmed destructor sets _pshooter to NULL in its destrucor.  So if
					_pshooter isn't NULL, then it's still a good pointer. */
		_pshooter->removeBullet(this);
}

BOOL cTankBullet::isTarget(cCritter* pcritter)
{ 
//Collide already rules out the _pshooter and bullets from the same shooter.
//For now we'll view everything else except a wall as a target.
	if (pcritter->GetRuntimeClass()==RUNTIME_CLASS(cCritterWall)) /* Don't blow up any
			basic walls.  For now we WILL blow up children of walls, thinking ahead towards
			shooting out of cages, but if you don't want to do that, change this line to
			use IsKindOf. */
		return FALSE;
	return TRUE;
} 

void cTankBullet::update(CPopView *pactiveview, Real dt)
{
	cCritter::update(pactiveview, dt); /* Feels force, also checks _age against _lifetime. */
	if (_outcode && _dieatedges)/* _outcode nonzero means near an edge.  This keeps bullets
		from bouncing or wrapping,	but it also makes the critters unable tofire when they are 
		really near an edge. */
	{
		delete_me();
		return;
	}
}

int cTankBullet::collidesWith(cCritter *pcritter)
{
/* Don't bump into other bullets from your shooter. If your shooter is dead (NULL),
you'll also ignore bullets from other dead shooters.  Note that the cast in the 
second clause of the && will crash C++ if the condition in the first clause isn't
true.  But C++ doesn't evaluate the second clause of a && if the first clause is
FALSE.  */
	if (pcritter->IsKindOf(RUNTIME_CLASS(cTankBullet)) &&  // C++ bails if FALSE
	 	((cTankBullet*)pcritter)->pshooter() == _pshooter) // Can be NULL
			return cCollider::DONTCOLLIDE;
//Don't bump into your shooter.
	if (pcritter == _pshooter)
		return cCollider::DONTCOLLIDE; 
#ifdef BULLETSIGNOREMOSTOTHERS
	if (   !pcritter->IsKindOf(RUNTIME_CLASS(cCritterWall)) //Might need to bounce off it
		&& !pcritter->IsKindOf(RUNTIME_CLASS(cTankBullet)) //Might need to get shot by it
		&& !isTarget(pcritter) )//Might need to kill it
		return cCollider::DONTCOLLIDE; 
#endif //BULLETSIGNOREMOSTOTHERS
	return cCritter::collidesWith(pcritter);
}

BOOL cTankBullet::collide(cCritter *pcritter)
{
//If you hit a target, damage it and die.
	if (isTarget(pcritter))
	{
		if (!touch(pcritter))
			return FALSE;
		int hitscore = pcritter->damage(_hitstrength);
		delete_me(); //Makes a service request, but you won't go away yet.
		if (_pshooter) //Possible that _pshooter has died, is NULL.
			_pshooter->addScore(hitscore);
		return TRUE;
	}
//Bounce off or everything else.
	return cCritter::collide(pcritter); //Bounce off non-target critters
}
