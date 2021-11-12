#include "ChainedHashTable.h"
#include "Node.h"

template <typename T>
ChainedHashTable<T>::ChainedHashTable(unsigned int d)
                    : t(1 << d)
{
    this->n = 0;
    this->d = d;
}

template <typename T>
bool ChainedHashTable<T>::add(const T &x)
{
    if(find(x)) return false;
    if(n + 1 > t.capacity())
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
    ArrayStack<ArrayStack<T>> b(t.size() * 2);
    ++d;
    for(int i = 0; i < t.size(); ++i)
        for(int j = 0; j < t[i].size(); ++j)
            b[hash(t[i][j])].add(b[hash(t[i][j])].size(), t[i][j]);
    t = b;
}

template <typename T>
unsigned int ChainedHashTable<T>::hash(const T &x)
{
    return ((unsigned int) (4102541685) * hashCode(x) >> (32 - d));
}

template <typename T>
unsigned int ChainedHashTable<T>::hashCode(const T &x) const
{
    return x; // Identity function
}