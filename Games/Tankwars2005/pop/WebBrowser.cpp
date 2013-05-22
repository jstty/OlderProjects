// WebBrowser.cpp : implementation file
//

#include "stdafx.h"
#include "WebBrowser.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CWebBrowser

IMPLEMENT_DYNCREATE(CWebBrowser, CHtmlView)

CWebBrowser::CWebBrowser()
{
	EnableAutomation();
	//{{AFX_DATA_INIT(CWebBrowser)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

CWebBrowser::~CWebBrowser()
{
}

void CWebBrowser::OnFinalRelease()
{
	// When the last reference for an automation object is released
	// OnFinalRelease is called.  The base class will automatically
	// deletes the object.  Add additional cleanup required for your
	// object before calling the base class.

	CHtmlView::OnFinalRelease();
}

void CWebBrowser::DoDataExchange(CDataExchange* pDX)
{
	CHtmlView::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWebBrowser)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CWebBrowser, CHtmlView)
	//{{AFX_MSG_MAP(CWebBrowser)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CWebBrowser, CHtmlView)
	//{{AFX_DISPATCH_MAP(CWebBrowser)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

// Note: we add support for IID_IWebBrowser to support typesafe binding
//  from VBA.  This IID must match the GUID that is attached to the 
//  dispinterface in the .ODL file.

// {A4AAF905-688E-11D4-8408-005004E390E4}
static const IID IID_IWebBrowser =
{ 0xa4aaf905, 0x688e, 0x11d4, { 0x84, 0x8, 0x0, 0x50, 0x4, 0xe3, 0x90, 0xe4 } };

BEGIN_INTERFACE_MAP(CWebBrowser, CHtmlView)
	INTERFACE_PART(CWebBrowser, IID_IWebBrowser, Dispatch)
END_INTERFACE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CWebBrowser diagnostics

#ifdef _DEBUG
void CWebBrowser::AssertValid() const
{
	CHtmlView::AssertValid();
}

void CWebBrowser::Dump(CDumpContext& dc) const
{
	CHtmlView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CWebBrowser message handlers

long __stdcall CWebBrowser::Go(VARIANT text)
{
	
	MessageBox("Go");

	return 0;
}
