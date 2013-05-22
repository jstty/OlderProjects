////////////////////////////////////////////////////////////////////////
//	Program Name:	ActionClass.h
//	Programmer:		Joseph Sutton
//	Company:			Moggie Software
//	Corporation:	Willy Wong Ping Pong Inc.
//	Description:	Action Class header File
//	Date:					6/18/99
//	Version:			2.00
////////////////////////////////////////////////////////////////////////
#ifndef _ACTION
#define _ACTION

#include "..\Header Files\ErrorClass.h"
#include "..\Header Files\ActionVarClass.h"

#include "..\Header Files\gfx.h"

DWORD WINAPI ThreadProc(LPVOID msg);

class ACTION : public ERRORCLASS{
	public:
		HRESULT	e;
		unsigned __int16	Delay;
		unsigned __int16	DelayRes;

		unsigned int ThreadLoop:2;
		//
		void End(void){ ThreadLoop = 1;	};
		bool Loop(void);

		void Set_data(ActionVar v)
		{
			Delay = v.Delay;
			DelayRes = v.DelayRes;
		};
		bool Load(void);

		//
		void MoveObject(LAYER *l);
		void CheckCol(LAYER *l);
		
		//
		unsigned __int8 i;
		DWORD		tick;
		MOVE	*tm;
		MOVE	*Move;

		COL	*Col;
		COL	*tc1;
		COL	*tc2;
		LAYER *tl;
};

typedef ACTION *P_ACTION, FAR *FP_ACTION;

#endif