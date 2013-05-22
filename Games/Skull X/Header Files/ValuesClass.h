////////////////////////////////////////////////////////////////////////
//	Program Name:	ValuesClass.h
//	Programmer:		Joseph Sutton
//	Company:			Moggie Software
//	Corporation:	Willy Wong Ping Pong Inc.
//	Description:	Values Class header File
//	Date:					6/18/99
//	Version:			2.00
////////////////////////////////////////////////////////////////////////
#ifndef _VALUES
#define _VALUES

#include <time.h>

#include "..\Header Files\ErrorClass.h"

#include "..\Header Files\FileUtilClass.h"

#include "..\Header Files\MainClass.h"
#include "..\Header Files\ControlsClass.h"
#include "..\Header Files\DisplayClass.h"
#include "..\Header Files\ActionClass.h"
#include "..\Header Files\SoundClass.h"
#include "..\Header Files\GameClass.h"

struct SETUPFILE
{
	// 255 max
	unsigned __int8 Version;
	MainVar			mv;
	ControlVar	cv;
	DisplayVar	dv;
	ActionVar		av;
	SoundVar		sv;
};

struct GAMESETUP
{
	// 255 max
	unsigned __int8 Version;
	GSMainVar			mv;
	GSControlVar	cv;
};


	// Debug and level refresh
DWORD WINAPI Main_ThreadProc(LPVOID lpParam);

	// Joystick and keyboard
DWORD WINAPI Controls_ThreadProc(LPVOID msg);

	// Sprite, image, tile, map, and draw screen.
DWORD WINAPI Display_ThreadProc(LPVOID msg);

	// Collision, animation, and movement
DWORD WINAPI Action_ThreadProc(LPVOID msg);

	// Wav and Midi
DWORD WINAPI Sound_ThreadProc(LPVOID msg);

class VALUES : public ERRORCLASS{
public:
//	private:
		HGLOBAL		hFile_Util;
		HGLOBAL		hMain;
		HGLOBAL		hControls;
		HGLOBAL		hDisplay;
		HGLOBAL		hAction;
		HGLOBAL		hSound;
		HGLOBAL		hGame;
		//
		HANDLE		Main_hThread;
/*
		HANDLE		Controls_hThread;
		HANDLE		Display_hThread;
		HANDLE		Action_hThread;
		HANDLE		Sound_hThread;
*/
	public:
		// Version
		DWORD Size;
		//
		FILE_UTIL		*File_Util;
		MAIN				*Main;
		CONTROLS		*Controls;
		DISPLAY			*Display;
		ACTION			*Action;
		SOUND				*Sound;
		GAME				*Game;

		//
		bool LoadAll(void)
		{
			SetLastError(0);
			SetError_Format();

			hFile_Util = GlobalAlloc(GHND, sizeof(FILE_UTIL) );
			if(GetLastError() != NO_ERROR)
				return Error(NULL, "VALUES", "LoadAll:GlobalAlloc", GetLastError() );

			File_Util = (FILE_UTIL*)GlobalLock(hFile_Util);
			if(GetLastError() != NO_ERROR)
				return Error(NULL, "VALUES", "LoadAll:GlobalLock", GetLastError() );

			if(File_Util->LoadMem( (HGLOBAL &)Main, hMain, sizeof(MAIN) ) )
				return 1;

			if(File_Util->LoadMem( (HGLOBAL &)Controls, hControls, sizeof(CONTROLS) ) )
				return 1;

			if(File_Util->LoadMem( (HGLOBAL &)Display, hDisplay, sizeof(DISPLAY) ) )
				return 1;

			if(File_Util->LoadMem( (HGLOBAL &)Action, hAction, sizeof(ACTION) ) )
				return 1;

			if(File_Util->LoadMem( (HGLOBAL &)Sound, hSound, sizeof(SOUND) ) )
				return 1;

			if(File_Util->LoadMem( (HGLOBAL &)Game, hGame, sizeof(GAME) ) )
				return 1;
			
			return 0;
		};
		//
		bool FreeAll(void)
		{
			if( File_Util->FreeMem(hMain) )
				return 1;

			if( File_Util->FreeMem(hControls) )
				return 1;

			if( File_Util->FreeMem(hDisplay) )
				return 1;

			if( File_Util->FreeMem(hAction) )
				return 1;

			if( File_Util->FreeMem(hSound) )
				return 1;

			GlobalUnlock(hFile_Util);
			if( GetLastError() != NO_ERROR)
				return Error(NULL, "VALUES", "FreeAll:GlobalUnlock", GetLastError());

			GlobalDiscard(hFile_Util);

			if( GetLastError() != NO_ERROR)
				return Error(NULL, "VALUES", "FreeAll:GlobalDiscard", GetLastError());

			return 0;
		};

		void	InitObjects(void)
		{
			InitError();
			File_Util->InitError();
			Main->InitError();
			Controls->InitError();
			Display->InitError();
			Action->InitError();
			Sound->InitError();
		}
		//
		
		
		bool LoadSetup(SETUPFILE *f);
		void SetGlobal(void);

		//
		//
		//
		bool CreateLoops(void)
		{
			if( cLoop(Main_hThread,			Main_ThreadProc,			"MAIN",			Main->Get_DelayRes() ) )
				return 1;

			return 0;
		}
		//
		bool StartLoops(void)
		{
			if(Main_hThread)
			{
				if( sLoop(Main_hThread, "MAIN") )
				{
					Main_hThread = NULL;
					/*
					Display_hThread = NULL;
					Action_hThread = NULL;
					Controls_hThread = NULL;
					Sound_hThread = NULL;
					*/
					return 1;
				}
			}

			bool loop = 1;
			HANDLE hThread = GetCurrentThread();
			while(loop)
			{
				WaitForSingleObject(hThread, 500);
				if(Main->LoadLevel == 1)
					loop = 0;
				else if(Main->ThreadLoop == 2)
				{
					Error(NULL, "VALUES", "CreateLoop:Main_hThread", 100);
					/*
					Display_hThread = NULL;
					Action_hThread = NULL;
					Controls_hThread = NULL;
					Sound_hThread = NULL;
					*/
					return 1;
				}
			}

			return 0;
		}
		//
		bool DestroyLoops(void)
		{
			if(!Main->ThreadLoop)
			{
				Main->End();
			}
			else
			{
				Main->ThreadLoop = 2;
				Controls->ThreadLoop = 2;
				Display->ThreadLoop = 2;
				Action->ThreadLoop = 2;
				Sound->ThreadLoop = 2;
			}

			return 0;
		}
//
//
		bool sLoop(HANDLE &h, char *c)
		{
			ResumeThread(h);
			if(GetLastError() != NO_ERROR)
				return Error(NULL, c, "StartLoops:ResumeThread", GetLastError() );

			return 0;
		}
		//
		bool cLoop(HANDLE &h, LPTHREAD_START_ROUTINE Proc, char *c, int p, void *Var = NULL)
		{
			DWORD ID;
			SetLastError(0);

			h = CreateThread(NULL, 0,  Proc, Var, CREATE_SUSPENDED, &ID);
			if(GetLastError() != NO_ERROR)
				return Error(NULL, c, "CreateLoops:CreateThread", GetLastError() );

			if( (p == THREAD_PRIORITY_IDLE) ||
					(p == THREAD_PRIORITY_LOWEST) ||
					(p == THREAD_PRIORITY_BELOW_NORMAL) ||
					(p == THREAD_PRIORITY_NORMAL) ||
					(p == THREAD_PRIORITY_ABOVE_NORMAL) ||
					(p == THREAD_PRIORITY_HIGHEST) ||
					(p == THREAD_PRIORITY_TIME_CRITICAL) )
			{
				SetThreadPriority(h, p);
				if(GetLastError() != NO_ERROR)
					return Error(NULL, c, "CreateLoop:SetThreadPriority", GetLastError() );
			}
			else
				return Error(NULL, c, "CreateLoop:InvalidPriority", p );

			return 0;
		}
};

typedef VALUES *P_VALUES, FAR *FP_VALUES;

#endif

