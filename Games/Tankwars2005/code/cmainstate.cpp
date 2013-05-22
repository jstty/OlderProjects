// cMainState.cpp : implementation file
//

#include "stdafx.h"
#include "../pop/pop.h"
#include "cMainState.h"

#include "tankwars2005.h"
#include "cOptions.h"

extern cTankWars2005 *tws2005;
extern cOptionsData *options_data;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// cMainState dialog


cMainState::cMainState(CWnd* pParent /*=NULL*/)
	: CDialog(cMainState::IDD, pParent)
{
	//{{AFX_DATA_INIT(cMainState)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void cMainState::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(cMainState)
	DDX_Control(pDX, IDC_NAME, m_name);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(cMainState, CDialog)
	//{{AFX_MSG_MAP(cMainState)
	ON_BN_CLICKED(IDC_MOVE, OnMove)
	ON_BN_CLICKED(IDC_FIRE, OnFire)
	ON_BN_CLICKED(IDC_PASS, OnPass)
	ON_BN_CLICKED(IDC_SUR, OnSur)
	ON_WM_KEYDOWN()
	ON_WM_CLOSE()
	ON_WM_CANCELMODE()
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// cMainState message handlers

BOOL cMainState::OnInitDialog() 
{
	CDialog::OnInitDialog();

//
	CHARFORMAT cf;
	ZeroMemory(&cf, sizeof(CHARFORMAT));
	cf.cbSize = sizeof(CHARFORMAT);
	cf.dwMask = CFM_COLOR | CFM_BOLD;
	cf.dwEffects = CFE_BOLD;
	cf.crTextColor = options_data->GetPlayer_Color();
	m_name.SetDefaultCharFormat(cf);
	m_name.SetBackgroundColor(false, GetSysColor(COLOR_3DFACE));

	m_name.SetWindowText( options_data->GetPlayer_Name() );
//

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void cMainState::OnMove() 
{
   options_data->SetMainState(Move);
   options_data->SetTankState(Moving);
   CDialog::OnOK();
}

void cMainState::OnFire() 
{
	options_data->SetMainState(Fire);
   options_data->SetTankState(Weapon_Selection);
   CDialog::OnOK();
}

void cMainState::OnPass() 
{
   options_data->SetMainState(Pass);
   CDialog::OnCancel();
}

void cMainState::OnSur() 
{
   options_data->SetMainState(Surrender);
   CDialog::OnCancel();	
}

void cMainState::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
   if( (nChar == 'f') || (nChar == 'F') )
   {
      OnFire();
   }
   else if( (nChar == 'm') || (nChar == 'M') )
   {
      OnMove();
   }
   else if( (nChar == 'p') || (nChar == 'P') )
   {
      OnPass();
   }
   else if( (nChar == 's') || (nChar == 'S') )
   {
      OnSur();
   }
   
	CDialog::OnKeyDown(nChar, nRepCnt, nFlags);
}

void cMainState::OnClose() 
{	
//	CDialog::OnClose();
}

BOOL cMainState::DestroyWindow() 
{	
	return CDialog::DestroyWindow();
}

void cMainState::OnFinalRelease() 
{
	CDialog::OnFinalRelease();
}

void cMainState::OnCancelMode() 
{
	CDialog::OnCancelMode();
}

void cMainState::OnDestroy() 
{
	CDialog::OnDestroy();
}

BOOL cMainState::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult) 
{
	
	return CDialog::OnNotify(wParam, lParam, pResult);
}

BOOL cMainState::OnCommand(WPARAM wParam, LPARAM lParam) 
{
	if( (wParam == 2) && (lParam == 0) ) 
      OnPass();
   
	return CDialog::OnCommand(wParam, lParam);
}

BOOL cMainState::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo) 
{
	return CDialog::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}
