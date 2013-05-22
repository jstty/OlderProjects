// LISTND.H
// ListNode template definition
#ifndef LISTND_H
#define LISTND_H

template< class T > class List;  // forward declaration

template< class NODETYPE >
class ListNode {
   friend class List< NODETYPE >; // make List a friend
public:
   ListNode( const NODETYPE & );  // constructor
   NODETYPE getData() const;    // return the data in the node
   void setNextPtr( ListNode *nPtr ) { nextPtr = nPtr; }
   ListNode *getNextPtr() const { return nextPtr; }
private:
   NODETYPE data;               // data
   ListNode *nextPtr;           // next node in the list
};

// Constructor
template< class NODETYPE >
ListNode< NODETYPE >::ListNode( const NODETYPE &info )
	: data(info), nextPtr(NULL) { }

// Return a copy of the data in the node
template< class NODETYPE >
NODETYPE ListNode< NODETYPE >::getData() const { return data; }

#endif
