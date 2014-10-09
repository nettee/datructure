#include <iostream>
#include <cassert>

#include "list/dlist.h"

#ifndef _LQUEUE_H_
#define _LQUEUE_H_

template <typename T>
class lqueue {
public:
    lqueue();
    ~lqueue();

    bool empty()const;
    int size()const;

    void enqueue(T x);
    T dequeue();

private:
    dlist<T> queue;
};

template <typename T>
lqueue<T>::lqueue()
{
    queue = dlist<T>();
}

template <typename T>
lqueue<T>::~lqueue()
{
    queue.~dlist();
}

template <typename T>
bool lqueue<T>::empty()const
{
    return queue.empty();
}
 
template <typename T>
int lqueue<T>::size()const
{
    return queue.size();
}

template <typename T>
void lqueue<T>::enqueue(T x)
{
    queue.push_back(x);
}

template <typename T>
T lqueue<T>::dequeue()
{
    return queue.pop_front();
}






#endif 
