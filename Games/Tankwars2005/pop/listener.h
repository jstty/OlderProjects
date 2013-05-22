// Listener.h: interface for the cListener class.
//
//////////////////////////////////////////////////////////////////////

#ifndef LISTENER_H
#define LISTENER_H
#include "realnumber.h"
#include "vectortransformation.h"

class cCritter;
class cGame;

class cListener : public CObject
{
DECLARE_SERIAL(cListener);
public:
	static Real CRITTERTURNSPEEDSLOW; //Slow Radians per second to turn. Try 0.5*PI
	static Real CRITTERTURNSPEEDFAST; //Fast Radians per second to turn. Try 2.0*PI
	static Real TURNSPEEDUPWAIT; //Time in secs of turning before you turn faster.
public:
	cListener(){};
	virtual ~cListener(){} //Virtual in case we need to overload.
	Real turnspeed(Real age);
	virtual void install(cCritter *pcritter); 
	virtual void listen(Real dt, cCritter *pcritter){}  
//Serialize methods
	virtual void Serialize(CArchive &ar){CObject::Serialize(ar);}
};

class cListenerArrow : public cListener
{
DECLARE_SERIAL(cListenerArrow);
public:
	cListenerArrow(){}
	virtual void listen(Real dt, cCritter *pcritter);  
};

/* cListenerArrowAttitude is like class cListenerArrow except that makes the arow motions
relative to the player's attitude rather than relative to the axies.  Also it changes
the roles of the key pairs to be intuitive if you ride a player in 3D, where "up"
is the ZAXIS, not the YAXIS. */
class cListenerArrowAttitude : public cListener
{
DECLARE_SERIAL(cListenerArrowAttitude);
public:
	cListenerArrowAttitude(){}
	virtual void listen(Real dt, cCritter *pcritter);  
};

class cListenerHopper : public cListener
{
DECLARE_SERIAL(cListenerHopper);
protected:
	Real _walkspeed; //How fast you move with the arrow key motion
	Real _hopuptime; //How long you can hop up for a given press of UP arrow.
	Real _hopagainwait; //How long you have to wait after last hop before a new hop.
	Real _lasthopage; //Helper.  Age of your critter at which you last stopped hopping.
	BOOL _hopping; //Helper. Are you hopping right now.
public:
	cListenerHopper(Real walkspeed = 6.0, Real hopuptime = 0.2, Real hopagainwait = 0.4):
		_walkspeed(walkspeed),_hopuptime(hopuptime), _hopagainwait(hopagainwait),
		_lasthopage(-hopagainwait), _hopping(FALSE){}
	Real walkspeed(){return _walkspeed;}
	Real hopuptime(){return _hopuptime;}
	Real hopagainwait(){return _hopagainwait;}
	Real lasthopage(){return _lasthopage;}
	void setWalkspeed(Real ws){_walkspeed = ws;}
	void setHopuptime(Real hut){_hopuptime = hut;}
	void setHopagainwait(Real huw){_hopagainwait = huw;}
	virtual void listen(Real dt, cCritter *pcritter);  
	virtual void Serialize(CArchive &ar);
};

class cListenerScooterYHopper : public cListener
{
DECLARE_SERIAL(cListenerScooterYHopper);
protected:
	Real _hopuptime; //How long you can hop up for a given press of UP arrow.
	Real _hopagainwait; //How long you have to wait after last hop before a new hop.
	Real _lasthopage; //Helper.  Age of your critter at which you last stopped hopping.
	BOOL _hopping; //Helper. Are you hopping right now.
public:
	cListenerScooterYHopper(Real hopuptime = 0.2, Real hopagainwait = 0.4):
		_hopuptime(hopuptime), _hopagainwait(hopagainwait),
		_lasthopage(-hopagainwait), _hopping(FALSE){}
	Real hopuptime(){return _hopuptime;}
	Real hopagainwait(){return _hopagainwait;}
	Real lasthopage(){return _lasthopage;}
	void setHopuptime(Real hut){_hopuptime = hut;}
	void setHopagainwait(Real huw){_hopagainwait = huw;}
	virtual void listen(Real dt, cCritter *pcritter);  
	virtual void Serialize(CArchive &ar);
};

class cListenerScooter : public cListener /* cListenerScooter works well in 2D and in 3D. */
{
DECLARE_SERIAL(cListenerScooter)
public:
	cListenerScooter(){}
	virtual void listen(Real dt, cCritter *pcritter);  
};

class cListenerCar : public cListener
{
DECLARE_SERIAL(cListenerCar);
public:
	cListenerCar(){}
	virtual void listen(Real dt, cCritter *pcritter);  
};

class cListenerSpaceship : public cListener
{
DECLARE_SERIAL(cListenerSpaceship);
public:
	cListenerSpaceship(){}
	virtual void listen(Real dt, cCritter *pcritter);  
};

class cListenerCursor : public cListener
{
DECLARE_SERIAL(cListenerCursor);
public:
	static Real TOOSMALLAMOVE; /* Accumulate mouse moves till you get a 
		magnitude larger than this, otherwise you'll see too much wobble. */
	static Real CURSORSPEED;	
protected: 
	BOOL _attached;
public:
	cListenerCursor():_attached(TRUE){}
	BOOL attached(){return _attached;}
	virtual void Serialize(CArchive &ar);
	virtual void install(cCritter *pcritter);
	virtual void listen(Real dt, cCritter *pcritter);  
};

//The following are special listeners used by the cCritterViewer

class cListenerViewerRide : public cListener //Assume 3D
{
DECLARE_SERIAL(cListenerViewerRide)
public:
//Some statics for adjusting the riderview
	static cVector OFFSETDIR;
	static Real PLAYERLOOKAHEAD;
protected:
	cVector _offset; //offset from the player, if you are riding on him.
public:
	cListenerViewerRide(){}; // We will initialize _offset inside the install call.
	void setOffset(cVector offset){_offset = offset;}
	cVector offset()const{return _offset;}
	virtual void install(cCritter *pcritter);
	virtual void listen(Real dt, cCritter *pcritter);  
	virtual void Serialize(CArchive &ar);
};


class cListenerViewerFly : public cListener //Assume 3D
{
DECLARE_SERIAL(cListenerViewerFly)
public:
	cListenerViewerFly(){}
	virtual void install(cCritter *pcritter); 
	virtual void listen(Real dt, cCritter *pcritter);  
};

class cListenerViewerOrtho : public cListener //Assume 2D
{
DECLARE_SERIAL(cListenerViewerOrtho)
public:
	cListenerViewerOrtho(){}
	virtual void install(cCritter *pcritter); 
	virtual void listen(Real dt, cCritter *pcritter);  
};

class cListenerViewerTranslate : public cListener //Assume 3D.  Not used yet.
{
DECLARE_SERIAL(cListenerViewerTranslate)
public:
	cListenerViewerTranslate(){}
	virtual void install(cCritter *pcritter); 
	virtual void listen(Real dt, cCritter *pcritter);  
};

class cListenerViewerOrbit : public cListener //3D, but not used yet.
{
DECLARE_SERIAL(cListenerViewerOrbit)
public:
	cListenerViewerOrbit(){}
	virtual void install(cCritter *pcritter);
	virtual void listen(Real dt, cCritter *pcritter);  
};

#endif //CRITTER_H

