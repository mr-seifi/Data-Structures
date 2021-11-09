#include "ArrayStack.h"

template <typename T>
ArrayStack<T>::ArrayStack(unsigned int len)
        :a(len)
{
    n = len;
}

template <typename T>
ArrayStack<T>::ArrayStack(const ArrayStack<T> &a)
{
    *this = a;
}

template <typename T>
unsigned int ArrayStack<T>::size() const
{
    return n;
}

template <typename T>
const T &ArrayStack<T>::get(unsigned int i)
{
    return a[i];
}

template <typename T>
T ArrayStack<T>::set(unsigned int i, const T &x)
{
    T y = a[i];
    a[i] = x;
    return y;
}

template <typename T>
void ArrayStack<T>::add(unsigned int i, const T &x)
{
    if(n + 1 > a.len())
        resize();
    std::copy_backward(a.a + i, a.a + n, a.a + n + 1);
    a[i] = x;
    ++n;
}

template <typename T>
T ArrayStack<T>::remove(unsigned int i)
{
    T x = a[i];
    std::copy_backward(a.a + i + 1, a.a + n, a.a + n - 1);
    --n;
    if(a.len() >= 3 * n)
        resize();
    return x;
}

template <typename T>
void ArrayStack<T>::resize()
{
    Array<T> b((n * 2 > 1 ? n * 2 : 1));
    std::copy(a.a + 0, a.a + n, b.a + 0);
    a = b;
}

template <typename T>
std::ostream &operator<<(std::ostream &output, const ArrayStack<T> &b)
{
    int t = b.n;
    while(t - 1)
        output << b.a[b.n - t--] << '\t';
    return output;
}

template <typename T>
const T &ArrayStack<T>::operator[](int subscript)
{
    return get(subscript);
}

template <typename T>
ArrayStack<T> &ArrayStack<T>::operator=(const ArrayStack<T> &a)
{
    n = a.len;
    for(int i = 0; i < a.size(); ++i)
        add(i, a[i]);
    return *this;
}