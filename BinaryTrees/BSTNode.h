#ifndef DATA_STRUCTURES_BSTNODE_H
#define DATA_STRUCTURES_BSTNODE_H

#include "BTNode.h"

template <typename T>
class BSTNode : public BTNode<BSTNode<T>, T>
{
public:
    T data;
    BSTNode() : BTNode<BSTNode<T>, T>() {};
    BSTNode(const T &d) : BTNode<BSTNode<T>, T>() { data = d; };
};

#endif //DATA_STRUCTURES_BSTNODE_H
