// Biota.cpp: implementation of the cBiota class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "biota.h"
#include "critter.h"
#include "critterwall.h" //For purgeNonPlayerNonWall
#include "game.h" //for constructing default _pgame. 
#include "spritepolygon.h" //For cPolygon::MF_ALL, used in spawn.
#include "pop.h" //for playSound
#include "critterarmed.h"

#define FREEZEFOCUSCRITTER
	/* Comment this in if you want the focus critter to be frozen, that is, not moved or aged.
We use this so that we can drag objects.  And at one time this seemed like a good feature 
so that I could fix a critter in place and examine it, but it seems to be too confusing
for users, so now in fact only the arrow Select cursor clicks set the focus critter. */
//============================= Macros ==========================
IMPLEMENT_SERIAL( cCritterArray, CObArray, 0);
IMPLEMENT_SERIAL( cBiota, cCritterArray, 0);

 //******** CONST STATICS **********************************************
 const int cBiota::NOINDEX = -1;


//==================cCritterArray=====================

cCritterArray::cCritterArray(const cCritterArray &critarray)
{
	SetSize(critarray.GetSize());
	for (int i=0; i< GetSize(); i++)
		ElementAt(i) = critarray.GetAt(i);
}
//==================cBiota=========================
cBiota::cBiota():_pgame(NULL)
{
//	_pgame = new cGame(this); //This seems wasteful.  Moot as I haven't come here yet.
}

cBiota::cBiota(cGame *pgame):
_pgame(pgame)
{}

cBiota::~cBiota()
{
	_free();
} 

void cBiota::_free() /* Delete all members.  This is used in desctructor and before
loading into an existing cBiota object. */
{
	processServiceRequests(); /* Just in case, it seems better to clear up any
		backlog lest there be some confusion. */
	for (int i=0; i<GetSize(); i++)
	{
		delete GetAt(i);
		ElementAt(i) = NULL; // Always get rid of a pointer as soon as it's bad.
	}
	RemoveAll();
}
	
//-------------------- cBiota Serialize methods -----------------------

void cBiota::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
		cCritterArray::Serialize(ar);
	else
	{
		/* We'll get a memory leak unles we make sure the cBiota being read into
			is completely emptied out. Note that the cGame constructor creates a
			cBiota* at startup, so we will indeed be reading into something nonempty. */
		_free(); // The default cBiota will be empty, this is just to be sure.
		cCritterArray::Serialize(ar);
		for (int i=0; i<GetSize(); i++)
			GetAt(i)->setOwner(this);
		for (i=0; i<GetSize(); i++)
			GetAt(i)->fixPointerRefs();
		updateMetric(); //Fix the _metrickey fields and the _metric.
	}
} 

void cBiota::purgeCritters(CRuntimeClass *pruntimeclass)
{ /*Rather than deleting the pointers and removing from the array, we use the
servicerequest mechanism, which handles things like _pgame->pFocus(), etc. */
	for (int i=0; i<GetSize(); i++)
		if (GetAt(i)->IsKindOf(pruntimeclass))
			GetAt(i)->delete_me();
	processServiceRequests();	
}

void cBiota::purgeNonPlayerCritters()
{ //See comment on purgeCritters.  purgeNonPlayerCritters gets rid of all but player.
	for (int i=0; i<GetSize(); i++)
		if (GetAt(i) != _pgame->pplayer())
			GetAt(i)->delete_me();
	processServiceRequests();	
}

void cBiota::purgeNonPlayerNonWallCritters()
{ //See comment on purgeCritters.  purgeNonPlayerCritters gets rid of all but player.
	for (int i=0; i<GetSize(); i++)
		if (GetAt(i) != _pgame->pplayer() && 
			!GetAt(i)->IsKindOf(RUNTIME_CLASS(cCritterWall)))
			GetAt(i)->delete_me();
	processServiceRequests();	
}

void cBiota::removeReferencesTo(cCritter *pdeadcritter)
{
//Remove references to pdeadcritter in any critter already in the cBiota array.
	for (int i=0; i<GetSize(); i++)
	{
		cCritter *pcritter = GetAt(i); //This may already be NULL if you're deleting the cBiota.
		if (pcritter)
			pcritter->removeReferencesTo(pdeadcritter);
	}
/* Also remove any references to pdeadcritter in any critter waiting to get into the cBiota 
	array. This fixes a subtle bug that would arise if I fired two bullets with cForceObjectSeek
	at the same target.  If the first bullet killed the target before the second bullet actually
	got added into the biota, then the second bullet would have a bad pointer. */
	for (i=0; i<_servicerequestarray.GetSize(); i++)
	{
		if (_servicerequestarray[i]._request == "add_me")
			_servicerequestarray[i]._pclient->removeReferencesTo(pdeadcritter);
	} 
}

void cBiota::Add(cCritter* pmember)
{
	ASSERT(_index(pmember) == cBiota::NOINDEX); /* Don't allow someone to add the same thing twice.
		This assert shouldn't ever get triggered, as I only call Add from inside the
		processServiceRequests call, and in there I check for this condition. */
	ASSERT(_pgame);
	for(int i=0; i<GetSize(); i++)
		_pgame->pcollider()->smartAdd(pmember, GetAt(i));
	/* I want to insert critters in such a way that if a critter uses the
	same texture as an existing critter, they will be stored next to each 
	other.  The reason is that there a time overhead for activating a
	texture, so it's faster to draw all same-textured critters one after
	the other. */
	if (!GetSize() || //If nothing in the array or...
		!(pmember->psprite()->usesTexture())) //It's a non-textured critter
		cCritterArray::Add(pmember); //Put it at the end of the array.
	else //look for a similarly textured critter.
	{
		int oldresourceID;
		int newresourceID = pmember->psprite()->resourceID();
		int insertindex = 1; /* Default position to insert at will be 1,
			right after the player. But if you have an offscreen player
			who's not in the array, you better make instertindex be 0.
			We'll check for this now.  It's safe to access ElementAt(0),
			because the if case just above took care of the empty array
			case. */
		if (!(ElementAt(0)->IsKindOf(RUNTIME_CLASS(cCritterArmedPlayer))))
				//Note that cPlayer inherits from cCritterArmedPlayer,
				//so don't use cCritterPlayer as the base class here.
			insertindex =0; //The offscreen player case.
		for (int i=0; i<GetSize(); i++)
		{
			oldresourceID = ElementAt(i)->psprite()->resourceID();
			if (oldresourceID == newresourceID)
			{
				insertindex = i+1; // We want to insert right after i.
				break;
			}
		}
		cCritterArray::InsertAt(insertindex, pmember); /* InsertAt puts
			pmember at insertindex, and shifts up by the index i of each
			member currently indexed at i >= insertindex. */
	}
	if (pmember)
		pmember->setOwner(this);
}

void cBiota::InsertAt(int index, cCritter* pmember)
{
	cCritterArray::InsertAt(index, pmember);
	if (pmember)
		pmember->setOwner(this);
}

int cBiota::_index(cCritter* pcritter)
{
	for (int i=0; i<GetSize(); i++)
		if (GetAt(i) == pcritter)
			return i;
	return cBiota::NOINDEX; //Means -1.  Use this to mean not found.
}

//-------------  cBiota service request methods ---------

void cBiota::addServiceRequest(cServiceRequest servicerequest)
{
	_servicerequestarray.Add(servicerequest);
}

BOOL cBiota::processServiceRequests()
{
	BOOL success = TRUE;
	int clientindex;
 /* Do two passes, first do all the deletes, then do the adds and other stuff.  The reason to get the 
deletes out of the way first is that when I add a critter to a cBiota I also plan to add all
relevant collision pairs to the the cCollider associtaed with the cBiota's owner cGame.  
And I wouldn't want to be setting up a collision for something I'm about to delete. */
	int i;
//The delete loop
	for (i=0; i<_servicerequestarray.GetSize(); i++)
	{
		if (_servicerequestarray[i]._request == "delete_me")
		{
			clientindex = _index(_servicerequestarray[i]._pclient);
			if (clientindex == cBiota::NOINDEX) //You already deleted this guy.
				success = FALSE;
			else
				_delete_me(clientindex);
		}		
	}
//The loop for add and other requests
	for (i=0; i<_servicerequestarray.GetSize(); i++)
	{
		clientindex = _index(_servicerequestarray[i]._pclient);
//We use the add request rather than doing Add out in the code.
		if (_servicerequestarray[i]._request == "add_me")
		{
			if (clientindex != cBiota::NOINDEX) //You already added this guy.
			{
				TRACE("Attempting to add a critter twice!");
				success = FALSE;
			}
			else
				Add(_servicerequestarray[i]._pclient); /* We overload the Add to 
					also update the _pgame->_pcollider. */
			continue; //Skip the rest of this loop step and go to the next i.
		}
//All the remaining requests depend on the critter already being a member.
		if (clientindex == cBiota::NOINDEX)
		{
			success = FALSE;
			continue; //Skip the rest of this block and go to the next i.
		}
		else if (_servicerequestarray[i]._request == "delete_me")
			; //do nothing, as we already handled the delete_me on the first pass through the loop.
		else if (_servicerequestarray[i]._request == "move_to_front")
			_move_to_front(clientindex);
		else if (_servicerequestarray[i]._request == "replicate")
			_replicate(clientindex);
		else if (_servicerequestarray[i]._request == "spawn")
			_spawn(clientindex);
		else if (_servicerequestarray[i]._request == "zap")
			_zap(clientindex);
		else //Tell programmer there's no handler for his service request string.
		{
			TRACE(_servicerequestarray[i]._request);
			TRACE(" request not supported by cBiota::processServiceRequests.\n");
		}
	}
	_servicerequestarray.SetSize(0); //You did them all, so empty it out.
	return success; /* FALSE means you couldn't find one of the _pclient 
		requesters.  Either someone put a bad value into the array or one
		of your members posted a request for a "delete_me" or a "convert..." 
		followed by another request, which can't be honored as the caller
		pointer's no longer there. */
}

void cBiota::_delete_me(int clientindex)
{
	if (GetAt(clientindex) == _pgame->pplayer()) //You can't delete the player.
		return;
	BOOL killingfocusflag =  (_pgame->pFocus() == GetAt(clientindex));
	delete GetAt(clientindex); /* Calls the critter's destructor.  This calls
		pgame()->removeReferencesTo(GetAt(clientindex)), which will (a) call 
		_pbiota->removeReferencesTo(GetAt(clientindex)) to check all critters in the cBiota and
		destroy any cCritter _ptarget or cForceObject _pnode variables that refer to me and
		(b) call pgame()->pcollider()->_pbiota->removeReferencesTo to remove the pairs. */
	ElementAt(clientindex) = NULL; // Always get rid of a pointer as soon as it's bad.
	RemoveAt(clientindex); //Never leave a bad pointer in the array.
	if (killingfocusflag)
		_pgame->setFocus(NULL);
}

void cBiota::_move_to_front(int clientindex)
{ /* Remove the critter  from the array and move all the others
	one index closer to the front. Then insert the critter at the front.  If the
	_pgame's player is in first place, put it after that, otherwise put it in first
	place.  Idea is to always keep any onscreen player on top. */
	if (GetSize() < 2) /* There's nothing to do if you have one or no members. */
		return;
	cCritter* pmovecritter = GetAt(clientindex);
	RemoveAt(clientindex);
	if (GetAt(0) == _pgame->pplayer()) //We know it's safe to do GetAt(0), as size was >= 2 before removing.
		InsertAt(1, pmovecritter); //After the player
	else
		InsertAt(0, pmovecritter); //On top.
}

void cBiota::_replicate(int clientindex)
{ 
	if (GetAt(clientindex) == _pgame->pplayer()) //You can't replicate the player.
		return;
	cCritter *ptemp = GetAt(clientindex)->clone();
	ptemp->mutate(cCritter::MF_NUDGE); //So it's not on top of me.
	Add(ptemp); /* We overload the Add to also update the _pgame->_pcollider. */
}

void cBiota::_spawn(int clientindex)
{ 
	if (GetAt(clientindex) == _pgame->pplayer()) //You can't spawn the player.
		return;
	cVector oldposition, oldvelocity;
	CRuntimeClass *pclientclass = GetAt(clientindex)->GetRuntimeClass();
	for( int i=0; i<GetSize(); i++)
	{ /* Don't spawn onto yourself and don't spawn onto a critter of a different class type.
You don't spawn to the player for instance becasue if you and player are both cCritterArmed, then
calling the copy function would change the player's _pbulletclass  */
		if (i==clientindex || GetAt(i)->GetRuntimeClass() != pclientclass)
			continue;
		oldposition = GetAt(i)->position(); //Save position.
		oldvelocity = GetAt(i)->velocity(); //Save velocity.
/* I could clone each critter if I were interested in behavior changes.  But this would cause problems
because I'm not sure the player should be changed, also because there is a connection between
cCritterArmed and cCritterBullet.  If I ever want to copy behavior I might use a limited spawn that
only clones among some copatible critters.
		delete ElementAt(i); //Immediately replace this with a good critter.
		ElementAt(i) = GetAt(clientindex)->clone();
Instead of cloning the critter I will copy the critter params and let this call clone the sprite. */
		ElementAt(i)->copy(GetAt(clientindex)); 
		ElementAt(i)->mutate(cSprite::MF_ALL | cPolygon::MF_ALL);
		ElementAt(i)->moveTo(oldposition);
		ElementAt(i)->setVelocity(oldvelocity);
	}
}

void cBiota::_zap(int clientindex)
{ 
	GetAt(clientindex)->randomize(cCritter::MF_VELOCITY | cSprite::MF_ALL | cPolygon::MF_ALL);
}
//------------------cGame Accessor methods----------
cCritter* cBiota::player(){return _pgame->pplayer();}
cRealBox cBiota::border(){return _pgame->border();}

//---------------- cBiota Pick methods -------------------

//Do pick for points

cCritter* cBiota::pickLowestIndexTouched(const cVector &vclick)
{ /* Draw draws the lower-numbered critters last, so those are visually "on top".)*/
	for( int i=0; i<GetSize(); i++)
	{
		if (GetAt(i)->touch(vclick)) 
			return GetAt(i);
	}
	return NULL;
}

cCritter* cBiota::pickClosestTouched(const cVector &vclick)
{
	cCritterArray toucharray = touchArray(vclick);
	if (toucharray.GetSize() == 0)
		return NULL;
	Real closestdistance = BIG_REAL, testdistance;
	int closesti = 0;
	for( int i=0; i<toucharray.GetSize(); i++)
	{
		testdistance = toucharray[i]->distanceTo(vclick);
		if (testdistance < closestdistance)
		{
			closestdistance = testdistance;
			closesti = i;
		}
	}
	return toucharray[closesti];
}

cCritterArray cBiota::touchArray(const cVector &vclick)
{
	cCritterArray toucharray;
	for( int i=0; i<GetSize(); i++)
		if (GetAt(i)->touch(vclick))
			toucharray.Add(GetAt(i)); 
	return toucharray;
}	

//And then do it for cCritter center points

cCritterArray cBiota::touchArray(cCritter* pcrittercenter)
{
	cCritterArray toucharray;
	for( int i=0; i<GetSize(); i++)
		if (pcrittercenter->touch(GetAt(i)))
			toucharray.Add(GetAt(i)); 
	return toucharray;
}	

cCritter* cBiota::pickClosestCritter(cCritter *pcrittercenter, CRuntimeClass *pruntimeclass,
	BOOL includesubclasses)
{
	cCritter *pclose = NULL;
	cCritter *ptest;
	Real closestdistance = BIG_REAL;
	Real testdistance;
	for (int i=0; i<GetSize(); i++)
	{
		ptest = GetAt(i);
		if (ptest == pcrittercenter)
			continue;
		if(!(
			(includesubclasses && ptest->IsKindOf(pruntimeclass)) ||
			(!includesubclasses && ptest->GetRuntimeClass()==pruntimeclass)
		))
			continue;
		testdistance = pcrittercenter->distanceTo(ptest);
		if (testdistance < closestdistance)
		{
			closestdistance = testdistance;
			pclose = ptest;
		}
	}
	return pclose;
}

//And then do it for cLine

cCritter* cBiota::pickTopTouched(const cLine &sightline, cCritter *pcritterignore)
{ /*Same code as pickClosestTouched but with a different sorting critereon;
	we use lineCoord(sightline) instead of distanceTo(sightline). */
	cCritterArray toucharray = touchArray(sightline, pcritterignore);
	if (toucharray.GetSize() == 0)
		return NULL;
	Real closestdistance = BIG_REAL, testdistance;
	int closesti = 0; //Everyone in the array is acceptable, so start with 0 is ok.
	for( int i=0; i<toucharray.GetSize(); i++)
	{
		testdistance = sightline.lineCoord(toucharray[i]->position());
		if (testdistance < closestdistance)
		{
			closestdistance = testdistance;
			closesti = i;
		}
	}
	return toucharray[closesti];
}

cCritter* cBiota::pickClosestTouched(const cLine &sightline, cCritter *pcritterignore)
{
	cCritterArray toucharray = touchArray(sightline, pcritterignore);
	if (toucharray.GetSize() == 0)
		return NULL;
	Real closestdistance = BIG_REAL, testdistance;
	int closesti = 0;
	for( int i=0; i<toucharray.GetSize(); i++)
	{
		testdistance = toucharray[i]->distanceTo(sightline);
		if (testdistance < closestdistance)
		{
			closestdistance = testdistance;
			closesti = i;
		}
	}
	return toucharray[closesti];
}

cCritter* cBiota::pickClosestAhead(const cLine &sightline, cCritter *pcrittercenter,
	Real visionangle, CRuntimeClass *pruntimeclass, BOOL includesubclasses)
{
	Real closestdistance = BIG_REAL, testdistance, angle;
	int closesti = cBiota::NOINDEX; //Possible that you won't find a single one.
	for( int i=0; i<GetSize(); i++)
	{
		cCritter *ppossible = GetAt(i);
		angle = angleBetween(sightline._tangent, 
			ppossible->position() - pcrittercenter->position());
		if(!( //Only go for the right type of critter.
			(includesubclasses && ppossible->IsKindOf(pruntimeclass)) ||
			(!includesubclasses && ppossible->GetRuntimeClass()==pruntimeclass)
		))
			continue;//Skip this critter.
		if (ppossible == pcrittercenter || fabs(angle) > visionangle / 2.0) //Only go for those ahead.
			continue; //Skip this critter.
		testdistance = ppossible->distanceTo(sightline); //Pick closest to sightline
	//	testdistance = ppossible->distanceTo(pcrittercenter); //OR Pick closest to pcrittercenter
		if (testdistance < closestdistance)
		{
			closestdistance = testdistance;
			closesti = i;
		}
	}
	if (closesti == cBiota::NOINDEX)
		return NULL;
	else
		return GetAt(closesti);
}

cCritterArray cBiota::touchArray(const cLine &sightline, cCritter *pcritterignore)
{
	cCritterArray toucharray;
	for( int i=0; i<GetSize(); i++)
		if (GetAt(i)->touch(sightline) && GetAt(i) != pcritterignore)
			toucharray.Add(GetAt(i)); 
	return toucharray;
}	

//---------------- cBiota Array-Walking methods -------------------

void cBiota::draw(cGraphics *pgraphics, int drawflags)
{
	cCritter *pcritter;
	if (GetSize() == 0) //Put this in for safety to avoid worrying BoundsChecker.
		return;
	for (int i = GetSize()-1; i>=0; i--) /* Draw the lower-numbered critters last, 
		so those are visually "on top".)*/
	{
		pcritter = GetAt(i);
		if (!pcritter)
			return;
		pcritter->draw(pgraphics, drawflags);
		if (pcritter == _pgame->pFocus())
			pcritter->drawHighlight(pgraphics, cSprite::HIGHLIGHTRATIO);
		if (i==0) /* You don't logically need this break, but it could make BoundsChecker uneasy
			to see i go down to -1 before exiting the loop. */
			break;
	}
}

void cBiota::setNewgeometryflag(BOOL onoff)
{
	for( int i=0; i<GetSize(); i++)
		GetAt(i)->psprite()->setNewgeometryflag(onoff);
}

int cBiota::count(CRuntimeClass *pruntimeclass, BOOL includesubclasses)
{
	int found = 0;
	for( int i=0; i<GetSize(); i++)
		if(
			(includesubclasses && GetAt(i)->IsKindOf(pruntimeclass)) ||
			(!includesubclasses && GetAt(i)->GetRuntimeClass()==pruntimeclass)
		)
			found++;
	return found;
}

void cBiota::update(CPopView *pactiveview, Real dt)
{
	for( int i=0; i<GetSize(); i++)
		GetAt(i)->update(pactiveview, dt);
}

void cBiota::feellistener(Real dt)
{
	for( int i=0; i<GetSize(); i++)
		GetAt(i)->feellistener(dt);
}

void cBiota::move(Real dt)
{
	for( int i=0; i<GetSize(); i++)
// We don't move a critter it is the focus critter AND it's not the player.
#ifdef FREEZEFOCUSCRITTER
		if (GetAt(i) != pgame()->pFocus() || GetAt(i) == pgame()->pplayer())
#endif //FREEZEFOCUSCRITTER
			GetAt(i)->move(dt);
}

void cBiota::animate(Real dt)
{
	for( int i=0; i<GetSize(); i++)
		GetAt(i)->animate(dt); //Perhaps rotate it or something.
}

void cBiota::setWrapflag(int wrapflag)
{
	for( int i=0; i<GetSize(); i++)
		GetAt(i)->setWrapflag(wrapflag);
}

 //=============Metric methods
void cBiota::updateMetric()
{
#ifdef USEMETRIC
/* This next line is important, for otherwise the hashtable will keep growing and growing as
new critters appear and generate new keys.  Just calling CMap::RemoveAll() is not enough, as
this call doesn't resize the hash table. The setSizeForCritterCount(crittercount) deletes the old
members of the hash table array, deletes the hash table array, and sets the hash table array size to the
recommended value of the first prime greater than 1.2 times the anticipated number of entries,
which is the square of crittercount. */
	_metric.setSizeForCritterCount(GetSize());
	for (int i=0; i<GetSize(); i++)
	{
		GetAt(i)->setMetricKey(i);
		for (int j=0; j<i; j++) 
		{
			cVector direction = GetAt(j)->position() - GetAt(i)->position();
			Real distance = direction.magnitude();
			if (distance > SMALL_REAL)
				direction /= distance;
			else
				direction = cVector(1,0);
			_metric.setAt(i, j, distance, direction);
			_metric.setAt(j, i, distance, -direction);
		}
	}	
#endif //USEMETRIC
}

Real cBiota::distance(cCritter *pa, cCritter *pb)
{
#ifdef USEMETRIC
	return _metric.distance(pa, pb);
#else //Don't use _metric
	return pa->position().distanceTo(pb->position());
#endif //USEMETRIC
}

cVector cBiota::direction(cCritter *pa, cCritter *pb)
{
#ifdef USEMETRIC
	return _metric.direction(pa, pb);
#else //Don't use _metric
	cVector dir = pb->position() - pa->position();
	dir.normalize();
	return dir;
#endif //USEMETRIC

}

cDistanceAndDirection cBiota::distanceAndDirection(cCritter *pa, cCritter *pb)
{
#ifdef USEMETRIC
	return _metric.distanceanddirection(pa, pb);
#else //Don't use _metric
	cVector dir = pb->position() - pa->position();
	Real distance = dir.magnitude();
	if (distance > SMALL_REAL)
		dir /= distance;
	else
		dir = cVector(1,0); //default unit vector
	return cDistanceAndDirection(distance, dir);
#endif //USEMETRIC
}


		