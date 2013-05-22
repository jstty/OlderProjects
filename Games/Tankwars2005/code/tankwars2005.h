//////////////////////////////////////////////////////////////////////////////
// Program Name:  tankwars2005.h
// Programmer:    Joseph E. Sutton
// Description:	TankWars 2005
// Course:        cs335
// Start Date:    2/5/2005
// Last Updated:  
// Version:       1.00
//////////////////////////////////////////////////////////////////////////////

#ifndef _TANKWARS2005_
#define _TANKWARS2005_

#include "levelselector.h"
#include "title_level.h"
#include "battle_level.h"
#include "end_level.h"

#include "../pop/game.h"
#include "../pop/spritepolygon.h"


enum cursor_type {CURSOR_CROSS, CURSOR_ZAP};

#define GAME_LOOP_ID 1111

//======================= cTankWars2005 ================
class cTankWars2005 : public cGame
{
DECLARE_SERIAL(cTankWars2005);
public:
	//See comments where these statics are implemented in gamespacewar.cpp
	static Real WORLDSIZE;

	static Real BULLETRADIUS;
	static int PLAYERHEALTH;

public:
	cTankWars2005();
   ~cTankWars2005();

 	virtual void Serialize(CArchive& ar); //Overload for _lastinvasionscore
	virtual void reset();
	virtual void adjustGameParameters();
	virtual void fixSkyBox();
	virtual void initializeView(CPopView *pview);
	virtual void initializeViewpoint(cCritterViewer *pviewer);
	virtual void seedCritters();
 	virtual void setAutoplay(int autoplay); /* Overload so as to make sure the
		player is using cListenerSpaceship. */


   void onLButtonDown(CPopView *pview, UINT nFlags, CPoint point);
   void onLButtonUp(CPopView *pview, UINT nFlags, CPoint point);
   void onMouseMove(CPopView *pview, UINT nFlags, CPoint point);
   void onKeyDown(CPopView *pview, UINT nChar, UINT nFlags);
   void onKeyUp(CPopView *pview, UINT nChar, UINT nFlags);

   void SetCursor(cursor_type ct);

	cPolyPolygon *LoadPoly(const char filename[]);

	void SetTimer(int ID, int delay, TIMERPROC lpfnTimer);

   // Status Bar
   void ShowStatusBar(bool state);
   void StartStatusBar();
   void StopStatusBar();

	void StatusBar_UpdatePlayer();
   void StatusBar_ResetTimer();

   // Game Loop
   void Loop();

   CPopApp *pop_app;
   cLevelSelector *level_selector;

   //
   cTitleLevel *tlevel;
   cBattleLevel *blevel;
   cEndLevel *elevel;

   cStatusBar *status;

protected:
   CPopView *ppopview;
};

#endif //TANKWARS2005