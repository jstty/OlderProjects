////////////////////////////////////////////////////////////////////////
//	Program Name:	Debug.cpp
//	Programmer:		Joseph Sutton
//	Company:			Moggie Software
//	Corporation:	Willy Wong Ping Pong Inc.
//	Description:	Debug Window File
//	Date:					6/18/99
//	Version:			2.00
////////////////////////////////////////////////////////////////////////
#ifdef _DEBUG

#include <windows.h>
#include <windowsx.h>
#include <commctrl.h>
	#include "..\Resource Files\resource.h"
#include "..\Header Files\DebugClass.h"
#include "..\Header Files\ValuesClass.h"
#include "..\Header Files\TestSpeed.h"

extern VALUES	*Val;
extern DEBUGCLASS	Debug;

//
extern TestSpeed tsMain;
extern TestSpeed tsControls;
extern TestSpeed tsDisplay;
extern TestSpeed tsAction;
extern TestSpeed tsSound;
//
unsigned int W;
unsigned int H;
//
//
//
void DEBUGCLASS::Start(void)
{
	__int8 i = 0;
	HTREEITEM hTreeMain;

//	HTREEITEM hTreeControls;
//	HTREEITEM hTreeP1, hTreeP2;
//	HTREEITEM hTree;
//	HTREEITEM hTreeSub;
//	HTREEITEM hTreeSprite[4];


	ListCount = 0;

	hTreeMain = CreateRoot("Rate");
	CreateSub(hTreeMain, "Rate = %f",				&(tsMain.Rate), E_FLOAT);
/*
	CreateSub(hTreeMain, "Control = %f",			&(Val->Main->controls_rate), E_FLOAT);
	CreateSub(hTreeMain, "Level = %f",				&(Val->Main->level_rate), E_FLOAT);
	CreateSub(hTreeMain, "Display = %f",			&(Val->Main->display_rate), E_FLOAT);
	
	CreateSub(hTreeMain, "Move = %f",				&(Val->Display->move_rate), E_FLOAT);
	CreateSub(hTreeMain, "Anim = %f",				&(Val->Display->anim_rate), E_FLOAT);
	CreateSub(hTreeMain, "Clean = %f",				&(Val->Display->clean_rate), E_FLOAT);
	CreateSub(hTreeMain, "Draw = %f",				&(Val->Display->draw_rate), E_FLOAT);
	CreateSub(hTreeMain, "Screen = %f",				&(Val->Display->screen_rate), E_FLOAT);
*/

	/*
	hTreeControls = CreateRoot("Controls");
//
	hTreeP1 = CreateSub(hTreeControls, "Player1");
	hTreeP2 = CreateSub(hTreeControls, "Player2");
	TreeView_Expand(hCView, hTreeP1, TVE_EXPAND);
	TreeView_Expand(hCView, hTreeP2, TVE_EXPAND);
//
	CreateSub(hTreeP1, "Up = %d",				&(Val->Controls->Player[0][UP]), E_BOOL );
	CreateSub(hTreeP1, "Down = %d",			&(Val->Controls->Player[0][DOWN]), E_BOOL );
	CreateSub(hTreeP1, "Left = %d",			&(Val->Controls->Player[0][LEFT]), E_BOOL );
	CreateSub(hTreeP1, "Right = %d",		&(Val->Controls->Player[0][RIGHT]), E_BOOL );
	CreateSub(hTreeP1, "Button 1 = %d",	&(Val->Controls->Player[0][B1]), E_BOOL );
	CreateSub(hTreeP1, "Button 2 = %d",	&(Val->Controls->Player[0][B2]), E_BOOL );
	CreateSub(hTreeP1, "Button 3 = %d",	&(Val->Controls->Player[0][B3]), E_BOOL );
	CreateSub(hTreeP1, "Button 4 = %d",	&(Val->Controls->Player[0][B4]), E_BOOL );
	CreateSub(hTreeP2, "Up = %d",				&(Val->Controls->Player[1][UP]), E_BOOL );
	CreateSub(hTreeP2, "Down = %d",			&(Val->Controls->Player[1][DOWN]), E_BOOL );
	CreateSub(hTreeP2, "Left = %d",			&(Val->Controls->Player[1][LEFT]), E_BOOL );
	CreateSub(hTreeP2, "Right = %d",		&(Val->Controls->Player[1][RIGHT]), E_BOOL );
	CreateSub(hTreeP2, "Button 1 = %d",	&(Val->Controls->Player[1][B1]), E_BOOL );
	CreateSub(hTreeP2, "Button 2 = %d",	&(Val->Controls->Player[1][B2]), E_BOOL );
	CreateSub(hTreeP2, "Button 3 = %d",	&(Val->Controls->Player[1][B3]), E_BOOL );
	CreateSub(hTreeP2, "Button 4 = %d",	&(Val->Controls->Player[1][B4]), E_BOOL );
*/

/*
	hTreeControls = CreateRoot("Controls");
	hTree = CreateSub(hTreeControls, "Mouse");

	CreateSub(hTree, "d Mouse X Pos = %d",	&(Val->Display->Mouse->r.left), E_INT16 );
	CreateSub(hTree, "d Mouse Y Pos = %d",	&(Val->Display->Mouse->r.top), E_INT16 );
	
	CreateSub(hTree, "c Mouse X Pos = %d",	&(Val->Controls->Mouse.x), E_INT16 );
	CreateSub(hTree, "c Mouse Y Pos = %d",	&(Val->Controls->Mouse.y), E_INT16 );

	CreateSub(hTree, "Mouse Left Click = %d",	&(Val->Controls->Mouse.Left), E_BOOL );
	CreateSub(hTree, "Mouse Right Click = %d",	&(Val->Controls->Mouse.Right), E_BOOL );
	CreateSub(hTree, "Mouse Mibble Click = %d",	&(Val->Controls->Mouse.Middle), E_BOOL );
	CreateSub(hTree, "Mouse Start X = %d",	&(Val->Controls->Mouse.StartX), E_INT16 );
	CreateSub(hTree, "Mouse Start Y = %d",	&(Val->Controls->Mouse.StartY), E_INT16 );
	CreateSub(hTree, "Mouse End X = %d",	&(Val->Controls->Mouse.EndX), E_INT16 );
	CreateSub(hTree, "Mouse End Y = %d",	&(Val->Controls->Mouse.EndY), E_INT16 );

	TreeView_Expand(hCView, hTree, TVE_EXPAND);
*/

	TreeView_Expand(hCView, hTreeMain, TVE_EXPAND);
//	TreeView_Expand(hCView, hTree, TVE_EXPAND);

	ReFresh();
}
//
//
//
HTREEITEM DEBUGCLASS::CreateRoot(char *Name)
{
	TV_INSERTSTRUCT tvInsert;
	tvInsert.hParent = NULL;
	tvInsert.hInsertAfter = TVI_LAST;

	TV_ITEM tvItem;
	tvItem.mask = LVIF_TEXT;
	tvItem.pszText = Name;
	tvItem.cchTextMax = sizeof(char)*strlen(Name);

	tvInsert.item = tvItem;

	return TreeView_InsertItem(hCView, &tvInsert);
}
//
//
//
void DEBUGCLASS::End(void)
{
	if( (htList != NULL) && (ListCount == 0) )
		Val->File_Util->FreeMem(htList);

	ListCount = 0;
	htList = 0;
}
//
//
//
HTREEITEM DEBUGCLASS::AddToList(HTREEITEM ht, char* n, void* p, unsigned int t)
{
	ListCount++;

	Val->File_Util->LoadMem((HGLOBAL &)tList, htList, sizeof(TreeList)*ListCount);

	unsigned int i = ListCount - 1;

	tList[i].hTree = ht;
	tList[i].Name = new char[strlen(n)];
	strcpy(tList[i].Name, n);
	tList[i].Param = p;
	tList[i].Type = t;

	return ht;
}
//
//
//
HTREEITEM DEBUGCLASS::CreateSub(HTREEITEM hTree, char *Name, void* param, unsigned int t)
{
	TV_INSERTSTRUCT tvInsert;
	tvInsert.hParent = hTree;
	tvInsert.hInsertAfter = TVI_LAST;

	TV_ITEM tvItem;
	tvItem.mask = LVIF_TEXT;
	tvItem.pszText = Name;
	tvItem.cchTextMax = sizeof(char)*strlen(Name);
	
	tvInsert.item = tvItem;

	return AddToList(TreeView_InsertItem(hCView, &tvInsert), Name, param, t);
}
//
//
//
void DEBUGCLASS::ReFresh(void)
{
	TV_ITEM tvItem;
	char Temp[256];
	unsigned int i;

	for(i = 0; i < ListCount; i++)
	{
		if(tList[i].Param != 0)
		{
			if(tList[i].Type == E_INT8)
			{
				unsigned __int8 *iParam;
				iParam = (unsigned __int8 *)tList[i].Param;
				sprintf(Temp, tList[i].Name, *iParam);
			}
			else if(tList[i].Type == E_INT16)
			{
				unsigned __int16 *iParam;
				iParam = (unsigned __int16 *)tList[i].Param;
				sprintf(Temp, tList[i].Name, *iParam);
			}
			else if(tList[i].Type == E_INT32)
			{
				unsigned __int32 *iParam;
				iParam = (unsigned __int32 *)tList[i].Param;
				sprintf(Temp, tList[i].Name, *iParam);
			}
			else if(tList[i].Type == E_FLOAT)
			{
				float *fParam;
				fParam = (float *)tList[i].Param;
				sprintf(Temp, tList[i].Name, *fParam);
			}
			else if(tList[i].Type == E_BOOL)
			{
				bool *fParam;
				fParam = (bool *)tList[i].Param;
				sprintf(Temp, tList[i].Name, *fParam);
			}
			else
				return;

			tvItem.mask = LVIF_TEXT;
			tvItem.hItem = tList[i].hTree;
			tvItem.pszText = Temp;
			tvItem.cchTextMax = sizeof(char)*strlen(Temp);

			TreeView_SetItem(hCView, &tvItem);
		}
	}
}

//////////////////////////////////////
// The Debug Procedure
//////////////////////////////////////
BOOL CALLBACK DebugProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	if(msg == WM_INITDIALOG)
	{
		Debug.End();
		RECT Rect1, Rect2;
		int xMax, yMax;

		GetWindowRect(Val->Main->Get_MainHwnd(), &Rect1);
		GetClientRect(Val->Main->Get_MainHwnd(), &Rect2);
		xMax = (int)( Rect1.right + Rect2.left - Rect2.right );
		yMax = (int)( Rect1.bottom + Rect2.top - Rect2.bottom );

		if(xMax < 0)
			xMax = 0;
		if(yMax < 0)
			yMax = 0;

//		xMax = 10;
//		xMax = (GetSystemMetrics(SM_CYSCREEN) - Rect1.bottom + Rect1.top) >> 1 - 50;

		SetWindowPos(hwnd, HWND_TOPMOST, 10, 10, 0, 0, SWP_NOSIZE);

		if(hwnd != NULL)
			Debug.hwndDlg = hwnd;
		else
			return 0;

		Debug.hCView = GetDlgItem(hwnd, IDC_TREE);
		if(Debug.hCView == NULL)
			return 0;

		GetWindowRect(hwnd, &Rect1);
		GetWindowRect(Debug.hCView, &Rect2);
		W = abs(Rect2.left - Rect1.left);
		H = abs(Rect2.top - Rect1.top);

		SetFocus(Val->Main->Get_MainHwnd());

		Debug.Start();

		return 1;
	}
	else if(msg == WM_COMMAND)
	{
		if((UINT)LOWORD(wParam) == IDCANCEL )
		{
			// GetPos

			// SaveInfo

			// Close
			Debug.End();
			DestroyWindow(hwnd);
		}
		return 1;
	}
	else if(msg == WM_SIZING)
	{
		unsigned int w, h;
		RECT Rect;
		//
		Rect = *(LPRECT)lParam;

		w = abs(Rect.right - Rect.left) - ( W << 1 );
		h = abs(Rect.bottom - Rect.top) - H - W;

		SetWindowPos(Debug.hCView, NULL, 0, 0, w, h, SWP_NOMOVE | SWP_SHOWWINDOW | SWP_NOZORDER );

		return 1;
	}

	return 0;
}
#endif