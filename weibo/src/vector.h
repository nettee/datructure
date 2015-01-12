#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <cassert>

template <typename E>
class Vector {
public:
    typedef E *iterator;
    typedef const E *const_iterator;

    Vector(): the_size(0) {
        data = new E[16];
        capacity = 16;
    }
    
    ~Vector() {
        delete[] data;
    }

    E& operator[](size_t i) { return data[i]; }
    const E& operator[](size_t i) const { return data[i]; }

    iterator begin() { return data; }
    const_iterator begin() const { return data; }
    iterator end() { return data + the_size; }
    const_iterator end() const { return data + the_size; }

    void clear() { the_size = 0; }
    size_t size() const { return the_size; }

    void push_back(const E& x) {
        if (the_size == capacity) {
            grow();
        }
        data[the_size++] = x;
    }

private:
    E *data;
    size_t the_size;
    size_t capacity;

    void grow() {
        int new_cap = capacity * 2;
        E *new_data = new E[new_cap];
        for (int i = 0; i < the_size; i++) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        capacity = new_cap;
    }
};

#endif
