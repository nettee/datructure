#include <iostream>
#include <cstdlib>
#include <cassert>

#ifndef _DLIST_H_
#define _DLIST_H_

template <typename T>
struct node {
    T val;
    node<T> *prev;
    node<T> *next;
    node() {
        val = T();
        prev = NULL;
        next = NULL;
    }
    node(T data) {
        val = data;
        prev = NULL;
        next = NULL;
    }
};

template <typename T>
class dlist {
public:
    dlist();
    dlist(dlist<T>& L);
    ~dlist();

    bool empty()const;
    int size()const;
    int search(T x)const;

    T getitem(int i)const;
    void setitem(int i, T x);

    void push_front(T x);
    T pop_front();
    void push_back(T x);
    T pop_back();
    
    void input();
    void output();

private:
    node<T> *head;
    node<T> *rear;
    int sz;
};

template <typename T>
dlist<T>::dlist()
{
    head = new node<T>();
    rear = new node<T>();
    head->next = rear;
    rear->prev = head;
    sz = 0;
}

template <typename T>
dlist<T>::dlist(dlist<T>& L)
{
    // not implemented
}

template <typename T>
dlist<T>::~dlist()
{
    for (int i = 0; i < sz; i++) {
        pop_back();
    }
}

template <typename T>
bool dlist<T>::empty()const
{
    return sz == 0;
}

template <typename T>
int dlist<T>::size()const
{
    return sz;
}

template <typename T>
int dlist<T>::search(T x)const
{
    node<T> *q = head->next;
    for (int i = 0; i < sz; i++) {
        if (q->val == x) {
            return i;
        }
        q = q->next;
    }
    return -1;
}

template <typename T>
T dlist<T>::getitem(int i)const
{
    assert(i >= 0 && i < sz);
    node<T> *q = head->next;
    for (int j = 0; j < i; j++) {
        q = q->next;
    }
    return q->val;
}

template <typename T>
void dlist<T>::setitem(int i, T x)
{
    assert(i >= 0 && i < sz);
    node<T> *q = head->next;
    for (int j = 0; j < i; j++) {
        q = q->next;
    }
    q->val = x;
}

template <typename T>
void dlist<T>::push_front(T x)
{
    node<T> *q = new node<T>(x);
    q->next = head->next;
    head->next->prev = q;
    q->prev = head;
    head->next = q;
    ++sz;
}

template <typename T>
T dlist<T>::pop_front()
{
    assert(sz != 0);
    node<T> *q = head->next;
    q->next->prev = head;
    head->next = q->next;
    T val = q->val;
    delete q;
    --sz;
    return val;
}

template <typename T>
void dlist<T>::push_back(T x)
{
    node<T> *q = new node<T>(x);
    q->prev = rear->prev;
    rear->prev->next = q;
    q->next = rear;
    rear->prev = q;
    ++sz;
}

template <typename T>
T dlist<T>::pop_back()
{
    assert(sz != 0);
    node<T> *q = rear->prev;
    q->prev->next = rear;
    rear->prev = q->prev;
    T val = q->val;
    delete q;
    --sz;
    return val;
}

template <typename T>
void dlist<T>::input()
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
void dlist<T>::output()
{
    node<T> *q = head->next;
    for (int i = 0; i < sz; i++) {
        std::cout << q->val << " ";
        q = q->next;
    }
    std::cout << std::endl;
}

#endif
