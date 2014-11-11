// =======================================================
// dlist.h -- Double Cycled Linked List
//
// dlist uses C++ template, supporting all possible types
// which implement =, ==, < operator
// =======================================================

#ifndef __DLIST_H__
#define __DLIST_H__

#include <iostream>
#include <cassert>

template <typename T>
struct DListNode {
    T val;
    DListNode<T> *prev;
    DListNode<T> *next;
    DListNode() {
        val = T();
        prev = NULL;
        next = NULL;
    }
    DListNode(T x) {
        val = x;
        prev = NULL;
        next = NULL;
    }
};

template <typename T>
class DList {
public:
    DList();
    ~DList();

    bool empty()const;
    int size()const;
    int search(T x)const;

    T getitem(int i)const;
    void setitem(int i, T x);

    // core list operator
    // Note that the program aborts if pop from empty list
    void push_front(T x);
    T pop_front();
    void push_back(T x);
    T pop_back();
    
    // for iterator use
    DListNode<T> *gethead() { return head; }
    DListNode<T> *getrear() { return rear; }
    DListNode<T> *begin();
    DListNode<T> *end();
    DListNode<T> *next(DListNode<T> *it);
    DListNode<T> *circle(DListNode<T> *it);
    
    void input();
    void output();

private:
    DListNode<T> *head;
    DListNode<T> *rear;
    int sz;
};

template <typename T>
DList<T>::DList()
{
    head = new DListNode<T>();
    rear = new DListNode<T>();
    head->next = rear;
    rear->prev = head;
    sz = 0;
}

template <typename T>
DList<T>::~DList()
{
    while (!empty()) {
        pop_back();
    }
}

template <typename T>
bool DList<T>::empty()const
{
    return sz == 0;
}

template <typename T>
int DList<T>::size()const
{
    return sz;
}

template <typename T>
int DList<T>::search(T x)const
{
    DListNode<T> *q = head->next;
    for (int i = 0; i < sz; i++) {
        if (q->val == x) {
            return i;
        }
        q = q->next;
    }
    return -1;
}

template <typename T>
T DList<T>::getitem(int i)const
{
    assert(i >= 0 && i < sz);
    DListNode<T> *q = head->next;
    for (int j = 0; j < i; j++) {
        q = q->next;
    }
    return q->val;
}

template <typename T>
void DList<T>::setitem(int i, T x)
{
    assert(i >= 0 && i < sz);
    DListNode<T> *q = head->next;
    for (int j = 0; j < i; j++) {
        q = q->next;
    }
    q->val = x;
}

template <typename T>
void DList<T>::push_front(T x)
{
    DListNode<T> *q = new DListNode<T>(x);
    q->next = head->next;
    head->next->prev = q;
    q->prev = head;
    head->next = q;
    ++sz;
}

template <typename T>
T DList<T>::pop_front()
{
    assert(sz != 0);
    DListNode<T> *q = head->next;
    q->next->prev = head;
    head->next = q->next;
    T val = q->val;
    delete q;
    --sz;
    return val;
}

template <typename T>
void DList<T>::push_back(T x)
{
    DListNode<T> *q = new DListNode<T>(x);
    q->prev = rear->prev;
    rear->prev->next = q;
    q->next = rear;
    rear->prev = q;
    ++sz;
}

template <typename T>
T DList<T>::pop_back()
{
    assert(sz != 0);
    DListNode<T> *q = rear->prev;
    q->prev->next = rear;
    rear->prev = q->prev;
    T val = q->val;
    delete q;
    --sz;
    return val;
}

template <typename T>
DListNode<T> *DList<T>::begin()
{
    return gethead()->next;
}

template <typename T>
DListNode<T> *DList<T>::end()
{
    return getrear();
}

template <typename T>
DListNode<T> *DList<T>::next(DListNode<T> *it)
{
    assert(it != getrear());
    return it->next;
}

template <typename T>
DListNode<T> *DList<T>::circle(DListNode<T> *it)
{
    if (it->next == getrear()) {
        return gethead()->next;
    } else {
        return it->next;
    }
}

template <typename T>
void DList<T>::input()
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
void DList<T>::output()
{
    DListNode<T> *q = head->next;
    for (int i = 0; i < sz; i++) {
        std::cout << q->val << " ";
        q = q->next;
    }
    std::cout << std::endl;
}

#endif
