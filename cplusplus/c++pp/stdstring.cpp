#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s1;
    string s2 = s1;
    string s3 = "hiya";
    string s4(10, 'c');
    cout << s1 << endl << s2 << endl;
    cout << s3 << endl << s4 << endl;
}

