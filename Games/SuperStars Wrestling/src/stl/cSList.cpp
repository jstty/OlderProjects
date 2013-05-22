//////////////////////////////////////////////////////////////////////////////
// Program Name:	cSList.cpp
// Programmer:		Joseph E. Sutton
// Description:	Sorted Linked List (Template)
// Start Date:		3/18/2004
// Last Updated:	
// Version:			1.00
//////////////////////////////////////////////////////////////////////////////

// FindNode return's pointer to node pointer
// with data value greater then input d
template <class DT>
d_node<DT> * const * cSList<DT>::FindNode(DT d) const
{
    // walk through list
    d_node<DT> * const *tpdn = &start;
    // while (NOT at end) AND (data less then d)
    while( (*tpdn != NULL) && ( (*(*tpdn)->GetData()) < d ) )
    // while (NOT at end) AND (data greater then d)
    //while( (*tpdn != NULL) && ( (*tpdn)->GetData() > d ) )
        tpdn = &((*tpdn)->next);

    return tpdn;
}

template <class DT>
cSList<DT>::cSList()
{
    lsize = 0;
    start = end = NULL;
}


// copy constructor
template <class DT>
cSList<DT>::cSList(const cSList<DT> &src)
{
    //lsize = src.lsize;
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
cSList<DT>::~cSList()
{
    clear();
}


// deallocate all in link list
template <class DT>
void cSList<DT>::clear()
{
    while( start != NULL )
    {
        temp = start->next;
        delete start;
        start = temp;
    }
    start = NULL;
    end = NULL;
    lsize = 0;
}

template <class DT>
bool cSList<DT>::insert(DT d)
{
    bool rval = true;
    d_node<DT> **tpdn = (d_node<DT> **)FindNode(d);

    // if (NOT found) OR (data NOT d)
    if( (*tpdn == NULL) || (*((*tpdn)->GetData()) != d) )
    {
        rval = true;
        temp = new d_node<DT>(d, *tpdn);
        *tpdn = temp;
        ++lsize;
    }

    return rval;
}

template <class DT>
DT cSList<DT>::pop()
{
    DT d_tmp;
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
DT *cSList<DT>::find(DT d) const
{
    d_node<DT> * const *tpdn = FindNode(d);
    // return TRUE if (not NULL) AND (data equal d)
    if((*tpdn != NULL) && ((*tpdn)->GetData() == d)) {
        return &((*tpdn)->GetData());
    } else {
        return NULL;
    }
}

template <class DT>
bool cSList<DT>::erase(DT d)
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
        --lsize;
    }

    return rval;
}

template <class DT>
void cSList<DT>::walk(void *out, void(* callback)(void *, DT) )
{
    temp = start;
    while( temp != NULL )
    {
        callback(out, temp->GetData() );
        temp = temp->next;
    }
}

template <class DT>
DT *cSList<DT>::front()
{
   if(start != NULL)
   {
      last = start;
      return last->GetData();
   }

   return NULL;
}


template <class DT>
DT *cSList<DT>::next()
{
   if(last != NULL)
   {
      last = last->next;

      if(last == NULL)
         return NULL;
      else
         return last->GetData();
   }

   return NULL;
}
