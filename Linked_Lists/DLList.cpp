#include "DLList.h"

template <typename T>
DLList<T>::DLList()
{
    dummy.next = &dummy;
    dummy.prev = &dummy;
    n = 0;
}

template <typename T>
unsigned int DLList<T>::size() const
{
    return n;
}

template <typename T>
DLNode<T> *DLList<T>::getNode(int i)
{
    DLNode<T> *u;
    if(i < n / 2)
    {
        u = dummy.next;
        for(int j = 0; j < i; ++j)
            u = u->next;
    }
    else
    {
        u = &dummy;
        for(int j = n; j > i; --j)
            u = u->prev;
    }
    return u;
}

template <typename T>
T DLList<T>::get(int i)
{
    return getNode(i)->x;
}

template <typename T>
T DLList<T>::set(int i, const T &x)
{
    getNode(i)->x = x;
    return x;
}

template <typename T>
DLNode<T> *DLList<T>::addBefore(DLNode<T> *w, const T &x)
{
    DLNode<T> *u = new DLNode<T>;
    u->x = x;
    u->prev = w->prev;
    u->next = w;
    u->next->prev = u;
    u->prev->next = u;
    ++n;
    return u;
}

template <typename T>
void DLList<T>::add(int i, const T &x)
{
    addBefore(getNode(i), x);
}

template <typename T>
void DLList<T>::remove(DLNode<T> *w)
{
    w->prev->next = w->next;
    w->next->prev = w->prev;
    delete w;
    --n;
}

template <typename T>
T DLList<T>::remove(int i)
{
    assert(i >= 0 && i < n);
    DLNode<T> *temp = getNode(i);
    T x = temp->x;
    remove(temp);
    return x;
}

template <typename T>
std::ostream &operator<<(std::ostream &output, const DLList<T> &b)
{
    DLNode<T> *temp = b.dummy.next;
    for(int i = 0; i < b.n; ++i, temp = temp->next)
        output << temp->x << '\t';
    return output;
}