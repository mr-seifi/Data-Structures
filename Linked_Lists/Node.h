#ifndef DATA_STRUCTURES_NODE_H
#define DATA_STRUCTURES_NODE_H

#include <iostream>

template <typename T>
class Node
{
public:
    T x;
    Node *next;
    Node();
    explicit Node(const T&);

};

template <typename T>
Node<T>::Node()
{
    x = 0;
    next = NULL;
}

template <typename T>
Node<T>::Node(const T &x0)
{
    x = x0;
    next = NULL;
}

#endif //DATA_STRUCTURES_NODE_H
