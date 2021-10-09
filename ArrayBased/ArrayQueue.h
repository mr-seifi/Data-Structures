#ifndef DATA_STRUCTURES_ARRAYQUEUE_H
#define DATA_STRUCTURES_ARRAYQUEUE_H

#include <iostream>
#include "Array.h"

template <typename T>
class ArrayQueue
{
    template <typename U>
    friend std::ostream &operator<<(std::ostream&, const ArrayQueue<U>&);
public:
    explicit ArrayQueue(unsigned int = 1);
    unsigned int size() const;
    bool add(const T&);
    T remove();
    const T &front();
    void resize();

private:
    Array<T> a;
    unsigned int n;
    int j;
};

#endif //DATA_STRUCTURES_ARRAYQUEUE_H
