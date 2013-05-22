// cWeaponSel.cpp : implementation file
//

#include "stdafx.h"
#include "..\pop\pop.h"
#include "cWeaponSel.h"

#include "tankwars2005.h"
#include "options_data.h"
extern cTankWars2005 *tws2005;
extern cOptionsData *options_data;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// cWeaponSel dialog


cWeaponSel::cWeaponSel(CWnd* pParent /*=NULL*/)
	: CDialog(cWeaponSel::IDD, pParent)
{
	//{{AFX_DATA_INIT(cWeaponSel)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void cWeaponSel::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(cWeaponSel)
	DDX_Control(pDX, IDC_AMMO_LIST, m_list);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(cWeaponSel, CDialog)
	//{{AFX_MSG_MAP(cWeaponSel)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// cWeaponSel message handlers

void cWeaponSel::OnOK() 
{
	list_pos = m_list.GetSelectionMark();
   list_data = m_list.GetItemData(list_pos);
	CDialog::OnOK();
}

void cWeaponSel::OnCancel() 
{
	CDialog::OnCancel();
}

BOOL cWeaponSel::OnInitDialog() 
{
	CDialog::OnInitDialog();

   player_data = options_data->GetPlayer();
   options_data->FillWeapon(&m_list);
   UpdateList();

   m_list.SetSelectionMark(list_pos);
   list_data = m_list.GetItemData(list_pos);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void cWeaponSel::UpdateList()
{
   WeaponData *wd;
   for(int i = 0; i < player_data->GetAmmoNum(); i++)
   {
      wd = options_data->GetWeapon(i);

      m_list.SetItem(i, 0, LVIF_TEXT, wd->name, 0, 0, 0, NULL);

      sprintf(stemp, "$ %0.1f mil.", wd->cost);
      m_list.SetItem(i, 1, LVIF_TEXT, stemp, 0, 0, 0, NULL);

      sprintf(stemp, "%0.1f", wd->damage);
      m_list.SetItem(i, 2, LVIF_TEXT, stemp, 0, 0, 0, NULL);

      sprintf(stemp, "%d", player_data->GetAmmo(i));
      m_list.SetItem(i, 3, LVIF_TEXT, stemp, 0, 0, 0, NULL);

      m_list.SetItemData(i, (DWORD)wd);
   }
}
