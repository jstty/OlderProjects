#if !defined(AFX_COPTIONS_H__42699589_CC4C_407D_8B35_8839F0702439__INCLUDED_)
#define AFX_COPTIONS_H__42699589_CC4C_407D_8B35_8839F0702439__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// cOptions.h : header file
//

#include "slist.h"
#include "options_data.h"

/////////////////////////////////////////////////////////////////////////////
// cOptions dialog

class cOptions : public CDialog
{
// Construction
public:
	cOptions(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(cOptions)
	enum { IDD = IDD_OPTIONS };
	CButton	m_color;
	CStatic	m_planet_desc;
	CEdit	m_money;
	CTabCtrl	m_select_player;
	CEdit	m_player_name;
	CStatic	m_planet_img;
	CComboBoxEx	m_planet;
	CListCtrl	m_list;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(cOptions)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

   int current_player;
   PlayerData *player_data;

   // temp string
   char stemp[128];

   COLORREF CustomColorRGB[16];

   void UpdateList();
   void UpdatePlanet();

   void DrawColorButton();

	// Generated message map functions
	//{{AFX_MSG(cOptions)
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnBuy();
	afx_msg void OnSell();
	virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeSelectPlayer(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnClose();
	afx_msg void OnSelchangingSelectPlayer(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnItemchangedAmmoList(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnSelchangePlanet();
	afx_msg void OnColorButton();
	afx_msg void OnClear();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_COPTIONS_H__42699589_CC4C_407D_8B35_8839F0702439__INCLUDED_)
