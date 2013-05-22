//////////////////////////////////////////////////////////////////////////////
// Program Name:  terrain.cpp
// Programmer:    Joseph E. Sutton, John
// Description:	TankWars 2005
// Course:        cs335
// Start Date:    2/12/2005
// Last Updated:  
// Version:       1.00
//////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "terrain.h"
#include "tankwars2005.h"
extern cTankWars2005 *tws2005;
IMPLEMENT_SERIAL(cCritterDamWall, cCritterWall, 0);

//////////////////////////////////////////////
// Constructor
//////////////////////////////////////////////
cTerrain::cTerrain(cGame *pownergame, UINT color)
{
	float newh = 2.0;
	int randomn;
   cCritterDamWall *twall; // Added by: Joseph E. Sutton
/*	do //Old method that used whole lines (good for very slow systems
	{
		newh = (float)4.0*rand()/(RAND_MAX+1.0);
	}
	while(newh < -3.5);
	for(float i = -17.1; i < 17.5; i+=0.4)
	{
		randomn = (int)900*rand()/(RAND_MAX+1.0);

		if(randomn < 300)
			newh+=0.15;
		else if(randomn > 600)
			newh-=0.15;

		if(newh < -3.5)
			newh+=0.15;
		else if(newh > 1.0)
			newh-=0.15;

		//new cCritterDamWall( cVector(i, -4.0), cVector(i, -1-(newh)), 0.4, pownergame, color);
	}*/
	//New version that uses squares to draw the terrain.
	randomn = (int)900*rand()/(RAND_MAX+1.0);
	if(randomn < 450)
		newh = -3.0;
	else
		newh = -2.5;

	for(float i = -17.1; i < 17.5; i+=0.5)
	{
		randomn = (int)700*rand()/(RAND_MAX+1.0);
		if(randomn < 300) //The if is here to vary the height of the terrain
			newh+=0.4;
		else if(randomn > 600)
			newh-=0.4;
		if(newh > 0.0)
			newh-=0.4; //Done so we don't get tooooo many critters
		for(float j = -4.0; j < newh; j+=0.4)
		{
         // Modified by: Joseph E. Sutton
			twall = new cCritterDamWall( cVector(i, j), cVector(i, (j+0.4)), 0.5, pownergame, color);
         twall->setPrismDz(0.0); // remove side walls (shading)
		}
	}
}

cTerrain::~cTerrain()
{
	// can't use DeleteCritterType, because it's not defined in critter, only in clevel
	tws2005->GetBiota()->purgeCritters( RUNTIME_CLASS(cCritterDamWall) );
}


#include "../pop/spritepolygon.h"
#include "../pop/force.h"
#include "../pop/listener.h"

/**************Rest of file modded by John P. Harris *************************/
BOOL cCritterDamWall::collide(cCritter *pcritter)
{
	cVector oldlocalpos, newlocalpos;
	Real newdistance;
	int oldoutcode, newoutcode;
	BOOL crossedwall;

	oldlocalpos = globalToLocalPosition(pcritter->oldposition());
	oldoutcode = _pskeleton->outcode(oldlocalpos); 
	newlocalpos = globalToLocalPosition( pcritter->position());
	newdistance = _pskeleton->distanceToOutcode(newlocalpos,
		newoutcode); //Sets the newoutcode as well.
	crossedwall = crossed(oldoutcode, newoutcode);

//#define DEBUGWALLCOLLIDE
#ifdef DEBUGWALLCOLLIDE
Real test = newlocalpos.y() ;
//if (test < 2*_pskeleton->hiy() && test > 2*_pskeleton->loy())
TRACE("OLD global position = (%f  %f  %f), \nNEW global position = (%f  %f  %f)\n",
pcritter->oldposition().x(), pcritter->oldposition().y(), pcritter->oldposition().z(),
pcritter->position().x(), pcritter->position().y(), pcritter->position().z());
TRACE("OLD local position = (%f  %f  %f), outcode = %d\nNEW local position = (%f  %f  %f), outcode = %d\n crossedwall %d \n",
oldlocalpos.x(), oldlocalpos.y(), oldlocalpos.z(), oldoutcode,
newlocalpos.x(), newlocalpos.y(), newlocalpos.z(), newoutcode,
crossedwall );
#endif //DEBUGWALLCOLLIDE

	if (newdistance >= pcritter->radius() && !crossedwall) //No collision
		return FALSE; /*See if there's a collision at all. We
	say there's a collision if crossedwall or if the
	cCritterWall::distance is less than radius.  Remember that
	cCritterWall::distance measures the distance to the OUTSIDE 
	PERIMETER of the box, not the distance to the box's center. */
	
#ifdef DEBUGWALLCOLLIDE
TRACE("collided local position = (%f  %f  %f)\n",
newlocalpos.x(), newlocalpos.y(),newlocalpos.z());
#endif //DEBUGWALLCOLLIDE
	
	/* I collided, so I need to move back further into the last good
		zone I was in outside the wall.  I want to set newlocalpos so 
		the rim of its critter is touching the wall. The idea is to back
		up in the direction of oldlocalpos.  To allow the possibility
		of skidding along the wall, we plan to back up from the
		the face (or edge or corner) facing oldlocalpos.  This works
		only if oldlocalpos was a good one, not inside the box.  In 
		principle this should always be true, but some rare weird circumstance
		(like a triple collsion) might mess this up, so we check for the
		bad case before starting. */

	if (oldoutcode == BOX_INSIDE) //Note that this almost never happens.
	{
TRACE("BAD WALL COLLISION CASE: Inside the box old pos = (%f  %f  %f), outcode %d\n", oldlocalpos.x(),
oldlocalpos.y(),oldlocalpos.z(), oldoutcode);
		cVector insidepos = oldlocalpos;
		oldlocalpos -= _pskeleton->maxsize() * pcritter->tangent();
			//Do a brutally large backup to get out of the box for sure.
		oldoutcode = _pskeleton->outcode(oldlocalpos);
			//Recalculate outcode at this new position.
		oldlocalpos = _pskeleton->closestSurfacePoint(oldlocalpos, oldoutcode,
			insidepos, BOX_INSIDE, FALSE);
			//Go to the closest surface point from there.
		oldoutcode = _pskeleton->outcode(oldlocalpos);
			//Recalculate outcode one more time to be safe.
		crossedwall = crossed(oldoutcode, newoutcode);
			//Recalculate crossedwall
	}
		/* I find that with this code, the mouse can drag things through walls,
		so I do a kludge to block it by setting crossedwall to TRUE, this
		affects the action of cRealBox::closestSurfacePoint, as modified
		in build 34_4. */
	if (pcritter->plistener()->IsKindOf(RUNTIME_CLASS(cListenerCursor)))
		crossedwall = TRUE; //Don't trust the mouse listener.
	newlocalpos = _pskeleton->closestSurfacePoint(oldlocalpos, oldoutcode, 
		newlocalpos, newoutcode, crossedwall);
		/* This call to closestSurfacePoint will move the newlocal pos
		from the far new side (or inside, or overlapping) of the box back to 
		the surface, usually on the old near side, edge, or corner given by
		oldoutcode. This prevents going through the	wall.
			If oldoutcode is a corner position and you are in fact heading
		towards a face near the corner, we used to bounce off the corner
		even though visually you can see you should bounce off the
		face.  This had the effect of making a scooter player get hung up on
		a corner sometimes. As of build 34_3, I'm moving the 
		newlocalpos to the newoutocode side in the case where oldlocalpos
		is an edge or a corner, and where crossedwall isn't TRUE.  I
		have to force in a TRUE for the cCursorLIstener case.  The USEJIGGLE
		code below also helps keep non-player critters from getting stuck
		on corners. */
	//Now back away from the box.
	newoutcode = _pskeleton->outcode(newlocalpos);
	cVector avoidbox = _pskeleton->escapeVector(newlocalpos, newoutcode);
	newlocalpos += pcritter->radius() * avoidbox; 
	newoutcode = _pskeleton->outcode(newlocalpos);

#ifdef DEBUGWALLCOLLIDE	
TRACE("non-overlapping local position = (%f  %f  %f) for \n critter radius %f, wall thickness %f, step per update %f.\n",
newlocalpos.x(), newlocalpos.y(), newlocalpos.z(), pcritter->radius(), _pskeleton->ysize(), 
pcritter->position().distanceTo(pcritter->oldposition()));
cVector correctedposition = localToGlobalPosition(newlocalpos);
TRACE("corrected global position = (%f  %f  %f)\n\n",
correctedposition.x(), correctedposition.y(), correctedposition.z());
#endif //DEBUGWALLCOLLIDE

	pcritter->moveTo(localToGlobalPosition(newlocalpos), TRUE); 
		//TRUE means continuous motion, means adjust tangent etc.
	//Done with position, now change the velocity
	cVector localvelocity = globalToLocalDirection(
		pcritter->velocity());
	cVector oldlocalvelocity = localvelocity;
	_pskeleton->reflect(localvelocity, newoutcode); 
		/* I rewrote the reflect code on Feb 22, 2004 for VErsion 34_3, changing
		it so that when you reflect off an edge or corner, you only bounce
		the smallest of your three velocity components. Balls stll seem to
		get hung up on the corner once is awhile. */
		/* Now decide, depending on the pcritter's absorberflag and bounciness,
		how much you want to use the new localvelocity vs. the 
		oldlocalvelocity. We decompose the new localvelocity into the
		tangentvelocity parallel to the wall and the normalvelocity
		away from the wall. Some pencil and paper drawings convince
		me that the tangent is half the sum of the oldlocalvelocity
		and the reflected new localvelocity. */
	cVector tangentvelocity = 0.5*(localvelocity + oldlocalvelocity);
	cVector normalvelocity = localvelocity - tangentvelocity;
	Real bouncefactor = 1.0;
	if (pcritter->absorberflag())
		bouncefactor = 0.0;
	else
//		bouncefactor = pcritter->bounciness();
		bouncefactor = 0.0;
	localvelocity = tangentvelocity + bouncefactor * normalvelocity;
#ifdef USECORNERJIGGLE
		/* USECORNERJIGGLE livens up action at the edges and corners.  Maybe
			the rotation should depend on the kind of edge or corner.
			Right now let's just use critter's binormal. Don't to it 
			to the player or viewer as it's confusing.  */
	if ( !(cRealBox::isFaceOutcode(newoutcode)) &&  //edge or corner
		 !(pcritter->IsKindOf(RUNTIME_CLASS(cCritterViewer))) && //not viewer
		 !(pcritter->IsKindOf(RUNTIME_CLASS(cCritterArmedPlayer))) ) 
			//Not player.  Note that cPlayer inherits from cCritterArmedPlayer,
			//so don't use cCritterPlayer as the base class here.
	{
		localvelocity.rotate(cSpin(
			cRandomizer::pinstance()->randomReal(
				-cCritterWall::CORNERJIGGLETURN,
 				cCritterWall::CORNERJIGGLETURN), //A random turn
				pcritter->binormal())); //Around the critter's binormal
		localvelocity *=  cCritterWall::CORNERJIGGLEKICK;  //Goose it a little
	}
#endif //USECORNERJIGGLE
	pcritter->setVelocity(localToGlobalDirection(localvelocity));
	return TRUE;
}

cCritterDamWall::cCritterDamWall(const cVector &enda, const cVector &endb,
	 Real thickness, cGame *pownergame, UINT color):
cCritterWall(enda, endb, thickness, 1.0, pownergame)
{
	_collidepriority = 100,0;
	//pownergame->buildCollider();

	psprite()->setFillColor(color);
  	setHealth(1);
	setValue(4);
}

int cCritterDamWall::damage(int hitstrength)
{
	if ( _shieldflag || recentlyDamaged())
 		return 0; /* Bail out right here if you were just damaged or if you were just replicated
 			from a just-damaged guy. Otherwise a newly replicated critter hit by one of a fusillade
 			of bullets that split its parent will get to split as well. */
 	int deathreward = cCritter::damage(hitstrength); /* This is _value (typically nonzero) you get
 		for killing off the critter. */
 	playSound("Ding"); //Signal the hit.
 	return deathreward;
}

