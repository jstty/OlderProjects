//////////////////////////////////////////////////////////////////////////////
// Program Name:    b-tree.cpp
// Programmer:      Joseph E. Sutton
// Description:     Binary Tree
// Start Date:      5/6/2004
// Last Updated:    5/13/2004
// Version:         1.20
//////////////////////////////////////////////////////////////////////////////

#include <iostream.h>
#include <stdlib.h>
#include <assert.h>

class btnode
{
public:
    float data;
    btnode *ltree,
           *rtree;

    btnode(float d = 0) 
    {
        data = d;
        ltree = rtree = NULL;
    }
};

class btree
{
protected:
    btnode *entry,
          **next;
    int rval;       // return value
    bool toggle; 

    void rcopy(btnode* &pn, const btnode * const s);
    void rrelease(btnode* &pn);
    int  radd(btnode* &pn, float d);
    btnode ** rfind(const btnode * const &pn, float d);
    int  rdel(btnode** pn);     // call rfind first to find pointer
    void rshow(const btnode * const pn);

public:
    btree()
    {
        entry = NULL;
        next = NULL;
        toggle = false;
        rval = 0;
    }

    btree(const btree &src);              // copy constructor
    ~btree();                             // deconstructor
    const btree &operator =(const btree &src);
    
    void release();
    int  add(float d);
    int  find(float d);
    int  del(float d);
    void show();
};

void btree::rcopy(btnode* &pn, const btnode * const s)
{
    if(s != NULL)
    {
        pn = new btnode( s->data );
        assert(pn != NULL);
        rcopy(pn->ltree, s->ltree);
        rcopy(pn->rtree, s->rtree);
    }
}

void btree::rrelease(btnode* &pn)
{
    if(pn != NULL)
    {
        rrelease(pn->ltree);
        rrelease(pn->rtree);
        
        // leaf
        delete pn;
    }
}

int btree::radd(btnode* &pn, float d)
{
    if(pn != NULL)
        if( pn->data > d )
            rval = radd(pn->ltree, d);
        else
            if( pn->data < d )
                rval = radd(pn->rtree, d);
            else // same value
                rval = 0;
    else // add
    {
        rval = 1;
        pn = new btnode(d);
    }

    return rval;
}

btnode ** btree::rfind(const btnode * const &pn, float d)
{
    if(pn != NULL)
    {
        if( pn->data > d )
            next = rfind(pn->ltree, d);
        else if( pn->data < d )
            next = rfind(pn->rtree, d);
        else // found
            next = (btnode **)(&pn);
    }
    else
        next = NULL;

    return next;
}

int btree::rdel(btnode **pn)
{
    if(pn != NULL)
    {
        rval = 1;
        btnode *temp = *pn;
        
        if(temp->ltree == NULL)     // twig/leaf may have right tree
        {
            *pn = temp->rtree;      // set current p2p to right tree
            delete temp;            // deallocate
        }
        else
            if(temp->rtree == NULL) // twig/leaf may have left tree
            {
                *pn = temp->ltree;  // set current p2p to left tree
                delete temp;        // deallocate
            }
            else                    // branch
            {
                if(toggle++)
                {
                    pn = &((*pn)->rtree);       // move one right
                    while((*pn)->ltree != NULL) // move left till end
                        pn = &((*pn)->ltree);
                }
                else
                {
                    pn = &((*pn)->ltree);       // move one left
                    while((*pn)->rtree != NULL) // move right till end
                        pn = &((*pn)->rtree);
                }
                
                temp->data = (*pn)->data;       // set data
                rdel(pn);                       // delete twig/leaf
            }
    }
    else
        rval = 0;

    return rval;
}

btree::btree(const btree &src)
{
    entry = NULL;
    next = NULL;
    toggle = false;
    rval = 0;
    rcopy(entry, src.entry); 
}

btree::~btree()
{
    release();
}

const btree &btree::operator =(const btree &src)
{
    release();
    rcopy(entry, src.entry);
    return *this;
}

void btree::release()
{
    rrelease(entry);
    entry = NULL;
}

int btree::add(float d)
{
    return radd(entry, d);
}

int btree::find(float d)
{
    return (rfind(entry, d) != NULL);
}

int btree::del(float d)
{
    return rdel( rfind(entry, d) );
}

void btree::rshow(const btnode * const pn)
{
    if(pn != NULL)
    {
        rshow(pn->ltree);
        cout << pn->data << ' ';
        rshow(pn->rtree);
    }
}

void btree::show()
{
    rshow(entry);
    cout << '\n';
}

