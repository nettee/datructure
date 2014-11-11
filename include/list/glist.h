#ifndef __GLIST_H__
#define __GLIST_H__

#include "list/dlist.h"

#include <iostream>
#include <string>

enum { HEAD, ATOM, SUBLIST };

template <typename T>
struct GListNode {
    int ntype;
    struct {
        T *a;
        T *b;
    };
    GListNode *next;
};

template <typename T>
class GList {
public:
    void input();

private:
    GListNode<T> *head;
};

template <typename T>
GListNode<T> *read_from_tokens(DList<T>& tokens)
{
    GListNode<T> *q = new GListNode<T>;
    return q;
}

template <typename T>
void GList<T>::input()
{
    DList<std::string> tokens;
    std::string word;
    while (std::cin >> word) {
        tokens.push_back(word);
    }
    assert(!tokens.empty());
    tokens.output();
    head = read_from_tokens(tokens);
}

#endif
