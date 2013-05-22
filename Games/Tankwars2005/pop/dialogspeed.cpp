// dialogspeed.cpp : implementation file
//

#include "stdafx.h"
#include "dialogspeed.h"
#include "Pop.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// cSpeedDialog dialog


cSpeedDialog::cSpeedDialog(CWnd* pParent /*=NULL*/)
	: CDialog(cSpeedDialog::IDD, pParent)
{
	//{{AFX_DATA_INIT(cSpeedDialog)
	m_cstrUpdatespersecond = _T("");
	m_nSpeed = 0;
	//}}AFX_DATA_INIT
}


void cSpeedDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(cSpeedDialog)
	DDX_Text(pDX, IDC_UPDATESPERSECOND, m_cstrUpdatespersecond);
	DDX_Text(pDX, IDC_SPEED, m_nSpeed);
	DDV_MinMaxInt(pDX, m_nSpeed, 1, 10);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(cSpeedDialog, CDialog)
	//{{AFX_MSG_MAP(cSpeedDialog)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// cSpeedDialog message handlers
