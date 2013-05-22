// Critterarmed.cpp: implementation of various cCritterArmed and cCritterBullet classes.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "critterarmed.h"
#include "critterwall.h" //For cCritterBullet::update
#include "force.h"
#include "listener.h"
#include "game.h" //For biot.h and to get the keystate in listen method.
#include "spritepolygon.h" //For cSprite, and for Bullet shape critter
#include "pop.h" //for playSound
#include "colorstyle.h"
#include "graphics.h"
#include "collider.h"
#include "../code/tankwars2005.h"
#include "../code/cOptions.h"

extern cTankWars2005 *tws2005;
extern cOptionsData *options_data;

//============================= cCritter ==========================
IMPLEMENT_SERIAL( cCritterBullet, cCritter, 0 );
IMPLEMENT_SERIAL( cCritterBulletRubber, cCritterBullet, 0 );
IMPLEMENT_SERIAL( cCritterBulletSilver, cCritterBullet, 0 );
IMPLEMENT_SERIAL( cCritterBulletSilverMissile, cCritterBulletSilver, 0 );
IMPLEMENT_SERIAL( cCritterArmed, cCritter, 0 );
IMPLEMENT_SERIAL( cCritterArmedRobot, cCritterArmed, 0 );
IMPLEMENT_SERIAL( cCritterArmedPlayer, cCritterArmed, 0 );
IMPLEMENT_SERIAL( cCritterPlayer, cCritterArmedPlayer, 0 );

//==============defines==================
#define PLAYERBULLETSPEEDUP
	/* If you comment in PLAYERBULLETSPEEDUP, the cCritterArmedPlayer::shoot method
	adds a part of the player's velocity to the bullet, but only the part that's in the direction
	the bullet's already going.  If you don't use this, your bullets stack up if you fly
	forward while shooting straight ahead, so all in all it's better to keep it. And if you
	just add the player velocity to the bullet, you get weird-looking effects, like motionless
	bullets when you shoot backwards. */
#define HIGHLIGHTPLAYER
	/* If you comment in HIGHLIGHTPLAYER, then you draw a circle around the player critter
	to make it stand out better. */
//#define BULLETSIGNOREMOSTOTHERS
	/*  If you comment in BULLETSIGNOREMOSTOTHERS, the cCritterBullet::collidesWith code
	is changed so that a bullet ignores anything that isn't a wall or a target or a bullet. */
#define COPYPHYSICSFORCES
	/* If you comment in COPYPHYSICSFORCES, then the cBullet::initialize(pshooter) copies
	the pshooter's physics forces (that is, friction and gravity).  Although on the face
	of it, this seems a reasonable thing to do, it causes bad surprises more often than
	not.  If you want some forces on your bullets its better to explicity add them in
	their child class overload of initialize. */

//********* SIZE RELATED STATICS *******************
 /* In looking at the size and speed , keep in mind that our typical world size is 14.0
  by 9.0, defined by the WORLD??? statics.  The speed is in units per second, so a
 speed of 3 means it takes about 3 seconds to cross the window.  A speed of 1 takes 10 
 seconds, a speed of 5 takes 2 seconds and so on. */
//=================Various Speed Statics==============
Real cCritterBullet::BULLETSPEED = 10.0;
Real cCritterBullet::MAXSPEED = 22.0; //HIgher than cCritterArmed::BULLETSPEED in case you
	//shoot a bullet from a moving critter.
//===============CritterBulletSilverMissile statics==========================
Real cCritterBulletSilverMissile::MAXSPEED = 10.0; //Not so high or they're too hard to escape.
Real cCritterBulletSilverMissile::CHASEACCELERATION = 20.0; /* Used in the
 	cForceObjectSeek constructor in the cCritterBulletSilverMissile constructor. */
//==================cCritterBullet Statics ===============
Real cCritterBullet::FIXEDLIFETIME = 3.0;
BOOL cCritterBullet::DIEATEDGES = TRUE;
//==================cCritterBulletRubber Statics ===============
BOOL cCritterBulletRubber::DIEATEDGES = FALSE;
Real cCritterBulletRubber::DENSITY = 100.0;
//==================cCritterArmed Statics ==================
int cCritterArmed::MAXBULLETS = 8;
Real cCritterArmed::GUNLENGTH = 1.3;
Real cCritterArmed::WAITSHOOT = 0.06; //0.06;
//==================cCritterArmedPlayer Statics ==========
Real cCritterArmedPlayer::DENSITY = 5.0;
int cCritterArmedPlayer::PLAYERHEALTH = 10;
 //===================Sound Statics ==========================
CString cCritterArmedPlayer::DAMAGESOUND = "BONK";
//********* SCORE RELATED STATICS *******************
int cCritterBulletSilver::SCOREVALUE = 10;
int cCritterBulletSilverMissile::SCOREVALUE = 20;

//==================cCritterBullet===============
// Joseph E. Sutton && John P. Harris
cCritterBullet::cCritterBullet():
_pshooter(NULL),
_shooterindex(cBiota::NOINDEX),
_hitstrength(1),
_dieatedges(FALSE) 
{
 	_defaultprismdz = cSprite::BULLETPRISMDZ;
	_value = 0;
	_usefixedlifetime = FALSE;
//	_fixedlifetime =  cCritterBullet::FIXEDLIFETIME;
	_collidepriority = cCollider::CP_BULLET; /* Don't use the setCollidePriority mutator, as that
		forces a call to pgame()->buildCollider(); */
	_maxspeed = cCritterBullet::MAXSPEED;
	setSpeed(cCritterBullet::BULLETSPEED);
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

void cCritterBullet::Serialize(CArchive &ar)
{
	cCritter::Serialize(ar);
	if (ar.IsStoring()) //Writing data.
	{
		if(_pownerbiota && _pshooter)		
			_shooterindex = _pownerbiota->_index(_pshooter);
		ar << _hitstrength << _dieatedges << _shooterindex;
	}
	else //reading data
	{
		ar >> _hitstrength >> _dieatedges >> _shooterindex;
		_pshooter = NULL; //Gets fixed by the cBiota call to fixPointerRefs.
	}
}		

void cCritterBullet::fixPointerRefs()
{
	cCritter::fixPointerRefs();
	if (_pownerbiota)
		_pshooter = (cCritterArmed*)(_pownerbiota->GetAt(_shooterindex));
}

void cCritterBullet::initialize(cCritterArmed *pshooter)
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
TRACE("cCritterBullet::initialize has bullet direction (%f, %f, %f)\n", tangent().x(),
	tangent().y(), tangent().z()); 
#endif //TRACEAIMVECTOR
}

cCritterBullet::~cCritterBullet()
{
	if (_pshooter) /* The cCritteArmed destructor sets _pshooter to NULL in its destrucor.  So if
					_pshooter isn't NULL, then it's still a good pointer. */
		_pshooter->removeBullet(this);
}

BOOL cCritterBullet::isTarget(cCritter* pcritter)
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

void cCritterBullet::update(CPopView *pactiveview, Real dt)
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

int cCritterBullet::collidesWith(cCritter *pcritter)
{
/* Don't bump into other bullets from your shooter. If your shooter is dead (NULL),
you'll also ignore bullets from other dead shooters.  Note that the cast in the 
second clause of the && will crash C++ if the condition in the first clause isn't
true.  But C++ doesn't evaluate the second clause of a && if the first clause is
FALSE.  */
	if (pcritter->IsKindOf(RUNTIME_CLASS(cCritterBullet)) &&  // C++ bails if FALSE
	 	((cCritterBullet*)pcritter)->pshooter() == _pshooter) // Can be NULL
			return cCollider::DONTCOLLIDE;
//Don't bump into your shooter.
	if (pcritter == _pshooter)
		return cCollider::DONTCOLLIDE; 
#ifdef BULLETSIGNOREMOSTOTHERS
	if (   !pcritter->IsKindOf(RUNTIME_CLASS(cCritterWall)) //Might need to bounce off it
		&& !pcritter->IsKindOf(RUNTIME_CLASS(cCritterBullet)) //Might need to get shot by it
		&& !isTarget(pcritter) )//Might need to kill it
		return cCollider::DONTCOLLIDE; 
#endif //BULLETSIGNOREMOSTOTHERS
	return cCritter::collidesWith(pcritter);
}

// modified by: Joseph E. Sutton
BOOL cCritterBullet::collide(cCritter *pcritter)
{
//If you hit a target, damage it and die.
	if (isTarget(pcritter))
	{
		if (!touch(pcritter))
			return FALSE;
		if(pcritter->IsKindOf(RUNTIME_CLASS(cCritterArmedPlayerTank)))
		{
			setVelocity(cVector::ZEROVECTOR);

         if(options_data->CheckBulletState(Moving))
            options_data->SetBulletState(Collided);

/*
			cCritter *boom = new cCritter(tws2005);
			cPolyPolygon *pp = tws2005->LoadPoly("objects\\explode.dat");
			pp->setRadius(0.15);
			boom->setSprite( pp );
         boom->moveTo(position(), false);
			boom->setFixedLifetime(1.5);
//			boom->fixedlifetime(); //Probably don't need this
//			boom->setCollidePriority(500);
//			boom->dieOfOldAge();
			options_data->GetOtherPlayer()->Hit(1);
			//delete_me(); //Makes a service request, but you won't go away yet.
*/
		}
		else
		{
         if(options_data->CheckBulletState(Moving))
            options_data->SetBulletState(Collided);

			//delete_me(); //Makes a service request, but you won't go away yet.

			int hitscore = pcritter->damage(_hitstrength);
			if (_pshooter) //Possible that _pshooter has died, is NULL.
				_pshooter->addScore(hitscore);
		}
		return TRUE;
	}
//Bounce off or everything else.
	return cCritter::collide(pcritter); //Bounce off non-target critters
}
//==================cCritterBulletSilver=======================

cCritterBulletSilver::cCritterBulletSilver()
{
	_value = cCritterBulletSilver::SCOREVALUE;
	_collidepriority = cCollider::CP_SILVERBULLET; /* Want this to have a lower priority than
		CP_BULLET, so that bullets can kill it in their collide call. 
		Don't use the setCollidePriority mutator, as that forces a call to
		pgame()->buildCollider(); */
	cPolygon *ppolygon = new cPolygon(5);
	/* Now make it a thin pentagon, with the apex at the 0th vertex.
		All that matters at first is the ratios of the numbers, as we will use
		seRadius to make the thing the right size, and center it on the origin. */
	ppolygon->setVertex(0, cVector(4.0, 0.0));
	ppolygon->setVertex(1, cVector(3.0, 1.0));
	ppolygon->setVertex(2, cVector(0.0, 1.0));
	ppolygon->setVertex(3, cVector(0.0, -1.0));
	ppolygon->setVertex(4, cVector(3.0, -1.0));
	ppolygon->setRadius(cCritter::BULLETRADIUS); //Make it small enough.
	ppolygon->setFillColor(cColorStyle::CN_LIGHTGREEN);
	setSprite(ppolygon); /* Also sets cSprite::_prismdz to CritterBullet::BULLETPRISMDZ. */

}

BOOL cCritterBulletSilver::isTarget(cCritter* pcritter)
{
	return pcritter == _ptarget;
} 

int cCritterBulletSilver::damage(int hitstrength)
{
	playSound("Pop");
	return cCritter::damage(hitstrength);
}

//==================cCritterBulletSilverMissile=======================
cCritterBulletSilverMissile::cCritterBulletSilverMissile()
{
	_value = cCritterBulletSilverMissile::SCOREVALUE;
	_maxspeed = cCritterBulletSilverMissile::MAXSPEED;
	_dieatedges = FALSE; //Make them particularly vicious and long-lived.
	cPolygon *ppolygon = new cPolygon(5);
	/* Now make it a thin pentagon triangle, with the apex at the 0th vertex.
		All that matters at first is the ratios of the numbers, as we will use
		seRadius to make the thing the right size and center it on origin. */
	ppolygon->setVertex(0, cVector(8.0, 0.0));
	ppolygon->setVertex(1, cVector(6.0, 1.0));
	ppolygon->setVertex(2, cVector(0.0, 1.0));
	ppolygon->setVertex(3, cVector(0.0, -1.0));
	ppolygon->setVertex(4, cVector(6.0, -1.0));
	ppolygon->setRadius(2.0*cCritter::BULLETRADIUS); //Make it small enough.
	ppolygon->setFillColor(cColorStyle::CN_LIGHTBLUE);
	setSprite(ppolygon);/* Also sets cSprite::_prismdz to CritterBullet::BULLETPRISMDZ. */
}

void cCritterBulletSilverMissile::initialize(cCritterArmed *pshooter)
{
	cCritterBullet::initialize(pshooter);
	addForce(
		new cForceObjectSeek(ptarget(), 
 			cCritterBulletSilverMissile::CHASEACCELERATION)	);
}

//==================cCritterBulletRubber=========================
cCritterBulletRubber::cCritterBulletRubber()
{
	_dieatedges = cCritterBulletRubber::DIEATEDGES;
	setDensity(cCritterBulletRubber::DENSITY); /* Use setDensity so you fixMass. */
	_collidepriority = cCollider::CP_CRITTER; /* This acts just like a critter, so doesn't 
		need any special priority.  In fact we want a low priority so regular bullets
		have higher priority and can kill it in their own collide calls.
		Don't use the setCollidePriority mutator, as that forces a call to pgame()->buildCollider(); */
	cPolygon *ppolygon = new cPolygon(9);
	/* Now make it a thin long nonogon, could be octogon, but I need to have
	vertex 0 point in the leading direction.
		All that matters at first is the ratios of the numbers, as we will use
		seRadius to make the thing the right size and center it properly. */
	ppolygon->setVertex(0, cVector(7, 0));
	ppolygon->setVertex(1, cVector(7, 2));
	ppolygon->setVertex(2, cVector(5, 4));
	ppolygon->setVertex(3, cVector(-5, 4));
	ppolygon->setVertex(4, cVector(-7, 2));
	ppolygon->setVertex(5, cVector(-7, -2));
	ppolygon->setVertex(6, cVector(-5, -4));
	ppolygon->setVertex(7, cVector(5, -4));
	ppolygon->setVertex(8, cVector(7, -2));
	ppolygon->setRadius(cCritter::BULLETRADIUS); //Make it small enough.
	ppolygon->setFillColor(cColorStyle::CN_LIGHTRED); //From colornames.h, should make these statics.
	setSprite(ppolygon);/* Also sets cSprite::_prismdz to CritterBullet::BULLETPRISMDZ. */
}

void cCritterBulletRubber::update(CPopView *pactiveview, Real dt)  //Don't use the cCritterBullet update.
{
	cCritter::update(pactiveview, dt);  //Don't do the bullet stuff.
}

BOOL cCritterBulletRubber::collide(cCritter *pcritter)
{
	return cCritter::collide(pcritter); //Regular collide.
}

//==================cCritterArmed==================
cCritterArmed::cCritterArmed(cGame *pownergame):
cCritter(pownergame),
_armed(TRUE),
_aimvector(0.0, 1.0),
_maxbullets(MAXBULLETS),
_ageshoot(0.0),
_waitshoot(WAITSHOOT),
_bshooting(FALSE),
_aimtoattitudelock(FALSE),
_gunlength(GUNLENGTH)
{
	_pbulletclass = RUNTIME_CLASS(cCritterBullet);
	setAimVector(_tangent);
}

void cCritterArmed::Serialize(CArchive &ar)
{
	cCritter::Serialize(ar);
		/* I had a  hell of a time figuring out how to serialize the CRuntimeClass *_pbulletclass.
			At present it actually doesn't matter, because I'm initializing _pbulletclass in my
			armed critter constructors.  But someday I might want to have a critter with multiple
			selectable bullet types, and then it woudl be nice to save the current bullet class.
			Here's an outline of how the present method developed.
			(1) You can't	call _pbulletclass.Serialize(ar), as this is not a method of CRuntimeClass.
			(2) Nor can you save off the CRuntimeClass m_lpszClassName field and try and use 
			RUNTIME_CLASS to reconstruct it, as RUNTIME_CLASS requires a literal argument and
			not a CString.
			(3)  MFC provides a CArchive::SerializeClass(CRuntimeClass *prtc). But it doesn't do the job
			either.  It's actually designed more for use as a compatability type-checker.
			If I put in ar.SerializeClass(_pbulletclass),  when I save and load, 
			I don't get anything read back innto _pbulletclass because SerializeClass treats its
			argument as a const and won't change it in the load! 
			(4) What DOES work is to save with ar.WriteClass(_pbulletclass) and load with 
			_pbulletclass = ar.ReadClass(). */
	if (ar.IsStoring()) //Writing data.
	{
		ar.WriteClass(_pbulletclass);
		_bulletindexarray.SetSize(_bulletarray.GetSize());
		for (int i=0; i<_bulletarray.GetSize(); i++)
			_bulletindexarray[i] = _pownerbiota->_index(_bulletarray[i]);
		ar << _armed << _ageshoot << _waitshoot << _aimvector << _maxbullets 
			<< _bshooting << _aimtoattitudelock << _gunlength;
	}
	else //reading data
	{
		_pbulletclass = ar.ReadClass();
		ar >> _armed >> _ageshoot >> _waitshoot >> _aimvector >> _maxbullets 
			>> _bshooting >> _aimtoattitudelock >> _gunlength;
	}
	_bulletindexarray.Serialize(ar); /* Note that you  do this AFTER the other serialization
		because it gets made in the IsStoring part. */
}

void cCritterArmed::fixPointerRefs()
{
	cCritter::fixPointerRefs();
	_bulletarray.SetSize(_bulletindexarray.GetSize());
	for (int i=0; i<_bulletindexarray.GetSize(); i++)
		_bulletarray[i] = (cCritterBullet*)(_pownerbiota->GetAt(_bulletindexarray[i]));
}

void cCritterArmed::copy(cCritter *pcritter)
{
/*We need to overload the cCritter copy because if I have cCritterArmedRobot which is
a cCritterArmed, and it gets split in two by a replicate call, then I want the new
copy to have all the same shooting behavior as the old one.  In general, I should
overload copy for each of my critter child classes, but for now this one is the
most important.  The overload does the regular copy, then looks if the thing 
being copied is a cCritterArmed, and if it is then it copies the additional fields. */
	cCritter::copy(pcritter);	
	if (!pcritter->IsKindOf(RUNTIME_CLASS(cCritterArmed)))
		return; //You're done if pcritter isn't a cCritterArmed*.
	cCritterArmed *pcritterarmed = (cCritterArmed *)(pcritter); /* I know it is a
		cCritterArmed at this point, but I need to do a cast, so the compiler will let me
		call a bunch of cCritterArmed methods. */
	_armed = pcritterarmed->_armed;
	_aimvector = pcritterarmed->_aimvector;
	_maxbullets = pcritterarmed->_maxbullets;
	_waitshoot = pcritterarmed->_waitshoot;
	_aimtoattitudelock = pcritterarmed->_aimtoattitudelock;
	setBulletClass(pcritterarmed->_pbulletclass);
	//_bulletarray.SetSize(0); //Just in case
}

cCritterArmed::~cCritterArmed()
{
/* It could cause a crash if any surviving cCritterBullet still has a _pshooter pointer to
	this deleted cCritterArmed.  So I set all the bullets' pshooter to NULL, and everywhere in
	the bullet code where I might use a pshooter, I always check that it isn't NULL. */
	for (int i=0; i<_bulletarray.GetSize(); i++)
		_bulletarray.GetAt(i)->_pshooter = NULL;
}

void cCritterArmed::aimAt(cVector vclick)
{
	if (!_armed)
		return;
	setAimVector((vclick - _position).direction()); /* Use the setAimVector call as this
		does a safety roundOff on the direction. */
	if (_aimtoattitudelock)
		setAttitudeTangent(_aimvector);
}

void cCritterArmed::aimAt(cCritter *pcritter)
{ /* I could make this code more sophisticated by taking into account the current velocity and
		distance of the pcritter to figure out where it will be when the bullet gets there. */
	if (_armed && pcritter)
		aimAt(pcritter->position());
}

void cCritterArmed::setAimVector(cVector dir)
{
	dir.roundOff(); /* I need this because in 3D with cGraphicsOpenGL, I will sometimes have
		an erroneous tiny z value that makes the planer seem to aim out of his plane. */
	_aimvector = dir.direction();
}

void cCritterArmed::update(CPopView *pactiveview, Real dt)
{
//(1) Call base class update to apply force.
	cCritter::update(pactiveview, dt);
//(2) Align gun with move direction if necessary.
	if (_aimtoattitudelock)
		setAimVector(attitudeTangent()); /* Keep the gun pointed in the right direction. */
//(3) Shoot if possible.
	if (!_armed || !_bshooting)
		return;
	/* If _age has been reset to 0.0, you need to get ageshoot back in synch. */
	if (_age < _ageshoot)
		_ageshoot = _age;
	if ((_age - _ageshoot > _waitshoot)) //A shoot key is down
	{
		shoot();
		_ageshoot = _age;
	}
}

void cCritterArmed::animate(Real dt)
{
	cCritter::animate(dt); //Calls updateAttitude(dt) and _psprite->animate(dt)
	if (_aimtoattitudelock)
		setAimVector(attitudeTangent().roundOff());
}

cCritterBullet* cCritterArmed::shoot()
{
	/* What do we do if we've fired the maximum number of bullets and then want
		to fire more? The simple solution would be to freeze out any new firing till
		all the existing bullets have died.  But this makes for a bad game, as you always
		need to be able to shoot a bullet if you're under severe threat.  So we limit
		the number of bullets by removing the oldest bullet when you shoot a new one.
		This means that if you stand on the shoot key, you'll see a stream of a few
		bullets coming out of your gun with the farther ones disappearing.
		If always add new bullets to the end of the array and remove them from the front,
		then the oldest bullet will be the one in the first place.  
		We can be sure that any bullet pointer in the _bulletarray is actually good because
		we have the bullet destructor remove the dying pointer from the shooter's array. */
	if (_bulletarray.GetSize() >= _maxbullets)
		_bulletarray[0]->delete_me();
	cCritterBullet *pbullet = (cCritterBullet*)(_pbulletclass->CreateObject()); /* Use
		CreateObject instead of just pbullet = new cCritterBullet(this, _bulletspeed, _hitstrength)
		because I want cCritterArmed to have freedom about what kind of bullets it shoots. */
	pbullet->initialize(this);
	pbullet->psprite()->setLineColor(psprite()->lineColor());
	pbullet->add_me(_pownerbiota); /* Makes a servicerequest to be handled by cBiota later. I used to
			have _pownerbiota.Add(pbullet) here, but this makes a problem if I do
			USEMETRIC; this is because _metric expects the critter's indices to stay fixed.
			In general, I should not be adding or deleting any critters except
			in the cBiota::processervicerequests call. Note that you have the default
			FALSE value of the immediateadd argument to add_me, meaning you don't
			add in this critter to the simulator cBiota until it finishes its current
			update loop and has a chance to call processServiceRequests. */
	_bulletarray.Add(pbullet); //Adds to end of my personal bullet-data array.
	return pbullet; /* In case you want to overload cCritterArmed::shoot to do something else to 
		the bullet. */
}

void cCritterArmed::removeBullet(cCritterBullet *pbullet)
{
	for (int i=0; i<_bulletarray.GetSize(); i++)
		if (_bulletarray.GetAt(i) == pbullet)
		{
			_bulletarray.RemoveAt(i);
			break;
		}
}

void cCritterArmed::draw(cGraphics *pgraphics,
		int drawflags)
{
	if (_armed && (pgraphics->is3D() || !_outcode))  /* The gun looks bad if
		 you're near the edge in 2D	graphics as it doesn't get clipped. */
	{
/* We draw the "gun" as a line.  It might be better to have the following
code be part of the cSprite::drawing, because then that would happen while the
pDC is clipped in the cCritter call.  One way to do it would be to have a CPopView::DF_GUN
drawflag. */
		cVector start = _position;
		cVector end = start + _gunlength*radius()*_aimvector;
#ifdef SKIPCOLOR
		cColorStyle guncolorstyle(psprite()->pcolorstyle());
		guncolorstyle.setLineWidth(0.2 * psprite()->radius());
		pgraphics->drawline(start, end,&guncolorstyle);
#endif //SKIPCOLOR
	}
	cCritter::draw(pgraphics, drawflags); 
		//Draw sprite on top of gun line.
}
//==================cCritterArmedRobot=====================

cCritterArmedRobot::cCritterArmedRobot(cGame *pownergame):
cCritterArmed(pownergame)
{
	_bshooting = TRUE; //Assume enemy shoots whenever time is up.
	setWaitShoot(_waitshoot);
}

void cCritterArmedRobot::setWaitShoot(Real waitshoot)
{
	_waitshoot = waitshoot;
	_ageshoot = _age - cRandomizer::pinstance()->randomReal(0.0, _waitshoot);
	/* Do this so they don't all shoot at once,	when you have several of them. */
}

void cCritterArmedRobot::setAge(Real age)
{
	cCritter::setAge(age);
	setWaitShoot(_waitshoot);
}

void cCritterArmedRobot::update(CPopView *pactiveview, Real dt)
{
	cCritterArmed::update(pactiveview, dt);	/* Do the basic cCritterArmed update to apply the forces,
		in _forcearray, which might include a cForceObjectSeek to approach the player
		and a cForceClassEvade to avoid the bullets. */
	aimAt(_ptarget);// Aim at the _ptarget (does nothing if _armed FALSE or if _ptarget NULL).
}

//===================== cCritterArmedPlayer ===========================================

cCritterArmedPlayer::cCritterArmedPlayer(cGame *pownergame):
cCritterArmed(pownergame),
_sensitive(FALSE)
{
	_collidepriority = cCollider::CP_PLAYER; /* Don't use the setCollidePriority mutator, as that
		forces a call to pgame()->buildCollider(); */
//	setDensity(cCritter::INFINITEDENSITY); 
		//So it can bull through.  But it's wiser to let the individual games do this.
	setAttitudeToMotionLock(FALSE); /* We want the player's
		attitude to be controlled by the listner actions and not by bumping into things,
		or moving with gravity. */
	setAimToAttitudeLock(TRUE); /* Normally
		we want a player to shoot in the dirction of his attitude. */
	cPolygon *ppolygon = new cPolygon(3);
	/* Now make it a thin isoceles triangle, with the apex at the 0th vertex.
		All that matters at first is the ratios of the numbers, as we will use
		seRadius to make the thing the right size. */
	ppolygon->setVertex(0, cVector(4.0, 0.0));
	ppolygon->setVertex(1, cVector(0.0, 1.0));
	ppolygon->setVertex(2, cVector(0.0, -1.0));
	ppolygon->setRadius(cCritter::PLAYERRADIUS); //Make it to a good size.
	setSprite(ppolygon);/* Normally the _prismdz will get changed to PLAYERPRISMDZ 
		by the cGame::setPlayer call */
	setPrismDz(cSprite::PLAYERPRISMDZ);
}

void cCritterArmedPlayer::Serialize(CArchive &ar)
{
	cCritterArmed::Serialize(ar);
	if (ar.IsStoring()) //Writing data.
	{
		ar << _sensitive;
	}
	else //reading data
	{
		ar >> _sensitive;
	}
}

void cCritterArmedPlayer::copy(cCritter *pcritter)
{
/*We need to overload the cCritter copy because if I have cCritterArmedRobot which is
a cCritterArmed, and it gets split in two by a replicate call, then I want the new
copy to have all the same shooting behavior as the old one.  In general, I should
overload copy for each of my critter child classes, but for now this one is the
most important.  The overload does the regular copy, then looks if the thing 
being copied is a cCritterArmed, and if it is then it copies the additional fields. */
	cCritterArmed::copy(pcritter);	
	if (!pcritter->IsKindOf(RUNTIME_CLASS(cCritterArmedPlayer)))
		return; //You're done if pcritter isn't a cCritterArmed*.
	cCritterArmedPlayer *pcritterplayer = (cCritterArmedPlayer *)(pcritter); /* I know it is a
		cCritterArmed at this point, but I need to do a cast, so the compiler will let me
		call a bunch of cCritterArmed methods. */
	_sensitive = pcritterplayer->_sensitive;
}

void cCritterArmedPlayer::reset()
{
	_lasthit_age = _age = 0.0;
	_health = PLAYERHEALTH;
	_score = 0;
	_position.setZero();
	_velocity.setZero();
	_acceleration.setZero();
	_spin.setZero();
	_speed = 0;
}

BOOL cCritterArmedPlayer::collide(cCritter *pcritter)
{
	BOOL collided = cCritter::collide(pcritter);
	if (collided && _sensitive && !pcritter->IsKindOf(RUNTIME_CLASS(cCritterWall)))
		damage(1);
	return collided;
}

int cCritterArmedPlayer::damage(int hitstrength)
{
   // Added by: Joseph E. Sutton
   //playSound("wav\\pop.wav");
	if (!(_shieldflag || recentlyDamaged()))
	{
		//playSound(cCritterArmedPlayer::DAMAGESOUND);
/* In some games we might want to recenter the player after damage, but for now let's not. */
//		_position.setZero();
//		_velocity.setZero();
	}
	return cCritter::damage(hitstrength);
}

void cCritterArmedPlayer::draw(cGraphics *pgraphics, int drawflags)
{ 
#ifdef HIGHLIGHTPLAYER
	// Draw a circle around the player so you know its size better.
	drawHighlight(pgraphics, cSprite::HIGHLIGHTRATIO);
#endif //HIGHLIGHTPLAYER
	cCritterArmed::draw(pgraphics, drawflags);
}

void cCritterArmedPlayer::feellistener(Real dt)
{
	cCritter::feellistener(dt);
	if ( pgame()->visibleplayer()) //Is not an offscreen player.
	{
		_bshooting = (pgame()->keystate(VK_SPACE) != cController::KEYOFF);
			 //TRUE if keystate is cController::KEYON or cController::KEYONLOCK
		if (pgame()->keystate(VK_LBUTTON) != cController::KEYOFF)//shoot with left mouse click
			//The controller will only have turned VK_LBUTTON on if if you left clicked the  
			//Shoot Cursor, left clicks with other cursors will be ignored by controller.
		{
			_bshooting = TRUE; 
			if (_plistener->GetRuntimeClass() != RUNTIME_CLASS(cListenerCursor))
					/* You don't want to call the aimAt method if your critter is 
						right on top of the cursor, as then there's no "aiming line"
						from critter to cursor. */
				aimAt(pgame()->cursorpos()); 
		}
	}
}

cCritterBullet* cCritterArmedPlayer::shoot()
{
	cCritterBullet *pbullet = cCritterArmed::shoot();
#ifdef PLAYERBULLETSPEEDUP
/* I used to just have 
	pbullet->addVelocity(_velocity), but this gives unattractive results. */
	Real bulletspeedup = _velocity % pbullet->tangent();
	if (bulletspeedup > 0.0)
		pbullet->addVelocity(bulletspeedup * pbullet->tangent()); //So bullets don't stack up.
#endif //PLAYERBULLETSPEEDUP
	return pbullet;
}
	
//===================== cCritterPlayer ===========================================

cCritterPlayer::cCritterPlayer(cGame *pownergame):
cCritterArmedPlayer(pownergame)
{
	_bshooting = FALSE;
}
