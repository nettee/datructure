#include <iostream>
#include <cstdlib>
#include <cstring>
#include "sstring.h"

using namespace std;

String::String()
{
    v = new char[1];
    v[0] = '\0';
}

String::String(const char* s)
{
    v = new char[strlen(s)+1];
    strcpy(v, s);
}

String::String(String& s)
{
    v = new char[s.length()+1];
    strcpy(v, s.v);
}

String::~String()
{
    delete []v;
    v = NULL;
}

int String::length()
{
    return strlen(v);
}


