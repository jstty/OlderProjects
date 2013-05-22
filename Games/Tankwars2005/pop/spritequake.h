/*
11/22/01	Giavinh	Pham Created. Added MD2 mesh model (animation) into the game.
The MD2 mesh type was orginally created for Quake 2.
4/14/2003  Rudy Rucker reworked so the textures are handled by cGraphics.
CAUTION: Use only with skins that are rectangles whose edges are powers of two,
like 64, 128, 256, etc.  This should be standard in any skins you'll download. 
*/

#ifndef SPRITEQUAKE_H
#define SPRITEQUAKE_H

#include "sprite.h"
#include "quakeMD2model.h"


#define TESTBIGNOSE
#ifdef TESTBIGNOSE
	/* Bignose is an MD2 wiht a PCX that is not
	powers of two in size, its 320x200.  It loads OK wthehter or not I have
	GLUSCALETEXTUREINFO turned on in texture.cpp. */
	#define DEFAULTMODEL "models\\bignose\\tris.MD2"
	#define DEFAULTSKIN "models\\bignose\\Bignose.pcx"
#else //not TESTBIGNOSE
	#define DEFAULTMODEL "models\\invader\\Tris.MD2"
	#define DEFAULTSKIN "models\\invader\\alien.bmp"
	//#define DEFAULTSKIN "models\\invader\\alien_unscaled.bmp"
		/* I was testing what happens if I rescale the correct alien.bmp
		to be a bad alien_unscaled.bmp 384x256 instead of the original
		256x256.  It doesn't work, even if I rescale the bitmap for the texture,
		and the reason is that the MD2 gives the texture coords in terms of
		pixel locations, in the bitmap and then the OpenGL texture coords
		are ratios between these pixel locations and the bitmap size, and
		if I in fact load the wrong size bitmap, the ratios are wrong. */
	//#define DEFAULTMODEL "models\\Ripper\\Tris.MD2"
	//#define DEFAULTSKIN "models\\Ripper\\ripper.pcx"
#endif //TESTBIGNOSE

class cSpriteQuake : public cSprite
{
DECLARE_SERIAL(cSpriteQuake)
protected:
	cMD2Model *_pModel;			// the character model
	modelState_t _modelState;	// model state
	modelState_t _lastModelState;// last model state
	CString _modelfilename;        // the filepath of the model
	CString _skinfilename;          // the filepath of the skin texture
	cVector _correctionpercents;      /* slide the image proportional to its bounding
										box radii along the x,y,z axes. */
	Real _dt;			//Save the frame dt from animate(dt) for use in render().
	Real _framerate;	/* Arbitrary number which is multiplied times _dt to set the rate of
						frames, default is 10, which seems to look good. */
	BOOL _loaded; /* Although we make a new _pModel in the constructor, we don't call
		the _pmodel->Load method  until we have an active OpenGL context, in the first call
		to imagedraw.  We use _loaded to track if this task has been done. */
public:
	cSpriteQuake(const char * modelFileName = DEFAULTMODEL,
		const char * skinFileName = DEFAULTSKIN,
		cVector correctionpercents = cVector(0.0, 0.0, 0.0)); /* Acts as no-arg consructor too.
			Note that you can may CString arguments instead of const char * arguments. 
			We translate the sprite by correctionpercents.x()*boundingbox()->xradius()
			etc.  Often we want to move it up in the z direction by half the height
			so it can walk on the "floor," that is on the xy plane, so we often
			put 0.5 in the third place, though it may be, say,  0.2 or 0.7 depending on
			the exact geometry. */
	~cSpriteQuake();
//Special methods
	virtual void setstate(modelState_t newState) {_modelState = newState;}
	virtual modelState_t state() {return _modelState;}
	virtual void setCorrectionPercents(cVector cp);
		 /* Scoot the icon up or down to make a walking figure
		seem to rest on the ground or make a jellyfish blob be centerd on the critter's pos.
		Mainly we tweak this to make the visual appearance match a sphere centered on 
		critter's position, can check by using View|Wireframe Polygons. */
//Overloads
	virtual void fixResourceID(); /* This virtual helper method is needed
		because I plan to use _resourceID in cBiota::Add to see if
		two sprites use the same textures.  A cSpriteQuake will set a
		_resoruceID keyed to its skin file. */
	virtual BOOL usesTexture(){return TRUE;}
	virtual BOOL enabledisplaylist()const{return FALSE;}
	/* enabledisplaylist specifies whetehr or not you want to
		try and use a display list to show this kind of sprite. By default this is TRUE.  We 
		make it FALSE because the cSpriteIcon actually runs slower with displaylists, so we
		want to be able turn of display lists for them.  */ 
	virtual void imagedraw(cGraphics *pgraphics, int drawflags);
	virtual void animate(Real dt, cCritter *powner){_dt = dt;} 
	virtual void setRadius(Real newradius); /* Set _radius to newradius, and then match
		the appearance to the _radius parameter, that is, make
		_spriteattitude.scalefactor() * _pModel->boundingbox.radius() = _radius. */
	virtual Real radius() const{return _radius;} /* Don't multiply in 
		_spriteattitude.scalefactor(), as we use the scale to make the in fact
		quite large mesh model match the _radius. */
	BOOL isLoaded(){return _pModel != NULL;}
	virtual void Serialize(CArchive &ar);
};


class cSpriteQuakeAlien : public cSpriteQuake
{
DECLARE_SERIAL(cSpriteQuakeAlien)
public:
	cSpriteQuakeAlien():
		cSpriteQuake("models\\Invader\\Tris.MD2",
		"models\\Invader\\alien.bmp",
		cVector(0.0, 0.0, 0.48)){}
};

class cSpriteQuakeOgro : public cSpriteQuake
{
DECLARE_SERIAL(cSpriteQuakeOgro)
public:
	cSpriteQuakeOgro():
		cSpriteQuake("models\\Ogro\\Tris.MD2",
		"models\\Ogro\\ogrobase.pcx",
		cVector(0.0, 0.0, 0.45)){}
};

class cSpriteQuakeRipper : public cSpriteQuake
{
DECLARE_SERIAL(cSpriteQuakeRipper)
public:
	cSpriteQuakeRipper():
		cSpriteQuake("models\\Ripper\\tris.MD2",
		"models\\Ripper\\ripper.bmp",
		cVector(0.0, 0.0, 0.85)){};
};

class cSpriteQuakeBigNose : public cSpriteQuake
{
DECLARE_SERIAL(cSpriteQuakeBigNose)
public:
	cSpriteQuakeBigNose():
		cSpriteQuake("models\\bignose\\tris.MD2",
		"models\\bignose\\Bignose.pcx",
		cVector(-0.15, 0.0, 0.08)){}
};

#endif//SPRITEQUAKE_H