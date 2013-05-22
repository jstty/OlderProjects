//////////////////////////////////////////////////////////////////////////////
// Program Name:	queue.h
// Programmer:		Joseph E. Sutton
// Description:	Queue Class Header
// Start Date:		9/28/2004
// Last Updated:	10/18/2005
// Version:			1.10
//////////////////////////////////////////////////////////////////////////////

#ifndef QUEUE_H  
#define QUEUE_H

enum Error_code { success=0, fail, range_error, underflow, overflow, fatal,
                  not_present, duplicate_error, entry_inserted, entry_found,
                  internal_error };

typedef int Entry_type;

class Queue
{
public:

	Queue(int s);	// set front to 0, rear to -1 and  count to 0
   ~Queue();
	
	bool empty() const;
	bool full() const;
	int size() const;

	Error_code append(const Entry_type & value);
	Error_code retrieve(Entry_type &value);	// can't make const because of temp_return
	Error_code serve();
	Error_code serve_retrieve(Entry_type & value);
	
private:
	Error_code temp_return;	// tempary return value, used in append, retrieve, serve, and serve_retrieve
	
	int front, rear, count;
	Entry_type *data;
   int maxsize;
};

#endif // QUEUE_H
