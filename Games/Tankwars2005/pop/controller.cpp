// controller.cpp: implementation of various controller classes.
//
//////////////////////////////////////////////////////////////////////


#include "stdafx.h"
#include "controller.h"

//============================= cCritter ==========================
IMPLEMENT_SERIAL( cController, CObject, 0 );

//=================cController Statics===================
const int cController::KEYOFF = 0;
const int cController::KEYON = 1;
const int cController::KEYONLOCK = 2;
const UINT cController::SHIFTBIT = 4;
const UINT cController::CONTROLBIT = 8;
const UINT cController::GOTONCEBIT = 16;
const UINT cController::GOTTWICEBIT = 32;
const UINT cController::TYPEMATICBIT = 64;
const UINT cController::FAKELBUTTONKEY = VK_Z; /* We assign a key that will mimic the behavior of the
	left mouse button.  This is a bit of developer gold plating intended to make the program
	more ergonomic.  I hate holding down the left button and dragging; it really hurts my
	tendons and promotes RSI.  So we have the option of holding down this key instead of
	the left button.  You have to choose the key a little carefully.  You can't use
	Control for instance, as you use Control in your program to open popups, like Control+F
	to open the file menu.  The key should be easy to reach, or its not ergonomic, so the
	work is pointless.  This rules out the F2 key etc. because these are on top.  The key
	should be on the left side of the keyboard so a typical user can use this key with
	left hand and mouse with right hand.  This rules out the Insert key.  So I use the Z 
	key. */

cController::cController():
_dt(0.0)
{
	for(int vkindex=0; vkindex< VKKEYCOUNT; vkindex++)
	{
		_keystate[vkindex] = KEYOFF;
		_keystateage[vkindex] = 0.0;
	}
}

/* Basically we just set _keystate[nChar] = KEYON here.  Also  I want to set the _keystateage to 0.0 
	if this is the first keypress. */
void cController::onKeyDown(UINT nChar, UINT nFlags)
{
	if (_keystate[nChar] == KEYOFF)
	{
		_keystateage[nChar] = 0.0;
		_keystate[nChar] = KEYON | nFlags;
	}
	else
		_keystate[nChar] |= TYPEMATICBIT;
}

void cController::onLButtonDown(UINT nFlags)
{
	_keystate[VK_LBUTTON] = KEYON;
	_keystateage[VK_LBUTTON] = 0.0;
}

void cController::onRButtonDown(UINT nFlags)
{
	_keystate[VK_RBUTTON] = KEYON;
	_keystateage[VK_RBUTTON] = 0.0;
}

BOOL cController::repeated(int vkcode)
{
//TRACE ("keystate of %d in repeated call is %u\n", vkcode, _keystate[vkcode]);
	return keystate(vkcode) & GOTTWICEBIT;
}

void cController::update(Real dt)
{
		/* We used to rely on the CPopView::OnKeyUp to pass key released info to 
		the controller.  But a view only gets the OnKeyUp call when a view has the focus, and
		is not made if another window or even a dialog box has the focus. So we use the view-
		independent GetAsyncKeyState call to check if a key has been released.
			We DO use OnKeyDown to detect keys being pressed because we DO want the initiation
		of a key press to be dected ONLY when a view has the focus; othewise pressing the
		spacebar would make the players fire in all open documents.
		Note that this applies to VK_LBUTTON as well.  */

	_dt = dt; //Store this for possible use ... though we actually don't use it.
	for(int vkindex=0; vkindex< VKKEYCOUNT; vkindex++)
	{
		if (_keystate[vkindex] & KEYON) //Note you don't do this if state is KEYONLOCK.
		{
			if (!(0x8000 & ::GetAsyncKeyState(vkindex))) //Key isn't down.
	//Need these brackets to make the else switch off the first "if" and not the second "if".
			{
				if (!(vkindex == VK_LBUTTON && _keystate[cController::FAKELBUTTONKEY] != KEYOFF)) 
					/* If Lbutton isn't down, pretend it IS down
						if cController::FAKELBUTTONKEY is down */
				{
					_keystate[vkindex] = KEYOFF; //Turn off the keystate.
					_keystateage[vkindex] = 0.0;
				}
			}
	//Need these brackets to make the else switch off the first "if" and not the second "if".
			else //Key is down.
			{
				_keystateage[vkindex] += dt; //Age the keystate.
				if (_keystate[vkindex] & GOTONCEBIT)  //Do a two-bit counting process here
					_keystate[vkindex] |= GOTTWICEBIT;
				else 
					_keystate[vkindex] |= GOTONCEBIT;
			}
		//	TRACE("cController::update: nchar %u, dt %f, state %u, keyage %f\n",
		//		vkindex, dt, _keystate[vkindex], _keystateage[vkindex]);
		} //End if KEYON case
/*			In Oct, 2003, I was seeing a timelag between key press and action 
			in Windows XP and I thought maybe the key wasn't picking up the press
			right away, so I put the following code here to check on this, but it
			turned out this code never got hit.  ACtually the problem was due to
			an incompatible grahpics card driver, and not "really" XP's fault.
		//#define FORCEKEYON
		#ifdef FORCEKEYON
		else //Not KEYON
			if ((0x8000 & ::GetAsyncKeyState(vkindex))) //Key is actually down.
				cController::onKeyDown(vkindex, 0); //Force it on
		#endif //FORCEKEYON
*/
	} //End i loop on vkindex
}




