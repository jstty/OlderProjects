// LIST.H
// Template List class definition
// Added copy constructor to member functions (not included in chapter).

#ifndef LIST_H
#define LIST_H

#include <iostream> 
#include <assert.h>

#include "Listnd.h"

template< class NODETYPE >
class List {
public:
   List();                            // default constructor
   List( const List< NODETYPE > & );  // copy constructor
   ~List();                           // destructor
   void insertAtFront( const NODETYPE & );
   void insertAtBack( const NODETYPE & );
   bool removeFromFront( NODETYPE & );
   bool removeFromBack( NODETYPE & );
   bool isEmpty() const;
protected:
   ListNode< NODETYPE > *firstPtr;  // pointer to first node
   ListNode< NODETYPE > *lastPtr;   // pointer to last node

   // Utility function to allocate a new node
   ListNode< NODETYPE > *getNewNode( const NODETYPE & );
};


// Default constructor
template< class NODETYPE >
List< NODETYPE >::List() { firstPtr = lastPtr = 0; }

// Copy constructor
template< class NODETYPE >
List< NODETYPE >::List( const List<NODETYPE> &copy )
{
   firstPtr = lastPtr = 0;  // initialize pointers

   ListNode< NODETYPE > *currentPtr = copy.firstPtr;

   while ( currentPtr != 0 ) {
      insertAtBack( currentPtr -> data );
      currentPtr = currentPtr -> nextPtr;
   }
}

// Destructor
template< class NODETYPE >
List< NODETYPE >::~List()
{
   if ( !isEmpty() ) {    // List is not empty
      //cout << "Destroying nodes ...\n\n";

      ListNode< NODETYPE > *currentPtr = firstPtr, *tempPtr;

      while ( currentPtr != 0 ) {  // delete remaining nodes
         tempPtr = currentPtr;
         //cout << tempPtr -> data << ' ';
         currentPtr = currentPtr -> nextPtr;
         delete tempPtr;
      }
   }

   //cout << "\nAll nodes destroyed\n\n";
   //cout << "\n";
}

// Insert a node at the front of the list
template< class NODETYPE >
void List< NODETYPE >::insertAtFront( const NODETYPE &value )
{
   ListNode<NODETYPE> *newPtr = getNewNode( value );

   if ( isEmpty() )  // List is empty
      firstPtr = lastPtr = newPtr;
   else {          // List is not empty
      newPtr -> nextPtr = firstPtr;
      firstPtr = newPtr;
   }
}

// Insert a node at the back of the list
template< class NODETYPE >
void List< NODETYPE >::insertAtBack( const NODETYPE &value )
{
   ListNode< NODETYPE > *newPtr = getNewNode( value );

   if ( isEmpty() )  // List is empty
      firstPtr = lastPtr = newPtr;
   else {          // List is not empty
      lastPtr -> nextPtr = newPtr;
      lastPtr = newPtr;
   }
}

// Delete a node from the front of the list
template< class NODETYPE >
bool List< NODETYPE >::removeFromFront( NODETYPE &value )
{
   if ( isEmpty() )             // List is empty
      return false;             // delete unsuccessful
   else {
      ListNode< NODETYPE > *tempPtr = firstPtr;

      if ( firstPtr == lastPtr )
         firstPtr = lastPtr = 0;
      else
         firstPtr = firstPtr -> nextPtr;

      value = tempPtr -> data;  // data being removed
      delete tempPtr;
      return true;              // delete successful
   }
}

// Delete a node from the back of the list
template< class NODETYPE >
bool List< NODETYPE >::removeFromBack( NODETYPE &value )
{
   if ( isEmpty() )
      return false;   // delete unsuccessful
   else {
      ListNode< NODETYPE > *tempPtr = lastPtr;

      if ( firstPtr == lastPtr )
         firstPtr = lastPtr = 0;
      else {
         ListNode< NODETYPE > *currentPtr = firstPtr;

         while ( currentPtr -> nextPtr != lastPtr )
            currentPtr = currentPtr -> nextPtr;

         lastPtr = currentPtr;
         currentPtr -> nextPtr = 0;
      }

      value = tempPtr -> data;
      delete tempPtr;
      return true;   // delete successful
   }
}

// Is the List empty?
template< class NODETYPE >
bool List< NODETYPE >::isEmpty() const { return firstPtr == NULL; }

// Return a pointer to a newly allocated node
template< class NODETYPE >
ListNode< NODETYPE > *List< NODETYPE >::getNewNode( const NODETYPE &value )
{
   ListNode< NODETYPE > *ptr = new ListNode< NODETYPE >( value );
   assert( ptr != 0 );
   return ptr;
}


#endif