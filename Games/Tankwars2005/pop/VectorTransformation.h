#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "realnumber.h"
#include <gl/gl.h> //for  OpenGL methods like glVertex()

#define THREEDVECTORS
/*  Comment in the THREEDVECTORS switch to make the types "cVector, cMatrix, cRealBox" be
cVector3, cMatrix3, and cRealBox3.  Comment THREEDVECTORS out to make the same types be,
respectively, cVector2, cMatrix2 and cRealBox2.
	You might be surprised to learn that the program runs essentially at the same speed with
2D instead of 3D vectors!  Very little percentage of the computation must be going into 
that third argument.  Sample figure: on my machine a 31 critter Dambuilder runs at 40-41 updates per
second with 3D vectors and at 41-42 updates per second with 2D vectors.  Maybe 3% speed pickup.
	The 3D games don't seem to work at all with 2D vectors, maybe there's an issue with the
viewer code assuming 3D.
	Instead of having this #ifdef switch on typedefs, I could have written a 
common cVector interface and have cVector2 and cVector3 inherit
from it.  But since I use these guys so often, I'm concerned that making their
methods virtual might slow the programs down.  Same for cMatrix.  I haven't actaully
tested if it would run slower if I had a cVectorBase that cVector2 and cVector3
inherit from, I really should.  But no time right now.  As mentioned,
in the Pop framework, we use "ambiguous" cVector and cMatrix types, and try and write
the code so it would work for any dimensionality.  I disambigutate the actual
dimensionality of these in this vectortransformation.h file and realbox.h by lines like: 
typedef class cVector3 cVector;
typedef class cMatrix3 cMatrix;
typedef class cRealBox3 cRealBox;
*/

/* 
History:

	The cVectorTransformation.* files implement 2 and 3 dimensional vectors and some
matrices for transforming them.  They were developed by Rudy Rucker for CS 116A at SJSU 
in Spring, 1996 in a series of 5 versions, up through cVector5.h and cVector5.cpp.
	This cVectorTransformation version was developed in Spring, 1999, for use in 
Rucker's SOFTWARE PROJECTS text.  It was extensively rewritten at this time.
	The code in this module was very heavily reworked again in Spring/Summer 2001
as part of the port to 3D OpenGL from our old 2D Windows API graphics.  These
graphics versions are called cGraphicsMFC and cGraphicsOpenGL; see the
graphics.h header for more information.

Three Dimensional Version is Preferred:

	With an eye to a possible future 4D version of the code, we tried to keep the 
2D and 3D vector and matrix classes closely in synch, even when it sometimes meant
doing some slightly unnatural things.
	In the rest of the Pop framework we generally use
"cVector" and "cMatrix" without specifiying if we mean "cVector2" and "cMatrix2" or
"cVector3" and "cMatrix3".  The goal was to write the code so that it woudl 
compile and run more or less well in either a 2D or a 3D form.  The point being
to make the code, as far as possible, dimension-free.  Again, this is done with
the hope of someday entering the Promised Land of four-dimensional videogames.
	As it turns out, the speed overhead of using 3D instead of 2D vectors is
negligable.  In particular, tests with the cGraphicsMFC show a typical slow
down of at most two percent when using 3D instead of 2D.  For this reason, 
we in fact will always use the 3D version from now on.  
	If you are curious to test the 2D version, you can comment out the
#define THREEDVECTORS at the head of this vectortransformation.h header file
and rebuild.  As of May 19, 2001, the 2D version build and ran fine with 
cGraphicsMFC, but there was a "blank screen" problem with cGraphicsOpenGL,
probably having to do with the positioning of the cCritterViewer used by
CPopView.  Due to constraints of time, we're not tracking down this particualr
bug and are instead focussing on getting cGraphicsMFC to work perfectly with
our now-standard 3D build. 

Usage:

	The cVector2 and cVector3 classes represent two and three dimensional vectors.
The +, - and * operators for addition, subtration, and scalar multiplication.
The operator% is used for the dot product.  Cross product has not been implemented.
	The cMatrix2 and cMatrix3 classes are used as transformations on,
respectively, the cVector2 and cVector3 objects.  To apply the transformation to a 
vector we use v.apply(M) or the overloaded friend operator* as in v = M * u.
Always use parentheses when you have several transformations so as to enforce the
desired order of evaluation.
	Our transformations effectively perform a scaling, shear and/or a rotation
followed by a translation.  When you multiply two transformations to get S = R * T, the effect of S will be
to perform T and to then perform R.

Implementation:
	We think of a 2-D vector as a 1 by 3 column matrix with a 1.0 in the bottom
row, and we think of a cMatrix2 as a 3 by 3 matrix with a bottom identiy
row of 0.0  0.0  1.0.
	The reason we do this is so that we can fit a translation into the matrix as the
third column, and we want our matrices square so we an invert them. Our
implementation computes the product of a cMatrix2 and cVector2 by doing the 
standard multiplication of a 3x3 matrix times a 1x3 column vector. 
	The same ideas appply to the realtionship cVector3 and cMatrix3. */

//Preliminary declarations involving types we'll specify later on in this file.==============
class cMatrix2; //So cVector2 can mention operator*(cMatrix2, cVector2)
class cMatrix3; //So cVector3 can mention operator*(cMatrix3, cVector3)
class cVector2;
class cVector3; //So cVector2 can have a cVector2(cVector3) constructor.
class cSpin; //A containter to hold a vector, and an axistype, for speeding up roations.
//Typedef of the generic vector and matrix classes we'll use.

#ifndef THREEDVECTORS
	typedef class cVector2 cVector;
	typedef class cMatrix2 cMatrix;
#else //THREEDVECTORS
	typedef class cVector3 cVector;
	typedef class cMatrix3 cMatrix;
#endif //THREEDVECTORS
//End preliminary type declarations.============================================================

//--TWO and THREE DIMENSIONAL Vectors ------

class cVector2 : public CObject
{
public:
	static const Real PRACTICALLY_ZERO; /* Used by the isZero method to treat as zero
		vectors the occasional neglibible rounded off remains of a vector that should be 
		zero. See isPracticallyZero below. */
	static const Real PRACTICALLY_PARALLEL_COSINE; /* Used when you dot product two unit vectors
		together; if they're "practiclaly parallel" the dot product is greater than this. */
	static const cVector2 ZEROVECTOR;
	static const cVector2 XAXIS;
	static const cVector2 YAXIS;
	static const cVector2 ZAXIS;
private:
	Real _x,_y;
	friend cMatrix2;
public:
	cVector2(){_x = _y = 0.0;} //The 0 vector. Use  default copy constructor and =. 
	cVector2(Real ix, Real iy){_x = ix; _y = iy;}
	cVector2(Real ix, Real iy, Real iz){_x = ix; _y = iy;} /* For uniformity of interface with
		the cVector3, we allow a three-arg constructor. */
	cVector2(const cVector2 &v){_x = v._x; _y = v._y;}
	cVector2(const cVector3 &v);
//Mutators
	void set(Real ix, Real iy, Real iz=0.0){_x = ix; _y = iy;}
	void setZ(Real iz){}
	void setZero(){_x = 0.0; _y = 0.0;}
	void setMagnitude(Real mag); //Make your length be mag
	cVector2 normalize(); //Make yourself of unit length and return self.
	Real normalizeAndReturnMagnitude(); //Make yourself of unit length and return mag.
	cVector2 roundOff(); /* Get rid of any component with size less than SMALL_REAL.  This
		can be useful if you have some nagging little roundoff residue in a compoment that
		should be 0. Return self. */ 
//Accessors 
	Real x()const {return _x;}
	Real y()const {return _y;}
	Real z()const {return 0.0;} //Have this so cVector2 interface is consistent with cVector3.
	Real angle() const; /* Returns an angle between 0 and 2*PI, and for the
		 degenerate vector (0,0) it returns 0. */
	Real magnitude() const{return sqrt(_x*_x + _y*_y);} //Return the cVector2's length.
	Real distanceTo(const cVector2 &vect) const;
	cVector2 direction(); //Return a unit vector in your direction.
	BOOL isZero()const{return _x == 0.0 && _y == 0.0;}
	BOOL isPracticallyZero()const{return magnitude() < PRACTICALLY_ZERO;} 
	BOOL isPracticallyEqualTo(const cVector2 &u)const{return (*this-u).magnitude() < PRACTICALLY_ZERO;} 
		/* Sometimes if I do something like u = cVector2(1,0) - cVector2(1,0),
			u I can end up with a nonzero magnitude.  So I use this to winnow out
			marginally inaccurate vectors that should be zero. */
//Other Methods
	friend Real distance(const cVector2 &u, const cVector2 &v); //Distance
	friend Real angleBetween(const cVector2 &u, const cVector2 &v); /* The angle of u
		minus the angle of v, that is, the counterclockwise	angle gotten by
		turning from v to u.  Value between 0 and 2*PI. */
	cVector2 defaultNormal();  //Useful sometimes to arbitrarily pick a normal
//Overloaded Operators
	cVector2 operator=(const cVector2 &u){_x=u._x; _y=u._y; return *this;}
	cVector2 operator+=(const cVector2 &u){_x+=u._x; _y+=u._y; return *this;}
	cVector2 operator-=(const cVector2 &u){_x-=u._x; _y-=u._y; return *this;}
	cVector2 operator*=(Real f){_x*=f; _y*=f; return *this;}
	cVector2 operator/=(Real f);
	cVector2 turn(Real angle); //Means rotate aroudn z axis
	cVector2 rotate(const cSpin &spin); //Stands for more general roatoin when in higher D.
	friend cVector2 operator*(const cVector2 &u, Real f); //Scalar prod
	friend cVector2 operator*(Real f, const cVector2 &u); //Scalar prod
	friend cVector2 operator/(const cVector2 &u, Real f); //Scalar division
	friend cVector2 operator+(const cVector2 &u, const cVector2 &v); //cVector2 sum
	friend cVector2 operator-(const cVector2 &u, const cVector2 &v);
		//cVector2 difference.
	friend cVector2 operator-(const cVector2 &u){return cVector2(-u._x,-u._y);}
	friend cVector3 operator*(const cVector2 &u, const cVector2 &v); //Returns (0,0,1)
		/* We have a default 2D cross product method so the interface is like the interface of the cVector3. */
		//Unary -
	friend Real operator%(const cVector2 &u, const cVector2 &v); //Dot product
	friend int operator==(const cVector2 &u, const cVector2 &v) //equality predicate.
		{return (u._x == v._x && u._y == v._y);}
	friend int operator!=(const cVector2 &u, const cVector2 &v) //inequality predicate.
		{return !(u._x == v._x && u._y == v._y);}
//Matrix methods
	friend cVector2 operator*(const cMatrix2 &M, const cVector2 &V);
	void apply(const cMatrix2 &M); //set self = M*self;
//Factory Method
	static cVector2 randomUnitVector();
//Serialization
	friend CArchive& operator<<(CArchive& ar, const cVector2 &v);
	friend CArchive& operator>>(CArchive& ar, cVector2 & v);
 	void Serialize(CArchive &ar);
};

class cVector3  : public CObject
{
public:
	static const Real PRACTICALLY_ZERO; /* Used by the isZero method to treat as zero
		vectors the occasional neglibible rounded off remains of a vector that should be 
		zero. See isPracticallyZero below. */
	static const Real PRACTICALLY_PARALLEL_COSINE; /* Used when you dot product two unit vectors
		together; if they're "practiclaly parallel" the dot product is greater than this. */
	static const cVector3 ZEROVECTOR;
	static const cVector3 XAXIS;
	static const cVector3 YAXIS;
	static const cVector3 ZAXIS;

private:
	Real _x, _y, _z;
	friend cMatrix3;
public:
	cVector3(){_x = _y = _z = 0.0;} //The 0 vector. Use  default copy constructor and =. 
	cVector3(Real ix, Real iy, Real iz):_x(ix),_y(iy),_z(iz){}
	cVector3(Real ix, Real iy):_x(ix),_y(iy),_z(0.0){}
	cVector3(const cVector3 &v){_x = v._x; _y = v._y; _z = v._z;}
	cVector3(const cVector2 &v){_x = v.x(); _y = v.y(); _z = 0.0;}
//Mutators
	void set(Real ix, Real iy, Real iz){_x = ix; _y = iy; _z = iz;}
	void set(Real ix, Real iy){_x = ix; _y = iy;}//leave z alone
	void setZ(Real iz){_z = iz;}
	void setZero(){_x = 0.0; _y = 0.0; _z = 0.0;}
	cVector3 normalize(); //Make yourself of unit length and return self.
	Real normalizeAndReturnMagnitude(); //Make yourself of unit length and return mag.
	cVector3 roundOff(); /* Get rid of any component with size less than SMALL_REAL.  This
		can be useful if you have some nagging little roundoff residue in a compoment that
		should be 0. Return self. */
	void setMagnitude(Real mag); //Make your length be mag
	void apply(const cMatrix3 &M); //Apply M to self.
	cVector3 turn(Real angle); //Means rotate around z axis.
	cVector3 rotate(const cSpin &spin);  //Can be around any axis.
	cVector3 getXYUnitVector(){return cVector(_x, _y, 0.0).normalize();}
		// Projects into the xy plane, makes a unit vector, returns copy.
//Accessors 
	Real x()const {return _x;}
	Real y()const {return _y;}
	Real z()const {return _z;}
	Real magnitude() const; //Return the cVector3's length.
	Real distanceTo(const cVector3 &vect) const;
//	Real angle(cVector3 standarddir=cVector3(1.0, 0.0, 0.0)) const 
//		{return angleBetween(*this, standarddir);} /* Returns an angle between 0 and PI.*/
	Real angle()const; //Collapse to 2D and get that angle.
	cVector3 direction()const; //Return a unit vector in your direction.
	BOOL isZero()const{return _x == 0.0 && _y == 0.0 && _z == 0.0;}
	BOOL isPracticallyZero()const{return magnitude() < PRACTICALLY_ZERO;} 
	BOOL isPracticallyEqualTo(const cVector3 &u)const{return (*this-u).magnitude() < PRACTICALLY_ZERO;} 
	/* Sometimes if I do something like u = cVector3(1,0) - cVector3(1,0),
			u I can end up with a nonzero magnitude.  So I use this to winnow out
			inaccurate vectors that should be zero. */
//Other Methods
	friend Real distance(const cVector3 &u, const cVector3 &v); //Distance
	friend Real angleBetween(const cVector3 &u, const cVector3 &v); /* The angle of u
		minus the angle of v, that is, the counterclockwise	angle gotten by
		turning from v to u.  Value between 0 and 2*PI. */
	cVector3 defaultNormal(); //Useful sometimes to arbitrarily pick a normal
//Overloaded Operators
	cVector3 operator=(const cVector3 &u){_x=u._x; _y=u._y; _z=u._z; return *this;}
	cVector3 operator+=(const cVector3 &u){_x+=u._x; _y+=u._y; _z+=u._z; return *this;}
	cVector3 operator-=(const cVector3 &u){_x-=u._x; _y-=u._y; _z-=u._z; return *this;}
	cVector3 operator*=(Real f){_x*=f; _y*=f;  _z*=f; return *this;}
	cVector3 operator/=(Real f);
//Factory Method
	static cVector3 randomUnitVector();
//Overloaded Friend operators
	friend cVector3 operator*(const cVector3 &u, Real f); //Scalar prod
	friend cVector3 operator*(Real f, const cVector3 &u); //Scalar prod
	friend cVector3 operator/(const cVector3 &u, Real f); //Scalar division
	friend cVector3 operator+(const cVector3 &u, const cVector3 &v); //cVector3 sum
	friend cVector3 operator-(const cVector3 &u, const cVector3 &v);//cVector3 difference.
	friend cVector3 operator-(const cVector3 &u){return cVector3(-u._x,-u._y,-u._z);}//Unary -
	friend Real operator%(const cVector3 &u, const cVector3 &v); //Dot product
	friend cVector3 operator*(const cVector3 &u, const cVector3 &v); //cross product
	friend int operator==(const cVector3 &u, const cVector3 &v) //equality predicate.
		{return (u._x == v._x && u._y == v._y && u._z == v._z);}
	friend int operator!=(const cVector3 &u, const cVector3 &v) //inequality predicate.
		{return !(u._x == v._x && u._y == v._y && u._z == v._z);}
	friend cVector3 operator*(const cMatrix3 &M, const cVector3 &V);
//Serialization
	friend CArchive& operator<<(CArchive& ar, const cVector3 &v);
	friend CArchive& operator>>(CArchive& ar, cVector3 & v);
 	void Serialize(CArchive &ar);
//OpenGL Methods
#ifdef USEFLOAT //Real means float
	//void glVertex(){::glVertex3f(_x, _y, _z);}
	void glVertex(){::glVertex3fv(&_x);}
#else //Real means double
	void glVertex(){::glVertex3d(_x, _y, _z);}
#endif //USEFLOAT
};

//Helper class
class cSpin : public CObject
{
public:
	static const enum AXISTYPE {XAXISTYPE, YAXISTYPE, ZAXISTYPE, ARBITRARYAXISTYPE};
private:
	Real _spinangle;
	cVector3 _spinaxis;
	AXISTYPE _axistype;
public:
	cSpin():_spinangle(0.0), _spinaxis(cVector3(1.0, 0.0, 0.0)), _axistype(ZAXISTYPE){}
	cSpin(cVector spinvector);
	cSpin(Real spinangle, cVector spinaxis);
	cSpin(Real angle):_spinangle(angle),_spinaxis(cVector3(0.0, 0.0, 1.0)), _axistype(ZAXISTYPE){}
	cSpin(const cSpin &spin){*this = spin;}
	Real spinangle()const{return _spinangle;}
	cVector3 spinaxis()const{return _spinaxis;}
	cSpin::AXISTYPE axistype()const{return _axistype;}
	void setZero(){_spinangle = 0.0; _axistype=ZAXISTYPE; _spinaxis = cVector3(0.0, 0.0, 1.0);}
	cSpin& operator=(const cSpin &spin){_spinangle = spin._spinangle; _spinaxis = spin._spinaxis;
		_axistype = spin._axistype; return *this;}
	friend cSpin operator*(Real f, const cSpin &spin){cSpin fspin(spin); fspin._spinangle*=f; return fspin;}
	friend CArchive& operator<<(CArchive& ar, const cSpin &v);
	friend CArchive& operator>>(CArchive& ar, cSpin & v);
 	void Serialize(CArchive &ar);
};		

// ----- Two and Three Dimensional Matrixes, or Transformations -------

class cMatrix2  : public CObject
{
private:
	Real _mat[3][3];
		/*Note that _mat[i][j] means the entry in the i_th row and the j_th
		column, so this is similar to usual matrix notation like m_ij.  One
		minor confusion is that C language indices start at 0, but matrix
		indices usually start at 1.*/
	friend cVector2;
	friend cMatrix3; //Need this for the up-cast constructor cMatrix3(cMatrix2)
public:
//Constructor
	cMatrix2(){identity();} //Call the Identity operation at construction.
	cMatrix2(const cMatrix2 &M);
	void copy(const cMatrix2 &M);
	cMatrix2& operator=(const cMatrix2 &M);
	cMatrix2(Real e00, Real e10, Real e20, Real e01, Real e11, Real e21,
		Real e02, Real e12, Real e22); /* Feed the args in as columns, so first three are first
		column, and so on. */
	cMatrix2::cMatrix2(cVector2 tangent, cVector2 normal, cVector2 position);
		/* This can be used to make a cMatrix2(tangent, normal, position) to
			set the cols to tangent, normal and position. */
	cMatrix2::cMatrix2(cVector2 tangent, cVector2 normal, cVector2 binormal,
		 cVector2 position);
	 /* To match the four arg constructor of cVector3, we include this, but ignore the binormal argument.
		Note it's binormal we ignore and NOT position.  This is so cMatrix2(tangent, normal, binormal,
			position) will set the cols to tangent, normal and position. */
//Accessor
	Real* elements(){return (Real*)_mat;} 
	cVector2 column(int i)const;
	cVector2 lastColumn()const{return column(2);}
	Real scalefactor()const; //How much scaling does this do?  Assume isotropic, so test on unit vector of XAXIS
//Mutators
	void identity(); //Set to the identity transformation.
		/* The following three friend operations create special kinds
			of matrices*/
	void set(Real e00, Real e10, Real e20, Real e01, Real e11, Real e21,
		Real e02, Real e12, Real e22); /* Feed the args in as columns, so first three are first
		column, and so on. */
	void setColumn(int j, const cVector2 &u); //j is 0, 1, or 2.
	void setLastColumn(const cVector3 &u){setColumn(2,u);}
	void setZTranslation(Real zpos){} //Do nothing, just here to match Matrix3 interface
	void setRotationAndScale(Real ang, Real s = 1.0);
	void setRotationAndScaleAboutCenter( cVector2 center, Real ang, Real s = 1.0);
	void translate(cVector2 trans);
	void orthonormalize(); //Make first two columns an orthonormal basis.
	cMatrix2 inverse();
//Matrix methods
	cMatrix2 transpose();
	//See the comments on the rigidBody methods in cMatrix3 and in the vectortransformation.cpp.
	cMatrix2 normalTransformation();
//Overloaded operators
	cMatrix2& operator*=(const cMatrix2 &M);
	friend cMatrix2 operator*(const cMatrix2 &M,
		const cMatrix2 &N);
	friend cVector2 operator*(const cMatrix2 &M, const cVector2 &V);
	friend cMatrix2 operator*(Real f, cMatrix2 M){for (int i=0; i<9; i++)M.elements()[i]*=f; return M;}
//Static Factory methods----------------------
	static cMatrix2 identityMatrix(){return cMatrix2();}
	static cMatrix2 xRotation(Real ang){return cMatrix2();} //return identity.
	static cMatrix2 yRotation(Real ang){return cMatrix2();} //return identity.
	static cMatrix2 zRotation(Real ang);
	static cMatrix2 rotation(Real ang){return rotation(cSpin(ang));}
	static cMatrix2 rotation(const cSpin &spin);/* ignore axis variable,
		its only here for consistency with the Vector3 interface. */
	static cMatrix2 rotationFromUnitToUnit(const cVector2 &u, const cVector2 &v); /* Assume that
		u and v are unit vectors.  This gives a matrix that rotates u into v. */
	static cMatrix2 scale(Real size);
	static cMatrix2 translation(const cVector2 &displace);
//Serialization
	friend CArchive& operator<<(CArchive& ar, const cMatrix2 & M);
	friend CArchive& operator>>(CArchive& ar, cMatrix2 &M);
 	void Serialize(CArchive &ar);
};

class cMatrix3  : public CObject
{
private:
	Real _mat[4][4];
		/*Note that _mat[i][j] means the entry in the i_th row and the j_th
		column, so this is similar to usual matrix notation like m_ij.  One
		minor confusion is that C language indices start at 0, but matrix
		indices usually start at 1.*/
	friend cVector3;
public:
//Constructor and copy
	cMatrix3(){identity();} //Call the Identity operation at construction.
	cMatrix3(Real e00, Real e10, Real e20, Real e30, Real e01, Real e11, Real e21, Real e31,
		Real e02, Real e12, Real e22, Real e32, Real e03, Real e13, Real e23, Real e33); /* We
		feed the arguments in column order, that is the first four are the first column, and so on. */
	cMatrix3(Real *vert); //Assume vert is an array of 16.
	cMatrix3(cVector3 tangent, cVector3 normal, cVector3 binormal,
		 cVector3 position); /*This will set the cols to tangent, normal and position. */
	cMatrix3(const cMatrix3 &M);
	void copy(const cMatrix3 &M);
	cMatrix3& operator=(const cMatrix3 &M);
	cMatrix3(const cMatrix2 &M); /* Use this so you can upgrade a cMatrix2 for loading into OpenGL */
//Accessor
	Real* elements(){return (Real*)_mat;} /* This returns the elements in row order, that is, the
		top row, followed by the next row and so on.  OpenGL uses elements in column order, so
		use a call like loadMatrix(M.transpose().elements()) to load into OpenGL.*/
	cVector3 column(int i)const;
	cVector3 lastColumn()const{return column(3);}
	Real scalefactor()const; //How much scaling does this do?  Assume isotropic, so test on unit vector of XAXIS

//Mutators
	void identity(); //Set to the identity transformation.
		/* The following three friend operations create special kinds
			of matrices*/
	void set(Real e00, Real e10, Real e20, Real e30, Real e01, Real e11, Real e21, Real e31,
		Real e02, Real e12, Real e22, Real e32, Real e03, Real e13, Real e23, Real e33); /* We
		feed the arguments in column order, that is the first four are the first column, and so on. */
	void set(Real *vert); //Assume vert is an array of 16.
	void setColumn(int j, const cVector3 &u); //j is 0, 1, 2, or 3.
	void setLastColumn(const cVector3 &u){setColumn(3,u);}
	void setZTranslation(Real zpos){setLastColumn(cVector3(lastColumn().x(), lastColumn().y(), zpos));}
	void translate(const cVector3 &trans);
	void orthonormalize(); //Make first three columns an orthonormal basis.
//Matrix methods
	cMatrix3 transpose();
	cMatrix3 inverse();/*This only works if we assume the matrix is a rigid-body matrix, 
		i.e. that its cVector3 columns are orthonormal unit vectors as are its cVector3
		rows (,ignoring the foruth column.)  You can have any translation you like in the fourth column. */
	cMatrix3 normalTransformation();
//Overloaded operators
	cMatrix3& operator*=(const cMatrix3 &M);
	friend cMatrix3 operator*(const cMatrix3 &M,
		const cMatrix3 &N);
	friend cVector3 operator*(const cMatrix3 &M, const cVector3 &V);
	friend cMatrix3 operator*(Real f, cMatrix3 M){for (int i=0; i<16; i++)M.elements()[i]*=f; return M;}
//Factory methods
	/* The following  operations create special matrices*/
	static cMatrix3 identityMatrix(){return cMatrix3();}
	static cMatrix3 xRotation(Real ang);
	static cMatrix3 yRotation(Real ang);
	static cMatrix3 zRotation(Real ang);
	static cMatrix3 rotation(Real ang){return rotation(cSpin(ang));}
	static cMatrix3 rotation(const cSpin &spin); 
	static cMatrix3 rotationFromUnitToUnit(const cVector3 &u, const cVector3 &v); /* Assume that
		u and v are unit vectors.  This gives a matrix that rotates u into v. */
	static cMatrix3 translation(const cVector3 &trans);
	static cMatrix3 scale(Real size);
	static cMatrix3 scale(Real xscale, Real yscale, Real zscale);
//Serialization
	friend CArchive& operator<<(CArchive& ar, const cMatrix3 & M);
	friend CArchive& operator>>(CArchive& ar, cMatrix3 &M);
 	void Serialize(CArchive &ar);
};

class cLine : public CObject
{
public:
	cVector _origin;
	cVector _tangent;
	cLine():_tangent(1,0,0){} //Default origin is (0,0,0)
	cLine(const cVector &origin, const cVector &tangent):_origin(origin),_tangent(tangent){}
	cLine(const cLine &line):_origin(line._origin),_tangent(line._tangent){}
	Real distanceTo(const cVector &point)const;
	Real lineCoord(const cVector &point)const; /* Project point onto the line, then
		take it's coord wiht the line numbered so _origin is 0.0, _origin+_tangent is 1.0, 
		and so on. */
};

class cPlane : public CObject
{
public:
	cVector _origin;
	cVector _binormal;
	cPlane():_binormal(0,0,1){} //Default origin is (0,0,0)
	cPlane(const cVector &origin, const cVector &binormal):_origin(origin),_binormal(binormal){}
	cPlane(const cPlane &plane):_origin(plane._origin),_binormal(plane._binormal){}
	cVector project(const cVector &point)const;
	cVector intersect(const cLine &line)const;
};


#endif //VECTOR_HPP
