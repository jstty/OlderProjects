//////////////////////////////////////////////////////////////////////////////
// Program Name:    cSTree.h
// Programmer:      Joseph E. Sutton
// Description:     AVL Balanced Binary Tree, Sorted and Searchable
// Start Date:      5/6/2004
// Last Updated:    5/19/2004
// Version:         1.50
//////////////////////////////////////////////////////////////////////////////

#ifndef SORT_TREE_H  
#define SORT_TREE_H

enum { LEFT = false, RIGHT = true};

inline int max(int a, int b)
{
    return (a > b) ? a : b;
}

template<class NDT>
class avlnode
{
protected:
    int depth;

public:
    NDT data;
    avlnode<NDT> *t[2];  // left, right array

    avlnode(NDT d = 0)
    {
        data = d;
        t[LEFT] = t[RIGHT] = NULL;
        depth = 0;
    }

    int Diff(bool dir) const
    {
        return GetDepth(dir) - GetDepth(!dir);
    }

    void UpdateDepth()
    {
        depth = 1 + max(GetDepth(LEFT), GetDepth(RIGHT));
    }

    int GetDepth(int dir=-1) const
    {
        int rval = 0;

        if(dir == LEFT)
            rval = (t[LEFT] == NULL) ? -1 : t[LEFT]->depth;
        else
            if(dir == RIGHT)
                rval = (t[RIGHT] == NULL) ? -1 : t[RIGHT]->depth;
            else
                rval = depth;

        return rval;
    }
};

template<class BTDT>
class cSTree
{
protected:
    avlnode<BTDT> *entry;   // entry into tree pointer
    avlnode<BTDT> **next;   // temp pointer to pointer
    int rval;               // return value
    bool toggle;            // when deleting 'toggle' tries to
                            // prevent systematic unbalancing

    void rcopy(avlnode<BTDT>* &pn, const avlnode<BTDT>* const s);
    void rrelease(avlnode<BTDT>* &pn);
    int  radd(avlnode<BTDT>* &pn, BTDT d);
    avlnode<BTDT> ** rfind(const avlnode<BTDT>* const &pn, BTDT d);
	// call rfind first before calling rdel to find node to delete
    int  rdel(avlnode<BTDT>** pn);
    void rshow(const avlnode<BTDT>* const pn) const;

    // checks and balances tree
    void rbalance(avlnode<BTDT>* &pn);
    // checks for AVL
    void check_avl(avlnode<BTDT>* &pn, bool dir);
    // rotates node to balance tree
    void rotate(avlnode<BTDT>* &pn, bool dir);
    // rotates twice to balance tree
    void dbl_rotate(avlnode<BTDT>* &pn, bool dir);


    // resursive walk
    void rwalk(const avlnode<BTDT>* const pn, 
               void *out,
               void(* callback)(void *, BTDT) ) const;

public:
    cSTree()
    {
        entry = NULL;
        next = NULL;
        toggle = false;
        rval = 0;
    }

    cSTree(const cSTree<BTDT> &src);        // copy constructor
    ~cSTree();                             // deconstructor
    const cSTree<BTDT> &operator =(const cSTree<BTDT> &src);
    
    void release();
    int  add(BTDT d);
    int  find(BTDT d); // return 0 is found, 1 if not
    int  del(BTDT d);
    void show();

    void walk(void *out, void(* callback)(void *, BTDT) );
};

// For MS VC++ 6
#ifdef WIN32
	#include "cSTree.cpp"
#endif
//

#endif // SORT_TREE_H
