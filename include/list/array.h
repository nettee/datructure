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
        N = 0;
    }

    Array(E *arr, int len) {
        data = new E[len];
        for (int i = 0; i < len; i++) {
            data[i] = arr[i];
        }
        N = len;
    }

    Array(const Array<E>& rhs) {
        if (this != &rhs) {
            N = rhs.N;
            data = new E[N];
            for (int i = 0; i < N; i++) {
                data[i] = rhs.data[i];
            }
        }
    }

    Array<E>& operator=(const Array<E>& rhs) {
        if (this != &rhs) {
            N = rhs.N;
            data = new E[N];
            for (int i = 0; i < N; i++) {
                data[i] = rhs.data[i];
            }
        }
    }

    ~Array() {
        delete[] data;
    }

    bool empty() const {
        return size() == 0;
    }

    int size() const {
        return N;
    }

    E& operator[](int i) { return data[i]; }
    const E& operator[](int i) const { return data[i]; }

private:
    int N;
    E *data;
};

#endif
