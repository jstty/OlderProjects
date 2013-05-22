

#ifndef BOX_HPP
#define BOX_HPP

#include "vectortransformation.h" //For cVector2 and cVector3
class cGraphics; //So we can use a cGraphics* pointer in the draw method declarations.

class cRealBox2;
class cRealBox3;
#ifndef THREEDVECTORS
	typedef class cRealBox2 cRealBox;
#else //THREEDVECTORS
	typedef class cRealBox3 cRealBox;
#endif //THREEDVECTORS

//===========
/* Outcodes for cRealBox2::outcode and for cCritterWall::outcode().  These can't be const
static int values because then (a) I'd have to define them for each dimension of cRealBoxN, 
also I'm not sure I could the use them in switch statements. */
#define BOX_INVALIDCODE -1
#define BOX_INSIDE 0
#define BOX_LOX 1
#define BOX_HIX 2
#define BOX_LOY 4
#define BOX_HIY 8
#define BOX_LOZ 16
#define BOX_HIZ 32
#define BOX_HIY_LOX (BOX_HIY|BOX_LOX)
#define BOX_HIY_HIX (BOX_HIY|BOX_HIX)
#define BOX_LOY_LOX (BOX_LOY|BOX_LOX)
#define BOX_LOY_HIX (BOX_LOY|BOX_HIX)
#define BOX_ALL (BOX_LOY_HIX|BOX_HIY_LOX)
#define BOX_X (BOX_LOX | BOX_HIX)
#define BOX_Y (BOX_LOY | BOX_HIY)
#define BOX_Z (BOX_LOZ | BOX_HIZ)
#define BOX_INVALIDOUTCODE -1

enum BOXSIDE{ LOX, HIX, LOY, HIY, LOZ, HIZ};
	/* An enum is similar to a static.  I use these for accessing
	a side of a box.*/

//==============
class cRealBox2 : public CObject
{
DECLARE_SERIAL(cRealBox2);
public:
static Real MINSIZE; /*It messes up our outcode computations for surface points 
	if we can have boxes with any degenerate 0 size, so we enforce a minimum
	of about a thousandth. */
protected:
	Real _lox, _hix, _loy, _hiy;
    void _arrange(); //helper function
	void _initialize(Real px, Real py, Real qx, Real qy); /* Make this private and use a more
		dimension-independnt form as the public method*/
	void _copy(const cRealBox2 &box);
	void _copy(const cRealBox3 &box);
	void _copy(cRealBox2 *pbox);
	void _copy(cRealBox3 *pbox);
public:
	//constructors
	 /* Makes a box of these dimensions centered on the origin. We give the default box a
		typical 4:3 screen aspect , as is seen in 800x600 pixel resolution. 
		Often this won't fill a typical window nicely, what with all the
		menu, tool, and status bars, so we change it at	the program start.*/
	cRealBox2(Real lox, Real loy, Real hix, Real hiy);	
	cRealBox2(Real xsize = 4.0, Real ysize = 3.0, Real dummyzsize = 0.0); 
	cRealBox2(const cVector2 &leftlocorner, const cVector2 &righthicorner);
	cRealBox2(const cVector2 &center, Real xsize, Real ysize, 
		Real dummyzsize = 0.0); 
	cRealBox2(const cVector2 &center, Real edge); //square
		cRealBox2(const cRealBox2 &box){_copy(box);}
	cRealBox2(const cRealBox3 &box){_copy(box);}
	cRealBox2(const cRealBox2 *pbox){_copy(pbox);}
	cRealBox2(const cRealBox3 *pbox){_copy(pbox);}
	cRealBox2* clone(){return new cRealBox2(this);}
	cRealBox2& operator=(const cRealBox2 &box){_copy(box); return *this;}
	void set(const cVector2 &locorner, const cVector2 &hicorner);
	void set(const cVector2 &center, Real xsize, Real ysize, Real zsize=0.0);
	void set(Real xsize, Real ysize, Real zsize=0.0); /* Have the dummy zsize arg in these constructors
		for consistency with the cRealBox3 interface. */
	virtual ~cRealBox2(){}
	//mutators
	void moveTo(const cVector2 &newcenter){set(newcenter, xsize(), ysize());}
	void matchAspect(int cx, int cy);
	void setYRange(Real loy, Real hiy){_loy = loy; _hiy = hiy; _arrange();} 
	void setZRange(Real loz, Real hiz){}; //does nothing, just here to match cRealBox3
	//accessors
	Real lox()const {return _lox;}
	Real hix()const {return _hix;}
	Real loy()const {return _loy;}
	Real hiy()const {return _hiy;}
	Real loz()const {return 0.0;}
	Real hiz()const {return 0.0;}
	Real midx()const {return (_hix + _lox) / 2.0;}
	Real midy()const {return (_hiy + _loy) / 2.0;}
	Real midz()const{return 0.0;}
	cVector2 center()const{return cVector2((_lox + _hix) / 2.0, (_loy + _hiy) / 2.0);}
	cVector2 locorner()const{return cVector2(_lox, _loy);}
	cVector2 hicorner()const{return cVector2(_hix, _hiy);}
	cVector2 corner(int i)const; //Method for listing corners 0 to 3 when you need to check all.
	Real xsize()const {return _hix - _lox;}
	Real ysize()const {return _hiy - _loy;}
	Real zsize()const{return 0.0;}
	Real minsize()const {return __min(xsize(), ysize());}
	Real maxsize()const {return __max(xsize(), ysize());} /* __min or __max with
		two underscores is a C macro */ 
	Real xradius()const {return (_hix - _lox)/2.0;}
	Real yradius()const {return (_hiy - _loy)/2.0;}
	Real zradius()const{return 0.0;}
	Real radius()const {return sqrt(xradius()*xradius() + yradius()*yradius());}
	Real averageradius()const {return (xradius() + yradius())/2.0;}
	cRealBox2 innerBox(Real radius)const; /* Return a box offset inward by radius
		distance from each wall.  We clamp radius be less than half the size() */
	cRealBox2 outerBox(Real radius)const; /* Return a box offset outward by radius */
	//methods
	cVector2 randomVector()const;
	BOOL inside(const cVector2 &testpos)const;
	int outcode(const cVector2 &testpos)const; //Outcodes are defined in realbox.h
	Real distanceTo(const cVector2 &testpos)const;
	Real distanceToOutcode(const cVector2 &testpos, int &posoutcode)const;
	Real maxDistanceToCorner(const cVector2 &testpos)const;
	int addBounce(cVector2 &position, cVector2 &velocity, Real bounciness)const;
     /*add velocity to position, but if you pass the border, then
     	reflect velocity and get a reflected position. */
	int addBounce(cVector2 &position, cVector2 &velocity, Real bounciness, Real dt)const;
		/* add dt*velocity to position, and do the bounce to velocity the same. */
	int wrap(cVector2 &position)const; /* If you move off one edge,
		then come back in the same amount from the other side */
	int wrap(cVector2 &position, cVector2 &wrapposition1, cVector2 &wrapposition2,
		cVector2 &wrapposition3, Real radius) const; /* If you are within
		radius of an edge, put the possible wrap values in wrappositions. */
	int clamp(cVector2 &position)const; /*Make sure position is inside*/
	int clamp(cVector2 &position, cVector2 &velocity)const; /*Make sure position is inside
		and kill any velocity in a wall-hitting direction. */
//	CRect realToPixel(const cRealPixelConverter &crealpixelconverter)const;
	virtual	void draw(cGraphics *pgraphics, int drawflags);
	friend cRealBox2 operator*(Real scale, const cRealBox2 &box); /* Return
		a box scale times as big as box. */
	friend BOOL operator==(const cRealBox2 arect, const cRealBox2 brect);
	friend BOOL  operator!=(const cRealBox2 arect, const cRealBox2 brect);
//Serialize methods
	virtual void Serialize(CArchive &ar); 
	friend CArchive& operator<<(CArchive& ar, cRealBox2 &realbox);
	friend CArchive& operator>>(CArchive& ar, cRealBox2 &realbox);
};

//3D=================================================================

class cRealBox3 : public CObject
{
DECLARE_SERIAL(cRealBox3);
public:
static Real MINSIZE; /*It messes up our outcode computations for surface points 
	if we can have boxes with any degenerate 0 size, so we enforce a minimum
	of about a thousandth. */
protected:
	Real _lox, _hix, _loy, _hiy, _loz, _hiz;
    void _arrange(); //helper function
	void _initialize(Real px, Real py, Real pz, Real qx, Real qy, Real qz); /* Make this private and use 
		a more dimension-independnt form as the public method*/
	void _copy(const cRealBox2 &box);
	void _copy(const cRealBox3 &box);
	void _copy(cRealBox2 *box);
	void _copy(cRealBox3 *box);
public:
	static BOOL isFaceOutcode(int outcode){
		return outcode == BOX_LOX ||outcode == BOX_HIX ||
		outcode == BOX_LOY ||outcode == BOX_HIY ||outcode == BOX_LOZ ||
		outcode == BOX_HIZ;}
	//constructors
	cRealBox3(Real xsize = 4.0, Real ysize = 3.0, Real zsize = 0.0); 
	cRealBox3(const cVector3 &locorner, const cVector3 &hicorner);
	cRealBox3(const cVector3 &center, Real xsize, Real ysize, 
		Real zsize = 0.0); 
	cRealBox3(const cVector3 &center, Real edge); //cube
	cRealBox3(const cRealBox2 &box){_copy(box);}
	cRealBox3(const cRealBox3 &box){_copy(box);}
	cRealBox3(cRealBox3 *pbox){_copy(pbox);}
	cRealBox3& operator=(const cRealBox3 &box){_copy(box); return *this;}
	cRealBox3* clone(){return new cRealBox3(this);}
	void set(const cVector3 &locorner, const cVector3 &hicorner);
	void set(const cVector3 &center, Real xsize, Real ysize, Real zsize=0.0);
	void set(Real xsize, Real ysize, Real zsize=0.0); /* Have the dummy zsize arg in these constructors
		for consistency with the cRealBox3 interface. */
	virtual ~cRealBox3(){}
	//accessors
	Real lox()const {return _lox;}
	Real hix()const {return _hix;}
	Real loy()const {return _loy;}
	Real hiy()const {return _hiy;}
	Real loz()const {return _loz;}
	Real hiz()const {return _hiz;}
	cVector3 locorner()const{return cVector3(_lox, _loy, _loz);}
	cVector3 hicorner()const{return cVector3(_hix, _hiy, _hiz);}
	Real midx()const {return (_hix + _lox) / 2.0;}
	Real midy()const {return (_hiy + _loy) / 2.0;}
	Real midz()const {return (_hiz + _loz) / 2.0;}
	cVector3 center()const{return cVector3(midx(), midy(), midz());}
	cVector3 corner(int i)const; //Method for listing corners 0 to 7 when you need to check all.
	Real xsize()const {return _hix - _lox;}
	Real ysize()const {return _hiy - _loy;}
	Real zsize()const {return _hiz - _loz;}
	Real minsize()const; //Return smallest non-zero dimension.
	Real maxsize()const {return __max(__max(xsize(), ysize()), zsize());} /* __min or __max with
		two underscores is a C macro */ 
	Real xradius()const {return (_hix - _lox)/2.0;}
	Real yradius()const {return (_hiy - _loy)/2.0;}
	Real zradius()const {return (_hiz - _loz)/2.0;}
	Real radius()const {return sqrt(xradius()*xradius() + yradius()*yradius()+ zradius()*zradius());}
	Real averageradius()const {return (xradius() + yradius() + zradius())/3.0;}
	cRealBox3 innerBox(Real radius)const; /* Return a box offset inward by radius
		distance from each wall, though we don't offset more than will fit. */
	cRealBox3 outerBox(Real radius)const; /* Return a box offset outward by radius. */
	cRealBox2 side(int iside); /* iside should be 0 through 5, that is, 
		an int(e) where e is one of the BOXSIDE enums */
	//mutators
	void matchAspect(int cx, int cy);
	void setYRange(Real loy, Real hiy){ _loy = loy; _hiy = hiy; _arrange();}; 
	void setZRange(Real loz, Real hiz){_loz = loz; _hiz = hiz; _arrange();} 
		/* Convenient for making a 2D box thick. */
	//methods
	cVector3 randomVector()const;
	BOOL inside(const cVector3 &testpos)const;
	int outcode(const cVector3 &testpos)const; //Outcodes are defined in realbox.h
	Real distanceTo(const cVector3 &testpos)const;
	Real distanceToOutcode(const cVector3 &testpos, int &posoutcode)const;
	Real maxDistanceToCorner(const cVector3 &testpos)const;
	cVector3 closestSurfacePoint(cVector oldpos, 
		int oldoutcode, cVector newpos,	int newoutcode,
		BOOL crossedwall )const;
	cVector3 escapeVector(const cVector3 &testpos,
		int posoutcode = BOX_INVALIDOUTCODE)const;
		 /* points away from box, or to closest face if you're inside. Computes
		the posoutcode if you dont' feed a good one.  */
	void reflect(cVector3 &velocity, int posoutcode)const; /* You must feed in a 
		correct posoutcode for reflect to work. */ 
	int addBounce(cVector3 &position, cVector3 &velocity, Real bounciness)const;
     /*add velocity to position, but if you pass the border, then
     	reflect velocity and get a reflected position. */
	int addBounce(cVector3 &position, cVector3 &velocity, Real bounciness, Real dt)const;
		/* add dt*velocity to position, and do the bounce to velocity the same. */
	int wrap(cVector3 &position)const; /* If you move off one edge,
		then come back in the same amount from the other side */
	int wrap(cVector3 &position, cVector3 &wrapposition1, cVector3 &wrapposition2,
		cVector3 &wrapposition3, Real radius) const; /* If you are within
		radius of an edge, put the possible wrap values in wrappositions. */
	int clamp(cVector3 &position)const; /*Make sure position is inside*/
	int clamp(cVector3 &position, cVector3 &velocity)const; /*Make sure position is inside
		and kill any velocity in a wall-hitting direction. */
//	CRect realToPixel(const cRealPixelConverter &crealpixelconverter);
	virtual	void draw(cGraphics *pgraphics, int drawflags);
	friend cRealBox3 operator*(Real scale, const cRealBox3 &box); /* Return
		a box scale times as big as box. */
	friend BOOL operator==(const cRealBox3 arect, const cRealBox3 brect);
	friend BOOL operator!=(const cRealBox3 arect, const cRealBox3 brect);
//Serialize methods
	virtual void Serialize(CArchive &ar); 
	friend CArchive& operator<<(CArchive& ar, cRealBox3 &realbox);
	friend CArchive& operator>>(CArchive& ar, cRealBox3 &realbox);
};

#endif //BOX_HPP
