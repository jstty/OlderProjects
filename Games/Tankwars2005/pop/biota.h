// Biota.h.  Interface for the cBiota class.
//
//////////////////////////////////////////////////////////////////////

#ifndef BIOTA_H
#define BIOTA_H

#include "critter.h" /* Need for the RUNTIME_CLASS(cCritter) default argument used
	in count and nearestCritter methods. */
#include "metric.h" // Need this stuff to define the _metric .

class cGame; //Forward declaration for _pgame member of cBiota.
class CPopView; //For the argument to update, used for sniffing.
class cGraphics; //For the draw method

/* The cServiceRequest utility class is going to be used in the cBiota
_servicerequestarray, which is used for passing messages from the cCritter* objects
 to the cBiota */
class cServiceRequest
{
friend class cBiota;
private:
	cCritter *_pclient;
	CString _request;
public:
//Constructors
	cServiceRequest(){};
	cServiceRequest(cCritter *pclient, CString request):
		_pclient(pclient), _request(request){}
};

/* Instead of using the more familiar  CArray<cCritter*, cCritter*> for my parent
array class, I have the option in MFC of using CTypedPtrArray<CObArray, cCritter*>.
The virtue of the second, gnarlier-looking class is that (a) it is not
template based, and methods using it are faster and (b) it "knows" it's made of
pointers so you are not required to write an overloaded
void AFXAPI SerializeElements(CArchive &ar, cCritter **pbubblearray, int count)
method that needs to be placed in CPopDoc right before your CDoc::Serialize
is defined.  We also declare Serialize again to make it public. */

	class cCritterArray : public CTypedPtrArray<CObArray, cCritter*> //Right way.
	{
	DECLARE_SERIAL(cCritterArray);
	public:
		cCritterArray(){}
		cCritterArray(const cCritterArray &critarray);
		void Serialize(CArchive& ar){CTypedPtrArray<CObArray, cCritter*>::Serialize(ar);}//Right
	};

/* I prefer to make the cBiota inherit as private from cCritterArray so that
users can only use those CArray methods which I choose to make public. This is
because I don't want other programmers to abuse the cBiota by doing the wrong
kinds of things to it. I do make cGame a friend so its basic methods can make
changes to the cGame _pbiota object.*/

class cBiota : private cCritterArray
{ 
DECLARE_SERIAL(cBiota); 
public: //Statics
	static const int NOINDEX; // -1, impossible index, For use by cBiota::_index().
protected:
//Non-serialized helper members;
	cGame* _pgame;
	CArray<cServiceRequest, cServiceRequest> _servicerequestarray;
	/** The _metric is a cMetricCritter, which inherits from the template class
	CMap<cPairCritter, cPairCritter&, cMetricCritter, cMetricCritter&>,
	which is a is a hash-table that matches cPairCritter keys to 
	cMetricCritter values.  A cPairCritter holds pointers to two critters, while
	the cMetricCritter value holds the distance and vector direction from the 
	first critter to the second.*/
	cMetricCritter _metric; 
//Protected helper methods
	void _delete_me(int clientindex); /* remove the element from the array, 
		moving all the other array members one index closer to the head.
		Call delete on element, to free the memory.  Invoke with _servicerequest "delete_me". */
	void _move_to_front(int clientindex); /* Move element from its current array
		position, to the head of the array, either in first position or (if there is an onscreen
		player in first position to second position).  We draw the cBiota in the draw last first
		draw first last order, so that visually the first things in the array show up on top
		or in front of the others.	Invoke with _servicerequest "move_to_front". */
	void _replicate(int clientindex); /* Make a mutated copy of the
		element and insert it into the array right after the element.*/
	void _spawn(int clientindex); /* Change all the other critter's sprites
		into mutations of element's sprite. */
	void _zap(int clientindex); // Do a 100% mutation.
//CArray Overloads
	void Add(cCritter* pmember); //Keep private, and overloads to fix _powner.
	void InsertAt(int n, cCritter* pmember); //Keep private, and overload to fix _powner.
	friend cGame; // Need this so cGame can use cBiota's new, delete, InsertAt, and RemoveAt.
public:
//Construction and destruction.
	cBiota();
	cBiota(cGame *pgame);
	virtual ~cBiota(); //virtual in case I want to derive.
	virtual void _free(); /* Delete all members.  This is used in destructor and
		 before loading into an existing cBiota object. */
	int _index(cCritter* pbubble); /* Find the i index where pbubble appears in
		the array.  Return NOINDEX, or -1, if it's not in the array. These 
		index numbers are fed to the servicerequest functions.  The index
		is also used in cCritter::Serialize, so it has to be public.*/
	void purgeNonPlayerCritters(); /* Does a delete on all the members except 
		_pgame->player(), thus shrinks _pbiota to size 0 or 1. */
	void purgeNonPlayerNonWallCritters(); /* Deletes all except player and walls. */
	void purgeCritters(CRuntimeClass *pruntimeclass = RUNTIME_CLASS(cCritter)); /* Gets rid of all
		of a desired type of critter, such as cCritterBullet.  If called with no argument,
		gets rid of all critters.  If you want to save the player use purgeNonPlayerCritters.*/
	void removeReferencesTo(cCritter *pdeadpcritter); /* Calls pcritter->removeReferencesTo(
		pdeadcritter) for every pcritter in the array. */
//Mutator
	void setWrapflag(int wrapflag); //Sets critters wrapflags.
	void setGame(cGame *pgame){_pgame = pgame;}
//Accessor
	int score();
	int health();
	int count(CRuntimeClass *pruntimeclass = RUNTIME_CLASS(cCritter),BOOL includesubclasses = TRUE);
		 /* This counts critters of the type pruntimeclass.  If includesubclasses is TRUE, it also
		looks for critters that are subclasses of the pruntimeclass; if includesublclasses is FALSE,
		it looks only for critters that have the same class type as pruntimeclass.  The default
		settings are so that count() will count all the critters. */
	cCritter* player();
	cRealBox border();
	cGame* pgame(){ASSERT(_pgame && "cBiota has valid cGame pointer _pgame."); return _pgame;}
//CArray Overloads
	void Serialize(CArchive& ar); 
		/* We make the next two public so we can use them in the various fixPointerRefs calls made
			by cCritter and cForce children.  Other than those cases, you should avoid using
			these lowlevel methods. */
	int GetSize(){return cCritterArray::GetSize();} //Declaration makes method public.
	cCritter* GetAt(int i){if (i == NOINDEX) return NULL; else return cCritterArray::GetAt(i);}
		//This declaration also has the effect of making the method public.
//Metric methods.  These are implemented two ways, depending if USEMETRIC #defined in metric.h
	void updateMetric();
	Real distance(cCritter *pa, cCritter *pb);
	cVector direction(cCritter *pa, cCritter *pb);
	cDistanceAndDirection distanceAndDirection(cCritter *pa, cCritter *pb);
//Distance and touch  methods
	//For points
	cCritter* pickLowestIndexTouched(const cVector &vclick);
	cCritter* pickClosestTouched(const cVector &vclick);
	cCritterArray touchArray(const cVector &vclick);
	//For Critters
	cCritterArray touchArray(cCritter *pcrittercenter); /* Return critters touching pcenter. */
	cCritter* pickClosestCritter(cCritter *pcrittercenter,
		CRuntimeClass *pruntimeclass = RUNTIME_CLASS(cCritter),	BOOL includesubclasses = TRUE);
		/* This looks for the closest critter to the pcenter critter. It searches for critters of
		the type pruntimeclass.  If includesubclasses is TRUE, it also looks for critters that are 
		subclasses of the pruntimeclass; if includesublclasses if FALSE, it looks only for critters
		that have the same class type as pruntimeclass.  The default settings are so that
		pickClosestCritter(pcenter) will look for the closest critter of any kind. */
	//For sightlines
	cCritter* pickTopTouched(const cLine &sightline, cCritter *pcritterignore = NULL);
	cCritter* pickClosestTouched(const cLine &sightline, cCritter *pcritterignore = NULL);
	cCritter* pickClosestAhead(const cLine &sightline, cCritter *pcrittercenter,
		Real visionangle = PI/4.0,
		CRuntimeClass *pruntimeclass = RUNTIME_CLASS(cCritter),	BOOL includesubclasses = TRUE);
		/* looks along the sightline from pcrittercenter and finds candidate critters
		of the desired pruntimeclass and which are within the visionangle field around
		sighline. Of these candidates, the critter that's actually closest to the
		sightline is chosen.*/
	cCritterArray touchArray(const cLine &sightline, cCritter *pcritterignore = NULL);
//Service request methods
	void addServiceRequest(cServiceRequest servicerequest);
	BOOL processServiceRequests();  
//Array-walking methods.
	virtual void draw(cGraphics *pgraphics, int drawflags = 0);
		//cBiota::draw is normally called in cGraphics::graphicsOnDraw.
		//All the following array walking methods are called in cGame::step.
	void move(Real dt); //Calls each critter's move(dt).
	void update(CPopView *pactiveview, Real dt); /* Calls all critters' updates. The pview can be passed to sniff. */
	void animate(Real dt); //Calls each critter's _psprite->animate(dt).
	void feellistener(Real dt); /* Calls each critter's listen (for controller input like key and mouse).
		The cListenerCursor needs the dt to set the _velocity. */
	void setNewgeometryflag(BOOL onoff); /* Use to set each pcritter->psprite()->newgeometryflag
		to FALSE, we use this after we've drawn the critters in all the views and the draws
		have possibly made new display list IDs for the geometry of any sprite that had its
		newgeomtryflag TRUE. Can also use to set to TRUE when toggling between solid
		and transparent view. */
};

#endif //BIOTA_H

