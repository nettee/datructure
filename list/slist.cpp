#include <iostream>
#include <string>
#include "slist.h"

using namespace std;

slist::slist()
{
	head = new node();
	size = 0;
}

slist::slist(slist& L)
{
	// not implemented
	size = 0;
}

slist::~slist()
{
	// not implemented
}

bool slist::empty()const
{
	return size == 0;
}

int slist::length()const
{
	return size;
}

int slist::search(int x)const
{
	// not implemented
}

int slist::getitem(int i)const
{
	// not implemented
}
	
void slist::setitem(int i, int x)
{
	// not implemented
}

void slist::push_front(int x)
{
	node *q = new node(x);
	q->next = head->next;
	head->next = q;
	++size;
}

void slist::pop_front()
{
	if (size == 0) {
		cerr << "Error: pop from empty list" << endl;
		exit(1);
	}
	node *q = head->next;
	head->next = q->next;
	delete q;
	--size;
}

void slist::output()
{
	node *q = head->next;
	cout << "[";
	for (int i = 0; i != size; ++i) {
		cout << q->val << ", ";
		q = q->next;
	}
	cout << "]" << endl;
}
