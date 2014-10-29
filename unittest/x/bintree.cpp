#include <iostream>
#include "tree/bintree.h"

using namespace std;

char v[29] = {
                                  'A',


                  'B',                            'C',

          'D',            '*',            'E',            'F',

      'G',    'H',    '*',    '*',    '*',    'I',    'J',   '*',
    '*','*','*','*','*','*','*','*','*','*','*','*','K','L',
};

int main()
{
    BinTree<char> t;
    t.input(v, 29);
    t.output();
    t.preorder_traversal();
    t.inorder_traversal();
    t.postorder_traversal();
    return 0;
}
