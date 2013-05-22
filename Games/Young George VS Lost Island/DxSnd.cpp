////////////////////////////////////////////////////////////////////////
//	Program Name:	DxSnd.cpp
//	Programmer:		Joseph Sutton
//	Company:			Moggie Software
//	Corporation:	Willy Wong Ping Pong Inc.
//	Description:	DirectX Sound File
//	Date: 
////////////////////////////////////////////////////////////////////////
#include <windows.h>
#include <stdio.h>  
#include <string.h>
#include <dsound.h>
#include "E:\My Code\Young George VS Lost Island\YoungGeroge.h"
#include "E:\My Code\Young George VS Lost Island\resource.h"
#include "DxSnd.h"

			//////////////////////////////////////
			//  WAVE Load
			//////////////////////////////////////
SOUND LoadWaveFile(HINSTANCE hInst, SOUND sound)
{
	SOUND	TempSound = sound;
	IDirectSound				*ds;
	DSBUFFERDESC				dsbd;
	HRSRC								hrsrc;
	HGLOBAL							hRData;
	DWORD								*pRData;
	LPBYTE							pMem1, pMem2;
	DWORD								dwSize1, dwSize2;

	DirectSoundCreate(NULL, &ds, NULL);
	ds->SetCooperativeLevel(global->MainVar.ChildHwnd, DSSCL_NORMAL);

	memset(&dsbd, 0, sizeof(DSBUFFERDESC));
	dsbd.dwSize = sizeof(DSBUFFERDESC);
	dsbd.dwFlags = DSBCAPS_STATIC | DSBCAPS_CTRLDEFAULT;

	for(UINT i = 0; i < TempSound.wav.nfile; i++)
		{
		if( TempSound.wav.file[i] != -1)
			{
			hrsrc = FindResource(hInst, MAKEINTRESOURCE(TempSound.wav.file[i]), "WAVE");
			hRData = LoadResource(hInst, hrsrc);
			pRData = (DWORD *)LockResource(hRData);
			dsbd.dwBufferBytes = *(pRData + 10);
			dsbd.lpwfxFormat = (LPWAVEFORMATEX)(pRData + 5);

			ds->CreateSoundBuffer(&dsbd, &TempSound.wav.DSBuffer[i], NULL);

			TempSound.wav.DSBuffer[i]->Lock(0, dsbd.dwBufferBytes, (void **)&pMem1, &dwSize1,
																				(void **)&pMem2, &dwSize2, 0);
			memcpy(pMem1, (LPBYTE)(pRData + 11), dwSize1);
			if (dwSize2 != 0)
					memcpy(pMem2, (LPBYTE)(pRData + 11) + dwSize1, dwSize2);
			TempSound.wav.DSBuffer[i]->Unlock(pMem1, dwSize1, pMem2, dwSize2);
			}
		}
return TempSound;
}
			//////////////////////////////////////
			//  WAVE Proc.
			//////////////////////////////////////
void WaveProc(UINT uNum, UINT uControl, DWORD uMsg)
{
BOOL all = FALSE;
if(uNum == 0)
	all = TRUE;

switch(uControl)
	{
	case IDM_PLAY:
		{
		if(all)
			{
			for(UINT i = 0; i < global->sound.wav.nfile; i++)
				 global->sound.wav.DSBuffer[i]->Play(0, 0, uMsg);
			}
		else
			 global->sound.wav.DSBuffer[uNum]->Play(0, 0, uMsg);
		} break;
	case IDM_STOP:
		{
		if(all)
			{
			for(UINT i = 0; i <  global->sound.wav.nfile; i++)
				 global->sound.wav.DSBuffer[i]->Stop();
			}
		else
			 global->sound.wav.DSBuffer[uNum]->Stop();
		} break;
	}
}
