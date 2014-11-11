#include "list/dlist.h"

#include <iostream>
#include <random>

using namespace std;

int main()
{
    DList<int> a;
    assert(a.empty());
    default_random_engine e;
    for (int i = 0; i < 10; i++) {
        a.push_back(e());
    }
    assert(a.size() == 10);
    a.setitem(1, 9);
    assert(a.getitem(1) == 9);
    assert(a.size() == 10);
    a.pop_front();
    a.pop_front();
    assert(a.size() == 8);
}


