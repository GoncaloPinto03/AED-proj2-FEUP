//
// Created by gpinto03 on 26-12-2022.
//

#include "Airport.h"

Airport::Airport() {
    this->code = "";
    this->name = "";
    this->city = "";
    this->country = "";
    this->latitude = "";
    this->longitude = "";
}

Airport::Airport(string code, string name, string city, string country, string latitude, string longitude) {
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

string Airport::getLatitude() const {
    return latitude;
}

string Airport::getLongitude() const {
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

void Airport::setLatitude(string latitude2) {
    this->latitude = latitude2;
}

void Airport::setLongitude(string longitude2) {
    this->longitude = longitude2;
}

int Airport::hAirport::operator()(const Airport &airport) const {
    string code = airport.getCode();
    int hashCode = 0;
    for (int i = 0; i < code.length(); i++) {
        hashCode += code[i] * pow(31, i);
    }
    return hashCode;
}

bool Airport::eqAirport::operator()(const Airport &a1, const Airport &a2) const {
    return a1.getCode()==a2.getCode();
}
