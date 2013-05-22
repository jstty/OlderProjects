//////////////////////////////////////////////////////////////////////////////
// Program Name:    stack.cpp
// Programmer:      Joseph E. Sutton
// Description:     Stack
// Start Date:      4/22/2004
// Last Updated:    4/30/2004
// Version:         1.20
//////////////////////////////////////////////////////////////////////////////

#include <iostream.h>
#include <stdlib.h>
#include <string.h>

template<class NDT>
class gnode
{
protected:
    NDT data;

public:
    gnode<NDT> * next;
    gnode(NDT d = 0, gnode<NDT> *n = NULL) : data(d), next(n) {}

    NDT GetData(){ return data; }
};

template<class SDT>
class stack
{
protected:
    gnode<SDT> *start,
               *temp;

private:
    void copy(const stack<SDT> &src);
    void release_all();

public:
    stack(){ start = temp = NULL; } // default constructor
    stack(const stack<SDT> &src);   // copy constructor
    ~stack();                       // deconstructor

    const stack<SDT> &operator =(const stack<SDT> &src);

    bool empty();
    void push(SDT val);
    SDT pop();
};

// copy
template<class SDT>
void stack<SDT>::copy(const stack<SDT> &src)
{
    start = NULL;
    gnode<SDT> **tpdn = &start;
    gnode<SDT> *prev = NULL;
    temp = src.start;
    
    while(temp != NULL)
    {
        // set new node's data
        prev = new gnode<SDT>(temp->GetData());
        // set pointer to node pointer to new node pointer
        *tpdn = prev;                       
        // set new node's next to pointer to node pointer to next
        tpdn = &(prev->next);
        // set temp pointer to temp's next
        temp = temp->next;
    }
}

// release_all
template<class SDT>
void stack<SDT>::release_all()
{
    while( start != NULL )
    {
        temp = start->next;
        delete start;
        start = temp;
    }
}

// copy constructor
template<class SDT>
stack<SDT>::stack<SDT>(const stack<SDT> &src)
{
    release_all();
    copy(src);
}

// deconstructor
template<class SDT>
stack<SDT>::~stack<SDT>()
{
    release_all();
}

// simple assinment
template<class SDT>
const stack<SDT> &stack<SDT>::operator =(const stack<SDT> &src)
{
    release_all();
    copy(src);
    return *this;
}

//
template<class SDT>
bool stack<SDT>::empty()
{
    return bool(start == NULL);
}

template<class SDT>
void stack<SDT>::push(SDT val)
{
    temp = new gnode<SDT>(val, start);
    start = temp;
}

template<class SDT>
SDT stack<SDT>::pop()
{
    SDT dtmp;

    if( !empty() )
    {
        dtmp = start->GetData();
        temp = start->next;
        delete start;
        start = temp;
    }
    
    return dtmp;
}

