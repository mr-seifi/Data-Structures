#include "BST.h"

template <typename Node, typename T>
T BST<Node, T>::findEQ(const T &x) const
{
    Node *w = this->r;
    while(w)
    {
        if(w->data > x)
            w = w->left;
        else if(w->data < x)
            w = w->right;
        else
            return w->x;
    }

    return NULL;
}

template <typename Node, typename T>
T BST<Node, T>::find(const T &x) const
{
    Node *w = this->r;
    Node *z = NULL;

    while(w)
    {
        if(w->data > x)
        {
            z = w;
            w = w->left;
        }
        else if(w->data < x)
            w = w->right;
        else
            return w->data;
    }

    return (z ? z->data : NULL);
}

template <typename Node, typename T>
Node *BST<Node, T>::findLast(const T &x)
{
    Node *w = this->r;
    Node *prev = NULL;
    while(w)
    {
        prev = w;
        if(w->data > x)
            w = w->left;
        else if(w->data < x)
            w = w->right;
        else
            return w;
    }

    return prev;
}

template <typename Node, typename T>
bool BST<Node, T>::addChild(Node *p, Node *u)
{
    if(!p || !this->n)
        this->r = u;
    else
    {
        if(u->data > p->data)
            p->right = u;
        else if(u->data < p->data)
            p->left = u;
        else
            return false;
        u->parent = p;
    }

    ++this->n;
    return true;
}

template <typename Node, typename T>
bool BST<Node, T>::add(const T &x)
{
    Node *p = findLast(x);
    Node *u = new Node(x);
    return addChild(p, u);
}

template <typename Node, typename T>
bool BST<Node, T>::add(Node *u)
{
    Node *p = findLast(u->data);
    return addChild(p, u);
}

template <typename Node, typename T>
void BST<Node, T>::splice(Node *u)
{
    Node *s, *p;
    if(u->left)
        s = u->left;
    else
        s = u->right;

    if(u == this->r)
    {
        this->r = s;
        p = NULL;
    }
    else
    {
        p = u->parent;
        if(p->left == u)
            p->left = s;
        else
            p->right = s;
    }
    if(s)
        s->parent = p;
    --this->n;
}

template <typename Node, typename T>
void BST<Node, T>::remove(Node *u)
{
    if(!u->left || !u->right)
    {
        splice(u);
        delete u;
    }
    else
    {
        Node *w = u->right;
        while(w->left)
            w = w->left;
        u->data = w->data;
        splice(w);
        delete w;
    }
}

template <typename Node, typename T>
std::ostream &operator<<(std::ostream &output, const BST<Node, T> &b)
{
    return output;
}