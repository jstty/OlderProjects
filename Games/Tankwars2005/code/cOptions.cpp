// cOptions.cpp : implementation file
//

#include "stdafx.h"
#include "../pop/pop.h"

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
// cOptions dialog
cOptions::cOptions(CWnd* pParent /*=NULL*/)
	: CDialog(cOptions::IDD, pParent)
{
	//{{AFX_DATA_INIT(cOptions)
	//}}AFX_DATA_INIT
}


void cOptions::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(cOptions)
	DDX_Control(pDX, IDC_COLOR_BUTTON, m_color);
	DDX_Control(pDX, IDC_PLANET_DESC, m_planet_desc);
	DDX_Control(pDX, IDC_MONEY, m_money);
	DDX_Control(pDX, IDC_SELECT_PLAYER, m_select_player);
	DDX_Control(pDX, IDC_PLAYER_NAME, m_player_name);
	DDX_Control(pDX, IDC_PLANET_IMG, m_planet_img);
	DDX_Control(pDX, IDC_PLANET, m_planet);
	DDX_Control(pDX, IDC_AMMO_LIST, m_list);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(cOptions, CDialog)
	//{{AFX_MSG_MAP(cOptions)
	ON_BN_CLICKED(IDC_BUY, OnBuy)
	ON_BN_CLICKED(IDC_SELL, OnSell)
	ON_NOTIFY(TCN_SELCHANGE, IDC_SELECT_PLAYER, OnSelchangeSelectPlayer)
	ON_WM_CLOSE()
	ON_NOTIFY(TCN_SELCHANGING, IDC_SELECT_PLAYER, OnSelchangingSelectPlayer)
	ON_NOTIFY(LVN_ITEMCHANGED, IDC_AMMO_LIST, OnItemchangedAmmoList)
	ON_CBN_SELCHANGE(IDC_PLANET, OnSelchangePlanet)
	ON_BN_CLICKED(IDC_COLOR_BUTTON, OnColorButton)
	ON_BN_CLICKED(IDC_CLEAR, OnClear)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// cOptions message handlers

BOOL cOptions::OnInitDialog() 
{
	CDialog::OnInitDialog();

   options_data->FillPlanet(&m_planet);
   options_data->FillWeapon(&m_list);

   m_select_player.InsertItem(0, "Player 1");
   m_select_player.InsertItem(1, "Player 2");
   m_select_player.SetCurSel(0);

   current_player = 0;
   options_data->SetCurrentPlayer(current_player);
   player_data = options_data->GetPlayer();

   // update play info
 	player_data->SetMoneyBox(&m_money);
	player_data->SetNameBox(&m_player_name);

   // update list
   m_list.SetSelectionMark(0);
   UpdateList();

   // update list
   UpdatePlanet();

   //
   DrawColorButton();

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void cOptions::OnOK() 
{
   // copy Planet to level data
      //current_planet
   //

   // current save name
	player_data->GetNameBox(&m_player_name);
	
	CDialog::OnOK();
}

void cOptions::OnCancel() 
{
   options_data->SetCurrentPlanet(0);
	options_data->SetPlayerDefault(0);
   options_data->SetPlayerDefault(1);

   // update play info
   player_data->SetMoneyBox(&m_money);
	player_data->SetNameBox(&m_player_name);

   // update list
   m_list.SetSelectionMark(0);
   UpdateList();

   //
   UpdatePlanet();
	
	//CDialog::OnCancel();
}

void cOptions::OnBuy() 
{
   int pos = m_list.GetSelectionMark();
   // get pos

   WeaponData *wd = (WeaponData *)m_list.GetItemData(pos);
	if( player_data->BuyAmmo(wd) )
	{
		// update money box
			player_data->SetMoneyBox(&m_money);

      // update list
         UpdateList();
	}
}

void cOptions::OnSell() 
{
	int pos = m_list.GetSelectionMark();
   // get pos

   WeaponData *wd = (WeaponData *)m_list.GetItemData(pos);
   if( player_data->SellAmmo(wd) )
   {
      // update money box
      player_data->SetMoneyBox(&m_money);

      // update list
      UpdateList();
   }
}


void cOptions::OnSelchangeSelectPlayer(NMHDR* pNMHDR, LRESULT* pResult) 
{
	current_player = m_select_player.GetCurSel();
   options_data->SetCurrentPlayer(current_player);
   player_data = options_data->GetPlayer();

   // update player info
   player_data->SetMoneyBox(&m_money);
	player_data->SetNameBox(&m_player_name);


   // update list
   UpdateList();
   //

   //
   DrawColorButton();
	
	*pResult = 0;
}

void cOptions::OnClose() 
{  
	CDialog::OnCancel();
}

void cOptions::OnSelchangingSelectPlayer(NMHDR* pNMHDR, LRESULT* pResult) 
{
   current_player = m_select_player.GetCurSel();
   options_data->SetCurrentPlayer(current_player);
   player_data = options_data->GetPlayer();

   // save name
	player_data->GetNameBox(&m_player_name);

   
	*pResult = 0;
}


void cOptions::UpdateList()
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

void cOptions::OnItemchangedAmmoList(NMHDR* pNMHDR, LRESULT* pResult) 
{
	NM_LISTVIEW* pNMListView = (NM_LISTVIEW*)pNMHDR;

	*pResult = 0;
}

void cOptions::OnSelchangePlanet() 
{
   int pos = m_planet.GetCurSel();
   
   COMBOBOXEXITEM cbox;
   cbox.mask = CBEIF_LPARAM;
   cbox.iItem = pos;
   m_planet.GetItem(&cbox);
   options_data->SetCurrentPlanet( (int)cbox.lParam );

   //
   UpdatePlanet();
}

void cOptions::UpdatePlanet()
{
   // find options data with planet number
   unsigned char pn = options_data->GetPlanet_Num();
   int count = m_planet.GetCount();
   for(int i = 0; i < count; i++)
   {
      if( pn == m_planet.GetItemData(i))
      {
         m_planet.SetCurSel(i);
         break;
      }
   }
   //

   m_planet_desc.SetWindowText( options_data->GetPlanet_Desc() );
   //

   // update planet icon
   HBITMAP hbitmap = (HBITMAP)LoadImage(NULL, options_data->GetPlanet_Icon(), IMAGE_BITMAP, 48, 48, LR_LOADFROMFILE);
   m_planet_img.SetBitmap(hbitmap);
}


void cOptions::DrawColorButton() 
{
	CDC *pDC = GetDC();
	
	RECT rect;
	HBRUSH hbrush;
	HBITMAP hBitmap;

	HDC DCBitmap = CreateCompatibleDC(pDC->m_hDC);
	HGDIOBJ OldhBitmap;

	m_color.GetWindowRect(&rect);
	hBitmap = CreateCompatibleBitmap(pDC->m_hDC, rect.right - rect.left, rect.bottom - rect.top);
	OldhBitmap = SelectObject(DCBitmap, hBitmap);
	hbrush = CreateSolidBrush( player_data->GetColor() );

	RECT r = {0,0,0,0};
	r.right = rect.right - rect.left;
	r.bottom = rect.bottom - rect.top;

	FillRect(DCBitmap, &r, hbrush);
	m_color.SetBitmap(hBitmap);

	SelectObject(DCBitmap, OldhBitmap);
	DeleteDC(DCBitmap);
}

void cOptions::OnColorButton() 
{
   CColorDialog Color(player_data->GetColor(), CC_ANYCOLOR | CC_SOLIDCOLOR | CC_FULLOPEN);
	Color.m_cc.lpCustColors = CustomColorRGB;

	if(Color.DoModal() == IDOK) 
	{
		player_data->SetColor( GetRValue(Color.GetColor()), GetGValue(Color.GetColor()), GetBValue(Color.GetColor()) );

		for(int i = 0; i < 16 ; i++)
		{
			CustomColorRGB[i] = Color.m_cc.lpCustColors[i];
		}
	}

   DrawColorButton();
}

void cOptions::OnClear() 
{
	// resets all weapons
	options_data->ResetPlayerAmmo();

	// update money box
	player_data->SetMoneyBox(&m_money);

	// update list
	UpdateList();
}
