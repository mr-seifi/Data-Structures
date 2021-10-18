#ifndef DATA_STRUCTURES_SLLIST_H
#define DATA_STRUCTURES_SLLIST_H

#include "Node.h"
#include <iostream>

template <typename T>
class SLList {
    template <typename U>
    friend std::ostream &operator<<(std::ostream&, const SLList<U>&);
public:
    SLList();
    unsigned int size() const { return n; };
    T push(const T&);
    T pop();
    bool add(const T&);
    T remove();
private:
    Node<T> *head;
    Node<T> *tail;
    int n;
};


#endif //DATA_STRUCTURES_SLLIST_H
