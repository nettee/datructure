#include <iostream>
#include <cstring>

class String
{
public:
    String();
    String(const char *);
    String(String&);
    ~String();
    int length();
private:
    char *v;
};
