//
// Created by gpinto03 on 26-12-2022.
//

#include "Flight.h"

Flight::Flight(string source, string target, string airline) {
    this->source = source;
    this->target = target;
    this->airline = airline;
}

const string Flight::getSource() const {
    return source;
}

const string Flight::getTarget() const {
    return target;
}

const string Flight::getAirline() const {
    return airline;
}
