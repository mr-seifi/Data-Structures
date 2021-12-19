#ifndef DATA_STRUCTURES_BTNODE_H
#define DATA_STRUCTURES_BTNODE_H

#include <iostream>

template <typename T>
class BTNode
{
public:
    BTNode *left;
    BTNode *right;
    BTNode *parent;
    T data;
    BTNode()
    {
        left = right = parent = NULL;
    }
    BTNode(const T &d)
    {
        left = right = parent = NULL;
        data = d;
    }

};

#endif //DATA_STRUCTURES_BTNODE_H
