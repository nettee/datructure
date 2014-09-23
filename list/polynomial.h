#include <iostream>
#include <cstdlib>
#include <cassert>

#ifndef _POLINOMIAL_H_
#define _POLINOMIAL_H_

struct term {
    double coeff;
    int expo;
    term *next;
    term(double c, int e) {
        coeff = c;
        expo = e;
        next = NULL;
    }
};

class Polynomial {
public:
    Polynomial();
//    Polynomial(Polynomial& p);
    ~Polynomial();

    void input(double *c, int *e, int len);
    void output();

private:
    term *first;

};

Polynomial add_poly(Polynomial& a, Polynomial& b);

#endif
