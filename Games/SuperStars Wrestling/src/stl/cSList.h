//////////////////////////////////////////////////////////////////////////////
// Program Name:	cSList.h
// Programmer:		Joseph E. Sutton
// Description:	Sorted Linked List (Template)
// Start Date:		3/18/2004
// Last Updated:	
// Version:			1.00
//////////////////////////////////////////////////////////////////////////////

#ifndef SORT_LIST_H 
#define SORT_LIST_H

template <class DT> class d_node
{
private:
    const DT data;

public:
    d_node * next;

    d_node(DT d, d_node *n) : data(d), next(n) {}
    
    DT *GetData() { return (DT *)&data; }
};

template <class DT> class cSList
{
private:
    d_node<DT> * start, // start of endless data nodes
           * end,   // end of endless data nodes
           * temp,  // tempary node pointer
           * prev,  // tempary previous node pointer
           * last;  // used for next(function)

    // FindNode return's pointer to node pointer 
    // with data value greater then input d
    d_node<DT> * const * FindNode(DT d) const;

    unsigned int lsize;

public:
    cSList();                  // default constructor
    cSList(const cSList &src); // copy constructor
    ~cSList();                 // deconstructor

    void clear();
    bool erase(DT d);

    bool append(DT d){ return insert(d); }
    bool insert(DT d);
    DT   pop();
    DT  *find(DT d) const;

    bool empty()        const { return (start == NULL); }
    unsigned int size() const { return lsize; }

    DT *front();
    DT *next();   // call front first

    void walk(void *out, void(* callback)(void *, DT) );
};

// For MS VC++ 6
#ifdef WIN32
	#include "cSList.cpp"
#endif
//

#endif // SORT_LIST_H
