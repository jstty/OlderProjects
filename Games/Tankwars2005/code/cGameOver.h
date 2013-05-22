#if !defined(AFX_CGAMEOVER_H__AB416203_0BB5_466F_B4B7_082C2F680240__INCLUDED_)
#define AFX_CGAMEOVER_H__AB416203_0BB5_466F_B4B7_082C2F680240__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// cGameOver.h : header file
//

#include "../pop/resource.h"

/////////////////////////////////////////////////////////////////////////////
// cGameOver dialog

class cGameOver : public CDialog
{
// Construction
public:
	cGameOver(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(cGameOver)
	enum { IDD = IDD_GAME_OVER };
	CRichEditCtrl	m_info;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(cGameOver)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(cGameOver)
	afx_msg void OnOk();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CGAMEOVER_H__AB416203_0BB5_466F_B4B7_082C2F680240__INCLUDED_)
