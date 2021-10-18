#ifndef DATA_STRUCTURES_DLLIST_H
#define DATA_STRUCTURES_DLLIST_H

#include "Node.h"
#include <cassert>

template <typename T>
class DLNode : public Node<T>
{
public:
    DLNode<T> *prev;
    DLNode<T> *next;
    DLNode() : Node<T>() { prev = NULL; next = NULL; }
};

template <typename T>
class DLList {
    template <typename U>
    friend std::ostream &operator<<(std::ostream&, const DLList<U>&);
public:
    DLList();
    unsigned int size() const;
    DLNode<T> *getNode(int i);
    T get(int i);
    T set(int i, const T&);
    DLNode<T> *addBefore(DLNode<T>*, const T&);
    void add(int i, const T&);
    void remove(DLNode<T>*);
    T remove(int i);

private:
    DLNode<T> dummy;
    unsigned int n;
};


#endif //DATA_STRUCTURES_DLLIST_H
