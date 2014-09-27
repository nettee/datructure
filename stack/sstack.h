#include <iostream>
#include <string>
#include <cstdlib>
#include <cassert>

#ifndef _SSTACK_H_
#define _SSTACK_H_

template <typename T>
class sstack {
public:
    sstack(int size = 32);
    ~sstack();

    bool empty()const;
    bool full()const;
    int size()const;

    void push(T x);
    T pop();
    void clear();
    
    void output();

private:
    T *v;
    int top;
    int max_size;
        
};

template <typename T>
sstack<T>::sstack(int size)
{
    max_size = size;
    top = 0;
    v = new T[max_size];
}

template <typename T>
sstack<T>::~sstack()
{
    clear();
    delete []v;
}

template <typename T>
bool sstack<T>::empty()const
{
    return top == 0;
}

template <typename T>
bool sstack<T>::full()const
{
    return top == max_size;
}

template <typename T>
int sstack<T>::size()const
{
    return top;
}

template <typename T>
void sstack<T>::push(T x)
{
    assert(!full());
    v[top++] = x;
}

template <typename T>
T sstack<T>::pop()
{
    assert(!empty());
    return v[--top];
}

template <typename T>
void sstack<T>::clear()
{
    top = 0;
}

template <typename T>
void sstack<T>::output()
{
    for (int i = 0; i < top; i++) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

#endif
