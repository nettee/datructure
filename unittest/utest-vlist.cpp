#include <iostream>
#include "list/vlist.h"

using namespace std;

int main()
{
    vlist<int> a;
    assert(a.empty());
    assert(a.size() == 0);
    a.push_back(1);
    a.push_back(8);
    a.push_back(17);
    a.push_back(80);
    assert(!a.empty());
    assert(a.size() == 4);
    a.setitem(1, 9);
    assert(a.getitem(1) == 9);
    assert(a.size() == 4);
    a.pop_back();
    a.pop_back();
    assert(a.size() == 2);

}


