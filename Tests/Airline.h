//
// Created by gpinto03 on 26-12-2022.
//
#include <iostream>
#include <string>

using namespace std;

#ifndef PROJ_AIRLINE_H
#define PROJ_AIRLINE_H


class Airline {
    string code;
    string name;
    string callsign;
    string country;
public:
    Airline(string code, string name, string callsign, string country);
    const string getCode() const;
    const string getName() const;
    const string getCallsign() const;
    const string getCountry() const;
};


#endif //PROJ_AIRLINE_H
