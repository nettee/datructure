#include <iostream>
#include <cassert>

template <typename T>
class MinHeap {
public:
    MinHeap(T sentinel, int msz = 100);
    ~MinHeap();
    void clear();

    bool empty();
    bool full();
    int size();

    void insert(T x);
    T pop_min();

    void input(T *v, int len);
    void output();

private:
    T *v;
    T sentinel;
    int siz;
    int msiz;
};

template <typename T>
MinHeap<T>::MinHeap(T sentinel, int msz)
{
    v = new T[msz+1];
    msiz = msz;
    siz = 0;
    v[0] = sentinel;
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
int MinHeap<T>::size()
{
    return siz;
}

template <typename T>
void MinHeap<T>::insert(T x)
{
    assert(!full());
    v[++siz] = x;
    int i = siz;
    while (v[i/2] > x) {
        v[i] = v[i/2];
        i /= 2;
    }
    v[i] = x;
}

template <typename T>
T MinHeap<T>::pop_min()
{
    assert(!empty());
    T min_val = v[1];
    T last_element = v[siz--];
    int i = 1;
    while (i * 2 <= siz) {
        int child = i * 2;
        if (child != siz && v[child+1] < v[child]) {
            ++child;
        }
        if (last_element > v[child]) {
            v[i] = v[child];
        } else {
            break;
        }
        i = child;
    }
    v[i] = last_element;
    return min_val;
}

template <typename T>
void MinHeap<T>::input(T *xs, int len)
{
    assert(len <= msiz);
    for (int i = 0; i < len; i++) {
        v[i+1] = xs[i];
    }
    siz = len;
}

template <typename T>
void MinHeap<T>::output()
{
    for (int i = 1; i <= siz; i++) {
       std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}
