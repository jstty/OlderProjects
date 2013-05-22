//////////////////////////////////////////////////////////////////////////////
// Program Name:	slist.h
// Programmer:		Joseph E. Sutton
// Description:	Linked List (Template)
// Course:			cs350
// Start Date:		2/17/2005
// Last Updated:	
// Version:			1.00
//////////////////////////////////////////////////////////////////////////////

#ifndef SLIST_H
#define SLIST_H

template <class Entry_type> class Node
{
public:
	Node();
	Node(const Entry_type & value);

	Entry_type data;
	Node *next;
};

template <class Entry_type> class List
{
public:

   List();

   /* needed to manage dynamic memory */
   List(const List & copy);
   ~List();
   void operator = (const List & copy);

   /* standard general list operations */
   void clear();
   bool empty() const;
   bool full() const;
   int size() const;

   int retrieve(const int pos, Entry_type & value) const;
   Entry_type retrieve(const int pos) const;
   int replace(const int, const Entry_type & value);
   int insert(const int pos, const Entry_type & value);
   int remove(const int pos);

   void Front(Entry_type & value);        // reads from the front like a queue
   int append(const Entry_type & value);  // added to end like queue
   int find(const Entry_type & value);    // return current pos of found value

protected:
   int count;
   Node<Entry_type> *front;
   Node<Entry_type> *walker;  // used when traversing the list
   Node<Entry_type> *temp;    // temparary node pointer

   void copy_list(const List & src); // copy source onto this list
};

// For MS VC++ 6
#ifdef WIN32
	#include "slist.cpp"
#endif
//

#endif
