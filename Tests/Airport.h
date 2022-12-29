//
// Created by gpinto03 on 26-12-2022.
//
#include <iostream>
#include <string>
#include <cmath>

using namespace std;

#ifndef PROJ_AIRPORT_H
#define PROJ_AIRPORT_H


class Airport {
    string code;
    string name;
    string city;
    string country;
    string latitude;
    string longitude;
public:
    Airport();
    Airport(string code, string name, string city, string country, string latitude, string longitude);
    string getCode() const;
    string getName() const;
    string getCity() const;
    string getCountry() const;
    string getLatitude() const;
    string getLongitude() const;
    void setCode(string code2);
    void setName(string name2);
    void setCity(string city2);
    void setCountry(string country2);
    void setLatitude(string latitude2);
    void setLongitude(string longitude2);

    struct hAirport {
        int operator() (const Airport& airport) const;
    };
    struct eqAirport {
        bool operator() (const Airport& a1, const Airport& a2) const;
    };
};



#endif //PROJ_AIRPORT_H
