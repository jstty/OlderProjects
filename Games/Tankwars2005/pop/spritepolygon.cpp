#include "stdafx.h" //includes math.h
#include "spritepolygon.h"
#include "randomizer.h" 
#include "gl\gl.h"
#include "gl\glu.h"
#include "graphicsOpenGL.h"
#include "popview.h" //for DF_ flag


//#define TRACESPRITEATTITUDE
//----------------------TWO DIMENSIONAL---------------------
IMPLEMENT_SERIAL(cPolygon, cSprite,0)
IMPLEMENT_SERIAL(cSpriteRectangle, cPolygon,0)
IMPLEMENT_SERIAL(cPolyPolygon, cSpriteComposite, 0)

//===================cPolyPolygon Statics =====================
Real cPolyPolygon::MIN_TIP_RADIUS_RATIO = 0.2;
Real cPolyPolygon::MAX_TIP_RADIUS_RATIO = 0.5;
Real cPolyPolygon::MINTIPANGLEVELOCITY = 1.0;
Real cPolyPolygon::MAXTIPANGLEVELOCITY = 4.0;
Real cPolyPolygon::TIPPRISMDZMULTIPLIER = 1.3;

//------------Constructors, Destructor, and Copiers---------------
void cPolygon::_initializer() //used by the constructors
{
	//The two CArrays are set to size 0 by their default constructors
	//Nine decoration fields
	_dotted = FALSE;
  	_pdotcolorstyle = new cColorStyle();
	_pdotcolorstyle->setFillColor(cColorStyle::CN_YELLOW);
	_realdotradiusweight = 0.05;
	// helper fields
	_convex = TRUE;
}

// The default constructor makes an empty polygon with standard	decorations.
cPolygon::cPolygon()
{
	_initializer();
} 

cPolygon::cPolygon(int n, cVector *pverts, cColorStyle *pcolorstyle)
{
	_initializer();
	_vectorvert.SetSize(n);
	for(int i=0; i<n; i++)
		_vectorvert[i] = pverts[i];
	if (pcolorstyle)
		setColorStyle(new cColorStyle(pcolorstyle)); //Otherwise keep the default.
	fixCenterAndRadius();
}

cPolygon::cPolygon(int vertcount)
{
	_initializer();
	setRegularPolygon(vertcount, cVector(0.0, 0.0), 1.0, 0.0);
}

void cPolygon::copy(cSprite *psprite) //Use this in copy constructor and operator=
{
/* Because our class has some CArray fields, we can't use the default overloaded
copy constructor and operator=.  So as to avoid having to maintain similar code
for these two different methods, we write a helper copy function that both
the copy constructor and the operator= can use. */
	cSprite::copy(psprite); //does center(), _radius, _angle, _rotationspeed.
	if (!psprite->IsKindOf(RUNTIME_CLASS(cPolygon)))
		return; //You're done if psprite isn't a cPolygon*.
	cPolygon *ppolygon = (cPolygon *)(psprite); /* I know it is a cPolygon
		at this point, but I need to do a cast, so the compiler will let me
		call a bunch of cPolygon methods. */
	//Arrays
	setSize(ppolygon->vertCount());
	_vectorvert.Copy(ppolygon->_vectorvert);
	//Decoration fields
	setColorStyle(new cColorStyle(ppolygon->pcolorstyle()));
	setDotColorStyle(new cColorStyle(ppolygon->pdotcolorstyle()));
	_dotted = ppolygon->_dotted;
	_realdotradiusweight = ppolygon->_realdotradiusweight;
	//Helper fields
	_convex = ppolygon->_convex;
}

cPolygon::cPolygon(cPolygon &poly)  //Need a copy constructor
{
	copy(&poly);
}

cPolygon::cPolygon(cPolygon *ppoly)  //Need a copy constructor
{
	copy(ppoly);
}

cPolygon::~cPolygon()
{
	//The CArray delete will kill the two arrays for you.
	delete _pdotcolorstyle;
	_pdotcolorstyle = NULL;
}

//-----------------Geometric mutators-----------------
void cPolygon::_fixConvex()
{
	int lastindex = vertCount()-1;
	int thisindex = 0;
	int nextindex = 1;
	for (int i=0; i<vertCount(); i++)
	{
		Real test = ((_vectorvert[thisindex] - _vectorvert[lastindex]) *
			(_vectorvert[nextindex] - _vectorvert[lastindex])).z();
			/* Take the cross product and look at the z component.
			If it is positive, the cross product points up, so this is 
			counterclockwise rotation and you aren't convex. */
		if (test  < 0)
		{
			_convex = FALSE;
			break;
		}
		lastindex = thisindex;
		thisindex = nextindex;
		nextindex++;
		if (nextindex >= vertCount())
			nextindex = 0;
	}
}

void cPolygon::fixCenterAndRadius()
{
//Calculate the centroid
	/* We plan to divide by vertCount, so don't allow it to be zero. */
	if (!vertCount())
		return;
	cVector centroid; //Default constuctor starts at zeroVector.
	for (int i=0; i<vertCount(); i++)
		centroid += _vectorvert[i];
	centroid /= vertCount(); // We already made sure this divisor isn't zero.
//Move the centroid to the origin
	for (i=0; i<vertCount(); i++)
		_vectorvert[i] -= centroid;
//Fix Radius as furthest vertex from the origin.
	Real distance = 0.0; //Start with this and look for the biggest one.
	Real testdistance;
	for ( i=0; i<vertCount(); i++)
	{
		testdistance = _vectorvert[i].magnitude(); 
		if (testdistance > distance)
			distance = testdistance;
	}
	_radius = distance; //_radius is a raw number.
	_fixConvex();
}

void cPolygon::setRadius(Real newradius)
{
	fixCenterAndRadius(); /* In case you haven't done this yet, for instance if you've built
		the polygon with a bunch of setVertex or addVertex calls and you are now calling setRadius. */
	if (!newradius)
		return; //Don't allow zero radius.
	ASSERT(radius()); //else it's hopeless
	Real scalefactor = newradius/radius();
	for (int i=0; i<vertCount(); i++)
		_vectorvert[i] *= scalefactor; // Centroid is origin so we can scale around it.
	_radius = scalefactor * _radius; /* _radius measures the newly scaled geometry of the
		polygon around the origin.  Note  newradius = spriteattitude._scalefactor()*_radius
		rather than newradius = _radius, although quite often the scalefactor is in fact 1.0. */
	setNewgeometryflag(TRUE);
}

CArray<cVector, cVector &>* cPolygon::transformedVert(const cMatrix &M)
{
	_transformedvert.SetSize(vertCount());
	for (int i=0; i<vertCount(); i++)
		_transformedvert[i] = M * _vectorvert[i];
	return &_transformedvert;
}

//----------Geometric accessor-------------
cVector& cPolygon::getVertex(int n)
{
	return _vectorvert.ElementAt(n);
}

Real cPolygon::angle()
{
	if (!vertCount())
		return 0.0;
	return angleBetween(_vectorvert[0]-center(), cVector(1.0, 0.0, 0.0));
}
//----------------Mutators----------------------

void cPolygon::setDotColorStyle(cColorStyle *pdotcolorstyle)
{
	delete _pdotcolorstyle;
	_pdotcolorstyle = NULL;
	_pdotcolorstyle = pdotcolorstyle;
	_newgeometryflag = TRUE;
}

void cPolygon::setLineWidthWeight(Real linewidthweight)
{
	_pcolorstyle->setLineWidthWeight(linewidthweight);
	_newgeometryflag = TRUE;
}

void cPolygon::setDotted(BOOL yesno)
{
	_dotted = yesno;
	_newgeometryflag = TRUE;
}

void cPolygon::setDotRadiusWeight(Real dotradiusweight)
{
	_realdotradiusweight = dotradiusweight;
	_newgeometryflag = TRUE;
}

void cPolygon::setSize(int newcount)
{ 
	_vectorvert.SetSize(newcount);
	_newgeometryflag = TRUE;
}

void cPolygon::addVertex(const cVector &vect)
{
	setSize(vertCount() + 1);
	_vectorvert[vertCount()-1] = vect;
	_newgeometryflag = TRUE;
}

void cPolygon::setVertex(int n, const cVector &vect)
{
	if (vertCount() < n+1)
		setSize(n+1);
	_vectorvert[n] = vect;
	_newgeometryflag = TRUE;
}

void cPolygon::setRegularPolygon(int vertexcount, cVector center, Real newradius,
	Real initangle)
{
	Real angle = initangle;

	setSize(vertexcount);
	for (int i=0; i<vertexcount; i++)
	{
		_vectorvert[i] = center + newradius*cVector(cos(angle), sin(angle));
		angle += (2*PI)/vertexcount;
	}
	_convex = TRUE;
	setCenter(center);
	_radius = newradius;
	setRadius(_radius);
	_newgeometryflag = TRUE;
}

void cPolygon::changeVertexcount(int updown)
{
	int newvertcount = _vectorvert.GetSize() + updown;
	if (newvertcount < 2)
		newvertcount = 2;
	setRegularPolygon(newvertcount, center(), radius(), angle());
	_newgeometryflag = TRUE;
}


void cPolygon::setRandomStarPolygon(int mincount,
	int maxcount)
{
#ifdef TRUESTAR
	CPoint starpoint(cRandomizer::pinstance()->random(mincount, maxcount),
		cRandomizer::pinstance()->random(2,maxcount/2));

	if (GCD(starpoint.x, starpoint.y) != 1)
		starpoint = next_rel_prime_pair(starpoint);
	setStarPolygon(starpoint.x, starpoint.y, center(),
		_radius, angle());
	_newgeometryflag = TRUE;
#else //Fake not TRUESTAR
	setStarPolygon(cRandomizer::pinstance()->random(mincount, maxcount),
		cRandomizer::pinstance()->randomReal(0.25, 0.9), center(),
		_radius, angle());
	_newgeometryflag = TRUE;
#endif //not TRUESTAR
}

#ifdef TRUESTAR

void cPolygon::setStarPolygon(int vertexcount, int step, cVector center,
	Real newradius, Real initangle)
{
	Real angle;
	int i = 0, stepi = 0;

	if (step < 1)
		step = 1; //Avoid endless loop you'd get if step == 0.
	setSize(vertexcount);
	while (!i || stepi)
	/* Do the while loop for the first step (when !i) and for any
	succeding step where stepi is not yet divisible by vertexcount*/
	{
		angle = initangle + (stepi * 2.0 * PI)/vertexcount;
		_vectorvert[i] = center + newradius*cVector(cos(angle), sin(angle));
		i++;
		stepi = (i*step)%vertexcount;
	}
	setSize(i); //There are i actual vertexes that got used.
	_convex = FALSE;
	setCenter(center);
	setRadius(newradius);
	_newgeometryflag = TRUE;
}

#else //not TRUESTAR fake a star

void cPolygon::setStarPolygon(int vertexcount, Real dentpercent, cVector center,
	Real newradius, Real initangle)
{
	setSize(2*vertexcount);
	Real angle = initangle;
	Real anglestep = PI/vertexcount;
	BOOL tipvertex = TRUE;
	Real innerradius = newradius * dentpercent;
	Real currentradius = newradius;
	for (int i=0; i<2*vertexcount; i++)
	{
		if (tipvertex)
			currentradius = newradius;
		else
			currentradius = innerradius;
		_vectorvert[i] = center + currentradius*cVector(cos(angle), sin(angle));
		angle += anglestep;
		tipvertex ^= TRUE;
	}
	setCenter(center);
	setRadius(newradius);
	_newgeometryflag = TRUE;
}

#endif //TRUESTAR

void cPolygon::mutate(int mutationflags, Real mutationstrength)
{
	cSprite::mutate(mutationflags, mutationstrength); 
	//Also mutates pcolorstyle fields.
/* Mutates _radius
		and calls setRadius, which does a scaling operation. */
	_pdotcolorstyle->mutate(mutationflags, mutationstrength);
//The dots
	if (mutationflags & cPolygon::MF_DOTS)
	{
		setDotted(_dotted ^ cRandomizer::pinstance()->randomBOOL(mutationstrength/2.0));
		_realdotradiusweight =
			cRandomizer::pinstance()->mutate(_realdotradiusweight, 0.2, 0.4, mutationstrength);
	}
//Number of vertices
	if (mutationflags & cPolygon::MF_VERTCOUNT)
	{
		int newcount;
		if  (!vertCount()) 
		{//Creating a new polygon 
			if (cRandomizer::pinstance()->randomBOOL(0.5))
				setRegularPolygon(cRandomizer::pinstance()->random(2,9), center(), _radius, angle());
			else
			{
				newcount = cRandomizer::pinstance()->random(5, 14);
				setRandomStarPolygon(newcount, newcount);
			}
		}
		else if (cRandomizer::pinstance()->randomBOOL(mutationstrength))//Mutate an existing one
		{
			int minsides = __max(2, vertCount() - 2);
			int maxsides = __min(9, vertCount() + 2);
			if (cRandomizer::pinstance()->randomBOOL(0.5))
			{
				newcount = cRandomizer::pinstance()->random(minsides, maxsides);
				setRegularPolygon(newcount,	center(), _radius, angle());
			}
			else
			{
				minsides = __max(5, vertCount() - 2);
				maxsides = __min(14, vertCount() + 2);
				newcount = cRandomizer::pinstance()->random(minsides, maxsides);
				setRandomStarPolygon(newcount, newcount);
			}
		}
	}
//Fixups
	if (vertCount() == 2)	 //Don't want any plain old line segments.
		setDotted(TRUE);
	setRadius(_radius); /* Set the radius last, as it depends on the line width, 
		dots, etc. */
	_newgeometryflag = TRUE;
}
//-----------------Randomizing Functions---------------
int GCD(int a, int b)
{ // Euclid's algorithm for the greatest common divisor of a and b.
	if (a < b)
	{
		int temp = a;
		a = b;
		b = temp;
	}
	if (!b)
		return a;
	int q = a/b;
	int r = a - b*q;
	return GCD(q,r);
}

void cPolygon::setRandomRegularPolygon(int mincount, int maxcount)
{
	setRegularPolygon(cRandomizer::pinstance()->random(mincount, maxcount), center(),
		_radius, angle());
	_newgeometryflag = TRUE;
}


void cPolygon::setRandomAsteroidPolygon(int mincount, int maxcount, Real spikiness)
{			
	Real angle = 0.0, anglestep;
	int vertexcount = cRandomizer::pinstance()->random(mincount, maxcount);
	setSize(vertexcount);
	anglestep = 2*PI/vertexcount;
	for (int i=0; i<vertexcount && angle < 2.0*PI; i++)
	{
		cVector temp = 
		_vectorvert[i] = cRandomizer::pinstance()->randomReal(1.0 - spikiness, 1.0 + spikiness) *
			cVector(cos(angle), sin(angle));
		angle += cRandomizer::pinstance()->randomReal(0.0, 2.0*anglestep);
	}
	setSize(i);
	fixCenterAndRadius();
	setRadius(_radius);
	_newgeometryflag = TRUE;
}

//--------------- cPolygon Serialization -------------

void cPolygon::Serialize(CArchive &ar)
{
	cSprite::Serialize(ar);
		/* If I were to try to do ar<<_vectorvert and  ar<<_vectorvert in
		the two cases below, the code won't compile.  We must always use Serialize
		calls to write and read CArray objects. */
	_vectorvert.Serialize(ar); 
	if (ar.IsStoring()) //Writing data.
		ar <<  _dotted <<	_realdotradiusweight << _convex << _pdotcolorstyle;
	else //Reading data.
	{
 		delete _pdotcolorstyle;
		_pdotcolorstyle = NULL;
 			//always delete a pointer before reading into it or you have a leak.
		ar >>  _dotted >> _realdotradiusweight >> _convex >> _pdotcolorstyle;
	}
}

void cPolygon::imagedraw(cGraphics *pgraphics, int drawflags)
{
	if (_convex)
		pgraphics->drawpolygon(this, drawflags);
	else
		pgraphics->drawstarpolygon(this, drawflags);
}

//====================Polypolygon code==================

cPolyPolygon::cPolyPolygon(int baseverts, int tipverts)
{
	setBasePoly(new cPolygon(baseverts));
	setTipShape(new cPolygon(tipverts));
	randomize(cSprite::MF_RADIUS | cPolygon::MF_COLOR);
	//Randomize the tip rotations.
	_tipangvelocity = cRandomizer::pinstance()->randomReal(cPolyPolygon::MINTIPANGLEVELOCITY,
		 cPolyPolygon::MAXTIPANGLEVELOCITY);
	_tipangvelocity *= cRandomizer::pinstance()->randomSign();
}

cPolygon* cPolyPolygon::pbasepoly() const
{
	if (!_childspriteptr.GetSize())
		return NULL;
	return (cPolygon*)(_childspriteptr[0]);
}

cSprite* cPolyPolygon::ptipshape() const
{
	if (_childspriteptr.GetSize()<2)
		return NULL;
	return _childspriteptr[1];
}

Real cPolyPolygon::radius() const
{
	Real tempradius = 0.0;
	Real scaledradius;
	if (pbasepoly())
		tempradius += pbasepoly()->radius();
	if (ptipshape())
		tempradius += ptipshape()->radius();
	scaledradius = (_spriteattitude.scalefactor())*tempradius;
	return scaledradius;
}

void cPolyPolygon::setBasePoly(cPolygon *ppoly)
{
	cSprite *ptipshapeold = NULL;
	if (ptipshape())
		ptipshapeold = ptipshape()->clone();
	for (int i=0; i<_childspriteptr.GetSize(); i++)
	{
		delete _childspriteptr[i];
		_childspriteptr.ElementAt(i) = NULL;
	}
	_childspriteptr.SetSize(0);
	add(ppoly);
	setTipShape(ptipshapeold);
}

void  cPolyPolygon::setTipShape(cSprite *pshape)
{
	int i;
	if (!pbasepoly() || !pshape)
		return;
	for (i=1; i<_childspriteptr.GetSize(); i++)
	{
		delete _childspriteptr[i];
		_childspriteptr.ElementAt(i) = NULL;
	}
	_childspriteptr.SetSize(1);
	Real angle = 0.0, angleincrement = 2*PI;
	if (pbasepoly()->vertCount())
		angleincrement /= pbasepoly()->vertCount();
	for (i=0; i<pbasepoly()->vertCount(); i++)
	{
		cSprite* ptipshapenew = pshape->clone();
		cMatrix tipattitude = cMatrix::zRotation(angle);
		angle += angleincrement;
		tipattitude.setLastColumn(pbasepoly()->getVertex(i));
		ptipshapenew->setSpriteAttitude(tipattitude);
		add(ptipshapenew);
	}
	setPrismDz(_prismdz); //Cascade the prismdz out to the tips.
	delete pshape;
	pshape = NULL;
}	

void cPolyPolygon::setPrismDz(Real prismdz)
{
/* If the tipshapes are exactly the same thcikness at the baseshape, we have their faces coinciding
with each otehr, which gives an ugly drawing effect.  So in cPolyPolygon::setPrismDz, we make the
tipshape thicker than the base shape.  To make it stick out above the base shape on both sides,
we translate each tipshape downward in the z direction a bit as well. */
	_prismdz = prismdz;
	Real scalefactor = _spriteattitude.scalefactor();
	ASSERT(scalefactor > SMALL_REAL);
	Real baseprismdz = _prismdz/scalefactor; /* We 
		divide by the scalefactor becuase, for a composite sprite, the
		attitude scales the whole assembly from the "outside," and we want
		the prismdz thickness to be aboslute. */
	pbasepoly()->setPrismDz(baseprismdz);
	Real tipprismdz = cPolyPolygon::TIPPRISMDZMULTIPLIER * baseprismdz;
	Real tipoffsetdz = 0.5*(tipprismdz - baseprismdz);
	for (int i=1; i<_childspriteptr.GetSize(); i++) 
	{
	//To only get the tip shapes and not base, start i with 1 not 0.
		//Make thicker.
		_childspriteptr.GetAt(i)->setPrismDz(cPolyPolygon::TIPPRISMDZMULTIPLIER * baseprismdz);
		//Slide so tipshape sticks out equally above and below .
		cMatrix tipattitude = _childspriteptr.GetAt(i)->spriteattitude();
		tipattitude.setZTranslation(-tipoffsetdz); /* Use this absolute method rather than a
			relative call to tranlsate(cVector(0,0,-tipoffsetdz) because it's possible I might
			call setPrismDz more than once on a given sprite, so I don't watn the z corretions
			to accumulate. */
		_childspriteptr.GetAt(i)->setSpriteAttitude(tipattitude);
			/* Slide down the z axis a bit.  Don't try to do this by multiplying in 
				a cMatrix::translation matrix. */
	}
}

void cPolyPolygon::mutate(int mutationflags, Real mutationstrength)
{
	if (!pbasepoly())
		add(new cPolygon());
	pbasepoly()->mutate(mutationflags, mutationstrength);
	cSprite* ptipshapenew;
	if (ptipshape())
		ptipshapenew = ptipshape()->clone(); //Use this as a model
	else
		ptipshapenew = new cPolygon();
	ptipshapenew->mutate(mutationflags, mutationstrength);
		//Make the tip shape have smaller radius than the basepoly.
	ptipshapenew->setRadius(cRandomizer::pinstance()->mutate(ptipshapenew->radius(),
		MIN_TIP_RADIUS_RATIO*pbasepoly()->radius(), MAX_TIP_RADIUS_RATIO*pbasepoly()->radius(),
		mutationstrength));
	//Randomize the tip rotations.
	_tipangvelocity = cRandomizer::pinstance()->randomSign() * cRandomizer::pinstance()->mutate(_tipangvelocity, cPolyPolygon::MINTIPANGLEVELOCITY,
		 cPolyPolygon::MAXTIPANGLEVELOCITY, mutationstrength);
	//Make all the tips the same.
	setTipShape(ptipshapenew);  //This deletes ptipshapenew
//More fixup
	_newgeometryflag = TRUE; //Because you changed the relative positions of the tips.
}

void cPolyPolygon::animate(Real dt, cCritter *powner)
{
	for (int i=1; i<_childspriteptr.GetSize(); i++) 
	{ //Tp oOnly rotate the tip shapes and not base, start i with 1 not 0.
		_childspriteptr[i]->rotate(dt*_tipangvelocity); /* this multiplies _spriteattitude
			by the given zRotation amount on the right. */
#ifdef TRACESPRITEATTITUDE
	Real *aelements = _childspriteptr[i]->spriteattitude().transpose().elements();
	TRACE("3D version of cCritter attitude() matrix out cPolyPolygon::animate(call.\n");
	TRACE("%f  %f  %f  %f\n", aelements[0], aelements[4], aelements[8], aelements[12]);
	TRACE("%f  %f  %f  %f\n", aelements[1], aelements[5], aelements[9], aelements[13]);
	TRACE("%f  %f  %f  %f\n", aelements[2], aelements[6], aelements[10], aelements[14]);
	TRACE("%f  %f  %f  %f\n", aelements[3], aelements[7], aelements[11], aelements[15]);
#endif //TRACESPRITEATTITUDE
	}
}

//cSpriteRectangle==================================

cSpriteRectangle::cSpriteRectangle(Real lox, Real loy, Real hix, Real hiy)
{
		/* I used to call _initializer() here, but that was mistake
		as the baseclass cPolygon constructor calls _initializer first.
		Calling _initializer twice made a resrource leak. */
	_vectorvert.SetSize(4);
	setVertex(0,cVector(lox, loy));
	setVertex(1,cVector(hix, loy));
	setVertex(2,cVector(hix, hiy));
	setVertex(3,cVector(lox, hiy));
	setPrismDz(0.0);
	_convex = TRUE;
	fixCenterAndRadius();
}	

cSpriteRectangle::~cSpriteRectangle()
{//Do nothing here, then C++ calls the base cPolygon destructor.
}