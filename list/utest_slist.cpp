#include <iostream>
#include "slist.h"

using namespace std;

int main()
{
	slist<int> *a = new slist<int>();

	//a->push_front(9);
	//a->push_front(70);
	//a->push_front(18);
	//a->push_front(22);
    a->input();
	a->output();

//	a->setitem(1,99);
//	a->output();
//    a->push_front(1);
//    a->push_front(74);
//    a->push_front(52);
//    a->push_back(-10);
//    a->push_back(88);
//    a->output();
//	slist<int> b(*a);
//	b.output();
//
    slist<int> *c = new slist<int>();
    reverse(a, c);
    c->output();

	delete a;
}

