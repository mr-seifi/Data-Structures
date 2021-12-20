#ifndef DATA_STRUCTURES_BT_H
#define DATA_STRUCTURES_BT_H

#include <iostream>

template <typename Node, typename T>
class BT {
public:
    Node *r;
    int n;
    BT();
    int depth(Node*) const;
    int size(Node*) const;
    int height(Node*) const;
    virtual void traverse(Node*) const;
};


#endif //DATA_STRUCTURES_BT_H
