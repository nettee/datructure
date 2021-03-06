#include "network.h"
#include "stack.h"

#include <iostream>
#include <algorithm>

using namespace std;

/* to sort circles in decreasing order */
bool circle_compare(const Circle& c1, const Circle& c2) {
    if (c1.size() > c2.size()) {
        return true;
    } else if (c1.size() < c2.size()) {
        return false;
    } else {
        // compare first element of both sets
        return *(c1.begin()) > *(c2.begin());
    }
}

void Network::build_circle() {
    /* divide a circle: according to bi-connected component in a graph
     * using Tarjan algorithm to find out articulation vertices
     */
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

    // sort circles to decreasing order of length
    sort(circles.begin(), circles.end(), circle_compare);
}

void Network::print_circle(int idx) {
    cout << "Circle[" << idx << "]:";
    for (Circle::const_iterator it = circles[idx].begin();
            it != circles[idx].end(); ++it) {
        cout << " " << users[*it].uid;
    }
    cout << endl;
}

void Network::print_all_circle() {
    for (int i = 0; i < circles.size(); i++) {
        print_circle(i);
    }
}

void Network::print_top_circle(int n) {
    for (int i = 0; i < n && i < circles.size(); i++) {
        print_circle(i);
    }
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
    for (Friend *f = users[u].friends; f != NULL; f = f->next) {
        int v = f->dest;

        if (!visited[v]) {
            // vertex v is child of u, and (u,v) is an edge in DFS tree
            parent[v] = u;
            num_child++;

            stack.push(Rel(u, v));  // no care about closeness in relationship
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
                Rel r;
                Circle c;
                do {
                    stack.pop(r);
                    c.insert(r.src);
                    c.insert(r.dest);
                } while (!((r.src == u && r.dest == v) || (r.src == v && r.dest == u)));
                circles.push_back(c);
            }
        } else {
            // vertex v has been visited, edge (u,v) is not in DFS tree
            if (v != parent[u]) {
                low[u] = min(low[u], dfn[v]);
            }
        }
    }
    if (parent[u] == -1) {
        Rel r;
        Circle c;
        do {
            stack.pop(r);
            c.insert(r.src);
            c.insert(r.dest);
        } while (!stack.empty());
        circles.push_back(c);
    }
}
