#ifndef _GRAPH_H_
#define _GRAPH_H_

#include <list>
#include <vector>
#include <queue>
#include <iostream>
#include "Airport.h"
#include "Flight.h"
#include "Airline.h"
#include <unordered_set>

using namespace std;

class Graph {
    struct Edge {
        int dest;   // Destination node
        int weight=1;     // An integer weight
        string airline;
    };

    struct Node {
        Airport airport;
        list<Edge> adj; // The list of outgoing edges (to adjacent nodes)
        bool visited;
        int distance;// As the node been visited on a search?s
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
    void fillgraph(unordered_set<Airport, Airport::hAirport, Airport::eqAirport> airports, unordered_set<Flight, Flight::hFlight, Flight::eqFlight> flights);
    // Depth-First Search: example implementation
    void dfs(int v);
    // Breadth-First Search: example implementation
    void bfs(int v);
    void bfsdist(int v);

    int distance(string astr,string bstring);
    int minFlights(int source, int destination);
    int findAirport(string code);
};

#endif



