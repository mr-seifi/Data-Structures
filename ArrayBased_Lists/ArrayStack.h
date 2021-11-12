#ifndef DATA_STRUCTURES_ARRAYSTACK_H
#define DATA_STRUCTURES_ARRAYSTACK_H

#include <iostream>
#include "Array.h"

template <typename T>
class ArrayStack
{
    template <typename U>
    friend std::ostream &operator<<(std::ostream&, const ArrayStack<U>&);
public:
    ArrayStack();
    explicit ArrayStack(unsigned int);
    ArrayStack(unsigned int, const T&);
    unsigned int size() const;
    unsigned int capacity() const;
    T& get(unsigned int);
    T set(unsigned int, const T&);
    void add(unsigned int, const T&);
    T remove(unsigned int);
    void resize();
    T& operator[](int subscript);
    ArrayStack<T> &operator=(const ArrayStack<T>&);

private:
    Array<T> a;
    unsigned int n;
};

#endif //DATA_STRUCTURES_ARRAYSTACK_H
