// Listener.cpp: implementation of various cListener classes.
//
//////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "listener.h"
#include "game.h" //Gives include biota.h, critter.h, sprite.h
#include "critterarmed.h"
#include "spritepolygon.h" //For Player critter
#include "pop.h" //for playSound
#include "critterviewer.h" //For the cCritterViewer class

IMPLEMENT_SERIAL(cListener, CObject, 0 );
IMPLEMENT_SERIAL(cListenerArrow, cListener, 0 );
IMPLEMENT_SERIAL(cListenerArrowAttitude, cListener, 0 );
IMPLEMENT_SERIAL(cListenerHopper, cListener, 0 );
IMPLEMENT_SERIAL(cListenerCar, cListener, 0 );
IMPLEMENT_SERIAL(cListenerSpaceship, cListener, 0 );
IMPLEMENT_SERIAL(cListenerScooter, cListener, 0 );
IMPLEMENT_SERIAL(cListenerScooterYHopper, cListener, 0 );
IMPLEMENT_SERIAL(cListenerCursor, cListener, 0 );
IMPLEMENT_SERIAL(cListenerViewerOrbit, cListener, 0)
IMPLEMENT_SERIAL(cListenerViewerRide, cListener, 0)
IMPLEMENT_SERIAL(cListenerViewerFly, cListener, 0)
IMPLEMENT_SERIAL(cListenerViewerOrtho, cListener, 0)
IMPLEMENT_SERIAL(cListenerViewerTranslate, cListener, 0)

//=================== cListener Statics ================
#define RIDESTEP 0.05
#define MOVEVIEW 1
		/* MOVEVIEW must be 1 or -1. 
		If MOVEVIEW is 1, then the cCritterViewerFly and
	cCritterViewerOrtho	will move the cCritterViewer in such a way that what you see 
	scrolls left when you press Ctrl+left arrow, scrolls right with Ctrl+right arrow,
	up with Ctrl+up arrow, down with Ctrl+down arrow.  The effect is that these keys
	are moving the world, as opposed to moving the viewer.  This seems better, as the
	typical user will not think in terms of the viewer as a separate object.  Also
	the Ctrl+Shift+left arrow will rotate the world to the left, and so on.  To do
	all this, the cCritterViewer actually is moving or rotating in the 
	opposite directions of the arrow, that is, a left arrow moves the critter right, which
	makes the view that the critter sees move to the left and so on.
		If MOVEVIEW is -1, all this is undone, and the arrows move the criter viewer
	in the natural way and the visual motions of the world are reversed. 
		I'm still not 100% sure that the MOVEVIEW 1 makes the best interface, which is
	why we have the MOVEVIEW #define for changing all at once. */
Real cListenerCursor::TOOSMALLAMOVE = 0.1;
Real cListener::CRITTERTURNSPEEDSLOW = 0.2*PI;
Real cListener::CRITTERTURNSPEEDFAST = 2.0*PI;
Real cListener::TURNSPEEDUPWAIT = 0.1;
Real cListenerCursor::CURSORSPEED = 100.0;
//================cListenerViewer Statics


/*In studying this code, be aware that the cCritterArmedPlayer overloads the cCritter::listen
	method to use the space and left click for shooting.  Look at the ::listen method in
	critterarmed.cpp.  */

#define ALLOWCARREVERSE
	/* ALLOWCARREVERSE allows you to use cListenerCar back up a car in reverse. If you
		comment out ALLOWCARREVERSE, then car can only slow down to a stop. 
		But if you are using worlds with gravity, the implementation of reverse
		is going to	give odd results eitherw ay.  If you comment in ALLOWCARREVERSE,
		a critter falling backwards thinks its in reverse and does the "wrong" thing
		when you turn it, that is, it seems to turn in an odd diretion.  But with
		gravity, commenting out ALLOWCARREVERSE gives worse results, as then 
		the critter can't fall backwards but can fall forwards.  Face it, you
		don't drive cars in free fall! Use Spaceship for gravity worlds. */

//=================cListener===================

void cListener::install(cCritter *pcritter)
{
	pcritter->restoreMaxspeed(); //In case you were just using cListenerCursor
	pcritter->copyAttitudeMatrixToMotionMatrix(); 
/* In case the two don't match, give your attitude
		precendence, just to get off to a proper start with the listener. */
}

Real cListener::turnspeed(Real keydowntime)
{
	if (keydowntime < cListener::TURNSPEEDUPWAIT)
		return cListener::CRITTERTURNSPEEDSLOW;
	else
		return cListener::CRITTERTURNSPEEDFAST;
}	

//=================cListenerArrow Code===================================================
void cListenerArrow::listen(Real dt, cCritter *pcritter)
{
	cController *pcontroller = pcritter->pgame()->pcontroller();
	/* Note that since I set the velocity to 0.0 when I'm not
		pressing an arrow key, this means that acceraltion forces don't get
		to have accumulating effects on a critter with a cListenerScooter listener. So rather
		than having some very half-way kinds of acceleration effects, I go aheand and
		set acceleration to 0.0 in here. */
	pcritter->setAcceleration(cVector::ZEROVECTOR);	
	if (!pcontroller->keyonplain(VK_LEFT) && !pcontroller->keyonplain(VK_RIGHT) &&
			!pcontroller->keyonplain(VK_DOWN) && !pcontroller->keyonplain(VK_UP) &&
			!pcontroller->keyonplain(VK_PAGEDOWN) && !pcontroller->keyonplain(VK_PAGEUP)
		)
	{
		pcritter->setVelocity(cVector::ZEROVECTOR);
		return;
	}
		/* If you get here, you've pressed an arrow key.  First match the velocity to 
			the arrow key direction, and then match the attitude. */
	if (pcontroller->keyonplain(VK_LEFT))
		pcritter->setVelocity(- pcritter->maxspeed() * cVector::XAXIS);
	if (pcontroller->keyonplain(VK_RIGHT))
		pcritter->setVelocity(pcritter->maxspeed() * cVector::XAXIS);
	if (pcontroller->keyonplain(VK_DOWN))
		pcritter->setVelocity(-pcritter->maxspeed() * cVector::YAXIS);
	if (pcontroller->keyonplain(VK_UP))
		pcritter->setVelocity(pcritter->maxspeed() * cVector::YAXIS);
	if (pcontroller->keyonplain(VK_PAGEDOWN) && pcritter->in3DWorld())
		pcritter->setVelocity(-pcritter->maxspeed() * cVector::ZAXIS);
	if (pcontroller->keyonplain(VK_PAGEUP)&& pcritter->in3DWorld())
		pcritter->setVelocity(pcritter->maxspeed() * cVector::ZAXIS);
	//Now match the attitude.
	if (pcritter->attitudetomotionlock())
		  /* Need this condition if you want
		to have a "spaceinvaders" type shooter that always points up as in 
		the textbook problem 3.11 */
		pcritter->copyMotionMatrixToAttitudeMatrix();
	//Note that if pcritter is cCritterArmed*, then the cCritterArmed::listen does more stuff.
}

//=================cListenerArrowAttitude Code===================================================

void cListenerArrowAttitude::listen(Real dt, cCritter *pcritter) /* used in Defender3d */
{
	cController *pcontroller = pcritter->pgame()->pcontroller();
	/* Note that since I set the velocity to 0.0 when I'm not
		pressing an arrow key, this means that acceraltion forces don't get
		to have accumulating effects on a critter with a cListenerScooter listener. So rather
		than having some very half-way kinds of acceleration effects, I go aheand and
		set acceleration to 0.0 in here. */
	pcritter->setAcceleration(cVector::ZEROVECTOR);	
	if (!pcontroller->keyonplain(VK_LEFT) && !pcontroller->keyonplain(VK_RIGHT) &&
			!pcontroller->keyonplain(VK_DOWN) && !pcontroller->keyonplain(VK_UP) &&
			!pcontroller->keyonplain(VK_PAGEDOWN) && !pcontroller->keyonplain(VK_PAGEUP)
		)
	{
		pcritter->setVelocity(cVector::ZEROVECTOR);
		return;
	}
		/* If you get here, you've pressed an arrow key.  First match the velocity to 
			the arrow key direction, and then match the attitude. */
	if (pcontroller->keyonplain(VK_LEFT))
		pcritter->setVelocity(pcritter->maxspeed() * pcritter->attitudeNormal());
	if (pcontroller->keyonplain(VK_RIGHT))
		pcritter->setVelocity(-pcritter->maxspeed() * pcritter->attitudeNormal());
	if (pcontroller->keyonplain(VK_PAGEDOWN))
		pcritter->setVelocity(-pcritter->maxspeed() * pcritter->attitudeTangent());
	if (pcontroller->keyonplain(VK_PAGEUP))
		pcritter->setVelocity(pcritter->maxspeed() * pcritter->attitudeTangent());
	if (pcontroller->keyonplain(VK_DOWN) && pcritter->in3DWorld())
		pcritter->setVelocity(-pcritter->maxspeed() * pcritter->attitudeBinormal());
	if (pcontroller->keyonplain(VK_UP)&& pcritter->in3DWorld())
		pcritter->setVelocity(pcritter->maxspeed() * pcritter->attitudeBinormal());
	//DON'T match the attitude to the motion.
	//Note that if pcritter is cCritterArmed*, then the cCritterArmed::listen does more stuff.
}

//=================cListenerHopper Code===================================================
void cListenerHopper::listen(Real dt, cCritter *pcritter)
{
	cController *pcontroller = pcritter->pgame()->pcontroller();
	/* We design this primarily for use in 2D where you use left/right to move
		along the x axis and use the up key (or you coudl have instead used
		the spacebar if you don't need it for shooting) to hop in the air.
		Simply as a default extension to 3D, we'll assume that in 3D the z direction
		would be on the ground and the y could continue to be the hopping direction.
		We set the x (and the z velocity) to 0.0 when I'm not
		pressing an arrow key, this means that acceleration forces don't get
		to have accumulating effects on a critter with a cListenerScooter listener. 
		So rather than having some very half-way kinds of acceleration effects, I go 
		ahead and set x and z acceleration to 0.0 in here. But I leave y alone. */
	pcritter->setAcceleration(cVector(0.0, pcritter->acceleration().y(), 0.0));	
	cVector curvel = pcritter->velocity(); //Just to save typing
	if (!pcontroller->keyonplain(VK_LEFT) && !pcontroller->keyonplain(VK_RIGHT) &&
			!pcontroller->keyonplain(VK_DOWN) && !pcontroller->keyonplain(VK_UP) &&
			!pcontroller->keyonplain(VK_PAGEDOWN) && !pcontroller->keyonplain(VK_PAGEUP)
		)
		pcritter->setVelocity(cVector(0.0, curvel.y(), 0.0)); //don't keep left right momentum.
	if (pcontroller->keyonplain(VK_LEFT))
		pcritter->setVelocity(cVector(-walkspeed(), curvel.y(), curvel.z()));
	if (pcontroller->keyonplain(VK_RIGHT))
		pcritter->setVelocity(cVector(walkspeed(), curvel.y(), curvel.z()));
	 /* In a 2D world we'll assume critter hops in Y direction
			with VK_UP. In a 3D world, we'll assume critter hops in Y direction with
			VK_PAGEUP, and uses regular UP/DOWN to move "forward" in the negative
			Z direction, walking into the sceen from hiz to loz. */
	BOOL hopkeypressed;
	if (!pcritter->in3DWorld())
	{
		hopkeypressed = pcontroller->keyonplain(VK_UP);
	}
	else //3DWorld case
	{
		hopkeypressed = pcontroller->keyonplain(VK_PAGEUP);
		if (pcontroller->keyonplain(VK_DOWN) && pcritter->in3DWorld())
			/* In the 3D World, let's by default assume hopper is "walking" form hiz to loz */
			pcritter->setVelocity(cVector(curvel.x(), curvel.y(), walkspeed()));
		if (pcontroller->keyonplain(VK_UP)&& pcritter->in3DWorld())
			pcritter->setVelocity(cVector(curvel.x(), curvel.y(), -walkspeed()));
	}
	if (hopkeypressed && pcritter->age() > _lasthopage + _hopagainwait &&
		pcontroller->keystateage(VK_UP) < _hopuptime ) //Haven't used up this hop yet
	{
			 //Pulse upwards
			pcritter->addAcceleration(pcritter->listeneracceleration() * cVector::YAXIS);
			_hopping = TRUE;
	}
	else //not hopping
	{
		if (_lasthopage > pcritter->age()) /*  The critter's age was reset and you
			have a left-over big value in _lasthopage that's too large. */
			_lasthopage = pcritter->age();
		if (_hopping) //Just stopped hopping and not pressing any other key
			_lasthopage = pcritter->age();
		_hopping = FALSE;
	}
	// if (pcontroller->keyonplain(VK_DOWN)) ignore the down arrow.
	//Now match the attitude if you like.
	if (pcritter->attitudetomotionlock())
		pcritter->copyMotionMatrixToAttitudeMatrix();
	//Note that if pcritter is cCritterArmed*, then the cCritterArmed::listen does more stuff.
}

void cListenerHopper::Serialize(CArchive &ar)
{
	cListener::Serialize(ar);
	if (ar.IsStoring()) //Writing data.
	{
		ar <<  _hopuptime << _lasthopage << _hopagainwait << _walkspeed << _hopping;
	}
	else //reading data
	{
		ar >> _hopuptime >> _lasthopage >> _hopagainwait >> _walkspeed >> _hopping;
	}
}





//====================cListenerViewerFly============

void cListenerScooter::listen(Real dt, cCritter *pcritter)
{
	cController *pcontroller = pcritter->pgame()->pcontroller();
	/* Note that since I set the velocity to 0.0 when I'm not
		pressing an arrow key, this means that acceraltion forces don't get
		to have accumulating effects on a critter with a cListenerScooter listener. So rather
		than having some very half-way kinds of acceleration effects, I go aheand and
		set acceleration to 0.0 in here. */
	pcritter->setAcceleration(cVector::ZEROVECTOR);	
//Translate
	/* I want to move the critter position. But I don't
		just use a moveTo because I want to have a correct _velocity inside the 
		critter so I can use it to hit things and bounce and so on.  So I change
		the velocity.*/
	BOOL inreverse = FALSE; //Only set TRUE if currently pressing VK_DOWN
	if (pcontroller->keyonplain(VK_UP))
		pcritter->setVelocity(pcritter->maxspeed()*pcritter->attitudeTangent());
	if (pcontroller->keyonplain(VK_DOWN))
	{
		pcritter->setVelocity(-pcritter->maxspeed()*pcritter->attitudeTangent());
		inreverse = TRUE;
	}
	if (!pcontroller->keyonplain(VK_UP) && !pcontroller->keyonplain(VK_DOWN))
		pcritter->setVelocity(cVector::ZEROVECTOR);
//	Real inreversesign = inreverse?-1.0:1.0;
//Turn
	if (!pcontroller->keyonplain(VK_LEFT) && !pcontroller->keyonplain(VK_RIGHT) &&
			!pcontroller->keyonplain(VK_HOME) && !pcontroller->keyonplain(VK_END) &&
			!pcontroller->keyonplain(VK_PAGEDOWN) && !pcontroller->keyonplain(VK_PAGEUP)
		)
		return;
		/* If you get here, you've pressed an arrow key.  Do three things.
			(a) Match the motion vectors to the visible attitude.
			(b) Rotate the motion vectors withe the arrow keys.
			(c) Match the attitude to the altered motion vectors. */
		//(a) Match the motion matrix to the attitude.
	pcritter->copyAttitudeMatrixToMotionMatrix(); //Changes _velocity
	if (inreverse) //Keep the tangent and atttitudeTangent in opposite directions.
		pcritter->yaw(PI); //This puts _velocity back in the correct direction.
		//(b) Alter the motion matrix.
	if (pcontroller->keyonplain(VK_LEFT))
		pcritter->yaw(dt*turnspeed(pcontroller->keystateage(VK_LEFT)));
	if (pcontroller->keyonplain(VK_RIGHT))
		pcritter->yaw(-dt*turnspeed(pcontroller->keystateage(VK_RIGHT)));
	if (pcritter->in3DWorld()) /* Don't allow use of the pitch and roll in 2D
		worlds or you might get your critter bucked up out of his "reality". */
	{
		if (pcontroller->keyonplain(VK_PAGEDOWN))
			pcritter->pitch(dt*turnspeed(pcontroller->keystateage(VK_PAGEDOWN)));
		if (pcontroller->keyonplain(VK_PAGEUP))
			pcritter->pitch(-dt*turnspeed(pcontroller->keystateage(VK_PAGEUP)));
		if (pcontroller->keyonplain(VK_HOME))
			pcritter->roll(-dt*turnspeed(pcontroller->keystateage(VK_HOME)));
		if (pcontroller->keyonplain(VK_END))
			pcritter->roll(dt*turnspeed(pcontroller->keystateage(VK_END)));
	}
	//(c) Match the attitude to the motion matrix.
	pcritter->copyMotionMatrixToAttitudeMatrix();
	if (inreverse) //Keep the tangent and atttitudeTangent in opposite directions.
		pcritter->rotateAttitude(-PI);
}
//ScooterYHopper=======================
void cListenerScooterYHopper::listen(Real dt, cCritter *pcritter)
{
	cController *pcontroller = pcritter->pgame()->pcontroller();
	/* Note that since I set the velocity to 0.0 when I'm not
		pressing an arrow key, this means that acceraltion forces don't get
		to have accumulating effects on a critter with a cListenerScooter listener. So rather
		than having some very half-way kinds of acceleration effects, I go aheand and
		set acceleration to 0.0 in here. */
//	pcritter->setAcceleration(cVector(0.0, pcritter->acceleration().y(), 0.0));	
	Real yvelocity = pcritter->velocity().y(); /* Save this and restore it before we leave
		this call, so that gravity can act in the y direction. */
//Translate
	/* I want to move the critter position. But I don't
		just use a moveTo because I want to have a correct _velocity inside the 
		critter so I can use it to hit things and bounce and so on.  So I change
		the velocity.*/
	BOOL inreverse = FALSE; //Only set TRUE if currently pressing VK_DOWN
	if (pcontroller->keyonplain(VK_UP))
		pcritter->setVelocity(pcritter->maxspeed()*pcritter->attitudeTangent());
	if (pcontroller->keyonplain(VK_DOWN))
	{
		pcritter->setVelocity(-pcritter->maxspeed()*pcritter->attitudeTangent());
		inreverse = TRUE;
	}
	if (!pcontroller->keyonplain(VK_UP) && !pcontroller->keyonplain(VK_DOWN))
		pcritter->setVelocity(cVector::ZEROVECTOR);

	//Now restore the y velocity.
	pcritter->setVelocity(
		cVector(pcritter->velocity().x(), yvelocity, pcritter->velocity().z()));
//	Real inreversesign = inreverse?-1.0:1.0;

	if (!pcontroller->keyonplain(VK_LEFT) && !pcontroller->keyonplain(VK_RIGHT) &&
			!pcontroller->keyonplain(VK_PAGEDOWN) && !pcontroller->keyonplain(VK_PAGEUP) )
		return;
		/* If you get here, you've pressed an arrow key or a hop key. */ 
	if (pcontroller->keyonplain(VK_LEFT) || pcontroller->keyonplain(VK_RIGHT))
	{
		/* To rotate, Do three things.
			(a) Match the motion vectors to the visible attitude.
			(b) Rotate the motion vectors withe the arrow keys.
			(c) Match the attitude to the altered motion vectors. */
		//(a) Match the motion matrix to the attitude.
		pcritter->copyAttitudeMatrixToMotionMatrix(); //Changes _velocity
		if (inreverse) //Keep the tangent and atttitudeTangent in opposite directions.
			pcritter->yaw(PI); //This puts _velocity back in the correct direction.
			//(b) Alter the motion matrix.
		if (pcontroller->keyonplain(VK_LEFT))
			pcritter->yaw(dt*turnspeed(pcontroller->keystateage(VK_LEFT)));
		if (pcontroller->keyonplain(VK_RIGHT))
			pcritter->yaw(-dt*turnspeed(pcontroller->keystateage(VK_RIGHT)));
		//(c) Match the attitude to the motion matrix.
		pcritter->copyMotionMatrixToAttitudeMatrix();
		if (inreverse) //Keep the tangent and atttitudeTangent in opposite directions.
			pcritter->rotateAttitude(-PI);
		pcritter->setVelocity( //Restore y velocity in case you changed it again.
			cVector(pcritter->velocity().x(), yvelocity, pcritter->velocity().z()));
	}
//Hopping code
	if (pcritter->in3DWorld()) 
	{
		BOOL hopkeypressed = pcontroller->keyonplain(VK_PAGEUP);
		if (hopkeypressed && pcritter->age() > _lasthopage + _hopagainwait &&
			pcontroller->keystateage(VK_PAGEUP) < _hopuptime ) //Haven't used up this hop yet
		{
			 //Pulse upwards
			pcritter->addAcceleration(pcritter->listeneracceleration() * cVector::YAXIS);
			_hopping = TRUE;
		}
		else //not hopping
		{
			if (_lasthopage > pcritter->age()) /*  The critter's age was reset and you
				have a left-over big value in _lasthopage that's too large. */
				_lasthopage = pcritter->age();
			if (_hopping) //Just stopped hopping and not pressing any other key
				_lasthopage = pcritter->age();
			_hopping = FALSE;
		}
	}
}

void cListenerScooterYHopper::Serialize(CArchive &ar)
{
	cListener::Serialize(ar);
	if (ar.IsStoring()) //Writing data.
	{
		ar <<  _hopuptime << _lasthopage << _hopagainwait  << _hopping;
	}
	else //reading data
	{
		ar >> _hopuptime >> _lasthopage >> _hopagainwait >> _hopping;
	}
}


//=================cListenerCar Code========================

void cListenerCar::listen(Real dt, cCritter *pcritter)
{
//Translate
	cController *pcontroller = pcritter->pgame()->pcontroller();
	if (pcontroller->keyonplain(VK_UP))
		pcritter->addAcceleration(
			pcritter->listeneracceleration() * pcritter->attitudeTangent());
	if (pcontroller->keyonplain(VK_DOWN))		
		pcritter->addAcceleration(
			-pcritter->listeneracceleration() * pcritter->attitudeTangent());
	BOOL inreverse = pcritter->tangent() % pcritter->attitudeTangent() < 0.0;

#ifndef ALLOWCARREVERSE
	if (inreverse) 
		pcritter->setSpeed(0.0); //Just stop, don't back up.
#endif //ALLOWCARREVERSE

	if (!pcontroller->keyonplain(VK_LEFT) && !pcontroller->keyonplain(VK_RIGHT) &&
			!pcontroller->keyonplain(VK_HOME) && !pcontroller->keyonplain(VK_END) &&
			!pcontroller->keyonplain(VK_PAGEDOWN) && !pcontroller->keyonplain(VK_PAGEUP)
		)
		return;
		/* If you get here, you've pressed an arrow key.  Do three things.
			(a) Match the motion vectors to the visible attitude.
			(b) Rotate the motion vectors with the arrow keys.
			(c) Match the attitude to the altered motion vectors. */
		//(a) Match the motion matrix to the attitude.
	pcritter->copyAttitudeMatrixToMotionMatrix();
#ifdef ALLOWCARREVERSE
	if (inreverse) //Keep the tangent and atttitudeTangent in opposite directions.
		pcritter->yaw(PI);
#endif //ALLOWCARREVERSE
		//(b) Alter the motion matrix.
//2D Turn
	if (pcontroller->keyonplain(VK_LEFT))
		pcritter->yaw(dt*turnspeed(pcontroller->keystateage(VK_LEFT)));
	if (pcontroller->keyonplain(VK_RIGHT))
		pcritter->yaw(dt*-turnspeed(pcontroller->keystateage(VK_RIGHT)));
		//Note that Left and Right Cancel out if both are down.
//3D Turn
	if (pcritter->in3DWorld())/* Don't allow use of the pitch and roll in 2D
		worlds or you might get your critter bucked up out of his "reality". */
	{
		if (pcontroller->keyonplain(VK_PAGEDOWN))
			pcritter->pitch(dt*turnspeed(pcontroller->keystateage(VK_PAGEDOWN)));
		if (pcontroller->keyonplain(VK_PAGEUP))
			pcritter->pitch(-dt*turnspeed(pcontroller->keystateage(VK_PAGEUP)));
		if (pcontroller->keyonplain(VK_HOME))
			pcritter->roll(-dt*turnspeed(pcontroller->keystateage(VK_HOME)));
		if (pcontroller->keyonplain(VK_END))
			pcritter->roll(dt*turnspeed(pcontroller->keystateage(VK_END)));
	}
	//(c) match the attitude to the motion matrix.
	pcritter->copyMotionMatrixToAttitudeMatrix();
#ifdef ALLOWCARREVERSE
	if (inreverse)  //Keep the tangent and atttitudeTangent in opposite directions.
		pcritter->rotateAttitude(PI);
#endif //ALLOWCARREVERSE
//Note that if pcritter is cCritterArmed*, then the cCritterArmed::listen does more stuff.
}

//=================cListenerSpaceship Code========================

//This works fine in 2D, but I can't get it right for 3D, so at present
//it's disabled for 3D worlds on the menu.
void cListenerSpaceship::listen(Real dt, cCritter *pcritter)
{
	cController *pcontroller = pcritter->pgame()->pcontroller();
		//Note that for the cListenerSpaceship, the pcritter->_direction is NOT locked to the _attitude
//Blast rocket
	cVector blastacceleration;
	if (pcontroller->keyonplain(VK_UP))
		blastacceleration = pcritter->listeneracceleration() * 
			pcritter->attitudeTangent();
	if (pcontroller->keyonplain(VK_DOWN))		
		blastacceleration = -pcritter->listeneracceleration() *
			pcritter->attitudeTangent();
	if (pcontroller->keyonplain(VK_UP) == pcontroller->keyonplain(VK_DOWN)) //both on or both off
		blastacceleration = cVector::ZEROVECTOR;
	pcritter->addAcceleration(blastacceleration);

//Rotate 2D
	if (pcontroller->keyonplain(VK_LEFT))
	{
		pcritter->rotateAttitude(cSpin(dt*turnspeed(pcontroller->keystateage(VK_LEFT)),
			pcritter->attitudeBinormal()));
/*	Real *aelements = pcritter->attitude().transpose().elements();
	aelements = pcritter->attitude().transpose().elements();
	TRACE("3D version of cCritter attitude() matrix in cCritter::draw call after left arrow.\n");
	TRACE("%f  %f  %f  %f\n", aelements[0], aelements[4], aelements[8], aelements[12]);
	TRACE("%f  %f  %f  %f\n", aelements[1], aelements[5], aelements[9], aelements[13]);
	TRACE("%f  %f  %f  %f\n", aelements[2], aelements[6], aelements[10], aelements[14]);
	TRACE("%f  %f  %f  %f\n", aelements[3], aelements[7], aelements[11], aelements[15]);
*/
	}
	if (pcontroller->keyonplain(VK_RIGHT))
		pcritter->rotateAttitude(cSpin(-dt*turnspeed(pcontroller->keystateage(VK_RIGHT)),
			pcritter->attitudeBinormal()));
//3D Turn 
	if (pcritter->in3DWorld())/* Don't allow use of the pitch and roll in 2D
		worlds or you might get your critter bucked up out of his "reality". */
	{
		if (pcontroller->keyonplain(VK_PAGEDOWN))
			pcritter->rotateAttitude(cSpin(dt*turnspeed(pcontroller->keystateage(VK_PAGEDOWN)),
				pcritter->attitudeNormal()));
		if (pcontroller->keyonplain(VK_PAGEUP))
			pcritter->rotateAttitude(cSpin(-dt*turnspeed(pcontroller->keystateage(VK_PAGEUP)),
				pcritter->attitudeNormal()));
		if (pcontroller->keyonplain(VK_HOME))
			pcritter->rotateAttitude(cSpin(dt*turnspeed(pcontroller->keystateage(VK_HOME)),
				pcritter->attitudeTangent()));
		if (pcontroller->keyonplain(VK_END))
			pcritter->rotateAttitude(cSpin(-dt*turnspeed(pcontroller->keystateage(VK_END)),
				pcritter->attitudeTangent()));
	}
//Note that if pcritter is cCritterArmed*, then the cCritterArmed::listen does more stuff.
}
//=================cListenerCursor Code========================

void cListenerCursor::install(cCritter *pcritter)
{
	cListener::install(pcritter);
	pcritter->setTempMaxspeed(cListenerCursor::CURSORSPEED); /* Give a critter with a cursor listener a very high max speed
		so that I can use large velocities of the form displacement/dt . */
}

void cListenerCursor::listen(Real dt, cCritter *pcritter)
{
	cController *pcontroller = pcritter->pgame()->pcontroller();
	/* Unlike the other listeners, the cListenerCursor is going to have
		 pcritter ignore
		any forces.  This is so it can strictly move with the cursor.
		 So we zero out
		the acceleration each time.  We also zero out the velocity so the thing 
		doesn't
		have inertia. */
	pcritter->setVelocity(cVector::ZEROVECTOR);
	pcritter->setAcceleration(cVector::ZEROVECTOR);
	if (_attached && dt > SMALL_REAL) //Check dt so don't divide by zero. (_attached always TRUE)
	{
		cVector cursorposclamp = pcritter->pgame()->cursorpos();
		cRealBox effectivebox = pcritter->moveBox().innerBox(pcritter->radius());
//		ASSERT (pcritter->in3DWorld() || effectivebox.zsize() == 0.0);
		effectivebox.clamp(cursorposclamp);
		cVector displacement = ( cursorposclamp - pcritter->position());
		if (displacement.magnitude() > cListenerCursor::TOOSMALLAMOVE) 
			//The if condition is because you get wobble if you adjust for too small a step.
		{
			/* I want to move the critter position to cursorposclamp.  But I don't
				just use a moveTo because I want to have a correct _velocity inside the 
				critter so I can use it to hit things and bounce and so on.  So I change
				the velocity.  Alternately I could change the acceleration, but for sudden
				moves, it is preferagle to make  an "impulse" change by using velocity and
				not acceleration. */
			pcritter->setVelocity((1.0/dt)*displacement);
			pcritter->copyMotionMatrixToAttitudeMatrix();
		}
	}
	//If no rotation keys have been pressed, you're done.
	//Note that if pcritter is cCritterArmed*, then the cCritterArmed::listen does more stuff.
	if (pcontroller->keyonplain(VK_LEFT))
		pcritter->yaw(dt*turnspeed(pcontroller->keystateage(VK_LEFT)));
	if (pcontroller->keyonplain(VK_RIGHT))
		pcritter->yaw(-dt*turnspeed(pcontroller->keystateage(VK_RIGHT)));
	if (pcritter->in3DWorld()) /* Don't allow use of the pitch and roll in 2D
		worlds or you might get your critter bucked up out of his "reality". */
	{
		if (pcontroller->keyonplain(VK_PAGEDOWN))
			pcritter->pitch(dt*turnspeed(pcontroller->keystateage(VK_PAGEDOWN)));
		if (pcontroller->keyonplain(VK_PAGEUP))
			pcritter->pitch(-dt*turnspeed(pcontroller->keystateage(VK_PAGEUP)));
		if (pcontroller->keyonplain(VK_HOME))
			pcritter->roll(-dt*turnspeed(pcontroller->keystateage(VK_HOME)));
		if (pcontroller->keyonplain(VK_END))
			pcritter->roll(dt*turnspeed(pcontroller->keystateage(VK_END)));
	}
	//(c) Match the attitude to the motion matrix.
	pcritter->copyMotionMatrixToAttitudeMatrix();
}

void cListenerCursor::Serialize(CArchive &ar)
{
	cListener::Serialize(ar);
	if (ar.IsStoring()) //Writing data.
	{
		ar <<  _attached;
	}
	else //reading data
	{
		ar >> _attached;
	}
}
//=================cListenerViewer Code===================================================
//====================cListenerViewerOrtho==== //Used for 2D worlds only.
/* Note that I used a different method for the moving and the
turning in the code for cListenerViewerOrtho than I used in cListenerViewerFly; so far
as I know the two methods are equivalent, but all in all, I prefer the cListenerViewerFly
code, which was written more recently. */

void cListenerViewerOrtho::install(cCritter *pcritter)
{	cListener::install(pcritter);
	cCritterViewer *pcritterv = (cCritterViewer*)(pcritter); 

	pcritter->setAttitudeToMotionLock(FALSE);
	pcritterv->setPerspective(FALSE); //2D
#ifndef THREEDVECTORS //Two dimensional case.
	cMatrix2 M; /* Use a default orientation for your attitude, as all you want to to is to match
		your x and y to the world and project up the z. */
	pcritter->setAttitude(M);
#endif //THREEDVECTORS
}

void cListenerViewerOrtho::listen(Real dt, cCritter *pcritter)
{
	cController *pcontroller = pcritter->pgame()->pcontroller();
	cCritterViewer *pcritterv = (cCritterViewer*)(pcritter);
		 //Need the cast to use ::zoom
	ASSERT(pcritterv);
//Use the Control + (Arrow keys, Insert or Delete) to translate.
	if (pcontroller->keyoncontrol(VK_LEFT))
		pcritter->setVelocity(MOVEVIEW*pcritter->maxspeed() * cVector::XAXIS);
	if (pcontroller->keyoncontrol(VK_RIGHT))
		pcritter->setVelocity(-MOVEVIEW*pcritter->maxspeed() * cVector::XAXIS);
	if (pcontroller->keyoncontrol(VK_DOWN))
		pcritter->setVelocity(MOVEVIEW*pcritter->maxspeed() * cVector::YAXIS);
	if (pcontroller->keyoncontrol(VK_UP))
		pcritter->setVelocity(-MOVEVIEW* pcritter->maxspeed() * cVector::YAXIS);
	if (!pcontroller->keyoncontrol(VK_LEFT) && !pcontroller->keyoncontrol(VK_RIGHT) &&
			!pcontroller->keyoncontrol(VK_DOWN) && !pcontroller->keyoncontrol(VK_UP) )
		pcritter->setVelocity(cVector::ZEROVECTOR);
/* Use the Insert, Delete keys to zoom. Control should be off; as it happens the Control key actually
blocks processing of the Insert key. */
	if (pcontroller->keyon(VK_INSERT))
		pcritterv->zoom(cCritterViewer::DEFAULTZOOMFACTOR);
	if (pcontroller->keyon(VK_DELETE))
		pcritterv->zoom(1.0/cCritterViewer::DEFAULTZOOMFACTOR);

	if (pcritter->velocity().z() != 0.0) //Pointless to move in z if its a nonperspective viewer?
		pcritter->setVelocity(cVector(pcritter->velocity().x(), pcritter->velocity().y(), 0.0));
}
//====================cListenerViewerFly============Used for 3D Worlds Only

void cListenerViewerFly::install(cCritter *pcritter)
{
	cListener::install(pcritter);
	cCritterViewer *pcritterv = (cCritterViewer*)(pcritter); 
	pcritterv->setPerspective(TRUE); //Assume we always use this with _perspective on.
	pcritter->setAttitudeToMotionLock(TRUE); 
		/* We will move the 
		critter around and match the attitude to the position. */
}

void cListenerViewerFly::listen(Real dt, cCritter *pcritter)
{
	cController *pcontroller = pcritter->pgame()->pcontroller();

//Translate
	if (pcontroller->keyoncontrol(VK_UP))
		pcritter->moveTo(pcritter->position() -MOVEVIEW*dt*pcritter->maxspeed()*pcritter->binormal());
	if (pcontroller->keyoncontrol(VK_DOWN))
		pcritter->moveTo(pcritter->position() +MOVEVIEW*dt*pcritter->maxspeed()*pcritter->binormal());
	if (pcontroller->keyoncontrol(VK_LEFT))
		pcritter->moveTo(pcritter->position() -MOVEVIEW* dt*pcritter->maxspeed()*pcritter->normal());
	if (pcontroller->keyoncontrol(VK_RIGHT))
		pcritter->moveTo(pcritter->position() +MOVEVIEW* dt*pcritter->maxspeed()*pcritter->normal());
	if (pcontroller->keyoncontrol(VK_PAGEUP))
		pcritter->moveTo(pcritter->position() + dt*pcritter->maxspeed()*pcritter->tangent());
	if (pcontroller->keyoncontrol(VK_PAGEDOWN))
		pcritter->moveTo(pcritter->position() - dt*pcritter->maxspeed()*pcritter->tangent());
//Turn
	if (pcontroller->keyoncontrolshift(VK_LEFT))
		pcritter->yaw(-MOVEVIEW*dt*PI/3.0);
	if (pcontroller->keyoncontrolshift(VK_RIGHT))
		pcritter->yaw(MOVEVIEW*dt*PI/3.0);
	if (pcontroller->keyoncontrolshift(VK_UP))
		pcritter->pitch(MOVEVIEW*dt*PI/3.0);
	if (pcontroller->keyoncontrolshift(VK_DOWN))
		pcritter->pitch(-MOVEVIEW*dt*PI/3.0);
	if (pcontroller->keyoncontrolshift(VK_HOME))
		pcritter->roll(MOVEVIEW*dt*PI/3.0);
	if (pcontroller->keyoncontrolshift(VK_END))
		pcritter->roll(-MOVEVIEW*dt*PI/3.0);
/* Use the Insert, Delete keys to zoom. Control should be off; as it happens the Control key actually
blocks processing of the Insert key. */
	cCritterViewer *pcritterv = (cCritterViewer*)(pcritter);
		 //Need the cast to use ::zoom
	ASSERT(pcritterv);
	if (pcontroller->keyon(VK_INSERT))
		pcritterv->zoom(cCritterViewer::DEFAULTZOOMFACTOR);
	if (pcontroller->keyon(VK_DELETE))
		pcritterv->zoom(1.0/cCritterViewer::DEFAULTZOOMFACTOR);
}

//====================cListenerViewerRide============Used for 3D Worlds only.
cVector cListenerViewerRide::OFFSETDIR = cVector(-1.1, 0.0, 2.0);
Real cListenerViewerRide::PLAYERLOOKAHEAD = 7.;

void cListenerViewerRide::install(cCritter *pcritter)
{
	cListener::install(pcritter);
	cCritterViewer *pcritterv = (cCritterViewer*)(pcritter); 
	ASSERT(pcritterv);
	pcritterv->setPerspective(TRUE); //Assume we always use this with _perspective on.
	pcritterv->resetZoom();
	pcritterv->zoom(1.3); //Slightly more wideangle.
	pcritter->setAttitudeToMotionLock(FALSE);
	_offset = pcritter->pplayer()->radius() * cListenerViewerRide::OFFSETDIR;
}

void cListenerViewerRide::listen(Real dt, cCritter *pcritter)
{
	cController *pcontroller = pcritter->pgame()->pcontroller();
	cCritterViewer *pcritterv = (cCritterViewer*)(pcritter);
		 //Need the cast to use cCritterViewer::zoom.
	ASSERT(pcritterv);
//Read the keys and maybe adjust the _offset
	if (pcontroller->keyoncontrol(VK_UP))
		_offset +=  RIDESTEP * cVector::ZAXIS; 
	else if (pcontroller->keyoncontrol(VK_DOWN))
		_offset +=  -RIDESTEP * cVector::ZAXIS; 
	/* The idea here is to not let the offset get unreasonably high or low. */
	if (_offset.z() < -15.0 * pcritter->radius())
		_offset.setZ(-15.0 * pcritter->radius());
	if (_offset.z() > 15.0 * pcritter->radius())
		_offset.setZ(15.0 * pcritter->radius());
/* Use the Insert, Delete keys to zoom. Control should be off; as it happens the Control key actually
blocks processing of the Insert key. */
	if (pcontroller->keyon(VK_INSERT))
		pcritterv->zoom(cCritterViewer::DEFAULTZOOMFACTOR);
	if (pcontroller->keyon(VK_DELETE))
		pcritterv->zoom(1.0/cCritterViewer::DEFAULTZOOMFACTOR);
/* We make it the responsibility of the pcritter to match position to player()+_offset in the
cCritterViewer::update method.  Why don't we do this here in cListenerViewerRide::listen?  The
reason is that if I have two views of a game with a cListenerViewerRide viewpoint in each
view, I want them to both be updating, even though I don't want to have both of them
them listening. */
}

void cListenerViewerRide::Serialize(CArchive &ar)
{
	cListener::Serialize(ar);
	if (ar.IsStoring()) //Writing data.
	{
		ar <<  _offset;
	}
	else //reading data
	{
		ar >> _offset;
	}
}

//====================cListenerViewerTranslate==== //Not currently used
/* cListenerViewerTranslate might be useful in a 3D world where you have buildings, walls, etc. to 
give a very clear sense of what the standard x,y,z axes are.  In worlds in which
there's not much furniture and you are interacting with other critters, the
cListenerViewerFly is better. Note that I used a different method for the moving and the
turning in the code for cListenerViewerTranslate than I used in cListenerViewerFly; so far
as I know the two methods are equivalent, but all in all, I prefer the cListenerViewerFly
code, which was written more recently. */

void cListenerViewerTranslate::install(cCritter *pcritter)
{	cListener::install(pcritter);
	cCritterViewer *pcritterv = (cCritterViewer*)(pcritter); 

	pcritter->copyAttitudeMatrixToMotionMatrix();
	pcritter->setAttitudeToMotionLock(FALSE);
	pcritterv->setPerspective(TRUE);
#ifndef THREEDVECTORS //Two dimensional case.
	cMatrix2 M; /* Use a default orientation for your attitude, as all you want to to is to match
		your x and y to the world and project up the z. */
	pcritter->setAttitude(M);
#endif //THREEDVECTORS
}

void cListenerViewerTranslate::listen(Real dt, cCritter *pcritter)
{
	cController *pcontroller = pcritter->pgame()->pcontroller();
	cCritterViewer *pcritterv = (cCritterViewer*)(pcritter);
		 //Need the cast to use ::zoom
	ASSERT(pcritterv);
//Use the Control + (Arrow keys, Insert or Delete) to translate.
	if (pcontroller->keyoncontrol(VK_LEFT))
		pcritter->setVelocity(pcritter->maxspeed() * cVector::XAXIS);
	if (pcontroller->keyoncontrol(VK_RIGHT))
		pcritter->setVelocity(- pcritter->maxspeed() * cVector::XAXIS);
	if (pcontroller->keyoncontrol(VK_DOWN))
		pcritter->setVelocity(pcritter->maxspeed() * cVector::YAXIS);
	if (pcontroller->keyoncontrol(VK_UP))
		pcritter->setVelocity(- pcritter->maxspeed() * cVector::YAXIS);
	if (pcontroller->keyoncontrol(VK_PAGEUP))
		pcritter->setVelocity(pcritter->maxspeed() * cVector::ZAXIS);
	if (pcontroller->keyoncontrol(VK_PAGEDOWN))
		pcritter->setVelocity(- pcritter->maxspeed() * cVector::ZAXIS);
	if (!pcontroller->keyoncontrol(VK_LEFT) && !pcontroller->keyoncontrol(VK_RIGHT) &&
			!pcontroller->keyoncontrol(VK_DOWN) && !pcontroller->keyoncontrol(VK_UP) &&
			!pcontroller->keyoncontrol(VK_PAGEDOWN) && !pcontroller->keyoncontrol(VK_PAGEUP))
		pcritter->setVelocity(cVector::ZEROVECTOR);
/* Use the Insert, Delete keys to zoom. Control should be off; as it happens the Control key actually
blocks processing of the Insert key. */
	if (pcontroller->keyon(VK_INSERT))
		pcritterv->zoom(cCritterViewer::DEFAULTZOOMFACTOR);
	if (pcontroller->keyon(VK_DELETE))
		pcritterv->zoom(1.0/cCritterViewer::DEFAULTZOOMFACTOR);

//Use Control + Shift +  (Arrow keys, Insert or Delete) to turn.
	if (pcontroller->keyoncontrolshift(VK_LEFT))
		pcritter->setSpin((PI/3.0), cVector::ZAXIS);
	else if (pcontroller->keyoncontrolshift(VK_RIGHT))
		pcritter->setSpin(-(PI/3.0), cVector::ZAXIS);
	else if (pcontroller->keyoncontrolshift(VK_DOWN))
		pcritter->setSpin(-(PI/3.0), cVector::YAXIS); //odd
	else if (pcontroller->keyoncontrolshift(VK_UP))
		pcritter->setSpin((PI/3.0), cVector::YAXIS); //odd
	else if (pcontroller->keyoncontrolshift(VK_PAGEUP))
		pcritter->setSpin(-(PI/3.0), cVector::XAXIS); //fine
	else if (pcontroller->keyoncontrolshift(VK_PAGEDOWN))
		pcritter->setSpin((PI/3.0), cVector::XAXIS); //fine
	else
		pcritter->setSpin(0.0, cVector::ZAXIS);
	if (pcritter->velocity().z() != 0.0) //Pointless to move in z if its a nonperspective viewer?
		pcritter->setVelocity(cVector(pcritter->velocity().x(), pcritter->velocity().y(), 0.0));
}

//====================cListenerViewerOrbit============NOT USED

void cListenerViewerOrbit::install(cCritter *pcritter)
{
	cListener::install(pcritter);
	cCritterViewer *pcritterv = (cCritterViewer*)(pcritter); 
	pcritterv->setPerspective(TRUE); //Assume we always use this with _perspective on.
	pcritter->copyAttitudeMatrixToMotionMatrix();
	pcritter->setAttitudeToMotionLock(TRUE); 
		/* We keep the critter pointed at the origin, and lock the attitude. */
}

void cListenerViewerOrbit::listen(Real dt, cCritter *pcritter)
{
	cController *pcontroller = pcritter->pgame()->pcontroller();
	cVector newposition = pcritter->position(); //default
	if (pcontroller->keyoncontrol(VK_LEFT))
		newposition.rotate(dt*cSpin(-(PI/3.0), cVector::YAXIS));
	else if (pcontroller->keyoncontrol(VK_RIGHT))
		newposition.rotate(dt*cSpin((PI/3.0), cVector::YAXIS)); 
	else if (pcontroller->keyoncontrol(VK_DOWN))
		newposition.rotate(dt*cSpin(-(PI/3.0), cVector::XAXIS));
	else if (pcontroller->keyoncontrol(VK_UP))
		newposition.rotate(dt*cSpin((PI/3.0), cVector::XAXIS)); 
	else if (pcontroller->keyoncontrol(VK_PAGEUP))
		newposition.rotate(dt*cSpin(-(PI/3.0), cVector::ZAXIS));
	else if (pcontroller->keyoncontrol(VK_PAGEDOWN))
		newposition.rotate(dt*cSpin((PI/3.0), cVector::ZAXIS));
	if (newposition != pcritter->position())
	{
		pcritter->moveTo(newposition);
//Do something extra, try and always look at the origin.
//		cCritter *pplayer = pcritter->pgame()->pplayer();
//		pcritter->lookAt(pplayer->position());
		pcritter->lookAt(cVector::ZEROVECTOR);
//		pcritter->setTangent(-pcritter->position()); 
	/* Point at the origin.  Unfortunately, as currently implemented,
		this call has the unpleasant side effect of sometimes flipping your visual up and down, as when
		you move from, say, (0, 0.1, 10) to (0, -0.1, 10).  Using setAttitudeTangent(-position())
		has the same effect.  This is because both use the cMatrix::rotationFromUnitToUnit
		to turn the normal and binormal along with the tangent. */
	}
}

