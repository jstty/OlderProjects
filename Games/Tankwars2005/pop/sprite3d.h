#ifndef SPRITE3D_H
#define SPRITE3D_H

#include "sprite.h"

class cSprite3DBox : public cSprite
{
DECLARE_SERIAL(cSprite3DBox)
public:
//Constructor, destructor, operator=
	cSprite3DBox(Real xsize = 1.0, Real ysize = 1.0, Real zsize = 1.0); //Default constructor calls initializer
	cSprite3DBox(cSprite3DBox &pspritebox); //Uses copy
	cSprite3DBox(cSprite3DBox *pspritebox); //Uses copy
	virtual	~cSprite3DBox(){}; /* The destructor of a base class must be virtual
		if any of its child classes can have more fields that may need additional
		destruction. */
//Overloaded cSprite methods
	virtual void copy(cSprite *pspritebox){} /* Checks if csprite is a cSprite3DBox,
		and, if so, copies all the fields.  */
	virtual void imagedraw(cGraphics *pgraphics, int drawflags);
};


class cSpriteSphere : public cSprite
{
DECLARE_SERIAL(cSpriteSphere)
protected:
	int _slices;
	int _stacks;
public:
//Constructor, destructor, operator=
	cSpriteSphere(Real radius = 1.0, int slices = 16, int stacks = 16); //Default constructor calls initializer
	cSpriteSphere(cSpriteSphere &pspritebox); //Uses copy
	cSpriteSphere(cSpriteSphere *pspritebox); //Uses copy
	virtual	~cSpriteSphere(){}; /* The destructor of a base class must be virtual
		if any of its child classes can have more fields that may need additional
		destruction. */
//Overloaded cSprite methods
	virtual void copy(cSprite *pspritebox){} /* Checks if csprite is a cSpriteSphere,
		and, if so, copies all the fields.  */
	void mutate(int mutationflags, Real mutationstrength);
	virtual void imagedraw(cGraphics *pgraphics, int drawflags);
};

#endif //SPRITE3D_H
