#ifndef _STACK_H_
#define _STACK_H_

#include <cassert>

template <typename E>
struct StackNode {
    E val;
    StackNode *next;
    StackNode(E data): next(NULL) { val = data; }
};

template <typename E>
class Stack {
public:
    Stack() { head = NULL; }
    ~Stack() { clear(); }

    void clear() {
        StackNode<E> *p = head;
        while (p != NULL) {
            StackNode<E> *q = p;
            p = p->next;
            delete q;
        }
    }

    bool empty() const { return head == NULL; }

    const E& top() const {
        assert(!empty());
        return head->val; 
    }
    
    void push(const E& x) {
        StackNode<E> *q = new StackNode<E>(x);
        q->next = head;
        head = q;
    }

    void pop(E& x) {
        assert(!empty());
        StackNode<E> *q = head;
        head = head->next;
        x = q->val;
        delete q;
    }

private:
    StackNode<E> *head;
};

#endif
