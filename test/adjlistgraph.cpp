#include <iostream>
#include <cassert>

#include "graph/adjlistgraph.h"

using namespace std;

char nodes[6] = {'A', 'B', 'C', 'D', 'S', 'T'};

int main()
{
    AdjListGraph<char> g;
    g.fromArray(nodes, 6);

    int v1, v2;
    float w;
    while (cin >> v1 >> v2 >> w) {
        g.add_edge(v1, v2, w);
    }

    g.print_graph();

    return 0;
}
