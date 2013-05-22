//////////////////////////////////////////////////////////////////////////////
// Program Name:	sList.h
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

    d_node(DT d = 0, d_node *n = NULL) : data(d), next(n) {}
    
    DT GetData() { return data; }
};

template <class DT> class sList
{
private:
    d_node<DT> * start, // start of endless data nodes
           * end,   // end of endless data nodes
           * temp,  // tempary node pointer
           * prev;  // tempary previous node pointer

    // FindNode return's pointer to node pointer 
    // with data value greater then input d
    d_node * const * FindNode(DT d) const;

public:
    sList();                      // default constructor
    sList(const sList &src); // copy constructor
    ~sList();                     // deconstructor

    void   release();
    bool   insert(DT d);
    DT     get();
    bool   find(DT d) const;
    bool   erase(DT d);
    bool   empty() const { return (start == NULL); }
};

// For MS VC++ 6
#ifdef WIN32
	#include "sList.cpp"
#endif
//

#endif // SORT_LIST_H
