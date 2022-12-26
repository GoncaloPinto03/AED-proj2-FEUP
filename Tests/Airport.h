//
// Created by gpinto03 on 26-12-2022.
//
#include <iostream>
#include <string>

using namespace std;

#ifndef PROJ_AIRPORT_H
#define PROJ_AIRPORT_H


class Airport {
    string code;
    string name;
    string city;
    string country;
    float latitude;
    float longitude;
public:
    Airport(string code, string name, string city, string country, float latitude, float longitude);
    const string getCode() const;
    const string getName() const;
    const string getCity() const;
    const string getCountry() const;
    const float getLatitude() const;
    const float getLongitude() const;
};



#endif //PROJ_AIRPORT_H
