#include <iostream>

#include "sstack.h"

using namespace std;

int main()
{
    sstack<char> s;
    assert(s.empty());
    assert(!s.full());
    s.push('a');
    assert(!s.empty());
    s.push('r');
    s.push('5');
    s.push('p');
    assert(s.size() == 4);
    char a = s.pop();
    assert(a == 'p');
    assert(s.size() == 3);

    s.output();
}
