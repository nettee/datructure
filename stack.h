#include <iostream>
#include <string>
#include <cstdlib>
#include <cassert>

#ifndef _STACK_H_
#define _STACK_H_

template <typename T>
class Stack {
public:
    Stack(int size = 32);
    ~Stack();

    bool empty()const;
    int size()const;

    void push(T x);
    T pop();
    T top();
    void clear();
    
    void output();

private:
    T *v;
    int top_;
    int max_size;
        
    bool full()const;
};

template <typename T>
Stack<T>::Stack(int size)
{
    max_size = size;
    top_ = 0;
    v = new T[max_size];
}

template <typename T>
Stack<T>::~Stack()
{
    clear();
    delete []v;
}

template <typename T>
bool Stack<T>::empty()const
{
    return top_ == 0;
}

template <typename T>
bool Stack<T>::full()const
{
    return top_ == max_size;
}

template <typename T>
int Stack<T>::size()const
{
    return top_;
}

template <typename T>
void Stack<T>::push(T x)
{
    assert(!full());
    v[top_++] = x;
}

template <typename T>
T Stack<T>::pop()
{
    assert(!empty());
    return v[--top_];
}

template <typename T>
T Stack<T>::top()
{
    assert(!empty());
    return v[top_ - 1];
}

template <typename T>
void Stack<T>::clear()
{
    top_ = 0;
}

template <typename T>
void Stack<T>::output()
{
    for (int i = 0; i < top_; i++) {
        std::cout << v[i] << " ";
    }
    std::cout << std::endl;
}

#endif
