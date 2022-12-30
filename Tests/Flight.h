//
// Created by gpinto03 on 26-12-2022.
//

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

#ifndef PROJ_FLIGHT_H
#define PROJ_FLIGHT_H


class Flight {
    string source;
    string target;
    string airline;
public:
    Flight();
    Flight(string source, string target, string airline);
    string getSource() const;
    string getTarget() const;
    string getAirline() const;
    void setSource(string source2);
    void setTarget(string target2);
    void setAirline(string airline2);

    struct hFlight {
        int operator() (const Flight& flight) const;
    };
    struct eqFlight {
        bool operator() (const Flight& f1, const Flight& f2) const;
    };
};


#endif //PROJ_FLIGHT_H
