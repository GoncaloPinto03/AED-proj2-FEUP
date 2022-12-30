//
// Created by gpinto03 on 30-12-2022.
//

#include "City.h"

City::City() {
    this->name = "";
    this->country = "";
}

City::City(string name, string country) {
    this->name = name;
    this->country = country;
}

string City::getName() const {
    return name;
}

string City::getCountry() const {
    return country;
}

void City::setName() {
    this->name = name;
}

void City::setCountry() {
    this->country = country;
}

int City::hCity::operator()(const City &city) const {
    string code = city.getName()+city.getCountry();
    int hashCode = 0;
    for (int i = 0; i < code.length(); i++) {
        hashCode += code[i] * pow(31, i);
    }
    return hashCode;
}

bool City::eqCity::operator()(const City &c1, const City &c2) const {
    return c1.name == c2.getName() && c1.getCountry()==c2.getCountry();
}
