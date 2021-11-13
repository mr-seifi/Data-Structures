#include "LinearHashTable.h"

template <typename T>
LinearHashTable<T>::LinearHashTable()
{

}

template <typename T>
T *LinearHashTable<T>::find(const T &x)
{
    int i = hash(x);
    while(!t[i].null)
    {
        if(!t[i].del && t[i] == x)
            return &t[i];
        i = (i == t.len()) ? 0 : i + 1;
    }
    return NULL;
}

template <typename T>
bool LinearHashTable<T>::add(const T &x)
{
    if(find(x))
        return false;
    if(2 * (q + 1) > t.len())
        resize();
    int i = hash(x);
    while(!t[i].null && !t[i].del)
        i = (i == t.len() - 1) ? 0 : i + 1;
    if(t[i].null)
        ++q;
    ++n;
    t[i] = x;
    return true;
}

template <typename T>
T *LinearHashTable<T>::remove(const T &x)
{
    int i = hash(x);
    while(!t[i].null)
    {
        if(!t[i].del && t[i] == x)
        {
            T y = t[i];
            t[i].del = true;
            --n;
            if(8 * n < t.len())
                resize();
            return y;
        }
        i = (i == t.len() - 1) ? 0 : i + 1;
    }
    return NULL;
}

template <typename T>
void LinearHashTable<T>::resize()
{
    int dTemp = 1;
    while((1 << dTemp) < 3 * n)
        ++dTemp;
    Array<Node<T>> t_new(1 << d);
    struct Node<T> null = {0, true, false};
    for(int k = 0; k < t_new.len(); ++k)
        t_new[k] = null;
    for(int k = 0; k < t.len(); ++k)
        if(!t[k].null && !t[k].del)
        {
            int i = hash(t[i]);
            while(!t_new[i].null)
                i = (i == t.len() - 1) ? 0 : i + 1;
            t_new[i] = t[k];
        }
    t = t_new;
}