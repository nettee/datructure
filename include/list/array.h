#ifndef __ARRAY_H__
#define __ARRAY_H__
/*
 * immutable array
 */

template <typename E>
class Array {
public:
    Array() {
        data = NULL;
        siz = 0;
    }

    Array(E *arr, int len) {
        data = new E[len];
        for (int i = 0; i < len; i++) {
            data[i] = arr[i];
        }
        siz = len;
    }

    ~Array() {
        delete[] data;
    }

    int size() {
        return siz;
    }

    E& operator[](int i) { return data[i]; }
    const E& operator[](int i) const { return data[i]; }

private:
    int siz;
    E *data;
};

#endif
