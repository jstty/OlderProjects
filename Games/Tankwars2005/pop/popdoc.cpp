// PopDoc.cpp : implementation of the CPopDoc class
//

#include "stdafx.h"
#include "popdoc.h"
#include "Childfrm.h" /* Put this here so popdoc.h can see the 
	STATIC_SPLITTER switch in Childfrm.h to use in setting START_WORLD_WIDTH */
#include "critterarmed.h"

#include "../code/tankwars2005.h"

#include "listener.h"
#include "Pop.h" 

//=============== cPopDoc const Statics ========================
 const int CPopDoc::VIEWHINT_STARTGAME = 1;//Don't use 0, as that's the default viewhint
 const int CPopDoc::VIEWHINT_LOADINGARCHIVE = 2;

//=============Defines 

//#define TRACETIMESTEPANOMALIES
/* When you run the cGraphicsMFC mode in high pixel resolution with 3 bytes or more per pixel the
BitBlt and PatBlt cost seems to be high enough so that you have a little glitch or jerk in the 
update every so often.  There's also some sluggish behavior when this happens.  This switch helps
trace when it happens. Apparently you can get rid of the glitch by not drawing a background,
see cGraphicsMFC::rectangle in graphicsmfc.cpp. */

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPopDoc

IMPLEMENT_DYNAMIC(cTimeHint, CObject)
IMPLEMENT_DYNAMIC(cArchiveHint, CObject)
IMPLEMENT_DYNCREATE(CPopDoc, CDocument)


BEGIN_MESSAGE_MAP(CPopDoc, CDocument)
	//{{AFX_MSG_MAP(CPopDoc)
	ON_COMMAND(ID_GAME_HUGE, OnGameHuge)
	ON_UPDATE_COMMAND_UI(ID_GAME_HUGE, OnUpdateGameHuge)
	ON_COMMAND(ID_GAME_LARGE, OnGameLarge)
	ON_UPDATE_COMMAND_UI(ID_GAME_LARGE, OnUpdateGameLarge)
	ON_COMMAND(ID_GAME_MEDIUM, OnGameMedium)
	ON_UPDATE_COMMAND_UI(ID_GAME_MEDIUM, OnUpdateGameMedium)
	ON_COMMAND(ID_GAME_SMALL, OnGameSmall)
	ON_UPDATE_COMMAND_UI(ID_GAME_SMALL, OnUpdateGameSmall)
	ON_COMMAND(ID_GAME_RESTART, OnGameRestart)
	ON_COMMAND(ID_FILE_SEED_FANCYPOLYGONS, OnGameFancypolygons)
	ON_COMMAND(ID_FILE_SEED_POLYPOLYGONS, OnGamePolypolygons)
	ON_COMMAND(ID_FILE_SEED_SIMPLEPOLYGONS, OnGameSimplepolygons)
	ON_COMMAND(ID_GAME_TRIPLEPOLYPOLYGONS, OnGameTriplepolypolygons)
	ON_COMMAND(ID_EDIT_COPY, OnEditCopy)
   ON_COMMAND(ID_GAME_ASTEROIDS, OnGameAsteroids)
   ON_UPDATE_COMMAND_UI(ID_GAME_ASTEROIDS, OnUpdateGameAsteroids)
	ON_UPDATE_COMMAND_UI(ID_EDIT_COPY, OnUpdateEditCopy)
	ON_COMMAND(ID_EDIT_CUT, OnEditCut)
	ON_UPDATE_COMMAND_UI(ID_EDIT_CUT, OnUpdateEditCut)
	ON_COMMAND(ID_EDIT_PASTE, OnEditPaste)
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE, OnUpdateEditPaste)
	ON_COMMAND(ID_GAME_BITMAPS, OnGameBitmaps)
	ON_UPDATE_COMMAND_UI(ID_GAME_BITMAPS, OnUpdateGameBitmaps)
	ON_COMMAND(ID_GAME_ASSORTED, OnGameAssorted)
	ON_UPDATE_COMMAND_UI(ID_GAME_ASSORTED, OnUpdateGameAssorted)
	ON_COMMAND(ID_GAME_WRAP, OnGameWrap)
	ON_UPDATE_COMMAND_UI(ID_GAME_WRAP, OnUpdateGameWrap)
	ON_UPDATE_COMMAND_UI(ID_GAME_TRIPLEPOLYPOLYGONS, OnUpdateGameTriplepolypolygons)
	ON_UPDATE_COMMAND_UI(ID_FILE_SEED_FANCYPOLYGONS, OnUpdateGameFancypolygons)
	ON_UPDATE_COMMAND_UI(ID_FILE_SEED_POLYPOLYGONS, OnUpdateGamePolypolygons)
	ON_UPDATE_COMMAND_UI(ID_FILE_SEED_SIMPLEPOLYGONS, OnUpdateGameSimplepolygons)
	ON_COMMAND(ID_PLAYER_3DFLYER, OnPlayerFlykeys)
	ON_UPDATE_COMMAND_UI(ID_PLAYER_3DFLYER, OnUpdatePlayerFlykeys)
	ON_COMMAND(ID_PLAYER_CARKEYS, OnPlayerCarkeys)
	ON_UPDATE_COMMAND_UI(ID_PLAYER_CARKEYS, OnUpdatePlayerCarkeys)
	ON_COMMAND(ID_PLAYER_SPACESHIPKEYS, OnPlayerSpaceshipkeys)
	ON_UPDATE_COMMAND_UI(ID_PLAYER_SPACESHIPKEYS, OnUpdatePlayerSpaceshipkeys)
	ON_COMMAND(ID_PLAYER_GODMODE, OnPlayerShield)
	ON_UPDATE_COMMAND_UI(ID_PLAYER_GODMODE, OnUpdatePlayerShield)
	ON_UPDATE_COMMAND_UI(ID_PLAYER_RUBBERBULLETS, OnUpdatePlayerRubberbullets)
	ON_COMMAND(ID_PLAYER_RUBBERBULLETS, OnPlayerRubberbullets)
	ON_UPDATE_COMMAND_UI(ID_PLAYER_DEADLYBULLETS, OnUpdatePlayerDeadlybullets)
	ON_COMMAND(ID_PLAYER_DEADLYBULLETS, OnPlayerDeadlybullets)
	ON_COMMAND(ID_PLAYER_MASSIVEPLAYER, OnPlayerMassiveplayer)
	ON_UPDATE_COMMAND_UI(ID_PLAYER_MASSIVEPLAYER, OnUpdatePlayerMassiveplayer)
	ON_COMMAND(ID_PLAYER_ABSORBERPLAYER, OnPlayerAbsorberplayer)
	ON_UPDATE_COMMAND_UI(ID_PLAYER_ABSORBERPLAYER, OnUpdatePlayerAbsorberplayer)
	ON_COMMAND(ID_PLAYER_BOUNCINGPLAYER, OnPlayerBouncingplayer)
	ON_UPDATE_COMMAND_UI(ID_PLAYER_BOUNCINGPLAYER, OnUpdatePlayerBouncingplayer)
	ON_COMMAND(ID_PLAYER_AUTOPLAY, OnPlayerAutoplay)
	ON_UPDATE_COMMAND_UI(ID_PLAYER_AUTOPLAY, OnUpdatePlayerAutoplay)
	ON_COMMAND(ID_PLAYER_CURSORCRITTER, OnPlayerCursorcritter)
	ON_UPDATE_COMMAND_UI(ID_PLAYER_CURSORCRITTER, OnUpdatePlayerCursorcritter)
	ON_COMMAND(ID_PLAYER_ARROWKEYS, OnPlayerArrowkeys)
	ON_UPDATE_COMMAND_UI(ID_PLAYER_ARROWKEYS, OnUpdatePlayerArrowkeys)
	ON_COMMAND(ID_GAME_BOUNCE, OnGameBounce)
	ON_UPDATE_COMMAND_UI(ID_GAME_BOUNCE, OnUpdateGameBounce)
	ON_COMMAND(ID_GAME_BUBBLES, OnGameBubbles)
	ON_UPDATE_COMMAND_UI(ID_GAME_BUBBLES, OnUpdateGameBubbles)
	ON_COMMAND(ID_PLAYER_HOPPERCONTROL, OnPlayerHoppercontrol)
	ON_UPDATE_COMMAND_UI(ID_PLAYER_HOPPERCONTROL, OnUpdatePlayerHoppercontrol)
	ON_COMMAND(ID_GAME_QUAKESTYLEMMODELS, OnGameQuakeStyleModels)
	ON_UPDATE_COMMAND_UI(ID_GAME_QUAKESTYLEMMODELS, OnUpdateGameQuakeStyleModels)
	ON_COMMAND(ID_PLAYER_SCOOTERHOPPER3D, OnPlayerScooterhopper3d)
	ON_UPDATE_COMMAND_UI(ID_PLAYER_SCOOTERHOPPER3D, OnUpdatePlayerScooterhopper3d)
	ON_COMMAND(ID_GAME_SPHERES, OnGameSpheres)
	ON_UPDATE_COMMAND_UI(ID_GAME_SPHERES, OnUpdateGameSpheres)

   ON_COMMAND(ID_GAME_SPACEWAR, OnGameSpacewar)
	ON_UPDATE_COMMAND_UI(ID_GAME_SPACEWAR, OnUpdateGameSpacewar)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPopDoc construction/destruction
CPopDoc::CPopDoc():
_pgame(NULL)
{
/*  Choose the type of game you want at startup by commenting in ONE setGameClass line.
The setGameClass sets brandnewgameflag to TRUE. */

	setGameClass(RUNTIME_CLASS(cTankWars2005));
}

CPopDoc::~CPopDoc()
{
	delete _pgame;
	_pgame = NULL;
}

void CPopDoc::setGameClass(CRuntimeClass *pruntimeclass)
{
	/* Create a new pointer with the MFC CreateObject method.  Even though we cast the new game
		into a cGame* pointer for the return, it "really" remains whatever kind of child class is
		described by the pruntimeclass variable, and will use the child class' overloads
		of any virtual methods. */  
	delete _pgame; //It's OK to delete a NULL, as happens at startup.
	_pgame = NULL;
	((CPopApp*)::AfxGetApp())->setRunspeed(1.0); /* Restore this in case
		you changed in a game constructor, like cTankWars2005Sun. */
	cGame *pnewgame = (cGame*)(pruntimeclass->CreateObject());
	/* Constructor makes pnewgame->_gameisfreshlyinitialized be TRUE, so when
		 you press ENTER it won't reseed. */
	ASSERT(pnewgame); //Will be NULL if there's something wrong with pruntimeclass.
	_pgame = pnewgame;
	_pgame->seedCritters();
	_pgame->processServiceRequests(); /* To process all the add requests made by
		critter constructors in the construtor and the seedCritters call. */
	UpdateAllViews(NULL, CPopDoc::VIEWHINT_STARTGAME, 0);
}
/////////////////////////////////////////////////////////////////////////////
// CPopDoc serialization

/*		Whenever you use load into a pointer variable ptr, we have to call delete on the pointer 
	first, otherwise we'll have a memory leak caused by the "orphaned" object that the pointer
	pointed to before you overwrote it with the load.  For reasons we'll now explain, we must use
	an overloaded ar >> ptr operator to load into a pointer, rather than a ptr->Serialize(ar) call.
		To save and load the _pgame fields of cPopDoc, we use the autogenerated
	overloaded operator<<(CArchive &ar, cgame *p) and operator>>(CArchive &ar, cGame *&p).
	MFC has "written the code" for these operators automatically becasue the cGame	
			(a) inherits from CObject,
			(b) has DECLARE and IMPLEMENT_SERIAL, and
			(c) has it's own Serialize defined. 
		In the load case we want to make a new cGame* and place it into the _pgame field, and
	this is exactly what ar >> _pgame does.
		Now, as mentioned just above, in the load case, we delete _pgame before loading it.  At
	first you might think you could load either with _pgame->Serialize(ar) or ar >> _pgame. 
		But since you delete _pgame just before the load, it becomes an invalid pointer just before
	the load, and you would get a crash if you tried to call _pgame->Serialize(ar) for the load.
		We could actually use _pgame->Serialize(ar) in the save case, but for symmetry in the
	appearance of the read and write cases, we use	ar << _pgame there. 
*/

void CPopDoc::Serialize(CArchive& ar)
{
	/* So as to make sure that (a) I load and save my files with the same build and
		(b) I don't try and load non-Pop files, I'm going to write a version string
		at the head of each archive. */
	CString cStrAppVersion;
 	VERIFY(cStrAppVersion.LoadString(IDR_MAINFRAME));
		/* VERIFY means always evaluate the expression, but if you 
		are in the debug build and the expression is 0, then interrupt
		just like a failed assertion. */

	CObject::Serialize(ar);
	if (ar.IsStoring()) // Save 
	{
		ar << cStrAppVersion;
		ar << _pgame;
		getActiveView()->Serialize(ar);
	}
	else //Load 
	{
		CString cStrFileVersion;
		ar >> cStrFileVersion;
		if (cStrFileVersion.GetLength() > 256) //Then you opened some totally bogus file
			cStrFileVersion = cStrFileVersion.Left(16) + "..."; //Truncate
		if (cStrFileVersion != cStrAppVersion)
		{
			CString message = "File Version:\n" + cStrFileVersion + 
			"\n\nDoesn't Match App Version:\n" + cStrAppVersion + "\n\nWill Abort the Load.";
			MessageBeep(MB_ICONEXCLAMATION);
			::AfxMessageBox(message);
			::AfxThrowArchiveException(0, NULL); /* This throws an exception which is caught
				inside the base class CDocument::OnOpenDocument call and then closes the badly 
				opened document. */
			return;
		}
		delete _pgame; /*At CPopDoc construction a document creates a 
				default cGame *_pgame.  So if we're loading a game we need to
				delete the existing game first or there will be a memory leak.*/
		_pgame = NULL;
		ar >> _pgame; /* Uses CreateObject to creates a new cGame* object of the
				correct child class, copies the new objects fields out of the file,
				and places the pointer to the new object in _pgame. Constructor 
				makes pnewgame->_gameisfreshlyinitialized be TRUE, so when
				you press ENTER it won't reseed. The CPopDoc constructor calls 
				setGameClass.   */
		_pgame->setGameover(TRUE); /* So you can press ENTER to actually start it
				running. _gameisfreshlyinitialized is true, as mentioned just above, so
				ENTER won't randomize things. */
			/* We used to not bother to try to load the CPopView info, and we just called
				UpdateAllViews(NULL, CPopDoc::VIEWHINT_STARTGAME, 0); But as of 9/2001,
				we wrap the CArchive in a cArchiveHint and pass it to the views. */
		cArchiveHint *parchivehint = new cArchiveHint(&ar);
		UpdateAllViews(NULL, CPopDoc::VIEWHINT_LOADINGARCHIVE, parchivehint); /* This call
			jumps right to CPopView::OnUpdate, so the ar information is still good. */
		delete parchivehint;
		parchivehint = NULL;
	}
}

cBiota* CPopDoc::pbiota()
{
	return pgame()->pbiota();
}


cRealBox CPopDoc::border()
{
	return pgame()->border();
}


BOOL CPopDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)
	return TRUE;
}

void CPopDoc::stepDoc(Real dt)
{ 
/* Here I step the game and update the views.  If the game reaches a _gameover state because of the adjustGameParams
call made inside of cGame::step, then the step code "spins" in a wait state showing 
a "Game Over" AfxMessageBox and the final state of the game isn't drawn, which is bad.
So we do the UpdateAllViews call before we do the cGame::step call. */
	CPopView *pactiveview = getActiveView(); //So I can pass it to the game for possible sniffing.
	cTimeHint timehint(dt); //Wrap dt up so we can pass it to the views.
	_pgame->step(dt, pactiveview); /* Move the critters and maybe add or
		delete some. Critters possibly use the pview to sniff out the pixel color at some locations. */
	UpdateAllViews(NULL, 0, &timehint); //Redraw all the views.
//Possibly wait for user to start or restart game.
	BOOL didareset = FALSE;

   // Changed: removed AfxMessageBox promt
   // Modfied by: Joseph E. Sutton
	if (_pgame->newgame())
	{
		//AfxMessageBox("PRESS ENTER\nTo Start Game.", MB_OK | MB_ICONINFORMATION); 
      // Spin in AfxMessageBox till User presses Enter.
		_pgame->start();
		didareset = TRUE;
	}
	if(_pgame->gameover())
	{
		int playmore = ::AfxMessageBox(_pgame->gameOverMessage(), MB_OK | MB_ICONINFORMATION); 
      // Spin in AfxMessageBox till user presses Enter or Cancel.
		if (playmore == IDOK) _pgame->restart();

      //_pgame->restart();
		didareset = TRUE;
	}
	if (didareset && _pgame->pplayer()->plistener()->IsKindOf(RUNTIME_CLASS(cListenerCursor)))
		getActiveView()->setCursorPosToCritter(_pgame->pplayer()); // Match cursor to player pos. 

#ifdef TRACETIMESTEPANOMALIES
	static Real olddt = 0.0; 
	static int updatecount = 0;
	if (dt > 2.0*olddt)
	{
		TRACE("%f dt after %f olddt in CPopDoc::stepDoc.\n", dt, olddt); 
		TRACE("%d updates since last anomalous dt.\n", updatecount);
		TRACE("%d by %d = %d pixels in active view.\n", pview->cx(), pview->cy(), pview->cx()*pview->cy());
		updatecount = 0;
	}
	updatecount++;
	olddt = dt;
#endif //TRACETIMESTEPANOMALIES
}

CPopView* CPopDoc::getActiveView()
{
	CMDIFrameWnd *pFrame =(CMDIFrameWnd*)AfxGetMainWnd();
	if (!pFrame) //In case things aren't initialized yet.
		return NULL;
	CMDIChildWnd *pChild = pFrame->MDIGetActive();
	if (!pChild) //In case things aren't initialized yet.
		return NULL;
	CPopView *pView = (CPopView *) pChild->GetActiveView();
		return pView;
}

/////////////////////////////////////////////////////////////////////////////////
// CPopDoc diagnostics

#ifdef _DEBUG
void CPopDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CPopDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPopDoc commands


void CPopDoc::OnGameRestart() //You get this when you press the ENTER key.
{ 
	_pgame->restart();
}

void CPopDoc::OnGameSmall() 
{
	_pgame->setSeedcount(cGame::COUNTSMALL);
//	UpdateAllViews(NULL);	//This gets called all the time anyway.
}
void CPopDoc::OnUpdateGameSmall(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable((_pgame->menuflags() & cGame::MENU_COUNT)?TRUE:FALSE);	
	pCmdUI->SetCheck(_pgame->seedcount()==cGame::COUNTSMALL?1:0);
}
void CPopDoc::OnGameMedium() 
{
	_pgame->setSeedcount(cGame::COUNTMEDIUM);
}
void CPopDoc::OnUpdateGameMedium(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable((_pgame->menuflags() & cGame::MENU_COUNT)?TRUE:FALSE);	
	pCmdUI->SetCheck(_pgame->seedcount()==cGame::COUNTMEDIUM?1:0);
}
void CPopDoc::OnGameLarge() 
{
	_pgame->setSeedcount(cGame::COUNTLARGE);
}
void CPopDoc::OnUpdateGameLarge(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable((_pgame->menuflags() & cGame::MENU_COUNT)?TRUE:FALSE);	
	pCmdUI->SetCheck(_pgame->seedcount()==cGame::COUNTLARGE?1:0);
}
void CPopDoc::OnGameHuge() 
{
	_pgame->setSeedcount(cGame::COUNTHUGE);
}
void CPopDoc::OnUpdateGameHuge(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable((_pgame->menuflags() & cGame::MENU_COUNT)?TRUE:FALSE);	
	pCmdUI->SetCheck(_pgame->seedcount()==cGame::COUNTHUGE?1:0);
}

//==========Pop Game Menu Controls===============

void CPopDoc::OnGameWrap() 
{
	_pgame->setWrapflag(cCritter::WRAP);
}

void CPopDoc::OnUpdateGameWrap(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable((_pgame->menuflags() & cGame::MENU_BOUNCEWRAP)?TRUE:FALSE);	
	pCmdUI->SetCheck(_pgame->wrapflag() == cCritter::WRAP?1:0);
}

void CPopDoc::OnGameBounce() 
{
	_pgame->setWrapflag(cCritter::BOUNCE);
}

void CPopDoc::OnUpdateGameBounce(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable((_pgame->menuflags() & cGame::MENU_BOUNCEWRAP)?TRUE:FALSE);	
	pCmdUI->SetCheck(_pgame->wrapflag() == cCritter::BOUNCE?1:0);
}

void CPopDoc::OnGameBitmaps() 
{
	_pgame->setSpritetype(cGame::ST_BITMAPS);
}

void CPopDoc::OnUpdateGameBitmaps(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable((_pgame->menuflags() & cGame::MENU_SHAPE)?TRUE:FALSE);	
	pCmdUI->SetCheck(_pgame->spritetype() == cGame::ST_BITMAPS?1:0);
}

void CPopDoc::OnGameBubbles() 
{
	_pgame->setSpritetype(cGame::ST_BUBBLES);
}

void CPopDoc::OnUpdateGameBubbles(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable((_pgame->menuflags() & cGame::MENU_SHAPE)?TRUE:FALSE);	
	pCmdUI->SetCheck(_pgame->spritetype() == cGame::ST_BUBBLES?1:0);
}

void CPopDoc::OnGameAssorted() 
{
	_pgame->setSpritetype(cGame::ST_ASSORTED);
}

void CPopDoc::OnUpdateGameAssorted(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable((_pgame->menuflags() & cGame::MENU_SHAPE)?TRUE:FALSE);	
	pCmdUI->SetCheck(_pgame->spritetype() == cGame::ST_ASSORTED?1:0);
}

void CPopDoc::OnGameSimplepolygons() 
{
	_pgame->setSpritetype(cGame::ST_SIMPLEPOLYGONS);
}

void CPopDoc::OnUpdateGameSimplepolygons(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable((_pgame->menuflags() & cGame::MENU_SHAPE)?TRUE:FALSE);	
	pCmdUI->SetCheck(_pgame->spritetype() == cGame::ST_SIMPLEPOLYGONS?1:0);
}

void CPopDoc::OnGameFancypolygons() 
{
	_pgame->setSpritetype(cGame::ST_FANCYPOLYGONS);
}

void CPopDoc::OnUpdateGameFancypolygons(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable((_pgame->menuflags() & cGame::MENU_SHAPE)?TRUE:FALSE);	
	pCmdUI->SetCheck(_pgame->spritetype() == cGame::ST_FANCYPOLYGONS?1:0);
}

void CPopDoc::OnGamePolypolygons() 
{
	_pgame->setSpritetype(cGame::ST_POLYPOLYGONS);
}

void CPopDoc::OnUpdateGamePolypolygons(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable((_pgame->menuflags() & cGame::MENU_SHAPE)?TRUE:FALSE);	
	pCmdUI->SetCheck(_pgame->spritetype() == cGame::ST_POLYPOLYGONS?1:0);
}

void CPopDoc::OnGameAsteroids() 
{
	_pgame->setSpritetype(cGame::ST_ASTEROIDPOLYGONS);
}

void CPopDoc::OnUpdateGameAsteroids(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable((_pgame->menuflags() & cGame::MENU_SHAPE)?TRUE:FALSE);	
	pCmdUI->SetCheck(_pgame->spritetype() == cGame::ST_ASTEROIDPOLYGONS?1:0);
}

void CPopDoc::OnGameTriplepolypolygons() 
{
	_pgame->setSpritetype(cGame::ST_TRIPLEPOLYPOLYGONS);
}

void CPopDoc::OnUpdateGameTriplepolypolygons(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable((_pgame->menuflags() & cGame::MENU_SHAPE)?TRUE:FALSE);	
	pCmdUI->SetCheck(_pgame->spritetype() == cGame::ST_TRIPLEPOLYPOLYGONS?1:0);
}

void CPopDoc::OnGameSpheres() 
{
	_pgame->setSpritetype(cGame::ST_SPHERES);
}

void CPopDoc::OnUpdateGameSpheres(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable((_pgame->menuflags() & cGame::MENU_SHAPE)?TRUE:FALSE);	
	pCmdUI->SetCheck(_pgame->spritetype() == cGame::ST_SPHERES?1:0);
}

void CPopDoc::OnGameQuakeStyleModels() 
{
	_pgame->setSpritetype(cGame::ST_MESHSKIN);
}

void CPopDoc::OnUpdateGameQuakeStyleModels(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable((_pgame->menuflags() & cGame::MENU_SHAPE)?TRUE:FALSE);	
	pCmdUI->SetCheck(_pgame->spritetype() == cGame::ST_MESHSKIN?1:0);
}

//========Edit Controls=========================
/* These serve no discernible purpose and put an additonal load on code maintenance,
so we no longer have the Edit popup with the items to call the various edit message
handlers.  But if you added an Edit popup menu again with the ID_EDIT_COPY,
ID_EDIT_PASTE, and ID_EDIT_CUT control IDs you could use these again. */

void CPopDoc::OnEditCopy() 
{
	delete ((CPopApp*)AfxGetApp())->_pcritter_clipboard;
	((CPopApp*)AfxGetApp())->_pcritter_clipboard = NULL;
	((CPopApp*)AfxGetApp())->_pcritter_clipboard = _pgame->pFocus()->clone();
}

void CPopDoc::OnUpdateEditCopy(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable((_pgame->pFocus() && 
		_pgame->pFocus()!=_pgame->pplayer())?TRUE:FALSE);	
}

void CPopDoc::OnEditCut() 
{
	OnEditCopy();
	_pgame->pFocus()->delete_me();	
}

void CPopDoc::OnUpdateEditCut(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable((_pgame->pFocus() && 
		_pgame->pFocus()!=_pgame->pplayer())?TRUE:FALSE);	
}

void CPopDoc::OnEditPaste() 
{
	(((CPopApp*)AfxGetApp())->_pcritter_clipboard)->clone()->add_me(_pgame->pbiota());
}

void CPopDoc::OnUpdateEditPaste(CCmdUI* pCmdUI) 
{
	cCritter *pclipboard = ((CPopApp*)AfxGetApp())->_pcritter_clipboard;
	pCmdUI->Enable((pclipboard && pclipboard->pgame() == _pgame)?TRUE:FALSE);
}

//================Player Listener controls==================
void CPopDoc::OnPlayerArrowkeys() 
{
	_pgame->pplayer()->setListener(new cListenerArrow());
}

void CPopDoc::OnUpdatePlayerArrowkeys(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(_pgame->visibleplayer()
		&& (_pgame->menuflags() & cGame::MENU_CHANGELISTENER) );
	pCmdUI->SetCheck(
		(_pgame->playerListenerClass() == (RUNTIME_CLASS(cListenerArrow)) ||
		_pgame->playerListenerClass() == (RUNTIME_CLASS(cListenerArrowAttitude)))
		?1:0);
}

void CPopDoc::OnPlayerHoppercontrol() 
{
	_pgame->pplayer()->setListener(new cListenerHopper());
}

void CPopDoc::OnUpdatePlayerHoppercontrol(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(_pgame->visibleplayer() 
		&& (_pgame->menuflags() & cGame::MENU_HOPPER) 
		&& (_pgame->menuflags() & cGame::MENU_CHANGELISTENER) 
		);
	pCmdUI->SetCheck(_pgame->playerListenerClass() == (RUNTIME_CLASS(cListenerHopper))?
		1:0);
}

void CPopDoc::OnPlayerScooterhopper3d() 
{
	_pgame->pplayer()->setListener(new cListenerScooterYHopper());
}

void CPopDoc::OnUpdatePlayerScooterhopper3d(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(_pgame->visibleplayer() 
		&& (_pgame->menuflags() & cGame::MENU_HOPPER) 
		&& (_pgame->menuflags() & cGame::MENU_CHANGELISTENER) 
		);
	pCmdUI->SetCheck(_pgame->playerListenerClass() == (RUNTIME_CLASS(cListenerScooterYHopper))?
		1:0);
}


void CPopDoc::OnPlayerCarkeys() 
{
	_pgame->pplayer()->setListener(new cListenerCar());
}

void CPopDoc::OnUpdatePlayerCarkeys(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(_pgame->visibleplayer()
		&& (_pgame->menuflags() & cGame::MENU_CHANGELISTENER) );
	pCmdUI->SetCheck(_pgame->playerListenerClass() == (RUNTIME_CLASS(cListenerCar))?
		1:0);
}

void CPopDoc::OnPlayerSpaceshipkeys() 
{
	_pgame->pplayer()->setListener(new cListenerSpaceship());
}

void CPopDoc::OnUpdatePlayerSpaceshipkeys(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(_pgame->visibleplayer() && !(_pgame->in3DWorld())  
		//Spaceship listener as of 35_1 doesn't work right in 3D
		&& (_pgame->menuflags() & cGame::MENU_CHANGELISTENER) );
	pCmdUI->SetCheck(_pgame->playerListenerClass() == (RUNTIME_CLASS(cListenerSpaceship))?1:0);
}

void CPopDoc::OnPlayerCursorcritter() 
{
	_pgame->pplayer()->setListener(new cListenerCursor());
	getActiveView()->setCursorPosToCritter(_pgame->pplayer()); // Match cursor to player pos. 
}

void CPopDoc::OnUpdatePlayerCursorcritter(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(_pgame->visibleplayer() &&
		(_pgame->menuflags() & cGame::MENU_CHANGELISTENER) &&
		(_pgame->menuflags() & cGame::MENU_ALLOWLISTENERCURSOR));
	pCmdUI->SetCheck(_pgame->playerListenerClass() == 
		(RUNTIME_CLASS(cListenerCursor))?1:0);
}

void CPopDoc::OnPlayerFlykeys() 
{
	_pgame->pplayer()->setListener(new cListenerScooter());
}

void CPopDoc::OnUpdatePlayerFlykeys(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(_pgame->visibleplayer()
		&& (_pgame->menuflags() & cGame::MENU_CHANGELISTENER) ); // && _pgame->border().zsize());
	pCmdUI->SetCheck(_pgame->playerListenerClass() == (RUNTIME_CLASS(cListenerScooter))?1:0);
}

//================================================Other(non-LIstener) Player controls

void CPopDoc::OnPlayerShield() 
{
	_pgame->pplayer()->setShield(_pgame->pplayer()->shield()^TRUE);
}

void CPopDoc::OnUpdatePlayerShield(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable((_pgame->visibleplayer() && 
		(_pgame->menuflags() & cGame::MENU_SHIELD))?TRUE:FALSE);	
	pCmdUI->SetCheck(_pgame->pplayer()->shield()?1:0);
}

void CPopDoc::OnUpdatePlayerRubberbullets(CCmdUI* pCmdUI) 
{
	if (!_pgame->visibleplayer())
	{
		pCmdUI->Enable(FALSE);
		return;
	}
	if (!(_pgame->pplayer()->IsKindOf(RUNTIME_CLASS(cCritterArmed))))
	{
		pCmdUI->Enable(FALSE);
		return;
	}
	cCritterArmed *parmedplayer = (cCritterArmed*)(_pgame->pplayer());
	if (!parmedplayer->armed())
	{
		pCmdUI->Enable(FALSE);
		return;
	}
	pCmdUI->Enable(TRUE);
	pCmdUI->SetCheck(parmedplayer->pbulletclass()== 
		RUNTIME_CLASS(cCritterBulletRubber)?1:0);
}

void CPopDoc::OnPlayerRubberbullets() 
{
	if (_pgame->pplayer()->IsKindOf(RUNTIME_CLASS(cCritterArmed)))
	{
		cCritterArmed *parmedplayer = (cCritterArmed*)(_pgame->pplayer());
		parmedplayer->setBulletClass(RUNTIME_CLASS(cCritterBulletRubber));
	}
}

void CPopDoc::OnUpdatePlayerDeadlybullets(CCmdUI* pCmdUI) 
{
	if (!_pgame->visibleplayer())
	{
		pCmdUI->Enable(FALSE);
		return;
	}
	if (!(_pgame->pplayer()->IsKindOf(RUNTIME_CLASS(cCritterArmed))))
	{
		pCmdUI->Enable(FALSE);
		return;
	}
	cCritterArmed *parmedplayer = (cCritterArmed*)(_pgame->pplayer());
	if (!parmedplayer->armed())
	{
		pCmdUI->Enable(FALSE);
		return;
	}
	pCmdUI->Enable(TRUE);
	pCmdUI->SetCheck(parmedplayer->pbulletclass()== 
		RUNTIME_CLASS(cCritterBulletRubber)?0:1);
}

void CPopDoc::OnPlayerDeadlybullets() 
{
	if (_pgame->pplayer()->IsKindOf(RUNTIME_CLASS(cCritterArmed)))
	{ //Do the cast if it's safe.
		cCritterArmed *parmedplayer = (cCritterArmed*)(_pgame->pplayer());
		/* Figure out what kind of default bullet the player should use by making a 
			fresh sample critter of the same class. */
		CRuntimeClass *pplayerclass = _pgame->pplayer()->GetRuntimeClass();
		cCritterArmed* psampleplayer = (cCritterArmed*)(pplayerclass->CreateObject());
		parmedplayer->setBulletClass(psampleplayer->pbulletclass());
		delete psampleplayer;
		psampleplayer = NULL;
	}
}

/* Absorbing doesn't have any real effect if the infinite density is on, so we 
don't allow the combination of absorberflag && inifinite density. */
void CPopDoc::OnPlayerMassiveplayer() 
{
	_pgame->pplayer()->setDensity(cCritter::INFINITEDENSITY);
	_pgame->pplayer()->setAbsorberflag(FALSE);
}

void CPopDoc::OnUpdatePlayerMassiveplayer(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(_pgame->visibleplayer());
	pCmdUI->SetCheck(
		_pgame->pplayer()->density()==cCritter::INFINITEDENSITY?1:0);
}

/* Absorbing doesn't work if the infinite density is on, so we don't allow
the combination of absorberflag && infinite density. Since we want to show
player bulling through crowds, we by default turn infinite density on when
we turn absorber flag off.*/
void CPopDoc::OnPlayerAbsorberplayer() 
{
		_pgame->pplayer()->setAbsorberflag(
			TRUE ^ _pgame->pplayer()->absorberflag());
		if (_pgame->pplayer()->absorberflag())
			_pgame->pplayer()->setDensity(1.0);
}

void CPopDoc::OnUpdatePlayerAbsorberplayer(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(_pgame->visibleplayer());
	pCmdUI->SetCheck(_pgame->pplayer()->absorberflag()?1:0);
}

void CPopDoc::OnPlayerBouncingplayer() 
{
	_pgame->pplayer()->setAbsorberflag(FALSE);
	_pgame->pplayer()->setDensity(1.0);
}

void CPopDoc::OnUpdatePlayerBouncingplayer(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(_pgame->visibleplayer());
	pCmdUI->SetCheck(
	!(_pgame->pplayer()->absorberflag() || _pgame->pplayer()->density()==cCritter::INFINITEDENSITY)
		?1:0);
}

void CPopDoc::OnPlayerAutoplay() 
{
	_pgame->setAutoplay( 1 - _pgame->autoplay());
}

void CPopDoc::OnUpdatePlayerAutoplay(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable((_pgame->menuflags() & cGame::MENU_AUTOPLAY)?TRUE:FALSE);	
	pCmdUI->SetCheck(_pgame->autoplay()==1 ?1:0);
}


void CPopDoc::OnGameSpacewar() 
{
	setGameClass(RUNTIME_CLASS(cTankWars2005));
}

void CPopDoc::OnUpdateGameSpacewar(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(_pgame->IsKindOf(RUNTIME_CLASS(cTankWars2005))?1:0);
}







