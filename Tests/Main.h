//
// Created by gpinto03 on 27-12-2022.
//

#ifndef PROJ_MAIN_H
#define PROJ_MAIN_H

#include "Airline.h"
#include "Airport.h"
#include "Flight.h"
#include "City.h"
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Main {
public:
    static unordered_set<Airline, Airline::hAirline, Airline::eqAirline> readAirlines();
    static unordered_set<Airport, Airport::hAirport, Airport::eqAirport> readAirports();
    static unordered_set<Flight, Flight::hFlight, Flight::eqFlight> readFlights() ;
    static unordered_set<City, City::hCity, City::eqCity> readCities();
    static void printAirlines(unordered_set<Airline, Airline::hAirline, Airline::eqAirline> airlines);
    static void printAirports(unordered_set<Airport, Airport::hAirport, Airport::eqAirport> airports);
    static void printFlights(unordered_set<Flight, Flight::hFlight, Flight::eqFlight> flights);
    static void printCities(unordered_set<City, City::hCity, City::eqCity> cities);
};


#endif //PROJ_MAIN_H
