#include <cassert>

template <typename T>
class MinHeap {
public:
    MinHeap(int msz = 100);
    ~MinHeap();
    void clear();

    bool empty();
    bool full();

    void insert(T x);

private:
    T *v;
    int siz;
    int msiz;
};

template <typename T>
MinHeap<T>::MinHeap(int msz)
{
    v = new T[msz];
    msiz = msz;
    siz = 0;
}

template <typename T>
MinHeap<T>::~MinHeap()
{
    clear();
    delete[] v;
}

template <typename T>
void MinHeap<T>::clear()
{
    siz = 0;
}

template <typename T>
bool MinHeap<T>::empty()
{
    return siz == 0;
}

template <typename T>
bool MinHeap<T>::full()
{
    return siz == msiz;
}

template <typename T>
void MinHeap<T>::insert(T x)
{
    assert(!full());
    v[siz] = x;
    ++siz;
}
