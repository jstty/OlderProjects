// Pop.h : main header file for the POP application
//

#if !defined(AFX_POP_H__89C2B645_322E_11D3_AD90_000000000000__INCLUDED_)
#define AFX_POP_H__89C2B645_322E_11D3_AD90_000000000000__INCLUDED_

/*
#ifndef USE_DIRECTSOUND
   #define USE_DIRECTSOUND
#endif
*/

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols
#include "memorydc.h" //for cTransparentMemoryDC
#include "realnumber.h" //for Real
#include "timer.h" //for cPerformanceTimer

// added by: Joseph E. Sutton
#include "../code/defs.h"

#include "MainFrm.h"

#ifdef USE_DIRECTSOUND
	#include "DxSound.h" // For DirectSound/Music
#endif // USE_DIRECTSOUND


/////////////////////////////////////////////////////////////////////////////
// CPopApp:
// See Pop.cpp for the implementation of this class
//
class CPopDoc; //Forward declaration for the getActiveDoc method.

class CPopApp : public CWinApp
{
public:
	CPopApp();
	~CPopApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPopApp)
	public:
	virtual BOOL InitInstance();
	virtual BOOL OnIdle(LONG lCount);
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CPopApp)
	afx_msg void OnAppAbout();
	afx_msg void OnGamePlaysounds();
	afx_msg void OnUpdateGamePlaysounds(CCmdUI* pCmdUI);
	afx_msg void OnFileNew();
	afx_msg void OnFileOpen();
	afx_msg void OnGameSpeed();
	afx_msg void OnUpdateGameAnimate(CCmdUI* pCmdUI);
	afx_msg void OnGameAnimate();
	afx_msg void OnOpenglinfodialog();
	afx_msg void OnUpdateFileNew(CCmdUI* pCmdUI);
	afx_msg void OnAbout();
	afx_msg void OnExit();
	afx_msg void OnAppExit();
	afx_msg void OnFullscreen();
	afx_msg void OnUserGuide();
	afx_msg void OnHelpUsersguide();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
//-------Human code starts here.  RR.
private:
	BOOL _sound_is_enabled; //for toggling sound
	double _runspeed;


#ifdef USE_DIRECTSOUND
	cDxSound* _pdxSound; // for DirectSound/Music
#endif // USE_DIRECTSOUND

public: 
   CMainFrame* pMainFrame;

	static Real MINDT; // Default shortest update time.
	static int STARTPIXELWIDTH; //Default window size
	static int STARTPIXELHEIGHT;
	static int MAXCHILDWINDOWCOUNT; //Max child windows you allow, to avoid crashing.
	BOOL _animateflag; //for toggling animation
	HCURSOR _hCursorPlay;
	HCURSOR _hCursorArrow;
	HCURSOR _hCursorDragger;
	HCURSOR _hCursorPin; //Load these at startup
	HCURSOR _hCursorZap;
	HCURSOR _hCursorReplicate;
	HCURSOR _hCursorSpawn;
	class cCritter *_pcritter_clipboard;
	cPerformanceTimer _timer;
	void playSound(LPCSTR pwavfileresourcename); //Calls ::PlaySound if _sound_is_enabled.
	void playMusic(const char* filename);
	void stopMusic();
	void stopSound();
	void animateAllDocs(Real dt); //special animation function.
	double appdt(){return _runspeed*_timer.dt();}
	double runspeed(){return _runspeed;}
	int cursorToID(HCURSOR hcursor);
	void setRunspeed(Real rs){CLAMP(rs, 0.0, 10.0); _runspeed = rs;}
	HCURSOR IDToCursor(int cursorid);
	BOOL isDocOpen(); //Is there an open doc?  Used to enable sound and pause.
	CPopDoc* getActiveDoc(); /* Return pointer to the document whose view has the focus, or NULL.
		We don't actually use this method anywhere. */ 
	CPopDoc* getDocByTitle(CString targettitle); /* Return pointer to doc with this title, or NULL.
		Note that a doc title is the name+file extension without any directory info.  This method
		is not case-sensitive. We use getDocByTitle in our overload of OpenDocumentFile. */
	virtual CDocument* OpenDocumentFile(LPCTSTR lpszFileName); /* This  method is called by
		OnFileOpen. We overload it to close any document with the same name as the file we're
		opening.  We need the overlaod because the default AFX behavior is to refuse to open a 
		file if a doc with the same title is open. */

   void RemoveStyle(long style);
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_POP_H__89C2B645_322E_11D3_AD90_000000000000__INCLUDED_)
