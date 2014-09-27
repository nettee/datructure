#include <iostream>
#include <string>
#include <cstdlib>
#include <cassert>

#ifndef _VSTACK_H_
#define _VSTACK_H_

template <typename T>
class vstack {
public:
    vstack(int size = 32);
    ~vstack();

    bool empty()const;
    int size()const;

    void push(T x);
    T pop();
    void clear();
    
    void output();

private:
    T *v;
    int top;
    int max_size;
        
    bool full()const;
};

template <typename T>
vstack<T>::vstack(int size)
{
    max_size = size;
    top = 0;
    v = new T[max_size];
}

template <typename T>
vstack<T>::~vstack()
{
    clear();
    delete []v;
}

template <typename T>
bool vstack<T>::empty()const
{
    return top == 0;
}

template <typename T>
bool vstack<T>::full()const
{
    return top == max_size;
}

template <typename T>
int vstack<T>::size()const
{
    return top;
}

template <typename T>
void vstack<T>::push(T x)
{
    assert(!full());
    v[top++] = x;
}

template <typename T>
T vstack<T>::pop()
{
    assert(!empty());
    return v[--top];
}

template <typename T>
void vstack<T>::clear()
{
    top = 0;
}

template <typename T>
void vstack<T>::output()
{
    for (int i = 0; i < top; i++) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

#endif
