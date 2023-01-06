#include "Graph.h"

// Constructor: nr nodes and direction (default: undirected)
Graph::Graph(int num, bool dir) : n(num), hasDir(dir), nodes(num+1) {
}

// Add edge from source to destination with a certain weight
void Graph::addEdge(int src, int dest, int weight) {
    if (src<1 || src>n || dest<1 || dest>n) return;
    nodes[src].adj.push_back({dest, weight});
    if (!hasDir) nodes[dest].adj.push_back({src, weight});
}

void Graph::addNode(Airport airport) {
    n++;
    Node node;
    node.airport = airport;
    nodes.push_back(node);
}

void Graph::addFlight(const Flight &flight) {
    // Find the source and target nodes using the airport codes
    int src = -1, dest = -1;
    for (int i = 1; i <= n; i++) {
        if (nodes[i].airport.getCode() == flight.getSource()) {
            src = i;
        }
        if (nodes[i].airport.getCode() == flight.getTarget()) {
            dest = i;
        }
        if (src != -1 && dest != -1) break;
    }
    // If both nodes were found, add an edge between them
    if (src != -1 && dest != -1) {
        addEdge(src, dest, 1);
    }
}


// Depth-First Search: example implementation
void Graph::dfs(int v) {
    // show node order
    // cout << v << " ";
    nodes[v].visited = true;
    for (auto e : nodes[v].adj) {
        int w = e.dest;
        if (!nodes[w].visited)
            dfs(w);
    }
}

// Breadth-First Search: example implementation
void Graph::bfs(int v) {
    for (int i=1; i<=n; i++) nodes[i].visited = false;
    queue<int> q; // queue of unvisited nodes
    q.push(v);
    nodes[v].visited = true;
    while (!q.empty()) { // while there are still unvisited nodes
        int u = q.front(); q.pop();
        for (auto e : nodes[u].adj) {
            int w = e.dest;
            if (!nodes[w].visited) {
                q.push(w);
                nodes[w].visited = true;
            }
        }
    }
}


