#ifndef _SINGLE_LIST_H_
#define _SINGLE_LIST_H_

#include <iostream>
#include <cstdlib>
#include <cassert>

template <typename E>
struct SListNode {
    E val;
    SListNode<E> *next;
    SListNode(): val(E()), next(NULL) {}
    SListNode(E data): next(NULL) { val = data; }
};

template <typename E>
class SingleList {
public:
    SingleList() { head = NULL; }
    ~SingleList() { clear(); }
    SingleList(SingleList<E>& rhs);
    SingleList& operator=(SingleList<E>& rhs);

    bool empty() const { return head == NULL; }

    void push_front(E& x) {
        SListNode<E>* q = new SListNode<E>(x);
        q->next = head;
        head = q;
    }

    E pop_front() {
        SListNode<E> *q = head;
        head = head->next;
        E val = q->val;
        delete q;
        return E;
    }

private:
    SListNode<E> *head;
};

template <typename E>
SingleList<E>::SingleList(SingleList<E>& L)
{
    head = new SListNode<E>();
    n = L.size();
	SListNode<E> *p = L.head;
	SListNode<E> *q = head;
	for (int i = 0; i < n; i++) {
		p = p->next;
		SListNode<E> *np = new SListNode<E>(p->val);
		q->next = np;
		q = q->next;
        if (i == n - 1) {  // last SListNode
            last = q;
            q->next = head;
        }
    }
}

#endif
