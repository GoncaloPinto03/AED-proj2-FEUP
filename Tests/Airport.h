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
    Airport();
    Airport(string code, string name, string city, string country, float latitude, float longitude);
    string getCode() const;
    string getName() const;
    string getCity() const;
    string getCountry() const;
    float getLatitude() const;
    float getLongitude() const;
    void setCode(string code2);
    void setName(string name2);
    void setCity(string city2);
    void setCountry(string country2);
    void setLatitude(float latitude2);
    void setLongitude(float longitude2);
};



#endif //PROJ_AIRPORT_H
