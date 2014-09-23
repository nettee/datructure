#include <iostream>
#include "polynomial.h"

using namespace std;

int main()
{
    double c[] = {1.1, 2.3, 6.2};
    int e[] = {0, 1, 4};
    Polynomial p;
    p.input(c, e, 3);
    p.output();
}
