#include "Graph.h"

// Constructor: nr nodes and direction (default: undirected)
Graph::Graph(int num, bool dir) : n(num), hasDir(dir), nodes(num+1) {
}

// Add edge from source to destination with a certain weight
void Graph::addEdge(int src, int dest, int weight, string airline) {
    if (src<1 || src>n || dest<1 || dest>n) return;
    nodes[src].adj.push_back({dest, weight, airline});
    if (!hasDir) nodes[dest].adj.push_back({src, weight, airline});
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
        addEdge(src, dest, 1, flight.getAirline());
    }
}

void Graph::fillgraph(unordered_set<Airport, Airport::hAirport, Airport::eqAirport> airports, unordered_set<Flight, Flight::hFlight, Flight::eqFlight> flights){
    while(!airports.empty()){
        auto it=airports.begin();
        addNode(*it);
        it++;
    }
    while(!flights.empty()){
        auto it=flights.begin();
        addFlight(*it);
        it++;
    }
}

void Graph::addNode(Airport airport) {
    n++;
    Node node;
    node.airport = airport;
    nodes.push_back(node);
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
void Graph::bfsdist(int v){
    for (int i=1; i<=n; i++) {
        nodes[i].visited = false;
        nodes[i].distance=0;
    }
    queue<int> q; // queue of unvisited nodes
    q.push(v);
    nodes[v].visited = true;
    nodes[v].distance=0;
    while (!q.empty()) { // while there are still unvisited nodes
        int u = q.front(); q.pop();
        for (auto e : nodes[u].adj) {
            int w = e.dest;
            if (!nodes[w].visited) {
                q.push(w);
                nodes[w].visited = true;
                nodes[w].distance=nodes[u].distance+1;
            }
        }
    }
}

int Graph::distance(string astr, string bstr) {
    int a=0,b=0;
    for(int i=1;i<=n;i++){
        if(nodes[i].airport.getCode()==astr)a=i;
        if(nodes[i].airport.getCode()==bstr)b=i;
    }
    bfsdist(a);
    if(!nodes[b].visited)return -1;
    return nodes[b].distance;

}


int Graph::minFlights(int source, int destination) {
    // Initialize a queue to store nodes to visit, and a vector to store the number of flights taken to reach each node
    queue<int> q;
    vector<int> numFlights(n+1, 0);

    // Mark all nodes as unvisited
    for (int i = 1; i <= n; i++) {
        nodes[i].visited = false;
    }

    // Add the source node to the queue and mark it as visited
    q.push(source);
    nodes[source].visited = true;

    // While there are still nodes to visit
    while (!q.empty()) {
        // Get the next node in the queue
        int u = q.front();
        q.pop();

        // For each of its neighbors
        for (auto e : nodes[u].adj) {
            int w = e.dest;
            if (!nodes[w].visited) {
                // If the neighbor is the destination, return the number of flights taken to reach it
                if (w == destination) {
                    return numFlights[u] + 1;
                }
                // Otherwise, add the neighbor to the queue and mark it as visited
                q.push(w);
                nodes[w].visited = true;
                // Store the number of flights taken to reach this neighbor
                numFlights[w] = numFlights[u] + 1;

            }
        }
    }
    // If the destination was not reached, return -1 to indicate that it is not reachable from the source
    return -1;
}

int Graph::findAirport(string code) {
    for (int i = 1; i <= n; i++) {
        if (nodes[i].airport.getCode() == code)
            return i;
    }
    return -1;
}

