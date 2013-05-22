// stdafx.h : include file for standard system include files,
//  or project specific include files that are used frequently, but
//      are changed infrequently
//

#if !defined(AFX_STDAFX_H__89C2B647_322E_11D3_AD90_000000000000__INCLUDED_)
#define AFX_STDAFX_H__89C2B647_322E_11D3_AD90_000000000000__INCLUDED_
/* 	The alternate #if !defined syntax is used instead of #ifndef.  
The "label" given for the include file is some hideous machine-generated thing which
perhaps includes the orignal builder's Visual Studio registration number.  RR. */

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
/*The _MSC_VER symbol is a macro that returns a number associated with the version number
 of Visual Studio being used.  Visual C++ 6.0 happens to return the number 1200,
 which means that it supports a new "pragma" called "once" which specifies that
 the StdAfx.h file can only be included once.  (Really, this is redundant, as the 
trick with the initial #if !defined ensures the same thing.  Microsoft is simply
 showing off a new compiler feature for us here.) RR. */

#define VC_EXTRALEAN		// Exclude rarely-used stuff from Windows headers
/* The #define VC_EXTRALEAN is a preprocessor switch that is set before
including the Windows header files such as afxwin.h immediately below.  You can 
find documentation on it under the name "VC_LEANMEAN" in the Help files; it's
 something you can turn on and off by using your Project|Settings... dialog. 
 Setting a "switch"  before including the Windows header files such as can have 
the  effect of changing the actual code from files such as afxwin.h which gets
included.  Note that the VC_EXTRALEAN excludes everything that
the older WIN32_LEAN_AND_MEAN does, and more.  RR. */
#include <afxwin.h>         // MFC core and standard components
#include <afxext.h>         // MFC extensions
#include <afxdisp.h>        // MFC Automation classes
#include <afxdtctl.h>		// MFC support for Internet Explorer 4 Common Controls
#ifndef _AFX_NO_AFXCMN_SUPPORT
#include <afxcmn.h>			// MFC support for Windows Common Controls
#endif // _AFX_NO_AFXCMN_SUPPORT

//================Human code goes here======================= RR.
//==============Special includes========================
#include <afxtempl.h> //Include the afx template header for CArray everywhere.  RR.
#include <math.h> //Include the math library everywhere. RR.

#define new DEBUG_NEW
	/* The purpose of #define new DEBUG_NEW is to make it easier to track the
	location of memory leaks.  Normally, if there is a memory leak, the output window 
	WILL tell you the number of bytes in the leaked memory and the
	Hexadecimal code address of where the object came from.  But then it's hard to 
	figure out the real source of the allocated but unallocated memory.
	Once you comment in the #define new DEBUG_NEW  directive, the preprocessor will
	insert some MFC macro code calld DEBUG_NEW wherever you use "new".  The effect of
	the DEBUG_NEW macro versoin of "new" is to save file and line number with each
	"new" call, and if there is a memory leak,  the filename and line number information
	about the source of the leak is dumped to the Output window at exit.  The macro
	code is not used when you compile a Release version of your program; in that case
	DEBUG_NEW resolves back to the standard "new" operation.
	You can leave the #define new DEBUG_NEW directive off unless you know you
	have a memory leak, and you are trying to track it down.  It 
	would seem to be a possibility that leaving the directive on may cause your Debug
	build to run anomolously, so if you have problems with the Debug build vs. the
	Releae build, try commenting out  #define new DEBUG_NEW and see if it makes
	a difference. 

	WARNING: DEBUG_NEW is incompatible with some standard template library
	STL code.  If you want to use STL templates, you'll have to comment
	out #define new DEBUG_NEW.

	By the way if you use STL, you always have to include the template with
	lines of this form
		#include <set>
		using namespace std;
*/

//==============Human code ends here================================

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.



#endif // !defined(AFX_STDAFX_H__89C2B647_322E_11D3_AD90_000000000000__INCLUDED_)
