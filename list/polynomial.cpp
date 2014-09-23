#include <iostream>
#include "polynomial.h"

using namespace std;

Polynomial::Polynomial()
{
    first = NULL;
}

Polynomial::~Polynomial()
{
    term *q;
    while (first != NULL) {
        q = first;
        first = first->next;
        delete q;
    }
}

void Polynomial::input(double *c, int *e, int len)
{

}

void Polynomial::output()
{
    for (term *q = first; q != NULL; q = q->next) {
        cout << "(" << q->coeff << ", ";
        cout << q->expo << ") ";
    }
    cout << endl;
}
