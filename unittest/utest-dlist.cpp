#include <iostream>
#include "list/dlist.h"

using namespace std;

int main()
{
    dlist<int> a;
    assert(a.empty());
    assert(a.size() == 0);
    a.push_front(1);
    a.push_back(8);
    a.push_back(17);
    a.push_back(80);
    assert(!a.empty());
    assert(a.size() == 4);
    a.setitem(1, 9);
    assert(a.getitem(1) == 9);
    assert(a.size() == 4);
//    a.pop_front();
//    a.pop_front();
//    assert(a.size() == 2);
    a.output();
}


