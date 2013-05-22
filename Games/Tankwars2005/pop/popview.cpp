// PopView.cpp : implementation of the CPopView class
//

#include "stdafx.h"
#include "ChildFrm.h" //For CChildFrame class to use _cSplitterWnd.  RR.
#include "game.h"
#include "listener.h"
#include "MainFrm.h" //For CMainFrame class to call SetMessageText.  RR.
#include "sprite.h" //For DF_ drawflags constants
#include "Pop.h"
#include "PopView.h"
#include "graphicsMFC.h"
#include "graphicsOpenGL.h"
#include "critterviewer.h"
#include "critterviewerstereo.h"
#include "dialogstereo.h"
#include ".\popview.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//#define TRACEONKEY //Used for debugging the OnKeyDown key handling
//#define AUTOSHOWOPENGLINFO
	/* Comment this in to automatically pop up an OpenGL system dialog the first
	time you enter OpenGL mode. */
//#define SHOWREFRESHRATEINSTATUSBAR
	/* Show the hardware refresh rate in the status bar. Normally you don't want this, as
	the user will mistakenly read this as the app refresh rate.  */
//#define DONTSHOWCURSORWHENDRAGGINGPLAYER
	/* If we comment in DONTSHOWCURSORWHENDRAGGINGPLAYER, then we don't show the
	cursor when we use a cListenerCursor to move the player.  This makes the
	view cleaner, but some users find it confusing. If we comment out
	DONTSHOWCURSORWHENDRAGGINGPLAYER, then we show a crosshair. */
//#define PINGKEYPRESS
	/* For testing purposes make a sound when you press a key, I'm using
	this to test the mysterious new lag in Windows XP, where I press
	a key and don't see onscreen response till about ten updates later. 
	Using this in the cGameSpacewarSun under XP, I can hear, say, an 
	VK_UP keypress almost a full second before I see the reaction in
	the motion of the rocket on screen. And a half second lag in plain
	spacewar.  And the lag grows as time goes on.  ACtually the problem
	was due to an incompatible grahpics card driver, and not "really" 
	XP's fault, October, 2003. */
/////////////////////////////////////////////////////////////////////////////
// CPopView

 //============== CPopView Statics =============
 BOOL CPopView::STARTBITMAPBACKGROUNDFLAG = FALSE;
 BOOL CPopView::STARTSOLIDBACKGROUNDFLAG = FALSE;

 // Chanaged: color
 // Modified by: Joseph E. Sutton
 COLORREF CPopView::GAMEOVEREDGECOLOR = RGB(0, 0, 0);
 COLORREF CPopView::GAMEACTIVEEDGECOLOR = cColorStyle::CN_BLACK;

 //LORREF CPopView::GAMEOVEREDGECOLOR = RGB(32, 32, 32 );
 //LORREF CPopView::GAMEACTIVEEDGECOLOR = RGB(128, 128, 128 );
//******** CONST STATICS **********************************************
/* These are drawflags used by my various draw(CDC*, CRealPixelConverter&, int)
 functions of cSpriteBubble, cCritter, and cSprite. */
const int CPopView::DF_STANDARD =0;
const int CPopView::DF_FOCUS = 1;
const int CPopView::DF_WIREFRAME = 8;
const int CPopView::DF_FULL_BACKGROUND = 16;
const int CPopView::DF_SIMPLIFIED_BACKGROUND = 32;
const int CPopView::DF_DRAWING_SKYBOX = 64;
const int CPopView::NO_BACKGROUND = 0;
const int CPopView::SIMPLIFIED_BACKGROUND = 1;
const int CPopView::FULL_BACKGROUND = 2;

IMPLEMENT_DYNCREATE(CPopView, CView)

BEGIN_MESSAGE_MAP(CPopView, CView)
	//{{AFX_MSG_MAP(CPopView)
	ON_WM_MOUSEMOVE()
	ON_WM_CREATE()
	ON_WM_SIZE()
	ON_COMMAND(ID_VIEW_COLOREDBUBBLES, OnViewColoredbubbles)
	ON_UPDATE_COMMAND_UI(ID_VIEW_COLOREDBUBBLES, OnUpdateViewColoredbubbles)
	ON_COMMAND(ID_VIEW_XRAYBUBBLES, OnViewXraybubbles)
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_VIEW_DRAGGERCURSOR, OnViewDraggercursor)
	ON_UPDATE_COMMAND_UI(ID_VIEW_DRAGGERCURSOR, OnUpdateViewDraggercursor)
	ON_COMMAND(ID_VIEW_PINCURSOR, OnViewPincursor)
	ON_UPDATE_COMMAND_UI(ID_VIEW_PINCURSOR, OnUpdateViewPincursor)
	ON_WM_SETCURSOR()
	ON_WM_LBUTTONUP()
	ON_UPDATE_COMMAND_UI(ID_VIEW_XRAYBUBBLES, OnUpdateViewXraybubbles)
	ON_WM_KEYDOWN()
	ON_WM_MOUSEWHEEL()
	ON_WM_KEYUP()
	ON_WM_SETFOCUS()
	ON_COMMAND(ID_VIEW_ARROWCURSOR, OnViewArrowcursor)
	ON_UPDATE_COMMAND_UI(ID_VIEW_ARROWCURSOR, OnUpdateViewArrowcursor)
	ON_COMMAND(ID_VIEW_SPAWNCURSOR, OnViewSpawncursor)
	ON_UPDATE_COMMAND_UI(ID_VIEW_SPAWNCURSOR, OnUpdateViewSpawncursor)
	ON_COMMAND(ID_VIEW_ZAPCURSOR, OnViewZapcursor)
	ON_UPDATE_COMMAND_UI(ID_VIEW_ZAPCURSOR, OnUpdateViewZapcursor)
	ON_COMMAND(ID_VIEW_REPLICATECURSOR, OnViewReplicatecursor)
	ON_UPDATE_COMMAND_UI(ID_VIEW_REPLICATECURSOR, OnUpdateViewReplicatecursor)
	ON_WM_ERASEBKGND()
	ON_COMMAND(ID_GAME_BACKGROUND, OnGameBackground)
	ON_UPDATE_COMMAND_UI(ID_GAME_BACKGROUND, OnUpdateGameBackground)
	ON_COMMAND(ID_VIEW_SHOOTCURSOR, OnViewShootcursor)
	ON_UPDATE_COMMAND_UI(ID_VIEW_SHOOTCURSOR, OnUpdateViewShootcursor)
	ON_COMMAND(ID_VIEW_OPENGLGRAPHICS, OnViewOpenglgraphics)
	ON_UPDATE_COMMAND_UI(ID_VIEW_OPENGLGRAPHICS, OnUpdateViewOpenglgraphics)
	ON_COMMAND(ID_VIEW_MFCGRAPHICS, OnViewMfcgraphics)
	ON_UPDATE_COMMAND_UI(ID_VIEW_MFCGRAPHICS, OnUpdateViewMfcgraphics)
	ON_COMMAND(ID_VIEW_TRANSLATE, OnViewTranslate)
	ON_UPDATE_COMMAND_UI(ID_VIEW_TRANSLATE, OnUpdateViewTranslate)
	ON_COMMAND(ID_VIEW_RIDE, OnViewRide)
	ON_UPDATE_COMMAND_UI(ID_VIEW_RIDE, OnUpdateViewRide)
	ON_COMMAND(ID_VIEW_FLY, OnViewFly)
	ON_UPDATE_COMMAND_UI(ID_VIEW_FLY, OnUpdateViewFly)
	ON_COMMAND(ID_VIEW_KEEPPLAYERINVIEW, OnViewKeepplayerinview)
	ON_UPDATE_COMMAND_UI(ID_VIEW_KEEPPLAYERINVIEW, OnUpdateViewKeepplayerinview)
	ON_COMMAND(ID_VIEW_ORBIT, OnViewOrbit)
	ON_UPDATE_COMMAND_UI(ID_VIEW_ORBIT, OnUpdateViewOrbit)
	ON_COMMAND(ID_VIEW_SOLIDBACKGROUND, OnViewSolidbackground)
	ON_UPDATE_COMMAND_UI(ID_VIEW_SOLIDBACKGROUND, OnUpdateViewSolidbackground)
	ON_COMMAND(ID_VIEW_NOBACKGROUND, OnViewNobackground)
	ON_UPDATE_COMMAND_UI(ID_VIEW_NOBACKGROUND, OnUpdateViewNobackground)
	ON_COMMAND(ID_VIEW_RESTORESTANDARDVIEWPOSITION, OnViewRestoreViewpoint)
	ON_WM_DESTROY()
	ON_COMMAND(ID_VIEW_OPENGL_STEREO, OnViewOpenglStereo)
	ON_UPDATE_COMMAND_UI(ID_VIEW_OPENGL_STEREO, OnUpdateViewOpenglStereo)
	//}}AFX_MSG_MAP
//	ON_WM_GETMINMAXINFO()
	ON_WM_CHAR()
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPopView construction/destruction

CPopView::CPopView():		//Put defaults in for your data fields
	_pgraphics(NULL), //We'll set this with the setGraphicsClass call in OnCreate
	_drawflags(CPopView::DF_STANDARD),
	_hCursor(NULL),
	_pviewpointcritter(NULL)
{
	if (CPopView::STARTBITMAPBACKGROUNDFLAG)
		_drawflags |= CPopView::DF_FULL_BACKGROUND;
	else
		_drawflags &= ~CPopView::DF_FULL_BACKGROUND;
	if (CPopView::STARTSOLIDBACKGROUNDFLAG)
		_drawflags |= CPopView::DF_SIMPLIFIED_BACKGROUND;
	else
		_drawflags &= ~CPopView::DF_SIMPLIFIED_BACKGROUND;	
	/* We put all the rest of the initialization in OnCreate. Here in the constructor we don't
		have a good pointer to a CPopDoc yet, and the pgame() method will only return a NULL.
		We might also need to use somethign from CPopApp,  but we can't do that here either,
		because in here, CPopApp hasn't yet executed CWinApp::InitInstance, and isn't fully
		initialized. In general it's safer to do any substantive intialization in OnCreate. */
}

BOOL CPopView::PreCreateWindow(CREATESTRUCT& cs)
{
//Do the base class call first, and bail if it fails.
	if (!CView::PreCreateWindow(cs)) 
		return FALSE;
    cs.style |= WS_CLIPSIBLINGS | WS_CLIPCHILDREN; /* This is a non-standard move
		that we must do in order for the window to be compatible with 
		OpenGL graphics. It doensn't seem to cause any trouble in standard
		MFC graphics, so we just do it all the time. */
	return TRUE;
}

int CPopView::OnCreate(LPCREATESTRUCT lpCreateStruct) 
{
// Base class call comes first.  Have to to this before the call to GetDocument hidden in pgame().
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1; 
	_pviewpointcritter = new cCritterViewer(this); /* Looks at pgame()->border(), so wait
		till we're in OnCreate, and CPopDoc is fully initialized and we can access pgame().
		Do this before setGraphicsClass, as setGraphicsClass likes to set the 
		_pviewpointcritter's listener. */
	setGraphicsClass(RUNTIME_CLASS(cGraphicsMFC)); 
		/* We need to set up a _pgraphics  object right away, so it we can call it in the
		upcoming OnSize call. We may end up having to get rid of this cGraphics object
		quite soon when we install the default game, so we could 
		just put in a do-nothing base
		class cGraphics. */
	OnUpdate(NULL, CPopDoc::VIEWHINT_STARTGAME, NULL);  /* You need this OnUpdate,
		as this view wasn't here to pick up the OnUpdate issued by the 
		by the CPopDoc::setGameClass in the CPopDoc	constructor. */
	return 0;
}

void CPopView::OnDestroy() 
{
	CWnd::OnDestroy();
}

CPopView::~CPopView()
{
	if (_pgraphics)
		delete _pgraphics;
	_pgraphics = NULL;
	if (_pviewpointcritter)
		delete _pviewpointcritter; 
	_pviewpointcritter = NULL;
} 

void CPopView::Serialize(CArchive& ar)
{
	CRuntimeClass *pgraphicsclass = NULL; 	/* This is a dummy to hold the graphics class type.
		Rather than serializing graphics, we only have to serialize the class.  Note that we 
		don't have to delete pgraphicsclass, as MFCtakes care of CRuntimeClass memory. */
	int cursorid;
 	CObject::Serialize(ar);
 	if (ar.IsStoring()) // Save 
	{
		pgraphicsclass = _pgraphics->GetRuntimeClass();
			//Use the CArchive::ReadClass and WriteClass methods to serialize runtime classes.
		ar.WriteClass(pgraphicsclass);
		cursorid = ((CPopApp*)AfxGetApp())->cursorToID(_hCursor);
 		ar << _pviewpointcritter << _drawflags << cursorid;
	}
 	else //Load 
	{
		pgraphicsclass = ar.ReadClass();
		setGraphicsClass(pgraphicsclass);
		pgraphics()->installLightingModel(pgame()->plightingmodel());
	/* When you read in a pointer, you actually are creating a new object,
	so we need to delete the existing pointer fields in case they've been
	initialized.  They are NULL from the constructor, so they may be
	still NULL, but maybe I've hit OnCreate before here. */
		delete _pviewpointcritter;
		_pviewpointcritter = NULL;
		ar >> _pviewpointcritter  >> _drawflags >> cursorid;
		_pviewpointcritter->setOwnerView(this);
		_hCursor = ((CPopApp*)AfxGetApp())->IDToCursor(cursorid);
	}
}

void CPopView::setGraphicsClass(CRuntimeClass *pruntimeclass)
{
	/* set _pgraphics to the appropriate kind of pointer.  Even though its typed as a
plain cGraphics*, _pgraphics really remains whatever kind of child class is
described by the pruntimeclass variable, and will use the child class' overloads
of any virtual methods.  */  
	/* We'll override the user request in case we happen to have already
	put in a cCritterViewerStereo viewer, and in this case force a
	cGraphicsOpenGL. The point of this is to be able to call 
	pgame()->initializeView(this) inside the CPopView::OnViewOpenglStereo()
	 method without possibly 
	reverting to MFC graphics. */
	if (_pviewpointcritter->IsKindOf( RUNTIME_CLASS(cCritterViewerStereo)))
			pruntimeclass = RUNTIME_CLASS(cGraphicsOpenGL);

	if (_pgraphics == NULL || _pgraphics->GetRuntimeClass() != pruntimeclass)
	{
		if (_pgraphics)
			delete _pgraphics; 
		_pgraphics = (cGraphics*)(pruntimeclass->CreateObject());
		_pgraphics->installLightingModel(pgame()->plightingmodel());
		_pgraphics->setOwnerView(this);
		_pgraphics->activate();
		_pgraphics->setViewport(cx(), cy());
			/* The Real world size of the object will be set by ortho
			or perspective calls made by the cCritterViewer. */
//Now just make some default settings for the _pviewpointcritter
		if (_pgraphics->is3D())
		{
			_pviewpointcritter->setListener(new cListenerViewerFly()); 
			_pviewpointcritter->setViewpoint(cVector3(0.0, -1.0, 2.0),
				cVector::ZEROVECTOR);
			//Direction to viewer is down a bit, and back off less than that.
		}
		else //2D case.
		{
			_pviewpointcritter->setListener(new cListenerViewerOrtho());
			_pviewpointcritter->setViewpoint(cVector::ZAXIS, cVector::ZEROVECTOR);
		}
		pgame()->initializeViewpoint(_pviewpointcritter); /* The initialization
			code will look at the kind of viewer you have. */
	}
	//Make sure the new graphics has the right size information.
	CRect clientrect;
	GetClientRect(&clientrect);
	OnSize(SIZE_RESTORED, clientrect.right, clientrect.bottom);


#ifdef AUTOSHOWOPENGLINFO
	if (pgraphicsclass()==(RUNTIME_CLASS(cGraphicsOpenGL)))
	{
		if (cGraphicsOpenGL::FIRSTTIME)
		{
			CPopApp *ppopapp = (CPopApp *)(::AfxGetApp());
			ppopapp->OnOpenglinfodialog(); //Show the info dialog.
			cGraphicsOpenGL::FIRSTTIME = FALSE;
		}
	}
#endif //AUTOSHOWOPENGLINFO
}

/////////////////////////////////////////////////////////////////////////////
// CPopView drawing

void CPopView::OnDraw(CDC* pDC)
{
	if (pDC->IsPrinting())
		return; //Don't try to deal with printing case.

//Wake up the graphics.
	_pgraphics->activate();

//Tell the cGraphics to get rid of any extra unused image resources.
	_pgraphics->garbageCollect();
//Graphically show the status of the game.
	ASSERT(pgame());
	if (pgame()->gameover()) //Dim the lights
		_pgraphics->setClearColor(CPopView::GAMEOVEREDGECOLOR);
	else //turn the lights on
		_pgraphics->setClearColor(CPopView::GAMEACTIVEEDGECOLOR);

//Clear the graphics background.
	CRect targetrect;
	pDC->GetClipBox(&targetrect);
	_pgraphics->clear(targetrect);

//Install the projection and view matrices.
	_pviewpointcritter->loadProjectionMatrix(); /* Initializes the PROJECTION matrix or,
		in the case of cGraphicsMFC, initializes the cRealPixelConvertor. */
	_pviewpointcritter->loadViewMatrix(); //Initializes the MODELVIEW matrix

//Draw the world, by default as a background and a foreground rectangle.
	pgame()->drawWorld(_pgraphics, _drawflags); 

//Draw the critters.
	pgame()->drawCritters(_pgraphics, _drawflags);

//Send the graphics to your video display.  cGraphicsMFC needs to draw foreground again in here.
	_pgraphics->display(this, pDC);
}

/////////////////////////////////////////////////////////////////////////////
// CPopView diagnostics

#ifdef _DEBUG
void CPopView::AssertValid() const
{
	CView::AssertValid();
}

void CPopView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CPopDoc* CPopView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CPopDoc)));
	return (CPopDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CPopView message handlers

BOOL CPopView::OnEraseBkgnd(CDC* pDC) 
{
/* We normally don't want to erase the background because our onDraw will cover it up with 
the _cMemDC copyTo.  If we did erase the background, we'd get flicker.
This is also true with OpenGL. */
	return TRUE; //Don't call baseclass method, CView::OnEraseBkgnd(pDC);
}

void CPopView::OnSize(UINT nType, int cx, int cy) 
{
	CView::OnSize(nType, cx, cy); //Machine code.
//	if ( 0 >= cx || 0 >= cy )
//		return;
	//TRACE("%d\n", (int)this);
	if (_pgraphics)
	{
		_pgraphics->activate(); //Wake up the graphics
		_pgraphics->setViewport(cx, cy);
	}
	pviewpointcritter()->setAspect((Real)cx/(Real)cy); // width/height ratio
}

void CPopView::OnLButtonDown(UINT nFlags, CPoint point) 
{
//My Code.  RR.
	SetCapture(); /* This is so that as long as the mouse button is down,  this
		window gets messages from the mouse even when the mouse is outside
		the window. */
	pgame()->onLButtonDown(this, nFlags, point);
//Don't need to figure out the gameworld pos, it's set as pgame()->pbiota()->_cursorpos in OnSetCursor.
}

void CPopView::OnMouseMove(UINT nFlags, CPoint point) 
{
	/* Normally I track the cursor position in OnSetCursor, but this method doesn't get called during
		dragging, so I need to do it here */
	if ((nFlags & MK_LBUTTON) || (nFlags & MK_RBUTTON) ) //You're dragging.
	{
#define PASSTOSETCURSOR //this is better than trying to replicate some OnSetCursor code here.
#ifdef PASSTOSETCURSOR
		OnSetCursor(this, HTCLIENT, WM_LBUTTONDOWN);
			//OnSetCursor args are the window of the mouse, the hit-test code, the mouse message.
#else
/* If we are riding the critter, we want to pick a point on the yon wall, that is, the viewer's
far clip plane.  Given that we're on the critter, that distance from us will the
viwpointcritter's toFarZ(), inlined as {return fabs(_zfar - _position.z());}*/
		if (_pviewpointcritter->plistener()->IsKindOf(RUNTIME_CLASS(cListenerViewerRide)))
			pgame()->setCursorPos(pixelToPlayerYonWallVector(point.x, point.y, 
				_pviewpointcritter->toFarZ() ));
		else
			pgame()->setCursorPos(pixelToPlayerPlaneVector(point.x, point.y));
#endif //PASSTOSETCURSOR
	}
	pgame()->onMouseMove(this, nFlags, point);
}

void CPopView::OnLButtonUp(UINT nFlags, CPoint point) 
{
	ReleaseCapture(); /* Now that the mouse button is up,  this
		window stops getting mouse messages from outside the window. */
//Don't need to set the gameworld location as pgame()->pbiota()->_cursorpos was set by OnSetCursor.
	pgame()->onLButtonUp(this, nFlags, point);
}

void CPopView::OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
		/* We will use the Windows-defined VK_??? symbols to stand for the various nChar
		values. Most of these are defined in the Visual C++ include file winuser.h.  A few
		that should be defined are not, so we fix this by #defining them in the controller.h
		header file.  */

		/*Although the documentation says nRepCnt gives you the number of repeated
		typematic messages from a keypress, this may not always to be true.  Alternately,
		the doc says Bit number 14 of nFlags tells me if a prior OnKeyDown message has already
		been sent from this particular keypress.  If this bit is on, the key is
		being held down. You access bit 14 via (fFlags & (1<<14)).  But in any case we
		are not very interested in detecting repeated typematic OnKeyDown messages,
		instead we plan to make cController set a GOTTWICEBIT bitflag to signal when a
		given key press has been accessed more than once by the critters. This is more
		of an issue than whether we have a typematic repeat. */

	UINT control = (0x8000 & ::GetAsyncKeyState(VK_CONTROL))?cController::CONTROLBIT:0; 
		/* Is control key down?  The GetAsyncKeyState method returns a short unsigned int
		that has a one in its high bit if the key in question is down.  I trust this more
		than using the nFlags.
			No matter how you detect Ctrl, on the Microsoft	Natural Keyboard, the
		control key blocks the INSERT key, so we can't count on using the Ctrl+INSERT 
		combination for anything.  In the same critcal vein, note that when	the Alt key is
		down, you do not get any OnKeyDown messages at all.  This contradicts the Microsoft
		doc that says the nFlags have a bit (#13) to tell you if the Alt key is down. */
	UINT shift = (0x8000 & ::GetAsyncKeyState(VK_SHIFT)) ?
		cController::SHIFTBIT:0;
		//Is shift key down?  Again, GetAsyncKeyState seems more reliable than nFlags.
	nFlags = control | shift;
#ifdef TRACEONKEY
	TRACE("CPopView::OnKeyDown: nchar %u, control %u, shift %u, keyage %f\n",
		nChar, control, shift, pgame()->pcontroller()->keystateage(nChar));
#endif //TRACEONKEY
	if (nChar != 0) 
	{
		pgame()->onKeyDown(this, nChar, nFlags);
#ifdef PINGKEYPRESS
		((CPopApp*)::AfxGetApp())->playSound("Pop", SND_RESOURCE|SND_ASYNC);
#endif //PINGKEYPRESS
	}
		/*	A very serious issue with the keyboard is the behavior of the group of four arrow keys,
		not the digital keypad on the right, but the little group with UP and then below it
		LEFT DOWN RIGHT.  The LEFT key here fails to fire if the UP and SPACE are pressed.
		That is, it passes a nChar 0 value to the OnKeyDown.  If you hold down SPACE and LEFT,
		the UP key is then blocked in the same way.
			What makes this weird is that the RIGHT key will fire when the UP and SPACE are
		pressed.  Also this blocking doesn't occur for the digital key pad LEFT arrow keys.
			The really crippling thing about this hardware bug is that if, for instance,
		you have pressed down the UP and SPACE, the (0x8000 & ::GetAsyncKeyState(VK_LEFT))
		test will return FALSE.
			And if you have pressed down the UP and LEFT, the GetAsyncKeyState test on
		SPACE will also return false. I don't know what to do about it.
		 */
}

void CPopView::OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags) 
{
			/* We will use the Windows-defined VK_??? symbols to stand for the various nChar
		values. Most of these are defined in the Visual C++ include file winuser.h.  A few
		that should be defined are not, so we fix this by #defining them in the controller.h
		header file.  */

		/*Although the documentation says nRepCnt gives you the number of repeated
		typematic messages from a keypress, this may not always to be true.  Alternately,
		the doc says Bit number 14 of nFlags tells me if a prior OnKeyDown message has already
		been sent from this particular keypress.  If this bit is on, the key is
		being held down. You access bit 14 via (fFlags & (1<<14)).  But in any case we
		are not very interested in detecting repeated typematic OnKeyDown messages,
		instead we plan to make cController set a GOTTWICEBIT bitflag to signal when a
		given key press has been accessed more than once by the critters. This is more
		of an issue than whether we have a typematic repeat. */

	UINT control = (0x8000 & ::GetAsyncKeyState(VK_CONTROL))?cController::CONTROLBIT:0; 
		/* Is control key down?  The GetAsyncKeyState method returns a short unsigned int
		that has a one in its high bit if the key in question is down.  I trust this more
		than using the nFlags.
			No matter how you detect Ctrl, on the Microsoft	Natural Keyboard, the
		control key blocks the INSERT key, so we can't count on using the Ctrl+INSERT 
		combination for anything.  In the same critcal vein, note that when	the Alt key is
		down, you do not get any OnKeyDown messages at all.  This contradicts the Microsoft
		doc that says the nFlags have a bit (#13) to tell you if the Alt key is down. */
	UINT shift = (0x8000 & ::GetAsyncKeyState(VK_SHIFT)) ?
		cController::SHIFTBIT:0;
		//Is shift key down?  Again, GetAsyncKeyState seems more reliable than nFlags.
	nFlags = control | shift;
#ifdef TRACEONKEY
	TRACE("CPopView::OnKeyDown: nchar %u, control %u, shift %u, keyage %f\n",
		nChar, control, shift, pgame()->pcontroller()->keystateage(nChar));
#endif //TRACEONKEY
	if (nChar != 0) 
	{
		pgame()->onKeyUp(this, nChar, nFlags);
#ifdef PINGKEYPRESS
		((CPopApp*)::AfxGetApp())->playSound("Pop", SND_RESOURCE|SND_ASYNC);
#endif //PINGKEYPRESS
	}
		/*	A very serious issue with the keyboard is the behavior of the group of four arrow keys,
		not the digital keypad on the right, but the little group with UP and then below it
		LEFT DOWN RIGHT.  The LEFT key here fails to fire if the UP and SPACE are pressed.
		That is, it passes a nChar 0 value to the OnKeyDown.  If you hold down SPACE and LEFT,
		the UP key is then blocked in the same way.
			What makes this weird is that the RIGHT key will fire when the UP and SPACE are
		pressed.  Also this blocking doesn't occur for the digital key pad LEFT arrow keys.
			The really crippling thing about this hardware bug is that if, for instance,
		you have pressed down the UP and SPACE, the (0x8000 & ::GetAsyncKeyState(VK_LEFT))
		test will return FALSE.
			And if you have pressed down the UP and LEFT, the GetAsyncKeyState test on
		SPACE will also return false. I don't know what to do about it.
		 */
}

void CPopView::OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint) 
{/* This method gets called from cPopDoc, once every dt timestep update. cPopDoc passes
		the dt information inside the pHint. */ 
//If you've just loaded a new game, use the game's initialization code on this view.
	if (lHint == CPopDoc::VIEWHINT_LOADINGARCHIVE)
	{
		if (pHint && pHint->IsKindOf(RUNTIME_CLASS(cArchiveHint)))
		{
			CArchive *parchive = ((cArchiveHint*)pHint)->parchive();
			Serialize(*parchive);
		}
		return;
	}
//If you've just changed the game type, or restarted a game, 
//use the game's initialization code on this view.
	if (lHint == CPopDoc::VIEWHINT_STARTGAME)
	{
		if (_pgraphics)
			delete _pgraphics;
		_pgraphics = NULL;
		_pviewpointcritter->resetAndMatchMoveBox(pgame());
		pgame()->initializeView(this); //Calls preferred setGraphicsClass.
		pgame()->initializeViewpoint(_pviewpointcritter);
			//And now go on and show the game.
	}
/* If we get this far, we're in the normal case, as called by CPopDocument::stepDoc, with an
	lHint of 0 and a pHint holding a dt. */
//Animate the viewer
	Real dt = 0.0;
	if (pHint && pHint->IsKindOf(RUNTIME_CLASS(cTimeHint)))
		dt = ((cTimeHint*)pHint)->dt();
	if (isActiveView())
	{
		_pviewpointcritter->feellistener(dt); /* Listen only if this view has focus,
			otherwise if you have multiple views, you'll inadvertantly move the
			viewpoint in all of them at once. */
		updateStatusBar(); /* Before calling updateStatusBar, see if you are the focus view.
			Show changed score and object counts.  We only do it for the focus view,
			because otherwise if we have a splitter window or several documents
			and views then the Status line gets written for each view, and it flickers
			with different information --- remember there's only one Status bar, no
			matter how many views you have open. */
	}
	_pviewpointcritter->move(dt); 
	_pviewpointcritter->update(this, dt); 
		//possibly feel forces or sniff pixels or align position with player.
	_pviewpointcritter->animate(dt);
//Invalidate the window to force a call to OnDraw
	Invalidate(); /* We don't worry about calling Invalidate(FALSE) so as not to
		erase the background, becasue our OnEraseBkgnd is set do do nothing anyway. */
}

BOOL CPopView::OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message) 
 {
 	/* This method get called whenever the cursor is over the client area of
 			the view.  Don't call the baseclass handler, that is, don't call:
 			CView::OnSetCursor(pWnd, nHitTest, message), //DON'T CALL THIS!!!!
 			In particular, don't call base CView::OnSetCursor last because then you'll
 			get the default IDC_ARROW cursor back!*/
 //(1) Set the correct cursor for this view.
 	::SetCursor(_hCursor); 

//(2) Turn off or change the cursor if you are attached to the player. 
 	if(pgame()->playerListenerClass() == RUNTIME_CLASS(cListenerCursor))
 	{
 		cListenerCursor *plisten = 
 			(cListenerCursor*)(pgame()->pplayer()->plistener());
				//Do this cast so we can check the attached status, though currently its always TRUE.
 		if (plisten->attached())
#ifdef DONTSHOWCURSORWHENDRAGGINGPLAYER
			::SetCursor(NULL);
#else
			::SetCursor(  ((CPopApp*)::AfxGetApp()) -> _hCursorDragger );
#endif //DONTSHOWCURSORWHENDRAGGINGPLAYER
 	}

 //(3) If autofocus is on make sure this view is active.
  	if (!isActiveView())
 		/* Autofocus is handy thing if you plan to change the cursor tool by using the
 			accerlator keys (1 and 2) or the Mouse wheel.  But it's not always practical
 			for general use, as if you move your mouse up to the menu bar, whatever 
 			window 	you cross last has the focus, so its impractical to do menu things 
 			to windows that are to the right or down low. It's such a handy feature for 
 			play, though, that we add a Window|Autofocus control to turn it on and off.
 			The _autofocus switch lives in mainframe. */
 	{
 		CMainFrame* mainframe = (CMainFrame*)::AfxGetMainWnd();
 		if (mainframe->_autofocus)
 		{
 				/* The first two lines set the focus to the child
 					frame around this window.  Now, since this child frame
 					holds a splitter, we still need to put the focus into
 					the correct pane of the splitter, and that's what
 					the second two lines are for. */
 			CChildFrame *childframe = (CChildFrame *)GetParentFrame();
 			mainframe->MDIActivate(childframe); 
 			CSplitterWnd* psplitter = (CSplitterWnd*)GetParent();
 			while (psplitter->GetActivePane()!=this)
 				psplitter->ActivateNext();
 		}
 	}
// (4)  Save the cursor position with cGame::setCursorPos if you're the active view
 	if (isActiveView())
 	{
 	//First get the cursor position in a client area coordinates.
 		CPoint point;
 		::GetCursorPos(&point); //This global function gets screen coordinates
 		ScreenToClient(&point); //A CView conversion method
	//Then convert point to world coordinates and save with setCursorPos
		if (_pviewpointcritter->plistener()->IsKindOf(RUNTIME_CLASS(cListenerViewerRide)))
			pgame()->setCursorPos(pixelToPlayerYonWallVector(point.x, point.y, 
				0.5 * _pviewpointcritter->toFarZ()));
				/* If we are riding the critter, we want to pick a point on the "yon"
				wall, that is, the viewer's far clip plane.  Given that we're on the
				critter, that distance from us will the viewpointcritter's toFarZ(),
				inlined as {return fabs(_zfar - _position.z());} */
		else
			pgame()->setCursorPos(pixelToPlayerPlaneVector(point.x, point.y));
				/* Otherwise we pick a point in the plane of the player's body,
				that is, his tangent and normal plane. */
	}

 	return TRUE;
}

/* The purpose of the CPopView::OnFocus override is as follows.  When we open a
modal dialog or shift focus to another app, the timer keeps running and a large
interval of _dt will accumulate before we come back into the Pop program.  If
you don't do anything to correct this, you get a big jump in the positions.  
So we do a timer tick() so that we only count the interval of time starting when
the program becomes active again.  This has to be handled by CView rather than in
CMainFrame because the CMainFrame keeps focus while a modal dialog is open, and
does not get an OnSetFocus when the modal dialog closes. */

void CPopView::OnSetFocus(CWnd* pOldWnd) 
{
	CView::OnSetFocus(pOldWnd);
	
	((CPopApp*)::AfxGetApp())->_timer.tick();	//RR.
	
}

CPoint CPopView::paneColRow()
{
		/*	Return the pane location (row, col), starting with (0,0). This could be useful,
		in cGame::initializeView and cGame::initializeViewpoint. */
 	CSplitterWnd* psplitter = (CSplitterWnd*)GetParent();
	for (int row = 0; row < psplitter->GetColumnCount(); row++)
		for (int col = 0; col < psplitter->GetColumnCount(); col++)
		{
			if (this == psplitter->GetPane(row, col))
				return CPoint(col, row);
		}
	return CPoint(0,0);
}

BOOL CPopView::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt) 
{
/* Swap the cursor functionality, depending which cursors the game uses.
We just use the sign of zdelta, which will be some positive or negative number,
depending on which way and how far you turned the wheel. */
	_hCursor = pgame()->nextHCURSOR(_hCursor, zDelta);
	return TRUE;
}

void CPopView::setCursorPosToCritter(cCritter *pcritter)
{
/* 	Call this if you are using a ListenerCursor, to move the cursor to match the
	current position of the player.  This code seems to work pretty well, but we tend to
	be down by a vertical amount the size of the menu and tool bar height. 
	It gets worse when I'm in a zoomed in view of a long thin world with cGraphicsMFC,
	it's totally screwy.  So just comment the code out for now. */
	int intcrittx, intcritty;
	Real zbuff;
	vectorToPixel(pcritter->position(), intcrittx, intcritty, zbuff);
	CPoint intcritterpos(intcrittx, intcritty); 
	ClientToScreen(&intcritterpos);
	::SetCursorPos(intcritterpos.x, intcritterpos.y);
}

//=============Methods involving _pgraphics ========================================

cGraphics* CPopView::pgraphics()
{
	ASSERT(_pgraphics);
	return _pgraphics;
}

CRuntimeClass* CPopView::pgraphicsclass()
{
	ASSERT(_pgraphics);
	return _pgraphics->GetRuntimeClass();
}

void CPopView::setRealBox(cRealBox border)
{
	_pgraphics->setRealBox(border); //Only affects cGraphicsMFC, don't need activate
}

void CPopView::vectorToPixel(cVector position, int &xpix, int &ypix, Real &zbuff)
{
	_pgraphics->activate(); //Wake up the graphics
	_pgraphics->vectorToPixel(position, xpix, ypix, zbuff);
}

cVector CPopView::pixelToVector( int xpix, int ypix, Real zbuff)
{
	_pgraphics->activate(); //Wake up the graphics
	return _pgraphics->pixelToVector(xpix, ypix, zbuff);
}

cVector CPopView::pixelToPlayerPlaneVector(int xpix, int ypix)
{
	return pixelToCritterPlaneVector(xpix, ypix, pgame()->pplayer());
}

cVector CPopView::pixelToCritterPlaneVector(int xpix, int ypix, cCritter *pcritter)
{
	_pgraphics->activate(); //Wake up the graphics
	return _pgraphics->pixelAndPlaneToVector(xpix, ypix, pcritter->plane());
}

cVector CPopView::pixelToPlayerYonWallVector(int xpix, int ypix, Real distancetoyon)
{
	return pixelToCritterYonWallVector(xpix, ypix, pgame()->pplayer(), distancetoyon);
}

cVector CPopView::pixelToCritterYonWallVector(int xpix, int ypix, cCritter *pcritter, Real distancetoyon)
{
	_pgraphics->activate(); //Wake up the graphics
	return _pgraphics->pixelAndPlaneToVector(xpix, ypix, cPlane(
		pcritter->position() + distancetoyon*pcritter->attitudeTangent(), -pcritter->attitudeTangent()));
		//The two args to cPlane constructor are (origin, binormal), origin meaning a point on the plane.
}

COLORREF CPopView::sniff(cVector sniffpoint)
{
	_pgraphics->activate(); //Wake up the graphics
	return _pgraphics->sniff(sniffpoint);
}

//=================Special CPopView Methods======================

void CPopView::updateStatusBar()
{
	CMainFrame* cMainFrame = (CMainFrame*)::AfxGetMainWnd();
	CString statusmessage = pgame()->statusMessage();
#ifdef SHOWREFRESHRATEINSTATUSBAR
	CString cStrRefreshrate;
	int refreshrate = ::GetDeviceCaps(cMainFrame->GetDC()->GetSafeHdc(), VREFRESH);
	cStrRefreshrate.Format("  Graphics refresh per second: %d.", refreshrate);
	statusmessage += cStrRefreshrate;
#endif //SHOWREFRESHRATEINSTATUSBAR
#ifdef SHOWSTEREOINSTATUSBAR
	if (_pviewpointcritter->GetRuntimeClass() == RUNTIME_CLASS(cCritterViewerStereo))
		statusmessage += " STEREO ON";
	else
		statusmessage += " STEREO OFF";
#endif //SHOWSTEREOINSTATUSBAR
	cMainFrame->SetMessageText(statusmessage); //Write to status bar
}

BOOL CPopView::isActiveView()
{
	CMDIChildWnd *childframe = (CMDIChildWnd*)GetParentFrame();
	CMDIFrameWnd *mainframe = (CMDIFrameWnd*)(childframe->GetParentFrame());
	return (mainframe->GetActiveFrame() == childframe && childframe->GetActiveView() == this);
/* This alternate method doesn't work, as at the first call, pChild comes out NULL.
	CMDIFrameWnd *pFrame =(CMDIFrameWnd*)AfxGetMainWnd();
	CMDIChildWnd *pChild = pFrame->MDIGetActive();
	CPopView *pView = (CPopView *) pChild->GetActiveView();
	return pView == this;
*/
}

//Accessors

cGame* CPopView::pgame()
{
	CPopDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	return pDoc->pgame();
}

int CPopView::cx()
{
	CRect drawrect;
	GetClientRect(&drawrect);
	return drawrect.Width();
}

int CPopView::cy()
{
	CRect drawrect;
	GetClientRect(&drawrect);
	return drawrect.Height();
}

//========================Mutators==============================

void CPopView::setUseBackground(int backgroundtype)
{
	if (pgame()->pskybox())
		pgame()->pskybox()->setNewgeometryflag(TRUE);
	if (backgroundtype == CPopView::FULL_BACKGROUND)
	{
		_drawflags &= ~CPopView::DF_SIMPLIFIED_BACKGROUND;
		_drawflags |= CPopView::DF_FULL_BACKGROUND;
	}
	else if (backgroundtype == CPopView::SIMPLIFIED_BACKGROUND)
	{
		_drawflags |= CPopView::DF_SIMPLIFIED_BACKGROUND;
		_drawflags &= ~CPopView::DF_FULL_BACKGROUND;
	}
	else
	{
		_drawflags &= ~CPopView::DF_SIMPLIFIED_BACKGROUND;
		_drawflags &= ~CPopView::DF_FULL_BACKGROUND;
	}
}

//===================Menu Message Handlers=========================

void CPopView::OnViewColoredbubbles() 
{ //This makes all sprites "solid", not just those of the bubbles.
	_drawflags &= ~CPopView::DF_WIREFRAME;
	pgame()->setNewgeometryflag(TRUE);
	OnUpdate(NULL, 0, NULL); /* Do this rather than calling Invalidate directly,
		in case we change the way we do the OnUpdate */
}
void CPopView::OnUpdateViewColoredbubbles(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(_drawflags & CPopView::DF_WIREFRAME?0:1);	
}
void CPopView::OnViewXraybubbles() 
{//This makes all sprites "wireframe", not just those of the bubbles.
	_drawflags |= CPopView::DF_WIREFRAME;
	pgame()->setNewgeometryflag(TRUE);
	OnUpdate(NULL, 0, NULL);
}

void CPopView::OnUpdateViewXraybubbles(CCmdUI* pCmdUI) 
{
	pCmdUI->SetCheck(_drawflags & CPopView::DF_WIREFRAME?1:0);	
}

void CPopView::OnViewShootcursor() 
{
	_hCursor = ((CPopApp*)::AfxGetApp())->_hCursorPlay;
}

void CPopView::OnUpdateViewShootcursor(CCmdUI* pCmdUI) 
{
	cGame* pgamedoc = pgame();
	HCURSOR cursortool = ((CPopApp*)::AfxGetApp())->_hCursorPlay;
	pCmdUI->Enable((pgamedoc->validHCURSOR(cursortool) && !pgamedoc->pplayer()->plistener()->IsKindOf(RUNTIME_CLASS(cListenerCursor)))?1:0);
	pCmdUI->SetCheck(_hCursor == cursortool);	
}

void CPopView::OnViewArrowcursor() 
{
	_hCursor = ((CPopApp*)::AfxGetApp())->_hCursorArrow;
}

void CPopView::OnUpdateViewArrowcursor(CCmdUI* pCmdUI) 
{
	cGame* pgamedoc = pgame();
	HCURSOR cursortool = ((CPopApp*)::AfxGetApp())->_hCursorArrow;
	pCmdUI->Enable((pgamedoc->validHCURSOR(cursortool) && !pgamedoc->pplayer()->plistener()->IsKindOf(RUNTIME_CLASS(cListenerCursor)))?1:0);
	pCmdUI->SetCheck(_hCursor == cursortool);	
}

void CPopView::OnViewDraggercursor() 
{
	_hCursor = ((CPopApp*)::AfxGetApp())->_hCursorDragger;
}

void CPopView::OnUpdateViewDraggercursor(CCmdUI* pCmdUI) 
{
	cGame* pgamedoc = pgame();
	HCURSOR cursortool = ((CPopApp*)::AfxGetApp())->_hCursorDragger;
	pCmdUI->Enable((pgamedoc->validHCURSOR(cursortool) && 
		!pgamedoc->pplayer()->plistener()->IsKindOf(
		RUNTIME_CLASS(cListenerCursor)))?1:0);
	pCmdUI->SetCheck(_hCursor == cursortool);	
}

void CPopView::OnViewPincursor() 
{
	_hCursor = ((CPopApp*)::AfxGetApp())->_hCursorPin;
}

void CPopView::OnUpdateViewPincursor(CCmdUI* pCmdUI) 
{
	cGame* pgamedoc = pgame();
	HCURSOR cursortool = ((CPopApp*)::AfxGetApp())->_hCursorPin;
	pCmdUI->Enable((pgamedoc->validHCURSOR(cursortool) && !pgamedoc->pplayer()->plistener()->IsKindOf(RUNTIME_CLASS(cListenerCursor)))?1:0);
	pCmdUI->SetCheck(_hCursor == cursortool);	
}

void CPopView::OnViewSpawncursor() 
{
	_hCursor = ((CPopApp*)::AfxGetApp())->_hCursorSpawn;
}

void CPopView::OnUpdateViewSpawncursor(CCmdUI* pCmdUI) 
{
	cGame* pgamedoc = pgame();
	HCURSOR cursortool = ((CPopApp*)::AfxGetApp())->_hCursorSpawn;
	pCmdUI->Enable((pgamedoc->validHCURSOR(cursortool) && !pgamedoc->pplayer()->plistener()->IsKindOf(RUNTIME_CLASS(cListenerCursor)))?1:0);
	pCmdUI->SetCheck(_hCursor == cursortool);	
}

void CPopView::OnViewZapcursor() 
{
	_hCursor = ((CPopApp*)::AfxGetApp())->_hCursorZap;
}

void CPopView::OnUpdateViewZapcursor(CCmdUI* pCmdUI) 
{
	cGame* pgamedoc = pgame();
	HCURSOR cursortool = ((CPopApp*)::AfxGetApp())->_hCursorZap;
	pCmdUI->Enable((pgamedoc->validHCURSOR(cursortool) && !pgamedoc->pplayer()->plistener()->IsKindOf(RUNTIME_CLASS(cListenerCursor)))?1:0);
	pCmdUI->SetCheck(_hCursor == cursortool);	
}

void CPopView::OnViewReplicatecursor() 
{
	_hCursor = ((CPopApp*)::AfxGetApp())->_hCursorReplicate;
}

void CPopView::OnUpdateViewReplicatecursor(CCmdUI* pCmdUI) 
{
	cGame* pgamedoc = pgame();
	HCURSOR cursortool = ((CPopApp*)::AfxGetApp())->_hCursorReplicate;
	pCmdUI->Enable((pgamedoc->validHCURSOR(cursortool) && !pgamedoc->pplayer()->plistener()->IsKindOf(RUNTIME_CLASS(cListenerCursor)))?1:0);
	pCmdUI->SetCheck(_hCursor == cursortool);	
}

void CPopView::OnGameBackground() 
{
	setUseBackground(CPopView::FULL_BACKGROUND);
}

void CPopView::OnUpdateGameBackground(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable((pgame()->menuflags() & cGame::MENU_BACKGROUND)?TRUE:FALSE);	
	pCmdUI->SetCheck(useFullBackground()?1:0);
}

void CPopView::OnViewSolidbackground() 
{
	setUseBackground(CPopView::SIMPLIFIED_BACKGROUND);
}

void CPopView::OnUpdateViewSolidbackground(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable((pgame()->menuflags() & cGame::MENU_BACKGROUND)?TRUE:FALSE);	
	pCmdUI->SetCheck(!useFullBackground() && useSimplifiedBackground()?1:0);
}

void CPopView::OnViewNobackground() 
{
	setUseBackground(CPopView::NO_BACKGROUND);
}

void CPopView::OnUpdateViewNobackground(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable((pgame()->menuflags() & cGame::MENU_BACKGROUND)?TRUE:FALSE);	
	pCmdUI->SetCheck(!useFullBackground() && !useSimplifiedBackground()?1:0);
}

void CPopView::OnViewMfcgraphics() 
{
	if(pgraphicsclass()==(RUNTIME_CLASS(cGraphicsMFC)))
		return;
	if (_pviewpointcritter->IsKindOf(
		RUNTIME_CLASS(cCritterViewerStereo))) //Turn off stereo
	{
		delete _pviewpointcritter;
		_pviewpointcritter = new cCritterViewer(this);
	}
	setGraphicsClass(RUNTIME_CLASS(cGraphicsMFC));
	pgame()->initializeViewpoint(_pviewpointcritter);
	pgraphics()->installLightingModel(pgame()->plightingmodel());
}

void CPopView::OnUpdateViewMfcgraphics(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(pgame()->menuflags() & cGame::MENU_2D);
	pCmdUI->SetCheck(pgraphicsclass()==(RUNTIME_CLASS(cGraphicsMFC))?1:0);		
}

void CPopView::OnViewOpenglgraphics() 
{
	if(pgraphicsclass()==(RUNTIME_CLASS(cGraphicsOpenGL)))
		return;
	setGraphicsClass(RUNTIME_CLASS(cGraphicsOpenGL));
	pgame()->initializeViewpoint(_pviewpointcritter);
	pgraphics()->installLightingModel(pgame()->plightingmodel());
}

void CPopView::OnUpdateViewOpenglgraphics(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(pgame()->menuflags() & cGame::MENU_3D);
	pCmdUI->SetCheck(pgraphicsclass()==(RUNTIME_CLASS(cGraphicsOpenGL))?1:0);
}

void CPopView::OnViewOpenglStereo() 
{
	BOOL stereoOn = _pviewpointcritter->IsKindOf(
		RUNTIME_CLASS(cCritterViewerStereo));
	stereoOn = !stereoOn; //Toggle on or off.
	if (stereoOn) //Just turned stereo on
	{
			delete _pviewpointcritter;
			_pviewpointcritter = new cCritterViewerStereo(this);;
	}
	else //Just turned stereo off
	{
		delete _pviewpointcritter;
		_pviewpointcritter = new cCritterViewer(this);
	}
		/* I'm not sure I need the next three lines, but for now they seem safe. 
		Without them I was seeing a problem of the colors on cSpriteQuake models
		going bad if I turned stereo on and then off, also I was seeing my
		view get a little horizontally stretched. */
	pgame()->initializeView(this);
		/* At one point I was forcing a rider listener on the viewer if stereo here. */
	pgame()->initializeViewpoint(_pviewpointcritter);
	pgraphics()->installLightingModel(pgame()->plightingmodel());
		/* Instead of calling the three initialization lines, I could just
		call OnUpdate(NULL, CPopDoc::VIEWHINT_STARTGAME, NULL); which
		has the effect of the three	previous lines.*/
}

void CPopView::OnUpdateViewOpenglStereo(CCmdUI* pCmdUI) 
{
	// TODO: Add your command update UI handler code here
	pCmdUI->Enable(_pgraphics->is3D());
	pCmdUI->SetCheck(_pviewpointcritter->GetRuntimeClass()
		==(RUNTIME_CLASS(cCritterViewerStereo))?1:0);
}

void CPopView::OnViewTranslate() 
{
	_pviewpointcritter->setListener(new cListenerViewerOrtho());
}

void CPopView::OnUpdateViewTranslate(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(_pgraphics->is3D()?0:1); //Don't use Ortho View in 3D
	pCmdUI->SetCheck(_pviewpointcritter->plistener()->GetRuntimeClass()
		== (RUNTIME_CLASS(cListenerViewerOrtho))?1:0);
}

void CPopView::OnViewRide() 
{
	if (_pviewpointcritter->plistener()->GetRuntimeClass()
		!= (RUNTIME_CLASS(cListenerViewerRide)))
		_pviewpointcritter->setListener(new cListenerViewerRide());
	else
		_pviewpointcritter->setListener(new cListenerViewerFly());
	pgame()->initializeViewpoint(_pviewpointcritter);
}

void CPopView::OnUpdateViewRide(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(pgame()->visibleplayer() && 
		_pgraphics->is3D() && 
		(pgame()->menuflags() & cGame::MENU_RIDEPLAYER) &&
 		!(pgame()->pplayer()->plistener()->IsKindOf(
			RUNTIME_CLASS(cListenerCursor))));
	pCmdUI->SetCheck(_pviewpointcritter->plistener()->GetRuntimeClass()
		== (RUNTIME_CLASS(cListenerViewerRide))?1:0);
}

void CPopView::OnViewFly() 
{
	_pviewpointcritter->setListener(new cListenerViewerFly());
	pgame()->initializeViewpoint(_pviewpointcritter);
}

void CPopView::OnUpdateViewFly(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(_pgraphics->is3D()?1:0);
	pCmdUI->SetCheck(_pviewpointcritter->plistener()->GetRuntimeClass()
		== (RUNTIME_CLASS(cListenerViewerFly))?1:0);
}

void CPopView::OnViewOrbit() 
{
	_pviewpointcritter->setListener(new cListenerViewerOrbit());
	pgame()->initializeViewpoint(_pviewpointcritter);
}

void CPopView::OnUpdateViewOrbit(CCmdUI* pCmdUI) 
{
	pCmdUI->Enable(_pgraphics->is3D()?1:0);
	pCmdUI->SetCheck(_pviewpointcritter->plistener()->GetRuntimeClass()
		== (RUNTIME_CLASS(cListenerViewerOrbit))?1:0);
}

void CPopView::OnViewKeepplayerinview() 
{
	_pviewpointcritter->setTrackplayer(_pviewpointcritter->trackplayer()^TRUE);
		//Toggle the value.
	pgame()->initializeViewpoint(_pviewpointcritter);
	if (_pviewpointcritter->trackplayer())
		_pviewpointcritter->lookAt(pgame()->pplayer()->position());
}

void CPopView::OnUpdateViewKeepplayerinview(CCmdUI* pCmdUI) 
{
	BOOL isok = pgame()->menuflags() & cGame::MENU_TRACKPLAYER && //Only turn on/off if game allows
		pgame()->visibleplayer() && //Only track visible.
		!(_pviewpointcritter->plistener()->GetRuntimeClass()== 
			RUNTIME_CLASS(cListenerViewerRide)); //Don't track and ride.
	pCmdUI->Enable(isok?TRUE:FALSE);
	pCmdUI->SetCheck(_pviewpointcritter->trackplayer()?1:0);
}

void CPopView::OnViewRestoreViewpoint() 
{
	_pviewpointcritter->resetAndMatchMoveBox(pgame());	//Put in defaults like at start
	pgame()->initializeViewpoint(_pviewpointcritter); //Then make the standard adjustments.
}

//fullscreen...start
void CPopView::OnChar(UINT nChar, UINT nRepCnt, UINT nFlags)
{
	if (nChar == VK_ESCAPE)
	{
		CMainFrame* pFrame = (CMainFrame*) AfxGetMainWnd();
		pFrame->EscapeFullScreen();
	}
	CView::OnChar(nChar, nRepCnt, nFlags);
}
//fullscreen...end