//////////////////////////////////////////////////////////////////////////////
// Program Name:	queue.cpp
// Programmer:		Joseph E. Sutton
// Description:	Queue Class Source
// Start Date:		9/28/2004
// Last Updated:	10/18/2005
// Version:			1.10
//////////////////////////////////////////////////////////////////////////////

#include <stdlib.h>
#include <string.h>
#include "queue.h"

Queue::Queue(int s) 
 : front(0), rear(-1), count(0)
{
   maxsize = s;
   data = new Entry_type[maxsize];
   memset(data, 0, sizeof(Entry_type)*maxsize);
}

Queue::~Queue()
{
   if(data != NULL) {
      delete [] data;
      data = NULL;
   }
}

bool Queue::empty() const
/*
pre:	The count is initialy set to 0
post:	If the queue is empty return true otherwise it returns false.
*/
{
	return (count == 0);
}

bool Queue::full() const
/*
pre:	The maximum size of the queue is defined by MAX_SIZE
post:	If the queue is full return true otherwise it returns false.
*/
{
	return (count >= maxsize);
}

int Queue::size() const
/*
pre:	The count is initialy set to 0
post:	The number in the queue is returned.
*/
{
	return count;
}

Error_code Queue::append(const Entry_type & value)
/*
pre:	The rear is initialy set to -1
post:	If not full the count and rear is incremented and the value is stored in rear
*/
{
	if( !full() )
	{
		// for circular array, resets rear to zero when rear reaches max size.
		data[(rear = (++rear)%maxsize)] = value;
		count++;
		temp_return = success;
	}
	else
		temp_return = overflow;


	return temp_return;
}

Error_code Queue::retrieve(Entry_type & value)
/*
pre:	The front is initialy set to 0
post:	If not empty the data in front is stored in value
*/
{
	if( !empty() )
	{
		value = data[front];
		temp_return = success;
	}
	else
		temp_return = underflow;


	return temp_return;
}

Error_code Queue::serve()
/*
pre:	The front is initialy set to 0
post:	If not empty the count is decremented and front is incremented
*/
{
	if( !empty() )
	{
		// for circular array, resets rear to zero when rear reaches max size.
		front = (++front)%maxsize;
		count--;
		temp_return = success;
	}
	else
		temp_return = underflow;


	return temp_return;
}

Error_code Queue::serve_retrieve(Entry_type & value)
/*
pre:	The front is initialy set to 0
post:	If not empty the count is decremented and front is incremented
*/
{
	temp_return = retrieve(value);
	if(temp_return == success)
	{
		temp_return = serve();
	}
	
	return temp_return;
}
