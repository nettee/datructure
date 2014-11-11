#ifndef __GLIST_H__
#define __GLIST_H__

#include "list/dlist.h"

#include <iostream>
#include <string>

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
    DList<T> read_tokens();

private:
    GListNode<T> *head;
};

template <typename T>
DList<T> GList<T>::read_tokens()
{
    DList<T> wordlist;
    T word;
    while (std::cin >> word) {
        wordlist.push_back(word);
        std::cout << word;
    }
}

#endif
