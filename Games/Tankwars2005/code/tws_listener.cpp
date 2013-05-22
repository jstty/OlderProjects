// Listener.cpp: implementation of various cListener classes.
//
//////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "../pop/listener.h"
#include "../pop/game.h" //Gives include biota.h, critter.h, sprite.h
#include "../pop/critterarmed.h"
#include "../pop/spritepolygon.h" //For Player critter
#include "../pop/pop.h" //for playSound
#include "../pop/critterviewer.h" //For the cCritterViewer class

#include "tws_listener.h"

IMPLEMENT_SERIAL(cListenerLR, cListener, 0 ); // L/R


//================= cListenerLR =======================
void cListenerLR::listen(Real dt, cCritter *pcritter)
{
	cController *pcontroller = pcritter->pgame()->pcontroller();
//	pcritter->setAcceleration(cVector(0.0, pcritter->acceleration().y(), 0.0));	
	Real yvelocity = pcritter->velocity().y(); /* Save this and restore it before we leave
		this call, so that gravity can act in the y direction. */
//Translate
	/* I want to move the critter position. But I don't
		just use a moveTo because I want to have a correct _velocity inside the 
		critter so I can use it to hit things and bounce and so on.  So I change
		the velocity.*/
	BOOL inreverse = FALSE; //Only set TRUE if currently pressing VK_DOWN

	/*
	if (pcontroller->keyonplain(VK_UP))
		pcritter->setVelocity(pcritter->maxspeed()*pcritter->attitudeTangent());

	if (pcontroller->keyonplain(VK_DOWN))
	{
		pcritter->setVelocity(-pcritter->maxspeed()*pcritter->attitudeTangent());
		inreverse = TRUE;
	}

	if (pcontroller->keyonplain(VK_LEFT))
	{
		pcritter->setVelocity(-pcritter->maxspeed()*pcritter->attitudeTangent());
	}
	

	if (pcontroller->keyonplain(VK_RIGHT))
		pcritter->setVelocity(pcritter->maxspeed()*pcritter->attitudeTangent());
	if (!pcontroller->keyonplain(VK_UP) && !pcontroller->keyonplain(VK_DOWN))
		pcritter->setVelocity(cVector::ZEROVECTOR);
*/

	//Now restore the y velocity.
	pcritter->setVelocity(
		cVector(pcritter->velocity().x(), yvelocity, pcritter->velocity().z()));
//	Real inreversesign = inreverse?-1.0:1.0;

	if (!pcontroller->keyonplain(VK_LEFT) && !pcontroller->keyonplain(VK_RIGHT) &&
			!pcontroller->keyonplain(VK_PAGEDOWN) && !pcontroller->keyonplain(VK_PAGEUP) )
		return;
		/* If you get here, you've pressed an arrow key or a hop key. */ 

/*	if (pcontroller->keyonplain(VK_LEFT) || pcontroller->keyonplain(VK_RIGHT))
	{
		pcritter->setVelocity(-pcritter->maxspeed()*pcritter->attitudeTangent());
		inreverse = TRUE;
		/* To rotate, Do three things.
			(a) Match the motion vectors to the visible attitude.
			(b) Rotate the motion vectors withe the arrow keys.
			(c) Match the attitude to the altered motion vectors. */
		//(a) Match the motion matrix to the attitude.
		/*pcritter->copyAttitudeMatrixToMotionMatrix(); //Changes _velocity
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
			cVector(pcritter->velocity().x(), yvelocity, pcritter->velocity().z()));*/
//	}
//Hopping code
/*	if (pcritter->in3DWorld()) 
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
/*				_lasthopage = pcritter->age();
			if (_hopping) //Just stopped hopping and not pressing any other key
				_lasthopage = pcritter->age();
			_hopping = FALSE;
		}
	}*/
}

void cListenerLR::Serialize(CArchive &ar)
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




