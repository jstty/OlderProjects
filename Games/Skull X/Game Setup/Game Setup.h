// Game Setup.h : main header file for the GAME SETUP application
//

#if !defined(AFX_GAMESETUP_H__2BD6A0B7_CDF0_4F35_AF24_B2C346FEC40D__INCLUDED_)
#define AFX_GAMESETUP_H__2BD6A0B7_CDF0_4F35_AF24_B2C346FEC40D__INCLUDED_

#if _MSC_VER >= 1000
#pragma once
#endif // _MSC_VER >= 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGameSetupApp:
// See Game Setup.cpp for the implementation of this class
//

class CGameSetupApp : public CWinApp
{
public:
	CGameSetupApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGameSetupApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGameSetupApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Developer Studio will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GAMESETUP_H__2BD6A0B7_CDF0_4F35_AF24_B2C346FEC40D__INCLUDED_)
