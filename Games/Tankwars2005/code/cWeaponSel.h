#if !defined(AFX_CWEAPONSEL_H__0F1576CA_49B4_4070_BD56_FD801466E3D8__INCLUDED_)
#define AFX_CWEAPONSEL_H__0F1576CA_49B4_4070_BD56_FD801466E3D8__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// cWeaponSel.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// cWeaponSel dialog

class cWeaponSel : public CDialog
{
// Construction
public:
	cWeaponSel(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(cWeaponSel)
	enum { IDD = IDD_WEAPON_SELECTION };
	CListCtrl	m_list;
	//}}AFX_DATA

   int list_pos;

   DWORD list_data;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(cWeaponSel)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
   PlayerData *player_data;

   // temp string
   char stemp[128];

   void UpdateList();

	// Generated message map functions
	//{{AFX_MSG(cWeaponSel)
	virtual void OnOK();
	virtual void OnCancel();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CWEAPONSEL_H__0F1576CA_49B4_4070_BD56_FD801466E3D8__INCLUDED_)
