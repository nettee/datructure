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

    add_poly(p, q);
}
