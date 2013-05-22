/*
11/22/01	Giavinh		Created. Added MD2 mesh model (animation) into the game.
4/14/2003  Rudy Rucker reworked so the textures are handled by cGraphics.
*/

#include "stdafx.h"
#include "spritequake.h"
#include "quakeMD2model.h"
#include "graphics.h"
#include "sprite3d.h"
#include "popview.h"

IMPLEMENT_SERIAL(cSpriteQuake, cSprite, 0);
IMPLEMENT_SERIAL(cSpriteQuakeAlien, cSpriteQuake, 0);
IMPLEMENT_SERIAL(cSpriteQuakeOgro, cSpriteQuake, 0);
IMPLEMENT_SERIAL(cSpriteQuakeRipper, cSpriteQuake, 0);
IMPLEMENT_SERIAL(cSpriteQuakeBigNose, cSpriteQuake, 0);

//========================== cSpriteQuake =====================================
cSpriteQuake::cSpriteQuake(const char *modelFileName, const char *skinFileName,
	cVector correctionpercents):
_modelfilename(modelFileName),
_skinfilename(skinFileName),
_dt(0.02),
_framerate(3.5),
_correctionpercents(correctionpercents)
{
	_pModel = new cMD2Model;/* allocate memory for model objects and load it. */
	BOOL success = _pModel->Load(_modelfilename, _skinfilename);
	if (!success)
	{
		delete _pModel;
		_pModel = NULL;
		CString message = 
"cSpriteQuake constructor unable to load one or both of:\n  Model file: " +
			CString(_modelfilename) + 
			"\n  Skin file: " + CString(_skinfilename) + 
			"\nWill draw sprite as a circle.";
		MessageBeep(MB_ICONEXCLAMATION);
		::AfxMessageBox(message);
		return;
	}
	_lastModelState = _modelState = MODEL_RUN;// set model state to RUN, Giavinh had IDLE.
		/* Normally our sprites of this type will be figurines that "stand" on the
			critter's central point. */
	setRadius(_radius); /* Match the appearance to the _radius parameter, that is, 
		 Make _spriteattitude.scalefactor() * _pModel->boundingbox.radius() = _radius. 
		The _correctionpercents are used here as well. */
	fixResourceID();
}

cSpriteQuake::~cSpriteQuake()
{
	if (_pModel) 
	{
		delete _pModel; //~CMD2Model calls CMD2Model::Unload method
		_pModel = NULL;
	}
}

void cSpriteQuake::fixResourceID()
{
	_resourceID = 16000 + _pModel->skinfileKey();
	/* I'm faking a resourceID number so that cBiota::Add can check if
	a critter's sprite uses the same texture as an existing sprite, so that
	we can render similarly textured critters one after the other.  Now
	in practice my bitmap resource IDs are in the 200s, and the skinfileKey
	values range through 0, 1, 2, and so on, using only small numbers.  So
	I can easily tell them apart I add 16,000 to the skinfilekey. */
};

void cSpriteQuake::Serialize(CArchive &ar)
{
	cSprite::Serialize(ar);
	CString filename, modelname;
	if (ar.IsStoring()) //Writing data.
		ar << _modelfilename << _skinfilename << _dt << _framerate 
			<< _correctionpercents  << _modelState << _lastModelState;
	else //Reading data.
	{
		ar >> _modelfilename >> _skinfilename >> _dt >> _framerate 
			>> _correctionpercents;;// >> _modelState >> _lastModelState;
 		delete _pModel;
 			//delete the default _pModel and make a new one.
	}
	_pModel = new cMD2Model;/* allocate memory for model objects and load it. */
	BOOL success = _pModel->Load(_modelfilename, _skinfilename);
	if (!success)
	{
		delete _pModel;
		_pModel = NULL;
		CString message = 
"cSpriteQuake constructor unable to load one or both of:\n  Model file: " +
			CString(_modelfilename) + 
			"\n  Skin file: " + CString(_skinfilename) + 
			"\nWill draw sprite as a circle.";
		MessageBeep(MB_ICONEXCLAMATION);
		::AfxMessageBox(message);
		return;
	}
}

void cSpriteQuake::setRadius(Real newradius)
{
	if (!_pModel)
	{
		cSprite::setRadius(newradius);
		return;
	}
/*   Match the appearance to the _radius parameter, that is, 
		make _spriteattitude.scalefactor() * _pModel->boundingbox.radius() = _radius. */
	cRealBox box = _pModel->boundingbox(0); //Could get frame 40 size, but its about the same.
	Real boxradius = box.radius();
	Real scalefactor;

	_radius = newradius;
		/* The visual size of the sprite is about 0.85*scalefactor*box.averageradius.  
		The 0.85 is an eyeball impression I have that the "sphere" around a running
		figure isn't really the extent of the figure, it's tighter in. Match to _radius. */
	if (box.averageradius() > SMALL_REAL)
		scalefactor = _radius / (0.85*box.averageradius());
	else
		scalefactor = 1.0; //punt if there's no box radius.
		/* A matrix of the form S * T, the T acts first and then the S.  So we slide
			the figurine up to put its base at critter origin if _zElevation wants this,
			and then we scale it, which will leave base at origin. */
	_spriteattitude = cMatrix::scale(scalefactor)*
		 cMatrix::translation(cVector(_correctionpercents.x()*box.xsize(), 
			_correctionpercents.y()*box.ysize(),_correctionpercents.z()*box.zsize())); 
	setNewgeometryflag(TRUE); //This doesn't matter here, but stay consistent with cSprite
}

void cSpriteQuake::setCorrectionPercents(cVector cp) 
{
	/* It may be that you don't want a figurine that stands on the critter origin. Maybe 
		you want a jellyfish centered around the critter origin. */
	
	_correctionpercents = cp;
	Real scalefactor = _spriteattitude.scalefactor();
	cRealBox box = _pModel->boundingbox(0); //Could get frame 40 size, but its about the same.
	_spriteattitude = cMatrix::scale(scalefactor)*
		 cMatrix::translation(cVector(_correctionpercents.x()*box.xsize(), 
			_correctionpercents.y()*box.ysize(),_correctionpercents.z()*box.zsize())) ; 
//	_spriteattitude =  cMatrix::translation(cVector(0.0, 0.0, _zElevation)) * 
//		cMatrix::scale(scalefactor); 
}

void cSpriteQuake::imagedraw(cGraphics *pgraphics, int drawflags)
{
	if (!pgraphics->is3D() || !_pModel)
	{
		cSprite::imagedraw(pgraphics, drawflags); //Use the baseclass draw (a circle)
		return;
	}
	// set interpolation between keyframes
	float percent;
	//percent = 0.2; 
	if (_dt > SMALL_REAL)
	//	percent = 0.001 * _framerate / _dt; 
		percent = _framerate * _dt; 
			/* Want to get a number around 0.1
			to 0.3 range.  I stick in the 0.001 multiplier so that "_framerate"
			can be a reasonable kind of number like 2 or 3 */
	else
		percent = 0.2;
	/*
		   Frame#  Action
		   ----------------
		   0-39    idle
		   40-46   running
		   47-60   getting shot but not falling (back bending)
		   61-66   getting shot in shoulder
		   67-73   jumping
		   74-95   idle
		   96-112  getting shot and falling down
		   113-122 idle
		   123-135 idle
		   136-154 crouch
		   155-161 crouch crawl
		   162-169 crouch adjust weapon (idle)
		   170-177 kneeling dying
		   178-185 falling back dying
		   186-190 falling forward dying
		   191-198 falling back slow dying
			*/

		// set current model animation state
	_pModel->SetState(_modelState);
	if (_modelState != _lastModelState)
	{
		_lastModelState = _modelState;
		_pModel->setAnimatePercent(0.0);
	}
	// perform animation based on model state
	switch (_pModel->GetState())
	{
		case MODEL_IDLE:
			_pModel->Animate(pgraphics, 0, 39, percent);
			break;
		case MODEL_RUN:
			_pModel->Animate(pgraphics, 40, 46, percent);
			break;
		case MODEL_CROUCH:
			_pModel->Animate(pgraphics, 136, 154, percent);
			break;
		case MODEL_SHOT:
			_pModel->Animate(pgraphics, 47, 60, percent);
			break;
		case MODEL_JUMP:
			_pModel->Animate(pgraphics, 67, 73, percent);
			break;
		case MODEL_DIE:
			if (_pModel->animatePercent() < 1.0)
				_pModel->Animate(pgraphics, 178, 185, percent);
			else
				_pModel->RenderFrame(pgraphics, 183);
			break;
		default:
			break;
	}
}

