/*
 * immutable array
 */

#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <iostream>
#include <cassert>

template <typename E>
class Array {
public:
    Array(E *arr, int len) {
        elements = new E[len];
        for (int i = 0; i < len; i++) {
            elements[i] = arr[i];
        }
        siz = len;
    }

    ~Array() {
        delete[] elements;
    }

    int size() {
        return siz;
    }

    E get(int index) {
        assert(index >= 0 && index < siz);
        return elements[index];
    }

    void print() {
        for (int i = 0; i < siz; i++) {
            std::cout << elements[i];
            std::cout << ((i < siz - 1) ? " " : "\n");
        }
    }

private:
    int siz;
    E *elements;
};

#endif
