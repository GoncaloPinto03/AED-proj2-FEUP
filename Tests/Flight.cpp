//
// Created by gpinto03 on 26-12-2022.
//

#include "Flight.h"

Flight::Flight() {
    this->source = "";
    this->target = "";
    this->airline = "";
}

Flight::Flight(string source, string target, string airline) {
    this->source = source;
    this->target = target;
    this->airline = airline;
}

string Flight::getSource() const {
    return source;
}

string Flight::getTarget() const {
    return target;
}

string Flight::getAirline() const {
    return airline;
}

void Flight::setSource(string source2) {
    this->source = source2;
}

void Flight::setTarget(string target2) {
    this->target = target2;
}

void Flight::setAirline(string airline2) {
    this->airline = airline2;
}

int Flight::hFlight::operator()(const Flight &flight) const {
    string code = flight.getSource()+flight.getTarget()+flight.getAirline();
    int hashCode = 0;
    for (int i = 0; i < code.length(); i++) {
        hashCode += code[i] * pow(31, i);
    }
    return hashCode;
}

bool Flight::eqFlight::operator()(const Flight &f1, const Flight &f2) const {
    return f1.getAirline()==f2.getAirline() && f1.getSource()==f2.getSource() && f1.getTarget()==f2.getTarget();
}
