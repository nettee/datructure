#include "queue/minheap.h"

using namespace std;

int xs[] = {13, 14, 16, 19, 21, 19, 68, 65, 26, 32, 31};

int main()
{
    MinHeap<int> h(-1);
    h.input(xs, 10);
    h.pop_min();
    h.output();
    return 0;
}
