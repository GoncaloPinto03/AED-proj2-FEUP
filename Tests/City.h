//
// Created by gpinto03 on 30-12-2022.
//

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

#ifndef PROJ_CITY_H
#define PROJ_CITY_H


class City {
    string name;
    string country;
public:
    City();

    City(string name, string country);

    string getName() const;

    string getCountry() const;

    void setName();

    void setCountry();

    struct hCity {
        int operator()(const City &city) const;
    };

    struct eqCity {
        bool operator()(const City &c1, const City &c2) const;
    };
};

#endif //PROJ_CITY_H
