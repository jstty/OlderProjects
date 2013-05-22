// dialogopenglinfo.h : header file
//

#ifndef DIALOGOPENGLINFO_H 
#define DIALOGOPENGLINFO_H 


/////////////////////////////////////////////////////////////////////////////
// cDialogOpenGLInfo dialog

class cDialogOpenGLInfo : public CDialog
{
// Construction
public:
	cDialogOpenGLInfo(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(cDialogOpenGLInfo)
	enum { IDD = IDD_OPENGLINFO };
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(cDialogOpenGLInfo)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(cDialogOpenGLInfo)
		// NOTE: the ClassWizard will add member functions here
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
//Human code goes here
public:
	BOOL OnInitDialog(); //Override the base method to put our own text in a static text box ID_STATICINFO

};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif DIALOGOPENGLINFO_H 
