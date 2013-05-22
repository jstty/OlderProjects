// cGameOver.cpp : implementation file
//

#include "stdafx.h"
#include "../pop/pop.h"
#include "cGameOver.h"

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
// cGameOver dialog


cGameOver::cGameOver(CWnd* pParent /*=NULL*/)
	: CDialog(cGameOver::IDD, pParent)
{
	//{{AFX_DATA_INIT(cGameOver)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void cGameOver::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(cGameOver)
	DDX_Control(pDX, IDC_INFO, m_info);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(cGameOver, CDialog)
	//{{AFX_MSG_MAP(cGameOver)
	ON_BN_CLICKED(IDC_OK, OnOk)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// cGameOver message handlers



BOOL cGameOver::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
   //
	CHARFORMAT cf;
	ZeroMemory(&cf, sizeof(CHARFORMAT));
	cf.cbSize = sizeof(CHARFORMAT);
	cf.dwMask = CFM_COLOR | CFM_BOLD;
	cf.dwEffects = CFE_BOLD;
	cf.crTextColor = options_data->GetPlayer_Color();
	m_info.SetDefaultCharFormat(cf);
	m_info.SetBackgroundColor(false, GetSysColor(COLOR_3DFACE));

   char temp[256];
   sprintf(temp, "%s - Lost the Game", options_data->GetPlayer_Name());
	m_info.SetWindowText( temp );
//
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void cGameOver::OnOk() 
{
	CDialog::OnOK();
}