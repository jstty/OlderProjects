// Collider.cpp: implementation of the cColliderPair and cCollider class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "critter.h"
#include "collider.h"
#include "biota.h"


IMPLEMENT_DYNCREATE(cColliderPair, CObject);
IMPLEMENT_DYNCREATE(cColliderLevel, CObList); 
IMPLEMENT_DYNCREATE(cCollider, CObject); 

const int cCollider::DONTCOLLIDE = 2;
/* I pick the next three numbers so they are symmetric for the ASSERT call in smartAdd */
const int cCollider::COLLIDEASCALLER = 1;
const int cCollider::COLLIDEASARG = -1;
const int cCollider::COLLIDEEITHERWAY = 0;
Real cCollider::CP_CRITTER = 100.0;
Real cCollider::CP_PLAYER = 200.0;
Real cCollider::CP_SILVERBULLET = 300.0;
Real cCollider::CP_BULLET = 400.0;
Real cCollider::CP_WALL = 500.0;
Real cCollider::CP_MAXIMUM = 1000000.0;
Real cCollider::CP_MINIMUM = 0;

//===========================cColliderPair=============================

inline BOOL cColliderPair::collideThePair(BOOL checkpriority)
{
	BOOL collided;

	ASSERT (_pcrittercaller && _pcritterarg); //Is skipped in RELEASE build.

#ifdef LIMITCOLLISIONSPERUPDATE
	if (checkpriority)
	{
		/* There are various strategies I could use to limit the collisions.  I might, for
		instance only allow higher pririty collisions.  Or I might allow
		only one collision per cGame::collide call by checking if the
		lastCollidePartnerPriority() != cCollider::CP_MINIMUM */
		if (_pcrittercaller->lastCollidePartnerPriority() >
				_pcritterarg->collidePriority())
			return FALSE;
		if (_pcritterarg->lastCollidePartnerPriority() >
			_pcrittercaller->collidePriority())
			return FALSE;
	}
#endif //LIMITCOLLISIONSPERUPDATE
	

	collided = _pcrittercaller->collide(_pcritterarg);

#ifdef LIMITCOLLISIONSPERUPDATE
	if (collided)
	{
		_pcrittercaller->setLastCollidePartnerPriority(_pcritterarg->collidePriority());
		_pcritterarg->setLastCollidePartnerPriority(_pcrittercaller->collidePriority());
	}
#endif //LIMITCOLLISIONSPERUPDATE

	return collided;
}

//===========================cColliderLevel=============================

void cColliderLevel::RemoveAll()
{
	POSITION pos = GetHeadPosition();
	while(pos != NULL)
		delete GetNext(pos);
	CObList::RemoveAll();
}

void cColliderLevel::removeReferencesTo(cCritter *pdeadcritter)
{
	POSITION currpos, pos = GetHeadPosition();
	while(pos != NULL)
	{
		currpos = pos; //The position of ppair, in case we need to delete it.
		cColliderPair *ppair = GetNext(pos); //Bumps pos to next position.
		if(ppair->involves(pdeadcritter))
		{
			delete ppair;
			RemoveAt(currpos);
		}
	}
}

void cColliderLevel::iterateCollide(BOOL checkpriority)
{
	POSITION pos = GetHeadPosition();
	while(pos != NULL)
		 GetNext(pos)->collideThePair(checkpriority);
}

//===========================cCollider=============================

void cCollider::smartAdd(cCritter *pcritter, cCritter* pcritterother)
{
	cColliderPair *pnewpair = NULL;
	int collideswith = pcritter->collidesWith(pcritterother);
	int othercollideswith = pcritterother->collidesWith(pcritter);
	if (collideswith == cCollider::DONTCOLLIDE || othercollideswith == cCollider::DONTCOLLIDE)
		return; //Don't collide if either one is unwilling, even if the other was willing. */
	if (collideswith == cCollider::COLLIDEASCALLER || collideswith == cCollider::COLLIDEEITHERWAY )
		pnewpair = new cColliderPair(pcritter, pcritterother);
	else //(collideswith == cCollider::COLLIDEASARG)
		pnewpair = new cColliderPair(pcritterother, pcritter);
	if ((pnewpair->_pcrittercaller->collidePriority() == cCollider::CP_WALL) ||
		 (pnewpair->_pcritterarg->collidePriority() == cCollider::CP_WALL))
		_wallpairs.AddTail(pnewpair);
	else
		_nonwallpairs.AddTail(pnewpair);

	//ASSERT(collideswith == -othercollideswith);
		/* We chose the collision type codes to make this ASSERT
		likely at this point, but it might not always be true.  Only comment it in
		for testing. Do note that we bail before we hit it if either type is DONTCOLLIDE. */
}

void cCollider::removeAll()
{
	_wallpairs.RemoveAll();
	_nonwallpairs.RemoveAll();
}

void cCollider::removeReferencesTo(cCritter *pdeadcritter)
{
	_wallpairs.removeReferencesTo(pdeadcritter);
	_nonwallpairs.removeReferencesTo(pdeadcritter);
}

void cCollider::build(cBiota *pbiota)
{
	removeAll(); //Clear it out.
	for( int i=0; i<pbiota->GetSize(); i++)
		for( int j=i+1; j<pbiota->GetSize(); j++)
			smartAdd(pbiota->GetAt(i), pbiota->GetAt(j));
}

void cCollider::iterateCollide()
{
	_wallpairs.iterateCollide(FALSE);
	_nonwallpairs.iterateCollide(TRUE);
}
