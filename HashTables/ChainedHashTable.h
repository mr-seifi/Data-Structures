#ifndef DATA_STRUCTURES_CHAINEDHASHTABLE_H
#define DATA_STRUCTURES_CHAINEDHASHTABLE_H

#include "ArrayStack.h"

template <typename T>
class ChainedHashTable {
public:
    ChainedHashTable(unsigned int = 8);
    bool add(const T&);
    bool find(const T&);
    bool remove(const T&);
    unsigned int hash(const T&);
    unsigned int hashCode(const T&) const;
    void resize();

private:
    ArrayStack<ArrayStack<T>> t;
    int n;
    int d;
};


#endif //DATA_STRUCTURES_CHAINEDHASHTABLE_H
