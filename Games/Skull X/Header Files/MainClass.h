////////////////////////////////////////////////////////////////////////
//	Program Name:	MainClass.h
//	Programmer:		Joseph Sutton
//	Company:			Moggie Software
//	Corporation:	Willy Wong Ping Pong Inc.
//	Description:	Main Class header File
//	Date:					6/18/99
//	Version:			2.00
////////////////////////////////////////////////////////////////////////
#ifndef _MAIN
#define _MAIN

//#include <winbase.h>
#include "mmsystem.h"

#include "..\Header Files\Program.h"

#include "..\Header Files\ErrorClass.h"

#include "..\Header Files\MainVarClass.h"
#define WND_BORDER 4
//
#define LOOP_OUT		0
#define LOOP_IN			1
#define LOOP_PAUSED 2

#define RE_NONE	0
#define RE_SOME	1
#define RE_ALL	2
//

typedef HRESULT (FAR PASCAL *LEVELPROC)(void *v, DWORD s);

class MAIN : public ERRORCLASS{
	public:
		// Error info.
		HRESULT						e;

		float level_rate;
		float	display_rate;
		float controls_rate;
		DWORD tick;

		//
		bool							Closing;
		//
		bool							LoadLevel;
		HMODULE						hLevel;
		LEVELPROC					LevelProc;
		//
		unsigned int ThreadLoop:2;
		void End(void){ ThreadLoop = 1; };

		bool GetStretchState(void){ return data.Stretch; };

		void Load(void);

	private:
		// Settings
		MainVar data;

		unsigned __int16	x, y, w, h;
		unsigned __int16	xMax;
		unsigned __int16	yMax;
		RECT							ChildRect;

// Window Info
		HWND				MainHwnd;
		HINSTANCE		MainhInst;
		HWND				ChildHwnd;
//
	public:
		bool Loop(void);
//
		BOOL Register(HINSTANCE hInst);
		HWND Create(HINSTANCE hInst, int Show = SW_SHOWNORMAL);	
		BOOL Main_Create(HWND hwnd, CREATESTRUCT FAR* lpCreateStruct);
		void Main_Destroy(HWND hwnd);
		void Main_Paint(HWND hwnd);
		void Main_Move(HWND hwnd, int x, int y);
		void Main_Activate(HWND hwnd, UINT state, HWND hwndActDeact, BOOL fMinimized);

		void CreateChildWindow(HWND);
		BOOL Child_Create(HWND childhwnd, CREATESTRUCT FAR* lpCreateStruct);
		void Child_Destroy(HWND hwnd);
		void Child_Paint(HWND hwnd);

		void Start(HWND hwnd);

		unsigned short Get_Delay(void){return data.Delay;};
		unsigned short Get_DelayRes(void){return data.DelayRes;};

//		DWORD Get_TimerID(void){return TimerID;};

		HWND Get_MainHwnd(void){ return MainHwnd; };
		HWND Get_ChildHwnd(void){ return ChildHwnd; };
		HINSTANCE Get_hInst(void){ return MainhInst; };

		void Set_data(MainVar d){ data = d; };
};

typedef	MAIN *P_MAIN, FAR *FP_MAIN;

#endif


