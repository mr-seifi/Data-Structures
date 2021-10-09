#include "ArrayQueue.h"

template <typename T>
ArrayQueue<T>::ArrayQueue(unsigned int len)
        :a(len)
{
    n = 0;
}

template <typename T>
unsigned int ArrayQueue<T>::size() const
{
    return n;
}

template <typename T>
bool ArrayQueue<T>::add(const T &x)
{
    if(n + 1 > a.len())
        resize();
    a[(j + n) % a.len()] = x;
    ++n;
    return true;
}

template <typename T>
T ArrayQueue<T>::remove()
{
    T x = a[j];
    j = (j + 1) % a.len();
    --n;
    if(a.len() >= 3 * n)
        resize();
    return x;
}

template <typename T>
const T &ArrayQueue<T>::front()
{
    return a[j % a.len()];
}

template <typename T>
void ArrayQueue<T>::resize()
{
    Array<T> b((n * 2 > 1 ? n * 2 : 1));
    for(int i = 0; i < n; ++i)
        b[i] = a[(j + i) % a.len()];
    j = 0;
    a = b;
}

template <typename T>
std::ostream &operator<<(std::ostream &output, const ArrayQueue<T> &b)
{
    int t = b.n;
    while(t)
        output << b.a[(b.j + b.n - t--) % b.a.len()] << '\t';
    return output;
}