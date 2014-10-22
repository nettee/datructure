#include <iostream>
#include <cassert>

template<typename T>
struct btreenode {
    T val;
    btreenode *left;
    btreenode *right;
    btreenode(T x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

template<typename T>
class btree {
public:
    btree();
    btree(btree<T>& tree);
    ~btree();

    bool empty();


    void input();
    void output();

private:
    btreenode<T> *t;
};
