//////////////////////////////////////////////////////////////////////////////
// Program Name:  player_data.cpp
// Programmer:    Joseph E. Sutton
// Description:	TankWars 2005
// Course:        cs335
// Start Date:    2/25/2005
// Last Updated:  
// Version:       1.00
//////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "player_data.h"

void PlayerData::DefaultSettings()
{
   memset(name, 0, 127);
   money = PLAYER_DEF_MONEY;
   color[0] = 0; color[1] = 0; color[2] = 0;
   hp = PLAYER_MAX_HP;
   angle = 0;
   power = 0;
}

void PlayerData::DefaultAmmo()
{
   money = 0;
   ammo[0] = 10;
   ammo[1] = 2;
   ammo[2] = 2;
}


void PlayerData::SetName(const char *str)
{
	strncpy(name, str, 127);
}

char *PlayerData::GetName()
{
	return name;
}

void PlayerData::SetColor(int r, int g, int b)
{
	color[0] = r;
	color[1] = g;
	color[2] = b;
}

COLORREF PlayerData::GetColor()
{
	return RGB( color[0], color[1], color[2]);
}

void PlayerData::SetMoney(float m)
{
	money = m;
}

float PlayerData::GetMoney()
{
	return money;
}

unsigned char PlayerData::GetAmmo(int i)
{
	return ammo[i];
}

unsigned char PlayerData::GetAmmoNum()
{
	return ammo_num;
}

void PlayerData::SetAmmoNum(unsigned char num)
{
	ammo_num = num;
	ammo = new unsigned char[ ammo_num ];
   memset(ammo, 0, ammo_num);
}


void PlayerData::SetHP(float nhp)
{
	hp = nhp;
}

float PlayerData::GetHP()
{
	return hp;
}


void PlayerData::Hit(float hit)
{
	if( (hp - hit) > 0)
		hp -= hit;
	else
		hp = 0;
}

void PlayerData::Heal(float heal)
{
	hp += heal;
}


bool PlayerData::BuyAmmo(WeaponData *wd)
{
	if(money >= wd->cost)
	{
		ammo[wd->index]++;
		money -= wd->cost;
		return true;
	}

	return false;
}

bool PlayerData::UseAmmo(WeaponData *wd)
{
	if(ammo[wd->index] > 0)
   {
      ammo[wd->index]--;
      money += wd->cost;
		return true;
   }

	return false;
}

bool PlayerData::SellAmmo(WeaponData *wd)
{
	if(ammo[wd->index] > 0)
   {
      ammo[wd->index]--;
      money += wd->cost;
		return true;
   }

	return false;
}


void PlayerData::SetAngle(int n)
{
   angle = n;
}

int PlayerData::GetAngle()
{
   return angle;
}

void PlayerData::SetPower(unsigned int n)
{
   power = n;
}

unsigned int PlayerData::GetPower()
{
   return power;
}


void PlayerData::GetNameBox(CEdit *box)
{
	if(box != NULL)
		box->GetWindowText(name, 127);
}

void PlayerData::SetNameBox(CEdit *box)
{
	if(box != NULL)
		box->SetWindowText(name);
}

void PlayerData::SetMoneyBox(CEdit *box)
{
	if(box != NULL)
	{
		char stemp[256];
		sprintf(stemp, "$ %0.1f mil.", money);
		box->SetWindowText(stemp);
	}
}

