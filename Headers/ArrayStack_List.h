#ifndef DATA_STRUCTURES_ARRAYSTACK_LIST_H
#define DATA_STRUCTURES_ARRAYSTACK_LIST_H

#include "Array.h"

template <typename T>
class ArrayStack_List
{
    template <typename U>
    friend std::ostream &operator<<(std::ostream&, const ArrayStack_List<U>&);
public:
    explicit ArrayStack_List(unsigned int = 1);
    unsigned int size() const;
    const T& get(unsigned int);
    T set(unsigned int, const T&);
    void add(unsigned int, const T&);
    T remove(unsigned int);
    void resize();

private:
    Array<T> a;
    unsigned int n;
};

template <typename T>
ArrayStack_List<T>::ArrayStack_List(unsigned int len)
              :a(len)
{
    n = len;
}

template <typename T>
unsigned int ArrayStack_List<T>::size() const
{
    return n;
}

template <typename T>
const T &ArrayStack_List<T>::get(unsigned int i)
{
    return a[i];
}

template <typename T>
T ArrayStack_List<T>::set(unsigned int i, const T &x)
{
    T y = a[i];
    a[i] = x;
    return y;
}

template <typename T>
void ArrayStack_List<T>::add(unsigned int i, const T &x)
{
    if(n + 1 > a.len())
        resize();
    for(int j = n; j > i; --j)
        a[j] = a[j - 1];
    a[i] = x;
    ++n;
}

template <typename T>
T ArrayStack_List<T>::remove(unsigned int i)
{
    T x = a[i];
    for(unsigned int j = i; j < n; ++j)
        a[j] = a[j + 1];
    --n;
    if(a.len() >= 3 * n)
        resize();
    return x;
}

template <typename T>
void ArrayStack_List<T>::resize()
{
    Array<T> b((n * 2 > 1 ? n * 2 : 1));
    for(int i = 0; i < n; ++i)
        b[i] = a[i];
    a = b;
}

template <typename T>
std::ostream &operator<<(std::ostream &output, const ArrayStack_List<T> &b)
{
    output << b.a;
    return output;
}
#endif //DATA_STRUCTURES_ARRAYSTACK_LIST_H
