#include "network.h"
#include "stack.h"

#include <iostream>

using namespace std;

void Network::circle() {
    int n = num_user();
    visited = new bool[n];
    dfn = new int[n];  // DFS Number
    low = new int[n];
    parent = new int[n];

    for (int i = 0; i < n; i++) {
        visited[i] = false;
        dfn[i] = -1;
        low[i] = -1;
        parent[i] = -1;
    }

    Stack<Rel> stack;

    dfs(0, stack);
}

/* depth-first search */
void Network::dfs(int u, Stack<Rel>& stack) {
    static int counter = 0; // traversing order of DFS
    int num_child = 0;  // number of children of vertex u

    ++counter;
    visited[u] = true;

    dfn[u] = counter;
    low[u] = counter;

    // for each v adjancent to u
    for (List::const_iterator it = users[u].friends.begin();
            it != users[u].friends.end(); ++it) {
        int v = it->dest;

        if (!visited[v]) {
            // vertex v is child of u, and (u,v) is an edge in DFS tree
            parent[v] = u;
            num_child++;

            stack.push(Rel(u, v));
            dfs(v, stack);  // recursively do DFS on vertex v

            low[u] = min(low[u], low[v]);

            // case 1:
            // u is root of DFS tree, and has more than one subtrees,
            // then u is articulation vertex
            if ((parent[u] == -1 && num_child > 1)

            // case 2: u is not root,
            // if u's child v cannot reach vertex above u
            // unless through u, then u is articulation vertex
                    || (parent[u] >= 0 && low[v] >= dfn[u])) {
                users[u].is_arti = true;
                cout << "Circle:";
                Rel r;
                do {
                    stack.pop(r);
                    cout << " (" << users[r.src].uid << ", " << users[r.dest].uid << ")";
                } while (!((r.src == u && r.dest == v) || (r.src == v && r.dest == u)));
                cout << endl;
            }
        } else {
            // vertex v has been visited, edge (u,v) is not in DFS tree
            if (v != parent[u]) {
                stack.push(Rel(u, v));
                low[u] = min(low[u], dfn[v]);
            }
        }
    }
    if (parent[u] == -1) {
        cout << "Circle:";
        Rel r;
        do {
            stack.pop(r);
            cout << " (" << users[r.src].uid << ", " << users[r.dest].uid << ")";
        } while (!stack.empty());
        cout << endl;
    }
}


        




