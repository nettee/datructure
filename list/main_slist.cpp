#include <iostream>
#include "slist.h"

using namespace std;

int main()
{
	slist a;
	slist* b = new slist(a);
	a.output();
	a.push_front(9);
	a.push_front(70);
	a.output();
	a.pop_front();
	a.output();

}

