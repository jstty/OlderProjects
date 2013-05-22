// ChildFrm.h : interface of the CChildFrame class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_CHILDFRM_H__89C2B64B_322E_11D3_AD90_000000000000__INCLUDED_)
#define AFX_CHILDFRM_H__89C2B64B_322E_11D3_AD90_000000000000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/* Comment STATIC_SPLITTER out to have a dynamic (user selectable) splitter
window rather than a static (automatically present) splitter window.  If
we have STATIC_SPLITTER, then we use LEFT_PANE_PERCENT to specify how much
of the width between 0.0 and 1.0 of the child frame window is devoted to the left pane. 
In biota.cpp, we define some deafault real number width and height for the world
being depicted in our window.  Our code is written so that the actual sizes of
these numbers doesn't matter, but their ratio to each other does matter. 
If you turn STATIC_SPLITTER on, then you need to reset these default ratio
to get the best use of yoru window.*/
//#define STATIC_SPLITTER
#define LEFT_PANE_PERCENT 0.5

class CChildFrame : public CMDIChildWnd
{
	DECLARE_DYNCREATE(CChildFrame)
public:
	CChildFrame();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CChildFrame)
	public:
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	virtual void ActivateFrame(int nCmdShow);
	protected:
	virtual BOOL OnCreateClient(LPCREATESTRUCT lpcs, CCreateContext* pContext);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CChildFrame();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

// Generated message map functions
protected:
	//{{AFX_MSG(CChildFrame)
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
//Human code starts here.  RR.
protected: 
	CSplitterWnd _cSplitterWnd;
#ifdef STATIC_SPLITTER
	BOOL _splittercreated;  /* We use this to be careful not do anything 
		involving resizing or looking at panes before the splitter and its
		panes have been fully initialized by a call to CreateStatic
		in ChildFrame::OnCreateClient. */
#endif //STATIC_SPLITTER
	BOOL _spliton;
public:
	afx_msg void OnGetMinMaxInfo(MINMAXINFO* lpMMI);
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CHILDFRM_H__89C2B64B_322E_11D3_AD90_000000000000__INCLUDED_)
