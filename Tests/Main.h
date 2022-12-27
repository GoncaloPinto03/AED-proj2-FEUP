//
// Created by gpinto03 on 27-12-2022.
//

#ifndef PROJ_MAIN_H
#define PROJ_MAIN_H

#include "Airline.h"
#include "Airport.h"
#include "Flight.h"
#include <iostream>
#include <vector>

using namespace std;

class Main {
public:
    static vector<Airline> readAirlines();
    vector<Airport> readAirports();
    vector<Flight> readFlights();
};


#endif //PROJ_MAIN_H
