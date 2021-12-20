#include "BT.h"

template <typename Node, typename T>
BT<Node, T>::BT()
{
    r = new Node;
    n = 0;
}

template <typename Node, typename T>
int BT<Node, T>::depth(Node *u) const
{
    int d = 0;
    while(u != r)
    {
        u = u->parent;
        ++d;
    }
    return d;
}

template <typename Node, typename T>
int BT<Node, T>::size(Node *u) const
{
    if(!u)
        return 0;
    return 1 + size(u->left) + size(u->right);
}

template <typename Node, typename T>
int BT<Node, T>::height(Node *u) const
{
    if(!u)
        return -1;
    return 1 + std::max(height(u->left), height(u->right));
}

template <typename Node, typename T>
void BT<Node, T>::traverse(Node *u) const
{
    if(!u)
        return;
    traverse(u->left);
    traverse(u->right);
}