////////////////////////////////////////////////////////////////////////
//	Program Name:	DialogUtils.cpp
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
#include "DialogUtils.h"

//////////////////////////////////////////////////
// 							Procedure Functions							//
//////////////////////////////////////////////////
			//////////////////////////////////////
			// ControlBar Dialog Box Procedure
			//////////////////////////////////////
BOOL CALLBACK ControlBar_DialogProc(HWNDdll hwndDlg, UINT Message, 
																						 WPARAM wParam, LPARAM lParam)
{
global->MainVar.ControlsHwnd = hwndDlg;
LPMSG lpMsg = (LPMSG)malloc(sizeof(MSG));
lpMsg->hwnd = hwndDlg;
lpMsg->message = Message;
lpMsg->wParam = wParam;
lpMsg->lParam = lParam;
TranslateAccelerator(hwndDlg, global->MainVar.hAccControls, lpMsg);
	switch(Message)
	{
	  case WM_COMMAND:
			{
			ControlBar_OnCommand(hwndDlg, (int)(LOWORD(wParam)));
			return TRUE;
			}	break;
		case WM_INITDIALOG:
			{
			global->MainVar.hAccControls = LoadAccelerators(global->MainVar.MainhInst, MAKEINTRESOURCE(IDR_CONTROLS));
			HICON hicon;
			int j;
			InitCommonControls(); 
			SendDlgItemMessage(hwndDlg, IDC_ITEMLIST, LVM_DELETEALLITEMS, (WPARAM)(0), (LPARAM)(0));
// Create,fill and asign image list
			himl = ImageList_Create(CX_ICON, CY_ICON, ILC_COLOR16, MAXICON, MAXICON);
		for(j = STARTITEM - 1; j <= ENDITEM; j++)
			{
			hicon = LoadIcon(global->MainVar.MainhInst, MAKEINTRESOURCE(j));
			ImageList_AddIcon(himl, hicon);
			}
			SendDlgItemMessage(hwndDlg, IDC_ITEMLIST, LVM_SETIMAGELIST, (WPARAM)(LVSIL_NORMAL), (LPARAM)(HIMAGELIST)(himl));
// clear text bar
			SendDlgItemMessage(hwndDlg, IDC_TEXTBAR, WM_SETTEXT, (WPARAM)(0), (LPARAM)(LPCTSTR)(""));

			strcpy(item1, "");
			strcpy(item2, "");

			RECT Rect;
			RECT r;
			GetWindowRect(GetDesktopWindow(), &Rect);
			GetWindowRect(hwndDlg, &r);
			int ScreenW = (int)(Rect.right*(0.50) - XMAX*(0.50)),
					ScreenH	= (int)(Rect.bottom*(0.50) + YMAX*(0.50));

			SetWindowPos(hwndDlg, NULL, ScreenW, (int)(ScreenH - (r.bottom - r.top)), 0, 0, SWP_NOSIZE);

			SetFocus(global->MainVar.ChildHwnd);
			global->LevelVar.Redraw = TRUE;
			return TRUE;
			}	break;
		case WM_NOTIFY:
			{
				ControlBar_OnNotify(hwndDlg, (int) wParam, (LPNMHDR) lParam);
				return 0;
			}	break;
    default:
      return FALSE;
	}
}
			//////////////////////////////////////
			// Loadfile Dialog Box Procedure
			//////////////////////////////////////
BOOL CALLBACK Loadfile_DialogProc(HWNDdll hwndDlg, UINT Message, 
																					 WPARAM wParam, LPARAM lParam)
{
LPMSG lpMsg = (LPMSG)malloc(sizeof(MSG));
lpMsg->hwnd = hwndDlg;
lpMsg->message = Message;
lpMsg->wParam = wParam;
lpMsg->lParam = lParam;
TranslateAccelerator(hwndDlg, global->MainVar.hAccFileUtil, lpMsg);
	switch(Message)
		{
		case WM_COMMAND:
			{
			Load_OnCommand(hwndDlg, (UINT)(LOWORD(wParam)));
			return TRUE;
			} break;
		case WM_INITDIALOG:
			{
			global->MainVar.hAccFileUtil = LoadAccelerators(global->MainVar.MainhInst, MAKEINTRESOURCE(IDR_FILEUTILS));

			FILE *fp;
			if( (fp = fopen(SAVEFILE, "r+")) == NULL)
				{
				NewGameFile(SAVEFILE);
				fp = fopen(SAVEFILE, "r");
				}
			fread(&GameInfo, sizeof(GameInfo), 1, fp);
			fclose(fp);

			for (int j = 0; j < MAXSAVE; j++)
				{
				if(GameInfo[j].game.item[0] != (-1))
					SendDlgItemMessage(hwndDlg, IDC_LIST, LB_ADDSTRING, 0, (LPARAM)(LPCTSTR)(GameInfo[j].game.name));
				}
				SendDlgItemMessage(hwndDlg, IDC_LIST, LB_SELECTSTRING, (WPARAM)(-1), (LPARAM)(LPCTSTR)(GameInfo[0].game.name)); 
			return TRUE;
			}	break;
		}
	return FALSE;
}
			//////////////////////////////////////
			// Savefile Dialog Box Procedure
			//////////////////////////////////////
BOOL CALLBACK Savefile_DialogProc(HWNDdll hwndDlg, UINT Message, 
																					 WPARAM wParam, LPARAM lParam)
{
LPMSG lpMsg = (LPMSG)malloc(sizeof(MSG));
lpMsg->hwnd = hwndDlg;
lpMsg->message = Message;
lpMsg->wParam = wParam;
lpMsg->lParam = lParam;
TranslateAccelerator(hwndDlg, global->MainVar.hAccFileUtil, lpMsg);
	switch(Message)
		{
		case WM_COMMAND:
			{
			Save_OnCommand(hwndDlg, (UINT)(LOWORD(wParam)));
			return TRUE;
			} break;
		case WM_INITDIALOG:
			{
			global->MainVar.hAccFileUtil = LoadAccelerators(global->MainVar.MainhInst, MAKEINTRESOURCE(IDR_FILEUTILS));
			SetDlgItemText(hwndDlg, IDC_NAME, game->name);
			return TRUE;
			}	break;
		}
	return FALSE;
}
			//////////////////////////////////////
			// Text Dialog Box Procedure
			//////////////////////////////////////
BOOL CALLBACK Text_DialogProc(HWNDdll hwndDlg, UINT Message, 
															WPARAM wParam, LPARAM lParam)
{
global->MainVar.TextHwnd = hwndDlg;
LPMSG lpMsg = (LPMSG)malloc(sizeof(MSG));
lpMsg->hwnd = hwndDlg;
lpMsg->message = Message;
lpMsg->wParam = wParam;
lpMsg->lParam = lParam;
TranslateAccelerator(hwndDlg, global->MainVar.hAccControls, lpMsg);
	switch(Message)
		{
		case WM_COMMAND:
			{
			ControlBar_OnCommand(hwndDlg, (UINT)(LOWORD(wParam)));
			return TRUE;
			} break;
		case WM_INITDIALOG:
			{
			RECT Rect;
			GetWindowRect(GetDesktopWindow(), &Rect);
			int		ScreenW = (int)((Rect.right)*(0.50) - XMAX*(0.50)),
						ScreenH	= (int)((Rect.bottom)*(0.50) - YMAX*(0.50));
 
			SetWindowPos(hwndDlg, NULL, ScreenW, ScreenH, 0, 0, SWP_NOSIZE);

			SetFocus(global->MainVar.ChildHwnd);
				return TRUE;
			}	break;
		}
	return FALSE;
}
			//////////////////////////////////////
			// Options Dialog Box Procedure
			//////////////////////////////////////
BOOL CALLBACK Options_DialogProc(HWNDdll hwndDlg, UINT Message, 
																						 WPARAM wParam, LPARAM lParam)
{
LPMSG lpMsg = (LPMSG)malloc(sizeof(MSG));
lpMsg->hwnd = hwndDlg;
lpMsg->message = Message;
lpMsg->wParam = wParam;
lpMsg->lParam = lParam;
TranslateAccelerator(hwndDlg, global->MainVar.hAccOptions, lpMsg);
	switch(Message)
	{
	  case WM_COMMAND:
			{
			Options_OnCommand(hwndDlg, (UINT)(LOWORD(wParam)));
			return TRUE;
			}	break;
		case WM_INITDIALOG:
			{
			global->MainVar.hAccOptions = LoadAccelerators(global->MainVar.MainhInst, MAKEINTRESOURCE(IDR_OPTIONS));
			global->MainVar.OptionsHwnd = hwndDlg;
			TabIndex = 0;
			TC_ITEM FAR *item = (TC_ITEM FAR *)malloc(sizeof(TC_ITEM));
			item->mask = TCIF_TEXT;
			item->pszText = "General";
			item->cchTextMax = sizeof(item->pszText);
			SendDlgItemMessage(hwndDlg, IDC_TABBAR, TCM_INSERTITEM, (WPARAM)(ID_GENERAL), (LPARAM)(const TC_ITEM FAR*)(item) );
			item->mask = TCIF_TEXT;
			item->pszText = "Load/Save";
			item->cchTextMax = sizeof(item->pszText);
			SendDlgItemMessage(hwndDlg, IDC_TABBAR, TCM_INSERTITEM, (WPARAM)(ID_LOADSAVE), (LPARAM)(const TC_ITEM FAR*)(item) );
			if(global->sound.cd.CDGStat != IDM_NULL)
				{
				item->mask = TCIF_TEXT;
				item->pszText = "CD Player";
				item->cchTextMax = sizeof(item->pszText);
				SendDlgItemMessage(hwndDlg, IDC_TABBAR, TCM_INSERTITEM, (WPARAM)(ID_CDPLAYER), (LPARAM)(const TC_ITEM FAR*)(item) );
				}
// General TAB
			ShowItem(hwndDlg, IDHELPTXT,		SWP_SHOWWINDOW);
			ShowItem(hwndDlg, IDEXIT,				SWP_SHOWWINDOW);
			ShowItem(hwndDlg, IDMIDISND,		SWP_SHOWWINDOW);
			ShowItem(hwndDlg, IDWAVSND,			SWP_SHOWWINDOW);
			ShowItem(hwndDlg, IDCDSND,			SWP_SHOWWINDOW);
// Load/Save TAB
			ShowItem(hwndDlg, IDLOAD,				SWP_HIDEWINDOW);
			ShowItem(hwndDlg, IDSAVE,				SWP_HIDEWINDOW);
// CD Player TAB
			ShowItem(hwndDlg, IDC_EDIT_PL,	SWP_HIDEWINDOW);
			ShowItem(hwndDlg, IDC_SHUF,			SWP_HIDEWINDOW);
			ShowItem(hwndDlg, IDC_PLAYLIST,	SWP_HIDEWINDOW);
			ShowItem(hwndDlg, IDC_RTRACK,		SWP_HIDEWINDOW);
			ShowItem(hwndDlg, IDC_RDISK,		SWP_HIDEWINDOW);
			ShowItem(hwndDlg, IDC_S_TRACK,	SWP_HIDEWINDOW);
			ShowItem(hwndDlg, IDC_S_TIME,		SWP_HIDEWINDOW);
			ShowItem(hwndDlg, IDC_TRACK,		SWP_HIDEWINDOW);
			ShowItem(hwndDlg, IDC_TIME,			SWP_HIDEWINDOW);
			ShowItem(hwndDlg, IDC_CD_RW,		SWP_HIDEWINDOW);
			ShowItem(hwndDlg, IDC_CD_PLAY,	SWP_HIDEWINDOW);
			ShowItem(hwndDlg, IDC_CD_FF,		SWP_HIDEWINDOW);
			ShowItem(hwndDlg, IDC_CD_PAUSE,	SWP_HIDEWINDOW);
			ShowItem(hwndDlg, IDC_CD_STOP,	SWP_HIDEWINDOW);
			ShowItem(hwndDlg, IDC_CD_EJECT,	SWP_HIDEWINDOW);
// MIDI Check box
			if(global->sound.midi.MidiStat == IDM_PLAY)
				SendDlgItemMessage(hwndDlg, IDMIDISND, BM_SETCHECK, (WPARAM)(BST_CHECKED), (LPARAM)(0));
			else 
				SendDlgItemMessage(hwndDlg, IDMIDISND, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
// WAV Check box
			if(global->sound.wav.WavStat == IDM_PLAY)
				SendDlgItemMessage(hwndDlg, IDWAVSND, BM_SETCHECK, (WPARAM)(BST_CHECKED), (LPARAM)(0));
			else 
				SendDlgItemMessage(hwndDlg, IDWAVSND, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
///////////////////////////////
// CD Check box
///////////////////////////////
			if(global->sound.cd.CDGStat != IDM_NULL)
				{
				SendDlgItemMessage(hwndDlg, IDCDSND, BM_SETCHECK, (WPARAM)(BST_CHECKED), (LPARAM)(0));
			// Edit Controls
				SendDlgItemMessage(hwndDlg, IDC_EDIT_PL, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));
				SendDlgItemMessage(hwndDlg, IDC_PLAYLIST, EM_SETREADONLY, (WPARAM)(TRUE), (LPARAM)(0));
//				PlayList(hwndDlg, LOAD);
				}
			else 
				SendDlgItemMessage(hwndDlg, IDCDSND, BM_SETCHECK, (WPARAM)(BST_UNCHECKED), (LPARAM)(0));

			global->MainVar.LoadFile = FALSE;
			return TRUE;
			} break;
		case WM_NOTIFY:
			{
			TabIndex = SendDlgItemMessage(hwndDlg, IDC_TABBAR, TCM_GETCURSEL, (WPARAM)(0), (LPARAM)(0));
			if(TabIndex == ID_GENERAL)
				{
				
				KillTimer(hwndDlg, IDT_CDPLAYER);
			// General TAB
				ShowItem(hwndDlg, IDHELPTXT,		SWP_SHOWWINDOW);	
				ShowItem(hwndDlg, IDEXIT,				SWP_SHOWWINDOW);
				ShowItem(hwndDlg, IDMIDISND,		SWP_SHOWWINDOW);
				ShowItem(hwndDlg, IDWAVSND,			SWP_SHOWWINDOW);
				ShowItem(hwndDlg, IDCDSND,			SWP_SHOWWINDOW);
			// Load/Save TAB
				ShowItem(hwndDlg, IDLOAD,				SWP_HIDEWINDOW);
				ShowItem(hwndDlg, IDSAVE,				SWP_HIDEWINDOW);
			// CD Player TAB
				ShowItem(hwndDlg, IDC_EDIT_PL,	SWP_HIDEWINDOW);
				ShowItem(hwndDlg, IDC_SHUF,			SWP_HIDEWINDOW);
				ShowItem(hwndDlg, IDC_PLAYLIST,	SWP_HIDEWINDOW);
				ShowItem(hwndDlg, IDC_RTRACK,		SWP_HIDEWINDOW);
				ShowItem(hwndDlg, IDC_RDISK,		SWP_HIDEWINDOW);
				ShowItem(hwndDlg, IDC_S_TRACK,	SWP_HIDEWINDOW);
				ShowItem(hwndDlg, IDC_S_TIME,		SWP_HIDEWINDOW);
				ShowItem(hwndDlg, IDC_TRACK,		SWP_HIDEWINDOW);
				ShowItem(hwndDlg, IDC_TIME,			SWP_HIDEWINDOW);
				ShowItem(hwndDlg, IDC_CD_RW,		SWP_HIDEWINDOW);
				ShowItem(hwndDlg, IDC_CD_PLAY,	SWP_HIDEWINDOW);
				ShowItem(hwndDlg, IDC_CD_FF,		SWP_HIDEWINDOW);
				ShowItem(hwndDlg, IDC_CD_PAUSE,	SWP_HIDEWINDOW);
				ShowItem(hwndDlg, IDC_CD_STOP,	SWP_HIDEWINDOW);
				ShowItem(hwndDlg, IDC_CD_EJECT,	SWP_HIDEWINDOW);
				}			
			else if(TabIndex == ID_LOADSAVE)
				{
				KillTimer(hwndDlg, IDT_CDPLAYER);
			// General TAB
				ShowItem(hwndDlg, IDHELPTXT,		SWP_HIDEWINDOW);
				ShowItem(hwndDlg, IDEXIT,				SWP_HIDEWINDOW);
				ShowItem(hwndDlg, IDMIDISND,		SWP_HIDEWINDOW);
				ShowItem(hwndDlg, IDWAVSND,			SWP_HIDEWINDOW);
				ShowItem(hwndDlg, IDCDSND,			SWP_HIDEWINDOW);
			// Load/Save TAB
				ShowItem(hwndDlg, IDLOAD,				SWP_SHOWWINDOW);
				ShowItem(hwndDlg, IDSAVE,				SWP_SHOWWINDOW);
			// CD Player TAB
				ShowItem(hwndDlg, IDC_EDIT_PL,	SWP_HIDEWINDOW);
				ShowItem(hwndDlg, IDC_SHUF,			SWP_HIDEWINDOW);
				ShowItem(hwndDlg, IDC_PLAYLIST,	SWP_HIDEWINDOW);
				ShowItem(hwndDlg, IDC_RTRACK,		SWP_HIDEWINDOW);
				ShowItem(hwndDlg, IDC_RDISK,		SWP_HIDEWINDOW);
				ShowItem(hwndDlg, IDC_S_TRACK,	SWP_HIDEWINDOW);
				ShowItem(hwndDlg, IDC_S_TIME,		SWP_HIDEWINDOW);
				ShowItem(hwndDlg, IDC_TRACK,		SWP_HIDEWINDOW);
				ShowItem(hwndDlg, IDC_TIME,			SWP_HIDEWINDOW);
				ShowItem(hwndDlg, IDC_CD_RW,		SWP_HIDEWINDOW);
				ShowItem(hwndDlg, IDC_CD_PLAY,	SWP_HIDEWINDOW);
				ShowItem(hwndDlg, IDC_CD_FF,		SWP_HIDEWINDOW);
				ShowItem(hwndDlg, IDC_CD_PAUSE,	SWP_HIDEWINDOW);
				ShowItem(hwndDlg, IDC_CD_STOP,	SWP_HIDEWINDOW);
				ShowItem(hwndDlg, IDC_CD_EJECT,	SWP_HIDEWINDOW);
				}
			else if(TabIndex == ID_CDPLAYER)
				{
				TabCD(hwndDlg);
				}
			} break;
	}
	return FALSE;
}
//////////////////////////////////////////////////
// 							Message Functions								//
//////////////////////////////////////////////////
			//////////////////////////////////////
			// Handles ControlBar WM_COMMAND messages
			//////////////////////////////////////
void ControlBar_OnCommand(HWND hwndDlg, int id)
{
controlstat = id;
strcpy(item1 , "");
strcpy(item2 , "");
switch(id)
	{
	case IDUSE:
		{
		SendDlgItemMessage(hwndDlg, IDC_TEXTBAR, WM_SETTEXT, (WPARAM)(0), (LPARAM)(LPCTSTR)(strcpy(textbox, USE)));
		}	break;
	case IDEXAMINE:
		{
		SendDlgItemMessage(hwndDlg, IDC_TEXTBAR, WM_SETTEXT, (WPARAM)(0), (LPARAM)(LPCTSTR)(strcpy(textbox, EXAMINE)));
		}	break;
	case IDCLEAR:
		{
		SendDlgItemMessage(hwndDlg, IDC_TEXTBAR, WM_SETTEXT, (WPARAM)(0), (LPARAM)(LPCTSTR)(strcpy(textbox, "")));
		strcpy(item1 , "");
		strcpy(item2 , "");
		strcpy(global->LevelVar.ScreenItem , "");
		}	break;
	case IDTALK:
		{
		SendDlgItemMessage(hwndDlg, IDC_TEXTBAR, WM_SETTEXT, (WPARAM)(0), (LPARAM)(LPCTSTR)(strcpy(textbox, TALK)));
		}	break;
	case IDOPEN:
		{
		SendDlgItemMessage(hwndDlg, IDC_TEXTBAR, WM_SETTEXT, (WPARAM)(0), (LPARAM)(LPCTSTR)(strcpy(textbox, OPEN)));
		}	break;
	case IDBCLOSE:
		{
		SendDlgItemMessage(hwndDlg, IDC_TEXTBAR, WM_SETTEXT, (WPARAM)(0), (LPARAM)(LPCTSTR)(strcpy(textbox, CLOSE)));
		}	break;
	case IDGET:
		{
		SendDlgItemMessage(hwndDlg, IDC_TEXTBAR, WM_SETTEXT, (WPARAM)(0), (LPARAM)(LPCTSTR)(strcpy(textbox, GET)));
		}	break;
	case IDGIVE:
		{
		SendDlgItemMessage(hwndDlg, IDC_TEXTBAR, WM_SETTEXT, (WPARAM)(0), (LPARAM)(LPCTSTR)(strcpy(textbox, GIVE)));
		}	break;
	case IDPUSHPULL:
		{
		SendDlgItemMessage(hwndDlg, IDC_TEXTBAR, WM_SETTEXT, (WPARAM)(0), (LPARAM)(LPCTSTR)(strcpy(textbox, PUSH)));
		}	break;
	case IDOPTION:
		{
		DialogBox(global->MainVar.MainhInst, MAKEINTRESOURCE(IDD_OPTIONS), global->MainVar.ChildHwnd, (DLGPROC)Options_DialogProc);
		}	break;
	}
}
			//////////////////////////////////////
			// Handles ControlBar WM_NOTIFY messages
			//////////////////////////////////////
void ControlBar_OnNotify(HWND hwndDlg, int idCtrl, LPNMHDR pnmh)
{
if( (pnmh->code == LVN_ITEMCHANGING) || (pnmh->code == LVN_ITEMCHANGED) )
	{
	int count, i;
	LV_ITEM item;
	char TempStr[100];
	strcpy(TempStr, "");

	count = SendDlgItemMessage(hwndDlg, IDC_ITEMLIST, LVM_GETITEMCOUNT, (WPARAM)(0), (LPARAM)(0));

	for(i = 0; i < count; i++)
		{
		if(SendDlgItemMessage	(hwndDlg, IDC_ITEMLIST, LVM_GETITEMSTATE,
													(WPARAM)(i), (LPARAM)(LVIS_SELECTED)) == LVIS_SELECTED)
			{
			item.mask = LVIF_TEXT;
			item.iItem = i;
			item.iSubItem = 0;
			item.pszText = TempStr;
			item.cchTextMax = sizeof(TempStr);
			SendDlgItemMessage(hwndDlg, IDC_ITEMLIST, LVM_GETITEMTEXT, (WPARAM)(int)(i), (LPARAM)(LV_ITEM FAR *)(&item));
			count = -1;
			break;
			}
		}
// switches
	switch(controlstat)
		{
			case IDUSE:
			{
				if(strcmp(global->LevelVar.ScreenItem, "") != 0)
					{
					count = -1;
					strcpy(TempStr , global->LevelVar.ScreenItem);
					}
				if((strcmp(item1, "") == 0) && (count == -1))
					{
					strcpy(item1 , TempStr);
					strcpy(TempStr, USE);
					strcat(TempStr, item1);
					strcat(TempStr, WITH);
					SendDlgItemMessage(hwndDlg, IDC_TEXTBAR, WM_SETTEXT, (WPARAM)(0), (LPARAM)(LPCTSTR)(TempStr));
					}
				else	if((strcmp(item2, "") == 0) && (count == -1) && (strcmp(item1, TempStr) != 0))
					{
					strcpy(item2 , TempStr);
					strcpy(TempStr, USE);
					strcat(TempStr, item1);
					strcat(TempStr, WITH);
					strcat(TempStr, item2);
					SendDlgItemMessage(hwndDlg, IDC_TEXTBAR, WM_SETTEXT, (WPARAM)(0), (LPARAM)(LPCTSTR)(TempStr));
// send message
					MsgProc((HWNDdll)hwndDlg, controlstat, item1, item2);
// send message
					LV_ITEM FAR *pitem;
					pitem = (LV_ITEM FAR *)malloc(sizeof(LV_ITEM));
					pitem->state = LVIS_SELECTED;
					SendDlgItemMessage(hwndDlg, IDC_ITEMLIST, LVM_SETITEMSTATE, (WPARAM)(int)(i), (LPARAM)(LV_ITEM FAR *)(pitem) );
					strcpy(item1 , "");
					strcpy(item2 , "");
					strcpy(global->LevelVar.ScreenItem , "");
					SendDlgItemMessage(hwndDlg, IDC_TEXTBAR, WM_SETTEXT, (WPARAM)(0), (LPARAM)(LPCTSTR)(""));
					}

			}	break;
		case IDEXAMINE:
			{
				if(strcmp(global->LevelVar.ScreenItem, "") != 0)
					{
					count = -1;
					strcpy(TempStr , global->LevelVar.ScreenItem);
					}
				strcpy(item1 , TempStr);
				strcpy(TempStr , EXAMINE);
				strcat(TempStr, item1);
				SendDlgItemMessage(hwndDlg, IDC_TEXTBAR, WM_SETTEXT, (WPARAM)(0), (LPARAM)(LPCTSTR)(TempStr));
// send message
					MsgProc((HWNDdll)hwndDlg, controlstat, item1, item2);
// send message
				strcpy(item1 , "");
				strcpy(item2 , "");
				strcpy(global->LevelVar.ScreenItem , "");
				SendDlgItemMessage(hwndDlg, IDC_TEXTBAR, WM_SETTEXT, (WPARAM)(0), (LPARAM)(LPCTSTR)(""));
			}	break;
		case IDTALK:
			{
				if(strcmp(global->LevelVar.ScreenItem, "") != 0)
					{
					count = -1;
					strcpy(TempStr , global->LevelVar.ScreenItem);
					}
				strcpy(item1 , TempStr);
				strcpy(TempStr , TALK);
				strcat(TempStr, item1);
				SendDlgItemMessage(hwndDlg, IDC_TEXTBAR, WM_SETTEXT, (WPARAM)(0), (LPARAM)(LPCTSTR)(TempStr));
// send message
					MsgProc((HWNDdll)hwndDlg, controlstat, item1, item2);
// send message
				strcpy(item1 , "");
				strcpy(item2 , "");
				strcpy(global->LevelVar.ScreenItem , "");
				SendDlgItemMessage(hwndDlg, IDC_TEXTBAR, WM_SETTEXT, (WPARAM)(0), (LPARAM)(LPCTSTR)(""));
			} break;

		case IDGET:
			{
				if(strcmp(global->LevelVar.ScreenItem, "") != 0)
					{
					count = -1;
					strcpy(TempStr , global->LevelVar.ScreenItem);
					}
				strcpy(item1 , TempStr);
				strcpy(TempStr , GET);
				strcat(TempStr, item1);
				SendDlgItemMessage(hwndDlg, IDC_TEXTBAR, WM_SETTEXT, (WPARAM)(0), (LPARAM)(LPCTSTR)(TempStr));
// send message
					MsgProc((HWNDdll)hwndDlg, controlstat, item1, item2);
// send message
				strcpy(item1 , "");
				strcpy(item2 , "");
				strcpy(global->LevelVar.ScreenItem , "");
				SendDlgItemMessage(hwndDlg, IDC_TEXTBAR, WM_SETTEXT, (WPARAM)(0), (LPARAM)(LPCTSTR)(""));
			} break;
		case IDGIVE:
			{
				if(strcmp(global->LevelVar.ScreenItem, "") != 0)
					{
					count = -1;
					strcpy(TempStr , global->LevelVar.ScreenItem);
					}
				if((strcmp(item1, "") == 0) && (count == -1))
					{
					strcpy(item1 , TempStr);
					strcpy(TempStr, GIVE);
					strcat(TempStr, item1);
					strcat(TempStr, TO);
					SendDlgItemMessage(hwndDlg, IDC_TEXTBAR, WM_SETTEXT, (WPARAM)(0), (LPARAM)(LPCTSTR)(TempStr));
					}
				else	if((strcmp(item2, "") == 0) && (count == -1) && (strcmp(item1, TempStr) != 0))
					{
					strcpy(item2 , TempStr);
					strcpy(TempStr, GIVE);
					strcat(TempStr, item1);
					strcat(TempStr, TO);
					strcat(TempStr, item2);
					SendDlgItemMessage(hwndDlg, IDC_TEXTBAR, WM_SETTEXT, (WPARAM)(0), (LPARAM)(LPCTSTR)(TempStr));
// send message
					MsgProc((HWNDdll)hwndDlg, controlstat, item1, item2);
// send message
					LV_ITEM FAR *pitem;
					pitem = (LV_ITEM FAR *)malloc(sizeof(LV_ITEM));
					pitem->state = LVIS_SELECTED;
					SendDlgItemMessage(hwndDlg, IDC_ITEMLIST, LVM_SETITEMSTATE, (WPARAM)(int)(i), (LPARAM)(LV_ITEM FAR *)(pitem) );
					strcpy(item1 , "");
					strcpy(item2 , "");
					strcpy(global->LevelVar.ScreenItem , "");
					SendDlgItemMessage(hwndDlg, IDC_TEXTBAR, WM_SETTEXT, (WPARAM)(0), (LPARAM)(LPCTSTR)(""));	
					}
			} break;
		case IDPUSHPULL:
			{
				if(strcmp(global->LevelVar.ScreenItem, "") != 0)
					{
					count = -1;
					strcpy(TempStr , global->LevelVar.ScreenItem);
					}
				strcpy(item1 , TempStr);
				strcpy(TempStr , PUSH);
				strcat(TempStr, item1);
				SendDlgItemMessage(hwndDlg, IDC_TEXTBAR, WM_SETTEXT, (WPARAM)(0), (LPARAM)(LPCTSTR)(TempStr));
// send message
					MsgProc((HWNDdll)hwndDlg, controlstat, item1, item2);
// send message
				strcpy(item1 , "");
				strcpy(item2 , "");
				strcpy(global->LevelVar.ScreenItem , "");
				SendDlgItemMessage(hwndDlg, IDC_TEXTBAR, WM_SETTEXT, (WPARAM)(0), (LPARAM)(LPCTSTR)(""));
			} break;
		case IDOPEN:
			{
				if(strcmp(global->LevelVar.ScreenItem, "") != 0)
					{
					count = -1;
					strcpy(TempStr , global->LevelVar.ScreenItem);
					}
				strcpy(item1 , TempStr);
				strcpy(TempStr , OPEN);
				strcat(TempStr, item1);
				SendDlgItemMessage(hwndDlg, IDC_TEXTBAR, WM_SETTEXT, (WPARAM)(0), (LPARAM)(LPCTSTR)(TempStr));
// send message
					MsgProc((HWNDdll)hwndDlg, controlstat, item1, item2);
// send message
				strcpy(item1 , "");
				strcpy(item2 , "");
				strcpy(global->LevelVar.ScreenItem , "");
				SendDlgItemMessage(hwndDlg, IDC_TEXTBAR, WM_SETTEXT, (WPARAM)(0), (LPARAM)(LPCTSTR)(""));
			} break;
	case IDBCLOSE:
			{
				if(strcmp(global->LevelVar.ScreenItem, "") != 0)
					{
					count = -1;
					strcpy(TempStr , global->LevelVar.ScreenItem);
					}
				strcpy(item1 , TempStr);
				strcpy(TempStr , CLOSE);
				strcat(TempStr, item1);
				SendDlgItemMessage(hwndDlg, IDC_TEXTBAR, WM_SETTEXT, (WPARAM)(0), (LPARAM)(LPCTSTR)(TempStr));
// send message
					MsgProc((HWNDdll)hwndDlg, controlstat, item1, item2);
// send message
				strcpy(item1 , "");
				strcpy(item2 , "");
				strcpy(global->LevelVar.ScreenItem , "");
				SendDlgItemMessage(hwndDlg, IDC_TEXTBAR, WM_SETTEXT, (WPARAM)(0), (LPARAM)(LPCTSTR)(""));
			} break;
		}
	RECT r;
	r.top	= 0, r.left	= 0, r.bottom	= 128, r.right	= 640;
	RedrawWindow(hwndDlg, &r, NULL, RDW_ERASE |  RDW_INVALIDATE);
	}
}
			//////////////////////////////////////
			// Handles LoadFile WM_COMMAND messages
			//////////////////////////////////////
void Load_OnCommand(HWND hwndDlg, int id)
{
switch(id)
	{
	case IDOK:
		{
		if(global->sound.midi.MidiStat == IDM_PLAY)
			MidiProc(IDM_STOP);
//		if(global->sound.wav.WavStat == IDM_PLAY)
//			WaveProc(IDM_STOP);

			GAMEINFO	tempfi[MAXSAVE];
			char			S[256];
			int				item, i, j;
			FILE *		fp;

			fp = fopen(SAVEFILE, "r");
			fread(&GameInfo, sizeof(GameInfo), 1, fp);
			fclose(fp);

			memset(tempfi, '\0', sizeof(tempfi));
			strcpy(tempfi[0].game.name, NEWFILE);
			for(i = 0; i < MAXSAVE; i++)
				{
				for(j = 0; j < MAXICON; j++)
					tempfi[i].game.item[j] = -1;
				}

			int listsize = (int)SendDlgItemMessage(hwndDlg, IDC_LIST, LB_GETCOUNT, 0, 0);
			for (item = 0; item < listsize; item++)
	 			{
				SendDlgItemMessage(hwndDlg, IDC_LIST, LB_GETTEXT, (WPARAM)(item), (LPARAM)(LPCTSTR)(S));
				for (i = 0; i < MAXSAVE; i++)
					{
					if(strcmp(S, GameInfo[i].game.name) == 0)
						{
						tempfi[item] = GameInfo[i];
						i = MAXSAVE;
						}
					}
				}
			fp = fopen(SAVEFILE, "w+");
			fwrite(&tempfi, sizeof(tempfi), 1, fp);
			fclose(fp);

			item = (int)SendDlgItemMessage(hwndDlg, IDC_LIST, LB_GETCARETINDEX, 0, 0);
			SendDlgItemMessage(hwndDlg, IDC_LIST, LB_GETTEXT, (WPARAM)(item), (LPARAM)(LPCTSTR)(S));
			for (i = 0; i < MAXSAVE; i++)
				{
				if(strcmp(S, tempfi[i].game.name) == 0)
					{
					strcpy(game->name, tempfi[i].game.name);
					for(j = 0; j < MAXICON; j++)
						game->item[j]		= tempfi[i].game.item[j];
					for(j = 0; j < MAXVAR; j++)
						game->var[j]		= tempfi[i].game.var[j];
					game->levelNum			= tempfi[i].game.levelNum;
					game->MainChar			= tempfi[i].game.MainChar;
					game->MainChar			= tempfi[i].game.MainChar;
					game->GameSound.MidiStat = tempfi[i].game.GameSound.MidiStat;
					game->GameSound.CDGStat	 = tempfi[i].game.GameSound.CDGStat;
					game->GameSound.WavStat	 = tempfi[i].game.GameSound.WavStat;
					global->levelState	= 0;
					break;
					}
				}
			global->sound.midi.MidiStat = game->GameSound.MidiStat;
			global->sound.cd.CDGStat		= game->GameSound.CDGStat;
			global->sound.wav.WavStat		= game->GameSound.WavStat;
			strcpy(global->sound.midi.mf.file, "");
			global->MainVar.LoadFile = TRUE;
			EndDialog(hwndDlg, 0);
		}	break;

	case IDCANCEL:
		EndDialog(hwndDlg, 0);
		break;

	case IDDEL:
		{
		int item, listsize;
		item = (int)SendDlgItemMessage(hwndDlg, IDC_LIST, LB_GETCARETINDEX, 0, 0);
		listsize = (int)SendDlgItemMessage(hwndDlg, IDC_LIST, LB_GETCOUNT, 0, 0);
		if(listsize > 1)
			SendDlgItemMessage(hwndDlg, IDC_LIST, LB_DELETESTRING, (WPARAM)(item), (LPARAM)(0));
		if(item == (listsize - 1))
			item--;
		SendDlgItemMessage(hwndDlg, IDC_LIST, LB_GETTEXT, (WPARAM)(item), (LPARAM)(LPCTSTR)(string));
		SendDlgItemMessage(hwndDlg, IDC_LIST, LB_SELECTSTRING, (WPARAM)(-1), (LPARAM)(LPCTSTR)(string));
		}	break;
	}
if(global->LevelVar.LoadLevel)
	global->LevelVar.Redraw = TRUE;
}
			//////////////////////////////////////
			// Handles SaveFile WM_COMMAND messages
			//////////////////////////////////////
void Save_OnCommand(HWND hwndDlg, int id)
{
switch(id)
	{
	case IDOK:
		{
			FILE *fp;
			BOOL error;
			if((fp = fopen(SAVEFILE, "r")) != NULL)
				{
				fread(&GameInfo, sizeof(GameInfo), 1, fp);
				fclose(fp);
				error = FALSE;
				}
			else 
				{
				error = TRUE;
				NewGameFile(SAVEFILE);
				}

			game->GameSound.MidiStat = global->sound.midi.MidiStat;
			game->GameSound.CDGStat	 = global->sound.cd.CDGStat;
			game->GameSound.WavStat	 = global->sound.wav.WavStat;
			if(game->GameSound.MidiStat == IDM_PLAY)
				game->GameSound.MidiStat = IDM_PAUSE;
			if(game->GameSound.WavStat == IDM_PLAY)
				game->GameSound.WavStat = IDM_PAUSE;
			char S1[MAXARRAY];
			char S2[MAXARRAY];
			GetDlgItemText(hwndDlg, IDC_NAME, S2, MAXARRAY);
			for (int i = 0; i < MAXSAVE; i++)
	 			{
				if(strcmp(S2, GameInfo[i].game.name) == 0)
					{
					LoadString(global->MainVar.MainhInst, IDST_REPLACE, S1, sizeof(S1));
					int msg = MessageBox(hwndDlg, strcat(S2, S1), "File Error", MB_YESNO | MB_ICONERROR);
					if(msg == IDYES)
						{
						GameInfo[i].game = *game;
						error = FALSE;
						}
					if(msg == IDNO)
						error = TRUE;
					break;
					}
				else if(i == (MAXSAVE - 1))
					{
					for(int j = 0; j < MAXSAVE; j++)
						{
						if(GameInfo[j].game.item[0] == -1)
							{
							GameInfo[j].game = *game;
							strcpy(GameInfo[j].game.name, S2);
							error = FALSE;
							break;
							}
						}
					}
				}
			if(!error)
				{
				SaveGameFile(SAVEFILE);
				EndDialog(hwndDlg, 0);
				}
		} break;

	case IDCANCEL:
		EndDialog(hwndDlg, 0);
		break;
	}
}
			//////////////////////////////////////
			// Handles WM_COMMAND messages
			//////////////////////////////////////
void Options_OnCommand(HWND hwndDlg, int id)
{
switch(id)
	{
//	CANCEL Button
	case IDCANCEL:
		{
		global->LevelVar.Redraw = TRUE;
		EndDialog(hwndDlg, 0);
		SetFocus(global->MainVar.ControlsHwnd);
		}	break;
//	EXIT Button
	case IDEXIT:
		{
		PostQuitMessage(0);
		}	break;
//	HELP Button
	case IDHELPTXT:
		{
		char S[100];
		GetWindowsDirectory(S, sizeof(S));
		strcat(S, "\\NOTEPAD.EXE HELP.TXT");
		WinExec(S, SW_SHOWNORMAL);
		}	break;
//	LOAD Button
	case IDLOAD:
		{
		DialogBox(global->MainVar.MainhInst, MAKEINTRESOURCE(IDD_LOADFILE), hwndDlg, (DLGPROC)Loadfile_DialogProc);
		if(global->MainVar.LoadFile)
			{
			global->LevelVar.LoadLevel = FALSE;
			global->LevelVar.Redraw = TRUE;
			EndDialog(hwndDlg, 0);
			}
		SetFocus(hwndDlg);
		}	break;
//	SAVE Button
	case IDSAVE:
		{
		DialogBox(global->MainVar.MainhInst, MAKEINTRESOURCE(IDD_SAVEFILE), hwndDlg, (DLGPROC)Savefile_DialogProc);
		SetFocus(hwndDlg);
		}	break;
//	MIDI Check Button
	case IDMIDISND:
		{
		if(SendDlgItemMessage(hwndDlg, IDMIDISND, BM_GETCHECK, (WPARAM)(0), (LPARAM)(0)) == BST_CHECKED)
			{
			strcpy(global->sound.midi.mf.file, "");
			global->sound.midi.MidiStat = IDM_PAUSE;
			}
		else
			global->sound.midi.MidiStat = IDM_NULL;
		} break;
//	WAV Check Button
	case IDWAVSND:
		{
		if(SendDlgItemMessage(hwndDlg, IDWAVSND, BM_GETCHECK, (WPARAM)(0), (LPARAM)(0)) == BST_CHECKED)
			global->sound.wav.WavStat = IDM_PAUSE;
		else 
			global->sound.wav.WavStat = IDM_NULL;
		} break;
//	CD Check Button
	case IDCDSND:
		{
		StartCD(hwndDlg);
		} break;
//	PLAY Button
	case IDC_CD_PLAY:
		{
		PlayCD(hwndDlg);
		} break;
//	PAUSE Button
	case IDC_CD_PAUSE:
		{
		PauseCD(hwndDlg);
		} break;
//	RW Button
	case IDC_CD_RW:
		{
		RewindCD(hwndDlg);
		} break;
//	FF Button
	case IDC_CD_FF:
		{
		FastFCD(hwndDlg);
		} break;
//	STOP Button
	case IDC_CD_STOP:
		{
		StopCD(hwndDlg);
		} break;
//	EJECT Button
	case IDC_CD_EJECT:
		{
		EjectCD(hwndDlg);
		} break;
//	EDIT Button
	case IDC_EDIT_PL:
		{
		EditPL(hwndDlg);
		} break;
//	SHUFFLE Button
	case IDC_SHUF:
		{
		Shuffle(hwndDlg);
		} break;
//	Repeat Track Button
	case IDC_RTRACK:
		{
		RTrack(hwndDlg);
		} break;
//	Repeat Disk Button
	case IDC_RDISK:
		{
		RDisk(hwndDlg);
		} break;
	}
}
