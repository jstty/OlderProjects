////////////////////////////////////////////////////////////////////////
//	Program Name:	Sound.cpp
//	Programmer:		Joseph Sutton
//	Company:			Moggie Software
//	Corporation:	Willy Wong Ping Pong Inc.
//	Description:	Sound File
//	Date: 
////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdarg.h>

#include <direct.h>
#include <dmusicc.h>
#include <dmusici.h>

#include "..\Header Files\ValuesClass.h"
extern VALUES		*Val;

#ifdef _DEBUG
	#include "..\Header Files\TestSpeed.h"
	extern TestSpeed tsSound;
#endif
//
//
//
//
bool SOUND::Loop(void)
{
	HANDLE hThread = GetCurrentThread();
//	CRITICAL_SECTION cs;
//	InitializeCriticalSection(&cs);

//
	while(ThreadLoop == 0)
	{
//		EnterCriticalSection(&cs);
//
		#ifdef _DEBUG
				if(tsSound.Rate > 100)
					return 0;

				tsSound.Loop();
		#endif
// Code

	//	Fx();
	//	Midi();

//
//		LeaveCriticalSection(&cs);
		WaitForSingleObject(hThread, Delay);
	}

	ThreadLoop = 2;
	return 0;
}
///////////////////////////////////////////////////////
// Display_ThreadProc
///////////////////////////////////////////////////////
DWORD WINAPI Sound_ThreadProc(LPVOID msg)
{
	return Val->Sound->Loop();
}

//
//
bool SOUND::Load(void)
{
	// Init Sound
	/*
		e = CoInitialize(NULL);

		e = CoCreateInstance(CLSID_DirectMusicLoader, NULL, CLSCTX_INPROC, IID_IDirectMusicLoader, (void**)&dmLoader);

		e = CoCreateInstance(CLSID_DirectMusicPerformance, NULL, CLSCTX_INPROC, IID_IDirectMusicPerformance, (void**)&dmPerf);

		e = InitializeSynth();

		e = LoadSegment(0);

		dmSeg->SetRepeats(200);

		GUID guid = GUID_IDirectMusicStyle;
		e = g_pSegment->GetParam( guid, 0xffffffff, 0, 0, NULL, (void*)&g_pStyle );
	*/

	return 0;
}