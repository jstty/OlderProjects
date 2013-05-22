// PopView.h : interface of the CPopView class
//
// Spring 2003
// Retrofitted by Kenji Tan
// Original code by Professor Rudy Rucker
// Added: Stereo mode command handlers - OnViewOpenglStereo, OnUpdateViewOpenglStereo
//		  reference to modeless dialog box cStereoDialog *_pDlg
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_POPVIEW_H__89C2B64F_322E_11D3_AD90_000000000000__INCLUDED_)
#define AFX_POPVIEW_H__89C2B64F_322E_11D3_AD90_000000000000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "popdoc.h"

class cGraphics; //for _pgraphics member.
class cCritterViewer; //for _pviewpointcritter member.
class cCritter; //for the pixelToCritterPlaneVector method argument.
class cStereoDialog; // for modeless stereo dialog box

class CPopView : public CView
{
protected: // create from serialization only
	CPopView();
	DECLARE_DYNCREATE(CPopView)
	void _deleteGraphics(); /* This call deletes _pgraphics
		and _pviewpointcritter, as the latter may be tuned to the former. */

// Attributes
public:
	CPopDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPopView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnUpdate(CView* pSender, LPARAM lHint, CObject* pHint);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPopView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPopView)
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnViewColoredbubbles();
	afx_msg void OnUpdateViewColoredbubbles(CCmdUI* pCmdUI);
	afx_msg void OnViewXraybubbles();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnViewDraggercursor();
	afx_msg void OnUpdateViewDraggercursor(CCmdUI* pCmdUI);
	afx_msg void OnViewPincursor();
	afx_msg void OnUpdateViewPincursor(CCmdUI* pCmdUI);
	afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnUpdateViewXraybubbles(CCmdUI* pCmdUI);
	afx_msg void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	afx_msg void OnKeyUp(UINT nChar, UINT nRepCnt, UINT nFlags);
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnViewArrowcursor();
	afx_msg void OnUpdateViewArrowcursor(CCmdUI* pCmdUI);
	afx_msg void OnViewSpawncursor();
	afx_msg void OnUpdateViewSpawncursor(CCmdUI* pCmdUI);
	afx_msg void OnViewZapcursor();
	afx_msg void OnUpdateViewZapcursor(CCmdUI* pCmdUI);
	afx_msg void OnViewReplicatecursor();
	afx_msg void OnUpdateViewReplicatecursor(CCmdUI* pCmdUI);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	afx_msg void OnGameBackground();
	afx_msg void OnUpdateGameBackground(CCmdUI* pCmdUI);
	afx_msg void OnViewShootcursor();
	afx_msg void OnUpdateViewShootcursor(CCmdUI* pCmdUI);
	afx_msg void OnViewOpenglgraphics();
	afx_msg void OnUpdateViewOpenglgraphics(CCmdUI* pCmdUI);
	afx_msg void OnViewMfcgraphics();
	afx_msg void OnUpdateViewMfcgraphics(CCmdUI* pCmdUI);
	afx_msg void OnViewTranslate();
	afx_msg void OnUpdateViewTranslate(CCmdUI* pCmdUI);
	afx_msg void OnViewRide();
	afx_msg void OnUpdateViewRide(CCmdUI* pCmdUI);
	afx_msg void OnViewFly();
	afx_msg void OnUpdateViewFly(CCmdUI* pCmdUI);
	afx_msg void OnViewKeepplayerinview();
	afx_msg void OnUpdateViewKeepplayerinview(CCmdUI* pCmdUI);
	afx_msg void OnViewOrbit();
	afx_msg void OnUpdateViewOrbit(CCmdUI* pCmdUI);
	afx_msg void OnViewSolidbackground();
	afx_msg void OnUpdateViewSolidbackground(CCmdUI* pCmdUI);
	afx_msg void OnViewNobackground();
	afx_msg void OnUpdateViewNobackground(CCmdUI* pCmdUI);
	afx_msg void OnViewRestoreViewpoint();
	afx_msg void OnDestroy();
	afx_msg void OnViewOpenglStereo();
	afx_msg void OnUpdateViewOpenglStereo(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
//==========Human Written code starts here============  RR.
public: //Statics
	static BOOL STARTBITMAPBACKGROUNDFLAG;
	static BOOL STARTSOLIDBACKGROUNDFLAG;
	static COLORREF GAMEOVEREDGECOLOR;
	static COLORREF GAMEACTIVEEDGECOLOR;
 /*DF stands for drawflags.  Used by all the draw(cGraphics, drawflags) methods in cGame,
		cBiota, cCritter, and cSprite. */
	static const int DF_STANDARD; //Setting drawflags = DF_STANDARD does a standard draw.
	static const int DF_FOCUS; //Draw a dotted-line circle around the sprite.
	static const int DF_WIREFRAME; //Means fill with NULL_BRUSH.
	static const int DF_FULL_BACKGROUND; //Means to fill the game border with a bitmap.
	static const int DF_SIMPLIFIED_BACKGROUND; //Means to fill the game border with a solid
		//color provided that DF_FULL_BACKGROUND isn't on.
	static const int DF_DRAWING_SKYBOX; //Means I'm drawing a
		//skybox, and in this case I handle the 2D case differently,
		//See cSpriteTextureBox::draw.
	static const int NO_BACKGROUND;
	static const int SIMPLIFIED_BACKGROUND;
	static const int FULL_BACKGROUND;
protected:
	cCritterViewer *_pviewpointcritter;
	cGraphics *_pgraphics; /* _pgraphics is the currently active cGraphics
		pointer, which may be cGraphicsMFC or cGraphicsOpenGL. */
	int _drawflags;
	HCURSOR _hCursor;
	//Functions
	void updateStatusBar();
	BOOL isActiveView(); //Useful in the OnSetCursor call.
public:
//Accessors
	cGraphics *pgraphics();
	CRuntimeClass* pgraphicsclass();
	BOOL useFullBackground(){return _drawflags & CPopView::DF_FULL_BACKGROUND?TRUE:FALSE;}
	BOOL useSimplifiedBackground(){return _drawflags & CPopView::DF_SIMPLIFIED_BACKGROUND?TRUE:FALSE;}
	HCURSOR hcursor(){return _hCursor;}
	int drawflags(){return _drawflags;}
	int cx();
	int cy();
	cGame* pgame();
	cCritterViewer* pviewpointcritter()
		{ASSERT(_pviewpointcritter); return _pviewpointcritter;}
	CPoint CPopView::paneColRow();/*	Return the pane location (col, row), starting with (0,0).
		This is useful in cGame::initializeView and cGame::initializeViewpoint.
		Think of (col, row) as being like the (x, y) position of the pane in the
		grid. */
//Mutators
	void setGraphicsClass(CRuntimeClass *pruntimegraphicsclass); /* Feed in either
		RUNTIME_CLASS(cGraphicsMFC) or RUNTIME_CLASS(cGraphicsOpenGL).  Don't
		call this in the constructor as CPopView isn't complete enough yet to
		support intializeOpenGL.  Call in OnCreate or perhaps in response to a 
		View menu selection that asks to change the graphics type. */
	void setUseBackground(int backgroundtype); /* The background type can be
		CPopView::NO_BACKGROUND, CPopView::SIMPLIFIED_BACKGROUND, or 
		CPopView::FULL_BACKGROUND, which often means: nothing, lines, or
		planes&bitmaps, depending on how the skybox is defined. */
	void setCursor(HCURSOR hcursor){_hCursor = hcursor;}//Use in PopDoc when chaging gametype.
	void setCursorPosToCritter(cCritter *pcritter); 
//Methods that make a simple call to _pgraphics
	//Vector/pixel methods
	void setRealBox(cRealBox border);
	void vectorToPixel(cVector position, int &xpix, int &ypix, Real &zbuff);
	cVector pixelToVector( int xpix, int ypix, Real zbuff = 0.0);
	cVector pixelToCritterPlaneVector(int xpix, int ypix, cCritter *pcritter);
	cVector pixelToPlayerPlaneVector(int xpix, int ypix);
	cVector pixelToCritterYonWallVector(int xpix, int ypix, cCritter *pcritter, Real distancetoyon);
	cVector pixelToPlayerYonWallVector(int xpix, int ypix, Real distancetoyon);
	COLORREF sniff(cVector sniffpoint);
//Serialize
	virtual void Serialize(CArchive& ar);
//	afx_msg void OnGetMinMaxInfo(MINMAXINFO* lpMMI);
	afx_msg void OnChar(UINT nChar, UINT nRepCnt, UINT nFlags); //fullscreen
};

#ifndef _DEBUG  // debug version in PopView.cpp
inline CPopDoc* CPopView::GetDocument()
   { return (CPopDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POPVIEW_H__89C2B64F_322E_11D3_AD90_000000000000__INCLUDED_)
