#include <iostream>

using namespace std;

void init_graph();
void delete_graph();

void main_loop();

int main()
{
    init_graph();
    
    main_loop();

    delete_graph();

    return 0;
}
