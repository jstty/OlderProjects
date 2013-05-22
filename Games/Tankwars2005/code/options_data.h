//////////////////////////////////////////////////////////////////////////////
// Program Name:  options_data.h
// Programmer:    Joseph E. Sutton
// Description:	TankWars 2005
// Course:        cs335
// Start Date:    2/8/2005
// Last Updated:  
// Version:       1.00
//////////////////////////////////////////////////////////////////////////////
#ifndef _COPTIONSDATA_
#define _COPTIONSDATA_

#include "player_data.h"
#include "planet_data.h"

enum MainState { DlgBox, Waiting, Move, Fire, Pass, TimesUp, Done, Surrender };
enum TankState { Empty, Moving, Weapon_Selection, Fired, _Done };
enum BulletState { _Empty, _Moving, Collided, Exploding, __Done };

class cOptionsData
{
public:
	cOptionsData();
   ~cOptionsData();

   // Init
   int Load();
   void FillPlanet(CComboBoxEx *cb);
   void FillWeapon(CListCtrl *list);
   void SetPlayerDefault(unsigned char num);
   //

   PlayerData *GetPlayer(unsigned char num);

   PlayerData *GetPlayer();      // current player
   PlayerData *GetOtherPlayer(); // not current player
   PlayerData *GetLoserPlayer();
   WeaponData *GetWeapon(unsigned char num);
	PlanetData *GetPlanet();


   // Current Planet
   void SetCurrentPlanet(unsigned char num);
   unsigned char GetPlanet_Num();
   float GetPlanet_Gravity();

   float GetPlanet_WindSpd();
	cVector GetPlanet_WindDir();
   float UpdatePlanet_WindSpd();
	cVector UpdatePlanet_WindDir();

   const char *GetPlanet_Name();
   const char *GetPlanet_Desc();
   const char *GetPlanet_Img();
   const char *GetPlanet_Icon();
   COLORREF GetPlanet_Color();
   //

   // Current Player
   void SetCurrentPlayer(unsigned char num);
	unsigned char GetPlayer_Num();
   const char *GetPlayer_Name();
   float GetPlayer_HP();
   int GetPlayer_Angle();
   unsigned int GetPlayer_Power();
   COLORREF GetPlayer_Color();
	void ResetPlayerAmmo();	// current player
   //

   void SetPlayer_Lose(unsigned char num);

   // Current Weapon for current player
   void SetCurrentWeapon(unsigned char num);
   unsigned char GetWeapon_Num();
   float GetWeapon_Damage();
   unsigned char GetWeapon_Ammo();
   void UseWeapon_Ammo();
   bool NoAmmo(); // current player has not ammo left
   //

   float GetWeapon_Damage(unsigned char num);

	// Battle Fuctions
   void ResetStates();

	void SetMainState(int ms);
	bool CheckMainState(int cs);

	void SetTankState(int ts);
	bool CheckTankState(int cs);

	void SetBulletState(int ts);
   bool CheckBulletState(int cs);
	
   //
   unsigned char GetAmmo(unsigned char player_num, unsigned char ammo_num);
   void          UseAmmo(unsigned char player_num, unsigned char ammo_num);
	void			  ResetPlayerAmmo(unsigned char player_num);

protected:
   int LoadPlanet(char *data);
   int LoadWeapon(char *data);

   unsigned char current_planet_num;
   PlanetData *current_planet;
   List<PlanetData *> pd_list;
   List<WeaponData *> wd_list;

   PlayerData pdata[2];
   unsigned char current_player_num;
   PlayerData *current_player;
   unsigned char loser_player_num;

   unsigned char current_weapon_num;
   WeaponData *current_weapon;


	// Battle States
	int main_state;
	int tank_state;
	int bullet_state;

   // temp
   PlanetData *ptemp;
   WeaponData *wtemp;
};




#endif