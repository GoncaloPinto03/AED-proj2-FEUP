//
// Created by gpinto03 on 26-12-2022.
//

#include "Airline.h"

Airline::Airline(string code, string name, string callsign, string country) {
    this->code = code;
    this->name = name;
    this->callsign = callsign;
    this->country = country;
}

const string Airline::getCode() const {
    return code;
}

const string Airline::getName() const {
    return name;
}

const string Airline::getCallsign() const {
    return callsign;
}

const string Airline::getCountry() const {
    return country;
}


