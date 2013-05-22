 // game.h: interface for the cGame class and some of its children.
 //
 //////////////////////////////////////////////////////////////////////
 
#ifndef GAME_H
#define GAME_H
#include "realnumber.h"
#include "biota.h"
#include "controller.h"
#include "popview.h"
#include "spriteicon.h"
#include "pop.h" //for _animateflag in gamepaused() method.
#include "collider.h"
#include "spritetexturebox.h"
 

//#define DONTBOSS 
	/* DONTBOSS turns off all game constructor code that changes "global" things like CRITTERMINRADIUS. 
	Eventually I want to get it working this way, but haven't fully carried it out yet. */

class cCollider;
class cBiota;
class cController;
class CPopView;
class cSpriteIcon;
class cLightingModel;

class cMeshSkinNameTriple
{
public:
	CString _meshfilename;
	CString _skinfilename;
	cVector _correctionpercents;
	cMeshSkinNameTriple(CString meshfilename = "", CString skinfilename = "",
		cVector correctionpercents = cVector(0.0, 0.0, 0.0)):
	_meshfilename(meshfilename), _skinfilename(skinfilename),
	_correctionpercents(correctionpercents){}
};
 
class cGame : public CObject
{
DECLARE_SERIAL(cGame);
public:
	static const int COUNTSMALL;
 	static const int COUNTMEDIUM;
 	static const int COUNTLARGE;
 	static const int COUNTHUGE;
 	static int COUNTSTART;
 	static int MAXSCORE;
 	static Real WORLDWIDTH;
 	static Real WORLDHEIGHT;
#ifndef DONTBOSS
 	static Real CRITTERMINRADIUS;
 	static Real CRITTERMAXRADIUS;
 	static Real BULLETRADIUS;
 	static Real CRITTERMAXSPEED;
#endif //DONTBOSS
	static Real DEFAULTZDEPTH;
	static Real BACKGROUNDOFFSET;
	static Real FOREGROUNDOFFSET; /* These two are for moving the background
		and foreground out of the plane of the critters for when we do a 
		thee-d view. We use something like -0.1 and 0.9.*/
 //Kinds of sprite that we have on hand.  ST stands for sprite type.
	static const int ST_SPRITETYPENOTUSED; //when you plan to put in your own sprites.
	static const int ST_SIMPLEPOLYGONS; //Simple triangles, squares, pentagons.
 	static const int ST_FANCYPOLYGONS; //Diverse regular and star polygons.
 	static const int ST_ASTEROIDPOLYGONS;  //Polypolygons that have polypolygons at their tips.
 	static const int ST_POLYPOLYGONS;//Polypolygons that have polygons at their tips.
 	static const int ST_BITMAPS; //cSpriteIcon bitmaps.
 	static const int ST_MESHSKIN; //Quake style MD2 Skins on Meshes
	static const int ST_BUBBLES; //cBubble images.
	static const int ST_SPHERES; //cSpriteSphere
 	static const int ST_ASSORTED;  //Mixture from SIMPLEPOLYGONS through BUBBLES.
 	static const int ST_TRIPLEPOLYPOLYGONS;  //Polypolygons that have polypolygons at their tips.
	static const int MENU_ALL;
	static const int MENU_SHAPE;
	static const int MENU_BOUNCEWRAP;
	static const int MENU_2D;
	static const int MENU_3D;
	static const int MENU_AUTOPLAY;
	static const int MENU_COUNT; 
	static const int MENU_SHIELD;
	static const int MENU_BACKGROUND;
	static const int MENU_HOPPER;
	static const int MENU_CHANGELISTENER;
	static const int MENU_TRACKPLAYER;
	static const int MENU_RIDEPLAYER;
	static const int MENU_ALLOWLISTENERCURSOR;
	static const int SHAPE_RECT;
	static const int SHAPE_XSCROLLER;
	static const int SHAPE_YSCROLLER;
 private:
  	cCritter* _pplayer; /* Pointer to the player's critter.  This  will
 		never be NULL so that we have continuity from board to board.  We
 		initialize it in the constructor and delete only in the destructor. 
		Make it private so we remember to use the setPlayer mutator to set it.
		We use the pplayer() accessor to get at it. */

// added by: Joseph E. Sutton
 public:
    cBiota *GetBiota() { return _pbiota; }
    void SetSpriteType(int nst) { _spritetype = nst; }

 protected:
   cBiota *_pbiota;
	cCollider *_pcollider;
 	cCritter* _pfocus; // Pointer to the cCritter, if any, being dragged in the CView.
 	cRealBox _border; /* Keep a handy central reference to the size of the world. */
	cSpriteTextureBox *_pskybox;  /* We'll base a cSpriteTextureBox on 
		a cRealBox3 skeleton which will either match _border, or maybe be
		larger. */
	cLightingModel *_plightingmodel;
 	int _seedcount; //The current starting number of critters.
 	BOOL _gameover; //Is the game finished yet?
 	int _maxscore; //Target max score for a game
 	int _scorecorrection; //Extra points to give user to make his max score = _maxscore.
	int _wrapflag; //cCritter::BOUNCE or cCritter::WRAP
	int _spritetype; //For use in the "design" games that allow random changes to sprites.
	int _autoplay; //Use to turn autoplay on and off. 0 is off, 1 is on.
	int _level; //For later use, like in adjustGameParametes and in seedCritters.  Starts at 1.
//Don't Serialize these, as they get set in the constructor.
	CArray<UINT, UINT> _bitmapIDarray; /* Array lists the resource ID of all
 		available bitmaps for sprites. Is used by the randomSprite method. */
	CArray<UINT, UINT> _wallpaperBitmapIDarray; /* Array lists the resource ID
		of all available bitmaps for wallpaper. Is used by the random
		wallpaperID	method. */
	CArray<cMeshSkinNameTriple, cMeshSkinNameTriple> _meshSkinNameTripleArray;
 	BOOL _newgame; /*  Constructor sets to TRUE. Use _newgame to decide which prompt dialog
		to show if _gameover _newgame for start and !_negame for restart.
		Don't serialize _newgame because when I load a file, I want the first ENTER to
		call start and not restart, and the constructor call in the load will have 
		correctly set _newgame to TRUE. */
	CArray<HCURSOR, HCURSOR> _arrayHCURSOR;
 //Interface variables
 	cController* _pcontroller;
 	cVector _cursorpos;/* We track the "real" location corresponding to the cursor's
 		pixel position. */
 	BOOL _bDragging;
	int _menuflags; /* We use the bits of this int as flags to determine if 
		various menu controls will be activated for this game. We define various MENU_***
		constants to & against. We don't have to serialize this, by the way, because
		each game class sets it in the game class constructor. */
 //Helper method.
 	int _index(cCritter* pcritter){return _pbiota->_index(pcritter);}
 	int _HCURSORindex(HCURSOR hcursor);
 public:
 //Constructors, destructor, serialize.
 	cGame();
 	cGame(cBiota *pbiota); //Need so that the cBiota default constructor can make an owner game.
 	virtual ~cGame();
	virtual void removeReferencesTo(cCritter *pdeadpcritter); /* Has the _pbiota, the
		and the _pcollider call removeReferencesTo(pdeadcritter) */
 	virtual void Serialize(CArchive& ar);
	virtual int worldShape(){return cGame::SHAPE_RECT;} /* The cCritterViewer::update
		looks at this if _trackplayer is on, so as, if you have a side scroller game, 
		to only track left/right rather than also looking up and down. */
 //Accessors
 	cBiota* pbiota(){return _pbiota;}
 	cCollider* pcollider(){return _pcollider;}
 	cLightingModel *plightingmodel(){return _plightingmodel;}
	cVector cursorpos(){return _cursorpos;}
 	int wrapflag(){return _wrapflag;}
 	int seedcount(){return _seedcount;}
 	//These three accessors get the values from _pplayer. Virtual in case you want to scale them.
 	virtual int score();
 	virtual int health();
 	virtual Real age();
 	BOOL gameover(){return _gameover;}
 	BOOL newgame(){return _newgame;}
	BOOL gamepaused(){return TRUE^(((CPopApp*)::AfxGetApp())->_animateflag);}
 	cCritter* pFocus(){return _pfocus;} //May be NULL.
 	cCritter* pplayer(){ASSERT(_pplayer && "cGame has valid player critter pointer."); return _pplayer;}
 	cRealBox border(){return _border;}
 	cSpriteTextureBox *pskybox(){return _pskybox;}
 	cController* pcontroller(){return _pcontroller;}
 	int keystate(int vkcode){return _pcontroller->keystate(vkcode);}
 	Real keystateage(int vkcode){return _pcontroller->keystateage(vkcode);}
	void setKeystate(int vkcode, int state){_pcontroller->setKeystate(vkcode, state);}
 	CRuntimeClass* playerListenerClass();
 	int autoplay(){return _autoplay;}
 	BOOL visibleplayer(){return  _pbiota->_index(_pplayer) != cBiota::NOINDEX;}
 		//Is _pplayer an onscreen player that's in _pbiota?
 	BOOL validHCURSOR(HCURSOR hcursor);
 	HCURSOR nextHCURSOR(HCURSOR hcursor, int updown);
	int spritetype(){return _spritetype;}
	int menuflags(){return _menuflags;}
	BOOL in3DWorld();
	virtual BOOL upIsZ(){return TRUE;} /* Really all my worlds should have z as the
		up direction, but cGameHallway has Y up. */
	int randomBitmapID()
		{return _bitmapIDarray[
			cRandomizer::pinstance()->random(_bitmapIDarray.GetSize())];}
 //Mutators
 	void add(cCritter *pcritter, BOOL immediateadd = FALSE);  /* The cGame::add makes the following changes to pcritter: sets
 		pcritter's _movebox to match game's _border, puts pcritter in _pbiota, sets pcritter's
 		_wrapflag to match the game's _wrapflag. Normally this doesn't happen
		until pownerbiota makes a periodic call to processServiceRequests, but you
		can force it to be immediate with immediateadd. */
 	void setWrapflag(int wrapflag);
 	void setSeedcount(int seedcount);
 	void setPlayerControllerClass(CRuntimeClass *pruntimeclass);
 	void setFocus(cCritter* pfocus){_pfocus = pfocus;}
 	void setPlayer(cCritter *pplayernew, BOOL onscreen = TRUE); /* If onscreen, this means to
 		add the player to the _pbiota array, otherwise don't. */
 	virtual void setAutoplay(int autoplay); /* Virtual in case you need to set something
		like the player's listener. */
 	virtual void setSpritetype(int spritetype); /* Can overlaod to adjust linecolors or exclude some
		critters from having their sprites changed. */
	void setNewgeometryflag(BOOL onoff);
	void setGameover(BOOL onoff){_gameover = onoff;}
	void setBorder(Real dx, Real dy, Real dz = 0.0);
	void setBorder(const cVector &locorner, const cVector &hicorner);
	void setBorderZRange(Real loz, Real hiz);
	virtual void fixSkyBox();
	void setSkyBox(cVector locorner, cVector hicorner,
		int resourceID = -1); /* -1 resoruceID means
		just use plain rectangles for the faces. */
	void setSkyBox(cRealBox *pskeleton, int resourceID = -1)
		{setSkyBox(pskeleton->locorner(), pskeleton->hicorner(),
		resourceID);}
	void setBackgroundBitmap(int resourceID);
		 /* This is a legacy method mainly for use with 2D games. */
 //Critter adjustment Methods
	virtual void zStackCritters(); /* This is useful if you have a 2D world in which the critters
		don't collide, and now you want to stack them up in the z axis so that they don't
		pass through each other.  For this to work, your constructor should contain this
		line so that yoru world has enough zsize so that critters don't mistakenly get
		their z coordinate clamped away.
		setBorderZRange(0.0, cGame::DEFAULTZDEPTH + 2*cCritter::MAXRADIUS );
		I make it virtual, because, like in PickNPop I might want to stack
		a certain way.  The default zStackCritters just stacks them in
		the order they appear in the biota array, and this may NOT be the
		order you added them in, as we try and group together critters with
		similar sprites to speed up the texture use in OpenGL.	*/ 
 	cSprite* randomSprite(int spritetypeindex);/* A factory method to return one of the
 		various kinds of sprites. */
	UINT randomWallpaperID();
 //Input Methods
 	void setCursorPos(const cVector position){_cursorpos = position;}
 	virtual void onKeyDown(CPopView *pview, UINT nChar, UINT nFlags);
 	virtual void onKeyUp(CPopView *pview, UINT nChar, UINT nFlags);
 	virtual void onLButtonDown(CPopView *pview, UINT nFlags, CPoint point);
 	virtual void onLButtonUp(CPopView *pview, UINT nFlags, CPoint point);
 	virtual void onMouseMove(CPopView *pview, UINT nFlags, CPoint point);
 //Special Methods
	void processServiceRequests(){_pbiota->processServiceRequests();}
 	virtual void start(); //Just sets _gameoverflag = FALSE.
 	virtual void restart(); //Calls reset() and start()
	virtual void reset();
 	virtual void step(Real dt, CPopView *pactiveview);
 		/* The step function is called in CPopDoc::stepDoc(dt), followed by a call to
 		UpdateAllViews. The cGame step function calls _pcontroller->update(dt), then calls
		adjustGameParameters(), and then these pbiota() calls:
			feellistener(dt); move(dt); updateMetric(); update(pactiveview);  collide();
 			processServiceRequests(); animate(dt); 
		Then CPopDoc::stepDoc then does a call to UpdateAllViews(timehint(dt)).
			There are a number of considerations that go into this order, so if you change it,
		be careful to very thoroughly test your program after the change. We call updateMetric before
 		update and collide, because update and collide may use the metric information. */
	void buildCollider(){_pcollider->build(_pbiota);}
	virtual void collideStep(); /* By default calls _pcollider->iterateCollide(), but you can give it
		a void {} body if you don't want collisions. */
	virtual void drawCritters(cGraphics *pgraphics, int drawflags); /* Call the 
		_pbiota draw to walk the array. */
	static void playSound(CString wavfileresourcename)
		{cCritter::playSound(wavfileresourcename);}
	static void playMusic(const char* wavMidiFilename)
		{cCritter::playMusic(wavMidiFilename);}
	static void stopMusic()
		{cCritter::stopMusic();}
 //Special Methods you are likely to overload
	virtual void drawWorld(cGraphics *pgraphics, int drawflags);
	virtual void drawBackground(cGraphics *pgraphics, int drawflags);
		 /* Called in CPopView::_draw before critters are drawn.  Does a background rect that's
		an edge, a solid rect, or an edged bitmap.  Also calls drawForeground to draw a 
		foreground rect.  May also draw a wireframe of the border if it's a box. */
	virtual	void drawForeground(cGraphics *pgraphics, int drawflags);
 	virtual void seedCritters();
 	virtual void adjustGameParameters(){} /* This may set the _gameover flag, may
 		also reseed the world, or use change the background bitmap. */
 	virtual CString statusMessage(); //Called by CPopView::OnUpdate.
	virtual CString gameOverMessage(); /* Put this message up in a message box when a game is
		over.  Default just says "PRESS ENTER," but you can overload to give more info. */
 	virtual void initializeView(CPopView *pview);
 		/* initializeView sets the cursor type, the background, the graphics type, and
		whether the pviewpointcritter ignores, watches the player or rides it. 
		When you switch game types or start a new game, the CPopView::OnUpdate gets called 
		with the VIEWHINT_STARTGAME) parameter and this generates calls to initializeView and
		to initializeViewpoint. */
	virtual void initializeViewpoint(cCritterViewer *pviewer);
		/* initializeViewpoint sets the pviewpointcritter's zoom, and its postion and
		direction.  It has two cases for the 2D and the 3D.  initializeViewpoint gets
		called (a) when you start a new game, (b) when you switch graphics modes,
		(c) when you alter the player ignoring/riding/watching options. */
 };
 
 #endif //GAME_H
