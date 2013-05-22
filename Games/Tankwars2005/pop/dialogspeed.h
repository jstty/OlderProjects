#if !defined(AFX_SPEEDDIALOG_H__962556DD_4A62_11D3_ADCC_000000000000__INCLUDED_)
#define AFX_SPEEDDIALOG_H__962556DD_4A62_11D3_ADCC_000000000000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// dialogspeed.h : header file
//
#include "resource.h"
/////////////////////////////////////////////////////////////////////////////
// cSpeedDialog dialog

class cSpeedDialog : public CDialog
{
// Construction
public:
	cSpeedDialog(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(cSpeedDialog)
	enum { IDD = IDD_SPEED };
	CString	m_cstrUpdatespersecond;
	int		m_nSpeed;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(cSpeedDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(cSpeedDialog)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SPEEDDIALOG_H__962556DD_4A62_11D3_ADCC_000000000000__INCLUDED_)
