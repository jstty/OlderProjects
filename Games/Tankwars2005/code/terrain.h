//////////////////////////////////////////////////////////////////////////////
// Program Name:  terrain.h
// Programmer:    Joseph E. Sutton
// Description:	TankWars 2005
// Course:        cs335
// Start Date:    2/12/2005
// Last Updated:  
// Version:       1.00
//////////////////////////////////////////////////////////////////////////////
#ifndef _CTERRAIN_
#define _CTERRAIN_

#include "../pop/critterwall.h" //added by John P. Harris
#include "../pop/colorstyle.h"  //added by John P. Harris

class cCritterDamWall : public cCritterWall
{
DECLARE_SERIAL(cCritterDamWall);
public:
	collide(cCritter *pcritter);
	cCritterDamWall(const cVector &enda = cVector(-0.5, 0.0),
		const cVector &endb = cVector(0.5, 0.0), 
		Real thickness = 0.5, cGame *pownergame= NULL, UINT color = cColorStyle::CN_BROWN);
    int damage(int hitstrength);
};

class cTerrain
{
public:
	cTerrain(cGame *pownergame = NULL, UINT color = cColorStyle::CN_BROWN);
   ~cTerrain();

protected:

};

#endif