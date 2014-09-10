#include "stack.h"

void f()
{
    try {
        while (true)
            Stack::push('c');
    } catch (Stack::Overflow) {
        // oops: stack overflow;
        // take appropriate action
    }

}
