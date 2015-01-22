#ifndef __DEQUE_H__
#define __DEQUE_H__

#include <cassert>

template <typename E>
class Deque {
public:
    Deque() {
        arr = new E[20];
        limit = arr + 20;
        data = arr + 7;
        top = arr + 7;
    }

    ~Deque() { 
        delete[] arr;
    }

    Deque(const Deque<E>& rhs) {
        assert(0);
    }

    Deque& operator=(const Deque<E>& rhs) {
        assert(0);
    }

    void clear() {
        data = arr + (limit - arr) / 2;
        top = data;
    }

    bool empty() const { return top == data; }
    int size() const { return top - data; }

    E& operator[](size_t) { return data[i]; }
    const E& operator[](size_t i) const { return data[i]; }

    typedef E *iterator;
    typedef const E *const_iterator;

    iterator begin() { return data; }
    const_iterator begin() const { return data; }
    iterator end() { return top; }
    const_iterator end() const { return top; }

    E first() const { return *data; }
    E last() const { return *(top - 1); }

    void push_back(const E& x) {
        if (top == limit) {
            grow_up();
        }
        *top++ = x;
    }

    void push_front(const E& x) {
        if (data == arr) {
            grow_down();
        }
        *--data = x;
    }

    E pop_front() { return *data++; }
    E pop_back() { return *--top; }

private:
    E *arr;
    E *limit;
    E *data;
    E *top;
};


#endif 
