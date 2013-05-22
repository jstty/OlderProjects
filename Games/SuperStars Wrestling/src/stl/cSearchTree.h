//////////////////////////////////////////////////////////////////////////////
// Program Name:	cSearchTree.h
// Programmer:		Joseph E. Sutton
// Description:	Search Tree
// Course:			cs223 - HW 10
// Start Date:		11/22/2004
// Last Updated:	
// Version:			1.00
//////////////////////////////////////////////////////////////////////////////

#ifndef cSearchTree_H
#define cSearchTree_H

#include "cBinaryTree.h"

template <class T>
class cSearchTree: public cBinaryTree<T>
{ 
public:
   eErrorCode insert(const T & data);
   eErrorCode search(const T & data);
   eErrorCode remove(const T & data);

protected:
   eErrorCode recursive_insert(cBinaryNode<T> * &sub, const T & data);
   eErrorCode recursive_remove(cBinaryNode<T> * &sub, const T & data);
   eErrorCode remove_root(cBinaryNode<T> *&sub);

};

template <class T>
eErrorCode cSearchTree<T>::insert(const T & data)
{
   return recursive_insert(root, data);
}

template <class T>
eErrorCode cSearchTree<T>::remove(const T & data)
{
   return recursive_remove(root, data);
}

template <class T>
eErrorCode cSearchTree<T>::search(const T & data)
{
   cBinaryNode<T> *temp = root;

   while(temp != NULL)
   {
      if(temp->data == data)
         return success;
      else if(temp->data > data)
         temp = temp->left;
      else
         temp = temp->right;
   }

   return not_present;
}

template <class T>
eErrorCode cSearchTree<T>::recursive_insert(cBinaryNode<T> * &sub, const T & data)
{
   if(sub == NULL)
   {
      sub = new cBinaryNode<T>(data);
      return success;
   }

   if(sub->data == data)
      return duplicate_error;
   else if(sub->data > data)
      return recursive_insert(sub->left, data);
   else
      return recursive_insert(sub->right, data);
}

template <class T>
eErrorCode cSearchTree<T>::recursive_remove(cBinaryNode<T> * &sub, const T & data)
{
   if(sub == NULL)
      return not_present;

   if(sub->data == data)
      return remove_root(sub);
   else if(sub->data > data)
      return recursive_remove(sub->left, data);
   else
      return recursive_remove(sub->right, data);
}

template <class T>
eErrorCode cSearchTree<T>::remove_root(cBinaryNode<T> *&sub)
{
   cBinaryNode<T> *to_del = sub;
   
   if(sub->left == NULL)
      // 1 or 0 child node; leaf or has right child
      sub = sub->right;
   else if(sub->right == NULL)
      // 1 child node; has left child
      sub = sub->left;
   else
   {
      // 2 child nodes
      // predecessor method
      cBinaryNode<T> *prev = sub;
      to_del = sub->left;
      
      // get right most !NULL node
      while(to_del->right != NULL)
      {
         prev = to_del;
         to_del = to_del->right;
      }
      
      // copy data
      sub->data = to_del->data;

      // update link
      if(prev == sub)
         // did not move to the right
         prev->left = to_del->left;
      else
         // moved to the right
         prev->right = to_del->left;
   }

   delete to_del;

   return success;
}

#endif

