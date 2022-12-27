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
    Airline();
    Airline(string code, string name, string callsign, string country);
    string getCode() const;
    string getName() const;
    string getCallsign() const;
    string getCountry() const;
    void setCode(string code2);
    void setName(string name2);
    void setCallsign(string callsign2);
    void setCountry(string country2);
};



#endif //PROJ_AIRLINE_H
