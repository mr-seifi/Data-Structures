#ifndef DATA_STRUCTURES_NODE_H
#define DATA_STRUCTURES_NODE_H

template <typename T>
class Node
{
public:
    Node();
    explicit Node(T);
    T &getX() { return x; };
    Node *getNext() { return next; };

private:
    T x;
    Node *next;
};

template <typename T>
Node<T>::Node()
{
    x = 0;
    next = NULL;
}

template <typename T>
Node<T>::Node(T x0)
{
    x = x0;
    next = NULL;
}

#endif //DATA_STRUCTURES_NODE_H
