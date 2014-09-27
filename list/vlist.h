#include <iostream>
#include <cstdlib>
#include <cassert>

#ifndef _VLIST_H_
#define _VLIST_H_

template <typename T>
class vlist {
public:
    vlist(int size = 40);
    vlist(vlist<T>& L);
    ~vlist();

    bool empty()const;
    int max_size()const;
    int size()const;
    int search(T x)const;

    T getitem(int i)const;
    void setitem(int i, T x);

    void push_back(T x);
    T pop_back();

    void input();
    void output();

    vlist<T> operator=(vlist<T>& L);

private:
    T *v;
    int max_size;
    int size;
};

template <typename T>
vlist<T>::vlist(int size)
{
    assert(size > 0);
    max_size = size;
    size = 0;
    v = new T[max_size];
}

template <typename T>
vlist<T>::vlist(vlist<T>& L)
{
    max_size = L.max_size();
    size = L.size();
    v = new T[max_size];
    for (int i = 0; i < size; i++) {
        v[i] = L.getitem(i);
    }
}

template <typename T>
bool vlist<T>::empty()const
{
    return size == 0;
}

template <typename T>
int vlist<T>::max_size()const
{
    return max_size;
}

template <typename T>
int vlist<T>::size()const
{
    return size;
}

template <typename T>
int vlist<T>::search(T x)
{
    for (int i = 0; i < size; i++) {
        if (v[i] == x) {
            return i;
        }
    }
    return -1;
}

template <typename T>
T vlist<T>::getitem(int i)
{
    assert(i >= 0 && i < size);
    return v[i];
}

template <typename T>
void vlist<T>::setitem(int i, T x) 
{
    assert(i >= 0 && i < size);
    v[i] = x;
}

template <typename T>
void vlist<T>::push_back(T x)
{
    assert(size < max_size);
    v[size++] = x;
}

template <typename T>
T vlist<T>::pop_back()
{
    assert(size != 0);
    return v[--size];
}

template <typename T>
void vlist<T>::input()
{
    int len;
    std::cin >> len;
    T val;
    for (int i = 0; i < len; i++) {
        std::cin >> val;
        push_back(val);
    }
}

template <typename T>
void vlist<T>::output()
{
    for (int i = 0; i < size; i++) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
vlist<T> vlist<T>::operator=(vlist<T>& L)
{
    max_size = L.max_size();
    size = L.size();
    v = new T[max_size];
    for (int i = 0; i < size; i++) {
        v[i] = L.getitem(i);
    }
}

#endif 
