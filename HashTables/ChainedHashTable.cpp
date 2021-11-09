#include "ChainedHashTable.h"
#include "Node.h"

template <typename T>
ChainedHashTable<T>::ChainedHashTable(unsigned int n)
                   : t(n)
{
    this->n = 0;
}

template <typename T>
bool ChainedHashTable<T>::add(const T &x)
{
    if(find(x)) return false;
    if(n + 1 > t.size())
        resize();
    int j = hash(x);
    t[j].add(t[j].size(), x);
    ++n;
    return true;
}

template <typename T>
bool ChainedHashTable<T>::find(const T &x)
{
    int j = hash(x);
    for(int i = 0; i < t[j].size(); ++i)
        if(t[j][i] == x)
            return true;

    return false;
}

template <typename T>
bool ChainedHashTable<T>::remove(const T &x)
{
    int j = hash(x);
    for(int i = 0; i < t[j].size(); ++i)
        if(t[j][i] == x)
        {
            t[j].remove(i);
            --n;
            return true;
        }
    return false;
}

template <typename T>
void ChainedHashTable<T>::resize()
{
    ArrayStack<ArrayStack<T>> temp = t;
    t = ArrayStack<ArrayStack<T>>(temp.size() * 2);
    for(int i = 0; i < temp.size(); ++i)
        for(int j = 0; j < temp[i].size(); ++j)
            t[hash(temp[i][j])].add(j, temp[i][j]);
}

template <typename T>
int ChainedHashTable<T>::hash(const T &x, unsigned int d)
{
    unsigned int g = (((unsigned int) ((1 << 32) - 5) * hashCode(x)) >> (32 - d));
    return ((unsigned int) ((1 << 32) - 5) * hashCode(x)) >> (32 - d);
}

template <typename T>
int ChainedHashTable<T>::hashCode(const T &x) const
{
    return x;
}