#include <iostream>
#include <string>
#include <cstdlib>
#include <cassert>

#ifndef _STACK_H_
#define _STACK_H_

template <typename T>
struct StackNode{
    T val;
    StackNode *next;
    StackNode(T data) {
        val = data;
        next = NULL;
    }
};

template <typename T>
class Stack {
public:
    Stack() { head = NULL; }
    ~Stack() { clear(); }

    bool empty() const { return head == NULL; }
    
    void push(const T& x) {
        StackNode<T> *q = new StackNode<T>(x);
        q->next = head;
        head = q;
    }

    void pop(T& x) {
        assert(!empty());
        StackNode<T> *q = head;
        head = head->next;
        x = q->val;
        delete q;
    }

    void clear() {
        T x;
        while (!empty()) {
            pop(x);
        }
    }

    void output() {
        for (StackNode<T> *q = head; q != NULL; q = q->next) {
            std::cout << q->val << " ";
        }
        std::cout << std::endl;
    }
private:
    T *head;
};

#endif
