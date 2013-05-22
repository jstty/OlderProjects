//////////////////////////////////////////////////////////////////////////////
// File Name:		stack_link.h
// Programmer:		Joseph E. Sutton
// Description:	Linked Stack Class
// Course:			cs350
// Start Date:		1/13/2005
// Last Updated:	2/17/2005
// Version:			1.00
//////////////////////////////////////////////////////////////////////////////

#ifndef STACK_LINK_H  
#define STACK_LINK_H

template <class T>
struct Stack_Node
{
public:
	Stack_Node(T item, Stack_Node<T> *add_on=NULL)
	{
		entry = item;
		next_node = add_on;
	}

	T entry;
	Stack_Node<T> *next_node;
};

template <class T>
class Stack
{
public:

	Stack();
   /* needed to manage dynamic memory */
	~Stack();
   Stack(const Stack & copy);
   Stack<T> & operator = (const Stack & copy);

   void clear();
	bool empty() const;
	bool pop();
	bool top(T & item) const;
	bool push(const T & item);

private:
	
	Stack_Node<T> * top_node;
};

// For MS VC++ 6
#ifdef WIN32
	#include "stack_link.cpp"
#endif
//

#endif