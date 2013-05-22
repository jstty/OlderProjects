//////////////////////////////////////////////////////////////////////////////
// Program Name:    stree.cpp
// Programmer:      Joseph E. Sutton
// Description:     AVL Balanced Binary Tree, Sorted and Searchable
// Start Date:      5/6/2004
// Last Updated:    5/19/2004
// Version:         1.50
//////////////////////////////////////////////////////////////////////////////

template<class BTDT>
void sTree<BTDT>::rcopy(avlnode<BTDT>* &pn, const avlnode<BTDT>* const s)
{
    if(s != NULL)
    {
        pn = new avlnode<BTDT>( s->data );
        assert(pn != NULL);
        rcopy(pn->t[LEFT], s->t[LEFT]);
        rcopy(pn->t[RIGHT], s->t[RIGHT]);
    }
}

template<class BTDT>
void sTree<BTDT>::rrelease(avlnode<BTDT>* &pn)
{
    if(pn != NULL)
    {
        rrelease(pn->t[LEFT]);
        rrelease(pn->t[RIGHT]);
        
        // leaf
        delete pn;
    }
}

template<class BTDT>
int sTree<BTDT>::radd(avlnode<BTDT>* &pn, BTDT d)
{
    if(pn != NULL)
    {
        if( pn->data > d )
        {
            rval = radd(pn->t[LEFT], d);
            check_avl(pn, LEFT);
        }
        else
            if( pn->data < d )
            {
                rval = radd(pn->t[RIGHT], d);
                check_avl(pn, RIGHT);
            }
            else // same value
                rval = 0;
    }
    else // add
    {
        rval = 1;
        pn = new avlnode<BTDT>(d);
    }

    return rval;
}

template<class BTDT>
avlnode<BTDT> ** sTree<BTDT>::rfind(const avlnode<BTDT>* const &pn, BTDT d)
{
    if(pn != NULL)
    {
        if( pn->data > d )
            next = rfind(pn->t[LEFT], d);
        else if( pn->data < d )
            next = rfind(pn->t[RIGHT], d);
        else // found
            next = (avlnode<BTDT> **)(&pn);
    }
    else
        next = NULL;

    return next;
}

template<class BTDT>
int sTree<BTDT>::rdel(avlnode<BTDT> **pn)
{
    if(pn != NULL)
    {
        rval = 1;
        avlnode<BTDT> *temp = *pn;
        
        if(temp->t[LEFT] == NULL)   // twig/leaf may have right tree
        {
            *pn = temp->t[RIGHT];   // set current p2p to right tree
            delete temp;            // deallocate
        }
        else
            if(temp->t[RIGHT] == NULL) // twig/leaf may have left tree
            {
                *pn = temp->t[LEFT];   // set current p2p to left tree
                delete temp;           // deallocate
            }
            else                       // branch
            {
                if(toggle++)
                {
                    pn = &((*pn)->t[RIGHT]);       // move one right
                    while((*pn)->t[LEFT] != NULL)  // move left till end
                        pn = &((*pn)->t[LEFT]);
                }
                else
                {
                    pn = &((*pn)->t[LEFT]);        // move one left
                    while((*pn)->t[RIGHT] != NULL) // move right till end
                        pn = &((*pn)->t[RIGHT]);
                }
                
                temp->data = (*pn)->data;          // set data
                rdel(pn);                          // delete twig/leaf
            }
    }
    else
        rval = 0;

    return rval;
}

template<class BTDT>
void sTree<BTDT>::rshow(const avlnode<BTDT>* const pn) const
{
    if(pn != NULL)
    {
        rshow(pn->t[LEFT]);
        cout << pn->data << ' ';
        rshow(pn->t[RIGHT]);
    }
}

template<class BTDT>
void sTree<BTDT>::rbalance(avlnode<BTDT>* &pn)
{
    if(pn != NULL)
    {
        rbalance(pn->t[LEFT]);
        rbalance(pn->t[RIGHT]);

        check_avl(pn, LEFT);
        check_avl(pn, RIGHT);
    }
}

template<class BTDT>
void sTree<BTDT>::check_avl(avlnode<BTDT>* &pn, bool dir)
{
    if(dir == LEFT)
    {
        if(pn->Diff(LEFT) > 1)
        {
           if(pn->t[LEFT]->GetDepth(RIGHT) < pn->t[LEFT]->GetDepth(LEFT))
               rotate(pn, LEFT);
           else
               dbl_rotate(pn, LEFT);
        }
        else
            pn->UpdateDepth();
    }

    if(dir == RIGHT)
    {
        if(pn->Diff(RIGHT) > 1)
        {
           if(pn->t[RIGHT]->GetDepth(RIGHT) > pn->t[RIGHT]->GetDepth(LEFT))
               rotate(pn, RIGHT);
           else
               dbl_rotate(pn, RIGHT);
        }
        else
            pn->UpdateDepth();
    }
}

template<class BTDT>
void sTree<BTDT>::rotate(avlnode<BTDT>* &pn, bool dir)
{
    bool odir = !dir;
    avlnode<BTDT>* temp = pn->t[dir];
    
    pn->t[dir] = temp->t[odir];
    pn->UpdateDepth();
    temp->t[odir] = pn;
    pn = temp;
    pn->UpdateDepth();
}

template<class BTDT>
void sTree<BTDT>::dbl_rotate(avlnode<BTDT>* &pn, bool dir)
{
    bool odir = !dir;

    rotate(pn->t[dir], odir);
    rotate(pn, dir);
}

template<class BTDT>
sTree<BTDT>::sTree<BTDT>(const sTree<BTDT> &src)
{
    entry = NULL;
    next = NULL;
    toggle = false;
    rval = 0;
    rcopy(entry, src.entry); 
}

template<class BTDT>
sTree<BTDT>::~sTree<BTDT>()
{
    release();
}

template<class BTDT>
const sTree<BTDT> &sTree<BTDT>::operator =(const sTree<BTDT> &src)
{
    release();
    rcopy(entry, src.entry);
    return *this;
}

template<class BTDT>
void sTree<BTDT>::release()
{
    rrelease(entry);
    entry = NULL;
}

template<class BTDT>
int sTree<BTDT>::add(BTDT d)
{
    return radd(entry, d);
}

template<class BTDT>
int sTree<BTDT>::find(BTDT d)
{
    return (rfind(entry, d) != NULL);
}

template<class BTDT>
int sTree<BTDT>::del(BTDT d)
{
    next = rfind(entry, d);
    rval = rdel( next );
    if(rval)
        rbalance(*next);

    return rval;
}

template<class BTDT>
void sTree<BTDT>::show()
{
    rshow(entry);
    cout << '\n';
}
