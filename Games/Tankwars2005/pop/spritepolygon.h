#ifndef POLYGON2_HPP
#define POLYGON2_HPP

/*	
	1994.  The cPolygon class originally maintained a polygon as a "hand-made"
resizable array of cVector vertices.  It maintained an equally large hand-made
resizable array of CPoint pixel vertices as to support a 
realToPixel(CRealPixelConverter &) function which is called before using a
draw(CDC *) function to put the polygon on the screen.  The  CPoint _pointvert
array is used only in realToPixel and draw, we don't maintain its correctness
as we go along, only focussing on keeping the correct geometry of the polygon in
the cVector array.
	June 20, 1999.  The hand-made arrays were replaced with CArrays. The "dot"
feature was added to draw circles at the vertices.  Note that the dots as
implemented would not have the correct appearance for representing cPolygon3
projections. RR.
	August 4, 1999.  Changed it to a child of the cSprite class.
	June, 2001.  Gave it a general cVector which can be thought of as three-dimenisonal.

*/

#include "sprite.h"
#include "colorstyle.h"

//#define TRUESTAR
	/* If TRUESTAR is on, we draw true star polygons, but OpenGL can't draw
	them well, so we fake them. */

//--------------TWO DIMENSIONAL--------------

class cPolygon : public cSprite
{
DECLARE_SERIAL(cPolygon)
public:
//const statics 
	//The MF_ flags are defined in static.cpp.
	static const int MF_COLOR;
	static const int MF_FILLING;
	static const int MF_LINEWIDTH;
	static const int MF_DOTS;
	static const int MF_VERTCOUNT;
	static const int MF_ALL; //MF_COLOR | MF_FILLING | MF_LINDWIDTH | DOTS | VERTCOUNT;
protected:
//Special cPolygon variables
	//Main array field and helper array field
	CArray<cVector, cVector &> _vectorvert;
	CArray<cVector, cVector &> _transformedvert; /* We use this only in the transformedVert(Matrix)
		call.  We don't need to serialize it, as it is strictly a helper that gets updated before
		each use. */
	BOOL _convex;
//Special Polygon Data fields about dot.
	BOOL _dotted;
	cColorStyle *_pdotcolorstyle;
	Real _realdotradiusweight; //Ratio of vertex marker dot size to _polygonradius.
		/*	DON'T put in a Real _radius or Real _angle!  C++ will let you do
		this even though these fields exist in cSprite, but what a mistake.  If you
		put a second _radius in here, then the cPolygon methods change the
		cPolygon _radius, but the cSprite::radius() accessor returns the cSprite
		_radius, which will still be 0.0 */
//Private helper functions
	void _initializer(); //Used by the two constructors.
	void _fixConvex();
public:
//Constructor, destructor, operator=
	cPolygon(); //Default constructor calls initializer
	cPolygon(int vertcount); 
		//Makes a default regular polygon with n verts.
	cPolygon(int count, cVector *pverts, cColorStyle *pcolorstyle = NULL); /* Useful for wrapping 
		verts in a polygon class to pass to pgraphics->draw. */
	cPolygon(cPolygon &poly); //Uses copy
	cPolygon(cPolygon *ppoly); //Uses copy
	virtual	~cPolygon(); /* The destructor of a base class must be virtual
		if any of its child classes can have more fields that may need additional
		destruction. */
//Overloaded cSprite methods
	virtual BOOL usesSmoothing(){return FALSE;}
	virtual void copy(cSprite *psprite); /* Checks if csprite is a cPolygon,
		and, if so, copies all the fields.  */
	virtual Real angle();
	virtual void setRadius(Real radius);
	virtual void mutate(int mutationflags, Real mutationstrength);
	virtual void Serialize(CArchive &ar);
//Mutators
	void fixCenterAndRadius(); /* Helper function calculates the centroid as the
		average of the vertices, moves the centroid the origin, and sets the _radius as the
		max distance of a vertex from the origin. */
	void setSize(int maxcount);//Allocates arrays, preserves old info.
	void setVertex (int n, const cVector &v);
	void addVertex (const cVector &v);
	void changeVertexcount(int updown); //Add updown to vert count.
	void setLineWidthWeight(Real linewidthweight);
	void setDotColorStyle(cColorStyle *pdotcolorstyle);
	void setDotted(BOOL yesno);
	void setDotRadiusWeight(Real dotradiusweight);
		/*If you don't specify the center, radius, initangle arguments for
		RegularPolygon & StarPolygon, use default arguments */
	void setRegularPolygon(int vertexcount,
		cVector center = cVector(0.0, 0.0), Real radius = 1.0,
		Real initangle = 0.0);
#ifdef TRUESTAR
	void setStarPolygon(int vertexcount, int step,
		cVector center = cVector(0.0, 0.0), Real radius = 1.0,
		Real initangle = 0.0);
#else //not TRUESTAR
	void setStarPolygon(int vertexcount, Real dentpercent,
		cVector center = cVector(0.0, 0.0), Real radius = 1.0,
		Real initangle = 0.0);
#endif //TRUESTAR
	void setRandomStarPolygon(int mincount, int maxcount);
	void setRandomRegularPolygon(int mincount, int maxcount);
	void setRandomAsteroidPolygon(int mincount = 5,	int maxcount = 30, Real spikiness = 0.3);
//Accessors
	BOOL convex() const {return _convex;}
	int vertCount() const {return _vectorvert.GetSize();}  /*the const means the
		funtion doesn't change the class. I need this because some
		functions that	call (const cPolygon3 &p) use the cPolygon::getSize function.*/
	BOOL dotted() const {return _dotted;}
	cColorStyle *pdotcolorstyle(){return _pdotcolorstyle;}
	Real dotRadiusWeight() const {return _realdotradiusweight;}
	Real dotRadius() const {return _realdotradiusweight * _radius;}
	cVector& getVertex(int n);
//Matrix methods.
	CArray<cVector, cVector &>* transformedVert(const cMatrix &M); /* Fix our member array
		_transformedvert so it holds all the M*vert from the _vectorvert array, and then
		return a pointer to _transformedvert.  We can't return a copy of this array because
		MFC doesn't supply a CArray copy constructor. This method is needed by the
		cGraphicsMFC::draw(cPolygon) call. */
	friend cPolygon operator*(const cMatrix &M, cPolygon &p);
		/* Note that the cPolgon2 args can't be const because the copy
		constructor on a cPolygon can't be const, see Sprite.h for the reason. Even so, 
		we don't actually change anything in p.*/
//cSprite overloads
	virtual void imagedraw(cGraphics *pgraphics, int drawflags);
};

class cPolyPolygon : public cSpriteComposite
{
DECLARE_SERIAL(cPolyPolygon)
public:
	static Real MIN_TIP_RADIUS_RATIO;
	static Real MAX_TIP_RADIUS_RATIO;
	static Real MINTIPANGLEVELOCITY;
	static Real MAXTIPANGLEVELOCITY;
	static Real TIPPRISMDZMULTIPLIER; /* Make the tips have slightly larger prismdz. */
protected:
	Real _tipangvelocity;
public:
	cPolyPolygon():_tipangvelocity(0.0){} /* Start out with no basepoly and no tipshape, user must
		fix this with a call to mutate or to setBasePoly and setTipShape. */
	cPolyPolygon(int baseverts, int tipverts);
	virtual ~cPolyPolygon(){}
	void setBasePoly(cPolygon* pppoly);
	void setTipShape(cSprite* pshape); /* setTipShape puts a clone of pshape at each vertex of the
		pbasepoly(), and then it deletes pshape.  So don't use a pshape as argument that you need to save. */
//cSprite overloads
	virtual Real radius()const; /* Overload the standard cSpriteComposite radius() method. */
	virtual void mutate(int mutationflags, Real mutationstrength);
	virtual void animate(Real dt, cCritter *powner); 
	virtual void setPrismDz(Real prismdz); /* makes the tipshapes a bit thicker. */
//Special methods
	void setTipAngVelocity(Real newvel){_tipangvelocity = newvel;}
	cPolygon *pbasepoly() const; //These two aren't truly const, but we lie about it so radius can use them.
	cSprite *ptipshape() const; //They aren't truly const because we can use the poitner to change things.
};

class cSpriteRectangle : public cPolygon
{
DECLARE_SERIAL(cSpriteRectangle)
public:
	cSpriteRectangle(Real lox = -0.5, Real loy = -0.5, Real hix = 0.5,
		Real hiy = 0.5);
	virtual	~cSpriteRectangle(); /* The destructor of a base class must be virtual
		if any of its child classes can have more fields that may need additional
		destruction. */
};

#endif //POLYGON2_HPP
