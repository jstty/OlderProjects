#ifndef CRITTERVIEWER_H
#define CRITTERVIEWER_H

#include "critter.h"
#include "listener.h"

/* We think of the cCritterViewer as looking along its _direction axis. */

class cCritterViewer : public cCritter
{
DECLARE_SERIAL(cCritterViewer)
//friend class cListenerViewer;
public:
	static Real STARTFIELDOFVIEWANGLE; 
	static Real MINFIELDOFVIEWANGLE; 
	static Real MAXFIELDOFVIEWANGLE; 
	static Real MOVEBOXTOGAMEBORDERRATIO; /* We keep the critter in a _movebox
		that is this quantity times the pgame()->border() in size. */
	static Real MINZNEAR; /* Smallest value of the _znear clip plane value.  Must be bigger than
		0.0.  Typically use 0.1. */
	static Real DEFAULTZOOMFACTOR; /* Standard factor, about 1.1, to use for
		zooming in or out. */
	static Real ORTHOZOFFSET;
	static Real FOVEAPROPORTION;
	static Real TURNPROPORTION;
	static Real MOVEPROPORTION;
	static Real STARTYOFFSETPROPORTION;
	static Real PROPORTIONOFWORLDTOSHOW;
	static Real MINPROPORTIONOFWORLDTOSHOW;
	static Real MAXPROPORTIONOFWORLDTOSHOW;
/* The PLAYER_ constants were to distinguish between the cases where you don't watch the
	player, where you watch the player, and where you ride the player. They are used
	as arguments to the setPlayerWatch call. But I don't use this after all. */
//	static const int PLAYER_NEUTRAL;
//	static const int PLAYER_WATCH;
//	static const int PLAYER_RIDE;
protected:
	CPopView *_pownerview;
	BOOL _perspective; /* FALSE means use Ortho projection, 
		TRUE means use Perspective. We set this in the constructor according
		to the type of _pownerview->pgraphics(), using Ortho for graphicsMFC
		and Perspective for graphicsOpenGL.  If you like, you can use Ortho
		with graphicsOpenGL, but to make life simpler we don't want to bother
		implementing Perspective for the graphicsMFC. */
	BOOL _trackplayer; /* Whether to always keep the player in view */
	cVector _lastgoodplayeroffset; /* When tracking the player, remember the last offset from
		the player's postion from which you could comfortably see the player. */
	Real _proportionofworldtoshow; /* positive number expressing how big the visible world
		shown is relative to the whole game. Default is 1.  0.5 would mean a zoomed-in view,
		while 2.0 would mean a view in which the game is small in the window.  
		Is used in the Ortho mode to set realwindow, can be used in persepctive to
		set _fieldofviewangle and sometimes position. */
	Real _aspect; // Ratio of desired x width to y height for current projection.
	Real _fieldofviewangle; /* onsistent with the rest of the framework,
		we use radian measure for the angles, but keep in mind that OpenGL uses
		degree measure. */
	Real _foveaproportion; /* Number between 0.0 and 1.0 to specify how much of the 
		world you can see.  We pass _foveaproportion as the second argument to isVisible
		which wasy say something is visible if it  appears on the inner foveaproportion
		central box of the viewer's image screen, which is what you see in the view window. */
	Real _znear, _zfar;
//Accessors
	cGraphics* pgraphics()const; //get _pownerview->pgraphics(), and check that this isn't NULL.
	CPopView* pownerview()const; //get _pownerview, and check that it isn't NULL.
public:
	cCritterViewer(){} /* Don't bother doing anything as this is only
		used in copy and serialize. */
	cCritterViewer(CPopView *pview); //This is the only constructor we use.
	virtual void copy(cCritter *pcritter);
//Accessors
	Real aspect() const {return _aspect;}
	Real fieldOfViewDegrees() const {return (180.0 * + _fieldofviewangle)/PI;}
	Real fieldOfViewRadians() const {return _fieldofviewangle;}
	cRealBox2 orthoViewRect() const;
	BOOL trackplayer(){return _trackplayer;}
//	Real zfar(){return _zfar;}
//	Real znear(){return _znear;}
	Real toFarZ(){return fabs(_zfar - _position.z());} /* Use this in pixelToPlayerYonWallVector 
		calls to set the cursor pos, made inside CPopView OnMouseMouve and SetCursor,
		when viewer uses a cListenerViewerRide. */
	BOOL is3D(); //This returns  pgraphics()->is3D(), we use it in cGame::initializeViewpoint
//Mutators
	void resetAndMatchMoveBox(cGame *pgame);
	void resetZoom();
	void setDefaultView(); /* Center above origin, or offset a bit in _perspective case,
		looking down. */
	void cCritterViewer::setViewpoint(cVector toviewer = cVector3::ZAXIS,
		 cVector lookatpoint = cVector::ZEROVECTOR, BOOL trytoseewholeworld = TRUE);
	void setAspect(Real aspect){_aspect = aspect;} /* Idea is to make _aspect always match the 
		xpixelcount to ypixelcount ratio of the pixel size of the view window. This prevents
		distortion. This gets called in CPopView::OnSize. */
	void setPerspective(BOOL onoff); 
	BOOL zoom(Real zoomfactor); /* Sets the 
		_proportionofworldtoshow parameter, and, if _perspective,
		adjusts the _fieldofviewangle and possibly the position if the _proportionofworldtoshow
		would make _fieldofviewangle exceed WIDESTANGLE. Return tells if you had
		to move to achieve your effect. */
	void setFieldOfViewDegrees(Real angleindegrees){_fieldofviewangle = angleindegrees*PI/180.0;}
	void setFieldOfViewRadians(Real angleinradians){_fieldofviewangle = angleinradians;}
	void setFoveaProportion(Real foveaproportion)
		{CLAMP(foveaproportion, 0.0, 1.0);_foveaproportion = foveaproportion;}
	void setTrackplayer(BOOL onoff){_trackplayer = onoff;}
	void setOwnerView(CPopView *pview){_pownerview = pview;} //Used in  CPopView::Serialize.
//Special methods
	void loadViewMatrix()const; /* Puts the inverse of a modified aspect matrix of this
		critter into the modelveiw matrix of the pgraphics of the _pownerview. 
		The "modification" has to do with the fact that we think of a critterviewer as looking
		along its plus x-axis, but for the view matrix we think of looking along 
		its negatiave z axis. */
	virtual void loadProjectionMatrix(); /* Set the perspective matrix of the pgraphics
		of the _pownerview so that something like _proportionofworldtoshow much of the world
		shows (0.1 would be a tenth of the world, 1.0 would be all of it,
		2.0 would mean show space aroudn the world so it takes up half the
		view.  Not const as stereo viewer flips position temporarily. */
	void setZClipPlanes(const cRealBox3 &worldbox); /*This tries to set _znear and _zfar
		so that each of the eight corners of the worldbox is between
		the planes cutting the attitudeTangent() direction at distances of _znear and _zfar from the
		position().  We don't take into account the corners that are behind the viewer.  If
		any point is behind or almost behind the viewer pos relative to the
		viewedirection we set _znear to cCritterViewer::MINZNEAR, which is typically 0.1. */
	BOOL isVisible(const cVector &testpos) const;
	/* Uses _foveaproportion which lies between 0.0 and 1.0. We say something is visible if it 
		appears on the inner _foveaproportion central box of the viewer's image screen,
		which is what you see in the view window. */ 
//overloads
	virtual cGame* pgame()const; //Use _pownerview to get the CPopDoc and get the cGame from that.
	virtual BOOL in3DWorld(){return TRUE;} /* Even if the game world is 2D,
		the viewer is always free to move in 3D. */
	virtual void update(CPopView *pactiveview, Real dt);
	virtual void Serialize(CArchive &ar);
};

#endif // CRITTERVIEWER_H