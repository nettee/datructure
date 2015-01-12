#ifndef __AVL_TREE_SET_H__
#define __AVL_TREE_SET_H__

#include <iostream>
#include <cassert>

template <typename E>
struct AvlNode {
    E val;
    AvlNode *left;
    AvlNode *right;
    int height;
    AvlNode(E x): left(NULL), right(NULL) {
        val = x;
        height = 0;
    }
};

template <typename E>
int height(AvlNode<E> *t) {
    return (t == NULL) ? -1 : t->height;
}

template <typename E>
class AvlTree {
public:
    AvlTree(): root(NULL) { }
    ~AvlTree() { clear(root); }

    void clear() {
        clear(root);
        root = NULL;
    }

    bool empty() { return root == NULL; }

    void insert(E x) { insert(x, root); }

    void reverse_n_visit(int n, void visit(const E&));

private:
    AvlNode<E> *root;

    void clear(AvlNode<E> *t) {
        if (t == NULL) {
            return;
        }
        clear(t->left);
        clear(t->right);
        delete t;
    }

    void rotate_left(AvlNode<E> *&k2) {
        AvlNode<E> *k1 = k2->left;
        k2->left = k1->right;
        k1->right = k2;
        k2->height = std::max(height(k2->left), height(k2->right)) + 1;
        k1->height = std::max(height(k1->left), k2->height) + 1;
        k2 = k1;
    }

    void rotate_right(AvlNode<E> *&k1) {
        AvlNode<E> *k2 = k1->right;
        k1->right = k2->left;
        k2->left = k1;
        k1->height = std::max(height(k1->left), height(k1->right)) + 1;
        k2->height = std::max(height(k2->right), k1->height) + 1;
        k1 = k2;
    }

    void double_left(AvlNode<E> *&k3) {
        rotate_right(k3->left);
        rotate_left(k3);
    }

    void double_right(AvlNode<E> *&k1) {
        rotate_left(k1->right);
        rotate_right(k1);
    }

    void insert(E x, AvlNode<E> *&t) {
        if (t == NULL) {
            t = new AvlNode<E>(x);
        } else if (x < t->val) {
            insert(x, t->left);
            if (height(t->left) - height(t->right) >= 2) {
                if (x < t->left->val) {
                    rotate_left(t);
                } else {
                    double_left(t);
                }
            }
        } else if (x > t->val) {
            insert(x, t->right);
            if (height(t->right) - height(t->left) >= 2) {
                if (x > t->right->val) {
                    rotate_right(t);
                } else {
                    double_right(t);
                }
            }
        } else {  // duplicate
            ;  // do nothing
        }
        t->height = std::max(height(t->left), height(t->right)) + 1;
    }

    void reverse_n_visit(AvlNode<E> *t, int n, void visit(const E&)) {
        if (t == NULL) {
            return;
        }
        reverse_n_visit(t->right, n, visit);
        visit(t->val);
        reverse_n_visit(t->left, n, visit);
    }
};

#endif
