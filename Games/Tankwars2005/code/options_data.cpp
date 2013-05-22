//////////////////////////////////////////////////////////////////////////////
// Program Name:  options_data.cpp
// Programmer:    Joseph E. Sutton
// Description:	TankWars 2005
// Course:        cs335
// Start Date:    2/14/2005
// Last Updated:  
// Version:       1.00
//////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include "stdafx.h"
#include <io.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#include "tankwars2005.h"
#include "options_data.h"
extern cTankWars2005 *tws2005;

// Global data
char seps[] = " ,\t\n";

//////////////////////////////////////////////
// Constructor
//////////////////////////////////////////////
cOptionsData::cOptionsData()
{ }

cOptionsData::~cOptionsData()
{
   int i;
   for(i = 0; i < pd_list.size(); i++)
   {
      delete pd_list.retrieve(i);
   }

   for(i = 0; i < wd_list.size(); i++)
   {
      delete wd_list.retrieve(i);
   }
}

int cOptionsData::Load()
{
   int rv;
   int fs;
   long size;
   char *buffer;

   // get file size
   if( (fs  = _open("data\\planets.dat", _O_RDONLY )) == NULL )
      return 1;
      
   size = _filelength(fs) + 1;
   buffer = new char[size];
   _read(fs, buffer, size);
   _close( fs );

   rv = LoadPlanet(buffer);
   delete buffer;
   //


   // get file size
   if( (fs  = _open("data\\weapons.dat", _O_RDONLY )) == NULL )
      return 1;
      
   size = _filelength(fs) + 1;
   buffer = new char[size];
   _read(fs, buffer, size);
   _close( fs );

   rv = LoadWeapon(buffer);
   delete buffer;
   //


   return 0;
}

void cOptionsData::FillPlanet(CComboBoxEx *cb)
{
   int i;
   cb->ResetContent();
   COMBOBOXEXITEM cbox;

   for(i = 0; i < pd_list.size(); i++)
   {
      ptemp = pd_list.retrieve(i);
      
      if(ptemp != NULL)
      {
         cbox.mask = CBEIF_TEXT | CBEIF_LPARAM;
         cbox.iItem = i;
         cbox.pszText = ptemp->GetName();
         cbox.cchTextMax =  strlen(ptemp->GetName());
         cbox.lParam = (LPARAM)i;

         cb->InsertItem(&cbox);
      }
   }

}

void cOptionsData::FillWeapon(CListCtrl *list)
{
   int i;
   list->InsertColumn(0, "Name");
   list->InsertColumn(1, "Cost");
   list->InsertColumn(2, "Damage", LVCFMT_LEFT);
   list->InsertColumn(3, "Bought", LVCFMT_CENTER);

   list->SetColumnWidth(0,95);
   list->SetColumnWidth(1,70);
   list->SetColumnWidth(2,60);
   list->SetColumnWidth(3,50);

   //list->SetTextBkColor( RGB(0,0,0) );
   //list->SetTextColor( RGB(255,0,0) );

   for(i = 0; i < wd_list.size(); i++)
   {
      wtemp = wd_list.retrieve(i);
      if(wtemp != NULL)
      {
         list->InsertItem(i, wtemp->name);
      }
   }
}

int cOptionsData::LoadPlanet(char *data)
{
//
   char *pdest;
   int  start, end;
   int  cpos = 0, lpos = 0;
   char *token;
   char *temp = NULL;
   PlanetData *pd;
   bool ok = true;
   int i = 0;

   while(ok)
   {
      // find start and end block
      pdest = strstr(&(data[lpos]), "<planet>");
      if(pdest == NULL){ ok = false; break; }

      start = pdest - data + 1;
      start += 9;

      pdest = strstr(&(data[lpos]), "</planet>");
      end = pdest - data;

      temp = new char[end-start+1];

      memset(temp, 0, end-start+1);
      strncpy(temp, &(data[start]), end-start);

      lpos = end + 11;
      //

      pd = new PlanetData;

      //
      pdest = strchr(temp, '\n');
      end = pdest - temp ;

		// set planet name
		pd->SetName(temp, end);

      cpos = strlen(pd->GetName())+2;
      temp = &(temp[cpos]);
      //

      //
      pdest = strchr(temp, '\n');
      end = pdest - temp ;

		// set planet desc
		pd->SetDesc(temp, end);

      cpos = strlen(pd->GetDesc())+2;
      temp = &(temp[cpos]);
      //

      //
      pdest = strchr(temp, '\n');
      end = pdest - temp ;

		// set planet icon
		pd->SetIcon(temp, end);

      cpos = strlen(pd->GetIcon())+2;
      temp = &(temp[cpos]);
      //

      //
      pdest = strchr(temp, '\n');
      end = pdest - temp ;

		// set planet img
		pd->SetImg(temp, end);

      cpos = strlen(pd->GetImg())+2;
      temp = &(temp[cpos]);
      //

		float a, b, c;
      // token parse data
         // color
         token = strtok(temp, seps);
         a = atoi(token);
         token = strtok(NULL, seps);
         b = atoi(token);
         token = strtok(NULL, seps);
         c = atoi(token);

			pd->SetColor(a, b, c);

         // wind
         token = strtok(NULL, seps);
         a = atof(token);
         token = strtok(NULL, seps);
         b = atof(token);
			token = strtok(NULL, seps);
         c = atof(token);

			pd->SetWind(a, b, c);

         // gravity
         token = strtok(NULL, seps);
			pd->SetGravity( atof(token) );

      //

      pd_list.insert(i, pd);
      i++;
   }

   return 0;
}

int cOptionsData::LoadWeapon(char *data)
{
//
   char *pdest;
   int  start, end;
   int cpos = 0, lpos = 0;
   char *token;
   char *temp;
   WeaponData *wd;
   bool ok = true;
   int i = 0;

   while(ok)
   {
      // find start and end block
      pdest = strstr(&(data[lpos]), "<weapon>");
      if(pdest == NULL){ ok = false; break; }

      start = pdest - data + 1;
      start += 9;

      pdest = strstr(&(data[lpos]), "</weapon>");
      end = pdest - data;

      temp = new char[end-start+1];

      memset(temp, 0, end-start+1);
      strncpy(temp, &(data[start]), end-start);

      lpos = end + 11;
      //

      wd = new WeaponData;

      //
      pdest = strchr(temp, '\n');
      end = pdest - temp ;

      memset(wd->name, 0, 128);
      strncpy(wd->name, temp, end);

      cpos = strlen(wd->name)+2;
      temp = &(temp[cpos]);

      //
      pdest = strchr(temp, '\n');
      end = pdest - temp ;

      memset(wd->icon, 0, 128);
      strncpy(wd->icon, temp, end);

      cpos = strlen(wd->icon)+2;
      temp = &(temp[cpos]);

      // token parse data
         // cost
         token = strtok(temp, seps);
         wd->cost = atof(token);

         // damage
         token = strtok(NULL, seps);
         wd->damage = atof(token);
      //

		wd->index = i;
      wd_list.insert(i, wd);
      i++;
   }

   return 0;
}


void cOptionsData::SetPlayerDefault(unsigned char num)
{
	char temp[128];
   sprintf(temp, "Player %d", num+1);
	pdata[num].DefaultSettings();
   pdata[num].SetAmmoNum( wd_list.size() );
   pdata[num].DefaultAmmo();

   if(num == 0)  pdata[num].SetColor(255, 0, 0);
   else          pdata[num].SetColor(0, 0, 255);

	pdata[num].SetName(temp);
}



PlayerData *cOptionsData::GetPlayer()
{
   return current_player;
}

PlayerData *cOptionsData::GetPlayer(unsigned char num)
{
   return &(pdata[num]);
}

PlayerData *cOptionsData::GetOtherPlayer()
{
   if(current_player_num == 0)
      return &(pdata[1]);
   else
      return &(pdata[0]);
}

WeaponData *cOptionsData::GetWeapon(unsigned char num)
{
   return wd_list.retrieve(num);
}


unsigned char cOptionsData::GetAmmo(unsigned char player_num, unsigned char ammo_num)
{
   return pdata[player_num].GetAmmo(ammo_num);
}

void cOptionsData::UseAmmo(unsigned char player_num, unsigned char ammo_num)
{
	pdata[player_num].UseAmmo( wd_list.retrieve(ammo_num) );
}


void cOptionsData::ResetPlayerAmmo(unsigned char player_num)
{
	pdata[player_num].SetMoney(PLAYER_DEF_MONEY);
	pdata[player_num].SetAmmoNum( wd_list.size() );
}

void cOptionsData::ResetPlayerAmmo()
{
	current_player->SetMoney(PLAYER_DEF_MONEY);
	current_player->SetAmmoNum( wd_list.size() );
}


void cOptionsData::SetCurrentPlanet(unsigned char num)
{
   current_planet_num = num;
   current_planet = pd_list.retrieve(num);
}

unsigned char cOptionsData::GetPlanet_Num()
{
   return current_planet_num;
}

float cOptionsData::GetPlanet_Gravity()
{
   return current_planet->GetGravity();
}

float cOptionsData::GetPlanet_WindSpd()
{
   return current_planet->GetWindSpd();
}

cVector cOptionsData::GetPlanet_WindDir()
{
   return current_planet->GetWindDir();
}

float cOptionsData::UpdatePlanet_WindSpd()
{
   return current_planet->UpdateWindSpd();
}

cVector cOptionsData::UpdatePlanet_WindDir()
{
   return current_planet->UpdateWindDir();
}

const char *cOptionsData::GetPlanet_Name()
{
   return current_planet->GetName();
}

const char *cOptionsData::GetPlanet_Desc()
{
   return current_planet->GetDesc();
}

const char *cOptionsData::GetPlanet_Img()
{
   return current_planet->GetImg();
}

const char *cOptionsData::GetPlanet_Icon()
{
   return current_planet->GetIcon();
}

COLORREF cOptionsData::GetPlanet_Color()
{
   return current_planet->GetColor();
}


PlanetData *cOptionsData::GetPlanet()
{
	return current_planet;
}


void cOptionsData::SetCurrentPlayer(unsigned char num)
{
   current_player_num = num;
   current_player = &(pdata[num]);
}

unsigned char cOptionsData::GetPlayer_Num()
{
	return current_player_num;
}

const char *cOptionsData::GetPlayer_Name()
{
   return current_player->GetName();
}

float cOptionsData::GetPlayer_HP()
{
   return current_player->GetHP();
}

int cOptionsData::GetPlayer_Angle()
{
   return current_player->GetAngle();
}

unsigned int cOptionsData::GetPlayer_Power()
{
   return current_player->GetPower();
}

COLORREF cOptionsData::GetPlayer_Color()
{
   return current_player->GetColor();
}

void cOptionsData::ResetStates()
{
   main_state = DlgBox;
   tank_state = Empty;
   bullet_state = Empty;
}

void cOptionsData::SetMainState(int ms)
{
   main_state = ms;
}

bool cOptionsData::CheckMainState(int cs)
{
   return (main_state == cs) ? true : false;
}

void cOptionsData::SetTankState(int ms)
{
   tank_state = ms;
}

bool cOptionsData::CheckTankState(int cs)
{
   return (tank_state == cs) ? true : false;
}

void cOptionsData::SetBulletState(int ms)
{
   bullet_state = ms;
}

bool cOptionsData::CheckBulletState(int cs)
{
   return (bullet_state == cs) ? true : false;
}


void cOptionsData::SetCurrentWeapon(unsigned char num)
{
   current_weapon_num = num;
   current_weapon = wd_list.retrieve(num);
}

unsigned char cOptionsData::GetWeapon_Num()
{
   return current_weapon_num;
}

float cOptionsData::GetWeapon_Damage()
{
   return current_weapon->damage;
}

float cOptionsData::GetWeapon_Damage(unsigned char num)
{
   return wd_list.retrieve(num)->damage;
}

unsigned char cOptionsData::GetWeapon_Ammo()
{
   return current_player->GetAmmo(current_weapon_num);
}

void cOptionsData::UseWeapon_Ammo()
{
   if( current_player->GetAmmo(current_weapon_num) > 0)
      current_player->UseAmmo(current_weapon);
}

bool cOptionsData::NoAmmo()
{
   unsigned char size = current_player->GetAmmoNum();
   unsigned int sum = 0;
   for(unsigned char i=0; i < size; i++)
   {
      sum += current_player->GetAmmo(i);
   }

   if( sum > 0)   return false;
   else           return true;
}

void cOptionsData::SetPlayer_Lose(unsigned char num)
{
   loser_player_num = num;
}

PlayerData *cOptionsData::GetLoserPlayer()
{
   return &(pdata[ loser_player_num ]);
}