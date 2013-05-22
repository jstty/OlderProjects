////////////////////////////////////////////////////////////////////////
//	Program Name:	ActionVarClass.h
//	Programmer:		Joseph Sutton
//	Company:			Moggie Software
//	Corporation:	Willy Wong Ping Pong Inc.
//	Description:	Action Var Class header File
//	Date:					6/18/99
//	Version:			2.00
////////////////////////////////////////////////////////////////////////
#ifndef _ACTION_VAR
#define _ACTION_VAR

class	ActionVar
{
	public:
			// Delay time for loop in milli sec.
		unsigned __int16	Delay;
			// Will the delay be on time. if MainDelayRes = 0, yes. if greater than 0 maybe.
		unsigned __int16	DelayRes;
		//
};

#endif