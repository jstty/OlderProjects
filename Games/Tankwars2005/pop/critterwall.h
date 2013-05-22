// CritterWall.h: interface for the cCritterWall and cCritterBullet classes.
//
//////////////////////////////////////////////////////////////////////

#ifndef CRITTERWALL_H
#define CRITTERWALL_H

#include "critter.h"

class cCritterWall : public cCritter
{
DECLARE_SERIAL(cCritterWall);
public:
	static Real THICKNESS;
	static Real CORNERJIGGLETURN;/* To keep someone from impossibly bouncing up and down on a corner,
		 we jiggle the bounces off corners by a small random amount.*/
	static Real CORNERJIGGLEKICK;
	static COLORREF WALLFILLCOLOR; //It's set in static.cpp to CN_LIGHTGRAY
	static Real WALLPRISMDZ; //Default z-depth to use for drawing cCritterWall.
protected:
//Serialized fields
	COLORREF _defaultfillcolor;
	cRealBox *_pskeleton;
	int outcode(const cVector &globalpos); 
	int outcodeLocal(const cVector &localpos); 
	Real distanceToLocal(const cVector &localpos); 
	Real distanceToLocal(const cVector &localpos, int outcode); 
public:
	cCritterWall(const cVector &enda = cVector(-0.5, 0.0),
		const cVector &endb = cVector(0.0, 0.5),
		Real thickness = cCritterWall::THICKNESS,
		Real height = cCritterWall::WALLPRISMDZ,
		cGame *pownergame = NULL);
	cCritterWall(const cVector &enda, const cVector &endb, Real thickness, 
		cGame *pownergame);
//	cCritterWall(const cRealBox &skeleton, cGame *pownergame=NULL);
//	cCritterWall(Real xradius, Real yradius, Real zradius, cGame *pownergame = NULL);
	void initialize(const cVector &enda, const cVector &endb, Real thickness, Real height,
		cGame* pownergame);
	virtual void copy(cCritter *pcritter);
	virtual ~cCritterWall(){delete _pskeleton;}
//Mutators
	void setEndsThicknessHeight(const cVector &enda, const cVector &endb,
		Real thickness = cCritterWall::THICKNESS,
		Real height = cCritterWall::WALLPRISMDZ);
	void setThickness(Real thickness);
	void setHeight(Real height = 0.0);
	void setSkeleton(cRealBox *pskeleton)
		{if (_pskeleton)delete _pskeleton; _pskeleton = pskeleton;}
	void mutate(int mutationflags, Real mutationstrength); /* This is exactly the same as the
		base class cCritter::mutate except that we comment out the line, which would mutate the 
		sprite. We don't want to mutate a wall's sprite. */
	void setFillColor(COLORREF fillcolor);
//Accessors
	cRealBox *pskeleton(){return _pskeleton;}
	Real xradius()const {return _pskeleton->xradius();}
	Real yradius()const {return _pskeleton->yradius();}
	Real zradius()const{return _pskeleton->zradius();}
	Real length()const{return _pskeleton->xsize();}
	Real thickness()const{return _pskeleton->ysize();}
	Real height()const{return _pskeleton->zsize();}
//Serialize methods
	virtual void Serialize(CArchive &ar);
//Overloads
	int dragTo(cVector newposition, Real dt); /* Overload this so as not to change
		velocity as I normally want my walls to be stable and not drift after being dragged. */
	virtual BOOL collide(cCritter *pcritter);
	virtual int collidesWith(cCritter *pcritterother); /* Overload to rule out possibliity of 
		all/wall collision,	even if they aren't fixed. */
	virtual Real distanceTo(const cVector &vpoint);
	virtual int clamp(const cRealBox &border);
	virtual void setWrapflag(int wrapflag){}//Don't allow _wrapflag to change from cCritter::WRAP.
//Special method
	BOOL crossed(int startoutcode , int endoutcode );
	virtual BOOL blocks(const cVector& start, const cVector& end); /* Returns 
		TRUE if the wall blocks a line drawn from start to end. */
};

#endif //CRITTERWALL_H

