#include <iostream>
#include <cassert>

template <typename T>
struct BinTreeNode {
    T val;
    BinTreeNode *left;
    BinTreeNode *right;
    BinTreeNode(T x) {
        val = x;
        left = NULL;
        right = NULL;
    }
};

template <typename T>
class BinTree {
public:
    BinTree();
    BinTree(BinTree<T>& tree);
    ~BinTree();

    bool empty();
    int height();
    int nodes();

    void input(T *v, int len);
    void output() { 
        output_(t); 
        std::cout << std::endl;
    }

    void preorder_traversal();

private:
    BinTreeNode<T> *t;

    BinTreeNode<T> *input_subtree(int, T *, int);
    void output_(BinTreeNode<T> *t);
};

template <typename T>
BinTree<T>::BinTree()
{
    t = NULL;
}

template <typename T>
BinTree<T>::~BinTree()
{
    return;
}

template <typename T>
void BinTree<T>::input(T *v, int len)
{
    assert(len > 0);
    t = input_subtree(1, v, len);
}

template <typename T>
BinTreeNode<T> *BinTree<T>::input_subtree(int num, T *v, int len)
{
    if (num > len) {
        return NULL;
    }
    BinTreeNode<T> *np = new BinTreeNode<T>(v[num-1]);
    np->left = input_subtree(num * 2, v, len);
    np->right = input_subtree(num * 2 + 1, v, len);
    return np;
}

template <typename T>
void BinTree<T>::output_(BinTreeNode<T> *t)
{
    if (t == NULL) {
        return;
    }
    if (t->left == NULL && t->right == NULL) {
        std::cout << t->val;
    } else {
        std::cout << "(";
        std::cout << t->val;
        if (t->left) {
            std::cout << " ";
            output_(t->left);
        }
        if (t->right) {
            std::cout << " ";
            output_(t->right);
        }
        std::cout << ")";
    }
}
    
    
    

