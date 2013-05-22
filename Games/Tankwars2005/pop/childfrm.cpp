// ChildFrm.cpp : implementation of the CChildFrame class
//

#include "stdafx.h"
#include "Mainfrm.h" // RR. Need this to call getMDIChildCount in ActivateFrame
#include "ChildFrm.h"

#ifdef STATIC_SPLITTER
#include "popdoc.h"
#include "popview.h"
#include ".\childfrm.h"
#endif //STATIC_SPLITTER

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CChildFrame

IMPLEMENT_DYNCREATE(CChildFrame, CMDIChildWnd)

BEGIN_MESSAGE_MAP(CChildFrame, CMDIChildWnd)
	//{{AFX_MSG_MAP(CChildFrame)
	ON_WM_SIZE()
	ON_WM_CANCELMODE()
	ON_WM_CREATE()
	ON_WM_CAPTURECHANGED()
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
	ON_WM_GETMINMAXINFO()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CChildFrame construction/destruction

CChildFrame::CChildFrame()
{
#ifdef STATIC_SPLITTER
	_splittercreated = FALSE;
#endif STATIC_SPLITTER
	_spliton = FALSE;
}

CChildFrame::~CChildFrame()
{
}

BOOL CChildFrame::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	if( !CMDIChildWnd::PreCreateWindow(cs) )
		return FALSE;
#define KILLTITLE
/* KILLTITLE turns off the caption bars on the child windows.  This
makes the Fullscreen mode work more smoothly, but it breaks tiling
of windows. */
cs.style = WS_CHILD | WS_VISIBLE | WS_OVERLAPPED  
#ifdef KILLTITLE
		;  // | WS_DLGFRAME;
#else //don't KILLTITLE
		 | WS_CAPTION | WS_SYSMENU |
		FWS_ADDTOTITLE | WS_THICKFRAME |
		WS_MINIMIZEBOX | WS_MAXIMIZEBOX;
#endif //KILLTITLE

	return TRUE;
}

void CChildFrame::ActivateFrame(int nCmdShow)
{
	//My code.  RR.
	int viewcount = ((CMainFrame*)::AfxGetMainWnd())->getMDIChildCount();
 /* Gets the number of existing children, including this one.   */
	if (viewcount == 1) //This is the only view
		nCmdShow = SW_SHOWMAXIMIZED; 
	//Base class code.
	CMDIChildWnd::ActivateFrame(nCmdShow);
}


/////////////////////////////////////////////////////////////////////////////
// CChildFrame diagnostics

#ifdef _DEBUG
void CChildFrame::AssertValid() const
{
	CMDIChildWnd::AssertValid();
}

void CChildFrame::Dump(CDumpContext& dc) const
{
	CMDIChildWnd::Dump(dc);
}

#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CChildFrame message handlers


BOOL CChildFrame::OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext) 
{
	// When adding a splitter, be sure to comment out the base class code.  RR.
	// CMDIChildWnd::OnCreateClient(lpcs, pContext);
#ifdef STATIC_SPLITTER
	if (!_cSplitterWnd.CreateStatic(this, 1, 2))//1 row, 2 columns
		return FALSE;	
/* We create the pane views.  Since we are setting 1 row and two columns, the 
	only size setting you can make here that will have an effect is the width
	of the first pane.  The heights will always be the whole window, and
	the second pane will take whatever width the first doesn't use. If you use a
	GetClientRect here to find out the size of the ChildFrame, you'll get something
	inanaccurate, as the ChildFrame isn't yet sized inside this call. 
		But you can put in a raw pixel value like for the width if you like.
	 Since I want a resolution independent value, I'll assume I'm using a fullscreen
	window and use LEFT_PANE_PECENT, which I #define in stdafx.h.
		To make this pecent stay the same when I resize the window, I can
	get fancy and add a handler for ChildFrame::OnSize
	and use CSplitter::WndSetColumnInfo there, being careful not to call it unless
	_splittercreated is TRUE, meaning that the splitter and panes are ready. */
	int leftpanewidth = int(LEFT_PANE_PERCENT * GetSystemMetrics(SM_CXFULLSCREEN));
//This is a spot where we might choose two different kinds of views if we liked.
	_cSplitterWnd.CreateView(0,0,RUNTIME_CLASS(CPopView), CSize(leftpanewidth, 0),
		pContext);
	_cSplitterWnd.CreateView(0,1,RUNTIME_CLASS(CPopView), CSize(0,0), pContext);
	_cSplitterWnd.RecalcLayout(); /* You need to call RecalcLayout or the CSize
		setting in the first CreateView call won't have any effect. */
	_splittercreated = TRUE; /* Only set this to TRUE after you've crated the
		splitter and all of its panes. */
	return TRUE;
#else //Dynamic splitter
		/* Pass this pointer, the max number of rows (1 or 2), the max number
		of columns (1 or 2), and an (x,y) size of at which you want a pane to
		just disappear,  the pContext variable, and a flags variable. This selects
		the default view type that was specified for the CMultiDocTemplate
		in the CPopApp::InitInstance method in the pop.cpp file.*/ 
		_spliton = TRUE;
	return  _cSplitterWnd.Create(this, 1, 2, CSize(20, 20), pContext,
		WS_CHILD | WS_VISIBLE | SPLS_DYNAMIC_SPLIT); /* The default includes
		|WS_HSCROLL | WS_VSCROLL in the sixth argument, but I don't want it here. */
#endif //STATIC_SPLITTER
}

void CChildFrame::OnSize(UINT nType, int cx, int cy) 
{
	CMDIChildWnd::OnSize(nType, cx, cy);

#ifdef STATIC_SPLITTER	
	 /* Never call something like SetColumnInfo until after the panes are fully 
	initialized with calls to CreateView. Note that we don't call this at all
	in the Dynamic Splitter case where STATIC_SPLITTER is not defined. The
	last argument to SetColumnInfo specifies a minimum width below which the
	column disappears. */
	if (_splittercreated)
	{
		int actualwidth = cx - 3*::GetSystemMetrics(SM_CXFRAME);/* Use
			global GetSystemMetrics to find size to subtract off for the splitter
			bar. */
		_cSplitterWnd.SetColumnInfo(0, int(LEFT_PANE_PERCENT*actualwidth), 10);
		_cSplitterWnd.RecalcLayout();
	}
#endif //STATIC_SPLITTER
}

void CChildFrame::OnDestroy() 
{
	CMDIChildWnd::OnDestroy();
	
	// TODO: Add your message handler code here
	//My Code.  RR.
	/* This extra code is to make the autotiling feature work.  This view is
	being killed as part of the death of the ChildFrame around it.  The question
	is, after this view's ChildFrame goes away, will there be exactly one 
	ChildFrame remaining?  If there will be exactly one of them left, then we
	should maximize it, otherwise we should tile. We distinguish these cases
	using the getMDIChildCount helper I added to the CMainFrame.  When we
	get inside here, this childframe is already gone as far as CMainFrame is
	concerned, so the crucial case getMDIChildCount() == 1 */

	CMainFrame* mainframe = (CMainFrame*)::AfxGetMainWnd();
	int count;
	if (mainframe->_autotile) //Use the MDI client area efficiently.
	{
		if ( (count = mainframe->getMDIChildCount()) == 1) 
		{ //Case where one ChildFrame will remain after this one dies.
			mainframe->MDINext();
			mainframe->MDIMaximize(mainframe->MDIGetActive());
		}
		else //Case where no, or more than one, ChildFramae will remains.
			mainframe->MDITile(MDITILE_VERTICAL);
	}	
}

//fullscreen...start
void CChildFrame::OnGetMinMaxInfo(MINMAXINFO* lpMMI)
{
	if (_spliton)
	{
		CMainFrame* pFrame = (CMainFrame*) AfxGetApp()->m_pMainWnd;

		POINT pt;

		if (pFrame->GetFullScreenSize(this, pt))
		{
			ClientToScreen(&pt);
			lpMMI->ptMaxSize = pt;
			lpMMI->ptMaxTrackSize = pt;
		}
		else
			CMDIChildWnd::OnGetMinMaxInfo(lpMMI);
	}
}
//fullscreen...end