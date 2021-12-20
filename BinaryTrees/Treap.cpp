#include "Treap.h"

template <typename T>
void Treap<T>::rotateLeft(TreapNode<T> *u)
{
    TreapNode<T> *w = u->right;
    w->parent = u->parent;
    if (w->parent)
        (w->parent->left == u) ? (w->parent->left = w) : (w->parent->right = w);
    u->right = w->left;
    if (u->right)
        u->right->parent = u;
    u->parent = w;
    w->left = u;
    if (u == this->r)
    {
        this->r = w;
        this->r->parent = NULL;
    }
}

template <typename T>
void Treap<T>::rotateRight(TreapNode<T> *u)
{
    TreapNode<T> *w = u->left;
    w->parent = u->parent;
    if(w->parent)
        (w->parent->left == u) ? (w->parent->left = w) : (w->parent->right = w);
    u->left = w->right;
    if(u->left)
        u->left->parent = u;
    u->parent = w;
    w->right = u;
    if(u == this->r)
    {
        this->r = w;
        this->r->parent = NULL;
    }
}

template <typename T>
bool Treap<T>::add(const T &x)
{
    TreapNode<T> *u = new TreapNode<T>(x, rand());
    if(BST<TreapNode<T>, T>::add(u))
    {
        bubbleUp(u);
        return true;
    }
    delete u;
    return false;
}

template <typename T>
void Treap<T>::bubbleUp(TreapNode<T> *u)
{
    while(u->parent && u->parent->p > u->p)
        if(u->parent->right)
            rotateLeft(u->parent);
        else
            rotateRight(u->parent);

    if(!u->parent)
        this->r = u;
}

template <typename T>
bool Treap<T>::remove(const T &x)
{
    TreapNode<T> *u = this->findLast(x);
    if(u && u->data == x)
    {
        trickleDown(u);
        this->splice(u);
        delete u;
        return true;
    }
    return false;
}

template <typename T>
void Treap<T>::trickleDown(TreapNode<T> *u)
{
    while(u->left || u->right)
        if(!u->left)
            rotateLeft(u);
        else if(!u->right)
            rotateRight(u);
        else if(u->left->p < u->right->p)
            rotateRight(u);
        else
            rotateLeft(u);
    if(u == this->r)
        this->r = u->parent;
}

template <typename T>
void Treap<T>::traverse(TreapNode<T> *u)
{
    if(!u)
        return;
    traverse(u->left);
    traverse(u->right);
}

template <typename T>
std::ostream &operator<<(std::ostream &output, const Treap<T> &t)
{
    if(!t.r)
        return output;
    std::cout << "DATA: " << t.r->data << ", PRIORITY: " << t.r->p << std::endl;
    operator<<(output, Treap<T>(t.r->left));
    operator<<(output, Treap<T>(t.r->right));
    return output;
}