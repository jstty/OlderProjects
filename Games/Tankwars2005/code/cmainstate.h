#if !defined(AFX_CMAINSTATE_H__55C04286_4981_4B93_BDC3_FB879DD1E555__INCLUDED_)
#define AFX_CMAINSTATE_H__55C04286_4981_4B93_BDC3_FB879DD1E555__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// cMainState.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// cMainState dialog

class cMainState : public CDialog
{
// Construction
public:
	cMainState(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(cMainState)
	enum { IDD = IDD_MAIN_STATE };
	CRichEditCtrl	m_name;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(cMainState)
	public:
	virtual BOOL DestroyWindow();
	virtual void OnFinalRelease();
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(cMainState)
	afx_msg void OnMove();
	afx_msg void OnFire();
	afx_msg void OnPass();
	virtual BOOL OnInitDialog();
	afx_msg void OnSur();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnClose();
	afx_msg void OnCancelMode();
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CMAINSTATE_H__55C04286_4981_4B93_BDC3_FB879DD1E555__INCLUDED_)
