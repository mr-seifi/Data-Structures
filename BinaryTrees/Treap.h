#ifndef DATA_STRUCTURES_TREAP_H
#define DATA_STRUCTURES_TREAP_H

#include "BST.h"
#include "TreapNode.h"

template <typename T>
class Treap : public BST<TreapNode<T>, T>{
    template <typename U>
    friend std::ostream &operator<<(std::ostream&, const Treap<U>&);
public:
    Treap() {};
    Treap(TreapNode<T> *r) { this->r = r; }
    void rotateLeft(TreapNode<T>*);
    void rotateRight(TreapNode<T>*);
    bool add(const T&);
    void bubbleUp(TreapNode<T>*);
    bool remove(const T&);
    void trickleDown(TreapNode<T>*);
    void traverse(TreapNode<T>*);
};


#endif //DATA_STRUCTURES_TREAP_H
