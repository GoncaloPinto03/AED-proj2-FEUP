//
// Created by gpinto03 on 26-12-2022.
//

#include "Airport.h"

Airport::Airport() {
    this->code = "";
    this->name = "";
    this->city = "";
    this->country = "";
    this->latitude = 0.0;
    this->longitude = 0.0;
}

Airport::Airport(string code, string name, string city, string country, float latitude, float longitude) {
    this->code = code;
    this->name = name;
    this->city = city;
    this->country = country;
    this->latitude = latitude;
    this->longitude = longitude;
}

string Airport::getCode() const {
    return code;
}

string Airport::getName() const {
    return name;
}

string Airport::getCity() const {
    return city;
}

string Airport::getCountry() const {
    return country;
}

float Airport::getLatitude() const {
    return latitude;
}

float Airport::getLongitude() const {
    return longitude;
}

void Airport::setCode(string code2) {
    this->code = code2;
}

void Airport::setName(string name2) {
    this->name = name2;
}

void Airport::setCity(string city2) {
    this->city = city2;
}

void Airport::setCountry(string country2) {
    this->country = country2;
}

void Airport::setLatitude(float latitude2) {
    this->latitude = latitude2;
}

void Airport::setLongitude(float longitude2) {
    this->longitude = longitude2;
}

