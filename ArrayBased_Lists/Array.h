#ifndef DATA_STRUCTURES_ARRAY_H
#define DATA_STRUCTURES_ARRAY_H


#include <iostream>
#include <cassert>

template <typename T>
class Array
{
    template <typename U>
    friend std::ostream &operator<<(std::ostream&, const Array<U>&);
public:
    T *a;
    unsigned int length;
    explicit Array(unsigned int);
    ~Array();
    T &operator[](int);
    const T &operator[](int) const;
    Array<T> &operator=(Array<T>&);
    unsigned int len() const { return length; };

};


template <typename T>
Array<T>::Array(unsigned int l)
{
    length = l;
    a = new T[length];
}

template <typename T>
Array<T>::~Array()
{
    delete[] a;
}

template <typename T>
T &Array<T>::operator[](int subscript)
{
    assert(subscript >= 0 && subscript < length);
    return a[subscript];
}

template <typename T>
const T &Array<T>::operator[](int subscript) const
{
    assert(subscript >= 0 && subscript < length);
    return a[subscript];
}

template <typename T>
Array<T> &Array<T>::operator=(Array<T> &b)
{
    if(a != NULL)
        delete[] a;
    a = b.a;
    b.a = NULL; // This statement don't delete allocated memory, so its assign NULL value to local b.a variable
    length = b.length;
    return *this;
}

template <typename T>
std::ostream &operator<<(std::ostream &output, const Array<T> &b)
{
    for(int i = 0; i < b.length; ++i)
        output << b.a[i] << '\t';
    return output;
}

#endif //DATA_STRUCTURES_ARRAY_H
