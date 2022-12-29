//
// Created by gpinto03 on 26-12-2022.
//

#include "Airline.h"

Airline::Airline() {
    this->code = "";
    this->name = "";
    this->callsign = "";
    this->country = "";
}

Airline::Airline(string code, string name, string callsign, string country) {
    this->code = code;
    this->name = name;
    this->callsign = callsign;
    this->country = country;
}

string Airline::getCode() const {
    return code;
}

string Airline::getName() const {
    return name;
}

string Airline::getCallsign() const {
    return callsign;
}

string Airline::getCountry() const {
    return country;
}

void Airline::setCode(string code2) {
    this->code = code2;
}

void Airline::setName(string name2) {
    this->name = name2;
}

void Airline::setCallsign(string callsign2) {
    this->callsign = callsign2;
}

void Airline::setCountry(string country2) {
    this->country = country2;
}

int Airline::hAirline::operator()(const Airline &airline) const {
    string code = airline.getCode();
    int hashCode = 0;
    for (int i = 0; i < code.length(); i++) {
        hashCode += code[i] * pow(31, i);
    }
    return hashCode;
}

bool Airline::eqAirline::operator()(const Airline &a1, const Airline &a2) const {
    return a1.getCode()==a1.getCode();

}
