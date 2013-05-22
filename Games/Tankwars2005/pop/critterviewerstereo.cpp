//=============================================================
//
// CritterViewerStereo.cpp
// 
// Spring 2003
// Developed by Kenji Tan for his Master's Degree CS 298: Writing Project
// in the CS at SJSU, Spring 2003.  Reworked by Rudy Rucker.
//


#include "stdafx.h"
#include "critterviewerstereo.h"
#include "game.h"
#include "listener.h"
#include "Pop.h"
#include "PopView.h"
#include "PopDoc.h"
#include "graphicsopengl.h"
#include "graphicsmfc.h"
#include "dialogstereo.h"

IMPLEMENT_SERIAL(cCritterViewerStereo, cCritterViewer, 0)

Real cCritterViewerStereo::STEREOINTENSITY_TO_STEREO_OFFSET_MULTIPLIER = 0.04; 
Real cCritterViewerStereo::VISUALDRAG_TO_STEREO_OFFSET_MULTIPLIER =	0.01; 
Real cCritterViewerStereo::DEFAULTSTEROINTENSITY = 5.0;
Real cCritterViewerStereo::DEFAULTVISUALDRAG = 5.0;
Real cCritterViewerStereo::MINSI = 0.0;
Real cCritterViewerStereo::MAXSI = 10.0;
Real cCritterViewerStereo::MINVD = 0.0;
Real cCritterViewerStereo::MAXVD = 10.0; 

HDC cCritterViewerStereo::_desktop = 0; /* Windows treats the 0 HDC as
	being the whole screen, that is, the desktop. */
HBRUSH cCritterViewerStereo::_bluebrush = ::CreateSolidBrush(RGB(0,0,255));
HBRUSH cCritterViewerStereo::_blackbrush = ::CreateSolidBrush(RGB(0,0,0));
RECT cCritterViewerStereo::_leftField = {0};
RECT cCritterViewerStereo::_rightField = {0};
RECT cCritterViewerStereo::_black = {0};

cCritterViewerStereo::cCritterViewerStereo(CPopView *pview):
cCritterViewer(pview),
_eyeField(FIELD_LEFT),
_stereoIntensity(cCritterViewerStereo::DEFAULTSTEROINTENSITY),
_visualDrag(cCritterViewerStereo::DEFAULTVISUALDRAG),
_pdlgstereo(NULL)
{
	_perspective = TRUE; 
// set default camera offset 
// Fix windows stuff
	_desktop = ::GetDC(NULL);
	::SetRect(&_black, 0, ::GetSystemMetrics(SM_CYSCREEN)-3, 
		::GetSystemMetrics(SM_CXSCREEN), 
		::GetSystemMetrics(SM_CYSCREEN));
	::SetRect(&_leftField, 0, ::GetSystemMetrics(SM_CYSCREEN)-3,
		::GetSystemMetrics(SM_CXSCREEN) * 0.75f,
		::GetSystemMetrics(SM_CYSCREEN));
	::SetRect(&_rightField, 0, ::GetSystemMetrics(SM_CYSCREEN)-3, 
		::GetSystemMetrics(SM_CXSCREEN) * 0.25f, 
		::GetSystemMetrics(SM_CYSCREEN));
//Make dialog
	_pdlgstereo = new cStereoDialog(pownerview());
	_pdlgstereo->attachStereoViewer(this);
}

cCritterViewerStereo::~cCritterViewerStereo()
{
	::ReleaseDC(NULL, _desktop);
	if (_pdlgstereo)
		delete _pdlgstereo;
	_pdlgstereo = NULL;
}

/*
 * update(CPopView *activeview, Real dt)
 * Purpose: This function is called at every "time step" originating from 
 *          CPopApp::OnIdle and cascading to CPopView::OnDraw. The base 
			class update adjusts _aspect, _fieldofviewangle, _znear, 
 *          _zfar may change due to the user performing zoom ins or outs.
 *          In our overload, blue lines are rendered on the global DC and the eye fields
 *          are toggled to implement time-division multiplexed double buffering.
 */
void cCritterViewerStereo::update(CPopView *activeview, Real dt)
{
//Do baseclass update.
	cCritterViewer::update(activeview, dt); 
 //Toggle the eye left/right
	renderBlueLines(); //Tells the shutterglasses to toggle
	toggleFields(); //Change the _eyeField
}

void cCritterViewerStereo::loadProjectionMatrix()
{
/* Loads the perpective projection matrix using glFrustum.  We
just use ortho for cGraphicsMFC. */
	if (pownerview()->pgraphicsclass()==(RUNTIME_CLASS(cGraphicsMFC)))
		cCritterViewer::loadProjectionMatrix();
	else 
	{
		pgraphics()->matrixMode(cGraphics::PROJECTION); //Prepare to change Projection matrix
		pgraphics()->loadIdentity(); //Initialize it with identity
/* In the base class, we call
		pgraphics()->perspective(fieldOfViewDegrees(), _aspect, _znear, _zfar);
		which is equivalent to
		::gluPerspective(fieldOfViewDegrees(), _aspect, _znear, _zfar)
		which is equivalent to
		frustum( left, right, bottom, top, znear, zfar);
*/
/* Use an asymmetric frustum so as to get the effect of the
eye looking right or left but without tilting the near
horizontal base line. */	
//Compute the projection parameters used by my frustum call
		Real half_dy = _znear * tan(_fieldofviewangle/2.0);
		Real right = _aspect * half_dy;
		Real left = -right;
		Real stereoCamOffset =
			STEREOINTENSITY_TO_STEREO_OFFSET_MULTIPLIER * _stereoIntensity;
	if (_eyeField == FIELD_RIGHT)
		stereoCamOffset *= -1;

		Real dragoffset =
			 VISUALDRAG_TO_STEREO_OFFSET_MULTIPLIER * _visualDrag;
		pgraphics()->frustum(
			left  - stereoCamOffset * dragoffset, 
			right - stereoCamOffset * dragoffset, 
			-half_dy, //bottom 
			 half_dy, //top 
			_znear, 
			_zfar);
/* Move the viewer left or right; the sign of
stereoCamOffset was set in cCritterViewerStereo::update. */
		pgraphics()->translate(cVector(- stereoCamOffset, 0.0, 0.0));
		pgraphics()->matrixMode(cGraphics::MODELVIEW);
		pgraphics()->loadIdentity();
	}
}

void cCritterViewerStereo::renderBlueLines() const
{
	::FillRect(_desktop, &_black, _blackbrush); // set black brush first

	(_eyeField == FIELD_LEFT) ?
		::FillRect(_desktop, &_leftField, _bluebrush) : 
		::FillRect(_desktop, &_rightField, _bluebrush);
}

void cCritterViewerStereo::setStereoIntensity(Real si, BOOL passtodlg)
{ 
	_stereoIntensity = si;
	if (!passtodlg)  //Default arg for this is TRUE
		return;
//Set the dialog box
	if (_pdlgstereo)
		_pdlgstereo->setStereoIntensity(_stereoIntensity);
}

void cCritterViewerStereo::setVisualDrag(Real vd, BOOL passtodlg)
{
	_visualDrag = vd;
	if (!passtodlg)
		return;
//Set the dialog box
	if (_pdlgstereo)
		_pdlgstereo->setVisualDrag(_visualDrag);
}

