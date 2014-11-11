#include <iostream>
#include <cassert>

template <typename T>
struct bstreenode {
    T val;
    bstreenode *left;
    bstreenode *right;
    bstreenode(T x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

template <typename T>
class bstree {
public:
    bstree();
    bstree(const bstree<T>& tree);
    ~bstree();

    bool empty()const;
    void insert(const T& x);

private:

};
