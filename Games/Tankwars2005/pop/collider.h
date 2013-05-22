//////////////////////////////////////////////////////////////////////
// Collider.h: interface for the cCollisonPair, cCollider class.
//
//////////////////////////////////////////////////////////////////////

#ifndef COLLIDER_H
#define COLLIDER_H
#include "realnumber.h"

class cCritter; //We mention cCritter * members and args.
class cBiota; //We mention cBiota * args.

/* 	A List gives better behavior than an array because we will end up with fairly large collections
of pairs, like 400 of them with 20 critters, and if you remove a critter this means deleting 20
member pairs from the collection.  In the worst case these would all be near the front, and if
delete them one by one from an array, then after each delete you have to move all ~400 remaining
array members down one slot.  In other words you'd get ~8000 moves, an N-cubed algorithm.  And 
this isn't just a fantasy, if you do run with an Array you'll see big lurches in the runspeed
when you shoot an asteroid --- you'll only see this on certain machines though, on some you
won't notice it.  Another bad thing about the Array approach is that I was in fact seeing some
freeze-ups of the program when using it, and I have a feeling this may be because it unduly
fragments the memory unduly, though maybe the bug was only a transient coincidence.
	We use type-safe arrays or lists in any case.  I could have just used a CPtrArray or a CPtrList, 
but then I'd have to cast the pointers as I got them out. There's no noticeable speed overhead for
using the typesafe templates. 
	I prefer to use a collection of pointers to pairs because otherwise when I access the pairs
with the GetAt(i) or GetNext(pos), I have to copy the whole pair. If it's a collection of pointers,
the GetAt or GetNext only copies a pointer. 
*/

//#define LIMITCOLLISIONSPERUPDATE
	/* If I define in LIMITCOLLISIONSPERUPDATE, I only allow one collision per
	update. This may be used if it seems as if multiple collisions are causing trouble. */

class cColliderPair : public CObject
{
DECLARE_DYNCREATE(cColliderPair); /* Don't intend to Serialize this, but might
	as well have DYNAMIC for possible runtime class type, and the stronger
	DYNCREATE for possible creation with a CreateObject call. With the
	DECLARE_??? and IMPLEMENT_??? macros, SERIAL includes DYNCREATE which 
	in turn includes DYNAMIC. */
public:
	cCritter *_pcrittercaller; //Make public so we don't bother with accessor.
	cCritter *_pcritterarg;
	cColliderPair(cCritter *pcrittercaller = NULL, cCritter *pcritterarg = NULL):
		_pcrittercaller(pcrittercaller), _pcritterarg(pcritterarg){} /* Note
		that with the defaults this acts as a no-arg constructor as well.  We
		let cCollider::smartAdd handle  the heavy lifting of figuring out which 
		order to build our pairs in, given two arbitrary critter pointers. */
	~cColliderPair(){} /* We DON'T want to delete the member pointers, as cColliderPair is 
		simply a little helper object. */
	BOOL involves(cCritter *pcrittertest)
		{return pcrittertest == _pcrittercaller || pcrittertest == _pcritterarg;}
	inline BOOL collideThePair(BOOL checkpriority = FALSE);
};

class cColliderLevel : public CTypedPtrList<CObList, cColliderPair*>
{
DECLARE_DYNCREATE(cColliderLevel);
public:
	cColliderLevel(){};
	void RemoveAll(); //Overload to delete the member pointers as well.
	void removeReferencesTo(cCritter *pdeadcritter);
	void iterateCollide(BOOL checkpriority);
};

class cCollider : public CObject
{
DECLARE_DYNCREATE(cCollider);
protected:
	cColliderLevel _wallpairs;
	cColliderLevel _nonwallpairs;
public:
	static const int DONTCOLLIDE;
	static const int COLLIDEEITHERWAY;
	static const int COLLIDEASCALLER;
	static const int COLLIDEASARG;
	/* The CP_??? are default cCritter _collisionpriority values, in increasing size for
		increasingly high priority, where in a pair of critters, the higher priority
		critter is the caller of the collide method, and the lower priority critter
		is the argument to the collide call. I make these Real so I can always squeeze
		value in between, and I make them non-const in case a game wants to change their
		values. At present the values are, in order, 100, 200, 300, 400, 500, and a million. */
	static Real CP_CRITTER;
	static Real CP_PLAYER;
	static Real CP_SILVERBULLET;
	static Real CP_BULLET;
	static Real CP_WALL;
	static Real CP_MAXIMUM;
	static Real CP_MINIMUM;
public:
	cCollider(){}
	void removeAll(); 
	virtual void smartAdd(cCritter *pcritter, cCritter *pcritterother); /* The smartAdd will only add a
		cCollisionPair if ther critters want to collide, and if it adds one, it'll put the 
		critter into the cCollisionPair in the correct caller/arg order. You might someday want
		to overload this. */
	void removeReferencesTo(cCritter *pdeadcritter);
	void build(cBiota *pbiota);
	void iterateCollide();
};



#endif //COLLIDER_H
