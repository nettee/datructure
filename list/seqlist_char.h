#include <iostream>

class seqlist_char
{
public:
    // construction and destruction
    seqlist_char(int size);
    seqlist_char(seqlist_char& L);
    ~seqlist_char();

    // list info and referrence
    bool empty()const;
    int length()const;
    int size()const; // singular
    int search(char c)const;

    // item operation
    char getitem(int i)const;
    void setitem(int i, char c);

    // modify a list
//    void insert(int i, char c);
//    void remove(int i, char c);
//    void append(char c);
//    char pop();
//    void extend(seqlist_char& L);

    // other operations
//    seqlist_char operator=(seqlist_char L);

private:
    char *v;
    int max_size;
    int n;
};
