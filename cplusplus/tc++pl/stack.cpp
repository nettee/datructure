#include "stack.h"

Stack::Stack(int s)
{
    top = 0;
    if (s > 10000)
        throw Bad_size();
    max_size = s;
    v = new char[s];
}

Stack::~Stack()
{
    delete[] v;
}

void Stack::push(char c)
{
    if (top == max_size)
        throw Overflow();
    v[top] = c;
    top++;
}

char Stack::pop()
{
    if (top == 0)
        throw Underflow();
    top--;
    return v[top];
