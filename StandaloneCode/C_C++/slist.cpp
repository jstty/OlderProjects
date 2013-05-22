//////////////////////////////////////////////////////////////////////////////
// Program Name:	slist.cpp
// Programmer:		Joseph E. Sutton
// Description:	Sorted Linked List (Template)
// Start Date:		3/18/2004
// Last Updated:	
// Version:			1.00
//////////////////////////////////////////////////////////////////////////////

// FindNode return's pointer to node pointer
// with data value greater then input d
template <class DT>
d_node<DT> * const * sList<DT>::FindNode(DT d) const
{
    // walk through list
    d_node<DT> * const *tpdn = &start;
    // while (NOT at end) AND (data less then d)
    while( (*tpdn != NULL) && ( (*tpdn)->GetData() < d ) )
        tpdn = &((*tpdn)->next);

    return tpdn;
}

template <class DT>
sList<DT>::sList()
{
    start = end = NULL;
}


// copy constructor
template <class DT>
sList<DT>::sList(const sList<DT> &src)
{
    start = end = NULL;
    d_node<DT> **tpdn = &start;
    temp = src.start;
    
    while(temp != NULL)
    {
        // set new node's data
        prev = new d_node<DT>(temp->GetData());
        // set pointer to node pointer to new node pointer
        *tpdn = prev;                       
        // set new node's next to pointer to node pointer to next
        tpdn = &(prev->next);
        // set temp pointer to temp's next
        temp = temp->next;
    }
}

template <class DT>
sList<DT>::~sList()
{
    release();
}


// deallocate all in link list
template <class DT>
void sList<DT>::release()
{
    while( start != NULL )
    {
        temp = start->next;
        delete start;
        start = temp;
    }
    end = NULL;
}

template <class DT>
bool sList<DT>::insert(DT d)
{
    bool rval = true;
    d_node<DT> **tpdn = (d_node<DT> **)FindNode(d);

    // if (NOT found) OR (data NOT d)
    if( (*tpdn == NULL) || ((*tpdn)->GetData() != d) )
    {
        rval = true;
        temp = new d_node<DT>(d, *tpdn);
        *tpdn = temp;
    }

    return rval;
}

template <class DT>
double sList<DT>::get()
{
    DT d_tmp = 0;
    if( start != NULL )
    {
        d_tmp = start->GetData();
        temp = start->next;
        delete start;
        start = temp;
    }
    
    return d_tmp;
}

template <class DT>
bool sList<DT>::find(DT d) const
{
    d_node<DT> * const *tpdn = FindNode(d);
    // return TRUE if (not NULL) AND (data equal d)
    return ((*tpdn != NULL) && ((*tpdn)->GetData() == d));
}

template <class DT>
bool sList<DT>::erase(DT d)
{
    bool rval = false;
    d_node<DT> **tpdn = (d_node<DT> **)FindNode(d);

    if((*tpdn != NULL) && ((*tpdn)->GetData() == d))
    {
        // erase node
        rval = true;
        temp = (*tpdn)->next;
        delete *tpdn;
        *tpdn = temp;
    }

    return rval;
}

