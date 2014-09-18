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
	head = new node();
	size = L.length();
	// not completed
}

slist::~slist()
{
	for (int i = 0; i < size; i++) {
		pop_front();
	}
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
	node *q = head->next;
	for (int i = 0; i < size; i++) {
		if (q->val == x) {
			return i;
		}
		q = q->next;
	}
	return -1;
}

int slist::getitem(int i)const
{
	if (i < 0 || i >= size) {
		cerr << "Error: index out of range." << endl;
		exit(1);
	}
	node *q = head->next;
	for (int j = 0; j < i; j++) {
		q = q->next;
	}
	return q->val;
}
	
void slist::setitem(int i, int x)
{
	if (i < 0 || i >= size) {
		cerr << "Error: index out of range." << endl;
		exit(1);
	}
	node *q = head->next;
	for (int j = 0; j < i; j++) {
		q = q->next;
	}
	q->val = x;
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
