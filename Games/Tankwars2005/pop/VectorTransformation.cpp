//------------------VECTOR.CPP--------------
#include "stdafx.h" //Includes <math.h> for sin and cos.
#include "vectortransformation.h"
#include "randomizer.h" //For the static randomUnitVector methods.

//#define TRACEROTATION //Debugging switches to dump matrix to output window.
//#define TRACEPRODUCT
//#define TRACEUNITTOUNIT

//#define USEOPENGLENGINE 
	/* I once thought USEOPENGLENGINE might improve speed and reliability by using the OpenGL engine 
		for matrix  manipulations. The switch takes effect inside cMatrix3::rotation(cSpin) and inside
		cMatrix3.  But there's a catch with using the OpenGL engine, it
		works ONLY if you happen to have a view that has an OpenGL active!  If you try and use it
		before opening a view, for instance, you'll have a problem.  So I went ahead and
		handcoded a mehtod that actually copies the formlae of the openGl method (from the OpenGL
		reference blue book.) */
//#define USESPINAXISTYPE
	/* If you define in USESPINAXISTYPE, some of the cSpin constructors try and set the axis type to
	a standard axis value in the hope of speeding up the cMatrix::rotation(spin) computation by
	looking up the simple case.  This doesn't actually garner any speed, in fact the simulation
	seems to run faster in 2D and in 3D without USESPINAXISTYPE, maybe becaue thre are less if
	statements then.  Also USESPINAXISTYPE makes trouble in that I then have to be sure I have used 
	the same algorithm for both my general rotation matrix and my spceial matrices liek yRotation. 
	(I had a problem with yRotation not matching for awhile, as I think I had the wrong formula for it.) 
	So I'm not going to bother with USESPINAXISTYPE. */

#ifdef USEOPENGLENGINE	// Need to include the OpenGL headers if you use the OpenGL engine.
	#include "gl\gl.h"
	#include "gl\glu.h"
#endif //USEOPENGLENGINE

const Real cVector2::PRACTICALLY_ZERO = 0.001;
const cVector2 cVector2::ZEROVECTOR = cVector2(0.0, 0.0);
const Real cVector2::PRACTICALLY_PARALLEL_COSINE = 0.8;
const Real cVector3::PRACTICALLY_ZERO = cVector2::PRACTICALLY_ZERO;
const cVector3 cVector3::ZEROVECTOR = cVector3(0.0, 0.0, 0.0);
const Real cVector3::PRACTICALLY_PARALLEL_COSINE = cVector2::PRACTICALLY_PARALLEL_COSINE;
const cVector2 cVector2::XAXIS = cVector2(1.0, 0.0);
const cVector2 cVector2::YAXIS = cVector2(0.0, 1.0);
const cVector2 cVector2::ZAXIS = cVector2(0.0, 0.0, 1.0);
const cVector3 cVector3::XAXIS = cVector3(1.0, 0.0, 0.0);
const cVector3 cVector3::YAXIS = cVector3(0.0, 1.0, 0.0);
const cVector3 cVector3::ZAXIS = cVector3(0.0, 0.0, 1.0);
//----TWO DIMENSIONAL STUFF-----------------------------------------

//------------------cVector2 methods-------------------

//static Factory Method
cVector2 cVector2::randomUnitVector()
{
	Real vx, vy;
	cRandomizer::pinstance()->randomUnitPair(&vx, &vy);
	return cVector2(vx, vy);
}

cVector2::cVector2(const cVector3 &v)
{
	_x = v.x(); _y = v.y();
}

cVector2 cVector2::operator/=(Real f)
{
	if (fabs(f) >= SMALL_REAL)
	{
		_x/=f;
		_y/=f;
	}
	return *this;
}

Real cVector2::angle() const
{
	Real ang = atan2(_y, _x); //Note that atan2 takes the args in reverse order.
	//This will range between -pi and pi, and I prefer 0 to 2pi, so I fix this.
	if (ang < 0.0)
		ang += 2*PI;
	if (ang == 2*PI)
		ang = 0.0;
	return ang;
}

cVector2 cVector2::normalize()
{ //Make the cVector2 a unit cVector2, and return self
	Real m = magnitude();
	if (m < SMALL_REAL)
	{
		_x = 1.0;
		_y = 0;
		m = 0.0;
	}
	else
	{
		_x /= m;
		_y /= m;
	}
//	return m; Used to return magnitude
	return *this;
}

Real cVector2::normalizeAndReturnMagnitude() //Make yourself of unit length and return mag.
{
	Real m = magnitude();
	if (m < SMALL_REAL)
	{
		_x = 1.0;
		_y = 0;
		m = 0.0;
	}
	else
	{
		_x /= m;
		_y /= m;
	}
	return m; 
}

cVector2 cVector2::roundOff()
{
	if (fabs(_x) < SMALL_REAL)
		_x = 0.0;
	if (fabs(_y) < SMALL_REAL)
		_y = 0.0;
	return *this;
}


cVector2 cVector2::direction()
{ //Make a unit cVector2, and return it
	Real m = magnitude();
	cVector2 dir = *this;
	if (m < SMALL_REAL)
	{
		dir._x = 1.0;
		dir._y = 0;
	}
	else
	{
		dir._x /= m;
		dir._y /= m;
	}
	return dir;
}

void cVector2::setMagnitude(Real mag) //Make your length be mag
{
	normalize();
	_x *= mag;
	_y *= mag;
}

void cVector2::apply(const cMatrix2 &M)
{  /* Assume for now that the bottom row of matrix is always 0 0 1.
	This operation effectively does the scaling and rotation, followed by the
	translation. It's important here to use the dummy tempx, otherwise the
	_x you use in the definitino of _y is already the updated x value and you
	get a wrong result. */
	cVector2 self(*this);
	*this = M * self;
}

cVector2 cVector2::turn(Real turnangle) //Rotate the vector by turnangle
{
	if (!turnangle)
		return *this;
	apply(cMatrix2::zRotation(turnangle));
	return *this;
}

cVector2 cVector2::rotate(const cSpin &spin)
{
	if (!spin.spinangle())
		return *this;
	apply(cMatrix2::rotation(spin));
	return *this;
}


Real cVector2::distanceTo(const cVector2 &v) const
{
	Real dx = _x - v._x, dy = _y - v._y;
	return sqrt(dx*dx + dy*dy);
} 

//--------------Friend functions for cVector2-------------
Real distance(const cVector2 &u, const cVector2 &v)
{
	Real dx = u._x - v._x, dy = u._y - v._y;
	return sqrt(dx*dx + dy*dy);
} 

Real angleBetween(const cVector2 &u, const cVector2 &v)
{/* Use fact that dot product of two vectors is the cosine of the angle between them.  Always returns
an acute angle, between 0.0 and PI. */
	Real umag = u.magnitude();
	Real vmag = v.magnitude();
	if (!umag || !vmag)  //If either is a zero vector, just return a zero angle.
		return 0.0;
	Real cosine = u%v/(umag*vmag);
	CLAMP(cosine, -1.0, 1.0);
	return acos(cosine);
}

cVector2 cVector2::defaultNormal()
{
	if (_x != 0.0 || _y != 0.0)
		return cVector2(-_y, _x, 0.0);  
	else //always return nonzero vector.
		return cVector2(0.0, 1.0);
}

cVector2 operator*(const cVector2 &u, Real f) //Scalar prod
{
	return cVector2(u._x * f,	u._y * f);
}

cVector2 operator/(const cVector2 &u, Real f) //Scalar division
{
	return cVector2(u._x / f,	u._y / f);
}

cVector2 operator*(Real f, const cVector2 &u) //Scalar prod
{
	return cVector2(u._x * f, u._y * f);
}

cVector2 operator+(const cVector2 &u, const cVector2 &v)
{
	return cVector2(u._x + v._x, u._y + v._y);
}

cVector2 operator-(const cVector2 &u, const cVector2 &v)
{
	return cVector2(u._x - v._x, u._y - v._y);
}

Real operator%(const cVector2 &u, const cVector2 &v)
{
	return (u._x*v._x + u._y*v._y);
}

cVector3 operator*(const cVector2 &u, const cVector2 &v) //Fake cross product for interfact consistency.
{
	if (u.isZero() || v.isZero())
		return cVector3::ZEROVECTOR;
	else
		return (cVector3(0.0, 0.0, 1.0));
}

/* The following  friend operations is used to multiply
   in the transformation on the right, as in V = M * U. */

cVector2 operator*(const cMatrix2 &M, const cVector2 &v)
{  /* Assume for now that the bottom row of matrix is always 0 0 1.
	This operation effectively does the scaling and rotation, followed by the
	translation. */
	cVector2 u;
	u._x = v._x * M._mat[0][0] + v._y * M._mat[0][1] + M._mat[0][2];
	u._y = v._x * M._mat[1][0] + v._y * M._mat[1][1] + M._mat[1][2];
	return u;
}

//----------CArchive friend functions for cVector2------------------

CArchive& operator<<(CArchive& ar, const cVector2 &v)
{
	ar << v._x << v._y;
	return ar;	
}

CArchive& operator>>(CArchive& ar, cVector2 & v)
{
	ar >> v._x >> v._y;
	return ar;
}

void cVector2::Serialize(CArchive &ar)
{
	if (ar.IsStoring()) //Writing data.
 		ar <<  *this;
 	else //Reading data.
 		ar >> *this;
}

//------------------cVector3 methods-------------------
cVector3 cVector3::randomUnitVector()
{
	Real vx, vy, vz;
	cRandomizer::pinstance()->randomUnitTriple(&vx, &vy, &vz);
	return cVector3(vx, vy, vz);
}

cVector3 cVector3::operator/=(Real f)
{
	if (fabs(f) >= SMALL_REAL)
	{
		_x/=f;
		_y/=f;
		_z/=f;
	}
	return *this;
}

Real cVector3::magnitude() const
{
	return sqrt(_x*_x + _y*_y + _z*_z);
}

Real cVector3::angle() const
{ //Just copy the cVector2 code.
	Real ang = atan2(_y, _x); //Note that atan2 takes the args in reverse order.
	//This will range between -pi and pi, and I prefer 0 to 2pi, so I fix this.
	if (ang < 0.0)
		ang += 2*PI;
	if (ang == 2*PI)
		ang = 0.0;
	return ang;
}

cVector3 cVector3::normalize()
{ //Make the cVector3 a unit cVector3, and return self
	Real m = magnitude();
	if (m < SMALL_REAL)
	{
		_x = 1.0;
		_y = 0;
		_z = 0;
		m = 0.0;
	}
	else
	{
		_x /= m;
		_y /= m;
		_z /= m;
	}
	//	return m; //Used to return magnitude
	return *this;
}

Real cVector3::normalizeAndReturnMagnitude() //Make yourself of unit length and return mag.
{ 
	Real m = magnitude();
	if (m < SMALL_REAL)
	{
		_x = 1.0;
		_y = 0;
		_z = 0;
		m = 0.0;
	}
	else
	{
		_x /= m;
		_y /= m;
		_z /= m;
	}
	return m; 
}

cVector3 cVector3::roundOff()
{
	if (fabs(_x) < SMALL_REAL)
		_x = 0.0;
	if (fabs(_y) < SMALL_REAL)
		_y = 0.0;
	if (fabs(_z) < SMALL_REAL)
		_z = 0.0;
	return *this;
}


cVector3 cVector3::direction() const
{ //Make a unit cVector3, and return it
	Real m = magnitude();
	cVector3 dir = *this;
	if (m < SMALL_REAL)
	{
		dir._x = 1.0;
		dir._y = 0;
		dir._z = 0;
	}
	else
	{
		dir._x /= m;
		dir._y /= m;
		dir._z /= m;
	}
	return dir;
}

void cVector3::setMagnitude(Real mag) //Make your length be mag
{
	normalize();
	_x *= mag;
	_y *= mag;
	_z *= mag;
}

void cVector3::apply(const cMatrix3 &M)
{  /* Assume for now that the bottom row of matrix is always 0 0 0 1.
	This operation effectively does the scaling and rotation, followed by the
	translation. Its important to use the dummy tempx and tempy otherwise the
	update values get used prematurely in the _y and _z updates. */
	Real tempx, tempy;
	tempx = _x * M._mat[0][0] + _y * M._mat[0][1] + _z * M._mat[0][2] + M._mat[0][3];
	tempy = _x * M._mat[1][0] + _y * M._mat[1][1] + _z * M._mat[1][2] + M._mat[1][3];
	_z = _x * M._mat[2][0] + _y * M._mat[2][1] + _z * M._mat[2][2] +	M._mat[2][3];
	_x = tempx;
	_y = tempy;
}

Real cVector3::distanceTo(const cVector3 &v) const
{
	Real dx = _x - v._x, dy = _y - v._y, dz = _z - v._z;
	return sqrt(dx*dx + dy*dy + dz*dz);
} 

cVector3 cVector3::turn(Real angle)
{
	return rotate(cSpin(angle)); //Real constructor assumes rotation around Z axis.
}

cVector3 cVector3::rotate(const cSpin &spin)
{
	if (!spin.spinangle())
		return *this;
	apply(cMatrix3::rotation(spin));
	return *this;
}
//--------------Friend functions for cVector3-------------

Real distance(const cVector3 &u, const cVector3 &v)
{
	Real dx = u._x - v._x, dy = u._y - v._y, dz = u._z - v._z;
	return sqrt(dx*dx + dy*dy + dz*dz);
} 

Real angleBetween(const cVector3 &u, const cVector3 &v)
{
/* Use fact that dot product of two vectors is the cosine of the angle between them.  Always returns
an acute angle, between 0.0 and PI. */
	Real umag = u.magnitude();
	Real vmag = v.magnitude();
	if (!umag || !vmag)  //If either is a zero vector, just return a zero angle.
		return 0.0;
	Real cosine = u%v/(umag*vmag);
	CLAMP(cosine, -1.0, 1.0);
	return acos(cosine);
}

cVector3 cVector3::defaultNormal()
{
	if (_x != 0.0 || _y != 0.0)
		return cVector3(-_y, _x, 0.0);  
	else //it points along z axis up or down.
		return cVector3(1.0, 0.0, 0.0);
}


cVector3 operator*(const cVector3 &u, Real f) //Scalar prod
{
	return cVector3(u._x * f, u._y * f, u._z * f);
}

cVector3 operator/(const cVector3 &u, Real f) //Scalar division
{
	return cVector3(u._x / f, u._y / f, u._z / f);
}

cVector3 operator*(Real f, const cVector3 &u) //Scalar prod
{
	return cVector3(u._x * f, u._y * f, u._z * f);
}

cVector3 operator+(const cVector3 &u, const cVector3 &v)
{
	return cVector3(u._x + v._x, u._y + v._y, u._z + v._z);
}

cVector3 operator-(const cVector3 &u, const cVector3 &v)
{
	return cVector3(u._x - v._x, u._y - v._y, u._z - v._z);
}

Real operator%(const cVector3 &u, const cVector3 &v)
{
	return (u._x*v._x + u._y*v._y + u._z*v._z);
}

cVector3 operator*(const cVector3 &u, const cVector3 &v)
{
	return cVector3(u._y*v._z - u._z*v._y, -u._x*v._z + u._z*v._x,
		u._x*v._y - u._y*v._x);
}

/* The following  friend operation is used to multiply
   in the transformation on the right, as in V = M * U. */

cVector3 operator*(const cMatrix3 &M, const cVector3 &V)
{  //Assume for now that the bottom row of matrix is always 0 0 0 1
	cVector3 U;
	U._x = V._x * M._mat[0][0] + V._y * M._mat[0][1] + V._z * M._mat[0][2] + M._mat[0][3];
	U._y = V._x * M._mat[1][0] + V._y * M._mat[1][1] + V._z * M._mat[1][2] + M._mat[1][3];
	U._z = V._x * M._mat[2][0] + V._y * M._mat[2][1] + V._z * M._mat[2][2] +	M._mat[2][3];
	return U;
}

//----------CArchive friend functions for cVector3------------------

CArchive& operator<<(CArchive& ar, const cVector3 &v)
{
	ar << v._x << v._y << v._z;
	return ar;	
}

CArchive& operator>>(CArchive& ar, cVector3 & v)
{
	ar >> v._x >> v._y >> v._z;
	return ar;
}

void cVector3::Serialize(CArchive &ar)
{
	if (ar.IsStoring()) //Writing data.
 		ar <<  *this;
 	else //Reading data.
 		ar >> *this;
}
//----Matrix Stuff-----------------------------------------

//----------cMatrix2 operations----------------

cMatrix2::cMatrix2(Real e00, Real e10, Real e20, Real e01, Real e11, Real e21,
	Real e02, Real e12, Real e22)
{
	set(e00, e10, e20, e01, e11, e21, e02, e12, e22);
}

void cMatrix2::set(Real e00, Real e10, Real e20, Real e01, Real e11, Real e21,
	Real e02, Real e12, Real e22)
{ 
	_mat[0][0] = e00;
	_mat[1][0] = e10;
	_mat[2][0] = e20;
	_mat[0][1] = e01;
	_mat[1][1] = e11;
	_mat[2][1] = e21;
	_mat[0][2] = e02;
	_mat[1][2] = e12;
	_mat[2][2] = e22;
}

cMatrix2::cMatrix2(cVector2 col0, cVector2 col1, cVector2 col2)
{ 
	_mat[0][0] = col0.x();
	_mat[1][0] = col0.y();
	_mat[2][0] = 0.0;
	_mat[0][1] = col1.x();
	_mat[1][1] = col1.y();
	_mat[2][1] = 0.0;
	_mat[0][2] = col2.x();
	_mat[1][2] = col2.y();
	_mat[2][2] = 1.0;
}

cMatrix2::cMatrix2(cVector2 col0, cVector2 col1, cVector2 col2, cVector2 col3)
{ /* Note that we IGNORE col2 and USE col3.  This is not a typo, I really mean to ignore col2, the 
	second to last argument. This is because we normally feed in the args tangent, normal,
	(meaningless in 2D) binormal, and position.  */
	_mat[0][0] = col0.x();
	_mat[1][0] = col0.y();
	_mat[2][0] = 0.0;
	_mat[0][1] = col1.x();
	_mat[1][1] = col1.y();
	_mat[2][1] = 0.0;
	_mat[0][2] = col3.x();
	_mat[1][2] = col3.y();
	_mat[2][2] = 1.0;
}

cMatrix2::cMatrix2(const cMatrix2 &M)
{
	copy(M);
}

cMatrix2& cMatrix2::operator=(const cMatrix2 &M)
{
	copy(M);
	return *this;
}

void cMatrix2::copy(const cMatrix2 &M)
{
	Real *target = (Real*)_mat;
	Real *source = (Real*)(M._mat);
	for (int k=0; k<9; k++)
		target[k] = source[k];
}

void cMatrix2::identity()
{
	for (int i=0; i<3; i++)
		for (int j=0; j<3; j++)
			_mat[i][j] = (i==j)?1:0;
}

void cMatrix2::orthonormalize()
{
	cVector2 tan = column(0), norm = column(1);
	tan.normalize();
	norm -= (norm%tan) * tan;
	norm.normalize();
	ASSERT(fabs(norm%tan) < cVector2::PRACTICALLY_ZERO); //should be zero
	setColumn(0, tan);
	setColumn(1, norm);
}

void cMatrix2::setColumn(int j , const cVector2 &u)
{
		_mat[0][j] = u._x;
		_mat[1][j] = u._y;
}

cVector2 cMatrix2::column(int i) const
{
	ASSERT(0<=i && i<= 2);
	return cVector2(_mat[0][i], _mat[1][i]);
}	


void cMatrix2::setRotationAndScale(Real ang, Real sc)
{ //This transformation does the Rotation and Scale
	_mat[0][0] = sc*cos(ang);
	_mat[0][1] = -sc*sin(ang);
	_mat[1][0] = sc*sin(ang);
	_mat[1][1] = sc*cos(ang);
}

void cMatrix2::translate(cVector2 trans)
{
	_mat[0][2] += trans.x();
	_mat[1][2] += trans.y();
}

void cMatrix2::setRotationAndScaleAboutCenter(cVector2 center, Real ang, Real sc)
{ /* This transformation does the Rotation and Scale about center.  Because these
	transformations are linear, we can do the scale and rotation and then do 
	a translation to undo the motion caused the rotation and scaling of the center
	point by the scale and rotation. */
	cVector2 centerimage(center);
	setRotationAndScale(ang, sc);
	_mat[0][2] = _mat[1][2] = 0.0;
	centerimage.apply(*this);
	translate(center - centerimage);
}

cMatrix2 operator*(const cMatrix2 &K, const cMatrix2 &L)
{ //Assume for now that the bottom row of the matrix is always 0 0 1
	cMatrix2 M;

	for (int i=0; i<2; i++)
		for (int j=0; j<3; j++)
		{
			M._mat[i][j] = 0.0;
			for (int k=0; k<3; k++)
				M._mat[i][j] += K._mat[i][k]*L._mat[k][j];
		}
	return M;
}

cMatrix2& cMatrix2::operator*=(const cMatrix2 &M)
{ //Assume for now that the bottom row of the matrix is always 0 0 1
	cMatrix2 self(*this);
	copy(self*M);
	return *this;
}

cMatrix2 cMatrix2::transpose()
{
	cMatrix2 transpose;
	for (int i=0; i<3; i++)
		for (int j=0; j<3; j++)
			transpose._mat[i][j] = _mat[j][i];
	return transpose;
}

cMatrix2 cMatrix2::inverse()
{ /*This only works if we assume the matrix is a rigid-body matrix, i.e.
that its cVector2 columns are orthonormal unit vectors as are its cVector2
rows (,ignoring the third column.)  You can have any translation you
like in the third column. See comment on cMatrix2::rigidBodyINverse. */
	cMatrix2 inv;

	for (int i=0; i<2; i++)
		for (int j=0; j<2; j++)
		{
			inv._mat[i][j] = _mat[j][i];
			inv._mat[i][2] -= inv._mat[i][j]*_mat[j][2];
		}
	return inv;
}

cMatrix2 cMatrix2::normalTransformation()
{ /*See the comment on cMatrix3::rigidBodyNormalTransformation() for an explanation of this. */
	return inverse().transpose();
}

//------STatic factory method

cMatrix2 cMatrix2::zRotation(Real ang)
{ //Rotate x-axis towards y-axis by ang radians.
	cMatrix2 M;

	M._mat[0][0] = cos(ang);
	M._mat[0][1] = -sin(ang);
	M._mat[1][0] = -M._mat[0][1]; //sin(ang)
	M._mat[1][1] = M._mat[0][0]; //cos(ang)
	return M;
}

cMatrix2 cMatrix2::rotation(const cSpin &spin)
{ //Rotate x-axis towards y-axis by ang radians.
	cMatrix2 M;
	if (!spin.spinangle())
		return M; //identity.
	M._mat[0][0] = cos(spin.spinangle());
	M._mat[0][1] = -sin(spin.spinangle());
	M._mat[1][0] = -M._mat[0][1]; //sin(spin.spinangle())
	M._mat[1][1] = M._mat[0][0]; //cos(spin.spinangle())
	return M;
}

cMatrix2 cMatrix2::rotationFromUnitToUnit(const cVector2 &u, const cVector2 &v)
{
	/* ONly call this on unit vectors as arguments.  The components of u are cos and sin of
	the angle a that u makes with the x axis.  The components of v are cos and sin of angle b
	that v mkes with the x-axis.  We want to turn counterclockwise by the angle b-a. So now
	we get the componetns of the turnangle b-a.*/
	Real turncos = v._x * u._x + v._y * u._y; /* Use the trig formula for
	 cos(b - a)= cosb cosa + sinb sina */
	Real turnsin = v._y * u._x - v._x * u._y; //sin(b-a) = sinb cosa - cosb sina
	//Make a z-rotation matrix.  Remember that the constructor args go in by columns.
	return cMatrix2(turncos, turnsin, 0.0, //col0
	 -turnsin, turncos, 0.0, //col1
	 0.0, 0.0, 1.0); //col2
}

cMatrix2 cMatrix2::translation(const cVector2 &trans)
{
	cMatrix2 M;

	M._mat[0][2] = trans.x();
	M._mat[1][2] = trans.y();
	return M;
}

cMatrix2 cMatrix2::scale(Real scalefactor)
{
	cMatrix2 M;

	M._mat[0][0] = scalefactor;
	M._mat[1][1] = scalefactor;
	return M;
}

Real cMatrix2::scalefactor() const//How much scaling does this do?  Assume isotropic, so test on unit vector of XAXIS
{
	cVector2 uvectorimage(_mat[0][0], _mat[1][0]);
	return uvectorimage.magnitude();	
}


//----------CArchive friend functions for cMatrix2------------------

CArchive& operator<<(CArchive& ar, const cMatrix2 &M)
{
	for (int i=0; i<3; i++)
		for (int j=0; j<3; j++)
			ar << M._mat[i][j];
	return ar;	
}

CArchive& operator>>(CArchive& ar, cMatrix2 & M)
{
	for (int i=0; i<3; i++)
		for (int j=0; j<3; j++)
			ar >> M._mat[i][j];
	return ar;
}

void cMatrix2::Serialize(CArchive &ar)
{
	if (ar.IsStoring()) //Writing data.
 		ar <<  *this;
 	else //Reading data.
 		ar >> *this;
}
//----------cMatrix3 operations----------------
cMatrix3::cMatrix3(Real e00, Real e10, Real e20, Real e30, Real e01, Real e11, Real e21, Real e31,
	Real e02, Real e12, Real e22, Real e32, Real e03, Real e13, Real e23, Real e33)
{
	set(e00, e10, e20, e30, e01, e11, e21, e31,	e02, e12, e22, e32, e03, e13, e23, e33);
}

cMatrix3::cMatrix3(Real *vert)
{
	set(vert);
}

void cMatrix3::set(Real *vert)
{
	set(vert[ 0], vert[ 1], vert[ 2], vert[ 3], vert[ 4], vert[ 5], vert[ 6], vert[ 7], 
		vert[ 8], vert[ 9], vert[10], vert[11], vert[12], vert[13], vert[14], vert[15]);
}

void cMatrix3::set(Real e00, Real e10, Real e20, Real e30, Real e01, Real e11, Real e21, Real e31,
	Real e02, Real e12, Real e22, Real e32, Real e03, Real e13, Real e23, Real e33)
{ 
	_mat[0][0] = e00;
	_mat[1][0] = e10;
	_mat[2][0] = e20;
	_mat[3][0] = e30;
	_mat[0][1] = e01;
	_mat[1][1] = e11;
	_mat[2][1] = e21;
	_mat[3][1] = e31;
	_mat[0][2] = e02;
	_mat[1][2] = e12;
	_mat[2][2] = e22;
	_mat[3][2] = e32;
	_mat[0][3] = e03;
	_mat[1][3] = e13;
	_mat[2][3] = e23;
	_mat[3][3] = e33;
}

cMatrix3::cMatrix3(cVector3 col0, cVector3 col1, cVector3 col2, cVector3 col3)
{
	_mat[0][0] = col0.x();
	_mat[1][0] = col0.y();
	_mat[2][0] = col0.z();
	_mat[3][0] = 0.0;
	_mat[0][1] = col1.x();
	_mat[1][1] = col1.y();
	_mat[2][1] = col1.z();
	_mat[3][1] = 0.0;
	_mat[0][2] = col2.x();
	_mat[1][2] = col2.y();
	_mat[2][2] = col2.z();
	_mat[3][2] = 0.0;
	_mat[0][3] = col3.x();
	_mat[1][3] = col3.y();
	_mat[2][3] = col3.z();
	_mat[3][3] = 1.0;
}

cMatrix3::cMatrix3(const cMatrix3 &M)
{
	copy(M);
}

cMatrix3& cMatrix3::operator=(const cMatrix3 &M)
{
	copy(M);
	return *this;
}

void cMatrix3::copy(const cMatrix3 &M)
{
	Real *target = (Real*)_mat;
	Real *source = (Real*)(M._mat);
	for (int k=0; k<16; k++)
		target[k] = source[k];
}

cMatrix3::cMatrix3(const cMatrix2 &M)
{
	_mat[0][0] = M._mat[0][0];
	_mat[1][0] = M._mat[1][0];
	_mat[2][0] = 0.0;
	_mat[3][0] = 0.0;
	_mat[0][1] = M._mat[0][1];
	_mat[1][1] = M._mat[1][1];
	_mat[2][1] = 0.0;
	_mat[3][1] = 0.0;
	_mat[0][2] = 0.0;
	_mat[1][2] = 0.0;
	_mat[2][2] = 1.0;
	_mat[3][2] = 0.0;
	_mat[0][3] = M._mat[0][2];
	_mat[1][3] = M._mat[1][2];
	_mat[2][3] = 0.0;
	_mat[3][3] = 1.0;
}

void cMatrix3::identity()
{
	for (int i=0; i<4; i++)
		for (int j=0; j<4; j++)
			_mat[i][j] = (i==j)?1:0;
}

void cMatrix3::orthonormalize()
{
	cVector3 tan = column(0), norm = column(1), binorm = column(2);
	tan.normalize();
	norm -= (norm%tan) * tan;
	norm.normalize();
   // removed error: Joseph E. Sutton
	//ASSERT(fabs(norm%tan) < cVector3::PRACTICALLY_ZERO && "Failure in cMatrix3::orthonormalize."); //should be zero
   fabs(norm%tan);
	binorm = tan*norm;
	setColumn(0, tan);
	setColumn(1, norm);
	setColumn(2, binorm);
}

cVector3 cMatrix3::column(int i) const
{
	ASSERT(0<=i && i<= 3);
	return cVector3(_mat[0][i], _mat[1][i], _mat[2][i]);
}	

Real cMatrix3::scalefactor() const//How much scaling does this do?  Assume isotropic, so test on unit vector of XAXIS
{
	cVector3 uvectorimage(_mat[0][0], _mat[1][0], _mat[2][0]);
	return uvectorimage.magnitude();	
}

void cMatrix3::setColumn(int j, const cVector3 &u)
{
		_mat[0][j] = u._x;
		_mat[1][j] = u._y;
		_mat[2][j] = u._z;
}

cMatrix3 cMatrix3::inverse()
{ /*This only works if we assume the matrix is a rigid-body matrix, i.e.
that its cVector3 columns are orthonormal unit vectors as are its cVector3
rows (,ignoring the foruth column.)  You can have any translation you
like in the fourth column.  The inverse of such a matrix just takes the
transpose of the 3x3 rotational part, and then adjusts the fourth column
so that the matrix product will give zeroes there.  Thanks to Bob Holt
of Autodesk for showing me this trick.*/
	cMatrix3 inv; //default constructor sets it to identity.
	for (int i=0; i<3; i++)
		for (int j=0; j<3; j++)
		{
			inv._mat[i][j] = _mat[j][i];
			inv._mat[i][3] -= inv._mat[i][j]*_mat[j][3];
		}
	return inv;
}

void cMatrix3::translate(const cVector3 &trans)
{
	_mat[0][3] += trans.x();
	_mat[1][3] += trans.y();
	_mat[2][3] += trans.z();
}

cMatrix3 operator*(const cMatrix3 &K, const cMatrix3 &L)
{ //Assume for now that the bottom row of the matrix is always 0 0 0 1
	cMatrix3 M;

	for (int i=0; i<3; i++)
		for (int j=0; j<4; j++)
		{
			M._mat[i][j] = 0.0;
			for (int k=0; k<4; k++)
				M._mat[i][j] += K._mat[i][k]*L._mat[k][j];
		}
	return M;
}

cMatrix3& cMatrix3::operator*=(const cMatrix3 &M)
{ //Assume for now that the bottom row of the matrix is always 0 0 1
	cMatrix3 product = (*this)*M;
	copy(product);
#ifdef TRACEPRODUCT
	Real *aelements = product.transpose().elements();
	TRACE("product (*this)*M in operator*=(M).\n");
	TRACE("%f  %f  %f  %f\n", aelements[0], aelements[4], aelements[8], aelements[12]);
	TRACE("%f  %f  %f  %f\n", aelements[1], aelements[5], aelements[9], aelements[13]);
	TRACE("%f  %f  %f  %f\n", aelements[2], aelements[6], aelements[10], aelements[14]);
	TRACE("%f  %f  %f  %f\n", aelements[3], aelements[7], aelements[11], aelements[15]);
	cMatrix copyM(M);
	aelements = copyM.transpose().elements();
	TRACE("copyM matrix in *=(M).\n");
	TRACE("%f  %f  %f  %f\n", aelements[0], aelements[4], aelements[8], aelements[12]);
	TRACE("%f  %f  %f  %f\n", aelements[1], aelements[5], aelements[9], aelements[13]);
	TRACE("%f  %f  %f  %f\n", aelements[2], aelements[6], aelements[10], aelements[14]);
	TRACE("%f  %f  %f  %f\n", aelements[3], aelements[7], aelements[11], aelements[15]);
	aelements = transpose().elements();
	TRACE("*this matrix at end of *=(M).\n");
	TRACE("%f  %f  %f  %f\n", aelements[0], aelements[4], aelements[8], aelements[12]);
	TRACE("%f  %f  %f  %f\n", aelements[1], aelements[5], aelements[9], aelements[13]);
	TRACE("%f  %f  %f  %f\n", aelements[2], aelements[6], aelements[10], aelements[14]);
	TRACE("%f  %f  %f  %f\n", aelements[3], aelements[7], aelements[11], aelements[15]);
#endif //TRACEPRODUCT

	return *this;
}

cMatrix3 cMatrix3::transpose()
{
	cMatrix3 transpose;
	for (int i=0; i<4; i++)
		for (int j=0; j<4; j++)
			transpose._mat[i][j] = _mat[j][i];
	return transpose;
}

cMatrix3 cMatrix3::normalTransformation()
{ /*As with inverse we should only call this on a rigid-body matrix,  i.e. on
	a matrix such that its cVector3 columns are orthonormal unit vectors, as are its cVector3
	rows (,ignoring the foruth column.)  You can have any translation you like in the fourth
	column. as define in the fourth column.  The idea here is that if tan' = mat*tan, and normal
	was the normal to tan, we want to find the right value for the nmat so that norm' = N*norm.
	Note that here I'm using mat and nmat to stand for matrices, the first is this caller matrix,
	the second is the matrix I want to return.  I'll also use matinverse to stand for 
	mat.inverse().
	We know norm%tan is 0, using our dot product symbol %.  Suppose we write a varaible in CAPITALS
	to mean the transpose (flip of the ij positions). We think of our cVector3 as column vectors,
	so NORM would be a row vector, and we could write the dot product norm%tan as NORM*tan, where
	we think of * as ordinary matrix multiplication.
	NORM*tan = 0, since norm and tan are perpendicular.
	NORM*matinverse*mat*tan = 0, since matinverse*mat is the identity.
	(NORM*matinverse)*tan' = 0, since tan1 = mat*tan.
	NORM' = NORM*matinverse, since NORM' is to be the normal to tan'.
	norm' = MATINVERSE*norm, since for matrices, transpose(b)*transpose(a) = transpose(a*b),
		and transpose(transpose(a)) = a.
	So we return the transpose of the inverse.  After all this work, note that if
	the fourth column of _mat is just 0001, then the matrix returned is just _mat! */
	return inverse().transpose();
}

//Static factory methods-------------------------------

cMatrix3 cMatrix3::xRotation(Real ang)
{ //Rotate y-axis towards z-axis by ang radians.  Pos rot bucks y "up" and z "down".
	cMatrix3 M;

	M._mat[1][1] = cos(ang);
	M._mat[1][2] = -sin(ang);
	M._mat[2][1] = sin(ang);
	M._mat[2][2] = cos(ang);
	return M;
}

cMatrix3 cMatrix3::yRotation(Real ang)
{ //Rotate z-axis towards x-axis by ang radians.  Pos rot bucks z "up, x axis "down".
	cMatrix3 M;

	M._mat[0][0] = cos(ang);
	M._mat[0][2] = sin(ang); //I switched the sign of this to make this match Matrix3::rotation.
	M._mat[2][0] = -sin(ang); //swithced this too.
	M._mat[2][2] = cos(ang);
	return M;
}

cMatrix3 cMatrix3::zRotation(Real ang)
{ //Rotate x-axis towards y-axis by ang radians. Pos rot bucks y "down".
	cMatrix3 M;

	M._mat[0][0] = cos(ang);
	M._mat[0][1] = -sin(ang);
	M._mat[1][0] = -M._mat[0][1]; //sin(ang)
	M._mat[1][1] = M._mat[0][0]; //cos(ang)
	return M;
}

cMatrix3 cMatrix3::rotation(const cSpin &spin)
{
	if (!spin.spinangle())
		return cMatrix3(); //identity.
#ifdef USESPINAXISTYPE
	if (spin.axistype() == cSpin::ZAXISTYPE)
		return zRotation(spin.spinangle());
	else if (spin.axistype() == cSpin::XAXISTYPE)
		return xRotation(spin.spinangle());
	else if (spin.axistype() == cSpin::YAXISTYPE)
		return yRotation(spin.spinangle());
	else //(spin.axistype() == cSpin::ARBITRARYAXISTYPE)
	{
#endif //USESPINAXISTYPE
#ifndef USEOPENGLENGINE //This is preferred, as you may not always have an OpenGl engine available.
		Real c = cos(spin.spinangle());
		Real ccomp = 1.0 - c;
		Real s = sin(spin.spinangle());
		Real x = spin.spinaxis().x();	
		Real y = spin.spinaxis().y();	
		Real z = spin.spinaxis().z();
			/* Now feed in the numbers a column at a time (not a row at a time, as our cMatrix3 
			constructor	gets fed by columns).  I copied these formulae from the glRotate entry of the
			OpenGL Reference Manual, and triple checked I got it right. Note that since we feed in by 
			columns, what you see here is the transpose of what you see in the Manual. */
#ifdef TRACEROTATION
			cMatrix3 M(
			x*x*ccomp+c,   x*y*ccomp+z*s, x*z*ccomp-y*s, 0.0,
			x*y*ccomp-z*s, y*y*ccomp+c,   y*z*ccomp+x*s, 0.0,
			x*z*ccomp+y*s, y*z*ccomp-x*s, z*z*ccomp+c,   0.0,
			0.0,           0.0,           0.0,           1.0);
			Real *aelements = M.transpose().elements();
			TRACE("\n\nArbitrary rotation matrix around axis (%f, %f, %f) by  %f radians\n",
				 x, y, z, spin.spinangle());
			TRACE("%f  %f  %f  %f\n", aelements[0], aelements[4], aelements[8], aelements[12]);
			TRACE("%f  %f  %f  %f\n", aelements[1], aelements[5], aelements[9], aelements[13]);
			TRACE("%f  %f  %f  %f\n", aelements[2], aelements[6], aelements[10], aelements[14]);
			TRACE("%f  %f  %f  %f\n\n", aelements[3], aelements[7], aelements[11], aelements[15]);
			return M;
#else //not TRACEROTATION
		return cMatrix3(
			x*x*ccomp+c,   x*y*ccomp+z*s, x*z*ccomp-y*s, 0.0,
			x*y*ccomp-z*s, y*y*ccomp+c,   y*z*ccomp+x*s, 0.0,
			x*z*ccomp+y*s, y*z*ccomp-x*s, z*z*ccomp+c,   0.0,
			0.0,           0.0,           0.0,           1.0);
#endif //TRACROTATION
#else //USEOPENGLENGINE
		cMatrix3 M;
		Real angle = spin.spinangle()*180.0/PI; //convert to degrees for OpenGL
		float verts[16];
		int oldmatrixmode;
		::glGetIntegerv(GL_MATRIX_MODE, &oldmatrixmode);
		::glMatrixMode(GL_MODELVIEW);
		::glPushMatrix();
		::glLoadIdentity();
		::glRotatef(angle, spin.spinaxis().x(), spin.spinaxis().y(), spin.spinaxis().z());
		::glGetFloatv(GL_MODELVIEW_MATRIX, verts);
		::glPopMatrix();
		::glMatrixMode(oldmatrixmode);
		M.set(verts);
		return M;
#endif //USEOPENGLENGINE switch
#ifdef USESPINAXISTYPE
	}
#endif //USESPINAXISTYPE
}

cMatrix3 cMatrix3::rotationFromUnitToUnit(const cVector3 &u, const cVector3 &v)
{ 
	cMatrix3 M; //Identity to start with
	Real angle = angleBetween(u, v); //Will be 0 if either vector is zero or if they point the same way.
	if (!angle)
		return M; //return the identity in the degenerate cases.
	cVector3 axis = u*v; //We don't need to normalize as cSpin consturctor or OpenGL will normalize.
#ifndef USEOPENGLENGINE //Use our own algorithm.
	M = cMatrix3::rotation(cSpin(angle, axis));
#else // The USEOPENGLENGINE case
	angle *= 180.0/PI; //Convert to degrees.
	float verts[16];
	int oldmatrixmode;
	::glGetIntegerv(GL_MATRIX_MODE, &oldmatrixmode);
	::glMatrixMode(GL_MODELVIEW);
	::glPushMatrix();
	::glLoadIdentity();
	::glRotatef(angle, axis.x(), axis.y(), axis.z());  
	::glGetFloatv(GL_MODELVIEW_MATRIX, verts);
	::glPopMatrix();
	::glMatrixMode(oldmatrixmode);
	M.set(verts);
#endif //USEOPENGLENGINE
#ifdef TRACEUNITTOUNIT
	Real *aelements = M.transpose().elements();
	TRACE("unittounit rotation matrix using OpenGL.  Unreliable?\n");
	TRACE("from (%f, %f, %f) to  (%f, %f, %f)\n", u.x(), u.y(), u.z(), 
		v.x(), v.y(), v.z());
	TRACE("%f  %f  %f  %f\n", aelements[0], aelements[4], aelements[8], aelements[12]);
	TRACE("%f  %f  %f  %f\n", aelements[1], aelements[5], aelements[9], aelements[13]);
	TRACE("%f  %f  %f  %f\n", aelements[2], aelements[6], aelements[10], aelements[14]);
	TRACE("%f  %f  %f  %f\n", aelements[3], aelements[7], aelements[11], aelements[15]);
	TRACE("axis.x %f axis.y %f axis.z %f angle %f \n", axis.x(), axis.y(), axis.z(), angle);
#endif //TRACEUNITTOUNIT
	return M;
}

cMatrix3 cMatrix3::translation(const cVector3 &trans)
{
	cMatrix3 M;

	M._mat[0][3] = trans.x();
	M._mat[1][3] = trans.y();
	M._mat[2][3] = trans.z();
	return M;
}

cMatrix3 cMatrix3::scale(Real scalefactor)
{
	cMatrix3 M;

	M._mat[0][0] = scalefactor;
	M._mat[1][1] = scalefactor;
	M._mat[2][2] = scalefactor;
	return M;
}

cMatrix3 cMatrix3::scale(Real xscale, Real yscale, Real zscale)
{
	cMatrix3 M;

	M._mat[0][0] = xscale;
	M._mat[1][1] = yscale;
	M._mat[2][2] = zscale;
	return M;
}



//----------CArchive friend functions for cMatrix3------------------

CArchive& operator<<(CArchive& ar, const cMatrix3 &M)
{
	for (int i=0; i<4; i++)
		for (int j=0; j<4; j++)
			ar << M._mat[i][j];
	return ar;	
}

CArchive& operator>>(CArchive& ar, cMatrix3 & M)
{
	for (int i=0; i<4; i++)
		for (int j=0; j<4; j++)
			ar >> M._mat[i][j];
	return ar;
}

void cMatrix3::Serialize(CArchive &ar)
{
	if (ar.IsStoring()) //Writing data.
 		ar <<  *this;
 	else //Reading data.
 		ar >> *this;
}


//============== cSpin===================
//----------CArchive friend functions for cMatrix3------------------


cSpin::cSpin(cVector spinvector):_spinaxis(spinvector), _axistype(ARBITRARYAXISTYPE)
{
	_spinangle = _spinaxis.magnitude();
	_spinaxis.normalize();
#ifdef USESPINAXISTYPE
	if (_spinaxis == cVector3(1.0, 0.0, 0.0)) _axistype=XAXISTYPE;
	if (_spinaxis == cVector3(0.0, 1.0, 0.0)) _axistype=YAXISTYPE;
	if (_spinaxis == cVector3(0.0, 0.0, 1.0)) _axistype=ZAXISTYPE;
#endif //USESPINAXISTYPE
}

cSpin::cSpin(Real spinangle, cVector spinaxis):_spinangle(spinangle), _spinaxis(spinaxis),
	_axistype(ARBITRARYAXISTYPE)
{
	_spinaxis.normalize();
#ifdef USESPINAXISTYPE
	if (_spinaxis == cVector3(1.0, 0.0, 0.0)) _axistype=XAXISTYPE;
	if (_spinaxis == cVector3(0.0, 1.0, 0.0)) _axistype=YAXISTYPE;
	if (_spinaxis == cVector3(0.0, 0.0, 1.0)) _axistype=ZAXISTYPE;
#endif //USESPINAXISTYPE
}

CArchive& operator<<(CArchive& ar,  const cSpin &spin)
{
	ar << spin._spinangle << spin._spinaxis << spin._axistype;
	return ar;	
}

CArchive& operator>>(CArchive& ar, cSpin & spin)
{
	int axistype;
	ar >> spin._spinangle >> spin._spinaxis >> axistype;
	spin._axistype = (enum cSpin::AXISTYPE)axistype;
	return ar;
}

void cSpin::Serialize(CArchive &ar)
{
	if (ar.IsStoring()) //Writing data.
 		ar <<  *this;
 	else //Reading data.
 		ar >> *this;
}

//==========================Line and Plane=================

cVector cPlane::intersect(const cLine &line) const
{
	/* We give the line as the points P(t) of the form (line._origin + t*line._tangent), and we specify
	the plane as the points P such that P-_origin % _binormal = 0;  To find our intersection,
	we look for the t such that P(t) satisfies the plane condition.  That is, we want a t such that
	((line._origin + t*line._tangent) - _origin)%_binormal == 0; Since % distributes over
	+ and -, this is t = (_origin - line._origin)%binormal / line._tangent%binormal; The only difficulty
	is to avoid dividing by zero, which is the case where line is parallel to the plane. */

	Real denominator = line._tangent%_binormal; //We want to take the reciprocal of this.
	if (fabs(denominator)<SMALL_REAL)
	{
		if (denominator >= 0)
			denominator = BIG_REAL;
		else
			denominator = -BIG_REAL;
	}
	else
		denominator = 1.0/denominator;
	Real t = (_origin - line._origin)%_binormal * denominator;
	cVector planepoint = (line._origin + t*line._tangent); /* This is almost your answer, but
		it will definitely be off the plane in case the line was parallel to the plane, and it
		may have slopped off anyway.  So fix this. */
	return project(planepoint);
}

cVector cPlane::project(const cVector &point)const
{
	cVector topoint = point - _origin;  
	topoint -= (topoint % _binormal) * _binormal; /* Subtract off any component that lies
		perpendicular to the plane. */
	return _origin + topoint;
}

Real cLine::distanceTo(const cVector &point) const
{
	/* We draw a segment form the point to the _origin that lies on the line.  Then we take out
	the compoent of this segment that lies parallel to the line to get a segment that goes
	directly from the point to the line, makign a right angle with it. */
	cVector pointtoline = _origin - point;
	cVector wastemotion = pointtoline%_tangent * _tangent;
	pointtoline -= wastemotion;
	return pointtoline.magnitude();
}

Real cLine::lineCoord(const cVector &point)const
{
 /* Project point onto the line, then take it's coord wiht the line numbered so _origin
	is 0.0, _origin+_tangent is 1.0, and so on. */
	cVector linetopoint = point - _origin;
	return linetopoint%_tangent;
}
