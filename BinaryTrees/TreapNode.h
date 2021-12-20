#ifndef DATA_STRUCTURES_TREAPNODE_H
#define DATA_STRUCTURES_TREAPNODE_H

#include "BTNode.h"

template <typename T>
class TreapNode : public BTNode<TreapNode<T>, T>
{
public:
    T data;
    int p;
    TreapNode() : BTNode<TreapNode<T>, T>() { p = 0; };
    TreapNode(int d) : BTNode<TreapNode<T>, T>() { data = d; p = 0; };
    TreapNode(int d, int p) : BTNode<TreapNode<T>, T>() { data = d; this->p = p; };
};

#endif //DATA_STRUCTURES_TREAPNODE_H
