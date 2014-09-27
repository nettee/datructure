#include <iostream>
#include <cstdlib>
#include <cassert>

#ifndef _SLIST_H_
#define _SLIST_H_

template <typename T>
struct node {
    T val;
    node<T> *next;
    node() {
        val = T();
        next = NULL;
    }
    node(T data) {
        val = data;
        next = NULL;
    }
};

template <typename T>
class slist {
public:
    // construction and destruction
    slist();
    slist(slist<T>& L);
    ~slist();

    // list info and referrence
    bool empty()const;
    int size()const;
    int search(T x)const;

    // item operation
    T getitem(int i)const;
    void setitem(int i, T x);

    // modify a list
	void push_front(T x);
	T pop_front();
    void push_back(T x);

    void input();
    void output();

private:
    node<T> *head;
    node<T> *last;
    int n;
};

template <typename T>
void reverse(slist<T> *in, slist<T> *out);

template <typename T>
slist<T>::slist()
{
	head = new node<T>();
    head->next = head;
    last = head;
	n = 0;
}

template <typename T>
slist<T>::slist(slist<T>& L)
{
    head = new node<T>();
    n = L.size();
	node<T> *p = L.head;
	node<T> *q = head;
	for (int i = 0; i < n; i++) {
		p = p->next;
		node<T> *np = new node<T>(p->val);
		q->next = np;
		q = q->next;
        if (i == n - 1) {  // last node
            last = q;
            q->next = head;
        }
    }
}

template <typename T>
slist<T>::~slist()
{
	for (int i = 0; i < n; i++) {
		pop_front();
	}
}

template <typename T>
bool slist<T>::empty()const
{
	return n == 0;
}

template <typename T>
int slist<T>::size()const
{
	return n;
}

template <typename T>
int slist<T>::search(T x)const
{
	node<T> *q = head->next;
	for (int i = 0; i < n; i++) {
		if (q->val == x) {
			return i;
		}
		q = q->next;
	}
	return -1;
}

template <typename T>
T slist<T>::getitem(int i)const
{
    assert(i >= 0 && i < n);
	node<T> *q = head->next;
	for (int j = 0; j < i; j++) {
		q = q->next;
	}
	return q->val;
}
	
template <typename T>
void slist<T>::setitem(int i, T x)
{
    assert(i >= 0 && i < n);
	node<T> *q = head->next;
	for (int j = 0; j < i; j++) {
		q = q->next;
	}
	q->val = x;
}

template <typename T>
void slist<T>::push_front(T x)
{
	node<T> *q = new node<T>(x);
    if (n == 0) {
        last = q;
    }
	q->next = head->next;
	head->next = q;
	++n;
}

template <typename T>
T slist<T>::pop_front()
{
    assert(n != 0);
	node<T> *q = head->next;
	head->next = q->next;
    T val = q->val;
	delete q;
	--n;
    if (n == 0) {
        last = head;
    }
    return val;
}

template <typename T>
void slist<T>::push_back(T x)
{
    node<T> *q = new node<T>(x);
    q->next = head;
    // note that in empty list, var last is head
    last->next = q;
    last = q;
    ++n;
}

template <typename T>
void slist<T>::input()
{
    int len;
    std::cin >> len;
    T val;
    for (int i = 0; i < len; i++) {
        std::cin >> val;
        push_back(val);
    }
}

template <typename T>
void slist<T>::output()
{
	node<T> *q = head->next;
	for (int i = 0; i != n; ++i) {
		std::cout << q->val << " ";
		q = q->next;
	}
	std::cout << std::endl;
}

template <typename T>
void reverse(slist<T> *in, slist<T> *out)
{
    while (!in->empty()) {
        T val = in->pop_front();
        out->push_front(val);
    }
}

#endif
