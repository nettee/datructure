#include <iostream>
#include "list/arraylist.h"

using namespace std;

int main()
{
    ArrayList<int> a;
    assert(a.isEmpty());
    assert(a.size() == 0);
    a.add(1);
    a.add(8);
    a.add(17);
    a.add(80);
    assert(a.size() == 4);
    a.set(1, 9);
    assert(a.get(1) == 9);
    assert(a.size() == 4);
    a.output();
    a.add(0, 4);
    a.output();
    a.add(2, 22);
    a.output();
}


