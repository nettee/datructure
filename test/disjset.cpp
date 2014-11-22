#include <iostream>
#include <cassert>

#include "set/disjset.h"

using namespace std;

int main()
{
    DisjointSet s(8);
    s.setUnion(2, 4);
    s.setUnion(2, 3);
    s.output();
    cout << s.find(2) << ", " << s.find(3);
    cout << ", " << s.find(4) << endl;
    return 0;
}
