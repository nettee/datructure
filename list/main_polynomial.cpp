#include "polynomial.h"
#include <iostream>

using namespace std;

int main()
{
    Polynomial p;
    p.input();
    p.output();
    cout << p.length() << endl;

    Polynomial q;
    q.input();
    q.output();
    cout << q.length() << endl;

    Polynomial s;
    add_poly(p, q, s);
    s.output();
}
