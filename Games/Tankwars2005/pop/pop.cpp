// Pop.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include <mmsystem.h> //for PlaySound

#include "Pop.h"
#include "ChildFrm.h"
#include "critter.h" //So you know how to delete a critter_clipboard.
#include "MainFrm.h"
#include "PopDoc.h"
#include "PopView.h"
#include "dialogspeed.h" //for cSpeedDialog
#include "dialogopenglinfo.h" //for cDialogOpenGLInfo
#include "quakeMD2model.h" //So we can free static model information arrays.

#include "../code/StaticLink.h"
CStaticLink *Link;

#ifdef USE_DIRECTSOUND
	#include "DxSound.h" // For DirectSound/Music
#endif // USE_DIRECTSOUND

// added by: Joseph E. Sutton
#include "../code/tankwars2005.h"
cTankWars2005 *tws2005;
CPopApp *gpop_app;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//================== CPopApp Statics =============================
Real CPopApp::MINDT = 0.01; //Shortest allowable time step in seconds, means 100 updates a second.
int CPopApp::STARTPIXELWIDTH = 800;
int CPopApp::STARTPIXELHEIGHT = 600;
int CPopApp::MAXCHILDWINDOWCOUNT = 4; /* Don't allow more than this many child views open. */
/////////////////////////////////////////////////////////////////////////////
// CPopApp

BEGIN_MESSAGE_MAP(CPopApp, CWinApp)
	//{{AFX_MSG_MAP(CPopApp)
	ON_COMMAND(ID_APP_ABOUT, OnAppAbout)
	ON_COMMAND(ID_GAME_PLAYSOUNDS, OnGamePlaysounds)
	ON_UPDATE_COMMAND_UI(ID_GAME_PLAYSOUNDS, OnUpdateGamePlaysounds)
	ON_COMMAND(ID_FILE_NEW, OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, OnFileOpen)
	ON_COMMAND(ID_GAME_SPEED, OnGameSpeed)
	ON_UPDATE_COMMAND_UI(ID_GAME_ANIMATE, OnUpdateGameAnimate)
	ON_COMMAND(ID_GAME_ANIMATE, OnGameAnimate)
	ON_COMMAND(ID_OPENGLINFODIALOG, OnOpenglinfodialog)
	ON_UPDATE_COMMAND_UI(ID_FILE_NEW, OnUpdateFileNew)
	ON_COMMAND(ID_ABOUT, OnAbout)
	ON_COMMAND(ID_EXIT, OnExit)
	ON_COMMAND(ID_APP_EXIT, OnAppExit)
	ON_COMMAND(ID_FULLSCREEN, OnFullscreen)
	ON_COMMAND(ID_USER_GUIDE, OnUserGuide)
	ON_COMMAND(ID_HELP_USERSGUIDE, OnHelpUsersguide)
	//}}AFX_MSG_MAP
	// Standard file based document commands
	ON_COMMAND(ID_FILE_NEW, CWinApp::OnFileNew)
	ON_COMMAND(ID_FILE_OPEN, CWinApp::OnFileOpen)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPopApp construction

CPopApp::CPopApp():
// Modifed by: Joseph E. Sutton
_sound_is_enabled(TRUE), //Start with sound turned on (TRUE) or off (FALSE)
_runspeed(1.0), //Start with realtime runspeed
_animateflag(TRUE), //Start with animation off for framework, make TRUE for apps.
_pcritter_clipboard(NULL)
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
	_timer.setMinDt(CPopApp::MINDT); //Don't run faster than 100 updates a second.
	/* The default setting of the _timer's MinDt gets overriden in the mainframe.cpp
	file where we try and set the mindt so as not to outstrip the graphics card 
	update speed: there's no point doing updates you can't see. We can't do this here
	because we need a valid HWND in order to get an HDC to make a GetDeviceCaps call
	to find out the refresh rate. */
}

CPopApp::~CPopApp()
{
	delete _pcritter_clipboard;
	_pcritter_clipboard = NULL;
	cRandomizer::deleteSingleton(); /* Need this or you have a memory leak. */
#ifdef USE_DIRECTSOUND
	delete _pdxSound; // Free DirectSound/Music resources
#endif // USE_DIRECTSOUND
}
/////////////////////////////////////////////////////////////////////////////
// The one and only CPopApp object

CPopApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CPopApp initialization

BOOL CPopApp::InitInstance()
{
// Resource Initialization code by RR.===================
	/* Any code which loads resources for the views to use has to go in here
	before the ParseCommandLine code below, because the view is going to be
	created in ParseCommandLine and you have to get ready first. 
	Note that the resource-loading code can't go into the overloaded CWinApp
	constructor because the App isn't "alive" enough yet at that point to
	be able to load it's resrouces. */
	_hCursorPlay = LoadStandardCursor(IDC_CROSS);
	_hCursorArrow = LoadStandardCursor(IDC_ARROW);
	_hCursorDragger = LoadCursor(IDC_DRAGHAND);
	_hCursorPin = LoadCursor(IDC_PIN);
	_hCursorZap = LoadCursor(IDC_ZAP);
	_hCursorReplicate = LoadCursor(IDC_REPLICATE);
	_hCursorSpawn = LoadCursor(IDC_SPAWN);

//End Resource Initialization code by RR.====================
//=======App Wizard code from here on.============
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

/* We don't need the Enable3dControls calls anymore, these are deprecated now and in 
fact they throw a warning in Visual Studio 7, and they don't make a difference in
Visual Studio 6.
#ifdef _AFXDLL
	Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif
*/

	// Change the registry key under which our settings are stored.
	// TODO: You should modify this string to be something appropriate
	// such as the name of your company or organization.
	//SetRegistryKey(_T("Local AppWizard-Generated Applications"));
	//LoadStdProfileSettings();  // Load standard INI file options (including MRU)

	// Register the application's document templates.  Document templates
	//  serve as the connection between documents, frame windows and views.

// IDR_POPTYPE, IDR_MAINFRAME

   tws2005 = NULL;
   gpop_app = this;

	CMultiDocTemplate* pDocTemplate;
	pDocTemplate = new CMultiDocTemplate(
		IDR_MAINFRAME,
		RUNTIME_CLASS(CPopDoc),
		RUNTIME_CLASS(CChildFrame), // custom MDI child frame
		RUNTIME_CLASS(CPopView)); //The pressure point where we pick what kind of default view to use.
	AddDocTemplate(pDocTemplate);

	// create main MDI Frame window
	pMainFrame = new CMainFrame;
	if (!pMainFrame->LoadFrame(IDR_MAINFRAME))
		return FALSE;
	m_pMainWnd = pMainFrame;

// For DirectSound/Music
#ifdef USE_DIRECTSOUND
	_pdxSound = cDxSound::getInstance();
#endif // USE_DIRECTSOUND

	// Parse command line for standard shell commands, DDE, file open
	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);

	// Dispatch commands specified on the command line
	if (!ProcessShellCommand(cmdInfo))
		return FALSE;


	// The main window has been initialized, so show and update it.
	//pMainFrame->ShowWindow(SW_SHOWMAXIMIZED | m_nCmdShow); //Use this version if you want main window maximized.
	pMainFrame->ShowWindow(m_nCmdShow); //Use this version if you don't want main window maximized.
	pMainFrame->UpdateWindow();

   // Added: Timer Message to start full screen
   // Modifyed by: Joseph E. Sutton
#ifdef FULL_SCREEN
   pMainFrame->OnViewFullscreen();
#endif

   pMainFrame->SetTimer(GAME_LOOP_ID, 10, NULL);

  	return TRUE;
}

void CPopApp::RemoveStyle(long style)
{
   long current_style = GetWindowLong(pMainFrame->GetSafeHwnd(), GWL_STYLE);

   if( (current_style & style) == style )
      current_style -= style;

   SetWindowLong(pMainFrame->GetSafeHwnd(), GWL_STYLE, current_style);
}


/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	CStaticLink	m_link;
	CRichEditCtrl	m_info;
	CRichEditCtrl	m_cr;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnLink();
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	DDX_Control(pDX, IDC_LINK, m_link);
	DDX_Control(pDX, IDC_INFO, m_info);
	DDX_Control(pDX, IDC_CR, m_cr);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
	ON_BN_CLICKED(IDC_LINK, OnLink)
	ON_WM_MOUSEMOVE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

// App command to run the dialog
void CPopApp::OnAppAbout()
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

//////////////////////////////////////////////////////////////////////////
//cOpenGLDialog


/////////////////////////////////////////////////////////////////////////////
// CPopApp message handlers


void CPopApp::OnFileNew() 
{
	CMainFrame* mainframe = (CMainFrame*)::AfxGetMainWnd();
	if (mainframe->getMDIChildCount() >= CPopApp::MAXCHILDWINDOWCOUNT)
	{
		::MessageBeep(MB_ICONEXCLAMATION);
		return;
	}
	CWinApp::OnFileNew(); //Call base class handler first.
	//-------My Code.  RR. See comment on CMainFrame::OnWindowNew
	// Purpose of this is to glue multiple windows into tiled position.
	if (mainframe->_autotile && mainframe->getMDIChildCount() > 1) //Automatically keep all views tiled
		mainframe->MDITile(MDITILE_VERTICAL);
}

void CPopApp::OnFileOpen() 
{
	CMainFrame* mainframe = (CMainFrame*)::AfxGetMainWnd();
	if (mainframe->getMDIChildCount() >= CPopApp::MAXCHILDWINDOWCOUNT)
	{
		::MessageBeep(MB_ICONEXCLAMATION);
		return;
	}
	CWinApp::OnFileOpen(); /* This pops up a dialog box to get the
		lpszFileName, then calls OpenDocumentFile(LPCTSTR lpszFileName) */
	//-------My Code.  RR. See comment on CMainFrame::OnWindowNew
	// Purpose of this is to glue multiple windows into tiled position.
	if (mainframe->_autotile && mainframe->getMDIChildCount() > 1) //Automatically keep all views tiled
		mainframe->MDITile(MDITILE_VERTICAL);
}

CDocument* CPopApp::OpenDocumentFile(LPCTSTR lpszFileName)
{
	ASSERT(m_pDocManager != NULL); //Base class code
//Special Pop framework code starts here.
//First of all we clean up the 
	CString filename(lpszFileName);
	filename.MakeLower();
	int lastslashindex = filename.ReverseFind('\\'); 
		 /* Finds the index of the last backslash in the string, as is used in
		a dirctory name like C:\pop\test.pop". As you start counting with 0, you'd
		get 6 in this case. Note that I have to use the escape sequence '\\' as '\' won't compile. */
	if (lastslashindex != -1) //ReverseFind returns a -1 if no slash is found in the file name.  
		/* Note that if we didn't find a slash, we will use the whole filenname, so there's nothing
		to truncate, so we don't do this next step. */
		filename = filename.Right(filename.GetLength()-(lastslashindex+1)); 
			/* Right(n) returns the last n characters.  As the slash is at lastindex, there are
			lastindex+1 chars we don't want. */
	CPopDoc *pdoc = getDocByTitle(filename);
	if (pdoc)
		pdoc->OnCloseDocument(); //Close doc with same name.
//Special Pop framework code ends here.
	return m_pDocManager->OpenDocumentFile(lpszFileName); //Base class code
}


void CPopApp::OnGameSpeed() 
{
/* I want to have the user set _runspeed by setting an index from 1 to 10.
  Rather than having a linear scale, we'll list a specific runspeed value for
	each smoothnessIndex choice. In the interface we speak of higher smoothnessIndex
	as meaning smoother, slower motion, so we ramp the runspeed values the opposite
	way from the indices. */

	static double smoothnessIndexToRunspeed[10] =
		{10.0, 7.0, 5.0, 3.0, 2.0, 1.0, 0.7, 0.4, 0.1, 0.01}; 
		//  0	 1    2    3    4	 5    6    7    8     9	
	static int runspeedindex = 4;
	int nUpdatesPerSecond = int(_timer.updatesPerSecond());
	cSpeedDialog dlg;
	if (!nUpdatesPerSecond)
		dlg.m_cstrUpdatespersecond.Format("Less than one.");
	else	
		dlg.m_cstrUpdatespersecond.Format("%d", nUpdatesPerSecond);
	dlg.m_nSpeed = runspeedindex + 1;
	/* When using a modal dialog, it's important to bail out and not use its
		dlg values in the case where you exit the dialog by a Cancel, because
		then these will be bad values.  In other words, if I just call
		dlg.DoModal() instead of the next line, then if I input a bad value
		like -1 for the speed, and then Cancel out of the dialog, the bad
		value is still in dlg.m_nSpeed, and would get (disatrously) used.  So
		that's why I need to not use the values when DoModal returns IDCANCEL. */
	if (dlg.DoModal() == IDCANCEL)
		return;
	runspeedindex = dlg.m_nSpeed - 1; //Will lie between 1 and 10
	_runspeed = smoothnessIndexToRunspeed[runspeedindex];
}

BOOL CPopApp::OnIdle(LONG lCount) 
{
/* The default CWinApp behavior is to return CWinApp::OnIdle(lCount).
We'll do exactly this in the cases where either _animateflag is false or
where my WinApp is not the active window currently being used.
I do this second case so the program won't soak a lot of CPU time
when it's not in the foreground. If I really wanted the program to 
run off to one side like a miniatue screensaver, I could comment these
three lines our, alternately, I could put a switch in the CMainFrame to turn
them or and off.*/
//============ Non-foreground mode ======================
	CWnd *cwmainframe = AfxGetMainWnd();
	if (cwmainframe != cwmainframe->GetForegroundWindow()) 
		return CWinApp::OnIdle(lCount); 
		 
//============ Foreground mode ==========================
/*In the case where my WinApp is active, I'll first do the baseclass
processing, and then I'll start animating my documents. And then I'll return TRUE, 
which means that I want the WinApp::Run to keep on calling this OnIdle function 
over and over.
The lCount param tells you how many times OnIdle has been called since the last
message was processed.  Windows uses the  0th and 1st call to OnIdle for its own 
stuff, so we don't animate until those have been done, otherwise Windows has to
wait after the 0th for the 1st call, and this could cause GUI lag. */
	CWinApp::OnIdle(lCount); //Do the base class WinApp processing.
	if (lCount < 2) //Still doing Windows OnIdle processing, so call OnIdle again.
		return TRUE;
	/* Even if you're not animating, any change, such as a key press or a mouse 
action will generate a call to OnIdle, and we use this as chance to keep the docs
up to date. */
	if (!_animateflag)
	{ // Do a single update with a dt of 0.0.
		animateAllDocs(0.0);
		return FALSE; //Don't need to call OnIdle again until a message is received.
	}
	// The lCount >= 2 and _animateflag case.
	Real dt = _runspeed*_timer.tick(); /* Update the dt cycle time to be the realdt
		that the timer measures in the world times the _runspeed. */
	animateAllDocs(dt); //Step through all the docs and animate each doc and its views.
	return TRUE; //Keep doing OnIdle over and over while waiting for another message.
}

/////////////////////////////////////////////////////////////////////////////
// My CPopApp functions

void CPopApp::playSound(LPCSTR pwavfileresourcename)
{
	if (!_sound_is_enabled)
		return;
#ifdef USE_DIRECTSOUND
	// We use DirectSound only if USE_DIRECTSOUND is defined AND we could initalize it
	// If either case fails, then we resort to regular sound playing
	if(_pdxSound)
	{
		_pdxSound->playSound((char*)pwavfileresourcename);
		return;
	}
#endif // USE_DIRECTSOUND
	::PlaySound(NULL, NULL, 0); //Turn off any currently playing sound.
		//This would happen anyway
	::PlaySound(pwavfileresourcename, NULL, SND_RESOURCE | SND_ASYNC); 
		/*SND_RESOURCE means that the argument has to be the ID of a
		a sound in the resurces.    SND_ASYNC says to continue running
		the program without wating for the sound to finish. */
}

void CPopApp::playMusic(const char* filename)
{
	if (!_sound_is_enabled)
		return;
#ifdef USE_DIRECTSOUND
	if(_pdxSound)
	{
		_pdxSound->playMusic(filename);
	}
#endif // USE_DIRECTSOUND
}

void CPopApp::stopMusic()
{
#ifdef USE_DIRECTSOUND
	if(_pdxSound) _pdxSound->stopCurrentSong();
#endif USE_DIRECTSOUND
}

void CPopApp::stopSound()
{
	::PlaySound(NULL, NULL, 0); //Stops current sound
}

void CPopApp::animateAllDocs(Real dt)
{
	CMultiDocTemplate* pSelectedTemplate;
	CPopDoc* pDoc;
	POSITION docpos;
	POSITION pos = GetFirstDocTemplatePosition();
	if (pos == NULL)
		return; //No doc template exists yet.
	pSelectedTemplate = (CMultiDocTemplate*)GetNextDocTemplate(pos);
	docpos = pSelectedTemplate->GetFirstDocPosition();//find first document
	while(docpos != NULL) //while there are documents left to process
	{
		pDoc = (CPopDoc*)pSelectedTemplate->GetNextDoc(docpos); /* This retrieves
			the document at position docpos and then increments docpos to the next
			position. */
		pDoc->stepDoc(dt);  /* CAlifeDocument::stepDoc() will animate the *pDoc and
			call UpdateAllViews to update the *pDoc's views. */
	}
}

CPopDoc* CPopApp::getActiveDoc()
{
	CMultiDocTemplate* pSelectedTemplate;
	CPopDoc* pDoc;
	POSITION docpos;
	POSITION pos = GetFirstDocTemplatePosition();
	if (pos == NULL)
		return NULL; //No doc template exists yet.
	pSelectedTemplate = (CMultiDocTemplate*)GetNextDocTemplate(pos);
	docpos = pSelectedTemplate->GetFirstDocPosition();//find first document
	while(docpos != NULL) //while there are documents left to process
	{
		pDoc = (CPopDoc*)pSelectedTemplate->GetNextDoc(docpos); /* This retrieves
			the document at position docpos and then increments docpos to the next
			position. */
		if (pDoc->getActiveView() && pDoc->getActiveView()->GetDocument()==pDoc)
			return pDoc;
	}
	return NULL;
}

CPopDoc* CPopApp::getDocByTitle(CString targettitle)
{
	CMultiDocTemplate* pSelectedTemplate;
	CPopDoc* pDoc;
	POSITION docpos;
	POSITION pos = GetFirstDocTemplatePosition();
	if (pos == NULL)
		return NULL; //No doc template exists yet.
	pSelectedTemplate = (CMultiDocTemplate*)GetNextDocTemplate(pos);
	docpos = pSelectedTemplate->GetFirstDocPosition();//find first document
	while(docpos != NULL) //while there are documents left to process
	{
		pDoc = (CPopDoc*)pSelectedTemplate->GetNextDoc(docpos); /* This retrieves
			the document at position docpos and then increments docpos to the next
			position. */
		CString doctitle = pDoc->GetTitle();
			 //The title is the name+file extension without any directory info.
		targettitle.MakeLower(); //To avoid false negatives, we discard case info.
		doctitle.MakeLower();
		if (doctitle == targettitle)
			return pDoc;
	}
	return NULL; //If no doc with this title is found.
}

BOOL CPopApp::isDocOpen()
{
	CMultiDocTemplate* pSelectedTemplate;
	POSITION docpos;
	POSITION pos = GetFirstDocTemplatePosition();
	if (pos == NULL)
		return FALSE; //No doc template exists yet.
	pSelectedTemplate = (CMultiDocTemplate*)GetNextDocTemplate(pos);
	docpos = pSelectedTemplate->GetFirstDocPosition();//find first document
	if (docpos == NULL) //no documents  to process
		return FALSE;
	else
		return TRUE;
}

void CPopApp::OnGamePlaysounds() 
{
	_sound_is_enabled ^= TRUE;	
#ifdef USE_DIRECTSOUND
	if(_pdxSound && !_sound_is_enabled) stopMusic();
#endif
}

void CPopApp::OnUpdateGamePlaysounds(CCmdUI* pCmdUI) 
{ //Labelled as "Mute" so show as !_sound_is_enabled.
	pCmdUI->Enable(isDocOpen()?TRUE:FALSE);	
	pCmdUI->SetCheck(_sound_is_enabled?0:1);	
}


void CPopApp::OnUpdateGameAnimate(CCmdUI* pCmdUI) 
{ //This is labeled "Pause" now, so we check as !_animateflag.
	pCmdUI->Enable(isDocOpen()?TRUE:FALSE);	
	pCmdUI->SetCheck(_animateflag?0:1);	
}

void CPopApp::OnGameAnimate() 
{
	_animateflag ^= TRUE;	
	if (_animateflag)
		_timer.reset(); /* If you are just turning on the animateflag, you need
		to reset the cycle counter */
}

void CPopApp::OnOpenglinfodialog() 
{
	cDialogOpenGLInfo infodlg;
	infodlg.DoModal();
}

int CPopApp::cursorToID(HCURSOR hcursor)
{
	if (hcursor == _hCursorPlay)
		return 0;
	if (hcursor == _hCursorArrow)
		return 1;
	if (hcursor == _hCursorDragger)
		return 2;
	if (hcursor == _hCursorPin)
		return 3;
	if (hcursor == _hCursorZap)
		return 4;
	if (hcursor == _hCursorReplicate)
		return 5;
	if (hcursor == _hCursorSpawn)
		return 6;
	else
		return 1;
}

HCURSOR CPopApp::IDToCursor(int cursorid)
{
	if (cursorid == 0)	
		return _hCursorPlay;
	if (cursorid == 1)	
		return _hCursorArrow;
	if (cursorid == 2)	
		return _hCursorDragger;
	if (cursorid == 3)	
		return _hCursorPin; 
	if (cursorid == 4)	
		return _hCursorZap;
	if (cursorid == 5)	
		return _hCursorReplicate;
	if (cursorid == 6)	
		return _hCursorSpawn;
	else
		return _hCursorArrow;
}

void CPopApp::OnUpdateFileNew(CCmdUI* pCmdUI) 
{ /* I don't want user to be able to make a second doc, so disable File|New if
a doc is open. */
	pCmdUI->Enable(getActiveDoc()==NULL?TRUE:FALSE);	
}

void CPopApp::OnAbout() 
{
	CAboutDlg aboutDlg;
	aboutDlg.DoModal();
}

void CPopApp::OnExit() 
{
	PostQuitMessage(1);
}

void CPopApp::OnAppExit() 
{
   OnExit();
}

void CPopApp::OnFullscreen() 
{
   pMainFrame->OnViewFullscreen();
}


void CPopApp::OnUserGuide() 
{
   /*
#ifndef POPHTMLHELP //If not POPHTMLHELP do it the old way with a *.hlp
	::WinHelp(pMainFrame->GetSafeHwnd(), "help\\tws2005.hlp", HELP_CONTENTS, 0);	
#else // POPHTMLHELP means use a *.chm.
	::HtmlHelp(pMainFrame->GetSafeHwnd(),"help\\tws2005.chm", HH_DISPLAY_TOPIC, 0) ;
#endif //End POPHTMLHELP switch
*/
   char temp[256];
   GetCurrentDirectory(255, temp);
   CString s;
   s = temp;
   s.Replace('\\', '/');
   s += "/help/tws2005.pdf";

   ShellExecute(NULL, "open", s, NULL, NULL, SW_SHOWNORMAL);
}

void CPopApp::OnHelpUsersguide() 
{
   OnUserGuide();
}


BOOL CAboutDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	CHARFORMAT cf;

   //
	ZeroMemory(&cf, sizeof(CHARFORMAT));
	cf.cbSize = sizeof(CHARFORMAT);
	cf.dwMask = CFM_COLOR | CFM_BOLD;
	cf.dwEffects = CFE_BOLD;
	cf.crTextColor = RGB(255, 255, 255);
	m_info.SetDefaultCharFormat(cf);
	m_info.SetBackgroundColor(false, RGB(0, 0, 0));

	m_info.SetWindowText( ABOUT_INFO );
//
	
//
	ZeroMemory(&cf, sizeof(CHARFORMAT));
	cf.cbSize = sizeof(CHARFORMAT);
	cf.dwMask = CFM_COLOR | CFM_BOLD;
	cf.dwEffects = CFE_BOLD;
	cf.crTextColor = RGB(255, 255, 255);
	m_cr.SetDefaultCharFormat(cf);
	m_cr.SetBackgroundColor(false, RGB(0, 0, 0));

	m_cr.SetWindowText( ABOUT_CR );
//

   Link = &m_link;
	m_link.SetWindowText(ABOUT_LINK);
	m_link.Hand = LoadCursor( AfxGetApp()->m_hInstance, MAKEINTRESOURCE(IDC_ZAP));
	m_link.ShowWindow(SW_SHOW);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CAboutDlg::OnLink() 
{
   // go to website	
   ShellExecute(NULL, "open", ABOUT_LINK, NULL, NULL, SW_SHOWNORMAL); 
}

void CAboutDlg::OnMouseMove(UINT nFlags, CPoint point) 
{
   m_link.m_bOver = false;
	m_link.RedrawWindow();
	
	CDialog::OnMouseMove(nFlags, point);
}
