#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <cassert>
#include "list/array.h"

template <typename E>
struct LinkedNode {
    LinkedNode<E> *prev;
    LinkedNode<E> *next;
    E val;
    LinkedNode(): prev(NULL), next(NULL), val(E()) {}
    LinkedNode(const E& x): prev(NULL), next(NULL) { val = x; }
};

template <typename E>
class LinkedList {
public:
    LinkedList() {
        head = new LinkedNode<E>();
        rear = new LinkedNode<E>();
        head->next = rear;
        rear->prev = head;
        siz = 0;
    }

    ~LinkedList() {
        clear();
        delete head;
        delete rear;
    }

    void clear() {
        LinkedNode<E> *q = head->next;
        for (int i = 0; i < siz; i++) {
            LinkedNode<E> *p = q;
            q = q->next;
            delete p;
        }
        head->next = rear;
        rear->prev = head;
        siz = 0;
    }

    bool empty() const { return siz == 0; }
    int size() const { return siz; }

    E first() {
        assert(!isEmpty());
        return head->next->val;
    }

    E last() {
        assert(!isEmpty());
        return rear->prev->val;
    }

    bool contains(E x) {
        LinkedNode<E> *q;
        for (q = head->next; q != rear; q = q->next) {
            if (q->val == x) {
                return true;
            }
        }
        return false;
    }

    int indexOf(E x) {
        LinkedNode<E> *q = head->next;
        for (int i = 0; i < siz; i++) {
            if (q->val == x) {
                return i;
            }
            q = q->next;
        }
        return -1;
    }

    int lastIndexOf(E x) {
        int lastIndex = -1;
        LinkedNode<E> *q = head->next;
        for (int i = 0; i < siz; i++) {
            if (q->val == x) {
                lastIndex = i;
            }
            q = q->next;
        }
        return lastIndex;
    }

    void push_front(const E& e) {
        LinkedNode<E> *q = new LinkedNode<E>(e);
        q->next = head->next;
        head->next->prev = q;
        q->prev = head;
        head->next = q;
        ++siz;
    }

    void push_back(const E& e) {
        LinkedNode<E> *q = new LinkedNode<E>(e);
        q->prev = rear->prev;
        rear->prev->next = q;
        q->next = rear;
        rear->prev = q;
        ++siz;
    }

    E pop_front() {
        assert(!isEmpty());
        LinkedNode<E> *q = head->next;
        q->next->prev = head;
        head->next = q->next;
        E val = q->val;
        delete q;
        --siz;
        return val;
    }
    
    E pop_back() {
        assert(!isEmpty());
        LinkedNode<E> *q = rear->prev;
        q->prev->next = rear;
        rear->prev = q->prev;
        E val = q->val;
        delete q;
        --siz;
        return val;
    }

//    void fromArray(Array<E> *array) {
//        clear();
//        for (int i = 0; i < array->size(); i++) {
//            addLast(array->get(i));
//        }
//    }

private:
    LinkedNode<E> *head;
    LinkedNode<E> *rear;
    int siz;
};

#endif
