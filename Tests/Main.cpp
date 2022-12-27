#include "Main.h"
#include <iostream>
#include <fstream>

using namespace std;

vector<Airline> Main::readAirlines() {
    string filename = "airlines.csv";
    Airline airline;
    string code;
    string name;
    string callsign;
    string country;
    vector<Airline> airlines;
    string dummy;

    ifstream input = ifstream(filename, ios_base::in);
    if (input.is_open()) {
        getline(input, dummy);
        while (input.good()) {
            getline(input, code, ',');
            getline(input, name, ',');
            getline(input, callsign, ',');
            getline(input, country, '\n');

            airline.setCode(code);
            airline.setName(name);
            airline.setCallsign(callsign);
            airline.setCountry(country);

            airlines.push_back(airline);
        }
    }
    else {
        cout << "ERROR: File Not Open" << '\n';
    }
    input.close();
    return airlines;
}


vector<Airport> Main::readAirports() {
    return vector<Airport>();
}

vector<Flight> Main::readFlights() {
    return vector<Flight>();
}

void printAirlines(vector<Airline> airlines) {
    for (auto &i : airlines) {
        cout << i.getCode() << ", " << i.getName() << ", " << i.getCallsign() << ", " << i.getCountry() << "\n";
    }
}

int Menu() {
    int choice;
    do {
        cout << "\n 0. Ver companhias aéreas \n 1. Ver voos \n 2. Ver aeroportos \n 3. Creditos\n 4. Exit\n\n";
        cin >> choice;
        switch (choice) {
            case 0:
            {
                vector<Airline> airlines = Main::readAirlines();
                printAirlines(airlines);
                //cout << "SATA, TAP, RYANAIR, EASYJET";
                break;
            }
            case 1:
            {
                cout << "VOOS";
                break;
            }
            case 2:
            {
                cout << "Aeroportos";
                break;
            }
            case 3:
                cout << "Done by Goncalo Pinto, Miguel Figueiredo and Miguel Santos\n";
                break;
            case 4:
                return 0;
            default:
                return 0;
        }
    } while (choice);
}

int main() {
    Menu();
}
