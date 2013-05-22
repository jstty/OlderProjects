#if !defined(AFX_CSTATUSBAR_H__69C4AF50_157C_496F_B9F5_AAF2FF1DE84D__INCLUDED_)
#define AFX_CSTATUSBAR_H__69C4AF50_157C_496F_B9F5_AAF2FF1DE84D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// cStatusBar.h : header file
//

#include "../pop/resource.h"

#include "player_data.h"

/////////////////////////////////////////////////////////////////////////////
// cStatusBar dialog

class cStatusBar : public CDialogBar
{
// Construction
public:
	cStatusBar();   // standard constructor

// Dialog Data
	//{{AFX_DATA(cStatusBar)
	enum { IDD = IDD_STATUS_BAR };
	CEdit	m_time;
	CButton	m_fire;
   CButton	m_weapon_select;
	CSpinButtonCtrl	m_angle_ctr;
	CEdit	m_weapon;
	CStatic	m_power_value;
	CSliderCtrl	m_power;
	CEdit	m_angle;
	CListBox	m_planet_info;
	CStatic	m_player_hp;
	CStatic	m_player_name;
	//}}AFX_DATA

	void UpdatePlayer();
   void UpdateWeapon();

   void StartTimer();
   void UpdateTimer();

   // timer
   void ResetTimer();
   bool timer_started;

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(cStatusBar)
	public:
	virtual BOOL Create(CWnd* pParentWnd, UINT nIDTemplate, UINT nStyle, UINT nID);
	virtual BOOL OnChildNotify(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pLResult);
	virtual BOOL OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo);
	virtual BOOL DestroyWindow();
	virtual void OnFinalRelease();
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
	virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
	virtual void PostNcDestroy();
	//}}AFX_VIRTUAL


// Implementation
protected:

   bool start_timer;
   DWORD time_max;
   DWORD time_remain;

   char temp[256];
   PlayerData *pd;
	bool updating_player;

   bool update_weapon;
   int current_weapon_pos[2];
   WeaponData *current_weapon[2]; // one for each player

   DWORD time_start;
   DWORD time_diff;

	// Generated message map functions
	//{{AFX_MSG(cStatusBar)
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnFire();
	afx_msg void OnSelectWeapon();
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnClose();
	afx_msg void OnReleasedcapturePower(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnDeltaposSpinAngle(NMHDR* pNMHDR, LRESULT* pResult);
	afx_msg void OnCancelMode();
	afx_msg void OnDestroy();
	afx_msg void OnShowWindow(BOOL bShow, UINT nStatus);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CSTATUSBAR_H__69C4AF50_157C_496F_B9F5_AAF2FF1DE84D__INCLUDED_)
