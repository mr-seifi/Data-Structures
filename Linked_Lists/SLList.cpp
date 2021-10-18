#include "SLList.h"

template <typename T>
SLList<T>::SLList()
{
    head = NULL;
    tail = NULL;
    n = 0;
}

template <typename T>
T SLList<T>::push(const T &x)
{
    Node<T> *u = new Node<T>(x);
    u->next = head;
    head = u;
    if(++n == 1)
        tail = u;
    return x;
}

template <typename T>
T SLList<T>::pop()
{
    if(n == 0)
        return NULL;
    T x = head->x;
    Node<T> *u = head;
    head = head->next;
    delete u;
    if(--n == 0)
        tail = NULL;
    return x;
}

template <typename T>
bool SLList<T>::add(const T &x)
{
    Node<T> *u = new Node<T>;
    u->x = x;
    if(++n == 1)
        head = u;
    else
        tail->next = u;
    tail = u;
    return true;
}

template <typename T>
T SLList<T>::remove()
{
    return pop();
}

template <typename T>
std::ostream &operator<<(std::ostream &output, const SLList<T> &b)
{
    for(auto it = b.head; it != NULL; it = it->next)
        output << it->x << '\t';
    return output;
}