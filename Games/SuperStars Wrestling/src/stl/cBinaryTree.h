//////////////////////////////////////////////////////////////////////////////
// Program Name:	cBinaryTree.h
// Programmer:		Joseph E. Sutton
// Description:	Binary Tree
// Start Date:		11/16/2004
// Last Updated:	
// Version:			1.00
//////////////////////////////////////////////////////////////////////////////


/* filename:  cBinaryTree.h 
   project:   a basic binary tree */

#ifndef cBinaryTree_H
#define cBinaryTree_H

#include "cBinaryNode.h"

template <class T> 
class cBinaryTree {
public:
   /* constructors, destructor and overloaded = */ 
   cBinaryTree();
   cBinaryTree(const cBinaryTree &original);
   ~cBinaryTree();
   cBinaryTree & operator =(const cBinaryTree &original);


   /*  traversal methods */ 
   void preorder(void (*visit)(T &));
   void inorder(void (*visit)(T &));
   void postorder(void (*visit)(T &));
   
   /*  utility methods */ 
   bool empty() const;
   int  size() const;
   void clear();
   int  height() const;
   
    /* debugging */
   void showRoot() { if (root != NULL) cout << root->data; };

   /* inserts into branch with minimum height or left if equal */
   eErrorCode insert(const T & data);
   eErrorCode remove(const T & data);

protected:
   //  auxiliary functions.
   void recursive_inorder(cBinaryNode<T> *, void (*visit)(T &));
   void recursive_preorder(cBinaryNode<T> *, void (*visit)(T &));
   void recursive_postorder(cBinaryNode<T> *, void (*visit)(T &));
   
   eErrorCode recursive_insert(cBinaryNode<T> * &sub_root, const T &data);
   eErrorCode recursive_remove(cBinaryNode<T> * &sub_root, const T &data);
   eErrorCode remove_root(cBinaryNode<T> * &sub_root);
   
   int recursive_size(cBinaryNode<T> *sub_root) const;
   int recursive_height(cBinaryNode<T> *sub_root) const;
   void recursive_clear(cBinaryNode<T> *&sub_root);
   cBinaryNode<T> *recursive_copy(const cBinaryNode<T> * const src);

   cBinaryNode<T> *root;
};


// CONSTRUCTOR
template <class T>
cBinaryTree<T>::cBinaryTree()
/* Post: An empty binary tree has been created.  */
{ 
   root = NULL;
}

// COPY CONSTRUCTOR
template <class T>
cBinaryTree<T>::cBinaryTree(const cBinaryTree &original)
/* Post: A new binary tree is initialized to copy original.  */
{ root = recursive_copy(original.root); }


// DESTRUCTOR 
template <class T>
cBinaryTree<T>::~cBinaryTree()
{ clear(); }


// OVERLOADED = OPERATOR
template <class T>
cBinaryTree<T> &cBinaryTree<T>::operator =(const cBinaryTree &right)
/* the right binary tree is copied over the current tree*/
{  
   clear();
   root = recursive_copy(right.root);
   return *this;
}


// TREE TRAVERSALS 
template <class T>
void cBinaryTree<T>::inorder(void (*visit)(T &))
/* traverse the tree in infix order sequence and call *visit. */
{ recursive_inorder(root, visit); }
 
template <class T>
void cBinaryTree<T>::preorder(void (*visit)(T &))
/* traverse the tree in prefix order sequence and call *visit. */
{ recursive_preorder(root, visit); }
 
template <class T>
void cBinaryTree<T>::postorder(void (*visit)(T &))
/* traverse the tree in postfix order sequence and call *visit. */
{ recursive_postorder(root, visit); }

// CHECK EMPTY 
template <class T>
bool cBinaryTree<T>::empty() const
/* return true if the binary tree is empty.  Otherwise, false.  */
{
   return (root == NULL);
}


// CHECK SIZE
template <class T>
int cBinaryTree<T>::size() const
/* Post: The number of entries in the binary tree is returned.  */
{ return recursive_size(root); }

// CHECK HEIGHT 
template <class T>
int cBinaryTree<T>::height() const
/* Post: The height of the binary tree is returned.  */
{ return recursive_height(root); }

// CLEAR 
template <class T>
void cBinaryTree<T>::clear()
/* all entries in the binary tree are removed and memory deallocated.  */
{ recursive_clear(root); }

 
// INSERT 
template <class T>
eErrorCode cBinaryTree<T>::insert(const T & x)
/* call recursive insert to add x to the binary tree */
{ return recursive_insert(root, x); }

// REMOVE 
template <class T>
eErrorCode cBinaryTree<T>::remove(const T & x)
/* call recursive remove x from the binary tree */
{ return recursive_remove(root, x); }

/* AUXILIARY FUNCTIONS 
   The actual work is done by  these recursive functions. The user
   cannot  call these directly because the user is never given access
   to a node pointer */

template <class T>
void cBinaryTree<T>::recursive_inorder(cBinaryNode<T> *sub_root,
                                            void (*visit)(T &))
/* Pre:  sub_root is either NULL or points to a subtree of
     the cBinaryTree.
Post: The subtree has been been traversed in inorder sequence.
Uses: The function recursive_inorder recursively */
{
   if(sub_root != NULL)
   {
      recursive_inorder(sub_root->left, visit);
      (*visit)(sub_root->data);
      recursive_inorder(sub_root->right, visit);
   }
}
 
template <class T>
void cBinaryTree<T>::recursive_preorder(cBinaryNode<T> *sub_root,
                                            void (*visit)(T &)) 
/* Pre:  sub_root is NULL or points to a subtree of the cBinaryTree.
Post: The subtree has been been traversed in preorder sequence.
Uses: The function recursive_preorder recursively */
{
   if(sub_root != NULL)
   {
      (*visit)(sub_root->data);
      recursive_inorder(sub_root->left, visit);
      recursive_inorder(sub_root->right, visit);
   }
}
 
template <class T>
void cBinaryTree<T>::recursive_postorder(cBinaryNode<T> *sub_root,
                                            void (*visit)(T &))
/* Pre:  sub_root is NULL or points to a subtree of the cBinaryTree.
Post: The subtree has been been traversed in postorder sequence.
Uses: The function recursive_postorder recursively */
{
   if(sub_root != NULL)
   {
      recursive_inorder(sub_root->left, visit);
      recursive_inorder(sub_root->right, visit);
      (*visit)(sub_root->data);
   }
}
 
template <class T>
eErrorCode cBinaryTree<T>::recursive_insert(cBinaryNode<T> * &sub_root,
                                            const T &data)
/* Pre:  sub_root is NULL or points to a subtree of the cBinaryTree.
Post: The T  has been inserted into the subtree: First check the height of 
the left and right sub-trees. Insert in the left sub-tree if its height 
is <= right sub-tree.
Uses: The functions recursive_insert, recursive_height */
{
   if(sub_root != NULL)
   {
      int l = recursive_height(sub_root->left);
      int r = recursive_height(sub_root->right);
      if (l > r)
      {
         // go right
         return recursive_insert(sub_root->right, data);
      }
      else // r >= l 
      {
         // go left
         return recursive_insert(sub_root->left, data);
      }
   }
   else
   {
      // reached end of tree
      sub_root = new cBinaryNode<T>(data);
   }
   
   return success;
}

template <class T>
eErrorCode cBinaryTree<T>::recursive_remove(cBinaryNode<T> * &sub_root,
                                            const T &data)
{
   if(sub_root == NULL)
      return not_present;

   if(sub_root->data == data) {
      return remove_root(sub);
   } else {
      // check left side
      if( recursive_remove(sub->left, data) == success)  return success;
      // check right side
      if( recursive_remove(sub->right, data) == success)  return success;
   }
   
   return not_present;
}


template <class T>
eErrorCode cBinaryTree<T>::remove_root(cBinaryNode<T> *&sub_root)
{
   cBinaryNode<T> *to_del = sub_root;
   
   if(sub_root->left == NULL)
      // 1 or 0 child node; leaf or has right child
      sub_root = sub_root->right;
   else if(sub->right == NULL)
      // 1 child node; has left child
      sub_root = sub_root->left;
   else
   {
      // 2 child nodes
      // predecessor method
      cBinaryNode<T> *prev = sub;
      to_del = sub_root->left;
      
      // get right most !NULL node
      while(to_del->right != NULL)
      {
         prev = to_del;
         to_del = to_del->right;
      }
      
      // copy data
      sub_root->data = to_del->data;

      // update link
      if(prev == sub_root)
         // did not move to the right
         prev->left = to_del->left;
      else
         // moved to the right
         prev->right = to_del->left;
   }

   delete to_del;

   return success;
}
 
template <class T>
int cBinaryTree<T>::recursive_size(cBinaryNode<T> *sub_root) const
/* Post: The number of entries in the subtree rooted at
      sub_root is returned.  */ 
{
   if (sub_root == NULL) return 0;
   return 1 + recursive_size(sub_root->left) + recursive_size(sub_root->right);
}
 
template <class T>
int cBinaryTree<T>::recursive_height(cBinaryNode<T> *sub_root) const
/* Post: The height of the subtree rooted at sub_root is returned.  */
{
   if (sub_root == NULL) return 0;
   int l = recursive_height(sub_root->left);
   int r = recursive_height(sub_root->right);
   if (l > r) return 1 + l;
   else return 1 + r;
}
 
template <class T>
void cBinaryTree<T>::recursive_clear(cBinaryNode<T> *&sub_root)
/* Post: The subtree rooted at sub_root is cleared.  */
{
   if(sub_root != NULL)
   {
      recursive_clear(sub_root->left);
      recursive_clear(sub_root->right);
      delete sub_root;
      sub_root = NULL;
   }
}

template <class T>
cBinaryNode<T> *cBinaryTree<T>::recursive_copy(const cBinaryNode<T> * const src)
/* Pre: current tree is empty
   Post: The subtree rooted at sub_root is copied to *this tree.  */
{
   cBinaryNode<T> *temp = NULL;

   if(src != NULL)
   {
      temp = new  cBinaryNode<T>(src->data);
      temp->left = recursive_copy(src->left);
      temp->right = recursive_copy(src->right);
   }

   return temp;
}

#endif

