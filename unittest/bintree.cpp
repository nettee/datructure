#include <iostream>
#include "tree/bintree.h"

using namespace std;

int main()
{
    BinTree<char> t;
    char v[7] = {'a', 'b', 'c', 'd', '*', 'f', 'g'};
    t.input(v, 7);
    t.output();
    t.preorder_traversal();
    t.inorder_traversal();
    t.postorder_traversal();
    return 0;
}
