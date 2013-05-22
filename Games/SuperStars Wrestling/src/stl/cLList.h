//////////////////////////////////////////////////////////////////////////////
// Program Name:	cLList.h
// Programmer:		Joseph E. Sutton
// Description:	Linked cLList (Template)
// Start Date:		2/17/2005
// Last Updated:	7/17/2006
// Version:			1.00
//////////////////////////////////////////////////////////////////////////////

#ifndef ScLList_H
#define ScLList_H

template <class Entry_type> class Node
{
public:
	Node();
	Node(const Entry_type & value);

	Entry_type data;
	Node *next;
};

template <class Entry_type> class cLList
{
public:

   cLList();

   /* needed to manage dynamic memory */
   cLList(const cLList & copy);
   ~cLList();
   void operator = (const cLList & copy);

   /* standard general cLList operations */
   void clear();
   bool empty() const;
   bool full() const;
   int  size() const;

   int retrieve(const int pos, Entry_type & value) const;
   Entry_type retrieve(const int pos) const;
   int replace(const int, const Entry_type & value);
   int insert(const int pos, const Entry_type & value);
   int remove(const int pos);

   void front(Entry_type & value);         // reads from the front like a queue
   int  append(const Entry_type & value);  // added to end like queue
   int  find(const Entry_type & value);    // return current pos of found value

   // move a current item in list to another place in list
   // move a after b
   int move_after(const Entry_type & a, const Entry_type & b);

   Entry_type *front();
   Entry_type *next();   // call front first

protected:
   int m_count;
   Node<Entry_type> *m_front;
   Node<Entry_type> *m_walker;  // used when traversing the cLList
   Node<Entry_type> *m_temp;    // temparary node pointer

   void copy_list(const cLList & src); // copy source onto this cLList
};

// For MS VC++ 6
#ifdef WIN32
	#include "cLList.cpp"
#endif
//

#endif
