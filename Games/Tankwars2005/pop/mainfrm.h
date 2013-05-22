// MainFrm.h : interface of the CMainFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_MAINFRM_H__89C2B649_322E_11D3_AD90_000000000000__INCLUDED_)
#define AFX_MAINFRM_H__89C2B649_322E_11D3_AD90_000000000000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "../code/cStatusBar.h"

class CMainFrame : public CMDIFrameWnd
{
	DECLARE_DYNAMIC(CMainFrame)
public:
	CMainFrame();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMainFrame)
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CMainFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	BOOL GetFullScreenSize(CWnd* pWnd, POINT& pt) const; //fullscreen

   // added by: Joseph E. Sutton
   // for battle level
   cStatusBar  *main_status;

protected:  // control bar embedded members
//	CStatusBar  m_wndStatusBar;
//	CToolBar    m_wndToolBar;

	//fullscreen....start
	CWnd*		m_pWndFullScreen;
	WINDOWPLACEMENT m_PreviousPlace;
	WINDOWPLACEMENT m_MainPreviousPlace;
	CRect		m_FullScreenPlace;
	CRect		m_MainFullScreenPlace;
	BOOL m_bHadToolBar;
	BOOL m_bHadStatusBar;
	BOOL m_created;
	//fullscreen....end

// Generated message map functions
protected: 
	//{{AFX_MSG(CMainFrame)
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnWindowNew();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnWindowAutotile();
	afx_msg void OnUpdateWindowAutotile(CCmdUI* pCmdUI);
	afx_msg void OnWindowAutofocus();
	afx_msg void OnUpdateWindowAutofocus(CCmdUI* pCmdUI);
	afx_msg void OnClose();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
//User written code.  RR.
public:  //So that the CView and CDoc can see these.
	BOOL _autotile; /* If this is TRUE, then( a) when there are more than one MDI child frame
		 open, we automatically call MDITile so as to keep all open MDI children
		tiled into the window and (b) when there is only one MDI child open, we keep
		that view maximized.  The net result of using _autotile is that you never
		ever see the blank dull gray MDI client window except when all views are
		closed. Our default sets this to TRUE. We use it in CMainFrame::OnSize,
		in CMainFrame::OnWindowNew, and in the two methods mentioned just below. */
	BOOL _autofocus;  /* If this is on, the focus automatically shifts to whatever
		window the cursor is over.  This is convenient for multiple-view games,
		but inconvenient if you have more than one document open because then
		it's hard to give a window the focus and move the cursor to the menu bar
		//without having the focus change. */
	int getMDIChildCount();

	//fullscreen...start
	afx_msg void OnViewFullscreen();
	afx_msg void OnUpdateViewFullscreen(CCmdUI *pCmdUI);
	afx_msg void OnGetMinMaxInfo(MINMAXINFO* lpMMI);
	void EscapeFullScreen(void);
	//fullscreen...end
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAINFRM_H__89C2B649_322E_11D3_AD90_000000000000__INCLUDED_)
