#ifndef __LINKED_LIST_H__
#define __LINKED_LIST_H__

#include <iostream>
#include <cassert>

template <typename E>
struct LinkedNode {
    E val;
    LinkedNode<E> *prev;
    LinkedNode<E> *next;
    LinkedNode() {
        val = E();
        prev = NULL;
        next = NULL;
    }
    LinkedNode(E x) {
        val = x;
        prev = NULL;
        next = NULL;
    }
};

template <typename E>
class LinkedList {
public:
    LinkedList() {
        head = new LinkedNode<E>();
        rear = new LinkedNode<E>();
        head->next = rear;
        rear->prev = head;
        theSize = 0;
    }

    ~LinkedList() {
        clear();
        delete head;
        delete rear;
    }

    void clear() {
        LinkedNode<E> *q = head->next;
        for (int i = 0; i < theSize; i++) {
            LinkedNode<E> *p = q;
            q = q->next;
            delete p;
        }
        head->next = rear;
        rear->prev = head;
        theSize = 0;
    }

    bool isEmpty() {
        return theSize == 0;
    }

    int size() {
        return theSize;
    }

    E getFirst() {
        assert(!isEmpty());
        return head->next->val;
    }

    E getLast() {
        assert(!isEmpty());
        return rear->prev->val;
    }

    E get(int index) {
        assert(index >= 0 && index < theSize);
        LinkedNode<E> *q = head->next;
        for (int j = 0; j < index; j++) {
            q = q->next;
        }
        return q->val;
    }

    E set(int index, E e) {
        assert(index >= 0 && index < theSize);
        LinkedNode<E> *q = head->next;
        for (int j = 0; j < index; j++) {
            q = q->next;
        }
        E prev_element = q->val;
        q->val = e;
        return prev_element;
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
        for (int i = 0; i < theSize; i++) {
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
        for (int i = 0; i < theSize; i++) {
            if (q->val == x) {
                lastIndex = i;
            }
            q = q->next;
        }
        return lastIndex;
    }

    void addFirst(E e) {
        LinkedNode<E> *q = new LinkedNode<E>(e);
        q->next = head->next;
        head->next->prev = q;
        q->prev = head;
        head->next = q;
        ++theSize;
    }

    void addLast(E e) {
        LinkedNode<E> *q = new LinkedNode<E>(e);
        q->prev = rear->prev;
        rear->prev->next = q;
        q->next = rear;
        rear->prev = q;
        ++theSize;
    }

    bool add(E e) {
        addLast(e);
        return true;
    }

    void add(int index, E e) {
        assert(index >= 0 && index < theSize);
        LinkedNode<E> *current = head->next;
        for (int j = 0; j < index; j++) {
            current = current->next;
        }
        LinkedNode<E> *q = new LinkedNode<E>(e);
        q->prev = current->prev;
        q->next = current;
        current->prev->next = q;
        current->prev = q;
        ++theSize;
    }

    E removeFirst() {
        assert(!isEmpty());
        LinkedNode<E> *q = head->next;
        q->next->prev = head;
        head->next = q->next;
        E val = q->val;
        delete q;
        --theSize;
        return val;
    }
    
    E removeLast() {
        assert(!isEmpty());
        LinkedNode<E> *q = rear->prev;
        q->prev->next = rear;
        rear->prev = q->prev;
        E val = q->val;
        delete q;
        --theSize;
        return val;
    }

    bool removeFirstOccurrence(E x) {
        LinkedNode<E> *q;
        for (q = head->next; q != rear; q = q->next) {
            if (q->val == x) {
                q->prev->next = q->next;
                q->next->prev = q->prev;
                delete q;
                --theSize;
                return true;
            }
        }
        return false;
    }

    bool removeLastOccurrence(E x) {
        LinkedNode<E> *lastNode = NULL;
        LinkedNode<E> *q;
        for (q = head->next; q != rear; q = q->next) {
            if (q->val == x) {
                lastNode = q;
            }
        }
        if (lastNode) {
            lastNode->prev->next = lastNode->next;
            lastNode->next->prev = lastNode->prev;
            delete lastNode;
            --theSize;
        }
        return lastNode != NULL;
    }

    E remove() {
        return removeFirst();
    }

    /* different from Java API
     * because of the pitfall of C++ language
     */
    E removeByIndex(int index) {
        assert(index >= 0 && index < theSize);
        LinkedNode<E> *q = head->next;
        for (int j = 0; j < index; j++) {
            q = q->next;
        }
        q->prev->next = q->next;
        q->next->prev = q->prev;
        E val = q->val;
        delete q;
        --theSize;
        return val;
    }

    bool remove(E x) {
        LinkedNode<E> *q;
        for (q = head->next; q != rear; q = q->next) {
            if (q->val == x) {
                q->prev->next = q->next;
                q->next->prev = q->prev;
                delete q;
                --theSize;
                return true;
            }
        }
        return false;
    }

    // :IMPROVEABLE: efficiency
    void fromArray(E *source, int length) {
        clear();
        for (int i = 0; i < length; i++) {
            add(source[i]);
        }
    }

    // :IMPROVEABLE: efficiency
    void toArray(E *destination) {
        for (int i = 0; i < size(); i++) {
            destination[i] = get(i);
        }
    }

    void input();
    void output();

private:
    LinkedNode<E> *head;
    LinkedNode<E> *rear;
    int theSize;
};

template <typename E>
void LinkedList<E>::input()
{
    int len;
    std::cin >> len;
    E val;
    for (int i = 0; i < len; i++) {
        std::cin >> val;
        push_back(val);
    }
}

template <typename E>
void LinkedList<E>::output()
{
    LinkedNode<E> *q = head->next;
    for (int i = 0; i < theSize; i++) {
        if (q == NULL) break;
        std::cout << q->val << " ";
        q = q->next;
    }
    std::cout << std::endl;
}

#endif
