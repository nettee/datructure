#include <iostream>
#include <cstdlib>
#include <cassert>

#ifndef _VLIST_H_
#define _VLIST_H_

template <typename T>
class vlist {
public:
    vlist(int n = 40);
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
    int msize;
    int sz;
};

template <typename T>
vlist<T>::vlist(int n)
{
    assert(n > 0);
    msize = n;
    sz = 0;
    v = new T[msize];
}

template <typename T>
vlist<T>::vlist(vlist<T>& L)
{
    msize = L.max_size();
    sz = L.size();
    v = new T[msize];
    for (int i = 0; i < sz; i++) {
        v[i] = L.getitem(i);
    }
}

template <typename T>
vlist<T>::~vlist()
{
    delete []v;
}

template <typename T>
bool vlist<T>::empty()const
{
    return sz == 0;
}

template <typename T>
int vlist<T>::max_size()const
{
    return msize;
}

template <typename T>
int vlist<T>::size()const
{
    return sz;
}

template <typename T>
int vlist<T>::search(T x)const
{
    for (int i = 0; i < sz; i++) {
        if (v[i] == x) {
            return i;
        }
    }
    return -1;
}

template <typename T>
T vlist<T>::getitem(int i)const
{
    assert(i >= 0 && i < sz);
    return v[i];
}

template <typename T>
void vlist<T>::setitem(int i, T x) 
{
    assert(i >= 0 && i < sz);
    v[i] = x;
}

template <typename T>
void vlist<T>::push_back(T x)
{
    assert(sz < msize);
    v[sz++] = x;
}

template <typename T>
T vlist<T>::pop_back()
{
    assert(sz != 0);
    return v[--sz];
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
    for (int i = 0; i < sz; i++) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

template <typename T>
vlist<T> vlist<T>::operator=(vlist<T>& L)
{
    msize = L.max_size();
    sz = L.size();
    v = new T[msize];
    for (int i = 0; i < sz; i++) {
        v[i] = L.getitem(i);
    }
}

#endif 
