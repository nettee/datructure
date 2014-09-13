#include <iostream>
#include "sstring.h"

using namespace std;

int main()
{
    String a;
    String b("abcdef");
    cout << a.length() << endl;
    cout << b.length() << endl;
    String c(b);
    cout << c.length() << endl;

}
