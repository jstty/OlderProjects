// Game SetupDlg.h : header file
//

#if !defined(AFX_GAMESETUPDLG_H__FBF2466D_39B8_400D_BB16_20B2CFF823FA__INCLUDED_)
#define AFX_GAMESETUPDLG_H__FBF2466D_39B8_400D_BB16_20B2CFF823FA__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

/////////////////////////////////////////////////////////////////////////////
// CGameSetupDlg dialog

class CGameSetupDlg : public CDialog
{
// Construction
public:
	CGameSetupDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CGameSetupDlg)
	enum { IDD = IDD_GAMESETUP_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGameSetupDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CGameSetupDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GAMESETUPDLG_H__FBF2466D_39B8_400D_BB16_20B2CFF823FA__INCLUDED_)
