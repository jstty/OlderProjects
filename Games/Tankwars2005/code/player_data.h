//////////////////////////////////////////////////////////////////////////////
// Program Name:  player_data.h
// Programmer:    Joseph E. Sutton
// Description:	TankWars 2005
// Course:        cs335
// Start Date:    2/8/2005
// Last Updated:  
// Version:       1.00
//////////////////////////////////////////////////////////////////////////////
#ifndef _CPLAYERDATA_
#define _CPLAYERDATA_

#define PLAYER_MAX_HP		1000
#define PLAYER_DEF_MONEY   120

struct WeaponData
{
	int index;
   char name[128];
   char icon[128];
   float cost;
   float damage;
};


class PlayerData
{
public:
   void DefaultSettings();
   void DefaultAmmo();

	void SetName(const char *str);
	char *GetName();

	void SetColor(int r, int g, int b);
	COLORREF GetColor();

	void SetMoney(float m);
	float GetMoney();

	unsigned char GetAmmo(int i);
	unsigned char GetAmmoNum();
	void SetAmmoNum(unsigned char num);
	bool UseAmmo(WeaponData *wd);
	bool SellAmmo(WeaponData *wd);
	bool BuyAmmo(WeaponData *wd);

	void SetHP(float nhp);
	float GetHP();
	void Hit(float hit);
	void Heal(float heal);

   void SetAngle(int n);
	int GetAngle();

   void SetPower(unsigned int n);
	unsigned int GetPower();

	void SetNameBox(CEdit *box);
	void GetNameBox(CEdit *box);
	void SetMoneyBox(CEdit *box);

protected:
   char name[128];
   int  color[3];
   float money;
   unsigned char ammo_num; // number of ammos
   unsigned char *ammo;
	float hp;

   signed int angle;
   unsigned int power;
};

#endif