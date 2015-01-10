#include <iostream>
#include <string>
#include <vector>
#include <cctype>
#include <cstdlib>

using namespace std;

/* split a string into word, delimited by blank(s)
 * return: vector of strings, each string a word
 * each string is promised to be no blanks
 */
vector<string> split(const string& s)
{
    vector<string> res;
    string::size_type i = 0;
    while (i != s.size()) {
        // ignore leading blanks
        while (i != s.size() && isspace(s[i]))
            ++i;
        // find end of next word
        string::size_type j = i;
        while (j != s.size() && !isspace(s[j]))
            j++;

        // extract a word
        if (i != j) {
            res.push_back(s.substr(i, j - i));
            i = j;
        }
    }
    return res;
}

/* split an "at string" into two parts
 * an "at string" is like "1234567@3456789"
 * return from arg d1 and d2, d1 = 123456, d2 = 3456789
 */
void split_at(const string& s, int& d1, int& d2)
{
    string::size_type i = 0;
    while (i != s.size() && s[i] != '@')
        i++;
    d1 = atoi(s.substr(0, i).c_str());
    d2 = atoi(s.substr(i+1, s.size()-i-1).c_str());
}
