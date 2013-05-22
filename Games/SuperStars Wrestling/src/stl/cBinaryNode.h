/* //////////////////////////////////////////////////////////////////////
 Program Name:  cBinaryNode.h
 Programmer:    Joseph E. Sutton
 Start Date:    2006-15-06
 Updated:       
 Version:       1.00
 Description:
   Binary Tree Node
   
////////////////////////////////////////////////////////////////////// */

#ifndef __BINARY_NODE__
#define __BINARY_NODE__

/* error codes */
enum eErrorCode { success = 0, fail, range_error, underflow, overflow, fatal,
                  not_present, duplicate_error, entry_inserted, entry_found,
                  internal_error };
                  
template <class T>
class cBinaryNode {

public:
   cBinaryNode();
   cBinaryNode(const T &x);
   const T & getData() const { return data; }
   void setData( T x ) { data = x; }

   T data;
   cBinaryNode<T> *left;
   cBinaryNode<T> *right;

};

template <class T>
cBinaryNode<T>::cBinaryNode()
{
   left = right = NULL;
}

template <class T>
cBinaryNode<T>::cBinaryNode(const T &x)
{
   left = right = NULL;
   data = x;
}

#endif // __BINARY_NODE__

