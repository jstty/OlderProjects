////////////////////////////////////////////////////////////////////////
//	Program Name:	SoundVarClass.h
//	Programmer:		Joseph Sutton
//	Company:			Moggie Software
//	Corporation:	Willy Wong Ping Pong Inc.
//	Description:	Sound Var Class header File
//	Date:					6/18/99
//	Version:			2.00
////////////////////////////////////////////////////////////////////////
#ifndef _SOUND_VAR
#define _SOUND_VAR

class SoundVar
{
	public:
			// Delay time for loop in milli sec.
		unsigned __int16	Delay;
			// Will the delay be on time. if MainDelayRes = 0, yes. if greater than 0 maybe.
		unsigned __int16	DelayRes;
		//
		bool PlayFx;
		bool PlayMidi;
};

#endif