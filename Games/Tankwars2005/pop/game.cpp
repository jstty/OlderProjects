// Game.cpp: implementation of the cGame class and children.
//
//////////////////////////////////////////////////////////////////////
#include "stdafx.h"
#include "game.h"
#include "spritebubble.h"
#include "critter.h"
#include "critterarmed.h"
#include "critterwall.h"
#include "force.h"
#include "listener.h"
#include "spriteicon.h"
#include "spritepolygon.h"
#include "spritequake.h"
#include "sprite3d.h"
#include "pop.h" //for playSound
#include "graphics.h"
#include "critterviewer.h"
#include "graphicsmfc.h"
#include "graphicsopengl.h"
#include "collider.h"
#include "graphicsopengl.h"
#include "spritetexturebox.h"

IMPLEMENT_SERIAL( cGame, CObject, 0);

//#define TESTGLTEXT
	/* The TESTGLTEXT turns on some code in drawForeground to exercise the
	new drawtext code, specifically testing the OpenGL version. */
//#define MINIMALPOLYPOLYS
	/* The MINIMALPOLYPOLYS switch makes the polypolygons from randomSprite be squares with
	triangles at the tips. */
//#define DRAGGINGPINKILLS
	/* DRAGGINGPINKILLS is on, then draggin the pin cursor kills everything it crosses.
	This turns out to be a bad idea as you end up killing more than you need to, better
	to only activate the Pin cursor kill once per left button press. */
//#define FREEZEPICKCRITTER
	/* Comment FREEZEPICKCRITTER in if you want the arrow cursor to freeze a critter
	in place till you click elsewhere on the screen. For most games this is confusing
	and seems like a cheat. We would need this if we wanted to use the Edit | Copy
	control, but we no longer use this. So get rid of it. */
//#define DONTCOUNTALLCRITTERS
	/* Comment in DONTCOUNTALLCRITTERS if you want the info in the status bar that gives you
	the critter count to NOT include the bullets and the player in the count. Comment ou
	DONTCOUNTALLCRITTERS if you want the count to just be the number of enemy, prop, wall
	critters, but not the bullets and the player. */
#define ONLYPLAINBUBBLES
	/* If ONLYPLAINBUBBLES, just return the bubble guys wiht rectangles on
		their tops.  I'm doing this so game picknpop can vary the jewels. */
#ifdef TESTGLTEXT
void testtext(cGraphics *pgraphics); //Declaration of method defined at the bottom
#endif //TESTGLTEXT

//Static constants=============================================
 //******** CONST STATICS **********************************************
const int cGame::COUNTSMALL = 4;
const int cGame::COUNTMEDIUM = 8;
const int cGame::COUNTLARGE = 25;
const int cGame::COUNTHUGE = 80;
const int cGame::MENU_ALL = 0xFFFF; //All flags on
const int cGame::MENU_SHAPE = 0x0001; //Allow the buttons to change shapes of sprites.
const int cGame::MENU_BOUNCEWRAP = 0x0002; //Allow user to flip bounce/wrap settings.
const int cGame::MENU_2D = 0x0004; //Allow cGraphicsMFC
const int cGame::MENU_3D = 0x0008; //Allow cGraphicsOpenGL
const int cGame::MENU_AUTOPLAY = 0x0010; //Allow the Player | Autoplay control to work.
const int cGame::MENU_COUNT = 0x0020; //Allow the Game | Small, etc. controls
const int cGame::MENU_SHIELD = 0x0040; //Activate Player|Shield
const int cGame::MENU_BACKGROUND = 0x0080; //Activate View|Solid and View|Bitmap Background controls.
const int cGame::MENU_HOPPER = 0x0100; //Allow Hopper Listener
const int cGame::MENU_CHANGELISTENER = 0x0200; //Allow user to change listener at all.
const int cGame::MENU_TRACKPLAYER = 0x0400; //Allow use of VIew|Track Player
const int cGame::MENU_RIDEPLAYER = 0x0800; //Allow use of VIew|Track Player
const int cGame::MENU_ALLOWLISTENERCURSOR = 0x1000; //Allow use of Player|Mouse Listener
//World shape hints =================
const int cGame::SHAPE_RECT = 0;
const int cGame::SHAPE_XSCROLLER = 1;
const int cGame::SHAPE_YSCROLLER = 2;
//Depth STatics ========================================
#ifdef THREEDVECTORS
Real cGame::BACKGROUNDOFFSET = -0.6; /* Want this so sprites sliding on floor don't have
		z-fighting, but if you overdo it, then it looks bad to have the
		sprites floating above the floor. */
Real cGame::FOREGROUNDOFFSET = 0.9; //Make sure less than cSprite::MAXPRISMDZ.
#else //not THREEDVECTOR means 2D case
Real cGame::BACKGROUNDOFFSET = 0.0; //Make sure bigger than - cSprite::MAXPRISMDZ
Real cGame::FOREGROUNDOFFSET = 0.0; //Make sure less than cSprite::MAXPRISMDZ.
#endif //THREEDVECTOR
//============ cGame Statics =====================================
 int cGame::COUNTSTART = cGame::COUNTMEDIUM;
Real cGame::DEFAULTZDEPTH = 1.0; /* Use this when you want to make a 2D world 3D by stacking
	disklike critters up. */
int cGame::MAXSCORE = 1000; //Default _maxscore for a game; can be overridden in constructor.
 /* In looking at the size and speed , keep in mind that our typical world size is 14.0
  by 9.0, defined by the WORLD??? statics.  The speed is in units per second, so a
 speed of 3 means it takes about 3 seconds to cross the window.  A speed of 1 takes 10 
 seconds, a speed of 5 takes 2 seconds and so on. */
 //==================Size Related Statics =======================
  /* The actual window size on my screen is 12 inch by 8 inch.  I make both 20% larger for more room. */
 Real cGame::WORLDWIDTH = 14.4; //14.4
 Real cGame::WORLDHEIGHT = 9.6; //9.6
  /* The next four are used in the cGame constructor to set the corresponding cCritter statics
to these default values. */
#ifndef DONTBOSS
 Real cGame::CRITTERMINRADIUS = 0.3;
 Real cGame::CRITTERMAXRADIUS = 0.8;
 Real cGame::BULLETRADIUS = 0.125;
 Real cGame::CRITTERMAXSPEED = 3.0;
#endif //DONTBOSS
	 /* Default game constructor sets cCritter::MAXSPEED 
	to this value. */
//======================Static constants for the randomSprite Factory Method===========
//Note, the code for the the cGame::randomSprite Factory Method is at the bottom of this file.
const int cGame::ST_SPRITETYPENOTUSED = -1; //Indicates you will put in sprites by hand.
const int cGame::ST_SIMPLEPOLYGONS = 0; //Simple triangles, squares, pentagons.
const int cGame::ST_FANCYPOLYGONS = 1; //Diverse regular and star polygons.
const int cGame::ST_ASTEROIDPOLYGONS = 2;  //Polypolygons that have polypolygons at their tips.
const int cGame::ST_POLYPOLYGONS = 3;  //Polypolygons that have polygons at their tips.
const int cGame::ST_BITMAPS = 4;  //cSpriteIcon bitmaps.
const int cGame::ST_MESHSKIN = 5;  //Mixed from SIMPLEPOLYGONS through BUBBLES (but not TRIPLE).
const int cGame::ST_BUBBLES = 6;  //2D balls of various kinds.
const int cGame::ST_SPHERES = 7;  //3d balls.
const int cGame::ST_ASSORTED = 8;  //Mixed from SIMPLEPOLYGONS through BUBBLES (but not TRIPLE).
const int cGame::ST_TRIPLEPOLYPOLYGONS = 8;  //Polypolygons that have polypolygons at their tips.

//============================= cGame  ==========================

cGame::cGame():
_seedcount(COUNTSTART), 
_gameover(TRUE),
_maxscore(MAXSCORE),
_scorecorrection(0),
_wrapflag(cCritter::WRAP),
_bDragging(FALSE),
_pfocus(NULL),
_pplayer(NULL),
_border(cGame::WORLDWIDTH, cGame::WORLDHEIGHT), //Default no zsize, computes faster.
_pskybox(NULL),
_pcontroller(NULL),
_cursorpos(0.0, 0.0),
_autoplay(0),
_level(1),
_spritetype(cGame::ST_SPRITETYPENOTUSED),
_menuflags(cGame::MENU_ALL & ~cGame::MENU_AUTOPLAY & ~cGame::MENU_HOPPER),
_newgame(TRUE)
{
//Fix the statics
	/* Reset the various statics that may have been set to different values by previously
		running some other game. */
#ifndef DONTBOSS
	cCritter::MAXSPEED = cGame::CRITTERMAXSPEED;
	cCritter::MINRADIUS = cGame::CRITTERMINRADIUS;
	cCritter::MAXRADIUS = cGame::CRITTERMAXRADIUS;
	cCritter::BULLETRADIUS = cGame::BULLETRADIUS;
#endif //DONTBOSS
//Allocate the pointer variables.
	_pbiota = new cBiota(this);
	_pcollider = new cCollider();
	_pcontroller = new cController(); //This is a structure used to store key and mouse info.
	_plightingmodel = new cLightingModel(TRUE); //Default lighting model enables lights.
	setBorder(cGame::WORLDWIDTH, cGame::WORLDHEIGHT, 0.0);
	// setBorder initializes _pskybox as well 

//Initialize other variables.
	/* We never want to have a NULL player, so we just add a basic cCritter as player. 
		Note that we use the setPlayer accessor rather than just setting _pplayer. */
	_bitmapIDarray.RemoveAll(); /* We flush this out for each game,
		in case some games want to put different bitmap IDs in here. */
	 /* We use the _bitmapIDarray array as a way to select
		random bitmaps. Commonly we will adjust the list to match the "theme" of a game.
		Note that if you have special bitmaps used explicity in your critter constructors,
		those don't necessarily	need to be mentioned here. */
	_bitmapIDarray.Add(IDB_EARTH);
	_bitmapIDarray.Add(IDB_SUN);
	_bitmapIDarray.Add(IDB_FACE);
	_bitmapIDarray.Add(IDB_GNARLY);
	_bitmapIDarray.Add(IDB_SPRING);
	_bitmapIDarray.Add(IDB_BUM);
	_bitmapIDarray.Add(IDB_UFO);
/* Get a list of wallpaper resource IDs to be used by randomWallpaperID() */
	_wallpaperBitmapIDarray.RemoveAll();
	_wallpaperBitmapIDarray.Add(IDB_AQUATRAPEZOIDS);
	_wallpaperBitmapIDarray.Add(IDB_SMOOTHBRICK);
	_wallpaperBitmapIDarray.Add(IDB_PALEBLUESCROLLS);
	_wallpaperBitmapIDarray.Add(IDB_BEIGEFOAM);
/* We use the _meshSkinNameTripleArray to select random cSpriteQuake mesh/skin Triples.  See
the comments on _bitmapIDarray. */
	_meshSkinNameTripleArray.RemoveAll();
	_meshSkinNameTripleArray.Add(cMeshSkinNameTriple(
		"models\\Invader\\Tris.MD2", "models\\Invader\\alien.bmp",
		cVector(0.0, 0.0, 0.48)));
	_meshSkinNameTripleArray.Add(cMeshSkinNameTriple(
		"models\\Ogro\\Tris.MD2", "models\\Ogro\\ogrobase.pcx",
		cVector(0.0, 0.0, 0.45)));
	_meshSkinNameTripleArray.Add(cMeshSkinNameTriple(
		"models\\Ripper\\Tris.MD2", "models\\Ripper\\ripper.pcx",
		cVector(0.0, 0.0, 0.85)));
	_meshSkinNameTripleArray.Add(cMeshSkinNameTriple(
		"models\\bignose\\tris.MD2", "models\\bignose\\Bignose.pcx",
		cVector(-0.15, 0.0, 0.08)));

//Select the cursor tools
	_arrayHCURSOR.Add(((CPopApp*)::AfxGetApp())->_hCursorArrow); //Avaiable cursor tools.
	//_arrayHCURSOR.Add(((CPopApp*)::AfxGetApp())->_hCursorPlay); 
	//_arrayHCURSOR.Add(((CPopApp*)::AfxGetApp())->_hCursorPin);
	//_arrayHCURSOR.Add(((CPopApp*)::AfxGetApp())->_hCursorReplicate); 
	//_arrayHCURSOR.Add(((CPopApp*)::AfxGetApp())->_hCursorDragger);
	//_arrayHCURSOR.Add(((CPopApp*)::AfxGetApp())->_hCursorSpawn);
	//_arrayHCURSOR.Add(((CPopApp*)::AfxGetApp())->_hCursorZap); 
//Set the player, we want to make sure a game always has a player
	setPlayer(new cCritterPlayer(this)); //Sets _pplayer AND adds it to _pbiota.
}

cGame::cGame(cBiota *pbiota)
{
	delete _pbiota; //Get rid of the cBiota* that the default constructor gave you.
	_pbiota = NULL;
	_pbiota = pbiota;
	_pbiota->setGame(this); 
//Deleting the _pbiota killed off your _pplayer, so you need to get a new one.
	if (_pbiota->GetSize()>0) // use the first member of pbiota if there is one.
		_pplayer = _pbiota->GetAt(0);
	else //otherwise make a dummy. 
	{
		cCritter* pdummyplayer = new cCritter();
		setPlayer(pdummyplayer);
	}
}

cGame::~cGame()
{
	int playerindex = _index(_pplayer);
	if (playerindex == cBiota::NOINDEX) //player won't be deleted by cBiota destructor
	{
		delete _pplayer; /* I need to do this while the _pbiota is still good,
			as the delete _pplayer will call the ~cCritter, which will use
			_pbiota to find the pgame to call fixPointerRefs with. */
		_pplayer = NULL;
	}
	delete _pskybox;
	_pskybox = NULL;
	delete _pbiota;
	_pbiota = NULL;
	delete _pcollider;
	_pcollider = NULL;
	delete _pcontroller;
	_pcontroller = NULL;
	delete _plightingmodel;
	_plightingmodel = NULL;
/* At game exit, we release any of the shared cSpriteQuake model resources that we've
allocated from within the quakeMD2model.cpp file. I might have expected to
do this in the ~PopApp destructor in pop.cpp, but for some reason when I
get to that destructor, the information in the two static _map... fields has been
lost track of without being deleted. */
	cTextureInfo::_mapFilenameToTextureInfo.free();
	cMD2Model::_mapFilenameToMD2Info.free();
	stopMusic();
}

void cGame::removeReferencesTo(cCritter *pdeadcritter)
{
	_pbiota->removeReferencesTo(pdeadcritter);
	_pcollider->removeReferencesTo(pdeadcritter);
}

void cGame::Serialize(CArchive& ar)
{
	int focusindex, playerindex;
 	CObject::Serialize(ar);
  		/*It's worth noting that when we call this next line in loading mode,
 			the _pbiota will be pointing in a non-NULL cBiota that was created by the 
 			cGame constructor, so we'll need to have the cBiota::Serialize take care of
 			deleting members of an existing cBiota before loading into it. */
	_pbiota->Serialize(ar);
 		/* I don't serialize _arrayHCURSOR because (a) it gets set by the constructor 
 			and (b) it's like a	pointer in that the numerical value will depend on the 
 			program run, so the number would be useless. */
  	_pcontroller->Serialize(ar);
	_plightingmodel->Serialize(ar);
 	if (ar.IsStoring()) // Save 
 	{
 		focusindex = _index(_pfocus);
 		playerindex =  _index(_pplayer);
 		ar << _seedcount << _gameover << _maxscore << _scorecorrection << _wrapflag <<
 			_bDragging << _border << _pskybox <<
 			focusindex << playerindex << _autoplay << _level <<  _spritetype ;
 		if (playerindex == cBiota::NOINDEX)
 			ar << _pplayer;
 	}
  	else //Load 
 	{
		delete _pskybox;
 		ar >> _seedcount >> _gameover >> _maxscore >> _scorecorrection >> _wrapflag >>
 			_bDragging >> _border >> _pskybox >>
 			focusindex >> playerindex >> _autoplay >> _level >> _spritetype;
 		if (focusindex != cBiota::NOINDEX)
 			_pfocus = _pbiota->GetAt(focusindex);
 		if (playerindex == cBiota::NOINDEX)
 		{
 			delete _pplayer; /* If _pplayer is not in the cBiota, it wasn't deleted in
 				cBiota::Serialize so we delete it here.  But in the else case below,
 				_pplayer equals one of the pointers deleted in the cBiota::_free call
 				in cBiota::Serialize, so it is actually a bad pointer and we don't delete
 				it. */
			_pplayer = NULL;
 			ar >> _pplayer;
 			_pplayer->setOwner(_pbiota);
 			_pplayer->fixPointerRefs();
 		}
 		else /* _pplayer is a bad (already deleted) pointer; we overwrite it without
 					deleting again. */
 			_pplayer = _pbiota->GetAt(playerindex);
		_pcollider->build(_pbiota); /* Build up the array of cColliderPair objects
			using the freshly created pointers inside the _pbiota. */
		setAutoplay(_autoplay); //If _autoplay is TRUE, we have to call this to fix the controller.
 	}
 }

//Cursor toolmethods------------------------
int cGame::_HCURSORindex(HCURSOR hcursor)
{
	for (int i=0; i<_arrayHCURSOR.GetSize(); i++)
		if (_arrayHCURSOR.GetAt(i) == hcursor)
			return i;
	return cBiota::NOINDEX; //Use -1 to mean not found.
}

HCURSOR cGame::nextHCURSOR(HCURSOR hcursor, int updown)
{
	if (!validHCURSOR(hcursor))
		return hcursor;
	if (updown <= 0)
		updown = -1;
	else
		updown = 1;
	int index = _HCURSORindex(hcursor);
	index += updown;
	if (index < 0)
		index = _arrayHCURSOR.GetSize()-1;
	else if (index > _arrayHCURSOR.GetSize()-1)
		index = 0;
	return _arrayHCURSOR[index];
}
	
BOOL cGame::validHCURSOR(HCURSOR hcursor)
{
	return _HCURSORindex(hcursor) != cBiota::NOINDEX;
}

//-----------------Background methods----------
void cGame::setBorder(Real dx, Real dy, Real dz)
{
	_border.set(dx, dy, dz);
	fixSkyBox();
}

void cGame::setBorder(const cVector &locorner, const cVector &hicorner)
{
	_border.set(locorner, hicorner);
	fixSkyBox();
}

void cGame::setBorderZRange(Real loz, Real hiz)
{
	_border.setZRange(loz, hiz);
	fixSkyBox();
}

void cGame::fixSkyBox()
{
	cRealBox3 skeleton = _border;
	if (skeleton.zsize() < 0.5)
		skeleton.setZRange(cGame::BACKGROUNDOFFSET, 1.0); /* Move LOZ down to 
			avoid z-fighting with sprites in the xy plane.  MOve HIZ up to make
			walls around the world.*/
	setSkyBox(skeleton.locorner(), skeleton.hicorner(), -1);
	//Make the walls four shades.
	pskybox()->setSideSolidColor(LOX, RGB(180, 30, 200));
	pskybox()->setSideSolidColor(HIX, RGB(30, 10, 180));
	pskybox()->setSideSolidColor(LOY, RGB(255, 200, 200));
	pskybox()->setSideSolidColor(HIY, RGB(10, 255, 200));
	//Make floor be almost black
	pskybox()->setSideSolidColor(LOZ, RGB(15, 15, 15));
	//Make the top side transparent
	pskybox()->setSideInvisible(HIZ); /* Means make it gray and
		don't draw it. */
	pskybox()->setEdged(FALSE); //Turns off edges for the filled faces.
	pskybox()->setLineColor(cColorStyle::CN_DARKGRAY);
	pskybox()->setLineWidthWeight(cColorStyle::LW_IGNORELINEWIDTHWEIGHT);
	pskybox()->setLineWidth(1);
}

void cGame::setSkyBox(cVector locorner, cVector hicorner,
	int resourceID)
{
	if (_pskybox)
		delete _pskybox;
	_pskybox = NULL;
	_pskybox = new cSpriteTextureBox(locorner, hicorner, resourceID);
//	_pskybox->setColorStyle(new cColorStyle());
}

void cGame::setBackgroundBitmap(int resourceID)
{
   // Joseph E. Sutton
	pskybox()->pskeleton()->setZRange(-1.0, pskybox()->pskeleton()->hiz());
	pskybox()->setSideTexture(LOZ, resourceID, 1);
}

void cGame::drawCritters(cGraphics *pgraphics, int drawflags)
{
	_pbiota->draw(pgraphics, drawflags);
}

void cGame::drawWorld(cGraphics *pgraphics, int drawflags)
{
	drawBackground(pgraphics, drawflags); //Uses skybox
/* This is the end of drawWorld.  What about drawForeground?  That is
	only used by cGraphicsMFC::display, which calls it on its own. */

#ifdef TESTGLTEXT 
	testtext(pgraphics); //Code for this is at the bottom of the file.
#endif TESTGLTEXT 
}

void cGame::drawBackground(cGraphics *pgraphics, int drawflags)
{
		/* I'm going to interpret the DF_FULL_BACKGROUND flag
		as meaning draw the solid skybox, and I'm going to interpret
		the DF_SIMPLIFIED_BACKGROUND as meaning draw a wireframe skybox. 
			I don't make a separate case for !pgraphics()->is3D, as in that
		case my cSpriteTexturebox::draw just calls
		call _childspriteptr[LOZ]->draw(pgraphics, drawflags);*/
	if (drawflags & CPopView::DF_FULL_BACKGROUND)
	{
		drawflags &= ~CPopView::DF_WIREFRAME; //turn off wireframe
			_pskybox->draw(pgraphics, drawflags | CPopView::DF_DRAWING_SKYBOX);
	}
	else if (drawflags & CPopView::DF_SIMPLIFIED_BACKGROUND)
	{
		drawflags |= CPopView::DF_WIREFRAME; //turn on wireframe
		if (_pskybox)
			_pskybox->draw(pgraphics, drawflags | CPopView::DF_DRAWING_SKYBOX);
	}
	//else don't draw SIMPLIFIED or FULL background, that is, draw nothing.
}

void cGame::drawForeground(cGraphics *pgraphics, int drawflags)
{ //This is only called from cGraphicsMFC::display
	if (!pgraphics->is3D())
	{
		cSpriteRectangle temprect(_border.lox(), _border.loy(),
			_border.hix(), _border.hiy());
		temprect.setEdged(TRUE);
		temprect.setFilled(FALSE);

      // Function: Draws Border
      // Changed: Color
      // Modified by: Joseph E. Sutton
		temprect.setLineColor(cColorStyle::CN_LIGHTGRAY);

		temprect.setLineWidth(1);
		temprect.setLineWidthWeight(cColorStyle::LW_IGNORELINEWIDTHWEIGHT); 
			/* This means the edge is drawn
			to have width 0.2 of the world radius in graphicsMFC.  Default
			_linewidthweight is 0.05, which is a bit too wide. */
		temprect.draw(pgraphics, drawflags);/* Can draw some more
			foreground furniture if pgame likes. */
	}
}

//---------------- Player methods------------

int cGame::score()
{
	ASSERT(_pplayer);
	return _pplayer->score();
}

int cGame::health()
{
	ASSERT(_pplayer);
	return _pplayer->health();
}

Real cGame::age()
{
	ASSERT(_pplayer);
	return _pplayer->age();
}

CRuntimeClass* cGame::playerListenerClass()
{
	ASSERT(_pplayer);
	ASSERT(_pplayer->plistener());
	return (_pplayer->plistener()->GetRuntimeClass());
}

void cGame::setPlayer(cCritter *pplayernew, BOOL onscreen) //onscreen is TRUE by default
{
	int oldplayerindex, newplayerindex;
//Bail if you're mistakengly trying to set a NULL player
	ASSERT(pplayernew);
//Kill off the existing _pplayer if its not the same as pplayernew.
	if (pplayernew != _pplayer)
	{
	//First remove the old player
		if (_pfocus == _pplayer)
		_pfocus = NULL;
		oldplayerindex = _index(_pplayer);
		delete _pplayer;
		_pplayer = NULL;
		if (oldplayerindex != cBiota::NOINDEX)
			_pbiota->RemoveAt(oldplayerindex);
	}
/* You are going to directly manipulate the _pbiota array in the rest of this call,
	so before doing this, make sure there aren't any outstanding service requests
	that might, for instance, add some pointer into the pbiota after you've deleted
	it in here. There's also the likelihood that you already have an outstanding 
	add_me request for your pplayernew, particularly if the call that got you here
	has the form setPlayer(new cCritterArmedPlayer(this)), as the inner constructor
	call will have made an add_me request.
*/
	_pbiota->processServiceRequests();
//Now initialize the _pplayer field.
	_pplayer = pplayernew;
//Put the pplayer in the 0 slot, and if it happens somehow to already be present
//in some other slot, remove it from there.
	newplayerindex = _index(pplayernew);
	if (onscreen) //You want player onscreen, that is, in cBiota, put it in.
	{
		if (newplayerindex == cBiota::NOINDEX) // newplayer wasn't in cBiota yet
		{
			add(pplayernew); //Call this for various cGame::add side-effects
			_pbiota->processServiceRequests(); /* Force the add to happen to _pbiota now.
				This forces a call to cBiota::Add(pplayernew), which will also update the
				_pcollider */
			newplayerindex = _index(pplayernew); //Check the index again.
		}
		if (newplayerindex > 0) //newplayer is in cBiota but in wrong slot.  Move it!
		{
			_pbiota->RemoveAt(newplayerindex);
			_pbiota->InsertAt(0, _pplayer);
		}
	// Now my player is in the 0 slot. 
	}
	/* As a final step, in case we wanted the player offscreen and it happened already
	to be in cBiota, we remove it.*/
	if (!onscreen && newplayerindex != cBiota::NOINDEX)
	{
		_pbiota->RemoveAt(0);
		_pcollider->removeReferencesTo(_pplayer); /* The pcollider shouldn't want to bump a
			non onscreen player. */
		_pplayer->setOwner(NULL); //Make sure it doesn't think it's in the cBiota.
	}
}

void cGame::setNewgeometryflag(BOOL onoff)
{
	pbiota()->setNewgeometryflag(onoff);
	pskybox()->setNewgeometryflag(onoff);
}

void cGame::setAutoplay(int autoplay)
{
	_autoplay = autoplay;
	if (_autoplay)
	{
		_pcontroller->setKeystate(VK_SPACE, cController::KEYONLOCK);
		_pcontroller->setKeystate(VK_LEFT, cController::KEYONLOCK);
		_pcontroller->setKeystate(VK_UP, cController::KEYONLOCK);
	}
	else
	{
		_pcontroller->setKeystate(VK_SPACE, cController::KEYOFF);
		_pcontroller->setKeystate(VK_LEFT, cController::KEYOFF);
		_pcontroller->setKeystate(VK_UP, cController::KEYOFF);
	}
}

//------------------- Basic accessor and mutator methods --------------------------
void cGame::setSeedcount(int seedcount)
{
	_seedcount = seedcount;
	seedCritters();
	_pbiota->processServiceRequests();
		 //Do this here to double check that the adds from a possibly overloaded seedCritters take effect.
}

void cGame::setWrapflag(int wrapflag)
{
	_wrapflag= wrapflag;
	_pbiota->setWrapflag(_wrapflag);
}

void cGame::restart()
{
	/* This  sets	_pgame-_gameoverflag to FALSE to start
		the game in case its not currently running.  In addition, it calls _pgame->reset()
		to reset the player, call pgame->seedCritters, etc. */
	reset(); //Also sets _pplayer->age() to 0, which is what we get in the cGame::age() call.
	_gameover = FALSE; //Start running.
}

void cGame::start()
{
	_newgame = FALSE; //Next time use restart.
	_gameover = FALSE; //Start running
}

void cGame::reset()
{
	_level = 1; /* Go back to the first level.  If you've changed the furniture of the
		world at higher levels, you'll need to put that stuff back as well. */
	_pplayer->reset();  
	seedCritters();
	_pbiota->processServiceRequests();
		 //Do this here to double check that the adds from a possibly overloaded seedCritters take effect.
}

void cGame::setSpritetype(int spritetype)
{
	_spritetype = spritetype;
	seedCritters();
}

void cGame::add(cCritter* pcritter, BOOL immediateadd)
{
	pcritter->setMoveBox(border());
	pcritter->setDragBox(border());
	pcritter->setWrapflag(_wrapflag); //Make sure to do this after setting _movebox, as it calls a clamp.
	pcritter->add_me(_pbiota, immediateadd); 
/* cBiota::Add is protected to prevent abuse such as adding a member during
the middle of an update before everyone's ready.  It gets invoked only by a call to the
cBiota::processServiceRequests method, acting on all the pcritter who filed an add_me request.
At first I thought I should force the add to happen right away with the following line,
but it turns out that's not necessary, and would be a bad idea as it defeats the whole
purpose of our service requests structure.  If for instance an individual critter calls
the add method during its update, it really is better not to force the processServiceRequests,
and to first finish the updates of the other critters. If you want to force
an immediate add, you set immediateadd to TRUE. */ 
//	_pbiota->processServiceRequests(); //DON'T DO THIS!!!!!!!!!
}

//--------------------Fundamental running methods------------------------

	/* OnIdle happens right before the cGame::step method, which is called from inside
		CPopDoc::stepDoc, which is called from inside OnIdle.  Note that the first part of OnIdle, 
		is where the OnKeyDown, OnLButtonDown, etc. messages in queues are processed. */

void cGame::step(Real dt, CPopView *pactiveview)
{
	Real runspeed = ((CPopApp*)::AfxGetApp())->runspeed();
	Real realdt;
	if (runspeed)
		realdt = dt/runspeed;
		/* I may be running my game at a slowed-down _runspeed, as I do with
		cGameSpacewarSun. The dt that cGame gets is actually _runspeed * realdt,
		where realdt is the actual elapsed time in the user's physical world.
		We want to use realdt for the controls, so the controls don't feel 
		slowed down or speeded up. */
	_pcontroller->update(realdt); /* Do controller update first, when you're fresh from the OnIdle
		call that did the checking of messages as this, too, checks user input. The mouse
		click handling code of cController expects you to do the update right after the 
		standard mouse processing of OnIdle, so don't move this call. This call also stores
		the current dt value inside the controller. And don't use the dt = 0.0.*/
	if (_gameover) //Meaning you haven't pressed ENTER for the first time.
		dt = 0.0; /*  Prevents the lurch at startup when I turn _gameover off, also
			prevents anything from happening in the move or update methods when _gameover. */
	if (!visibleplayer())
		_pplayer->setAge(_pplayer->age() + dt); 
			/* Invisible player isn't aged by move, 
			so age it anyway for use in age() method. */
	adjustGameParameters();
	_pbiota->feellistener(dt); /* Critters listen to the _pcontroller data,
			possibly using _cursorpos. 	The cCritterArmedPlayer, in particular, will
			look at the _cursorpos if left button is down.  Use the dt to adjust velocity if you have a 
			cListenerCursor, */

	_pbiota->move(dt); /* Critters save current position as _oldposition, use
			their _velocity and _acceleration to compute a new position, possibly wrap or bounce
			this position off the _border and then set the new _position. */
	_pbiota->updateMetric(); //Possibly fill a look-up table for use in update and collide.
	_pbiota->update(pactiveview, dt); /* Feel any forces acting on the critter, possibly call sniff
			on pview to	check some pixel colors in the world to maybe back off from something 
			or 	kill something. We don't presently use the dt argument, but could use it for
			shrinking critter radius. */
	if (dt > 0.0) //Prevent constant readjustment when paused
		collideStep(); //Critter may abruptly change _position and _velocity in here.
	_pbiota->processServiceRequests();
	_pbiota->animate(dt);
		//And now the CPopDoc::stepDoc will redraw each view via UpdateAllViews(timehint(dt))
}

void cGame::collideStep()
{
#ifdef LIMITCOLLISIONSPERUPDATE //May be defined in collider.h
	for (int i=0; i<pbiota()->GetSize(); i++)
		pbiota()->GetAt(i)->setLastCollidePartnerPriority(cCollider::CP_MINIMUM);
#endif
	_pcollider->iterateCollide();
}

//-----------------Special overloadables--------------------------------

 void cGame::seedCritters()
 {
 	cCritter *newcritter;
 	_pbiota->purgeNonPlayerNonWallCritters(); /* Clean out all critters but player and
 		walls, in case you have walls. */
 	for (int i=0; i < _seedcount; i++)
 	{
 		newcritter = new cCritter(this); /* The this argument adds the critter to the game,
			and sets its _movebox and _dragbox to the game _border, sets its _wrapflag
			to match the game's _wrapflag. */
 		newcritter->randomize(cCritter::MF_POSITION | cCritter::MF_VELOCITY); 
 		newcritter->setSprite(randomSprite(_spritetype));
   		newcritter->addForce(new cForceEvadeBullet()); /* Default force for evading the 
 			cBullet objects that the player fires. This force is a child of 
 			cForceClassEvade with default constructor equivalent 
 			to cForceClassEvade(cForceEvadeBullet::DARTACCELERATION, cForceEvadeBullet::DARTSPEEDUP,
 			RUNTIME_CLASS(cCritterBullet), FALSE). The FALSE in the fourth arg, means don't
 			bother evading children of cCritterBullet. */
 	} 
}

CString cGame::gameOverMessage()
{
	CString cStrScore;
	cStrScore.Format("%d", score());
	return CString("Your Score Was ") +
		cStrScore +
		CString(" !\nTo Start a New Game...\n\n PRESS ENTER !");
}

CString cGame::statusMessage()
{
	CString cStrStatusBar;
	int nUpdatesPerSecond;
	CString cStrUpdatespersecond;
	CString cStrHealth;
	CString cStrCount;
	CString cStrScore;
	CString cStrCollisionCount; //Usually leave empty

	if (!gamepaused())
	{
		nUpdatesPerSecond = int(((CPopApp*)::AfxGetApp())->_timer.updatesPerSecond());
		if (!nUpdatesPerSecond)
			cStrUpdatespersecond.Format("Less than one update per second.");
		else	
			cStrUpdatespersecond.Format("Updates per second: %d.", nUpdatesPerSecond);
		if (((CPopApp*)::AfxGetApp())->_timer.runningNearMaxSpeed())
			cStrUpdatespersecond += " (Near Max)";
		if (((CPopApp*)::AfxGetApp())->_timer.runningNearMinSpeed())
			cStrUpdatespersecond += " (Slower than Real Time)";
	}
	else
			cStrUpdatespersecond.Format("Animation is paused.");
	cStrScore.Format("Score: %d.", score());
	cStrHealth.Format("Health: %d.", health());
//	cStrCollisionCount.Format("Collide-Checks: %d.", pcollider()->GetSize());
	int crittercount = _pbiota->count(RUNTIME_CLASS(cCritter));
#ifndef DONTCOUNTALLCRITTERS
	cStrCount.Format("Total Critters: %d.", crittercount);
#else //DONTCOUNTALLCRITTERS
	int bulletcount = _pbiota->count(RUNTIME_CLASS(cCritterBullet));
	crittercount -= bulletcount;
	if (visibleplayer()) /*Subtract off 1 for player as well. */
		crittercount -= 1;
	cStrCount.Format("Other Critters: %d.", crittercount);
#endif //DONTCOUNTALLCRITTERS
	cStrStatusBar = cStrScore + "  " + cStrHealth + "  " + cStrCount + "  " + cStrUpdatespersecond + 
		"  " + cStrCollisionCount; 
	return cStrStatusBar;
}

/*pgame()->initializeView is called by the pview->OnUpdate when starting a new game. */
void cGame::initializeView(CPopView *pview)
{
	pview->setCursor(((CPopApp*)::AfxGetApp())->_hCursorArrow);
	pview->setUseBackground(CPopView::FULL_BACKGROUND); /* The background type can be
		CPopView::NO_BACKGROUND, CPopView::SIMPLIFIED_BACKGROUND, or 
		CPopView::FULL_BACKGROUND, which often means: nothing, lines, or
		planes&bitmaps, depending on how the skybox is defined. */
	pview->setGraphicsClass(RUNTIME_CLASS(cGraphicsMFC)); //Cheap
//Some possible overrides:
	//pview->setUseSolidBackground(FALSE); //For no background at all, faster in 3D.
	//pview->setCursor(((CPopApp*)::AfxGetApp())->_hCursorPlay);
		//To use the crosshair cursor for shooting with mouse clicks.
	//pview->pviewpointcritter()->setTrackplayer(TRUE);
		/* To scroll after the player critter if it moves off screen.  This can be
		confusing, but is useful if you plan to use a zoomed in view. */ 
	//pview->setGraphicsClass(RUNTIME_CLASS(cGraphicsOpenGL)); //For 3D graphics
	//pview->pviewpointcritter()->setListener(new cListenerViewerRide());
		//To ride the player; this only works in 3D.
}

/*pgame()->initializeView(pviewer) is called by the pview->OnUpdate when starting a new game,
and it is also called when you use the menu to change the graphics class. */
void cGame::initializeViewpoint(cCritterViewer *pviewer)
{
		/* The two args to setViewpoint are (directiontoviewer, lookatpoint).
			Note that directiontoviewer points FROM the origin TOWARDS the viewer. */
		/* The two args to setViewpoint are (directiontoviewer, lookatpoint).
			Note that directiontoviewer points FROM the origin TOWARDS the viewer. */
	if (pviewer->is3D())
		pviewer->setViewpoint(cVector3(0.0, -1.0, 2.0), _border.center());
			//Direction to viewer is down a bit, and back off less than that.
	else //2D case.
		pviewer->setViewpoint(cVector::ZAXIS, _border.center());
}

//============cGame control methods===================

void cGame::onLButtonDown(CPopView *pview, UINT nFlags, CPoint point)
{
	if (gameover() || gamepaused())
		return; //Don't use mouse or keyborad messages until game starts.
	/*This next line is a little ugly in that it is specifically mentioning one kind of cursor.  
A more general way to do this would be to put the pview pointer into the _pcontroller record that
registers the onLButtonDown, and then when we got this record out to check the value of the
pview->hcursor(). */
	if ((pview->hcursor() == ((CPopApp*)::AfxGetApp())->_hCursorPlay) ||
		playerListenerClass() == RUNTIME_CLASS(cListenerCursor))
	/* We  put a left click into the _pcontroller for the individual critters to see it if
		either we have the hCursorPlay cursor, which is used for shooting, or if our player happens
		to be using	a ListenerCursor. */
		_pcontroller->onLButtonDown(nFlags); /* Don't need to save point, as that's handled
			by the trackCursor method. */
	if (playerListenerClass() == RUNTIME_CLASS(cListenerCursor))
		/* Don't try and use the cursor as a tool if its attached to the player. */
		return; 
	cCritter* pTouched = NULL;
	//Find the first bubble from the tail, if any, which you clicked.
	//pTouched = _pbiota->pickLowestIndexTouched(cursorpos()); //I used to do the pick like this, and it worked OK.
	//pTouched = _pbiota->pickClosestTouched(cursorpos());  //And then I did it like this, not good.
	//pTouched = _pbiota->pickClosestTouched(pview->pgraphics()->pixelToSightLine(point.x, point.y));
		/* And then I did this, since using the sight line works better once you go to 3D. 
			But this doesn't work in 2D with cGraphicsMFC.  */
	/* And finally I did this.  This "TopTouched" picks the top relative to this line.
		I need to define the sight line different ways for 2D and 3D graphics, so I let
		 cGraphics children overload pixelToSightLine. */
	pTouched = _pbiota->pickTopTouched(pview->pgraphics()->pixelToSightLine(point.x, point.y));
/* Click any cursor except cursor play (shoot cursor) sets focus to a clicked critter,
	or to nothing if you missed 'em. Don't let playcursor setFocus, because a focus critter
	doesn't move, and this would make it too much a sitting duck. */
	if ((pview->hcursor() != ((CPopApp*)::AfxGetApp())->_hCursorPlay) )
		setFocus(pTouched);
//No bubble clicked case doesn't apply for the Pin and the Hand.
	if (!pTouched)
		return;
//Put it on top.
	pTouched->makeServiceRequest("move_to_front"); //Only has visible effect in 2D worlds.
//Click Hand case 
	if (pview->hcursor() == ((CPopApp*)::AfxGetApp())->_hCursorDragger)
	{ //The draggable condition checks if the critter is willing to be dragged.
		if (pTouched->draggable())
		{
			//setFocus(pTouched); //I don't think I need this line, do I?
			_bDragging = TRUE; 
			onMouseMove(pview, nFlags, point); //Move to the click point.
		}
		return; /* Note that here we leave the _pfocus on the move critter, 
			which has the sideeffect that cBiota::move doesn't move it,	
			which is good. */
	}
//Click Pin case
	if (pview->hcursor() == ((CPopApp*)::AfxGetApp())->_hCursorPin && pTouched != pplayer())
		pTouched->die(); //makes "delete_me" request, possibly does more
//Click Spawn case
	if (pview->hcursor() == ((CPopApp*)::AfxGetApp())->_hCursorSpawn)
		pTouched->spawn(); //makes "spawn" request for mutated copy.
//Click Zap case
	if (pview->hcursor() == ((CPopApp*)::AfxGetApp())->_hCursorZap)
		pTouched->zap(); //makes "zap" request for this guy.
//Click Replicate case
	if (pview->hcursor() == ((CPopApp*)::AfxGetApp())->_hCursorReplicate)
		pTouched->replicate(); //makes "replicate" request for this guy.
	_pbiota->processServiceRequests(); /* So you don't change critter
		twice.  If you wait for the timer to trigger CPopDoc::stepDoc
		to call the processServiceRequest, you might possibly manage to
		click or drag the same critter again.  The reason is that you may
		have several OnLButtonDown messages in the message queue, and when they
		are processed you will get several calls to onLButtonDown. */
#ifdef FREEZEPICKCRITTER
	if ((pview->hcursor() != ((CPopApp*)::AfxGetApp())->_hCursorArrow) )
#endif //FREEZEPICKCRITTER
		setFocus(NULL); /* For all of these one-time actions, we release
			the pfocus after the action, because it's confusing to see
			the critter frozen in focus after you zap it for instance.
			(The freeze woudl be because cBiota::move doesn't move the
			pfocus.)  We will for now leave in the freeze on the pick 
			cursor, though maybe that's a bad idea. */
}

void cGame::onLButtonUp(CPopView *pview, UINT nFlags, CPoint point)
{
	if (gameover() || gamepaused())
		return; //Don't use mouse or keyborad messages until game starts.
	/* We let the cController::FAKELBUTTONKEY Key mimic the LButton.  So if it is still down,
		 then we are waiting for it to come up to generate the onLButtonDown.*/
	if 	(keystate(cController::FAKELBUTTONKEY) != cController::KEYOFF)
		return;

	if ((pview->hcursor() == ((CPopApp*)::AfxGetApp())->_hCursorPlay) ||
		playerListenerClass() == RUNTIME_CLASS(cListenerCursor))
	/* We only pass on a left click to the individual critters like the player if either we have
		 the hCursorPlay cursor, which is used for shooting, or if our player happens to be using
		a ListenerCursor. */
		_pcontroller->onLButtonUp(nFlags); //trackCursor already saved the point.
	if (playerListenerClass() == RUNTIME_CLASS(cListenerCursor))
		/* Don't try and use the cursor as a tool if its attached to the player. */
		return; 
	_bDragging = FALSE; 
	if (pview->hcursor() == ((CPopApp*)::AfxGetApp())->_hCursorDragger)
		setFocus(NULL);
}

void cGame::onMouseMove(CPopView *pview, UINT nFlags, CPoint point)
{
	if (gameover() || gamepaused())
		return; //Don't use mouse or keyborad messages until game starts.
	/* We pass this on, but ordinarily the critters don't do anything with it. */
	_pcontroller->onMouseMove(nFlags);
	if (playerListenerClass() == RUNTIME_CLASS(cListenerCursor))
		/* Don't try and use the cursor as a tool if it's attached to the player. */
		return; 
//The _cursorpos gets set in CView::OnMouseMove if you're dragging.
// No Drag Case
	if (!(nFlags & MK_LBUTTON || keystate(cController::FAKELBUTTONKEY) != cController::KEYOFF) )
		return;		//We are treating the cController::FAKELBUTTONKEY Key as an alternate LButton.
// Drag Pin Case
#ifdef DRAGGINGPINKILLS
	if (pview->hcursor() ==((CPopApp*)::AfxGetApp())->_hCursorPin)
	{
		onLButtonDown(pview, nFlags, point);
		return;
	}
#endif//
// Drag Hand Case, with (_hcursor == ((CPopApp*)::AfxGetApp())->_hCursorDragger)
	if (pFocus() && _bDragging)
	{
		cVector cursorforcritter = pview->pixelToCritterPlaneVector(point.x, point.y, pFocus());
			/* It's going to easier, at least to start with, to drag only within the focus critter
			plane. */
		pFocus()->dragTo(cursorforcritter, _pcontroller->dt()); /* Feed the current _dt to dragTo
			so as to set the critter's velocity to match the speed of the drag; this way you
			can "throw" a critter by dragging it. */
		_pbiota->processServiceRequests(); /* In case critter reacts.
		If you wait for the timer to trigger CPopDoc::stepDoc
		to call the processServiceRequest, you might possibly manage to
		click or drag the same critter again.  The reason is that you may
		have several OnMouseMove messages in the message queue, and when they
		are processed you will get several calls to onMouseMove. */
	}
}

	/* Let's use the cController::FAKELBUTTONKEY Key like a left mouse button to make dragging more ergonomic. And store
	info in keyflags. */
void cGame::onKeyDown(CPopView *pview, UINT nChar, UINT nFlags)
{
	if (gameover() || gamepaused())
		return; //Don't use mouse or keyborad messages until game starts.
	if (nChar == cController::FAKELBUTTONKEY) 
	{ //If you press cController::FAKELBUTTONKEY Key when Lbutton is not down, treat it like an lbutton press.
		if(keystate(cController::FAKELBUTTONKEY) == cController::KEYOFF 
			&& keystate(VK_LBUTTON) == cController::KEYOFF)
		{
			int ix, iy;
			Real zbuff;
			pview->vectorToPixel(_cursorpos, ix, iy, zbuff);
			onLButtonDown(pview, MK_LBUTTON, CPoint(ix,iy));
		//	if ((pview->hcursor() == ((CPopApp*)::AfxGetApp())->_hCursorPlay) ||
		//		playerListenerClass() == RUNTIME_CLASS(cListenerCursor))
			/* We only pass a left-click-mimicking Ctrl press to the individual critters like the
			 player if either we have the hCursorPlay cursor, which is used for shooting, or if 
			our player happens to be using	a ListenerCursor. */
				_pcontroller->setKeystate(cController::FAKELBUTTONKEY, cController::KEYON);
		}	
	}
	else
		_pcontroller->onKeyDown(nChar, nFlags);
}

	/* We won't pay attention to most onKeyUp messages.  Instead, 
	we let the _pcontroller use the global ::GetAsyncKeystate to look for released keys.
	This works better becuase then a controller will detect a key release even if a menu is 
	opened after the key is pressed and you then release the key with the  menu still open. 
	In the one case of the "fake left button" key we send an lButtonUp message to the game in case the
	game does some mouse code that's not filtered thorugh the contorller, which will
	in fact set VK_LBUTTON to match cController::FAKELBUTTONKEY. */
void cGame::onKeyUp(CPopView *pview, UINT nChar, UINT nFlags)
{
	if (gameover() || gamepaused())
		return; //Don't use mouse or keyborad messages until game starts.
	if (nChar == cController::FAKELBUTTONKEY) 
	{ //If you press cController::FAKELBUTTONKEY Key when Lbutton is not down, treat it like an lbutton press.
		if(keystate(cController::FAKELBUTTONKEY) == cController::KEYOFF 
			&& keystate(VK_LBUTTON) == cController::KEYOFF)
		{
		   int ix, iy;
		   Real zbuff;
		   pview->vectorToPixel(_cursorpos, ix, iy, zbuff);
		   _pcontroller->setKeystate(cController::FAKELBUTTONKEY, cController::KEYOFF); //Do now, or onLButtonUp won't work.
		   onLButtonUp(pview, MK_LBUTTON, CPoint(ix, iy));
      }
	}
   else
		_pcontroller->onKeyUp(nChar, nFlags);
}

//================= 3D Stuff=====================

BOOL cGame::in3DWorld()
{
	return border().zsize() > cRealBox3::MINSIZE;
}

void cGame::zStackCritters()
{
	/* For this to work, your constructor should contain this line so that your flat disk 
		critters don't mistakenly get clamped away from being in the range of DEPTH.
		setBorderZRange(0.0, cGame::DEFAULTZDEPTH + 2*cCritter::MAXRADIUS );  
	*/ 
	_pbiota->processServiceRequests(); /* In case you added critters and didn't 
		process the service requests yet to really add them, so count is right. */
	Real dz = (_border.zsize() - 2*cCritter::MAXRADIUS)/(pbiota()->count() + 2); /* Want to layer the critters in the z
		direction, leaving a space at the top and the bottom. The usual convention is to think
		of the biota as listing critters from closest to furthest, so we move down. */
	Real critterz = _border.hiz() - cCritter::MAXRADIUS - dz;
	
	ASSERT(_pbiota->count());
	for (int i=0; i< _pbiota->count(); i++)
	{
		_pbiota->GetAt(i)->moveToZ(critterz);
		critterz -= dz;
	}
}

//======================Factory Methods==============================
cSprite* cGame::randomSprite(int spritetypeindex)
{
	cPolygon *newpoly;
	cSpriteBubble *newbubble;
	cPolyPolygon *newpolypoly;
	cSpriteIcon *picon;
	cSpriteQuake *pspritequake;
	cSpriteSphere *psphere;

	if (spritetypeindex == cGame::ST_ASSORTED)
		spritetypeindex = cRandomizer::pinstance()->random(cGame::ST_ASSORTED);
			//Select a random index less than cGame::ST_ASSORTED
	/* This next block should be a switch, but the compiler won't let me use the cGame:: constants
		in a switch. */
	if(spritetypeindex == cGame::ST_SIMPLEPOLYGONS)
	{
		newpoly = new cPolygon(cRandomizer::pinstance()->random(3,5));
		newpoly->randomize(//cSprite::MF_RADIUS | 
			 cPolygon::MF_COLOR);
		return newpoly;
	}
	else if(spritetypeindex == cGame::ST_FANCYPOLYGONS)
	{
		newpoly = new cPolygon();
		newpoly->randomize(//cSprite::MF_RADIUS | 
			cPolygon::MF_COLOR | cPolygon::MF_LINEWIDTH |	cPolygon::MF_DOTS | cPolygon::MF_VERTCOUNT);
		return newpoly;
	}
	else if(spritetypeindex == cGame::ST_ASTEROIDPOLYGONS)
	{
		newpoly = new cPolygon();
		newpoly->setRandomAsteroidPolygon(5, 20, cRandomizer::pinstance()->randomReal(0.0, 0.4));
		newpoly->randomize(//cSprite::MF_RADIUS 
			 cPolygon::MF_COLOR);
		return newpoly;
	}
	else if(spritetypeindex == cGame::ST_BUBBLES)
	{
#ifndef ONLYPLAINBUBBLES
		if (cRandomizer::pinstance()->randomBOOL(0.5)) //60% cSpriteBubblePie
			newbubble = new cSpriteBubblePie();
		else if (cRandomizer::pinstance()->randomBOOL(0.75)) //0.75*0.4 make 30% cSpriteBubble
			newbubble = new cSpriteBubble();
		else //Leave 10% cSpriteBubbleGrayscale
			newbubble = new cSpriteBubbleGrayscale();
#else //ONLYPLAINBUBBLES
			newbubble = new cSpriteBubble();
#endif //ONLYPLAINBUBBLES
		newbubble->randomize( //cSprite::MF_RADIUS | 
			cPolygon::MF_COLOR | cPolygon::MF_LINEWIDTH );
		return newbubble;
	}
	else if(spritetypeindex == cGame::ST_SPHERES)
	{
		psphere = new cSpriteSphere();
		psphere->randomize( cPolygon::MF_COLOR );
		COLORREF fill = psphere->fillColor();
		return psphere;
	}
	else if(spritetypeindex == cGame::ST_POLYPOLYGONS)
	{
#ifdef MINIMALPOLYPOLYS
		return new cPolyPolygon(4, 3);
#else //not MINIMALPOLYPOLYS
		newpolypoly = new cPolyPolygon();
		newpolypoly->randomize(//cSprite::MF_RADIUS | 
			cPolygon::MF_COLOR | cPolygon::MF_LINEWIDTH | cPolygon::MF_DOTS | 
			cPolygon::MF_VERTCOUNT); 
		return newpolypoly;
#endif //MINIMALPOLYPOLYS switch
	}
	else if(spritetypeindex == cGame::ST_TRIPLEPOLYPOLYGONS)
	{
//#define POLYPOLYOFBITMAPS 
	/* Comment this in to have the option of showing a polygon with bitmaps
	at its vertices.  Otherwise we get a polygon with polypolygons. At present
	we don't use either one, as there is no menu access for
	 ST_TRIPLEPOLYPOLYGONS, and none of our critter consturctors asks for it. */
#ifdef POLYPOLYOFBITMAPS
	/*This doesn't seem to work right; in cGrahicsMFC the bitmaps don't have
	transparent backgrounds, and in cGraphicsOpenGL, the bitmaps cause a 
	resource leak. */
		newpolypoly = new cPolyPolygon;
		newpolypoly->randomize(//cSprite::MF_RADIUS | 
			cPolygon::MF_COLOR | cPolygon::MF_LINEWIDTH | cPolygon::MF_DOTS |
			 cPolygon::MF_VERTCOUNT); 
		newpolypoly->setTipShape(randomSprite(cGame::ST_BITMAPS));
		return newpolypoly;
#else  //not the POLYPOLYOFBITMAPS case
		newpolypoly= new cPolyPolygon();
		newpolypoly->randomize( cPolygon::MF_VERTCOUNT);
		newpolypoly->setTipShape(new cPolyPolygon());
		newpolypoly->randomize(//cSprite::MF_RADIUS | 
			cPolygon::MF_COLOR | cPolygon::MF_LINEWIDTH | cPolygon::MF_DOTS | cPolygon::MF_VERTCOUNT); 
		return newpolypoly;
#endif //POLYPOLYOFBITMAPS switch
	}
	else if(spritetypeindex == cGame::ST_BITMAPS)
	{
		int resourceidindex = cRandomizer::pinstance()->random(_bitmapIDarray.GetSize());
		picon = new cSpriteIcon(_bitmapIDarray[resourceidindex]); //[6] for just saucers.
		return picon;
	}
	else if(spritetypeindex == cGame::ST_MESHSKIN)
	{
		int index = cRandomizer::pinstance()->random(_meshSkinNameTripleArray.GetSize());
		pspritequake = new cSpriteQuake(_meshSkinNameTripleArray[index]._meshfilename,
			_meshSkinNameTripleArray[index]._skinfilename,
			_meshSkinNameTripleArray[index]._correctionpercents);
		//picon->randomize(cSprite::MF_RADIUS);
		return pspritequake;
	}

	return new cSprite(); //Default in the cGame::ST_SPRITETYPENOTUSED case
}

UINT cGame::randomWallpaperID()
{
	int resourceidindex = 
		cRandomizer::pinstance()->random(_wallpaperBitmapIDarray.GetSize());
	return _wallpaperBitmapIDarray[resourceidindex]; 
}

#ifdef TESTGLTEXT
void testtext(cGraphics *pgraphics)
{
//TEST THE 3D POLYGON-BASED FONTS
	pgraphics->use3DText(TRUE);
// Set color for lighted 3D text.
	GLfloat materialAmbDiff[4]={ 1.0, 1.0, 0.2, 1.0f };
	::glMaterialfv( GL_FRONT, GL_AMBIENT_AND_DIFFUSE, materialAmbDiff );
	// along the X axis
	::glPushMatrix();
	::glTranslatef( -1.5f, 2.0f, 1.5f ); //Positon 3D text like any GL object
	::glScalef( 2.0, 2.0, 3.0f ); 
	pgraphics->drawtext("X Axis ** 3D Text" );
	::glPopMatrix();
	// along the Y axis
	::glPushMatrix();
	::glTranslatef( -1.5f, -1.5f, 1.5f );
	::glRotatef( 90.0f, 0.0f, 0.0f, 1.0f );
	::glTranslatef( 0.0f, 0.5f, 0.0f );
	::glScalef( 2.0, 2.0, 3.0f ); 
	pgraphics->drawtext("Y Axis @@ 3D Text" );
	::glPopMatrix();
	// along the Z axis
	::glPushMatrix();
	::glTranslatef( 2.0f, 2.0f, 1.5f );
	::glRotatef( -90.0f, 0.0f, 1.0f, 0.0f );
	::glScalef( 2.0, 2.0, 3.0f ); 
	pgraphics->drawtext("Z Axis ## 3D Text" );
	::glPopMatrix();
//TEST THE 2D BITMAP-BASED FONTS
	pgraphics->use3DText(FALSE);
	::glDisable( GL_LIGHTING ); //Don't use lighting for bitmap text.
//Set color for the nonlighted text.
	::glColor3f( 0.8f, 0.8f, 0.2f ); // yellow text
//Draw text
	::glRasterPos2f(0.0, 0.0); //glRasterPos positions flat text.
	/* Scaling has no effect here, if you want bigger, you need to create from
	a bigger font. */
	pgraphics->drawtext("Flat Bitmap Text");
	::glEnable( GL_LIGHTING ); // turn lighting back on

} //End of the drawWorld method
#endif //TESTGLTEXT