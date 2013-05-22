//////////////////////////////////////////////////////////////////////////////
// Program Name:	cLList.cpp
// Programmer:		Joseph E. Sutton
// Description:	Linked cLList (Template)
// Start Date:		2/17/2005
// Last Updated:	7/17/2006
// Version:			1.00
//////////////////////////////////////////////////////////////////////////////

#include "cLList.h"

//////////////////////////////////////////////////////////////////////////////
// Node Functions
//////////////////////////////////////////////////////////////////////////////

template <class Entry_type>
Node<Entry_type>::Node()
//////////////////////////////////////////////////////////////////////////////
// pre:	none
// post:	sets next to NULL
//////////////////////////////////////////////////////////////////////////////
{
   next = NULL;
}


template <class Entry_type>
Node<Entry_type>::Node(const Entry_type & value)
//////////////////////////////////////////////////////////////////////////////
// pre:	none
// post:	sets data to value and next to NULL
//////////////////////////////////////////////////////////////////////////////
{
   data = value;
   next = NULL;
}


//////////////////////////////////////////////////////////////////////////////
// cLList Functions
//////////////////////////////////////////////////////////////////////////////

template <class Entry_type>
cLList<Entry_type>::cLList()
//////////////////////////////////////////////////////////////////////////////
// pre:	none
// post:	sets count to zero and m_front to NULL
//////////////////////////////////////////////////////////////////////////////
{
   m_count = 0;
   m_front = NULL;
}


template <class Entry_type>
cLList<Entry_type>::cLList(const cLList & copy)
//////////////////////////////////////////////////////////////////////////////
// pre:	none
// post:	copies data from copy to this cLList
//////////////////////////////////////////////////////////////////////////////
{
   count = 0;
   m_front = NULL;

   copy_list(copy);
}

template <class Entry_type>
cLList<Entry_type>::~cLList()
//////////////////////////////////////////////////////////////////////////////
// pre:	none
// post:	deletes all nodes in the cLList
//////////////////////////////////////////////////////////////////////////////
{
   clear();
}

template <class Entry_type>
void cLList<Entry_type>::operator=(const cLList & copy)
{
   clear();

   copy_list(copy);
}


template <class Entry_type>
void cLList<Entry_type>::clear()
//////////////////////////////////////////////////////////////////////////////
// pre:	none
// post:	removes all nodes, setting the count to zero and the first node to NULL
//////////////////////////////////////////////////////////////////////////////
{
   m_walker = m_front;
   while(m_walker != NULL)
   {
      m_temp = m_walker;
      m_walker = m_walker->next;
      delete m_temp;
   }

   m_front = NULL;
   m_count = 0;
}


template <class Entry_type>
bool cLList<Entry_type>::empty() const
//////////////////////////////////////////////////////////////////////////////
// pre:	Count is initialy set to 0
// post:	if count zero or m_front NULL return true other wise return false
//////////////////////////////////////////////////////////////////////////////
{
	return ( (m_count == 0) || (m_front == NULL) );
}


template <class Entry_type>
bool cLList<Entry_type>::full() const
//////////////////////////////////////////////////////////////////////////////
// pre:	none
// post:	if can't allocate memory for a node return true other wise return false
//////////////////////////////////////////////////////////////////////////////
{
	Node<Entry_type> *m_temp = new Node<Entry_type>();

   // can't allocate memory for a node
	if( m_temp == NULL )	return true;

	delete m_temp;
	return false;
}


template <class Entry_type>
int cLList<Entry_type>::size() const
//////////////////////////////////////////////////////////////////////////////
// pre:	Count is initialy set to 0
// post:	return count which is the size of the cLList
//////////////////////////////////////////////////////////////////////////////
{
	return m_count;
}

template <class Entry_type>
int cLList<Entry_type>::retrieve(const int pos, Entry_type & value) const
//////////////////////////////////////////////////////////////////////////////
// pre:	Count is initialy set to 0
//       Range: 0 -> (count-1)
//       < 0 . . . (count - 1) > count
// post:	If not in range return range_error
//       else if in range then store data in value and return success
//////////////////////////////////////////////////////////////////////////////
{
   if( (pos < 0) || (pos >= size()) )
      return 0;
   
   // walk cLList
   Node<Entry_type> *m_walker = m_front;
   for(int i = 0; (i < pos) && (m_walker != NULL); i++, m_walker = m_walker->next);
   
   value = m_walker->data;

	return 1;
}

template <class Entry_type>
Entry_type cLList<Entry_type>::retrieve(const int pos) const
//////////////////////////////////////////////////////////////////////////////
// pre:	Count is initialy set to 0
//       Range: 0 -> (count-1)
//       < 0 . . . (count - 1) > count
// post:	If not in range return range_error
//       else if in range then store data in value and return success
//////////////////////////////////////////////////////////////////////////////
{
   if( (pos < 0) || (pos >= size()) )
      return 0;
   
   // walk cLList
   Node<Entry_type> *m_walker = m_front;
   for(int i = 0; (i < pos) && (m_walker != NULL); i++, m_walker = m_walker->next);
   
   return m_walker->data;
}

template <class Entry_type>
int cLList<Entry_type>::replace(const int pos, const Entry_type & value)
//////////////////////////////////////////////////////////////////////////////
// pre:	Count is initialy set to 0
//       Range: 0 -> (count-1)
//       < 0 . . . (count - 1) > count
// post:	If not in range return range_error
//       else if in range then replace data at position 'pos' with value and return success
//////////////////////////////////////////////////////////////////////////////
{
   if( (pos < 0) || (pos >= size()) )
      return 0;

   // walk cLList
   m_walker = m_front;
   for(int i = 0; (i < pos) && (m_walker != NULL); i++, m_walker = m_walker->next);

	m_walker->data = value;

	return 1;
}


template <class Entry_type>
int cLList<Entry_type>::insert(const int pos, const Entry_type & value)
//////////////////////////////////////////////////////////////////////////////
// pre:	Count is initialy set to 0.
//       Can't insert at end because it would push
//       end value off and cLList should be full.
//       Range: 0 -> (count-1) 
//       < 0 . . . (count-1) >
// post:	If not in range return range_error
//       else if in range then find previous link at pos, update links.
//       Incremented the count and return success.
//////////////////////////////////////////////////////////////////////////////
{
   if( full() )
      return 0;
   else if( (pos < 0) || (pos > size()) )
      return 0;


   // walk cLList
   m_walker = m_front;
   for(int i = 0; (i < (pos-1)) && (m_walker != NULL); i++, m_walker = m_walker->next);
   
   // create new node
   m_temp = new Node<Entry_type>(value);
   if(m_temp == NULL)
     return 0;

   //
   if(pos == 0)
   {
      if(m_front != NULL)
      {
         // set next to new node's next
         m_temp->next = m_front;
         // set m_front to new node
         m_front = m_temp;
      }
      else
      {
         m_front = m_temp;
      }
   }
   else if(m_walker != NULL)
   {
      // set next to new node's next
      m_temp->next = m_walker->next;
      // set next to new node
      m_walker->next = m_temp;
   }
   else
      return 0;

	m_count++;
	return 1;
}

template <class Entry_type>
int cLList<Entry_type>::remove(const int pos)
//////////////////////////////////////////////////////////////////////////////
// pre:	Count is initialy set to 0.
//       Can't insert at end because it would push
//       end value off and cLList should be full.
//       Range: 0 -> (count-1) 
//       < 0 . . . (count-1) > count
// post:	If not in range return range_error
//       else if in range then find previous link at pos, update links.
//       Decremented the count and return success.
//////////////////////////////////////////////////////////////////////////////
{
   if( empty() )
      return 0;
   if( (pos < 0) || (pos > size()) )
      return 0;

   // walk cLList
   m_walker = m_front;
   for(int i = 0; (i < (pos-1)) && (m_walker != NULL); i++, m_walker = m_walker->next);


   //
   if(pos == 0)
   {
      if(m_front != NULL)
      {
         m_temp = m_front;
         m_front = m_front->next;
         delete m_temp;
      }
      else
         return 1;
   }
   else if(m_walker != NULL)
   {
      m_temp = m_walker->next;
      if(m_temp != NULL)
      {
         m_walker->next = m_temp->next;
         delete m_temp;
      }
      else
         return 1;
   }
   else
      return 1;
   //

   m_count--;
	return 1;
}


template <class Entry_type>
int cLList<Entry_type>::append(const Entry_type & value)
//////////////////////////////////////////////////////////////////////////////
// same as insert, used like queue
//////////////////////////////////////////////////////////////////////////////
{
   return insert( size(), value);
}

template <class Entry_type>
int cLList<Entry_type>::find(const Entry_type & value)
{
   int i;
   m_walker = m_front;
   for(i = 0; (m_walker != NULL) && (m_walker->data != value); i++, m_walker = m_walker->next);

   if(m_walker == NULL)
      return -1;
   else
      return i;
}


// move a after b
template <class Entry_type>
int cLList<Entry_type>::move_after(const Entry_type & a, const Entry_type & b)
{
   m_walker = m_front;
   for(i = 0; (m_walker != NULL) && (m_walker->data != b); i++, m_walker = m_walker->next);

   Node<Entry_type> *prev;
   m_temp = m_front;
   prev = m_temp;
   for(i = 0; (m_temp != NULL) && (m_temp->data != a); i++) {
      prev = m_temp;
      m_temp = m_temp->next;
   }

   if( (prev != NULL) &&
       (m_temp != NULL) &&
       (m_walker != NULL) )
   {
      // close out gap(m_temp)
      prev->next = m_temp->next;

      // move 
      m_temp->next = m_walker->next;
      m_walker->next = m_temp;

      return 0;
   }

   return 1;
}


template <class Entry_type>
void cLList<Entry_type>::front(Entry_type & value)
{
   if(m_front != NULL)
      value = m_front->data;
}


template <class Entry_type>
Entry_type *cLList<Entry_type>::front()
{
   if(m_front != NULL)
   {
      m_walker = m_front;
      return &(m_front->data);
   }

   return NULL;
}

template <class Entry_type>
Entry_type *cLList<Entry_type>::next()
{
   if(m_walker != NULL)
   {
      m_walker = m_walker->next;
      return &(m_walker->data);
   }

   return NULL;
}



template <class Entry_type>
void cLList<Entry_type>::copy_list(const cLList & src)
//////////////////////////////////////////////////////////////////////////////
// pre:	none
// post:	copies data from copy to this cLList
//////////////////////////////////////////////////////////////////////////////
{
   Node<Entry_type> *last = NULL;
   m_walker = src.m_front;
   while(m_walker != NULL)
   {
      // create node
      m_temp = new Node<Entry_type>(m_walker->data);

      // if first set m_front to new
      if(m_front == NULL) m_front = m_temp;
      // else set last's next to new
      else              last->next = m_temp;

      count++;
      last = m_temp;
      m_walker = m_walker->next;
   }
}
