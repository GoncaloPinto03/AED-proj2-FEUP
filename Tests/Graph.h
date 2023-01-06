#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <list>
#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
#include "Airport.h"
using namespace std;

class Graph {
    Graph(){}
    Graph(const Graph&);
    Graph& operator=(const Graph&);
    struct Edge {
        int dest;   // Destination node
        int weight; // An integer weight
    };

    struct Node {
        list<Edge> adj; // The list of outgoing edges (to adjacent nodes)
        bool visited;   // As the node been visited on a search?
    };

    int n;              // Graph size (vertices are numbered from 1 to n)
    bool hasDir;        // false: undirected; true: directed
    vector<Node> nodes; // The list of nodes being represented

public:
    friend Graph createGraph();
    static Graph& getGraph(){
        static Graph instance;
        return instance;
    }

    Graph(int nodes, bool dir = false);
    void addEdge(int src, int dest, int weight = 1);
    void addNode(Airport airport);
    // Depth-First Search: example implementation
    void dfs(int v);
    void bfs(int v);
    vector<int> predecessorbfs(int partida, int chegada);
};

#endif
