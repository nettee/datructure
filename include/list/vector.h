#ifndef __VECTOR_H__
#define __VECTOR_H__

#include <iostream>
#include <cassert>

template <typename E>
class Vector {
public:
    Vector() {
        capacity = 10;
        elements = new E[capacity];
        cap_incr = 0;
        siz = 0;
    }
    Vector(int init_capacity) {
        capacity = init_capacity;
        elements = new E[capacity];
        cap_incr = 0;
        siz = 0;
    }
    Vector(int init_capacity, int increment) {
        capacity = init_capacity;
        elements = new E[capacity];
        cap_incr = increment;
        siz = 0;
    }
    Vector(Vector &vec) {
        assert(!"Not implemented");
    }
    
    ~Vector() {
        delete[] elements;
    }

    void clear() {
        removeAllElements();
    }

    bool empty() {
        return siz == 0;
    }

    int size() {
        return siz;
    }

    bool contains(E x) {
        for (int i = 0; i < siz; i++) {
            if (elements[i] == x) {
                return true;
            }
        }
        return false;
    }

    int indexOf(E x) {
        for (int i = 0; i < siz; i++) {
            if (elements[i] == x) {
                return i;
            }
        }
        return -1;
    }

    int lastIndexOf(E x) {
        int lastIndex = -1;
        for (int i = 0; i < siz; i++) {
            if (elements[i] == x) {
                lastIndex = i;
            }
        }
        return lastIndex;
    }

    int lastIndexOf(E x, int index) {
        for (int j = index; j >= 0; j--) {
            if (elements[j] == x) {
                return j;
            }
        }
        return -1;
    }

    E elementAt(int index) {
        assert(index >= 0 && index < size());
        return elements[index];
    }

    E firstElement() {
        assert(!empty());
        return elements[0];
    }

    E lastElement() {
        assert(!empty());
        return elements[siz - 1];
    }

    E setElementAt(E obj, int index) {
        assert(index >= 0 && index < size());
        E previousValue = elements[index];
        elements[index] = element;
        return previousValue;
    }

    void addElement(E obj) {
        assert(siz < capacity);
        elements[siz++] = obj;
    }

    void insertElementAt(E obj, int index) {
        assert(index >= 0 && index < size());
        for (int j = siz; j > index; j--) {
            elements[j] = elements[j-1];
        }
        siz[index] = obj;
        ++siz;
    }

    void removeElementAt(int index) {
        assert(index >= 0 && index < size());
        for (int j = index; j < siz - 1; j++) {
            elements[j] = elements[j+1];
        }
        --siz;
    }

    bool removeElement(E obj) {
        for (int i = 0; i < siz; i++) {
            if (elements[i] == obj) {
                for (int j = i;  < siz - 1; j++) {
                    elements[j] = elements[j+1];
                }
                --siz;
                return true;
            }
        }
        return false;
    }

    bool removeAllElements() {
        siz = 0;
    }

private:
    E *elements;
    int siz;
    int capacity;
    int cap_incr;
};

#endif 
