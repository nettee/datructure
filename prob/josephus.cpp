#include <iostream>
#include <cstdlib>
#include <cassert>
#include "list/dlist.h"

using namespace std;

void josephus(int n, int m)
{
    dlist<int> L;
    for (int i = 0; i < n; i++) {
        L.push_back(i);
    }
    L.output();
}

int main(int argc, char *argv[])
{
    assert(argc == 3);
    int n, m;
    n = atoi(argv[1]);
    m = atoi(argv[2]);
    cout << "n = " << n << ", m = " << m << endl;

    josephus(n, m);

    return 0;
}
