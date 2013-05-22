// tws_listener.h: interface for the cListener class.
//
//////////////////////////////////////////////////////////////////////

#ifndef TWS_LISTENER_H
#define TWS_LISTENER_H
#include "../pop/realnumber.h"
#include "../pop/vectortransformation.h"
#include "../pop/listener.h"

class cCritter;
class cGame;

class cListenerNULL : public cListener
{
DECLARE_SERIAL(cListenerNULL);
public:
	cListenerNULL(){}
	virtual void listen(Real dt, cCritter *pcritter);  
};

class cListenerLR : public cListener
{
DECLARE_SERIAL(cListenerLR);
protected:
	Real _hopuptime; //How long you can hop up for a given press of UP arrow.
	Real _hopagainwait; //How long you have to wait after last hop before a new hop.
	Real _lasthopage; //Helper.  Age of your critter at which you last stopped hopping.
	BOOL _hopping; //Helper. Are you hopping right now.
public:
	cListenerLR(Real hopuptime = 0.2, Real hopagainwait = 0.4):
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

#endif


