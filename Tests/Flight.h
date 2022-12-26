//
// Created by gpinto03 on 26-12-2022.
//

#include <iostream>
#include <string>

using namespace std;

#ifndef PROJ_FLIGHT_H
#define PROJ_FLIGHT_H


class Flight {
    string source;
    string target;
    string airline;
public:
    Flight(string source, string target, string airline);
    const string getSource() const;
    const string getTarget() const;
    const string getAirline() const;
};


#endif //PROJ_FLIGHT_H
