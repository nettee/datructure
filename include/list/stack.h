#ifndef __STACK_H__
#define __STACK_H__

#include <iostream>
#include <cassert>

template <typename E>
class Stack {
public:
    Stack() {
        capacity = 10;
        elements = new E[capacity];
        top = 0;
    }
    
    ~Stack() {
        clear();
        delete[] elements;
    }

    bool empty() {
        return top == 0;
    }
    
    E push(E item) {
        assert(top < capacity);
        elements[top++] = item;
        return item;
    }

    E pop() {
        assert(top > 0);
        return elements[--top];
    }

    E peek() {
        assert(top > 0);
        return elements[top - 1];
    }

protected:
    clear() {
        top = 0;
    }

private:
    E *elements;
    int top;
    int capacity;
};

#endif 
