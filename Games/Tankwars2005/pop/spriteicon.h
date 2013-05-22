#ifndef ICON_HPP
#define ICON_HPP

#include "sprite.h"

class cSpriteIcon : public cSprite
{
DECLARE_SERIAL(cSpriteIcon)
protected:
	BOOL _transparent; /*Usually _transparent is TRUE, but if we use a cSpriteIcon for, say,
		a backgroudn bitmap, we might want _transparent to be FALSE. */
	BOOL _tiled;
	Real _aspect; /* The ratio of the width to the height.  Gets set when you first
		set up the image to match the _resourceID in the cGraphics object. */
	Real _sizex, _sizey; //These are helpers kept in synch with _aspect and _radius.
	BOOL _imageloaded; /* The first time we draw the icon and actually load its image,
		we set the _aspect to match the image unless presetaspect is TRUE. */
	BOOL _presetaspect; /* If _presetaspect holds, then the first time we load the image,
		we crop the image so that its size matches the _aspect. */
	Real _visualradius; /* Maintain a _visualradius smaller than _radius
		which is the radius of the rectangle out to the corners.  A typical
		bitmap might not go out to the corners of the rect its in, but rather out
		to its sides.  Let's try the average of the distance to the sides. */
	int _xtilecount;
public:
	cSpriteIcon();
	cSpriteIcon(int resourceID, BOOL transparent = TRUE, BOOL presetaspect = FALSE);
	cSpriteIcon(cSpriteIcon *picon);
	cSpriteIcon(cSpriteIcon &picon);
	~cSpriteIcon(){} /* Either we have the owner critter tell all the views to
		tell their pgraphics to get rid	of the images matching _resourceID, or we
		will eventually let the pgraphics have a garbage collection routine to winnow
		out scaled icons that are no longer in use.  In any case, the pgraphics will
		free up all the resourceImage and scaledImage objects in its destructor. */
//Accessors
	Real aspect()const{return _aspect;}
	Real sizex(){return _sizex;}
	Real sizey(){return _sizey;}
	Real lox(){return -_sizex / 2.0;}
	Real loy(){return -_sizey / 2.0;}
	virtual Real radius() const; /* Overload to returns something based on
		_visualradius. */ 
	cVector locorner(){return cVector(-_sizex/2.0, -_sizey/2.0);}
	cVector hicorner(){return cVector(_sizex/2.0, _sizey/2.0);}
	BOOL tiled(){return _tiled;}
	int xtilecount(){return _xtilecount;}
	BOOL imageloaded(){return _imageloaded;}
	BOOL presetaspect(){return _presetaspect;}
	virtual BOOL enabledisplaylist()const{return FALSE;}
	/* enabledisplaylist specifies whetehr or not you want to
		try and use a display list to show this kind of sprite. By
		default this is TRUE.  We make it FALSE because the
		cSpriteIcon actually runs slower with displaylists, so we
		want to be able turn off display lists for them.  
		  Using display lists for the texture-implemeneted bitmaps 
		of cSpriteIcon garners me no noticeable speed.  The fact
		that the cTexture is already a texture object must meant 
		that you've already gotten as much as you can out of that.
		All that using a display list in here does is save the time
		of making a few GL mode setting calls.  If anything, this 
		runs maybe 20% slower with the display list, probably
		because the display list call overhead outweighs making
		 the GL mode sets in immediate mode. But test this on your
		own machine by making the TRUE if you like.  */
//Mutator
	void setAspect(Real aspect);
	void setImageloaded(BOOL imageloaded){_imageloaded = imageloaded;}
	void setSize(Real sizex, Real sizey);
	void setTiled(BOOL onoff){_tiled = onoff;}
//cSprite overloads
	virtual BOOL usesTexture(){return TRUE;}
	virtual BOOL usesTransparentMask()const{return _transparent;}
	virtual BOOL usesAlpha(){return _transparent;}
	virtual BOOL usesLighting(){return !_transparent;}  /*
		I need to have no lighting for transparent icons,
		as otherwise their background show up as gray. */
	virtual void setRadius(Real radius);
	virtual void copy(cSprite *psprite);
	virtual void Serialize(CArchive &ar);
//The imagedraw function
	virtual void imagedraw(cGraphics *pgraphics, int drawflags = 0);
};

class cSpriteIconBackground : public cSpriteIcon
{
DECLARE_SERIAL(cSpriteIconBackground)
public:
	cSpriteIconBackground(){}
	cSpriteIconBackground(int resourceID, const cRealBox2 &worldborder,
		int xtilecount = 1);
};


#endif //ICON_HPP