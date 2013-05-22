////////////////////////////////////////////////////////////////////////
//	Program Name:	ControlsClass.h
//	Programmer:		Joseph Sutton
//	Company:			Moggie Software
//	Corporation:	Willy Wong Ping Pong Inc.
//	Description:	Controls Class header File
//	Date:					6/18/99
//	Version:			2.00
////////////////////////////////////////////////////////////////////////
#ifndef _CONTROLS
#define _CONTROLS

#include "..\Header Files\ErrorClass.h"

#include "..\Header Files\ControlVarClass.h"

class CONTROLS : public ERRORCLASS {
	public:
		//
		unsigned int ThreadLoop:2;
		void End(void)	{	ThreadLoop = 1; };
//
		bool Controls_Loop(void);
		void Joy_Loop(void);
		void Key_Loop(void);
		void Sys_Loop(void);
		//
		void OnMouse(HWND hwnd, int x, int y, UINT keyFlags);

		void OnMouseLDown(HWND hwnd, BOOL fDoubleClick, int x, int y, UINT keyFlags);
		void OnMouseRDown(HWND hwnd, BOOL fDoubleClick, int x, int y, UINT keyFlags);
		void OnMouseMDown(HWND hwnd, BOOL fDoubleClick, int x, int y, UINT keyFlags);

		void OnMouseLUp(HWND hwnd, int x, int y, UINT flags);
		void OnMouseRUp(HWND hwnd, int x, int y, UINT flags);
		void OnMouseMUp(HWND hwnd, int x, int y, UINT flags);
		// Func.
		void Set_data(ControlVar cv, bool load_default = 0);
		//
		bool TestKey(Key kb);
		//
		void OnKey(HWND hwnd, UINT vk, BOOL fDown, int cRepeat, UINT flags);
//

		unsigned __int16 Delay;
		unsigned __int16 DelayRes;

		unsigned __int8 NumPlayer;

		unsigned __int8 NumsKey;
		Key	*sKey;

		unsigned __int8 NumpKey;
		Key	*pKey;
		unsigned __int8 kPlayerNum;

		unsigned __int8 NumJoy;
		JoyStick	*Joy;

		//
		DBOOL	**Player;

		//
		unsigned __int8	j;
		unsigned __int8	b;
		unsigned __int8	k;

		DBOOL *TempPlayer;
		JoyStick	*TempJoy;
		Key				TempKey;

		HWND hWnd;
		RECT ChildRect;

		bool Cursor;
		MOUSE_INFO Mouse;

		unsigned __int16	xMax;
		unsigned __int16	yMax;

		//
		JOYINFOEX	JoyInfo;
};

typedef CONTROLS * P_CONTROLS, FAR *FP_CONTROLS;

#endif
