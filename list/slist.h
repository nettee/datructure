#include <iostream>
#include <cstdlib>

#ifndef _SLIST_H_
#define _SLIST_H_

struct node {
    int val;
    node *next;
    node() {
        val = 0;
        next = NULL;
    }
    node(int data) {
        val = data;
        next = NULL;
    }
};

class slist {
public:
    // construction and destruction
    slist();
    slist(slist& L);
    ~slist();

    // list info and referrence
    bool empty()const;
    int length()const;
    int search(int x)const;

    // item operation
    int getitem(int i)const;
    void setitem(int i, int x);

    // modify a list
	void push_front(int x);
	void pop_front();
//    void insert(int i, int x);
//    void remove(int i, int x);
//    void append(int x);
//    int pop();
//    void extend(slist& L);

    // other operations
//    slist operator=(slist L);

    // list reprenstation
    void output();

private:
    node *head;
    int size;
};

#endif
