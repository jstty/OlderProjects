////////////////////////////////////////////////////////////////////////
//	Program Name:	DebugClass.h
//	Programmer:		Joseph Sutton
//	Company:			Moggie Software
//	Corporation:	Willy Wong Ping Pong Inc.
//	Description:	Debug Class header File
//	Date:					6/18/99
//	Version:			2.00
////////////////////////////////////////////////////////////////////////
#ifndef _DEBUGCLASS
#define _DEBUGCLASS

#include "..\Header Files\ErrorClass.h"
#include "commctrl.h"

//#define E_INT		0
#define E_INT8	1
#define E_INT16 2
#define E_INT32 3
#define E_FLOAT 4
#define E_BOOL	5

class DEBUGCLASS : public ERRORCLASS{
	public:
		HWND hwndDlg;
		HWND hCView;

		void ReFresh(void);
		void Start(void);
		void End(void);
		void Hide(void){	ShowWindow(hwndDlg, SW_HIDE);	};

	private:
		unsigned __int8 ListCount;

		struct TreeList
		{
			HTREEITEM hTree;
			char *Name;
			void *Param;
			unsigned int Type:3;
		};

		TreeList *tList;
		HGLOBAL		htList;

		void FreeList(void);
		HTREEITEM CreateRoot(char *Name);
		HTREEITEM AddToList(HTREEITEM ht, char* n, void* p, unsigned int t);
		HTREEITEM CreateSub(HTREEITEM hTree, char *Name, void* param = NULL, unsigned int t = E_INT32);
};
typedef	DEBUGCLASS *P_DEBUGCLASS;

#endif
