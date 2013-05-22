// dialogopenglinfo.cpp : implementation file
//

#include "stdafx.h"
#include "pop.h"
#include "dialogopenglinfo.h"
#include "graphicsopengl.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// cDialogOpenGLInfo dialog


cDialogOpenGLInfo::cDialogOpenGLInfo(CWnd* pParent /*=NULL*/)
	: CDialog(cDialogOpenGLInfo::IDD, pParent)
{
	//{{AFX_DATA_INIT(cDialogOpenGLInfo)
	//}}AFX_DATA_INIT
}


void cDialogOpenGLInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(cDialogOpenGLInfo)
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(cDialogOpenGLInfo, CDialog)
	//{{AFX_MSG_MAP(cDialogOpenGLInfo)
		// NOTE: the ClassWizard will add message map macros here
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// cDialogOpenGLInfo message handlers

BOOL cDialogOpenGLInfo::OnInitDialog()
{
	BOOL returnval = CDialog::OnInitDialog();
	CString infostring = cGraphicsOpenGL::_graphicsmodestring + cGraphicsOpenGL::_vendorstring +
		cGraphicsOpenGL::_rendererstring;
		/* I could show the extension string, but this is more something
		the programmer cares about than the user. If I show _extensionsstring,
		I need to resize the IDC_STATICINFO box so it fits, it's multiple lines, 
		and may be quite quite long.*/
	CString commentstring("    If your \"Renderer\" is \"Microsoft Corporation\" your OpenGL calculations are done in software rather than hardware, and performance may be too slow.\n    In this case, try using your system's Display Properties dialog to set a different number of bits per pixel. Depending on the card, 16, 14, or 32 bits per pixel may be needed for hardware acceleration.\n    If this doesn't work, you can try going to the web page of your graphics card manufacturer to download and install a graphics card driver with OpenGL hardware acceleration for your operating system.\n    Graphics card drivers sometimes have bugs, if one driver causes problems, try another.");

	SetDlgItemText(IDC_STATICINFO, infostring);
	SetDlgItemText(IDC_STATICCOMMENT, commentstring);
	return returnval;
}