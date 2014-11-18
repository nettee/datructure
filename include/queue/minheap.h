#include <iostream>
#include <cassert>

template <typename T>
class MinHeap {
public:
    MinHeap(T sentinel, int msz = 100);
    ~MinHeap();
    void clear();

    bool isEmpty();
    bool isFull();
    int size();

    void insert(T x);
    T deleteMininal();

    void input(T *elements, int len);
    void output();

private:
    T *elements;
    T sentinel;
    int curSize;
    int maxSize;
};

template <typename T>
MinHeap<T>::MinHeap(T sentinel, int msz)
{
    elements = new T[msz+1];
    maxSize = msz;
    curSize = 0;
    elements[0] = sentinel;
}

template <typename T>
MinHeap<T>::~MinHeap()
{
    clear();
    delete[] elements;
}

template <typename T>
void MinHeap<T>::clear()
{
    curSize = 0;
}

template <typename T>
bool MinHeap<T>::isEmpty()
{
    return curSize == 0;
}

template <typename T>
bool MinHeap<T>::isFull()
{
    return curSize == maxSize;
}

template <typename T>
int MinHeap<T>::size()
{
    return curSize;
}

template <typename T>
void MinHeap<T>::insert(T x)
{
    assert(!isFull());
    elements[++curSize] = x;
    int i = curSize;
    while (elements[i/2] > x) {
        elements[i] = elements[i/2];
        i /= 2;
    }
    elements[i] = x;
}

template <typename T>
T MinHeap<T>::deleteMininal()
{
    assert(!isEmpty());
    T minValue = elements[1];
    T lastElement = elements[curSize--];
    int i = 1;
    while (i * 2 <= curSize) {
        int child = i * 2;
        if (child != curSize && elements[child+1] < elements[child]) {
            ++child;
        }
        if (lastElement > elements[child]) {
            elements[i] = elements[child];
        } else {
            break;
        }
        i = child;
    }
    elements[i] = lastElement;
    return minValue;
}

template <typename T>
void MinHeap<T>::input(T *xs, int len)
{
    assert(len <= maxSize);
    for (int i = 0; i < len; i++) {
        elements[i+1] = xs[i];
    }
    curSize = len;
}

template <typename T>
void MinHeap<T>::output()
{
    for (int i = 1; i <= curSize; i++) {
       std::cout << elements[i] << " ";
    }
    std::cout << std::endl;
}
