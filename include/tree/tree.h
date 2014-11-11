#include <iostream>
#include <cassert>

template <typename T>
struct TreeNode {
    T val;
    TreeNode *child;
    TreeNode *next;
    TreeNode(T x) {
        val = x;
        child = NULL;
        next = NULL;
    }
};

template <typename T>
TreeNode<T> *add_child(TreeNode<T> *last, T x)
{
    TreeNode<T> *q = new TreeNode<T>(x);
    last->child = q;
    return q;
}
    
template <typename T>
TreeNode<T> *add_next(TreeNode<T> *last, T x)
{
    TreeNode<T> *q = new TreeNode<T>(x);
    last->next = q;
    return q;
}

template <typename T>
class Tree {
public:
    Tree();
    Tree(Tree<T>& tree);
    ~Tree();

    bool empty();

    int height();
    int nodes();

    void output();

private:
    TreeNode<T> *root;

    void clear(TreeNode<T> *t);
    void print_tree(TreeNode<T> *);
};

template <typename T>
Tree<T>::Tree()
{
    root = new TreeNode<T>(18);
    TreeNode<T> *q, *last = root;
    last = add_child(last, 2);
    last = add_next(last, 20);
    last = add_next(last, 4);
    last = root->child->next;
    last = add_child(last, 1);
    last = add_next(last, 3);
    last = add_next(last, 5);
}

template <typename T>
Tree<T>::~Tree()
{
    clear(root);
}

template <typename T>
void Tree<T>::clear(TreeNode<T> *t)
{
    if (t == NULL) {
        return;
    }
    TreeNode<T> *q = t->child;
    while (q != NULL) {
        TreeNode<T> *p = q;
        q = q->next;
        delete p;
    }
    delete t;
}

template <typename T>
void Tree<T>::output()
{
    print_tree(root);
    std::cout << std::endl;
}

template <typename T>
void Tree<T>::print_tree(TreeNode<T> *t)
{
    if (t == NULL) {
        return;
    }
    std::cout << "(" << t->val;
    for (TreeNode<T> *q = t->child; q != NULL; q = q->next) {
        std::cout << " ";
        if (q->child == NULL) {
            std::cout << q->val;
        } else {
            print_tree(q);
        }
    }
    std::cout << ")";
}

