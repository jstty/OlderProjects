//////////////////////////////////////////////////////////////////////////////
// Program Name:	slist.cpp
// Programmer:		Joseph E. Sutton
// Description:	Linked List (Template)
// Course:			cs350
// Start Date:		2/17/2005
// Last Updated:	
// Version:			1.00
//////////////////////////////////////////////////////////////////////////////

#include "slist.h"

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
// List Functions
//////////////////////////////////////////////////////////////////////////////

template <class Entry_type>
List<Entry_type>::List()
//////////////////////////////////////////////////////////////////////////////
// pre:	none
// post:	sets count to zero and front to NULL
//////////////////////////////////////////////////////////////////////////////
{
   count = 0;
   front = NULL;
}


template <class Entry_type>
List<Entry_type>::List(const List & copy)
//////////////////////////////////////////////////////////////////////////////
// pre:	none
// post:	copies data from copy to this list
//////////////////////////////////////////////////////////////////////////////
{
   count = 0;
   front = NULL;

   copy_list(copy);
}

template <class Entry_type>
List<Entry_type>::~List()
//////////////////////////////////////////////////////////////////////////////
// pre:	none
// post:	deletes all nodes in the list
//////////////////////////////////////////////////////////////////////////////
{
   clear();
}

template <class Entry_type>
void List<Entry_type>::operator=(const List & copy)
{
   clear();

   copy_list(copy);
}


template <class Entry_type>
void List<Entry_type>::clear()
//////////////////////////////////////////////////////////////////////////////
// pre:	none
// post:	removes all nodes, setting the count to zero and the first node to NULL
//////////////////////////////////////////////////////////////////////////////
{
   walker = front;
   while(walker != NULL)
   {
      temp = walker;
      walker = walker->next;
      delete temp;
   }

   front = NULL;
   count = 0;
}


template <class Entry_type>
bool List<Entry_type>::empty() const
//////////////////////////////////////////////////////////////////////////////
// pre:	Count is initialy set to 0
// post:	if count zero or front NULL return true other wise return false
//////////////////////////////////////////////////////////////////////////////
{
	return ( (count == 0) || (front == NULL) );
}


template <class Entry_type>
bool List<Entry_type>::full() const
//////////////////////////////////////////////////////////////////////////////
// pre:	none
// post:	if can't allocate memory for a node return true other wise return false
//////////////////////////////////////////////////////////////////////////////
{
	Node<Entry_type> *temp = new Node<Entry_type>();

   // can't allocate memory for a node
	if( temp == NULL )	return true;

	delete temp;
	return false;
}


template <class Entry_type>
int List<Entry_type>::size() const
//////////////////////////////////////////////////////////////////////////////
// pre:	Count is initialy set to 0
// post:	return count which is the size of the list
//////////////////////////////////////////////////////////////////////////////
{
	return count;
}

template <class Entry_type>
int List<Entry_type>::retrieve(const int pos, Entry_type & value) const
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
   
   // walk list
   Node<Entry_type> *walker = front;
   for(int i = 0; (i < pos) && (walker != NULL); i++, walker = walker->next);
   
   value = walker->data;

	return 1;
}

template <class Entry_type>
Entry_type List<Entry_type>::retrieve(const int pos) const
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
   
   // walk list
   Node<Entry_type> *walker = front;
   for(int i = 0; (i < pos) && (walker != NULL); i++, walker = walker->next);
   
   return walker->data;
}

template <class Entry_type>
int List<Entry_type>::replace(const int pos, const Entry_type & value)
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

   // walk list
   walker = front;
   for(int i = 0; (i < pos) && (walker != NULL); i++, walker = walker->next);

	walker->data = value;

	return 1;
}


template <class Entry_type>
int List<Entry_type>::insert(const int pos, const Entry_type & value)
//////////////////////////////////////////////////////////////////////////////
// pre:	Count is initialy set to 0.
//       Can't insert at end because it would push
//       end value off and list should be full.
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


   // walk list
   walker = front;
   for(int i = 0; (i < (pos-1)) && (walker != NULL); i++, walker = walker->next);
   
   // create new node
   temp = new Node<Entry_type>(value);
   if(temp == NULL)
     return 0;

   //
   if(pos == 0)
   {
      if(front != NULL)
      {
         // set next to new node's next
         temp->next = front;
         // set front to new node
         front = temp;
      }
      else
      {
         front = temp;
      }
   }
   else if(walker != NULL)
   {
      // set next to new node's next
      temp->next = walker->next;
      // set next to new node
      walker->next = temp;
   }
   else
      return 0;

	count++;
	return 1;
}

template <class Entry_type>
int List<Entry_type>::remove(const int pos)
//////////////////////////////////////////////////////////////////////////////
// pre:	Count is initialy set to 0.
//       Can't insert at end because it would push
//       end value off and list should be full.
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

   // walk list
   walker = front;
   for(int i = 0; (i < (pos-1)) && (walker != NULL); i++, walker = walker->next);


   //
   if(pos == 0)
   {
      if(front != NULL)
      {
         temp = front;
         front = front->next;
         delete temp;
      }
      else
         return 1;
   }
   else if(walker != NULL)
   {
      temp = walker->next;
      if(temp != NULL)
      {
         walker->next = temp->next;
         delete temp;
      }
      else
         return 1;
   }
   else
      return 1;
   //

   count--;
	return 1;
}


template <class Entry_type>
int List<Entry_type>::append(const Entry_type & value)
//////////////////////////////////////////////////////////////////////////////
// same as insert, used like queue
//////////////////////////////////////////////////////////////////////////////
{
   return insert( size(), value);
}

template <class Entry_type>
int List<Entry_type>::find(const Entry_type & value)
{
   int i;
   walker = front;
   for(i = 0; (walker != NULL) && (walker->data != value); i++, walker = walker->next);

   if(walker == NULL)
      return -1;
   else
      return i;
}

template <class Entry_type>
void List<Entry_type>::Front(Entry_type & value)
{
   if(front != NULL)
      value = front->data;
}

template <class Entry_type>
void List<Entry_type>::copy_list(const List & src)
//////////////////////////////////////////////////////////////////////////////
// pre:	none
// post:	copies data from copy to this list
//////////////////////////////////////////////////////////////////////////////
{
   Node<Entry_type> *last = NULL;
   walker = src.front;
   while(walker != NULL)
   {
      // create node
      temp = new Node<Entry_type>(walker->data);

      // if first set front to new
      if(front == NULL) front = temp;
      // else set last's next to new
      else              last->next = temp;

      count++;
      last = temp;
      walker = walker->next;
   }
}
