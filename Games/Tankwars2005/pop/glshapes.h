#ifndef GLSHAPES_H
#define GLSHAPES_H

extern void APIENTRY glutWireSphere(GLdouble radius, GLint slices, GLint stacks);
extern void APIENTRY glutSolidSphere(GLdouble radius, GLint slices, GLint stacks);
	/* Slices means the number of longitude lines, stacks is the number of latitude
		lines. */
extern void APIENTRY glutWireCone(GLdouble base, GLdouble height, GLint slices, GLint stacks);
extern void APIENTRY glutSolidCone(GLdouble base, GLdouble height, GLint slices, GLint stacks);
extern void APIENTRY glutWireTorus(GLdouble innerRadius, GLdouble outerRadius, GLint sides, GLint rings);
extern void APIENTRY glutSolidTorus(GLdouble innerRadius, GLdouble outerRadius, GLint sides, GLint rings);
	/* Meaning of the second two args are as follows.
	The "sides" are the number of sides in a "vertial" torus crosssection as sliced
	through the ring as if making bagel chips, "sides" is also the number of
	latitude lines if we think of the poles located above and below the torus hole.
	The "rings" is the number "vertical" rings around the torus, the "rings" is
	the number of longitude lines, or the "rings" is the nubmer of sides in
	the shape we see if we look down at the torus from above its hole. */
extern void APIENTRY glutWireTetrahedron(void);
extern void APIENTRY glutSolidTetrahedron(void);
extern void APIENTRY glutWireCube(GLdouble size);
extern void APIENTRY glutSolidCube(GLdouble size);
extern void APIENTRY glutWireOctahedron(void);
extern void APIENTRY glutSolidOctahedron(void);
extern void APIENTRY glutWireDodecahedron(void);
extern void APIENTRY glutSolidDodecahedron(void);
extern void APIENTRY glutWireIcosahedron(void);
extern void APIENTRY glutSolidIcosahedron(void);
extern void APIENTRY glutWireTeapot(GLdouble scale);
extern void APIENTRY glutSolidTeapot(GLdouble scale);

#endif GLSHAPES_H