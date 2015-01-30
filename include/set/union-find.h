#ifndef __UNION_FIND_H__
#define __UNION_FIND_H__

/* union-find ADT 
 * supports union and find methods, along with methods for 
 * determining whether two objects are in the same component
 *
 * This implementation uses weighted quick union by size.
 *
 * This should be the final version of union-find.
 */

#include <iostream>
#include <cassert>

class UnionFind {
private:

    int *id;  // id[i] = parent of i
    int *treesize;  // subtree size
    int size;  // number of components

public:
    UnionFind(int N) {
        size = N;
        id = new int[size];
        treesize = new int[size];
        // initialize with N isolated components of treesize 1
        for (int i = 0; i < size; i++) {
            id[i] = i;
            treesize[i] = 1;
        }
    }

    ~UnionFind() {
        delete[] id;
    }

    /* returns the components identifier for the component
     * param i should be guaranteed in [0..N) by user
     */
    int find(int i) {
        while (i != id[i]) {
            i = id[i];
        }
        return i;
    }

    /* merges two components containing site p and q,
     * if p and q are in the same component, do nothing.
     * param p, q should be guaranteed in [0..N) by user
     */
    void union_(int p, int q) {
        int i = find(p);
        int j = find(q);
        if (i == j) {
            return;
        }
        if (treesize[i] < treesize[j]) {
            id[i] = j;
            treesize[j] += treesize[i];
        } else {
            id[j] = i;
            treesize[i] += treesize[j];
        }
    }

    /* Are the two sites p and q in the same component?
     * param p, q should be guaranteed in [0..N) by user
     */
    bool connected(int p, int q) {
        return find(p) == find(q);
    }

    void print();
};

void UnionFind::print()
{
    for (int i = 0; i < num_set; i++) {
        std::cout << ((i == 0) ? "{" : ", ");
        std::cout << sets[i];
    }
    std::cout << "}" << std::endl;
}

#endif
