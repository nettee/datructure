#ifndef __DISJOINT_SET_H__
#define __DISJOINT_SET_H__

#include <iostream>
#include <cassert>

typedef int Set_t;

class DisjointSet {
public:
    DisjointSet(int size) {
        num_sets = size;
        sets = new Set_t[num_sets];
        for (int i = 0; i < num_sets; i++) {
            sets[i] = -1;
        }
    }

    ~DisjointSet() {
        delete[] sets;
    }

    void setUnion(int root1, int root2) {
        assert(root1 != root2);
        sets[root2] = root1;
    }

    Set_t find(int x) {
        if (sets[x] == -1) {   // root
            return x;
        } else {
            return find(sets[x]);
        }
    }

    void output();

private:
    Set_t *sets;
    int num_sets;
};

void DisjointSet::output()
{
    for (int i = 0; i < num_sets; i++) {
        std::cout << ((i == 0) ? "{" : ", ");
        std::cout << sets[i];
    }
    std::cout << "}" << std::endl;
}

#endif
