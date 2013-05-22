// dialogstereo.cpp : implementation file
//

#include "stdafx.h"
#include "pop.h"
#include "dialogstereo.h"
#include "Popview.h"
#include "critterviewerstereo.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

BEGIN_MESSAGE_MAP(cStereoDialog, CDialog)
	//{{AFX_MSG_MAP(cStereoDialog)
	ON_BN_CLICKED(IDC_Reset, OnReset)
	ON_WM_VSCROLL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

//Some handy defines=======================

#define SPINCLICKS 50
	//Spin buttons go from 0 to SPINCLICKS, one unit at a time.
//Two helper methods for the scroll controls.
float spinvalue(int n, float lo, float hi)
{
	float spinproportion = (float)(n)/(SPINCLICKS);
	return(spinproportion * (hi - lo) + lo);
}	
int inversespinvalue(float val, float lo, float hi)
{
	return (int)(SPINCLICKS*(val - lo)/(hi - lo));
}

/////////////////////////////////////////////////////////////////////////////
// cStereoDialog dialog

cStereoDialog::cStereoDialog(CWnd* pParent)
: CDialog(cStereoDialog::IDD, pParent),
m_pView(NULL),
m_pstereo(NULL)
{
	//{{AFX_DATA_INIT(cStereoDialog)
	m_stereointensity = 10.0f;
	m_virtualdistance = 20.0f;
	//}}AFX_DATA_INIT
}

cStereoDialog::cStereoDialog(CPopView* pView):
m_pstereo(NULL)
{
	m_pView = pView;
	m_stereointensity = 10.0;
	m_virtualdistance = 20.0;
	CDialog::Create(cStereoDialog::IDD, pView);
	m_pView->SetActiveWindow();
	m_pView->SetFocus();
}

void cStereoDialog::attachStereoViewer(cCritterViewerStereo *pstereoviewer)
{
	m_pstereo = pstereoviewer;
	setVisualDrag(m_pstereo->getVisualDrag());
	setStereoIntensity(m_pstereo->getStereoIntensity());
}

void cStereoDialog::setStereoIntensity(Real si)
{
	m_stereointensity = si;
	UpdateData(FALSE); //Fixes the edit box to match
	fixSpinButtons(); //Fixes the scroll bar position
}

void cStereoDialog::setVisualDrag(Real vd)
{
	m_virtualdistance = vd;
	UpdateData(FALSE); //Fixes the edit box to match
	fixSpinButtons(); //Fixes the scroll bar position
}

void cStereoDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(cStereoDialog)
	DDX_Text(pDX, IDC_CAMOFFSET, m_stereointensity);
	DDV_MinMaxFloat(pDX, m_stereointensity,
		cCritterViewerStereo::MINSI,
		cCritterViewerStereo::MAXSI);
	DDX_Text(pDX, IDC_FOCALLEN, m_virtualdistance);
	DDV_MinMaxFloat(pDX, m_virtualdistance,
		cCritterViewerStereo::MINVD,
		cCritterViewerStereo::MAXVD);
	//}}AFX_DATA_MAP
}

BOOL cStereoDialog::UpdateData(BOOL bSaveAndValidate)
{
	BOOL success = CDialog::UpdateData(bSaveAndValidate);
	if (bSaveAndValidate && success)
	{
		updateStereoViewer();
		fixSpinButtons();
	}
	return success;
}

/////////////////////////////////////////////////////////////////////////////
// cStereoDialog message handlers

/////////////////////////////////////////////////////////////////////////////
// cStereoDialog message handlers

void cStereoDialog::updateStereoViewer()
{
	if (m_pstereo)
	{
		m_pstereo->setVisualDrag(m_virtualdistance, FALSE);
		m_pstereo->setStereoIntensity(m_stereointensity, FALSE);
			/* The FALSE argument means don't let the viewer send a 
			mutator call right back at me. */
	}
	m_pView->SetActiveWindow();
	m_pView->SetFocus();
}

void cStereoDialog::OnReset() 
{
	m_stereointensity = cCritterViewerStereo::DEFAULTSTEROINTENSITY;
	m_virtualdistance = cCritterViewerStereo::DEFAULTVISUALDRAG;
	UpdateData(FALSE); //Set the controls to match
	updateStereoViewer(); //Set the stereoviewer to match;
}

void cStereoDialog::OnCancel()
{
	// Do nothing here
}

void cStereoDialog::OnOK()//You get this when you press ENTER.
{
	UpdateData(TRUE); /* Copy controls to our local values.  If successful, UpdateData
		will also send new local values to the stereoviewer. */
}


//SCROLL Stuff==========================================================

	
BOOL cStereoDialog::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CSpinButtonCtrl *pSpin =
		(CSpinButtonCtrl *)GetDlgItem(IDC_SPINFOCAL);
	pSpin->SetRange(0, SPINCLICKS);
	pSpin->SetPos(0);

	pSpin = (CSpinButtonCtrl *)GetDlgItem(IDC_SPINCAM);
	pSpin->SetRange(0, SPINCLICKS);
	pSpin->SetPos(0);

	return TRUE;  // return TRUE unless you want to set the focus to a control
}

void cStereoDialog::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	CDialog::OnVScroll(nSBCode, nPos, pScrollBar);
	switch (pScrollBar->GetDlgCtrlID())
	{
		case IDC_SPINFOCAL:
			m_virtualdistance = spinvalue(nPos,
				cCritterViewerStereo::MINVD,
				cCritterViewerStereo::MAXVD);
			break;
		case IDC_SPINCAM:
			m_stereointensity = spinvalue(nPos,
				cCritterViewerStereo::MINSI,
				cCritterViewerStereo::MAXSI);
			break;
	}
	UpdateData(FALSE);
	updateStereoViewer();
}

void cStereoDialog::fixSpinButtons() 
{
	CSpinButtonCtrl *pSpin;
	pSpin =	(CSpinButtonCtrl *)GetDlgItem(IDC_SPINFOCAL);
	pSpin->SetPos(inversespinvalue(m_virtualdistance,
				cCritterViewerStereo::MINVD,
				cCritterViewerStereo::MAXVD));
	pSpin = (CSpinButtonCtrl *)GetDlgItem(IDC_SPINCAM);
	pSpin->SetPos(inversespinvalue(m_stereointensity,
				cCritterViewerStereo::MINSI,
				cCritterViewerStereo::MAXSI));
}


