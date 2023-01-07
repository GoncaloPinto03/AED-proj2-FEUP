//
// Created by gpinto03 on 27-12-2022.
//

#ifndef PROJ_MAIN_H
#define PROJ_MAIN_H

#include "Airline.h"
#include "Airport.h"
#include "Flight.h"
#include "City.h"
#include "Graph.h"
#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
#include <fstream>


using namespace std;

class Main {
    Graph g;
public:
    struct pair_hash {
        template <class T1, class T2>
        std::size_t operator()(const std::pair<T1, T2> &p) const {
            auto h1 = std::hash<T1>{}(p.first);
            auto h2 = std::hash<T2>{}(p.second);

            return h1 ^ h2;
        }
    };
    static unordered_set<Airline, Airline::hAirline, Airline::eqAirline> readAirlines();
    static unordered_set<Airport, Airport::hAirport, Airport::eqAirport> readAirports();
    static unordered_set<Flight, Flight::hFlight, Flight::eqFlight> readFlights() ;
    static unordered_set<City, City::hCity, City::eqCity> readCities();
    static void printAirlines(unordered_set<Airline, Airline::hAirline, Airline::eqAirline> airlines);
    static void printAirports(unordered_set<Airport, Airport::hAirport, Airport::eqAirport> airports);
    static void printFlights(unordered_set<Flight, Flight::hFlight, Flight::eqFlight> flights);
    static void printCities(unordered_set<City, City::hCity, City::eqCity> cities);
    static unordered_map<pair<string, string>, Flight> readFlights2();
};


#endif //PROJ_MAIN_H
