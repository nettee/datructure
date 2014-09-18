#include <iostream>
#include "slist.h"

using namespace std;

int main()
{
	slist *a = new slist();
	a->output();
	a->push_front(9);
	a->push_front(70);
	a->push_front(18);
	a->push_front(22);
	a->output();
	cout << a->search(70) << endl;
	cout << a->search(8) << endl;
	cout << a->getitem(2) << endl;
	a->setitem(1,99);
	a->output();
	delete a;
}

