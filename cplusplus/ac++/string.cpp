#include <iostream>
#include <string>
#include <cctype>

using namespace std;

vector<string> split(const string& s)
{
    vector<string> ret;
    string::string_size i = 0;

    // invariant: we have processed [0..i)
    while (i != s.size()) {

        // ignore leading blanks
        while (i != s.size() && isspace(s[i]))
            ++i;

        // find end of next word
        string::size_type j = i;
        while (j != s.size() && !isspace(s[j])) 
            j++;

        // if we found some nonwhitespace characters
        if (i != j) {
            ret.push_back(s.substr(i, j - i));
            i = j;
        }
    }
    return ret;
}
