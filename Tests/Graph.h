#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <list>
#include <vector>
#include <queue>
#include <iostream>
#include "Airport.h"
#include "Flight.h"
#include "Airline.h"

using namespace std;

class Graph {
    struct Edge {
        int dest;   // Destination node
        int weight;     // An integer weight
        string airline;
    };

    struct Node {
        Airport airport;
        list<Edge> adj; // The list of outgoing edges (to adjacent nodes)
        bool visited;   // As the node been visited on a search?s
    };

    int n;              // Graph size (vertices are numbered from 1 to n)
    bool hasDir;        // false: undirected; true: directed
    vector<Node> nodes; // The list of nodes being represented

public:
    // Constructor: nr nodes and direction (default: undirected)
    Graph(int nodes, bool dir = false);

    // Add edge from source to destination with a certain weight
    void addEdge(int src, int dest, int weight = 1, string airline = "");
    void addNode(Airport airport);
    void addFlight(const Flight &flight);

    // Depth-First Search: example implementation
    void dfs(int v);
    // Breadth-First Search: example implementation
    void bfs(int v);

    int minFlights(int source, int destination);

    int findAirport(string code);
};

#endif



