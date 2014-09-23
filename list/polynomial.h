#include <iostream>
#include <cstdlib>
#include <cassert>

#ifndef _POLYNOMIAL_H_
#define _POLYNOMIAL_H_

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
    Polynomial(Polynomial& L);
    ~Polynomial();

    bool empty();
    int length();

	void push_front(double c, int e);
	void pop_front();
    void push_back(double c, int e);

    void input();
    void output();

private:
    term *head;
    term *last;
    int size;
};


Polynomial::Polynomial()
{
	head = new term(0.0, -1);
    head->next = head;
    last = head;
	size = 0;
}

Polynomial::Polynomial(Polynomial& L)
{
    head = new term(0.0, -1);
    size = L.length();
	term *p = L.head;
	term *q = head;
	for (int i = 0; i < size; i++) {
		p = p->next;
		term *np = new term(p->coeff, p->expo);
		q->next = np;
		q = q->next;
        if (i == size - 1) {  // last term
            last = q;
            q->next = head;
        }
    }
}

Polynomial::~Polynomial()
{
	for (int i = 0; i < size; i++) {
		pop_front();
	}
}

bool Polynomial::empty()
{
	return size == 0;
}

int Polynomial::length()
{
    return size;
}

void Polynomial::push_front(double c, int e)
{
	term *q = new term(c, e);
    if (size == 0) {
        last = q;
    }
	q->next = head->next;
	head->next = q;
	++size;
}

void Polynomial::pop_front()
{
    assert(size != 0);
	term *q = head->next;
	head->next = q->next;
	delete q;
	--size;
    if (size == 0) {
        last = head;
    }
}

void Polynomial::push_back(double c, int e)
{
    term *q = new term(c, e);
    q->next = head;
    // note that in empty list, var last is head
    last->next = q;
    last = q;
    ++size;
}

void Polynomial::input()
{
    double c;
    int e;
    while (true) {
        std::cin >> c >> e;
        if (e == -1)
            return;
        push_back(c, e);
    }
}

void Polynomial::output()
{
	term *q = head->next;
	for (int i = 0; i != size; ++i) {
        std::cout << "(" << q->coeff << ", ";
        std::cout << q->expo << ")" << std::endl;
		q = q->next;
	}
}

#endif
