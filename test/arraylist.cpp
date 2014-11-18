#include <iostream>
#include "list/arraylist.h"

using namespace std;

static const int lengthOfSource = 7;
int source[100] = {1, 3, 5, 7, 9, 11, 13};
int destination[100];

int main()
{
    // initialization test
    ArrayList<int> a;
    assert(a.isEmpty());
    assert(a.size() == 0);
    a.add(1);
    assert(!a.isEmpty());
    assert(a.size() == 1);
    a.clear();
    assert(a.isEmpty());
    a.add(1);
    assert(a.size() == 1);

    a.fromArray(source, lengthOfSource);
    assert(a.size() == lengthOfSource);
    a.toArray(destination);
    for (int i = 0; i < lengthOfSource; i++) {
        assert(source[i] == destination[i]);
    }

    // get and set test
    a.clear();
    for (int i = 1; i < 100; i += 2) {
        a.add(i);
    }
    for (int i = 0; i < a.size(); i++) {
        a.set(i, a.get(i) - 1);
    }
    for (int i = 0; i < a.size(); i++) {
        assert(a.get(i) == i * 2);
    }
    for (int i = 0; i < 100; i++) {
        if (i % 2 == 1) {
            assert(!a.contains(i));
        } else {
            assert(a.contains(i));
        }
    }


    return 0;
}


