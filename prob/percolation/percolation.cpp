#include <iostream>
#include <cassert>

#include "set/union-find.h"

using namespace std;

class Percolation {
private:
    int n;
    UnionFind *uf;
    int top, bottom;
    bool *opened;

public:
    Percolation(int N) {
        assert(N > 0);
        n = N;
        top = n * n;
        bottom = n * n + 1;
        uf = new UnionFind(n*n+2);
        opened = new bool[n*n];
        for (int i = 0; i < n * n; i++) {
            opened[i] = false;
        }
        for (int i = 0; i < n; i++) {
            uf->set_union(top, i);
            uf->set_union(bottom, n*(n-1)+i);
        }
    }

    ~Percolation() {
        delete[] opened;
        delete uf;
    }

    void open(int i, int j) {
        assert(i >= 0 && i < n);
        assert(j >= 0 && j < n);
        int index = i*n + j;
        if (opened[index]) {
            return;
        }
        opened[index] = true;
        if (i != 0 && isOpen(i-1, j))
            uf->set_union(index, index-n);
        if (i != n-1 && isOpen(i+1, j)) 
            uf->set_union(index, index+n);
        if (j != 0 && isOpen(i, j-1)) 
            uf->set_union(index, index-1);
        if (j != n-1 && isOpen(i, j+1))
            uf->set_union(index, index+1);
    }

    bool isOpen(int i, int j) {
        assert(i >= 0 && i < n);
        assert(j >= 0 && j < n);
        return opened[i*n+j];
    }

    bool isFull(int i, int j) {
        assert(i >= 0 && i < n);
        assert(j >= 0 && j < n);
        return isOpen(i, j) && uf->connected(top, i*n+j);
    }

    bool percolates() {
        return uf->connected(top, bottom);
    }
};        
