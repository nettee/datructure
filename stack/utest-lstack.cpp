#include <iostream>

#include "lstack.h"

using namespace std;

int main()
{
    lstack<char> s;
    assert(s.empty());
    s.push('a');
    assert(!s.empty());
    cout << s.pop() << endl;
    s.pop();
    s.push('r');
    s.push('5');
    s.push('p');
    char a = s.pop();
    assert(a == 'p');

    s.output();
}
