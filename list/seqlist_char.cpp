#include <iostream>
#include "seqlist_char.h"

using namespace std;

seqlist_char::seqlist_char(int size)
{
    if (size <= 0) {
        cerr << "size <= 0" << endl;
        exit(1);
    }
    max_size = size;
    n = 0;
    v = new char[max_size];
}

seqlist_char::seqlist_char(seqlist_char& L)
{
    max_size = L.size();
    n = L.length();
    v = new char[max_size];
    for (int i = 0; i != n; ++i) {
        v[i] = L.getitem(i);
    }
}

seqlist_char::~seqlist_char()
{
    delete []v;
    n = 0;
}

int seqlist_char::search(char c)
{
    for (int i = 0; i != n; ++i) {
        if (v[i] == c)
            return i;
    }
    return -1;
}

char seqlist_char::getitem(int i)
{
    return v[i];
}

void seqlist_char::setitem(int i, char c)
{
    v[i] = c;
}
