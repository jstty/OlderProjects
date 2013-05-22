// CritterViewerStereo.h
// Developed as part of an MS writing project at SJSU
// Spring 2003
// Kenji Tan

#ifndef CRITTERVIEWERSTEREO_H
#define CRITTERVIEWERSTEREO_H

#include "critter.h"
#include "critterviewer.h"
#include "listener.h"

typedef enum EyeField //  Enumerated type for eye fields (L or R)
{
	FIELD_LEFT	= 0,
	FIELD_RIGHT = 1,
} EyeField;

class cStereoDialog;  //forward declaration of cStereoDialog class

class cCritterViewerStereo : public cCritterViewer
{
DECLARE_SERIAL(cCritterViewerStereo)
public:
	static Real DEFAULTSTEROINTENSITY;
	static Real DEFAULTVISUALDRAG;
	static Real STEREOINTENSITY_TO_STEREO_OFFSET_MULTIPLIER;
	static Real VISUALDRAG_TO_STEREO_OFFSET_MULTIPLIER; 
	static Real MINSI;
	static Real MAXSI;
	static Real MINVD;
	static Real MAXVD;
protected:
// Win32 data structures for implementing Blue Line Code stereo format
	static HDC _desktop;
	static HBRUSH _bluebrush;
	static HBRUSH _blackbrush;
	static RECT _rightField;
	static RECT _leftField;
	static RECT _black;
//Interface variables
	Real _stereoIntensity; //User changeable variable for strength of stereo effect
	Real _visualDrag;//User changeable variable for seeming distance of the 3D objects.
	EyeField _eyeField;
//dialog variable
	cStereoDialog* _pdlgstereo;
public:
//Constructors and Destructor
	cCritterViewerStereo() : cCritterViewer() {};
	cCritterViewerStereo(CPopView *pview); 
		// This is the constructor we really use.
	virtual ~cCritterViewerStereo();
//Accessors 
	Real getStereoIntensity() const { return _stereoIntensity; }
	Real getVisualDrag() const { return _visualDrag; }
//Mutators 
	void setStereoIntensity(Real si, BOOL passtodialog = TRUE);
	void setVisualDrag(Real vd, BOOL passtodialog = TRUE);
		/* Normally we want any change to be relfected int the Stereo Parameters dialog,
		but if the dialog itself is making the change we don't want to bounce a
		request back to the dialog. */
//Methods
// Special stereo mode functions
	void renderBlueLines() const;
	void toggleFields() { _eyeField = 
		(_eyeField==FIELD_LEFT) ? FIELD_RIGHT : FIELD_LEFT; };
//Overloads from cCritterViewer
	virtual void loadProjectionMatrix(); 
	virtual void update(CPopView *pactiveview, Real dt);
		//update has to toggle _eyefield.
	virtual void Serialize(CArchive &ar) { cCritterViewer::Serialize(ar); } 
};

#endif // CRITTERVIEWERSTEREO_H

