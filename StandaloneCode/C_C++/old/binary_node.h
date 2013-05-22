/* filename: binary_node.h  binary tree node */

#ifndef BINARY_NODE_H
#define BINARY_NODE_H

/* error codes */
enum Error_code { success = 0, fail, range_error, underflow, overflow, fatal,
                  not_present, duplicate_error, entry_inserted, entry_found,
                  internal_error };
                  
template <class T>
class Binary_node {

public:
   Binary_node();
   Binary_node(const T &x);
   const T & getData() const { return data; }
   void setData( T x ) { data = x; }

   T data;
   Binary_node<T> *left;
   Binary_node<T> *right;

};

template <class T>
Binary_node<T>::Binary_node()
{
   left = right = NULL;
}

template <class T>
Binary_node<T>::Binary_node(const T &x)
{
   left = right = NULL;
   data = x;
}

#endif

