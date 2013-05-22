////////////////////////////////////////////////////////////////// 
// CStaticLink 1997 Microsoft Systems Journal. 
// If this program works, it was written by Paul DiLascia.
// If not, I don't know who wrote it.
// CStaticLink implements a static control that's a hyperlink
// to any file on your desktop or web. You can use it in dialog boxes
// to create hyperlinks to web sites. When clicked, opens the file/URL
//

#include "StdAfx.h"
#include "StaticLink.h"

#define ABOUT_WEB_Unvisited RGB(255,255,  0)
#define ABOUT_WEB_Hover		 RGB(255,  0,	0)
#define ABOUT_WEB_Visited   RGB(255,  0,255)

extern CStaticLink *Link;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNAMIC(CStaticLink, CStatic)

BEGIN_MESSAGE_MAP(CStaticLink, CStatic)
 ON_WM_CTLCOLOR_REFLECT()
 //ON_CONTROL_REFLECT(STN_CLICKED, OnClicked)
 ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()
///////////////////
// Constructor sets default colors = blue/purple.
//
CStaticLink::CStaticLink()
{
 m_colorUnvisited = ABOUT_WEB_Unvisited;  // blue
 m_colorHover		= ABOUT_WEB_Hover;      // Red
 m_colorVisited   = ABOUT_WEB_Visited;    // purple
 m_bVisited       = FALSE;                // not visited yet
 m_bOver				= FALSE;                // not visited yet

 Hand = NULL;

 hbr = (HBRUSH)::GetStockObject(HOLLOW_BRUSH);
}
//////////////////// Handle reflected WM_CTLCOLOR to set custom control color.
// For a text control, use visited/unvisited colors and underline font.
// For non-text controls, do nothing. Also ensures SS_NOTIFY is on.
//
HBRUSH CStaticLink::CtlColor(CDC* pDC, UINT nCtlColor)
{
 ASSERT(nCtlColor == CTLCOLOR_STATIC);
 DWORD dwStyle = GetStyle();
 if (!(dwStyle & SS_NOTIFY)) {
     // Turn on notify flag to get mouse messages and STN_CLICKED.
     // Otherwise, I'll never get any mouse clicks!
     ::SetWindowLong(m_hWnd, GWL_STYLE, dwStyle | SS_NOTIFY);
 }

 if ((dwStyle & 0xFF) <= SS_RIGHT)
 {
     if (!(HFONT)m_font)
	 {
         LOGFONT lf;
         GetFont()->GetObject(sizeof(lf), &lf);
         lf.lfUnderline = TRUE;
         m_font.CreateFontIndirect(&lf);
     }
     pDC->SelectObject(&m_font);


	 if(!m_bOver)		pDC->SetTextColor(m_bVisited ? m_colorVisited : m_colorUnvisited);
	 else						pDC->SetTextColor(m_colorHover);

     pDC->SetBkMode(TRANSPARENT);
 }
 return hbr;
}


#include "../pop/resource.h"
void CStaticLink::OnMouseMove(UINT nFlags, CPoint point) 
{
	if(Link != NULL)
	{
		if(this == Link) Link->m_bOver = true;
		else				  Link->m_bOver = false;
		
		Link->RedrawWindow();
	}

	SetClassLong(m_hWnd, GCL_HCURSOR, (long)Hand);
	CStatic::OnMouseMove(nFlags, point);
}

