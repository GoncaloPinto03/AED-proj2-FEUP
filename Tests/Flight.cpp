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


