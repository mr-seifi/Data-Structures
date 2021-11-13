#ifndef DATA_STRUCTURES_LINEARHASHTABLE_H
#define DATA_STRUCTURES_LINEARHASHTABLE_H

#include "Array.h"
template <typename T>
struct Node
{
    T data;
    bool null = false;
    bool del = false;
};

template <typename T>
class LinearHashTable {
public:
    LinearHashTable();
    T *find(const T&);
    bool add(const T&);
    T *remove(const T&);
    unsigned int hash(const T&);
    void resize();
private:
    Array<Node<T>> t;
    int n;
    int q;
    int d;
};


#endif //DATA_STRUCTURES_LINEARHASHTABLE_H
