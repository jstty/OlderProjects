// MainFrm.cpp : implementation of the CMainFrame class
//

#include "stdafx.h"
#include "MainFrm.h"
#include "Pop.h"

#include "../code/tankwars2005.h"
extern cTankWars2005 *tws2005;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//====================BEGIN RUDY CODE BLOCK ==================
/* The #if block below defines the POPHTMLHELP flag  for Visual Studio.NET and doesn't
	define it for Visual Studio, Version 6.0. 
	If POPHTMLHELP is on, then the Help|Users Guide in the Pop app will show the POP.CHM file.
	If POPHTMLHELP is off, then the Help|Users Guide in the Pop app will show the POP.HLP file.
*/

#if _MSC_VER >= 1300 /* Begin switch for defining POPHTMLHELP.
	Version abcd means your Visual C++ is version ab.cd.  It turns out
	"Visual Studio.NET, Version 7.0" gives an _MSC_VER of 1300, or Build 13.00, 
	and "Version 6.0" has _MSC_VER of 1200, or Build 12.00 for a _MSC_VER of 1200.
		We could also have distinguised the two by detecting the MFC version, with _MFC_VER. 
	The _MFC_VER is, perversely, returned as a hexadecimal number.  Version 6.0 uses MFC 
	version 0x0060, while Version 7.0 uses 0x0070. */
#define POPHTMLHELP /* Normally don't use this with Version 6.0, though you can if you want, see
	the next comment down. */
#endif //End the _MSC_VER switch for defining POPHTMLHLP

//#define POPHTMLHELP
	/* Comment in the #define POPHTMLHELP if you want to override the default behavior and
	force the POPHTMLHELP flag on for Visual Studio 6.0. 
	Note that if you force the flag on, you may need to add htmlhelp.lib to the list
	 of external modules to link in.  In Visual Studio 6.0, this is found on
	Properties | Settings... | Link | Object/library modules. */
//#undef POPHTMLHELP
	/* 	Comment in the #undef POPHTMLHELP if you want to override the default behavior and
	force the POPHTMLHELP flag off for Visual Studio.NET. */ 

#ifdef POPHTMLHELP
#include <htmlhelp.h>
#include ".\mainfrm.h"
/* Visual Studio.NET puts htmlhelp.h and htmlhelp.lib onto your machine.  If you are
	using Visual Studio, Version 6.0, you may have to get these files yourself,and put
	them in a place where the current Visual Studio Directories settings can find them.
	Note that for Version 6.0, you also need to add htmlhelp.lib to the list of Link
	files.  You can	get the htmlhelp files from www.microsoft.com by searching for
	"download htmlhelp". */
#endif // POPHTMLHELP

#define DONTOUTSTRIPGRAPHICSREFRESHRATE
	/* If you comment in DONTOUTSTRIPGRAPHICSREFRESHRATE, we set the program's maximum
	update rate to not exceed the display's inherent refresh rate.*/

//#define TRACEFULLSCREEN
	/* If you comment in TRACEFULLSCREEN you dump information about the
	fullscreen switching code. */
//====================END RUDY CODE BLOCK ==================

/////////////////////////////////////////////////////////////////////////////
// CMainFrame

IMPLEMENT_DYNAMIC(CMainFrame, CMDIFrameWnd)

BEGIN_MESSAGE_MAP(CMainFrame, CMDIFrameWnd)
	//{{AFX_MSG_MAP(CMainFrame)
	ON_WM_CREATE()
	ON_COMMAND(ID_WINDOW_NEW, OnWindowNew)
	ON_WM_SIZE()
	ON_COMMAND(ID_WINDOW_AUTOTILE, OnWindowAutotile)
	ON_UPDATE_COMMAND_UI(ID_WINDOW_AUTOTILE, OnUpdateWindowAutotile)
	ON_COMMAND(ID_WINDOW_AUTOFOCUS, OnWindowAutofocus)
	ON_UPDATE_COMMAND_UI(ID_WINDOW_AUTOFOCUS, OnUpdateWindowAutofocus)
	ON_WM_CLOSE()
	ON_WM_TIMER()
	ON_WM_CHAR()
	ON_WM_KEYDOWN()
	ON_WM_KEYUP()
	//}}AFX_MSG_MAP
	ON_COMMAND(ID_VIEW_FULLSCREEN, OnViewFullscreen)
	ON_UPDATE_COMMAND_UI(ID_VIEW_FULLSCREEN, OnUpdateViewFullscreen)
	ON_WM_GETMINMAXINFO()
END_MESSAGE_MAP()

static UINT indicators[] =
{
	ID_SEPARATOR //,           // status line indicator
//	ID_INDICATOR_CAPS,
//	ID_INDICATOR_NUM,
//	ID_INDICATOR_SCRL,
};

/////////////////////////////////////////////////////////////////////////////
// CMainFrame construction/destruction

CMainFrame::CMainFrame():
_autotile(TRUE),	//RR.
_autofocus(FALSE)  //Nice feature, but is confusing for new users.
{
	// TODO: add member initialization code here
	//m_created = FALSE;
//fullscreen...start
	m_pWndFullScreen = NULL; //fullscreen
//fullscreen...end

}

CMainFrame::~CMainFrame()
{
	//
}

int CMainFrame::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
#ifdef DONTOUTSTRIPGRAPHICSREFRESHRATE
	int refreshrate = ::GetDeviceCaps(GetDC()->GetSafeHdc(), VREFRESH);
	if (refreshrate > 1) /* Some systems won't give this info and just return 0 or 1.
		and for these, we'll just leave the default mindt that was set in CPopApp constructor. */
		((CPopApp*)::AfxGetApp())->
		_timer.setMinDt(1.0/double(refreshrate)); //Don't run faster than 100 updates a second.
#endif //DONTOUTSTRIPGRAPHICSREFRESHRATE
	if (CMDIFrameWnd::OnCreate(lpCreateStruct) == -1)
		return -1;

   main_status = new cStatusBar;
   if (!main_status->Create(this, IDD_STATUS_BAR, WS_CHILD | CBRS_TOP, 100) )
	{
		TRACE0("Failed to create toolbar\n");
	}

   main_status->EnableDocking(CBRS_ALIGN_TOP | CBRS_ALIGN_BOTTOM);
	EnableDocking(CBRS_ALIGN_TOP | CBRS_ALIGN_BOTTOM);
	DockControlBar(main_status);
   ShowControlBar(main_status, false, false);
	
   // Removed toolbar and statusbar
   // Modifyed by: Joseph E. Sutton
   /*
	if (!m_wndToolBar.CreateEx(this, TBSTYLE_FLAT, WS_CHILD | WS_VISIBLE | CBRS_TOP
		| CBRS_GRIPPER | CBRS_TOOLTIPS | CBRS_FLYBY | CBRS_SIZE_DYNAMIC) ||
		!m_wndToolBar.LoadToolBar(IDR_MAINFRAME))
	{
		TRACE0("Failed to create toolbar\n");
		return -1;      // fail to create
	}

	if (!m_wndStatusBar.Create(this) ||
		!m_wndStatusBar.SetIndicators(indicators,
		  sizeof(indicators)/sizeof(UINT)))
	{
		TRACE0("Failed to create status bar\n");
		return -1;      // fail to create
	}
	m_wndStatusBar.SetPaneStyle(0, SBPS_POPOUT | SBPS_STRETCH);
		//This line makes the status bar message be outlined in a raised button.

	// TODO: Delete these three lines if you don't want the toolbar to
	//  be dockable
	m_wndToolBar.EnableDocking(CBRS_ALIGN_ANY);
	EnableDocking(CBRS_ALIGN_ANY);
	DockControlBar(&m_wndToolBar);
   */

	
	//m_created = TRUE;
	return 0;
}

BOOL CMainFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	if( !CMDIFrameWnd::PreCreateWindow(cs) )
		return FALSE;
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs
	cs.cx = CPopApp::STARTPIXELWIDTH;  //800;
	cs.cy = CPopApp::STARTPIXELHEIGHT; //600;
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CMainFrame diagnostics

#ifdef _DEBUG
void CMainFrame::AssertValid() const
{
	CMDIFrameWnd::AssertValid();
}

void CMainFrame::Dump(CDumpContext& dc) const
{
	CMDIFrameWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CMainFrame message handlers

void CMainFrame::OnWindowNew() 
{
	if (getMDIChildCount() >= CPopApp::MAXCHILDWINDOWCOUNT)
	{
		::MessageBeep(MB_ICONEXCLAMATION);
		return;
	}
	CMDIFrameWnd::OnWindowNew(); //Call base class handler.
	//My code.  RR.
		/* Keep tiling so the view windows stay "stuck" to the outer window.
			 The CMainFrame::getMDIChildCount() is a helper function I added.
			Gets the number of existing child frames, including this one.  If
			there are more than one child, then I tile, otherwise I don't tile
			because whenever I have only one child, it is maximized.  You don't
			want to tile when a single window is maximized as this brings its 
			caption bar back down into the MDI client area.*/
	if (_autotile && getMDIChildCount() > 1) //Automatically keep all views tiled
		MDITile(MDITILE_VERTICAL);
}

void CMainFrame::OnSize(UINT nType, int cx, int cy) 
{
	CMDIFrameWnd::OnSize(nType, cx, cy); //Call base class handler.
	//My code.  RR.
	if (_autotile && getMDIChildCount() > 1) //Automatically keep all views tiled
		MDITile(MDITILE_VERTICAL);

   SetWindowText(WINDOW_TITLE);
}

void CMainFrame::OnWindowAutotile() //RR
{
	_autotile ^= TRUE;
	if (_autotile && getMDIChildCount() > 1) //Automatically keep all views tiled
		MDITile(MDITILE_VERTICAL);
	if (_autotile) //Retile now if necessary, or maximize if there's only one.
	{	//See the comments on this code in CMainFrame::OnWindowNew  above.
		int viewcount = getMDIChildCount(); 
		if (viewcount > 1) 
			MDITile(MDITILE_VERTICAL);
		else if (viewcount == 1) //There's only one split view, so maximize it
		{
			CMDIChildWnd *childframe = MDIGetActive();
			childframe->ShowWindow(SW_SHOWMAXIMIZED); 
		}
	}
}

void CMainFrame::OnUpdateWindowAutotile(CCmdUI* pCmdUI) //RR
{
	pCmdUI->SetCheck(_autotile?1:0);
}

void CMainFrame::OnWindowAutofocus() //RR
{
	_autofocus ^= TRUE;	
}

void CMainFrame::OnUpdateWindowAutofocus(CCmdUI* pCmdUI) //RR
{
	pCmdUI->SetCheck(_autofocus?1:0);
}

//Helper function

int CMainFrame::getMDIChildCount()
{
	int count = 0;
	CMDIChildWnd *next, *current = MDIGetActive();
	if (!current)
		return 0;
	while (TRUE) //We exit this endless loop with a return that's sure to happen.
	{
		count++;
		MDINext();
		next = MDIGetActive();
		if (next == current)
			return count;
	}
}

void CMainFrame::OnClose() 
{
	CMDIFrameWnd::OnClose();
}

/*
void CMainFrame::OnHelpUsersguide() 
{
#ifndef POPHTMLHELP //If not POPHTMLHELP do it the old way with a *.hlp
	::WinHelp(GetSafeHwnd(), "Pop.hlp", HELP_CONTENTS, 0);	
#else // POPHTMLHELP means use a *.chm.
	::HtmlHelp(GetSafeHwnd(),"Pop.chm", HH_DISPLAY_TOPIC, 0) ;
#endif //End POPHTMLHELP switch
}
*/

//fullscreen...start
void CMainFrame::EscapeFullScreen(void)
{
   SetWindowText(WINDOW_TITLE);

	if (m_pWndFullScreen != NULL)
		OnViewFullscreen();
}

void CMainFrame::OnViewFullscreen()
{
   SetWindowText(WINDOW_TITLE);

#ifdef TRACEFULLSCREEN
//	TRACE("m_wndStatusBar == %d\n", m_wndStatusBar.IsWindowVisible());
//	TRACE("m_wndToolBar   == %d\n", m_wndToolBar.IsWindowVisible());
#endif //TRACEFULLSCREEN

	if (m_pWndFullScreen != NULL)
	{
		/* If we are returning the app to the non-fullscreen state,
		 SetWindowPlacement() draws the entire app twice - once to
		 its "Normal" state, then once to its previous size.
		 The LockWindowUpdate() calls suppress the extra redraw. */

		//ShowControlBar(&m_wndToolBar, m_bHadToolBar, FALSE);
		//ShowControlBar(&m_wndStatusBar, m_bHadStatusBar, FALSE);

		m_pWndFullScreen->LockWindowUpdate();
		m_pWndFullScreen->SetWindowPlacement(&m_PreviousPlace);
		m_pWndFullScreen->UnlockWindowUpdate();

		LockWindowUpdate();
		SetWindowPlacement(&m_MainPreviousPlace);
		UnlockWindowUpdate();
		m_pWndFullScreen = NULL;
	}
	else //We are entering fullscreen mode
	{
		m_pWndFullScreen = MDIGetActive();
		ASSERT(m_pWndFullScreen != NULL);

		//m_bHadToolBar = m_wndToolBar.IsWindowVisible();
		//m_bHadStatusBar = m_wndStatusBar.IsWindowVisible();
		//ShowControlBar(&m_wndToolBar, FALSE, FALSE);
		//ShowControlBar(&m_wndStatusBar,FALSE, FALSE);

		m_pWndFullScreen->GetWindowPlacement(&m_PreviousPlace);
		GetWindowPlacement(&m_MainPreviousPlace);

		CRect rectDesktop;
		if (!::SystemParametersInfo(SPI_GETWORKAREA, 0,
			 &rectDesktop, 0))
	 		::GetWindowRect(::GetDesktopWindow(), &rectDesktop);
		else
		{
			rectDesktop.right = ::GetSystemMetrics(SM_CXSCREEN);
			rectDesktop.bottom = ::GetSystemMetrics(SM_CYSCREEN);
				/* the next four lines do nothing, as rectDesktop was just
				created, so left and bottom are 0. */
			rectDesktop.right -= rectDesktop.left;
			rectDesktop.bottom -= rectDesktop.top;
			rectDesktop.left = -rectDesktop.left;
			rectDesktop.top = -rectDesktop.top;
		}

#ifdef TRACEFULLSCREEN
		TRACE("Going to (%d,%d) - (%d,%d)\n", 
			rectDesktop.left, rectDesktop.top,
			rectDesktop.right, rectDesktop.bottom);
#endif //TRACEFULLSCREEN

		CRect rectDesired = rectDesktop;
		::AdjustWindowRect(&rectDesktop, GetStyle(), TRUE);

#ifdef TRACEFULLSCREEN
		TRACE("Adjusted to (%d,%d) - (%d,%d)\n",
			rectDesktop.left, rectDesktop.top,
			rectDesktop.right, rectDesktop.bottom);
#endif //TRACEFULLSCREEN

		rectDesktop.bottom += ::GetSystemMetrics(SM_CYBORDER);
			// See "Ask Dr. GUI #10"
		rectDesktop.bottom += ::GetSystemMetrics(SM_CYSMCAPTION);
		m_FullScreenPlace = rectDesktop;
		m_MainFullScreenPlace = rectDesktop;

		WINDOWPLACEMENT wpNew = m_PreviousPlace;
		wpNew.showCmd =  SW_SHOWNORMAL;
		wpNew.rcNormalPosition = rectDesktop;

		LockWindowUpdate();
		SetWindowPlacement(&wpNew);
		UnlockWindowUpdate();

#ifdef TRACEFULLSCREEN
		TRACE("Before MDI Child to (%d,%d) - (%d,%d)\n",
			wpNew.rcNormalPosition.left, wpNew.rcNormalPosition.top,
			wpNew.rcNormalPosition.right, wpNew.rcNormalPosition.bottom);
#endif //TRACEFULLSCREEN

		wpNew.rcNormalPosition = rectDesired;
		::AdjustWindowRect(&(wpNew.rcNormalPosition), 
			m_pWndFullScreen->GetStyle(), FALSE);
			/* AdjustWindowRect function calculates the required size of the
			 window rectangle, based on the desired client-rectangle size */
#ifdef TRACEFULLSCREEN
		TRACE("MDI Child to (%d,%d) - (%d,%d)\n", 
			wpNew.rcNormalPosition.left, wpNew.rcNormalPosition.top,
			wpNew.rcNormalPosition.right, wpNew.rcNormalPosition.bottom);
#endif //TRACEFULLSCREEN

		m_pWndFullScreen->LockWindowUpdate();
		m_pWndFullScreen->SetWindowPlacement(&wpNew);
		m_pWndFullScreen->UnlockWindowUpdate();
	}
}

void CMainFrame::OnUpdateViewFullscreen(CCmdUI *pCmdUI)
{
	CMDIChildWnd* pWnd = MDIGetActive();
	pCmdUI->Enable(pWnd != NULL);
	pCmdUI->SetCheck(m_pWndFullScreen != NULL);
}

void CMainFrame::OnGetMinMaxInfo(MINMAXINFO* lpMMI)
{
	if (m_pWndFullScreen != NULL)
	{
		lpMMI->ptMaxSize.y = 
 		lpMMI->ptMaxTrackSize.y = m_FullScreenPlace.Height();
		lpMMI->ptMaxSize.x = 
		lpMMI->ptMaxTrackSize.x = m_FullScreenPlace.Width();
	}
	else
		CMDIFrameWnd::OnGetMinMaxInfo(lpMMI);  
}

BOOL CMainFrame::GetFullScreenSize(CWnd* pWnd, POINT& pt) const
{
	if(m_created)
	{
		if (m_pWndFullScreen != NULL && pWnd->m_hWnd == m_pWndFullScreen->m_hWnd)
		{
			pt.x = m_FullScreenPlace.Width();
			pt.y = m_FullScreenPlace.Height();
			pWnd->ScreenToClient(&pt);
		}

#ifdef TRACEFULLSCREEN
		TRACE("FullScreen Size is %d, %d\n", pt.x, pt.y);
#endif //TRACEFULLSCREEN

		return (m_pWndFullScreen != NULL);
	}

	return FALSE;
}
//fullscreen...end

// added by Joseph E. Sutton
void CMainFrame::OnTimer(UINT nIDEvent) 
{
   if(nIDEvent == GAME_LOOP_ID)
   {
      // Game Loop
      tws2005->Loop();

      //KillTimer(nIDEvent);
   }
	CMDIFrameWnd::OnTimer(nIDEvent);
}

void CMainFrame::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	
	CMDIFrameWnd::OnChar(nChar, nRepCnt, nFlags);
}

void CMainFrame::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	
	CMDIFrameWnd::OnKeyDown(nChar, nRepCnt, nFlags);
}

void CMainFrame::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	
	CMDIFrameWnd::OnKeyUp(nChar, nRepCnt, nFlags);
}
