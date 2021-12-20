#ifndef DATA_STRUCTURES_BTNODE_H
#define DATA_STRUCTURES_BTNODE_H

#include <iostream>

template <typename Node, typename T>
class BTNode
{
public:
    Node *left;
    Node *right;
    Node *parent;
    BTNode()
    {
        left = right = parent = NULL;
    }
};

#endif //DATA_STRUCTURES_BTNODE_H
