//////////////////////////////////////////////////////////////////////////////
// File Name:		stack_link.cpp
// Programmer:		Joseph E. Sutton
// Description:	Linked Stack Class
// Course:			cs350
// Start Date:		1/13/2005
// Last Updated:	2/17/2005
// Version:			1.00
//////////////////////////////////////////////////////////////////////////////

#include "stack_link.h"
#ifdef STACK_LINK_H  

//////////////////////////////////////////////////////////////////////////////
// constructors, destructor and overloaded =
//////////////////////////////////////////////////////////////////////////////
template <class T>
Stack<T>::Stack()
{
	top_node = NULL;
}

// COPY CONSTRUCTOR
template <class T>
Stack<T>::Stack(const Stack &original)
{
	Stack_Node<T> *temp = original.top_node;
	while(temp != NULL)
	{
		top_node = new Stack_Node<T>(temp->item, top_node);
		temp = temp->next_node;
	}
}

// OVERLOADED = OPERATOR
template <class T>
Stack<T> &Stack<T>::operator =(const Stack &right)
{  
   while(top_node != NULL)
	{
		Stack_Node<T> *temp = top_node;
		top_node = top_node->next_node;
		delete temp;
	}

   Stack_Node<T> *temp = original.top_node;
	while(temp != NULL)
	{
		top_node = new Stack_Node<T>(temp->item, top_node);
		temp = temp->next_node;
	}

   return *this;
}


template <class T>
Stack<T>::~Stack()
{
	clear();
}

template <class T>
void Stack<T>::clear()
{
	while(top_node != NULL)
	{
		Stack_Node<T> *temp = top_node;
		top_node = top_node->next_node;
		delete temp;
	}
}


template <class T>
bool Stack<T>::empty() const
/*
pre:	The stack_size is initialy set to 0
post:	If the stack is empty return true otherwise it returns false.
*/
{
	return (top_node == NULL);
}

template <class T>
bool Stack<T>::pop()
/*
pre:	none
post:	If the stack is not empty it subtracts one from the size, else return underflow error.
*/
{
	bool temp_return = false;

	if( !empty() )
	{
		Stack_Node<T> *temp = top_node;	// store for deallocation

		top_node = top_node->next_node;	// get next, store in top_node
		delete temp;			            // deallocat
		
		temp_return = true;
	}

	return temp_return;
}

template <class T>
bool Stack<T>::top(T & item) const
/*
pre:	The stack is allocated in memory. The stack_size is initialy set to 0
post:	If the stack is not empty it reads the top value from the stack and copies in to 't', else return underflow error.
*/
{
	bool temp_return = false;

	if( !empty() )
	{
		item = top_node->entry;
		temp_return = true;
	}

	return temp_return;
}

template <class T>
bool Stack<T>::push(const T & item)
/*
pre:	The stack is allocated in memory. The stack_size is initialy set to 0
post:	If the stack is not full it added 't' to the stack, else return overflow error.
*/
{
	top_node = new Stack_Node<T>(item, top_node);

	return true;
}

#endif