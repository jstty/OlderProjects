////////////////////////////////////////////////////////////////////////
//	Program Name:	CDPlayer.cpp
//	Programmer:		Joseph Sutton
//	Company:			Moggie Software
//	Corporation:	Willy Wong Ping Pong Inc.
//	Description:	Dialog Utils File
//	Date: 
////////////////////////////////////////////////////////////////////////
#include <windows.h>
#include <stdio.h>
#include <string.h>
#include <commctrl.h>
#include "E:\My Code\Young George VS Lost Island\YoungGeroge.h"
#include "E:\My Code\Young George VS Lost Island\resource.h"
#include "CDPlayer.h"

			//////////////////////////////////////
			//  START
			//////////////////////////////////////
void StartCD(HWND hwndDlg)
{
if(TabIndex != ID_CDPLAYER)
	{
	if(SendDlgItemMessage(hwndDlg, IDCDSND, BM_GETCHECK, (WPARAM)(0), (LPARAM)(0)) == BST_CHECKED)
		{
		// Get number of track
		CDProc(IDM_TRACK);
		for(UINT i = 0; i < global->sound.cd.nTrack; i++)
			{
			global->sound.cd.TrackNumber[i] = i+1;
			}
		char S[256];
		global->sound.cd.CTrack = global->sound.cd.TrackNumber[0];
		sprintf(S, " %u", global->sound.cd.CTrack);
		SetDlgItemText(hwndDlg, IDC_TRACK, S);
		PlayList(hwndDlg, LOAD_CD);
		// Get number of track
		global->sound.cd.TMin		= 0;
		global->sound.cd.TSec		= 0;
		global->sound.cd.TFrm		= 0;
		KillTimer(global->MainVar.ChildHwnd, IDT_CDTIMER);
		global->sound.cd.CDGStat = IDM_STOP;
		
		TC_ITEM FAR *item = (TC_ITEM FAR *)malloc(sizeof(TC_ITEM));
		item->mask = TCIF_TEXT;
		item->pszText = "CD Player";
		item->cchTextMax = sizeof(item->pszText);
		SendDlgItemMessage(hwndDlg, IDC_TABBAR, TCM_INSERTITEM, (WPARAM)(ID_CDPLAYER), (LPARAM)(const TC_ITEM FAR*)(item) );
		// STOP CD
		CDProc(global->sound.cd.CDGStat);
		SendDlgItemMessage(hwndDlg, IDC_CD_STOP, BM_SETCHECK, (WPARAM)(BST_CHECKED), (LPARAM)(0));
		SendDlgItemMessage(hwndDlg, IDC_CD_PAUSE, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
		SendDlgItemMessage(hwndDlg, IDC_CD_RW, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
		SendDlgItemMessage(hwndDlg, IDC_CD_FF, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
		SendDlgItemMessage(hwndDlg, IDC_CD_PLAY, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
		SendDlgItemMessage(hwndDlg, IDC_CD_EJECT, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));

		SendDlgItemMessage(hwndDlg, IDC_EDIT_PL, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
		SendDlgItemMessage(hwndDlg, IDC_SHUF, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
		SendDlgItemMessage(hwndDlg, IDC_PLAYLIST, EM_SETREADONLY, (WPARAM)(TRUE), (LPARAM)(0));
		}
	else 
		{
		if(global->sound.cd.CDGStat == IDM_PLAY)
			{
			global->sound.cd.CDGStat = IDM_STOP;
			CDProc(global->sound.cd.CDGStat);
			}
		global->sound.cd.CDGStat = IDM_NULL;
		SendDlgItemMessage(hwndDlg, IDC_TABBAR, TCM_DELETEITEM, (WPARAM)(ID_CDPLAYER), (LPARAM)(0));
		}
	}
else
	SendDlgItemMessage(hwndDlg, IDCDSND, BM_SETCHECK, (WPARAM)(BST_CHECKED), (LPARAM)(0));
}
			//////////////////////////////////////
			//  TAB
			//////////////////////////////////////
void TabCD(HWND hwndDlg)
{
	if(global->sound.cd.CDGStat == IDM_PLAY)
		SendDlgItemMessage(hwndDlg, IDC_CD_PLAY, BM_SETCHECK, (WPARAM)(BST_CHECKED), (LPARAM)(0));
	//
	else if(global->sound.cd.CDGStat == IDM_STOP)
		SendDlgItemMessage(hwndDlg, IDC_CD_STOP, BM_SETCHECK, (WPARAM)(BST_CHECKED), (LPARAM)(0));
	//
	else if(global->sound.cd.CDGStat == IDM_PAUSE)
		{
		SendDlgItemMessage(hwndDlg, IDC_CD_PLAY, BM_SETCHECK, (WPARAM)(BST_CHECKED), (LPARAM)(0));
		SendDlgItemMessage(hwndDlg, IDC_CD_PAUSE, BM_SETCHECK, (WPARAM)(BST_CHECKED), (LPARAM)(0));
		}
	//
	else if(global->sound.cd.CDGStat == IDM_OPEN)
		SendDlgItemMessage(hwndDlg, IDC_CD_EJECT, BM_SETCHECK, (WPARAM)(BST_CHECKED), (LPARAM)(0));
	//
	else if(global->sound.cd.CDGStat == IDM_SEEK_RW)
		SendDlgItemMessage(hwndDlg, IDC_CD_RW, BM_SETCHECK, (WPARAM)(BST_CHECKED), (LPARAM)(0));
	//
	else if(global->sound.cd.CDGStat == IDM_SEEK_FF)
		SendDlgItemMessage(hwndDlg, IDC_CD_FF, BM_SETCHECK, (WPARAM)(BST_CHECKED), (LPARAM)(0));
// Track/Disk Controls
	if(global->sound.cd.CDRStat == IDM_TRACK)
		{
		SendDlgItemMessage(hwndDlg, IDC_RTRACK, BM_SETCHECK, (WPARAM)(BST_CHECKED), (LPARAM)(0));
		SendDlgItemMessage(hwndDlg, IDC_RDISK, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
		}
	else if(global->sound.cd.CDRStat == IDM_DISK)
		{
		SendDlgItemMessage(hwndDlg, IDC_RTRACK, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
		SendDlgItemMessage(hwndDlg, IDC_RDISK, BM_SETCHECK, (WPARAM)(BST_CHECKED), (LPARAM)(0));
		}
	else
		{
		SendDlgItemMessage(hwndDlg, IDC_RTRACK, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
		SendDlgItemMessage(hwndDlg, IDC_RDISK, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
		}

	char S[256];
	sprintf(S, " %u", global->sound.cd.CTrack);
	SetDlgItemText(hwndDlg, IDC_TRACK, S);

	PlayList(hwndDlg, LOAD_CD);

	SetTimer(hwndDlg, IDT_CDPLAYER, CDTIME, (TIMERPROC)CD_DlgTimerProc);
// General TAB
	ShowItem(hwndDlg, IDHELPTXT,		SWP_HIDEWINDOW);
	ShowItem(hwndDlg, IDEXIT,				SWP_HIDEWINDOW);
	ShowItem(hwndDlg, IDMIDISND,		SWP_HIDEWINDOW);
	ShowItem(hwndDlg, IDWAVSND,			SWP_HIDEWINDOW);
	ShowItem(hwndDlg, IDCDSND,			SWP_HIDEWINDOW);
// Load/Save TAB
	ShowItem(hwndDlg, IDLOAD,				SWP_HIDEWINDOW);
	ShowItem(hwndDlg, IDSAVE,				SWP_HIDEWINDOW);
// CD Player TAB
	ShowItem(hwndDlg, IDC_EDIT_PL,	SWP_SHOWWINDOW);
	ShowItem(hwndDlg, IDC_SHUF,			SWP_SHOWWINDOW);
	ShowItem(hwndDlg, IDC_PLAYLIST,	SWP_SHOWWINDOW);
	ShowItem(hwndDlg, IDC_RTRACK,		SWP_SHOWWINDOW);
	ShowItem(hwndDlg, IDC_RDISK,		SWP_SHOWWINDOW);
	ShowItem(hwndDlg, IDC_S_TRACK,	SWP_SHOWWINDOW);
	ShowItem(hwndDlg, IDC_S_TIME,		SWP_SHOWWINDOW);
	ShowItem(hwndDlg, IDC_TRACK,		SWP_SHOWWINDOW);
	ShowItem(hwndDlg, IDC_TIME,			SWP_SHOWWINDOW);
	ShowItem(hwndDlg, IDC_CD_RW,		SWP_SHOWWINDOW);
	ShowItem(hwndDlg, IDC_CD_PLAY,	SWP_SHOWWINDOW);
	ShowItem(hwndDlg, IDC_CD_FF,		SWP_SHOWWINDOW);
	ShowItem(hwndDlg, IDC_CD_PAUSE,	SWP_SHOWWINDOW);
	ShowItem(hwndDlg, IDC_CD_STOP,	SWP_SHOWWINDOW);
	ShowItem(hwndDlg, IDC_CD_EJECT,	SWP_SHOWWINDOW);
}
			//////////////////////////////////////
			//  PLAY
			//////////////////////////////////////
void PlayCD(HWND hwndDlg)
{
	if(global->sound.cd.CDGStat != IDM_OPEN)
		{
		if(global->sound.cd.CDGStat != IDM_TRACK)
			{
			global->sound.cd.CDGStat = IDM_PLAY;
			SendDlgItemMessage(hwndDlg, IDC_CD_PLAY, BM_SETCHECK, (WPARAM)(BST_CHECKED), (LPARAM)(0));
			SendDlgItemMessage(hwndDlg, IDC_CD_STOP, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
			SendDlgItemMessage(hwndDlg, IDC_CD_PAUSE, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
			SendDlgItemMessage(hwndDlg, IDC_CD_RW, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
			SendDlgItemMessage(hwndDlg, IDC_CD_FF, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
			SendDlgItemMessage(hwndDlg, IDC_CD_EJECT, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
			// PLAY CD
			CDProc(global->sound.cd.CDGStat);
			}
		else
			SendDlgItemMessage(hwndDlg, IDC_CD_PLAY, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
		}
	else
		SendDlgItemMessage(hwndDlg, IDC_CD_PLAY, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
}
			//////////////////////////////////////
			//  PAUSE
			//////////////////////////////////////
void PauseCD(HWND hwndDlg)
{
	if(global->sound.cd.CDGStat != IDM_OPEN) 
		{
		if(global->sound.cd.CDGStat != IDM_TRACK)
			{
			if(global->sound.cd.CDGStat == IDM_PAUSE)
				{
				global->sound.cd.CDGStat = IDM_PLAY;
				// IDM_PLAY CD
				CDProc(global->sound.cd.CDGStat);
				}
			else
				{
				KillTimer(global->MainVar.ChildHwnd, IDT_CDTIMER);
				global->sound.cd.CDGStat = IDM_PAUSE;
				SendDlgItemMessage(hwndDlg, IDC_CD_PLAY, BM_SETCHECK, (WPARAM)(BST_CHECKED), (LPARAM)(0));
				SendDlgItemMessage(hwndDlg, IDC_CD_RW, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
				SendDlgItemMessage(hwndDlg, IDC_CD_FF, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
				SendDlgItemMessage(hwndDlg, IDC_CD_STOP, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
				SendDlgItemMessage(hwndDlg, IDC_CD_EJECT, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
				// PAUSE CD
				CDProc(global->sound.cd.CDGStat);
				}
			}
		else
			SendDlgItemMessage(hwndDlg, IDC_CD_PAUSE, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
		}
	else
		SendDlgItemMessage(hwndDlg, IDC_CD_PAUSE, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
}
			//////////////////////////////////////
			//  RW
			//////////////////////////////////////
void RewindCD(HWND hwndDlg)
{
	if(global->sound.cd.CDGStat != IDM_OPEN) 
		{
		if(global->sound.cd.CDGStat != IDM_TRACK)
			{
			UINT i = global->sound.cd.CDGStat;
			global->sound.cd.CDGStat = IDM_SEEK_RW;
			SendDlgItemMessage(hwndDlg, IDC_CD_FF, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
			SendDlgItemMessage(hwndDlg, IDC_CD_EJECT, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
			SendDlgItemMessage(hwndDlg, IDC_CD_RW, BM_SETCHECK, (WPARAM)(BST_CHECKED), (LPARAM)(0));
			// ReWind CD
			if(global->sound.cd.TArray >= 1)
				{
				global->sound.cd.TArray--;
				global->sound.cd.CTrack = global->sound.cd.TrackNumber[global->sound.cd.TArray];
				global->sound.cd.TMin		= 0;
				global->sound.cd.TSec		= 0;
				global->sound.cd.TFrm		= 0;
				}
			global->sound.cd.CDGStat = i;
			// Go back To CD Func. in use
			CDProc(global->sound.cd.CDGStat);
			char S[256];
			sprintf(S, " %u", global->sound.cd.CTrack);
			SetDlgItemText(hwndDlg, IDC_TRACK, S);
			// cont.
			SendDlgItemMessage(hwndDlg, IDC_CD_RW, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
			}
		else
			SendDlgItemMessage(hwndDlg, IDC_CD_RW, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
		}
	else
		SendDlgItemMessage(hwndDlg, IDC_CD_RW, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
}
			//////////////////////////////////////
			//  FF
			//////////////////////////////////////
void FastFCD(HWND hwndDlg)
{
	if(global->sound.cd.CDGStat != IDM_OPEN)
		{
		if(global->sound.cd.CDGStat != IDM_TRACK)
			{
			UINT testA = global->sound.cd.TArray;
			UINT testN = (global->sound.cd.nTrack - 1);
			UINT i = global->sound.cd.CDGStat;
			global->sound.cd.CDGStat = IDM_SEEK_FF;
			SendDlgItemMessage(hwndDlg, IDC_CD_RW, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
			SendDlgItemMessage(hwndDlg, IDC_CD_EJECT, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
			SendDlgItemMessage(hwndDlg, IDC_CD_FF, BM_SETCHECK, (WPARAM)(BST_CHECKED), (LPARAM)(0));
			// FastForward CD
			if(global->sound.cd.TArray < (global->sound.cd.nTrack - 1))
				{
				global->sound.cd.TArray++;
				global->sound.cd.CTrack = global->sound.cd.TrackNumber[global->sound.cd.TArray];
				global->sound.cd.TMin		= 0;
				global->sound.cd.TSec		= 0;
				global->sound.cd.TFrm		= 0;
				}
			// Go back To CD Func. in use
			global->sound.cd.CDGStat = i;
			CDProc(global->sound.cd.CDGStat);
			char S[256];
			sprintf(S, " %u", global->sound.cd.CTrack);
			SetDlgItemText(hwndDlg, IDC_TRACK, S);
			// cont.
			SendDlgItemMessage(hwndDlg, IDC_CD_FF, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
			}
		else
			SendDlgItemMessage(hwndDlg, IDC_CD_FF, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
		}
	else
		SendDlgItemMessage(hwndDlg, IDC_CD_FF, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
}
			//////////////////////////////////////
			//  STOP
			//////////////////////////////////////
void StopCD(HWND hwndDlg)
{
	if(global->sound.cd.CDGStat != IDM_OPEN)
		{
		if(global->sound.cd.CDGStat != IDM_TRACK)
			{
			global->sound.cd.TMin		= 0;
			global->sound.cd.TSec		= 0;
			global->sound.cd.TFrm		= 0;
			KillTimer(global->MainVar.ChildHwnd, IDT_CDTIMER);
			global->sound.cd.CDGStat = IDM_STOP;
			SendDlgItemMessage(hwndDlg, IDC_CD_STOP, BM_SETCHECK, (WPARAM)(BST_CHECKED), (LPARAM)(0));
			SendDlgItemMessage(hwndDlg, IDC_CD_PAUSE, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
			SendDlgItemMessage(hwndDlg, IDC_CD_RW, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
			SendDlgItemMessage(hwndDlg, IDC_CD_FF, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
			SendDlgItemMessage(hwndDlg, IDC_CD_PLAY, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
			SendDlgItemMessage(hwndDlg, IDC_CD_EJECT, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
			// STOP CD
			CDProc(global->sound.cd.CDGStat);
			}
		else 
			SendDlgItemMessage(hwndDlg, IDC_CD_STOP, BM_SETCHECK, (WPARAM)(BST_CHECKED), (LPARAM)(0));
		}
	else
		SendDlgItemMessage(hwndDlg, IDC_CD_STOP, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
}
			//////////////////////////////////////
			//  EJECT
			//////////////////////////////////////
void EjectCD(HWND hwndDlg)
{
	if(global->sound.cd.CDGStat != IDM_TRACK)
		{
		global->sound.cd.TArray = 0;
		global->sound.cd.TMin		= 0;
		global->sound.cd.TSec		= 0;
		global->sound.cd.TFrm		= 0;
		char S[256];
		sprintf(S, " %u", global->sound.cd.CTrack);
		SetDlgItemText(hwndDlg, IDC_TRACK, S);
		KillTimer(global->MainVar.ChildHwnd, IDT_CDTIMER);
		global->sound.cd.CDGStat = IDM_OPEN;
		SendDlgItemMessage(hwndDlg, IDC_CD_STOP, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
		SendDlgItemMessage(hwndDlg, IDC_CD_PAUSE, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
		SendDlgItemMessage(hwndDlg, IDC_CD_RW, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
		SendDlgItemMessage(hwndDlg, IDC_CD_FF, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
		SendDlgItemMessage(hwndDlg, IDC_CD_PLAY, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
		SendDlgItemMessage(hwndDlg, IDC_CD_EJECT, BM_SETCHECK, (WPARAM)(BST_CHECKED), (LPARAM)(0));
		// Eject CD
		CDProc(global->sound.cd.CDGStat);
		// After Eject CD
		// SetTimer(hwndDlg, IDT_CDTIMER, CDTIME, (TIMERPROC)CD_TimerProc);
		PlayList(hwndDlg, LOAD_CD);
		SendDlgItemMessage(hwndDlg, IDC_CD_EJECT, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
		global->sound.cd.CDGStat = IDM_STOP;
		CDProc(global->sound.cd.CDGStat);
		SendDlgItemMessage(hwndDlg, IDC_CD_STOP, BM_SETCHECK, (WPARAM)(BST_CHECKED), (LPARAM)(0));
		}
	else
		SendDlgItemMessage(hwndDlg, IDC_CD_EJECT, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
}
			//////////////////////////////////////
			//  Edit Play List Button
			//////////////////////////////////////
void EditPL(HWND hwndDlg)
{
	if(global->sound.cd.CDGStat != IDM_OPEN)
		{
		if(SendDlgItemMessage(hwndDlg, IDC_EDIT_PL, BM_GETCHECK, (WPARAM)(0), (LPARAM)(0)) == BST_CHECKED)
			{
			SendDlgItemMessage(hwndDlg, IDC_PLAYLIST, EM_SETREADONLY, (WPARAM)(FALSE), (LPARAM)(0));
			// Open
			global->sound.cd.CTrack = 1;
			global->sound.cd.TMin		= 0;
			global->sound.cd.TSec		= 0;
			global->sound.cd.TFrm		= 0;
			char S[256];
			sprintf(S, " %u", global->sound.cd.CTrack);
			SetDlgItemText(hwndDlg, IDC_TRACK, S);
			KillTimer(global->MainVar.ChildHwnd, IDT_CDTIMER);
			global->sound.cd.CDGStat = IDM_TRACK;
			SendDlgItemMessage(hwndDlg, IDC_CD_STOP, BM_SETCHECK, (WPARAM)(BST_CHECKED), (LPARAM)(0));
			SendDlgItemMessage(hwndDlg, IDC_CD_PAUSE, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
			SendDlgItemMessage(hwndDlg, IDC_CD_RW, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
			SendDlgItemMessage(hwndDlg, IDC_CD_FF, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
			SendDlgItemMessage(hwndDlg, IDC_CD_PLAY, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
			SendDlgItemMessage(hwndDlg, IDC_CD_EJECT, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
			}
		else
			{
			PlayList(hwndDlg, SAVE_CD);
			global->sound.cd.CDGStat = IDM_STOP;
			CDProc(global->sound.cd.CDGStat);
			SendDlgItemMessage(hwndDlg, IDC_PLAYLIST, EM_SETREADONLY, (WPARAM)(TRUE), (LPARAM)(0));
			}
		}
	else 
		SendDlgItemMessage(hwndDlg, IDC_EDIT_PL, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
}
			//////////////////////////////////////
			//  Shuffle Button
			//////////////////////////////////////
void Shuffle(HWND hwndDlg)
{
	char S[256];
	StopCD(hwndDlg);
	RandomList((int *)global->sound.cd.TrackNumber, global->sound.cd.nTrack, 0);
	PlayList(hwndDlg, LOAD_CD);
	global->sound.cd.CTrack	= global->sound.cd.TrackNumber[0];
	sprintf(S, " %u", global->sound.cd.CTrack);
	SetDlgItemText(hwndDlg, IDC_TRACK, S);
	SendDlgItemMessage(hwndDlg, IDC_SHUF, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
}
			//////////////////////////////////////
			//  Repeat Track Button
			//////////////////////////////////////
void RTrack(HWND hwndDlg)
{
	if(global->sound.cd.CDRStat == IDM_TRACK)
		{
		global->sound.cd.CDRStat = IDM_NULL;
		SendDlgItemMessage(hwndDlg, IDC_RTRACK, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
		SendDlgItemMessage(hwndDlg, IDC_RDISK, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
		}
	else 
		{
		global->sound.cd.CDRStat = IDM_TRACK;
		SendDlgItemMessage(hwndDlg, IDC_RTRACK, BM_SETCHECK, (WPARAM)(BST_CHECKED), (LPARAM)(0));
		SendDlgItemMessage(hwndDlg, IDC_RDISK, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
		}
}
			//////////////////////////////////////
			//  Repeat Disk Button
			//////////////////////////////////////
void RDisk(HWND hwndDlg)
{
	if(global->sound.cd.CDRStat == IDM_DISK)
		{
		global->sound.cd.CDRStat = IDM_NULL;
		SendDlgItemMessage(hwndDlg, IDC_RTRACK, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
		SendDlgItemMessage(hwndDlg, IDC_RDISK, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
		}
	else 
		{
		global->sound.cd.CDRStat = IDM_DISK;
		SendDlgItemMessage(hwndDlg, IDC_RTRACK, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
		SendDlgItemMessage(hwndDlg, IDC_RDISK, BM_SETCHECK, (WPARAM)(BST_CHECKED), (LPARAM)(0));
		}
}
			//////////////////////////////////////
			//  CD Timer Proc.
			//////////////////////////////////////
void CALLBACK CD_DlgTimerProc(HWND hwnd, UINT uMsg, UINT idEvent, DWORD dwTime)
{
	MCI_STATUS_PARMS MciStat;
	UINT Min = 0, Sec = 0;
	char S[256];

	memset(&MciStat, 0, sizeof(MCI_STATUS_PARMS));
	MciStat.dwCallback = 0;
	MciStat.dwItem		= MCI_STATUS_POSITION;
	MciStat.dwTrack		= 0;
	mciSendCommand(global->sound.cd.PlayCDId, MCI_STATUS, MCI_STATUS_ITEM , DWORD(&MciStat));
	Min = MCI_TMSF_MINUTE(MciStat.dwReturn);
	Sec = MCI_TMSF_SECOND(MciStat.dwReturn);
	sprintf(S, " %u : %02u", Min, Sec);
	SetDlgItemText(hwnd, IDC_TIME, S);
}
			//////////////////////////////////////
			//  CD Play List Func.
			//////////////////////////////////////
void PlayList(HWND hwndDlg, UINT msg)
{
	char S1[MAXARRAY];
	char S2[MAXARRAY];
	switch(msg)
		{
		case NEW_CD:
			{
			CDProc(START);
			if(global->sound.cd.TrackNumber[0] == 0)
				sprintf(S1, "%u", 0);
			else if(global->sound.cd.TrackNumber[0] == 1)
				sprintf(S1, "%u", 1);
			for(UINT i = 2; i < (global->sound.cd.nTrack +1); i++)
				{
				global->sound.cd.TrackNumber[i-1] = i;
				sprintf(S2, ",%u", i);
				strcat(S1, S2);
				}
			SetDlgItemText(hwndDlg, IDC_PLAYLIST, S1);
			} break;
		case LOAD_CD:
			{
			sprintf(S1, "%u", global->sound.cd.TrackNumber[0]);
			for(UINT i = 1; i < global->sound.cd.nTrack; i++)
				{
				sprintf(S2, ",%u", global->sound.cd.TrackNumber[i]);
				strcat(S1, S2);
				}
			SetDlgItemText(hwndDlg, IDC_PLAYLIST, S1);
			} break;
		case SAVE_CD:
			{
			GetDlgItemText(hwndDlg, IDC_PLAYLIST, S1, MAXARRAY);
			if(strcmp(S1, "") == 0)
				{
				CDProc(IDM_TRACK);
				for(UINT i = 0; i < global->sound.cd.nTrack; i++)
					{
					global->sound.cd.TrackNumber[i] = i+1;
					}
				char S[256];
				global->sound.cd.CTrack = global->sound.cd.TrackNumber[0];
				sprintf(S, " %u", global->sound.cd.CTrack);
				SetDlgItemText(hwndDlg, IDC_TRACK, S);
				PlayList(hwndDlg, LOAD_CD);
				}
			else
				{
				char *Str;
				Str = (char *)malloc(sizeof(char));
				strcpy(Str, "1234");
				GetDlgItemText(hwndDlg, IDC_PLAYLIST, S1, MAXARRAY);
				for(UINT i = 0; strcmp(Str, "") != 0 ; i++)
					{
					global->sound.cd.TrackNumber[i] = (UINT)strtod(S1, &Str);
					strcpy(S1, Str + 1);
					}
				global->sound.cd.TrackNumber[i] = (UINT)strtod(S1, NULL);
				global->sound.cd.nTrack = i + 1;
				}
			global->sound.cd.CTrack = global->sound.cd.TrackNumber[0];
			char S[256];
			sprintf(S, " %u", global->sound.cd.CTrack);
			SetDlgItemText(hwndDlg, IDC_TRACK, S);
			} break;
		}
}
			//////////////////////////////////////
			// CD Proc.
			//////////////////////////////////////
void CDProc(UINT msg)
{
	switch(msg)
		{
		case START:
			{
			if(!global->sound.cd.MciError)
				{
				BoxReturn = 0;
				MCI_OPEN_PARMS Open;
				memset(&Open, 0, sizeof(MCI_OPEN_PARMS));
				Open.lpstrDeviceType = (LPSTR)MCI_DEVTYPE_CD_AUDIO;
				Open.lpstrAlias = "Alien Mansion CD-ROM Drive";
				DWORD style = MCI_OPEN_TYPE | MCI_OPEN_TYPE_ID | MCI_OPEN_ALIAS | MCI_OPEN_SHAREABLE ;
				global->sound.cd.MciError = mciSendCommand(0, MCI_OPEN, style, DWORD(&Open));
				global->sound.cd.PlayCDId = Open.wDeviceID;
				if(!global->sound.cd.MciError)
					{
					MCI_SET_PARMS InfoSet;
					memset(&InfoSet, 0, sizeof(MCI_SET_PARMS));
					InfoSet.dwTimeFormat	= MCI_FORMAT_TMSF;
					global->sound.cd.MciError = mciSendCommand(global->sound.cd.PlayCDId, MCI_SET, MCI_SET_TIME_FORMAT, DWORD(&InfoSet));

					MCI_STATUS_PARMS MciStat;
					if(!global->sound.cd.MciError)
						{
						memset(&MciStat, 0, sizeof(MCI_STATUS_PARMS));
						MciStat.dwCallback = 0;
						MciStat.dwItem		= MCI_STATUS_NUMBER_OF_TRACKS;
						MciStat.dwTrack		= 0;
						global->sound.cd.MciError = mciSendCommand(global->sound.cd.PlayCDId, MCI_STATUS, MCI_STATUS_ITEM , DWORD(&MciStat));
						}
					if(global->sound.cd.MciError)
						{
						global->sound.cd.nTrack = 0;
						global->sound.cd.TrackNumber[0] = 0;
						}
					else
						{
						global->sound.cd.nTrack = MciStat.dwReturn;
						global->sound.cd.TrackNumber[0] = 1;
						}
					}
				}
			} break;
		case IDM_TRACK:
			{
			if(!global->sound.cd.MciError)
				{
				MCI_STATUS_PARMS MciStat;
				memset(&MciStat, 0, sizeof(MCI_STATUS_PARMS));
				MciStat.dwCallback = 0;
				MciStat.dwItem		= MCI_STATUS_NUMBER_OF_TRACKS;
				MciStat.dwTrack		= 0;
				global->sound.cd.MciError = mciSendCommand(global->sound.cd.PlayCDId, MCI_STATUS, MCI_STATUS_ITEM , DWORD(&MciStat));
				global->sound.cd.nTrack = MciStat.dwReturn;
				global->sound.cd.TrackNumber[0] = 1;
				}
			} break;
		case IDM_PLAY:
			{
			if(!global->sound.cd.MciError)
				{
				KillTimer(global->MainVar.ChildHwnd, IDT_CDTRACK);

				UINT TrackLength = 0;
				MCI_STATUS_PARMS MciStat;
				memset(&MciStat, 0, sizeof(MCI_STATUS_PARMS));
				MciStat.dwCallback = 0;
				MciStat.dwItem		= MCI_STATUS_LENGTH;
				MciStat.dwTrack		= global->sound.cd.TrackNumber[global->sound.cd.TArray];
				global->sound.cd.MciError = mciSendCommand(global->sound.cd.PlayCDId, MCI_STATUS, MCI_STATUS_ITEM | MCI_TRACK, DWORD(&MciStat));
				TrackLength = 60000*(MCI_MSF_MINUTE(MciStat.dwReturn)) + 1000*(MCI_MSF_SECOND(MciStat.dwReturn)) + (int)((50/3)*((double)MCI_MSF_FRAME(MciStat.dwReturn))) 
					- (60000*(global->sound.cd.TMin) + 1000*(global->sound.cd.TSec) + (int)( (50/3)*( (double)global->sound.cd.TFrm ) ));
				SetTimer(global->MainVar.ChildHwnd, IDT_CDTRACK, TrackLength, (TIMERPROC)CDTimerProc);

				if(!global->sound.cd.MciError)
					{
					MCI_PLAY_PARMS InfoPlay;
					memset(&InfoPlay, 0, sizeof(MCI_PLAY_PARMS));
					InfoPlay.dwFrom	= MCI_MAKE_TMSF(
						global->sound.cd.TrackNumber[global->sound.cd.TArray], 
						global->sound.cd.TMin, 
						global->sound.cd.TSec, 
						global->sound.cd.TFrm);
					global->sound.cd.MciError = mciSendCommand(global->sound.cd.PlayCDId, MCI_PLAY, MCI_FROM | MCI_NOTIFY, DWORD(&InfoPlay));
					}
				}
			} break;
		case IDM_CLOSE:
			{
			if(!global->sound.cd.MciError)
				{
				global->sound.cd.MciError = mciSendCommand(global->sound.cd.PlayCDId, MCI_CLOSE, 0, 0);
				}
			} break;
		case IDM_STOP:
			{
			if(!global->sound.cd.MciError)
				{
				global->sound.cd.TMin		= 0;
				global->sound.cd.TSec		= 0;
				global->sound.cd.TFrm		= 0;
				CDProc(IDM_PLAY);

				MCI_GENERIC_PARMS GenInfo;
				memset(&GenInfo, 0, sizeof(MCI_GENERIC_PARMS));
				GenInfo.dwCallback = 0;
				global->sound.cd.MciError = mciSendCommand(global->sound.cd.PlayCDId, MCI_STOP, MCI_NOTIFY, DWORD(&GenInfo));
				}
			}	break;
		case ((IDM_SEEK_FF) || (IDM_SEEK_RW)):
			{
			if(!global->sound.cd.MciError)
				{
				MCI_SEEK_PARMS InfoSeek;
				memset(&InfoSeek, 0, sizeof(MCI_SEEK_PARMS));
				InfoSeek.dwTo	= MCI_MAKE_TMSF(
					global->sound.cd.TrackNumber[global->sound.cd.TArray],
					global->sound.cd.TMin,
					global->sound.cd.TSec,
					global->sound.cd.TFrm);
				global->sound.cd.MciError = mciSendCommand(global->sound.cd.PlayCDId, MCI_SEEK, MCI_TO, DWORD(&InfoSeek));
				}
			} break;
		case IDM_PAUSE:
			{
			if(!global->sound.cd.MciError)
				{
				KillTimer(global->MainVar.ChildHwnd, IDT_CDTRACK);
				MCI_GENERIC_PARMS GenInfo;
				memset(&GenInfo, 0, sizeof(MCI_GENERIC_PARMS));
				global->sound.cd.MciError = mciSendCommand(global->sound.cd.PlayCDId, MCI_PAUSE, 0, DWORD(&GenInfo));

				if(!global->sound.cd.MciError)
					{
					MCI_STATUS_PARMS MciStat;
					memset(&MciStat, 0, sizeof(MCI_STATUS_PARMS));
					MciStat.dwCallback = 0;
					MciStat.dwItem		= MCI_STATUS_POSITION;
					MciStat.dwTrack		= 0;
					global->sound.cd.MciError = mciSendCommand(global->sound.cd.PlayCDId, MCI_STATUS, MCI_STATUS_ITEM , DWORD(&MciStat));
					global->sound.cd.TMin = MCI_TMSF_MINUTE(MciStat.dwReturn);
					global->sound.cd.TSec = MCI_TMSF_SECOND(MciStat.dwReturn);
					global->sound.cd.TFrm = MCI_TMSF_FRAME(MciStat.dwReturn);
					}
				}
			} break;
		case IDM_OPEN:
			{
			if(!global->sound.cd.MciError)
				{
				MCI_STATUS_PARMS MciStat;
				memset(&MciStat, 0, sizeof(MCI_STATUS_PARMS));
				MciStat.dwReturn = 0;
				global->sound.cd.MciError = mciSendCommand(global->sound.cd.PlayCDId, MCI_SET, MCI_SET_DOOR_OPEN, DWORD(NULL));
				
				if(!global->sound.cd.MciError)
					{
					while(MciStat.dwReturn == 0)
						{
						MCI_STATUS_PARMS MciStat;
						memset(&MciStat, 0, sizeof(MCI_STATUS_PARMS));
						MciStat.dwCallback = 0;
						MciStat.dwItem		= MCI_STATUS_NUMBER_OF_TRACKS;
						MciStat.dwTrack		= 0;
						global->sound.cd.MciError = mciSendCommand(global->sound.cd.PlayCDId, MCI_STATUS, MCI_STATUS_ITEM , DWORD(&MciStat));
						}
					global->sound.cd.CDGStat = IDM_CLOSE;
		
					if(!global->sound.cd.MciError)
						{
						MciStat.dwCallback = 0;
						MciStat.dwItem		= MCI_STATUS_NUMBER_OF_TRACKS;
						MciStat.dwTrack		= 0;
						global->sound.cd.MciError = mciSendCommand(global->sound.cd.PlayCDId, MCI_STATUS, MCI_STATUS_ITEM , DWORD(&MciStat));
						if(global->sound.cd.MciError)
							{
							global->sound.cd.nTrack = 0;
							global->sound.cd.TrackNumber[0] = 0;
							}
						else
							{
							global->sound.cd.nTrack = MciStat.dwReturn;
							global->sound.cd.TrackNumber[0] = 1;
							}
						}
					}
				}
			} break;
		}
mciGetErrorString(global->sound.cd.MciError, global->sound.cd.error, MAXARRAY*sizeof(global->sound.cd.error));
if((global->sound.cd.MciError != 0) && (BoxReturn == 0))
	{
	BoxReturn = -1;
	BoxReturn = MessageBox(global->MainVar.ChildHwnd, global->sound.cd.error, "Midi Error", MB_ABORTRETRYIGNORE | MB_ICONERROR);
	if(BoxReturn == IDABORT)
		{
		BoxReturn = 0;
		global->LevelVar.Redraw = TRUE;
		EndDialog(global->MainVar.OptionsHwnd, 0);
		SetFocus(global->MainVar.ControlsHwnd);
		}
	else if(BoxReturn == IDRETRY)
		{
		BoxReturn = 0;
		CDProc(START);
		}
	else if(BoxReturn == IDCANCEL)
		{
		BoxReturn = -1;
		}
	}
}
			//////////////////////////////////////
			// CD Timer Proc.
			//////////////////////////////////////
void CALLBACK CDTimerProc(HWND hwnd, UINT uMsg, UINT idEvent, DWORD dwTime)
{
	if(global->sound.cd.CDRStat != IDM_TRACK)
		{
		global->sound.cd.TArray++;
		if(global->sound.cd.TArray != (global->sound.cd.TrackNumber[global->sound.cd.TArray-1]+1))
			{
			if(global->sound.cd.TArray <= (global->sound.cd.nTrack-1))
				{
				char S[256];
				global->sound.cd.TMin		= 0;
				global->sound.cd.TSec		= 0;
				global->sound.cd.TFrm		= 0;
				global->sound.cd.CTrack = global->sound.cd.TrackNumber[global->sound.cd.TArray];
				sprintf(S, " %u", global->sound.cd.CTrack);
				SetDlgItemText(hwnd, IDC_TRACK, S);
				CDProc(IDM_PLAY);
				}
			}
		else
			{
			char S[256];
			UINT TrackLength = 0;
			MCI_STATUS_PARMS MciStat;
			memset(&MciStat, 0, sizeof(MCI_STATUS_PARMS));
			MciStat.dwCallback = 0;
			MciStat.dwItem		= MCI_STATUS_LENGTH;
			MciStat.dwTrack		= global->sound.cd.TrackNumber[global->sound.cd.TArray];
			mciSendCommand(global->sound.cd.PlayCDId, MCI_STATUS, MCI_STATUS_ITEM | MCI_TRACK, DWORD(&MciStat));
			TrackLength = 60000*(MCI_MSF_MINUTE(MciStat.dwReturn)) + 1000*(MCI_MSF_SECOND(MciStat.dwReturn)) + (int)((50/3)*((double)MCI_MSF_FRAME(MciStat.dwReturn)));
			SetTimer(global->MainVar.ChildHwnd, IDT_CDTRACK, TrackLength, (TIMERPROC)CDTimerProc);
			global->sound.cd.TMin		= 0;
			global->sound.cd.TSec		= 0;
			global->sound.cd.TFrm		= 0;
			global->sound.cd.CTrack = global->sound.cd.TrackNumber[global->sound.cd.TArray];
			sprintf(S, " %u", global->sound.cd.CTrack);
			SetDlgItemText(hwnd, IDC_TRACK, S);
			CDProc(IDM_PLAY);
			}
		}
	else if(global->sound.cd.CDRStat == IDM_TRACK)
		{
		char S[256];
		global->sound.cd.TMin		= 0;
		global->sound.cd.TSec		= 0;
		global->sound.cd.TFrm		= 0;
		global->sound.cd.CTrack = global->sound.cd.TrackNumber[global->sound.cd.TArray];
		sprintf(S, " %u", global->sound.cd.CTrack);
		SetDlgItemText(hwnd, IDC_TRACK, S);
		CDProc(IDM_PLAY);
		}

	if((global->sound.cd.TArray > (global->sound.cd.nTrack-1)) && (global->sound.cd.CDRStat == IDM_DISK))
		{
		char S[256];
		global->sound.cd.TMin		= 0;
		global->sound.cd.TSec		= 0;
		global->sound.cd.TFrm		= 0;
		global->sound.cd.TArray = 0;
		global->sound.cd.CTrack = global->sound.cd.TrackNumber[global->sound.cd.TArray];
		sprintf(S, " %u", global->sound.cd.CTrack);
		SetDlgItemText(hwnd, IDC_TRACK, S);
		CDProc(IDM_PLAY);
		}
	else if((global->sound.cd.TArray > (global->sound.cd.nTrack-1)) && (global->sound.cd.CDRStat != IDM_DISK))
		CDProc(IDM_STOP);
}