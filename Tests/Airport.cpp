//
// Created by gpinto03 on 26-12-2022.
//

#include "Airport.h"

Airport::Airport(string code, string name, string city, string country, float latitude, float longitude) {
    this->code = code;
    this->name = name;
    this->city = city;
    this->country = country;
    this->latitude = latitude;
    this->longitude = longitude;
}

const string Airport::getCode() const {
    return code;
}

const string Airport::getName() const {
    return name;
}

const string Airport::getCity() const {
    return city;
}

const string Airport::getCountry() const {
    return country;
}

const float Airport::getLatitude() const {
    return latitude;
}

const float Airport::getLongitude() const {
    return longitude;
}

