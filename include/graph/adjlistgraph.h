#ifndef __ADJ_LIST_GRAPH_H__
#define __ADJ_LIST_GRAPH_H__

#include "list/linkedlist.h"

#include <iostream>
#include <cassert>

typedef float W;  // weight of edge

struct Edge {
    int dest;
    W weight;
    
    Edge() {
        dest = -1;  // invalid dest
        weight = float();
    }

    Edge(int num, W w) {
        dest = num;
        weight = w;
    }

    bool operator==(Edge &rhs) {
        return this->dest == rhs.dest;
    }

    bool operator!=(Edge &rhs) {
        return this->dest != rhs.dest;
    }
};

template <typename VE>
struct Vertex {
    VE element;
    LinkedList<Edge> *adjList;

    Vertex(VE e) {
        element = e;
        adjList = new LinkedList<Edge>;
    }

    ~Vertex() {
        delete adjList;
    }
};

template <typename VE>
class AdjListGraph {
public:
    AdjListGraph() {
        n_vertex = 0;
        vtable = NULL;
    }

    ~AdjListGraph() {
        clear();
    }

    void clear() {
        if (vtable) {
            delete[] vtable;
            vtable == NULL;
        }
    }

    int vertex() {
        return n_vertex;
    }

    void add_edge(int v1, int v2, W weight) {
        LinkedList<Edge> *adj;
        adj = vtable[v1]->adjList;
        Edge e(v2, weight);
        adj->addLast(e);
    }

    void fromArray(VE *elements, int len) {
        vtable = new Vertex<VE> *[len];
        for (int i = 0; i < len; i++) {
            vtable[i] = new Vertex<VE>(elements[i]);
        }
        n_vertex = len;
    }

    void print_vertex() {
        for (int i = 0; i < n_vertex; i++) {
            std::cout << i << ": " << vtable[i]->element << std::endl;
        }
    }

    void print_graph() {
        Edge *edges;
        for (int i = 0; i < n_vertex; i++) {
            std::cout << i << ": " << vtable[i]->element;
            LinkedList<Edge> *adj = vtable[i]->adjList;
            int n_edge = adj->size();
            edges = new Edge[n_edge];
            adj->toArray(edges);
            for (int j = 0; j < n_edge; j++) {
                std::cout << " ->";
                std::cout << vtable[edges[j].dest]->element;
                std::cout << " " << edges[j].weight;
            }
            std::cout << std::endl;
        }
    }


private:
    Vertex<VE> **vtable;
    int n_vertex;
};

#endif
