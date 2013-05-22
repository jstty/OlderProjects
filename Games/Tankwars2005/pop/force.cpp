#include "stdafx.h"
#include "force.h"
#include "biota.h"
#include "critterarmed.h"

IMPLEMENT_SERIAL( cForce, CObject, 0 );
IMPLEMENT_SERIAL( cForceGravity, cForce, 0 );
IMPLEMENT_SERIAL( cForceDrag, cForce, 0 );
IMPLEMENT_SERIAL( cForceVortex, cForceDrag, 0 );
IMPLEMENT_SERIAL( cForceObject, cForce, 0 );
IMPLEMENT_SERIAL( cForceObjectSpringRod, cForceObject, 0 );
IMPLEMENT_SERIAL( cForceObjectSeek, cForceObject, 0 );
IMPLEMENT_SERIAL( cForceClass, cForce, 0 );
IMPLEMENT_SERIAL( cForceClassEvade, cForceClass, 0 );
IMPLEMENT_SERIAL( cForceEvadeBullet, cForceClassEvade, 0 );
IMPLEMENT_SERIAL(cForceObjectGravity, cForceObject, 0);

#define SCALESTEERINGWITHMASS
		/* The SCALESTEERINGWITHMASS switch can be used in 
		cForceObjectSeek::force and in cForceClassEvade::force.  If we
		comment SCALESTEERINGWITHMASS in, then we multiply the returned force by
		pcritter->mass() to counteract the fact that  the cCritter feelforce will
		divide the returned force by mass(). The justification for commenting 
		in SCALESTEERINGWITHMASS woudl be a feeling that a more massive object will
		evade and pursue with a more powerful motor so that	big and small objects would
		evade and pursue in the same way. A justification for not commenting in
		SCALESTEERINGWITHMASS would be that in the real world smaller animals move more
		nimbly and larger ones are more sluggish.  You decide which works best with your
		game. */
#define REYNOLDSTRICK
		/* REYNOLDSTRICK applies to the 
		cForceObjectSeek::force and  cForceClassEvade::force.  The 
		idea is inspired by Craig Reynolds, "Steering Behaviors for Autonomous Characters."
		Rather than applying a force in the desired direction of motion, he applies a force
		that is in the direction of the DIFFERENCE between the critter moving at max speed in
		the desired direction, and the critter's current velocity. It steers the critters
		much better, indeed it makes them almost too smart. */
//Statics======================================
Real cForce::INTENSITY = 5.0;
Real cForceEvadeBullet::INTENSITY = 8.0; //How strongly to accelerate away from bullets.
Real cForceEvadeBullet::DARTSPEEDUP = 2.0; // How much to speed up when fleeing bullets.
 
 //===================cForceClassEvade Statics ===========
 Real cForceClassEvade::COSINEIGNOREANGLE = -0.8; /* Ignore a nearest enemy whose direction
 	of motion makes an angle less than this with the direction to you.  If I put -1.0 here that
 	means not to ignore any enemy at all and to be skittish.   If I put 0.0 here that means
 	ignore any enemy that is not at all moving towards me and be fairly bold.  Normally I use 
 	something like -0.2, but I can use any number between -1.0 and 1.0. */ 
 Real cForceClassEvade::COSINESMALLANGLE = cos(PI/40); /* Move off to the side if the velocity of
 	the thing chasing you is with a cone of twice this angle size around your the direction
 	towards you.  cos changes very slowly near 0.  	cos(PI/40) is 0.997 and cos(PI/7) about 0.9. 
	So PI/40 would mean 2*180/40 degrees or 9 degrees.  Normally
 	is something like 0.99 or so, but can be any number between -1.0 and 1.0*/
 UINT cForceClassEvade::TURNPERSONALITYBIT = 0x00000020; 

//=====================Code=====================

cForce* cForce::clone()
{
	CRuntimeClass *pRuntimeClass = GetRuntimeClass();
	cForce *pforce = (cForce*)(pRuntimeClass->CreateObject());
	pforce->copy(this);
	return pforce;
}

void cForce::copy(cForce *pforce)
{
	_intensity = pforce->_intensity;
}

void cForce::Serialize(CArchive &ar)
{
	CObject::Serialize(ar);
	if (ar.IsStoring()) //Writing data.
	{
		ar <<  _intensity;
	}
	else //reading data
	{
		ar >> _intensity;
	}
}

//============ cForceGravity ======================
cVector cForceGravity::force(cCritter *pcritter)
{
	return _intensity * pcritter->mass() * _pulldirection;
}

void cForceGravity::copy(cForce *pforce)
{
	cForce::copy(pforce);
	if (!pforce->IsKindOf(RUNTIME_CLASS(cForceGravity)))
		return; 
	cForceGravity *pforcechild = (cForceGravity *)(pforce); 
	_pulldirection = pforcechild->_pulldirection;
}

void cForceGravity::Serialize(CArchive &ar)
{
	cForce::Serialize(ar);
	if (ar.IsStoring()) //Writing data.
	{
		ar <<  _pulldirection;
	}
	else //reading data
	{
		ar >> _pulldirection;
	}
}
//============ cForceDrag ======================
cVector cForceDrag::force(cCritter *pcritter)
{
	Real area = pcritter->radius()*pcritter->radius();
	Real mass = pcritter->mass();
	return cVector(area * _intensity * (_windvector - pcritter->velocity()));
}

void cForceDrag::copy(cForce *pforce)
{
	cForce::copy(pforce);
	if (!pforce->IsKindOf(RUNTIME_CLASS(cForceDrag)))
		return; 
	cForceDrag *pforcechild = (cForceDrag *)(pforce); // Cast so as to access fields.
	_windvector = pforcechild->_windvector;
}

void cForceDrag::Serialize(CArchive &ar)
{
	cForce::Serialize(ar);
	if (ar.IsStoring()) //Writing data.
	{
		ar <<  _windvector;
	}
	else //reading data
	{
		ar >> _windvector;
	}
}
//============ cForceVortex ======================
cVector cForceVortex::force(cCritter *pcritter)
{
	_windvector = (pcritter->position() - _eyeposition);
	_windvector.turn(_spiralangle);
	return cForceDrag::force(pcritter);
}

void cForceVortex::copy(cForce *pforce)
{
	cForceDrag::copy(pforce);
	if (!pforce->IsKindOf(RUNTIME_CLASS(cForceVortex)))
		return; 
	cForceVortex *pforcechild = (cForceVortex *)(pforce); // Cast so next lines work.
	_eyeposition = pforcechild->_eyeposition;
	_spiralangle = pforcechild->_spiralangle;
}

void cForceVortex::Serialize(CArchive &ar)
{
	cForceDrag::Serialize(ar);
	if (ar.IsStoring()) //Writing data.
	{
		ar <<  _eyeposition << _spiralangle;
	}
	else //reading data
	{
		ar >>  _eyeposition >> _spiralangle;
	}
}

//=========== ForceObject ============

void cForceObject::Serialize(CArchive &ar)
{
	cForce::Serialize(ar); //Does nothing but call CObject::Serialize(ar).
	if (ar.IsStoring()) //Writing data.
	{
		if (_pnode && _pnode->pownerbiota())
			_nodeindex = _pnode->pownerbiota()->_index(_pnode);
				 //Trick to save a nonserializiable pointer reference.
		else
			_nodeindex = cBiota::NOINDEX;
		ar << _nodeindex;
	}
	else //reading data
	{
	//Dummy index for nonserializable pointer reference variables.
		ar >> _nodeindex; /* It's up to the critter that has this force in its _forcearray to
			make a call to cForceObject::fixPointerRefs(_pownerbiota) to replace this index by a
			pointer.  This call will cascade out of the cCritter::fixPointerRefs() which is
			made at the end of the load case of the cBiota::Serialize method.  We can't 
			do the fixPointerRefs calls until all the critters have been loaded, which is
			why we leave it to cBiota to invoke the calls.  */
		_pnode = NULL;
	}
}

void cForceObject::copy(cForce *pforce)
{
	cForce::copy(pforce);
	if (!pforce->IsKindOf(RUNTIME_CLASS(cForceObject)))
		return; 
	cForceObject *pForceObject = (cForceObject *)(pforce);
	_pnode = pForceObject->_pnode; //Will cause a problem if pasting to a different document.
}

void cForceObject::fixPointerRefs(cBiota *pownerbiota)
{
	if (!pownerbiota)
		return;
	else
		_pnode = pownerbiota->GetAt(_nodeindex); 
				//Note that GetAt returns NULL if _nodeindex is cBiota:: NOINDEX
}

/* The cForceObjectAcceleateTowards:force code is below next to ForceClassEvade::force,
as both are "steering behaviors." */
	
//=============== cForceClass ==============

void cForceClass::copy(cForce *pforce)
{
	cForce::copy(pforce);
	if (!pforce->IsKindOf(RUNTIME_CLASS(cForceClass)))
		return; 
	cForceClass *pforcechild = (cForceClass *)(pforce); 
	_pnodeclass = pforcechild->_pnodeclass;
	_includechildclasses = pforcechild->_includechildclasses;
}


void cForceClass::Serialize(CArchive &ar)
{
	cForce::Serialize(ar);
		/* I had a  hell of a time figuring out how to serialize the
			CRuntimeClass *_pnodeclass.
			(1) You can't	call _pnodeclass.Serialize(ar), as this is not a method of
				CRuntimeClass.
			(2) Nor can you save off the CRuntimeClass m_lpszClassName field and try and 
				use RUNTIME_CLASS to reconstruct it, as RUNTIME_CLASS requires a literal 
				argument and not a CString.
			(3)  MFC provides a CArchive::SerializeClass(CRuntimeClass *prtc). But it 
				doesn't do the job either.  It's actually designed more for use as a 
				compatibility type-checker. If I put in ar.SerializeClass(_pnodeclass),  
				when I save and load, I don't get anything read back into _pnodeclass 
				because SerializeClass treats its argument as a const and won't change it 
				in the load! 
			(4) What DOES work is to save with ar.WriteClass(_pnodeclass) and load with 
			_pnodeclass = ar.ReadClass(). */
	if (ar.IsStoring()) //Writing data.
	{
		ar.WriteClass(_pnodeclass);
		ar <<  _includechildclasses;
	}
	else //reading data
	{
		_pnodeclass = ar.ReadClass();
		ar >>  _includechildclasses ;
	}
}
//=============== cForceClassEvade ==============

void cForceClassEvade::copy(cForce *pforce)
{
	cForceClass::copy(pforce);
	if (!pforce->IsKindOf(RUNTIME_CLASS(cForceClassEvade)))
		return; 
	cForceClassEvade *pforcechild = (cForceClassEvade *)(pforce); 
	_dartspeedup = pforcechild->_dartspeedup;
}

void cForceClassEvade::Serialize(CArchive &ar)
{
	cForceClass::Serialize(ar);
	if (ar.IsStoring()) //Writing data.
		ar <<  _dartspeedup;
	else //reading data
		ar >>  _dartspeedup;
}

cVector cForceClassEvade::force(cCritter *pcritter)
{
	cVector evadedirection, evadeforcevector;	
	cCritter* pclosestcritter = pcritter->pownerbiota()->pickClosestCritter(pcritter,
		_pnodeclass, _includechildclasses);
//Case (1) No enemies to evade ----------------------------------------------
	if (!pclosestcritter) //NULL if there aren't any of these guys around
	{
		pcritter->restoreMaxspeed();	//Go back to my normal non-darting speed and bail.
		return cVector::ZEROVECTOR;
	}
	evadedirection = pclosestcritter->directionTo(pcritter); /* Start with a unit vector that 
		points	from my enemy towards me. */
	Real cosangle = evadedirection % pclosestcritter->tangent(); /* Dot product of two
			unit vectors is the cosine of the angle between them.  I can use the cosine to figure
			out if the enemy is headed away from me (cosangle < 0) , generally towards me
			(cosangle > 0),	or directly towards me (cosangle near 1.0). */
//Case (2) Closest enemy is moving away from me. ------------------------------
	if (cosangle <  cForceClassEvade::COSINEIGNOREANGLE) // If nearest enemy is moving away, relax.
	{
		pcritter->restoreMaxspeed();	//Go back to my normal non-darting speed and bail.
		return cVector::ZEROVECTOR;
	}
//Case (3a) Closest enemy is directly towards  me. ------------------------------
	if ( cosangle > cForceClassEvade::COSINESMALLANGLE)/* If the nearest enemy is heading close
			to straight towards me, I shouldn't run straight away like a rabbit down a railorad
			track.  So in this case I'll head off at a 90 degree angle.  I'll use a	bit of the 
			pointer as a "personality trait" to consistently act like a "righty" or a "lefty" in
			terms of which side of the railroad track I jump off of. */
		evadedirection.turn(
			(cForceClassEvade::TURNPERSONALITYBIT & pcritter->personality())?PI/2:-PI/2);
//Case (3a and 3b) Closest enemy is moving towards me, directly or otherwise.
	pcritter->setTempMaxspeed(_dartspeedup * pcritter->maxspeedstandard()); 
		//Go faster while I'm darting away.
#ifdef REYNOLDSTRICK
	evadeforcevector = (pcritter->maxspeed()*evadedirection) - pcritter->velocity(); 
	evadeforcevector.setMagnitude(_intensity);
#else //not using the REYNOLDSTRICK
	evadeforcevector = _intensity * evadedirection;
#endif //REYNOLDSTRICK
#ifdef SCALESTEERINGWITHMASS
	evadeforcevector *= pcritter->mass();
#endif //SCALESTEERINGWITHMASS
	return _intensity * evadeforcevector;
}

//------ ForceObjectSeek  

cVector cForceObjectSeek::force(cCritter *pcritter)
{
	if (!_pnode)
		return cVector::ZEROVECTOR;
#ifdef REYNOLDSTRICK
	cVector pursueforcevector = 
		(pcritter->maxspeed()*pcritter->directionTo(_pnode)) - pcritter->velocity(); 
	pursueforcevector.setMagnitude(_intensity);
#else //not using REYNOLDSTRICK
	cVector pursueforcevector = _intensity * pcritter->directionTo(_pnode);
#endif //REYNOLDSTRICK 
#ifdef SCALESTEERINGWITHMASS
	pursueforcevector *= pcritter->mass();
#endif //SCALESTEERINGWITHMASS
	return  pursueforcevector;
}

//=============== cForceEvadeBullet ==============

cForceEvadeBullet::cForceEvadeBullet(): //Just call the baseclass constructor with args.
	cForceClassEvade(cForceEvadeBullet::INTENSITY, cForceEvadeBullet::DARTSPEEDUP,
		RUNTIME_CLASS(cCritterBullet), FALSE)
{}

cForceEvadeBullet::cForceEvadeBullet(Real dartacceleration, Real dartspeedup, BOOL includechildclasses):
	cForceClassEvade(dartacceleration, dartspeedup,	RUNTIME_CLASS(cCritterBullet), includechildclasses)
		//Just call the baseclass constructor with args.
{}

//============cForceObjectSpringRod================

cVector cForceObjectSpringRod::force(cCritter *pcritter)
{
	if (!_pnode)
		return cVector::ZEROVECTOR;
	if (pcritter->distanceTo(_pnode) < _rodlength)
	{
		pcritter->moveTo(_pnode->position()+
			_rodlength*_pnode->directionTo(pcritter), TRUE); /* The TRUE arg means
				to allow the motion cause a change in pcritter's _tangent, _normal, etc. */
		return cVector::ZEROVECTOR;
	}
	return _intensity * (_pnode->position() - pcritter->position());
}

void cForceObjectSpringRod::copy(cForce *pforce)
{
	cForceObject::copy(pforce);
	if (!pforce->IsKindOf(RUNTIME_CLASS(cForceGravity)))
		return; 
	cForceObjectSpringRod *pforcechild = (cForceObjectSpringRod *)(pforce); 
	_rodlength = pforcechild->_rodlength;
}

void cForceObjectSpringRod::Serialize(CArchive &ar)
{
	cForceObject::Serialize(ar);
	if (ar.IsStoring()) //Writing data.
	{
		ar <<  _rodlength;
	}
	else //reading data
	{
		ar >> _rodlength;
	}
}

//=================cForceObjectGravity===========

cVector cForceObjectGravity::force(cCritter *pcritter)
{
	if (!_pnode)
		return cVector::ZEROVECTOR;
	cDistanceAndDirection dirdic = 
		pcritter->distanceAndDirectionTo(_pnode);
	if (dirdic._distance < SMALL_REAL)
		return cVector::ZEROVECTOR;
	Real pull = (_intensity * 
		 _pnode->mass() *
		 pcritter->mass()) / 
		((dirdic._distance)*(dirdic._distance));
	return pull * dirdic._direction;
}