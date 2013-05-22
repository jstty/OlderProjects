// Controller.h: interface for the cController class.
//
//////////////////////////////////////////////////////////////////////

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "realnumber.h"

/* A peculiarity of the Windows VK code system is that you only use VK symbols for non-ASCII keys like 
VK_CONTROL or VK_INSERT or VK_F2.	For	ASCII keys 0-9 and A-Z, you have to use the key character in 
single quotes. Thus VK_Z is not an acceptable code; you must	use 'Z'.  This makes life needlessly
confusing, so we correct it here.*/
#define VK_A 'A'
#define VK_B 'B'
#define VK_C 'C'
#define VK_D 'D'
#define VK_E 'E'
#define VK_F 'F'
#define VK_G 'G'
#define VK_H 'H'
#define VK_I 'I'
#define VK_J 'J'
#define VK_K 'K'
#define VK_L 'L'
#define VK_M 'M'
#define VK_N 'N'
#define VK_O 'O'
#define VK_P 'P'
#define VK_Q 'Q'
#define VK_R 'R'
#define VK_S 'S'
#define VK_T 'T'
#define VK_U 'U'
#define VK_V 'V'
#define VK_W 'W'
#define VK_X 'X'
#define VK_Y 'Y'
#define VK_Z 'Z'
#define VK_0 '0'
#define VK_1 '1'
#define VK_2 '2'
#define VK_3 '3'
#define VK_4 '4'
#define VK_5 '5'
#define VK_6 '6'
#define VK_7 '7'
#define VK_8 '8'
#define VK_9 '9'
/* Another issue is that there aren't VK_PAGEDOWN and VK_PAGEUP, these keycodes are defined as VK_PRIOR
and VK_NEXT. */
#define VK_PAGEUP VK_PRIOR
#define VK_PAGEDOWN VK_NEXT
/* The center, or '5', key on the numeric keypad is useful sometimes, but its not well-known
that its name is VK_CLEAR. Note you only get this if NumLock is OFF.  Otherwise you'd get
VK_NUMPAD5. */

#define KLUDGEFIX
	/*	Nov 3, 2003, I have a bug with an nchar value of 255 coming in, 
	so I tried a kludge fix my making teh VKKEYCOUNT be 256. I sporadically
	get the bug when using the arrow key controls to move the viewpoint. 
	This happened after enabling OpenGL text. */
#ifdef KLUDGEFIX
	#define VKKEYCOUNT 0x100  
#else //Not KLUDGEFIX
	#define VKKEYCOUNT 0xA6  
#endif //KLUDGEFIX
	/* The purpose of VKKEYCOUNT is that we save on/off values for all the 
	various VK codes, which currently run from 0 to 0xA5, see the MFC winuser.h 
	for their names and values.  This file is in the Visual C++ include
	directory (which will have a name similar to
	c:\Program Files\Microsoft Visual Studio\VC98\Include, or you can use Windows
	Start|Find to locate it.  We aren't allowed to use a static const as an 
	argument to an array constructor, so we use a #define. */

class cController : public CObject
{
DECLARE_SERIAL(cController);
public:
	static const int KEYOFF;
	static const int KEYON;
	static const int KEYONLOCK;
	static const UINT SHIFTBIT;
	static const UINT CONTROLBIT;
	static const UINT GOTONCEBIT;
	static const UINT GOTTWICEBIT; /* The cController::update uses GOTONCEBIT and
		GOTTWICEBIT in the keystate values to signal if a keycode has been available
		for more than one update cycle. We need two flags because we bump this
		"counter" at the start of the cGame::step call to _pcontroller->update,
		so there's always been at least one update before the listener gets to
		look at the controller's keystates. */
	static const UINT TYPEMATICBIT; /* Use to signal when the keyboard typetmatic repeat 
		feature has sent more than one OnKeyDown message for this key, though normally
		you don't care. */
	static const UINT FAKELBUTTONKEY;
protected:
	UINT _keystate[VKKEYCOUNT];
	Real _keystateage[VKKEYCOUNT];
	Real _dt; //Current timestep being used, we use this info in cGame::onMouseMouseMove.
public:
	cController();
	UINT keystate(int vkcode){ASSERT(vkcode < VKKEYCOUNT); return _keystate[vkcode];}
	BOOL keyon(int vkcode){return keystate(vkcode) & (KEYON | KEYONLOCK);}
	BOOL control(int vkcode){return keystate(vkcode) & CONTROLBIT;}
	BOOL repeated(int vkcode); //Return TRUE if GOTTWICEBIT is on.
	BOOL shift(int vkcode){return keystate(vkcode) & SHIFTBIT;}
	BOOL keyonplain(int vkcode){return keyon(vkcode) && !control(vkcode) && !shift(vkcode);}
	BOOL keyoncontrol(int vkcode){return keyon(vkcode) && control(vkcode) && !shift(vkcode);}
	BOOL keyonshift(int vkcode){return keyon(vkcode) && shift(vkcode) && !control(vkcode);}
	BOOL keyoncontrolshift(int vkcode){return keyon(vkcode) && control(vkcode) && shift(vkcode);}
			// The following *single accessors only return TRUE once per keypress.
	BOOL keyonsingle(int vkcode){return keyon(vkcode) && !repeated(vkcode);}
	BOOL keyonplainsingle(int vkcode){return keyon(vkcode) && !control(vkcode) && !shift(vkcode)
		&& !repeated(vkcode);}
	BOOL keyoncontrolsingle(int vkcode){return keyon(vkcode) && control(vkcode) && !shift(vkcode)
		&& !repeated(vkcode);}
	BOOL keyonshiftsingle(int vkcode){return keyon(vkcode) && shift(vkcode) && !control(vkcode)
		&& !repeated(vkcode);}
	BOOL keyoncontrolshiftsingle(int vkcode){return keyon(vkcode) && control(vkcode) && shift(vkcode)
		&& !repeated(vkcode);}
		/* Sometimes, as when using an arrow key to spin a player, it is useful
		to know how long a key has been depressed. */
	Real keystateage(int vkcode){ASSERT(vkcode < VKKEYCOUNT); return _keystateage[vkcode];}
	Real dt(){return _dt;}
	void setKeystate(int vkcode, int state)
		{ASSERT(vkcode < VKKEYCOUNT);_keystate[vkcode] = state; _keystateage[vkcode] = 0.0;}
	virtual void Serialize(CArchive &ar){CObject::Serialize(ar);}
	virtual void onKeyDown(UINT nChar, UINT nFlags); //Store info in _keyflags
	virtual void onKeyUp(UINT nChar, UINT nFlags){} //Use the GetAsyncKeyState to detect this.
	virtual void onLButtonDown(UINT nFlags);
	virtual void onRButtonDown(UINT nFlags);
	virtual void onLButtonUp(UINT nFlags){} //Use the GetAsyncKeyState to detect this.
	virtual void onRButtonUp(UINT nFlags){} //Use the GetAsyncKeyState to detect this.
	virtual void onMouseMove(UINT nFlags){}
	virtual void update(Real dt);  /* cController uses update to check for when
		keys are no longer depressed and for when keys have been made availalble
		to the listeners more than once. */
};

#endif //CONTROLLER_H