// Sprite.h: interface for the cSprite class.
//
//////////////////////////////////////////////////////////////////////

#ifndef SPRITE_H
#define SPRITE_H

#include "realbox.h" //For Real, cRealPixelConverter, cVector, cGraphics, etc.
#include "colorstyle.h"

class cGraphics; //For argument to draw
class cCritter; //For argument to animate

class cSprite : public CObject  
{
 DECLARE_SERIAL(cSprite); 

public:
//Randomization and mutation flags.  MF stands for mutation flag.
	//The MF_ flags are defined in static.cpp.
	static const int MF_RADIUS;
	static const int MF_ROTATION;
	static const int MF_ALL; //MF_RADIUS | MF_ROTATION.
//Angular velocity bounds used in mutate(...MF_ROTATION...)
	static Real MINANGVELOCITY;
	static Real MAXANGVELOCITY;
//For drawing highlight circles in draw(...DF_FOCUS...)
	static Real HIGHLIGHTRATIO; 
	static const unsigned long INVALIDID; // Use 0 for this, see SPRITEID
//Prism statics
	static Real CRITTERPRISMDZ; /* The default Z depth to use for a cCritter sprite if we are
		in 3D and have a sprite that uses its _prismdz field. */
	static Real BULLETPRISMDZ; //Default z-depth to use for drawing cCritterBullet.
	//static Real WALLPRISMDZ; //Define this one in critterwall.h instead.
	static Real PLAYERPRISMDZ;  //Default z-depth to use for drawing cCritterArmedPlayer.
	static Real MAXPRISMDZ; /* We may make some graphical thickness additions that
		 do to make a 2D game look 3D, such as thick sprites or putting
		foreground or background at a z offset.  Keep all of these 
		within +-MAXPRISMDZ on the z axis so we know to set znear and 
		zfar to include them.  This isn't so much of an issue for a true 3D game,
		it's only an issue for 2D games that we dress up with prism sprites. */ 
protected:
	static unsigned long SPRITEID; /* Use this to assign each cSprite its own ID when its
		constructed. If you make four billion sprites, you'll wrap the ID around and trigger
		a ASSERT. We'll let the valid values go from 1 to 0xFFFFFFFF */
	unsigned long _spriteID; /* Don't serialize or copy this one, it's unique for each sprite,
		and is set by the constructor. We need it for use in a lookup method for display list
		IDs in cGraphicsOpenGL class. */
	cColorStyle *_pcolorstyle; //To hold things like fillcolor, texture map, etc.
	int _resourceID; /* _resourceID holds the id of any bitmap textue this
		sprite may want to use.  */
	Real _radius; /* Relates to the internal geometry of the sprite.  Will not usually
		equal the value returned by cSprite::radius(), as this method
		multiplies in the _spriteattiude.scalefactor() */
	cMatrix _spriteattitude; /* We draw the sprite in the sprite attitude*critter attitude.
		This lets us position the sprite as we like relative to the critter's orientation.
		This is particularly useful in cSpriteComposite where I can group several sprites
		together. */
	Real _prismdz; /* _prismdz is a kludge variable that I put in so that flat sprites will
		pop out to look 3D when I switch to a 3D graphics like cGraphicsOpenGL.  The
		default is 0.0.  If nonzero _prsimz, it turns a	2D sprite like a cPolygon or a 
		cBubble into a 3D prism or cylinder. */
	BOOL _newgeometryflag; /* This is for use with sophisticated graphics like 
		cGraphicsOpenGL, where we speed up the drawing
		of some kinds of sprites by saving a display list index that encapsulates the steps
		used to draw the sprite.  If you change the intrinsic geometry of the sprite, for
		instance by changing the number of vertices in a polygon, then you need to 
		make a new display list for that sprite, and the _newgeometryflag is the flag
		we have a cSprite use so as to signal this to the cGraphicsOpenGL. 
		At construction, _newgeometryflag is TRUE. We don't serialize this field. */
public:
	cSprite();
	cSprite(cSprite &sprite);/* The copy constructor for cCritter and cSprite
		can't have a const argument because we use the copy function
		that takes a pointer to the argument object.  The copy function MUST 
		have a pointer argument so it can be polymorphic. */
	cSprite(cSprite *psprite);
	virtual ~cSprite();
	virtual void copy(cSprite *psprite);
	cSprite operator=(cSprite &csprite); //uses the virtual copy.
	cSprite* clone(); /* Returns a pointer to a cSprite of the same child class
		type, with the same info in it. */
//Serialize method
	virtual void Serialize(CArchive &ar);
//Attitude mutators
	virtual void setSpriteAttitude(const cMatrix &m){_spriteattitude = m;}
	virtual void setCenter(const cVector &newcenter)
		{_spriteattitude.setLastColumn(newcenter);}
	virtual void setRadius(Real radius); /* The default cSprite method for setRadius 
		does the miniumum, to reset _radius.   cPolygon and cIcon override setRadius, by
		changing the intrinsic geometry of the polygon or the bitmap rectangle. 
		cSpriteComposite overrides to leave _radius alone and instead to scale the
		_spriteattitude method, though this	is in turn overridden for cSpriteShowOneChild.*/
	virtual void rotate(Real angle){_spriteattitude*=cMatrix::zRotation(angle);}
	virtual void rotate(const cSpin &spin){_spriteattitude*=cMatrix::rotation(spin);}
//3D Mutators
	virtual void setPrismDz(Real prismdz){_prismdz = prismdz;}
	virtual void setNewgeometryflag(BOOL onoff){_newgeometryflag = onoff;}
//Randomizing mutators
	virtual void mutate(int mutationflags, Real mutationstrength);
	virtual void randomizeColor(){}
	virtual void randomize(int mutationflags){mutate(mutationflags, 1.0);}
//cColorstyle Mutators
	virtual void setColorStyle(cColorStyle *pcolorstyle);
	virtual void setFilled(BOOL yesno){_pcolorstyle->setFilled(yesno);
		setNewgeometryflag(TRUE);}
	virtual void setEdged(BOOL yesno){_pcolorstyle->setEdged(yesno);
		setNewgeometryflag(TRUE);}
	virtual void setFillColor(COLORREF col){_pcolorstyle->setFillColor(col);
		setNewgeometryflag(TRUE);}
	virtual void setLineColor(COLORREF col){_pcolorstyle->setLineColor(col);
		setNewgeometryflag(TRUE);}
	virtual void setLineWidthWeight(Real linewidthweight)
		{_pcolorstyle->setLineWidthWeight(linewidthweight);
		setNewgeometryflag(TRUE);}
	virtual void setLineWidth(Real linewidth)
		{_pcolorstyle->setLineWidth(linewidth); setNewgeometryflag(TRUE);}
//Texture mutator
	void setResourceID(int resourceid){_resourceID = resourceid;} /* We'll count
		on the cGraphics to free the old resource bitmap memory and allocate the
		new resrouce bitmap memory as part of this sprite's next call to draw. */
	virtual void fixResourceID(){}; /* This virtual helper method is needed
		because I plan to use _resourceID in cBiota::Add to see if
		two sprites use the same textures.  A cSpriteComposite
		will adopt as its _resourceID the first non-trivial resourceID of
		a member, and a cSpriteQuake will set a _resoruceID keyed to
		its skin file. */
//accessors
	unsigned long spriteID()const{return _spriteID;}
	virtual Real radius() const; /* Default is _radius * _spriteattitude.scalefactor() */
	virtual Real angle() const{return 0.0;}
	virtual cVector center()const{return _spriteattitude.lastColumn();}
	virtual Real prismDz()const{return _prismdz;}
	cColorStyle* pcolorstyle(){return _pcolorstyle;} /* Don't call this accessor const,
		as we usually use it to then do something to _pcolorstyle. */
	BOOL newgeometryflag()const{return _newgeometryflag;} 
	cMatrix spriteattitude()const{return _spriteattitude;}
	virtual BOOL enabledisplaylist()const{return TRUE;}
	/* enabledisplaylist specifies whetehr or not you want to
		try and use a display list to show this sprites. By default 
		this is TRUE.  We make this virtual so I can turn it off
		for cSpriteIcon, which seems to runs slower with display 
		lists. */ 
	int resourceID(){return _resourceID;} 
//Attribute accessors
	/* The purpose of the attribute accessors is to turn on and off
	attributes of the cGraphics in one cGraphics::adjustAttributes call.
	It's especially necessary to turn the texture attribute on and off
	according to whether its used, as you can't fill polygons and draw
	textures without changing. In some cases turning off an attribute you
	don't need might help the speed. */
	virtual BOOL usesSmoothing(){return TRUE;}
	virtual BOOL usesTexture(){return FALSE;} //Necessary
	virtual BOOL usesTransparentMask()const{return FALSE;}
	virtual BOOL usesAlpha(){return FALSE;} //Trying for speed to cut down on alpha.
	virtual BOOL usesLighting(){return TRUE;} /* Use this since transparent
		icons don't look good with lighting. */
//cColorstyle accessors
	virtual BOOL filled() const {return _pcolorstyle->filled();}
	virtual BOOL edged() const {return _pcolorstyle->edged();}
	virtual COLORREF fillColor() const {return _pcolorstyle->fillColor();}
	virtual COLORREF lineColor() const {return _pcolorstyle->lineColor();}
	virtual Real lineWidthWeight() const {return _pcolorstyle->lineWidthWeight();}
	virtual Real lineWidth() const {return _pcolorstyle->lineWidth();}
//methods
	virtual void animate(Real dt, cCritter *powner){} /* Might choose sprite
		based on age, change the radius of the sprite with time, or choose a sprite based
		on direction or health of powner, or maybe spin. */
	virtual void draw(cGraphics *pgraphics, int drawflags = 0);
		/* This gets called by the owner cCritter::draw which does multMatrix
		(on the right) with the critter's own _attitude and calls psprite()->draw. 
		cSprite::draw does a multMatrix (on the right) with its own _spriteattitude
		and calls its special overloaded imagedraw method. It's effectively a
		Template Method. */
	virtual void imagedraw(cGraphics *pgraphics, int drawflags);
};

class cSpriteComposite : public cSprite  
{
DECLARE_SERIAL(cSpriteComposite); 
protected:
	CTypedPtrArray<CObArray, cSprite*> _childspriteptr;
public:
	cSpriteComposite():cSprite(){} //Default constructor of _childspriteptr will be a zero-size array.
	virtual ~cSpriteComposite();
	void Serialize(CArchive &ar);
//Mutators 
	/* By default the inherited cSprite mutators will only affect the base sprite.
	Depending on whether we plan to show all of the child sprites all the time, and
	on whether we might prefer to individually mutate them we might or might not
	want to cascade the mutators down to all the children.  For the following ones
	that we pretty definitely want to be uniform, we cascade them to mutate both
	the base and all the children. You might want to overload more of these later. */
	virtual void setLineColor(COLORREF col);
	virtual void setFillColor(COLORREF col);
	virtual void setEdged(BOOL onoff);
	virtual void setFilled(BOOL onoff);
	virtual void setLineWidthWeight(Real linewidthweight);
	virtual void setLineWidth(Real linewidth);
	virtual void setNewgeometryflag(BOOL onoff);
	virtual void setPrismDz(Real prismdz); /* setPrismDz needs to take the scaling of 
		the _spriteattitudematrix into account. */
	virtual void setRadius(Real radius); /* The default cSpriteComposite method for setRadius is
		to scale _spriteattitude matrix.  This gets used by cPolyPolygon and the
		various cSpriteBubble.  We override setRadius for the cSpriteShowOneChild 
		child of cSpriteComposite. */
//Accessor
	virtual Real radius() const; /* For now, we view a cSpriteComposite as having the
		 radius of its largest piece.  But often we will often overload this. */
	cSprite* member(int n){return _childspriteptr[n];}
//Methods
	virtual void fixResourceID(); /*  A cSpriteComposite
		will adopt as its _resourceID the first non-trivial resourceID of
		a member. */
	virtual void add(cSprite *psprite);
	virtual void add(int resourceid); /* Doesn't really need to be virtual as it
		calls the virtual add(new cSpriteIcon(resourceid)).*/
	virtual void changeMember(int index, cSprite *pspritenew); /* If there is 
		a sprite at index, delete it and put in psprite new.  Else do nothing. */
	virtual void copy(cSprite *psprite);
	virtual void draw(cGraphics *pgraphics, int drawflags = 0); /* Default is to cascade
		calls to the _childspriteptr members. */
	virtual void animate(Real dt, cCritter *powner); // Default is to cascade.
};

#endif // SPRITE_H
