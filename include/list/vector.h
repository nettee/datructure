#ifndef __VECTOR_H__
#define __VECTOR_H__

template <typename E>
class Vector {
public:
    Vector() {
        data = new E[16];
        limit = data + 16;
        top = data;
    }
    
    ~Vector() {
        delete[] data;
    }

    Vector(const Vector<E>& rhs) {
        assert(0);
    }

    Vector<E>& operator=(const Vector<E>& rhs) {
        assert(0);
    }

    void clear() { top = data; }

    bool empty() { return top == data; }
    size_t size() const { return top - data; }

    E& operator[](size_t i) { return data[i]; }
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
        if (top == capacity) {
            grow_up();
        }
        *top++ = x;
    }

    E pop_back() { return *--top; }

private:
    E *data;
    E *top;
    E *limit;

    void grow_up() {
        int old_cap = limit - data;
        int new_cap = old_cap * 2;
        E *new_data = new E[new_cap];
        for (int i = 0; i < old_cap; i++) {
            new_data[i] = data[i];
        }
        delete[] data;
        data = new_data;
        top = data + old_cap;
        limit = data + new_cap;
    }
};

#endif
