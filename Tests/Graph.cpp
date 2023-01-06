#include "Graph.h"


Graph::Graph(int num, bool dir) : n(num), hasDir(dir), nodes(num+1) {
}

void Graph::addEdge(int src, int dest, int weight) {
    if (src<1 || src>n || dest<1 || dest>n) return;
    nodes[src].adj.push_back({dest, weight});
    if (!hasDir) nodes[dest].adj.push_back({src, weight});
}
void Graph::addNode(Airport airport) {
    // Create a new node in the graph
    Node node;
    node.visited = false;

    // Add the node to the list of nodes in the graph
    this->nodes.push_back(node);
}

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
void Graph::bfs(int v) {
    for (int i=1; i<=n; i++) nodes[i].visited = false;
    queue<int> q; // queue of unvisited nodes
    q.push(v);
    nodes[v].visited = true;
    while (!q.empty()) { // while there are still unvisited nodes
        int u = q.front(); q.pop();
        // show node order
        //cout << u << " ";
        for (auto e : nodes[u].adj) {
            int w = e.dest;
            if (!nodes[w].visited) {
                q.push(w);
                nodes[w].visited = true;
            }
        }
    }
}

vector<int> Graph::predecessorbfs(int partida, int chegada) {
    queue<int> hold;
    int distances[n];
    for (int i = 0; i < n; i++) {
        distances[i] = INT_MAX;
    }
    distances[partida] = 0;
    int predecessors[n];
    for (int i = 0; i < n; i++) {
        predecessors[i] = -1;
    }
    predecessors[partida] = partida;
    hold.push(partida);
    nodes[partida].visited = true;
    while (!hold.empty()) {
        int v = hold.front();
        hold.pop();
        for (Edge e : nodes[v].adj) {
            int dest = e.dest;
            if (nodes[dest].visited) {
                distances[dest] = distances[v] + e.weight;
                hold.push(dest);
                nodes[dest].visited = true;
                if (dest == chegada) {
                    vector<int> path;
                    int node = chegada;
                    while (node != partida) {
                        path.push_back(node);
                        node = predecessors[node];
                    }
                    path.push_back(partida);
                    reverse(path.begin(), path.end());
                    return path;
                }
            }
        }
    }
    return {};
}