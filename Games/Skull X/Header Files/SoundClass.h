////////////////////////////////////////////////////////////////////////
//	Program Name:	SoundClass.h
//	Programmer:		Joseph Sutton
//	Company:			Moggie Software
//	Corporation:	Willy Wong Ping Pong Inc.
//	Description:	Sound Class header File
//	Date:					6/18/99
//	Version:			2.00
////////////////////////////////////////////////////////////////////////
#ifndef _SOUND
#define _SOUND

#include <direct.h>
#include <dmusicc.h>
#include <dmusici.h>

#include "..\Header Files\ErrorClass.h"
#include "..\Header Files\SoundVarClass.h"

DWORD WINAPI ThreadProc(LPVOID msg);

class SOUND : public ERRORCLASS{
/*
		IDirectMusicLoader*      dmLoader;
		IDirectMusicPerformance* dmPerf;
		IDirectMusicSegment*     dmSeg;
		IDirectMusicStyle*       dmStyle;
		WCHAR                    g_awszMotifName[9][MAX_PATH];
*/
	public:
		HRESULT	e;
		unsigned __int16	Delay;
		unsigned __int16	DelayRes;

		unsigned int ThreadLoop:2;
		//
		void End(void){ ThreadLoop = 1;	};
		bool Loop(void);

		bool Load(void);

		void Set_data(SoundVar v)
		{
			Delay = v.Delay;
			DelayRes = v.DelayRes;
		};

};

typedef SOUND *P_SOUND, FAR *FP_SOUND;

#endif