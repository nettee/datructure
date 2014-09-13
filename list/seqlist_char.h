#include <iostream>

class seqlist_char
{
public:
    seqlist_char(int size);
    seqlist_char(seqlist_char& L);
    ~seqlist_char();

    int size()const;
    int length()const;
    int search(char c)const;
    char getitem(int i)const;
    void setitem(int i, char c);
    void insert(int i, char c);
    void remove(int i, char c);
    void empty();
    void full();
    seqlist_char operator=(seqlist_char L);
private:
    char *v;
    int max_size;
    int n;
};
