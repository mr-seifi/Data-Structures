#ifndef DATA_STRUCTURES_CHAINEDHASHTABLE_H
#define DATA_STRUCTURES_CHAINEDHASHTABLE_H

#include "ArrayStack.h"

template <typename T>
class ChainedHashTable {
public:
    ChainedHashTable(unsigned int = (1 << ((1 << 3) + 1)));
    bool add(const T&);
    bool find(const T&);
    bool remove(const T&);
    int hash(const T&, unsigned int = (1 << 3));
    int hashCode(const T&) const;
    void resize();

private:
    ArrayStack<ArrayStack<T>> t;
    int n;
};


#endif //DATA_STRUCTURES_CHAINEDHASHTABLE_H
