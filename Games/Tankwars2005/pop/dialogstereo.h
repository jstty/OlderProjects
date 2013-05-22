#ifndef DIALOGSTEREO_H
#define DIALOGSTEREO_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// dialogstereo.h : header file for the Stereo Viewer adjuster
/////////////////////////////////////////////////////////////////////////////
// cStereoDialog dialog

/* Forward declarations for CPopView and cCritterViewerStereo */
class CPopView;
class cCritterViewerStereo;

class cStereoDialog : public CDialog
{
// Dialog Data

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(cStereoDialog)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL
// Implementation
protected:
	// Generated message map functions
	//{{AFX_MSG(cStereoDialog)
	virtual BOOL OnInitDialog();
	afx_msg void OnReset();
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnCancel();
	afx_msg void OnOK();
	//}}AFX_MSG
DECLARE_MESSAGE_MAP()
protected:
	//{{AFX_DATA(cStereoDialog)
	enum { IDD = IDD_StereoDialog };
	float	m_stereointensity;
	float	m_virtualdistance;
	//}}AFX_DATA
	CPopView* m_pView;
	cCritterViewerStereo *m_pstereo;
public:
// Construction
	cStereoDialog(CWnd* pParent = NULL);   // standard constructor
	cStereoDialog(CPopView* pView);
	void attachStereoViewer(cCritterViewerStereo *pstereoviewer);
//Mutators
	void setStereoIntensity(Real si); //These have to match the controls to new vals
	void setVisualDrag(Real vd);
//Special methods
	void updateStereoViewer();
	void fixSpinButtons();
//Overrides
	BOOL UpdateData(BOOL bSaveAndValidate = TRUE); /* Calls the DoDataExchange.
		TRUE means copy the controls to the local variables, FALSE means
		copy the control settings to the local variables.  We overlaod so that
		with TRUE we also set the values in m_pstereo. */
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // DIALOGSTEREO_H
