//////////////////////////////////////////////////////////////////////////////
// Program Name:  tankwars2005.cpp
// Programmer:    Joseph E. Sutton
// Description:	TankWars 2005
// Course:        cs335
// Start Date:    2/5/2005
// Last Updated:  
// Version:       1.00
//////////////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "tankwars2005.h"
#include "options_data.h"

#include "../pop/pop.h"
#include "../pop/popview.h"
#include "../pop/critterviewer.h"

extern cTankWars2005 *tws2005;
cOptionsData *options_data;
extern CPopApp * gpop_app;

IMPLEMENT_SERIAL(cTankWars2005, cGame, 0);


//==============================cTankWars2005
//Size statics.--------------------------------------------------
Real cTankWars2005::BULLETRADIUS = 0.4;
int cTankWars2005::PLAYERHEALTH = 10;
//Other statics --------------------------------------------------


cTankWars2005::~cTankWars2005()
{
   if( level_selector != NULL )
   {
      delete level_selector;
      level_selector = NULL;
   }

   if( options_data != NULL )
   {
      delete options_data;
   }
}


cTankWars2005::cTankWars2005()
{
   srand(time(0));

   // added so we can have Rich Text boxes in the game
	AfxInitRichEdit();
   //

   tws2005 = this;
   pop_app = gpop_app;
   status = pop_app->pMainFrame->main_status;

   level_selector = new cLevelSelector();

   tlevel = new cTitleLevel();
   level_selector->AddLevel(tlevel);

   blevel = new cBattleLevel();
   level_selector->AddLevel(blevel);

   elevel = new cEndLevel();
   level_selector->AddLevel(elevel);

   options_data = new cOptionsData();
   options_data->Load();
   options_data->SetPlayerDefault(0);
   options_data->SetPlayerDefault(1);
   options_data->SetCurrentPlanet(0);

//Fix the menu selections you'll allow.
	_menuflags |= cGame::MENU_AUTOPLAY;
		 //Default _menuflags from cGame as hopper off autoplay off.  Turn on autoplay.
//_menuflags &= ~cGame::MENU_SHAPE;  // Turn off MENU_SHAPE
#ifdef TESTINGALLCONTROLS
	_menuflags |= cGame::MENU_SHAPE;
#endif //TESTINGALLCONTROLS
//Fix your statics
  	cCritter::MAXRADIUS = cTankWars2005::CRITTERMAXRADIUS;
  	cCritter::MAXSPEED = cTankWars2005::CRITTERMAXSPEED;

  	cCritterBullet::BULLETRADIUS = cTankWars2005::BULLETRADIUS;
	cCritterBullet::BULLETSPEED *= 1.1;


   //Set the cursor tools.
  	_arrayHCURSOR.Add(((CPopApp*)::AfxGetApp())->_hCursorPlay);
   _arrayHCURSOR.Add(((CPopApp*)::AfxGetApp())->_hCursorDragger);
   

	// Joseph E. Sutton
	setBorder(35.0, 8.0);

	/********Modifications by John P. Harris ******************/
	//setBorder calls fixSkyBox() whic sets the background stuff,
   setWrapflag(cCritter::CLAMP);

  	//cCritter::BOUNCE turns off wrap to make it easier to shoot things.
   //Make a player
}

void cTankWars2005::seedCritters()
{
}

void cTankWars2005::Loop()
{
   if(level_selector != NULL)
      level_selector->Loop();
}

void cTankWars2005::setAutoplay(int autoplay)
{
/*
	cGame::setAutoplay(autoplay);
	if(autoplay)
		pplayer()->setListener(new cListenerSpaceship());
*/
}

void cTankWars2005::reset()
{
	cGame::reset();
}

void cTankWars2005::onLButtonDown(CPopView *pview, UINT nFlags, CPoint point)
{
   if(level_selector != NULL)
   {
      cVector v = cursorpos();
      level_selector->MouseClick(0, 0, v.x(), v.y());
   }

   cGame::onLButtonDown(pview, nFlags, point);
}

void cTankWars2005::onLButtonUp(CPopView *pview, UINT nFlags, CPoint point)
{
   if(level_selector != NULL)
   {
      cVector v = cursorpos();
      level_selector->MouseClick(0, 1, v.x(), v.y());
   }

   cGame::onLButtonUp(pview, nFlags, point);
}

void cTankWars2005::onMouseMove(CPopView *pview, UINT nFlags, CPoint point)
{
   cGame::onMouseMove(pview, nFlags, point);

   if(level_selector != NULL)
   {
      cVector v = cursorpos();
      level_selector->MouseMoved(v.x(), v.y());
   }
}

void cTankWars2005::onKeyDown(CPopView *pview, UINT nChar, UINT nFlags)
{
   if(pview != NULL)
      cGame::onKeyDown(pview, nChar, nFlags);

   if(level_selector != NULL)
   {
      level_selector->KeyPressed(nChar, nFlags);
   }
}

void cTankWars2005::onKeyUp(CPopView *pview, UINT nChar, UINT nFlags)
{
   if(pview != NULL)
      cGame::onKeyUp(pview, nChar, nFlags);

   if(level_selector != NULL)
   {
      level_selector->KeyUp(nChar, nFlags);
   }
}


#include <afxwin.h>
#include "../pop/graphicsopengl.h"
#include "../pop/graphicsmfc.h"

void cTankWars2005::initializeView(CPopView *pview)
{
	cGame::initializeView(pview);
	pview->setGraphicsClass(RUNTIME_CLASS(cGraphicsOpenGL));
	//pview->setGraphicsClass(RUNTIME_CLASS(cGraphicsMFC));

	//pview->setUseBackground(CPopView::SIMPLIFIED_BACKGROUND);
	pview->setUseBackground(CPopView::FULL_BACKGROUND);

	ppopview = pview;
	SetCursor(CURSOR_CROSS);

	level_selector->FirstLevel();
}

void cTankWars2005::SetCursor(cursor_type ct)
{
   if(ct == CURSOR_CROSS)
      ppopview->setCursor(((CPopApp*)::AfxGetApp())->_hCursorPlay);
   else if(ct == CURSOR_ZAP)
      ppopview->setCursor(((CPopApp*)::AfxGetApp())->_hCursorZap);
}

void cTankWars2005::initializeViewpoint(cCritterViewer *pviewer)
{
   /**************Flattens out 3D John P. Harris *************************/
	pviewer->setViewpoint(cVector3(0.0, 0.0, 0.0), _border.center());
}

void cTankWars2005::fixSkyBox()
{
	cRealBox3 skeleton = _border;
	skeleton.setZRange(-1.0, 1.0);
	cGame::setSkyBox(&skeleton); 
	//Make the walls four shades.

   // Changed: all walls color
   // Modifyed by: Joseph E. Sutton
	pskybox()->setSideSolidColor(LOX, cColorStyle::CN_BLACK);
	pskybox()->setSideSolidColor(HIX, cColorStyle::CN_BLACK);
	pskybox()->setSideSolidColor(LOY, cColorStyle::CN_BLACK);
	pskybox()->setSideSolidColor(HIY, cColorStyle::CN_BLACK);

	//Make floor black
	pskybox()->setSideSolidColor(LOZ, cColorStyle::CN_BLACK);
	//Make the top side transparent
	pskybox()->setSideInvisible(HIZ);
}



void cTankWars2005::adjustGameParameters()
{
   
}
 
void cTankWars2005::Serialize(CArchive& ar)
{
 	cGame::Serialize(ar);

}


#include <fstream.h>
cPolyPolygon *cTankWars2005::LoadPoly(const char filename[])
{
	cPolyPolygon *pp = new cPolyPolygon();

	// temp
	char inChar, chpt[256];
	int i, j;
	int num_polypoly = 0, w = 0, h = 0;
	int num_pts, color[3];
	float offset[2], pts[2];
	cPolygon *ppolygon = NULL;


   ifstream inFs(filename, ios::in );
   if( inFs.fail() )
   {
      cerr << "File could not be opened\n";
      return pp;
   }

   inFs.get(inChar);
   if( !inFs.fail() )
   {
      inFs.putback(inChar);

      inFs >> num_polypoly;
      inFs >> w;
      inFs >> h;
		//pp->setCenter( cVector(w/2, h/2) );

      i = 0;
      while( !inFs.fail() )
      {
         inFs.get(inChar);
         while(inChar == '#')
         {
            inFs.getline(chpt, 255);
            inFs.get(inChar);
         }

         if( (inChar != '\n') && (inChar != '\r') )
         {
            inFs.putback(inChar);
				// number of point in poly
            inFs >> num_pts;
				ppolygon = new cPolygon(num_pts);

				// color
					inFs >> color[0]; // R
					inFs >> color[1]; // G
					inFs >> color[2]; // B
				ppolygon->setFillColor( RGB(color[0], color[1], color[2]) );
				//
            
				// Off Set
					inFs >> offset[0]; // X
					inFs >> offset[1]; // Y
			   //

            for(j = 0; j < num_pts; j++)
            {
					inFs >> pts[0];
					inFs >> pts[1];

					pts[0] += offset[0];
					pts[1] += offset[1];
					ppolygon->setVertex(j, cVector(pts[0], pts[1]));
            }

				pp->add(ppolygon);
            i++;
         }
      }
   }

   inFs.close();
	
	return pp;
}

void cTankWars2005::SetTimer(int ID, int delay, TIMERPROC lpfnTimer)
{
	pop_app->pMainFrame->SetTimer(ID, delay, lpfnTimer);
}


void cTankWars2005::ShowStatusBar(bool state)
{
   pop_app->pMainFrame->ShowControlBar(status, state, false);
}

void cTankWars2005::StartStatusBar()
{
	status->UpdatePlayer();
   ShowStatusBar(true);
   status->SetTimer(1000, 10, NULL);
}

void cTankWars2005::StopStatusBar()
{
   ShowStatusBar(false);
   status->KillTimer(1000);
}

void cTankWars2005::StatusBar_UpdatePlayer()
{
	status->UpdatePlayer();
}

void cTankWars2005::StatusBar_ResetTimer()
{
	status->ResetTimer();
}