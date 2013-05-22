// cStatusBar.cpp : implementation file
//

#include "stdafx.h"
#include "../pop/pop.h"
#include "cStatusBar.h"
#include "cWeaponSel.h"

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
// cStatusBar dialog


cStatusBar::cStatusBar()
: CDialogBar()
{
	//{{AFX_DATA_INIT(cStatusBar)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void cStatusBar::DoDataExchange(CDataExchange* pDX)
{
	CDialogBar::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(cStatusBar)
	DDX_Control(pDX, IDC_TIME, m_time);
	DDX_Control(pDX, IDC_FIRE, m_fire);
   DDX_Control(pDX, IDC_SELECT_WEAPON, m_weapon_select);
	DDX_Control(pDX, IDC_SPIN_ANGLE, m_angle_ctr);
	DDX_Control(pDX, IDC_WEAPON_NAME, m_weapon);
	DDX_Control(pDX, IDC_POWER_TEXT, m_power_value);
	DDX_Control(pDX, IDC_POWER, m_power);
	DDX_Control(pDX, IDC_ANGLE, m_angle);
	DDX_Control(pDX, IDC_PLANET_INFO, m_planet_info);
	DDX_Control(pDX, IDC_PLAYER_HP, m_player_hp);
	DDX_Control(pDX, IDC_PLAYER_NAME, m_player_name);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(cStatusBar, CDialogBar)
	//{{AFX_MSG_MAP(cStatusBar)
	ON_WM_TIMER()
	ON_BN_CLICKED(IDC_FIRE, OnFire)
   ON_BN_CLICKED(IDC_SELECT_WEAPON, OnSelectWeapon)
	ON_WM_KEYDOWN()
	ON_WM_KEYUP()
	ON_WM_CHAR()
	ON_WM_CLOSE()
	ON_NOTIFY(NM_RELEASEDCAPTURE, IDC_POWER, OnReleasedcapturePower)
	ON_NOTIFY(UDN_DELTAPOS, IDC_SPIN_ANGLE, OnDeltaposSpinAngle)
	ON_WM_CANCELMODE()
	ON_WM_DESTROY()
	ON_WM_SHOWWINDOW()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// cStatusBar message handlers

BOOL cStatusBar::Create(CWnd* pParentWnd, UINT nIDTemplate, UINT nStyle, UINT nID) 
{
   UINT s;
   BOOL rv = CDialogBar::Create(pParentWnd, nIDTemplate, nStyle, nID);

	SetWindowText(STATUS_TITLE);

   // runs DoDataExchange, which initalized the controls handles
   UpdateData(FALSE);

   m_planet_info.ResetContent();
   m_player_name.SetWindowText("");
   m_player_hp.SetWindowText("");
   m_angle.SetWindowText("");
   m_power_value.SetWindowText("");
   m_weapon.SetWindowText("");

   m_power.SetRange(1, 100);
   m_power.SetTicFreq(10);
   m_power.SetPos(1);

	m_angle_ctr.SetBase(10);
	m_angle_ctr.SetRange(1, 90);
   m_angle_ctr.SetPos(1);

	updating_player = false;
   update_weapon = true;
   current_weapon[0] = NULL;
   current_weapon_pos[0] = 0;
   current_weapon[1] = NULL;
   current_weapon_pos[1] = 0;

   m_weapon_select.EnableWindow(true);
   m_fire.EnableWindow(true);

   //
   time_remain = time_max = 30; // in seconds
   timer_started = false;
   //

   s = GetBarStyle();
   SetBarStyle(CBRS_BORDER_ANY | CBRS_ALIGN_TOP | CBRS_SIZE_FIXED);

	return rv;
}

void cStatusBar::OnTimer(UINT nIDEvent) 
{
   /*
   if(m_angle_ctr.GetPos() > 89)
   {
      //options_data->FlipTankFace();
   }
   */

   if(
         options_data->CheckMainState(Move) ||
         options_data->CheckMainState(Fire)
      )
   {
      if( options_data->CheckMainState(Fire) )
      {
         if( options_data->CheckTankState(Weapon_Selection) &&
             !m_fire.IsWindowEnabled() )
         {
            m_fire.SetWindowText("FIRE ! ! !");
            m_fire.EnableWindow(true);
         }
         else if( options_data->CheckTankState(Fired) &&
              m_fire.IsWindowEnabled() ) m_fire.EnableWindow(false);
      }
      else if( options_data->CheckMainState(Move) )
      {
         if( options_data->CheckTankState(Moving) &&
             !m_fire.IsWindowEnabled() )
         {
            m_fire.SetWindowText("DONE ! ! !");
            m_fire.EnableWindow(true);
         }
         else if( options_data->CheckTankState(Fired) &&
              m_fire.IsWindowEnabled() ) m_fire.EnableWindow(false);
      }

      if(!timer_started)   // not started
      {
         timer_started = true;
         StartTimer();
      }

      // timer update
      UpdateTimer();
      if( time_diff > 1000)
      {
         time_remain--;   // subtract one second

		   sprintf(temp, "%d sec", time_remain);
		   m_time.SetWindowText( temp );

         // loop
         if(time_remain < 1)
         {
            ResetTimer();
            timer_started = false;  // stop timer
            options_data->SetMainState(TimesUp);
         }

		   StartTimer();
      }
      //
   }
   else
   {
      if( m_fire.IsWindowEnabled() ) m_fire.EnableWindow(false);
		m_time.SetWindowText("-----");
   }

   // update stats
   // handle weapon update
   if( (update_weapon) && (options_data != NULL))
   {
      if(current_weapon[options_data->GetPlayer_Num()] == NULL) // select first weapon
      {
         current_weapon_pos[options_data->GetPlayer_Num()] = 0;
         current_weapon[options_data->GetPlayer_Num()] = options_data->GetWeapon(0);
         options_data->SetCurrentWeapon( 0 );
      }

      if(current_weapon[options_data->GetPlayer_Num()] != NULL)
      {
         m_weapon.SetWindowText( current_weapon[options_data->GetPlayer_Num()]->name  );
         options_data->SetCurrentWeapon( current_weapon[options_data->GetPlayer_Num()]->index );
      }

      update_weapon = false;
   }
   //

   // handle player and planet update
   if(!updating_player)
	{
		// update from imput
      //m_power.SetPos( pd->GetPower() );
      //m_angle_ctr.SetPos( pd->GetAngle() );
		//pd->SetPower( m_power.GetPos() );
		//pd->SetAngle( m_angle_ctr.GetPos() );
		//

      // name
		m_player_name.SetWindowText( pd->GetName() );

      // HP
		sprintf(temp, "%d / %d", (int)pd->GetHP(), PLAYER_MAX_HP );
		m_player_hp.SetWindowText( temp );

      // Power level
		sprintf(temp, "%d %%", pd->GetPower());
		m_power_value.SetWindowText( temp );

		// planet info
		m_planet_info.ResetContent();
		sprintf(temp, "Wind Dir: %s", (options_data->GetPlanet_WindDir() == WIND_LEFT) ? "<-" : "->" );
		m_planet_info.InsertString(0, temp);

		sprintf(temp, "Wind Speed: %0.2f", options_data->GetPlanet_WindSpd());
		m_planet_info.InsertString(0, temp);
	}
   //

	CDialogBar::OnTimer(nIDEvent);
}

void cStatusBar::UpdatePlayer()
{
	updating_player = true;

	// update controls
	pd = options_data->GetPlayer();

	m_power.SetPos( pd->GetPower() );
	m_angle_ctr.SetPos( pd->GetAngle() );

   UpdateWeapon();

	updating_player = false;
}

void cStatusBar::OnFire()
{
   //cMainState ms;
   //ms.DoModal();
   if( options_data->CheckMainState(Fire) &&
       options_data->CheckTankState(Weapon_Selection) &&
       // check ammo before fire.
       (options_data->GetWeapon_Ammo() > 0) )
   {
	   options_data->SetTankState(Fired);
   }
   else if( options_data->CheckMainState(Move) &&
            options_data->CheckTankState(Moving) )
   {
      options_data->SetMainState(Done);
   }

   m_fire.SetCheck(0);
}

void cStatusBar::ResetTimer()
{
   time_remain = time_max;
}

void cStatusBar::OnSelectWeapon() 
{
	cWeaponSel ws;
   ws.list_pos = current_weapon_pos[options_data->GetPlayer_Num()];
   ws.DoModal();
   m_weapon_select.SetCheck(0);

   current_weapon_pos[options_data->GetPlayer_Num()] = ws.list_pos;
   current_weapon[options_data->GetPlayer_Num()] = (WeaponData *)ws.list_data;
   options_data->SetCurrentWeapon( ws.list_pos );
   
   UpdateWeapon();
}


void cStatusBar::UpdateWeapon()
{
  update_weapon = true;
}


void cStatusBar::StartTimer()
{
   time_start = GetTickCount();
}

void cStatusBar::UpdateTimer()
{
   time_diff = GetTickCount() - time_start;
}


BOOL cStatusBar::OnChildNotify(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pLResult) 
{
   if( lParam != 16318966)
   {
      int i = 0;
   }

	return CDialogBar::OnChildNotify(message, wParam, lParam, pLResult);
}

BOOL cStatusBar::OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult) 
{
	return CDialogBar::OnNotify(wParam, lParam, pResult);
}

// pipe keyboard back to game
void cStatusBar::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	tws2005->onKeyDown(NULL, nChar, nFlags);
	CDialogBar::OnKeyDown(nChar, nRepCnt, nFlags);
}

void cStatusBar::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	tws2005->onKeyUp(NULL, nChar, nFlags);
	CDialogBar::OnKeyUp(nChar, nRepCnt, nFlags);
}

BOOL cStatusBar::OnCommand(WPARAM wParam, LPARAM lParam) 
{
   if( (wParam == 2) && (lParam == 0) ) 
   {
      MessageBox("Test", "Test");
   }

	return CDialogBar::OnCommand(wParam, lParam);
}

void cStatusBar::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
	
	CDialogBar::OnChar(nChar, nRepCnt, nFlags);
}

BOOL cStatusBar::OnCmdMsg(UINT nID, int nCode, void* pExtra, AFX_CMDHANDLERINFO* pHandlerInfo) 
{	
	return CDialogBar::OnCmdMsg(nID, nCode, pExtra, pHandlerInfo);
}

void cStatusBar::OnClose() 
{
	CDialogBar::OnClose();
}

void cStatusBar::OnReleasedcapturePower(NMHDR* pNMHDR, LRESULT* pResult) 
{	
   updating_player = true;

   pd->SetPower( m_power.GetPos() );
	*pResult = 0;

   updating_player = false;
}

void cStatusBar::OnDeltaposSpinAngle(NMHDR* pNMHDR, LRESULT* pResult) 
{
   updating_player = true;

	NM_UPDOWN* pNMUpDown = (NM_UPDOWN*)pNMHDR;
	*pResult = 0;
   pd->SetAngle( m_angle_ctr.GetPos() );

   updating_player = false;
}

BOOL cStatusBar::DestroyWindow() 
{	
	return CDialogBar::DestroyWindow();
}

void cStatusBar::OnFinalRelease() 
{	
	CDialogBar::OnFinalRelease();
}

void cStatusBar::OnCancelMode() 
{
	CDialogBar::OnCancelMode();
	
}

void cStatusBar::OnDestroy() 
{
	CDialogBar::OnDestroy();	
}

void cStatusBar::OnShowWindow(BOOL bShow, UINT nStatus) 
{
	CDialogBar::OnShowWindow(bShow, nStatus);
		
}

void cStatusBar::PostNcDestroy() 
{	
	CDialogBar::PostNcDestroy();
}
