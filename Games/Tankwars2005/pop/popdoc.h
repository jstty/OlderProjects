
// PopDoc.h : interface of the CPopDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_POPDOC_H__89C2B64D_322E_11D3_AD90_000000000000__INCLUDED_)
#define AFX_POPDOC_H__89C2B64D_322E_11D3_AD90_000000000000__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include "realbox.h"  //For the _border accessor.

class cGame; //For the *_pgame member.
class cBiota; //For the cBiota* return type of the pbiota() method.
class CPopView; //For the GetActiveView method return type.

class cTimeHint : public CObject
{
	DECLARE_DYNAMIC(cTimeHint) //so we can check the runtime class in CPopView::OnUpdate.
private:
	Real _dt;
public:
	cTimeHint(Real dt):_dt(dt){}
	Real dt(){return _dt;}
};

class cArchiveHint : public CObject
{
	DECLARE_DYNAMIC(cArchiveHint) //so we can check the runtime class in CPopView::OnUpdate.
private:
	CArchive * _parchive;
public:
	cArchiveHint(CArchive *parch):_parchive(parch){}
	~cArchiveHint(){}
	CArchive* parchive(){return _parchive;}
};

class CPopDoc : public CDocument
{
protected: // create from serialization only
	CPopDoc();
	DECLARE_DYNCREATE(CPopDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPopDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CPopDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CPopDoc)
	afx_msg void OnGameHuge();
	afx_msg void OnUpdateGameHuge(CCmdUI* pCmdUI);
	afx_msg void OnGameLarge();
	afx_msg void OnUpdateGameLarge(CCmdUI* pCmdUI);
	afx_msg void OnGameMedium();
	afx_msg void OnUpdateGameMedium(CCmdUI* pCmdUI);
	afx_msg void OnGameSmall();
	afx_msg void OnUpdateGameSmall(CCmdUI* pCmdUI);
	afx_msg void OnGameRestart();
	afx_msg void OnGameFancypolygons();
	afx_msg void OnGamePolypolygons();
	afx_msg void OnGameSimplepolygons();
	afx_msg void OnGameAsteroids();
	afx_msg void OnGameTriplepolypolygons();
	afx_msg void OnEditCopy();
	afx_msg void OnUpdateEditCopy(CCmdUI* pCmdUI);
	afx_msg void OnEditCut();
	afx_msg void OnUpdateEditCut(CCmdUI* pCmdUI);
	afx_msg void OnEditPaste();
	afx_msg void OnUpdateEditPaste(CCmdUI* pCmdUI);
	afx_msg void OnGameBitmaps();
	afx_msg void OnUpdateGameBitmaps(CCmdUI* pCmdUI);
	afx_msg void OnGameAssorted();
	afx_msg void OnUpdateGameAssorted(CCmdUI* pCmdUI);
	afx_msg void OnGameWrap();
	afx_msg void OnUpdateGameWrap(CCmdUI* pCmdUI);
	afx_msg void OnUpdateGameTriplepolypolygons(CCmdUI* pCmdUI);
	afx_msg void OnUpdateGameAsteroids(CCmdUI* pCmdUI);
	afx_msg void OnUpdateGameFancypolygons(CCmdUI* pCmdUI);
	afx_msg void OnUpdateGamePolypolygons(CCmdUI* pCmdUI);
	afx_msg void OnUpdateGameSimplepolygons(CCmdUI* pCmdUI);
	afx_msg void OnPlayerFlykeys();
	afx_msg void OnUpdatePlayerFlykeys(CCmdUI* pCmdUI);
	afx_msg void OnPlayerCarkeys();
	afx_msg void OnUpdatePlayerCarkeys(CCmdUI* pCmdUI);
	afx_msg void OnPlayerSpaceshipkeys();
	afx_msg void OnUpdatePlayerSpaceshipkeys(CCmdUI* pCmdUI);
	afx_msg void OnPlayerShield();
	afx_msg void OnUpdatePlayerShield(CCmdUI* pCmdUI);
	afx_msg void OnUpdatePlayerRubberbullets(CCmdUI* pCmdUI);
	afx_msg void OnPlayerRubberbullets();
	afx_msg void OnUpdatePlayerDeadlybullets(CCmdUI* pCmdUI);
	afx_msg void OnPlayerDeadlybullets();
	afx_msg void OnPlayerMassiveplayer();
	afx_msg void OnUpdatePlayerMassiveplayer(CCmdUI* pCmdUI);
	afx_msg void OnPlayerAbsorberplayer();
	afx_msg void OnUpdatePlayerAbsorberplayer(CCmdUI* pCmdUI);
	afx_msg void OnPlayerBouncingplayer();
	afx_msg void OnUpdatePlayerBouncingplayer(CCmdUI* pCmdUI);
	afx_msg void OnPlayerAutoplay();
	afx_msg void OnUpdatePlayerAutoplay(CCmdUI* pCmdUI);
	afx_msg void OnPlayerCursorcritter();
	afx_msg void OnUpdatePlayerCursorcritter(CCmdUI* pCmdUI);
	afx_msg void OnPlayerArrowkeys();
	afx_msg void OnUpdatePlayerArrowkeys(CCmdUI* pCmdUI);
	afx_msg void OnGameDesignlab();
	afx_msg void OnUpdateGameDesignlab(CCmdUI* pCmdUI);
	afx_msg void OnGameBounce();
	afx_msg void OnUpdateGameBounce(CCmdUI* pCmdUI);
	afx_msg void OnGameMazeplay();
	afx_msg void OnUpdateGameMazeplay(CCmdUI* pCmdUI);
	afx_msg void OnGameBubbles();
	afx_msg void OnUpdateGameBubbles(CCmdUI* pCmdUI);
	afx_msg void OnPlayerHoppercontrol();
	afx_msg void OnUpdatePlayerHoppercontrol(CCmdUI* pCmdUI);
	afx_msg void OnGameQuakeStyleModels();
	afx_msg void OnUpdateGameQuakeStyleModels(CCmdUI* pCmdUI);
	afx_msg void OnPlayerScooterhopper3d();
	afx_msg void OnUpdatePlayerScooterhopper3d(CCmdUI* pCmdUI);
	afx_msg void OnGameSpheres();
	afx_msg void OnUpdateGameSpheres(CCmdUI* pCmdUI);

   afx_msg void OnGameSpacewar();
	afx_msg void OnUpdateGameSpacewar(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
//--------Human Written Code Starts Here-------------- RR
public: //Statics
	static const int SPACEWAR;
	static const int PATTERNS;
	static const int ASTEROIDS;
	static const int VIEWHINT_STARTGAME;
	static const int VIEWHINT_LOADINGARCHIVE;
protected:
	cGame *_pgame;
public:
	void stepDoc(Real dt); //Called by CPopApp.  It calls _pgame->step(dt) and UpdateAllViews.
	CPopView* getActiveView(); //This is a useful method to have around.
	cGame* pgame(){/*ASSERT (_pgame && "CPopDoc has valid cGame pointer _pgame."); */return _pgame;}
	cBiota* pbiota();
	cRealBox border();
	void setGameClass(CRuntimeClass *pruntimeclass);
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POPDOC_H__89C2B64D_322E_11D3_AD90_000000000000__INCLUDED_)
