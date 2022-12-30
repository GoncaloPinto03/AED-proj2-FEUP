#include "Main.h"
#include <iostream>
#include <fstream>
#include <unordered_set>
#include "Airport.h"
#include "Airline.h"

using namespace std;

unordered_set<Airline, Airline::hAirline, Airline::eqAirline> Main::readAirlines() {

    unordered_set<Airline, Airline::hAirline, Airline::eqAirline> airlinesSet;

    string filename = "../dataset/airlines.csv";
    Airline airline;
    string code;
    string name;
    string callsign;
    string country;
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

            airlinesSet.insert(airline);
        }
    }
    else {
        cout << "ERROR: File Not Open" << '\n';
    }
    input.close();
    return airlinesSet;
}


unordered_set<Airport, Airport::hAirport, Airport::eqAirport> Main::readAirports() {
    unordered_set<Airport, Airport::hAirport, Airport::eqAirport> airportSet;

    string filename = "../dataset/airports.csv";
    Airport airport;
    string code;
    string name;
    string city;
    string country;
    string latitude;
    string longitude;
    string dummy;

    ifstream input = ifstream(filename, ios_base::in);
    if (input.is_open()) {
        getline(input, dummy);

        while (input.good()) {
            getline(input, code, ',');
            getline(input, name, ',');
            getline(input, city, ',');
            getline(input, country, ',');
            getline(input, latitude, ',');
            getline(input, longitude, '\n');

            airport.setCode(code);
            airport.setName(name);
            airport.setCity(city);
            airport.setCountry(country);
            airport.setLatitude(latitude);
            airport.setLongitude(longitude);

            airportSet.insert(airport);
        }
    }
    else {
        cout << "ERROR: File Not Open" << '\n';
    }
    input.close();
    return airportSet;
}

unordered_set<Flight, Flight::hFlight, Flight::eqFlight> Main::readFlights() {
    unordered_set<Flight, Flight::hFlight, Flight::eqFlight> flightSet;
    string filename = "../dataset/flights.csv";
    Flight flight;
    string source;
    string target;
    string airline;
    string dummy;

    ifstream input = ifstream(filename, ios_base::in);
    if (input.is_open()) {
        getline(input, dummy);
        while (input.good()) {
            getline(input, source, ',');
            getline(input, target, ',');
            getline(input, airline, '\n');


            flight.setSource(source);
            flight.setAirline(airline);
            flight.setTarget(target);


            flightSet.insert(flight);
        }
    }
    else {
        cout << "ERROR: File Not Open" << '\n';
    }
    input.close();
    return flightSet;
}


void Main::printAirlines(unordered_set<Airline, Airline::hAirline, Airline::eqAirline> airlines) {
    for (auto &i : airlines) {
        cout << i.getCode() << ", " << i.getName() << ", " << i.getCallsign() << ", " << i.getCountry() << "\n";
    }
}

void Main::printAirports(unordered_set<Airport, Airport::hAirport, Airport::eqAirport> airports) {
    for (auto &i : airports) {
        cout << i.getCode() << ", " << i.getName() << ", " << i.getCity() << ", " << i.getCountry() << ", " << i.getLatitude() << ", " << i.getLongitude() << "\n";
    }
}
void Main::printFlights(unordered_set<Flight , Flight::hFlight  , Flight::eqFlight  > flights){
    for (auto &i : flights) {
        cout << i.getSource() << ", " << i.getTarget() << ", " << i.getAirline() << "\n";
    }
}

int Menu() {
    int choice;
    do {
        cout << "\n 0. Ver companhias aereas \n 1. Ver voos(Aviso:demora tempo aprox 2min) \n 2. Ver aeroportos \n 3. Mostrar percurso mais Rapido entre 2 Locais \n 4. Informacoes de aeroporto \n 5. Creditos\n 6. Exit\n\n";
        cin >> choice;
        switch (choice) {
            case 0:
            {
                unordered_set<Airline, Airline::hAirline, Airline::eqAirline> airlines = Main::readAirlines();
                Main::printAirlines(airlines);
                break;
            }
            case 1:
            {
                unordered_set<Flight, Flight::hFlight, Flight::eqFlight> flights= Main::readFlights();
                Main::printFlights(flights);
                break;
            }
            case 2:
            {
                cout << "Aeroportos";
                unordered_set<Airport, Airport::hAirport, Airport::eqAirport> airports = Main::readAirports();
                Main::printAirports(airports);
                break;
            }
            case 3:
            {
                string partida, chegada;
                cout << "Local de Partida :";
                cin >> partida;
                cout << "\nLocal de Chegada";
                cin >> chegada;
                break;
            }
            case 4:
            {
                string aeroporto;
                cout<<"De que aeroporto pretende obter as informaçoes?";
                cin>> aeroporto;
            }
            case 5:
                cout << "Done by Goncalo Pinto, Miguel Figueiredo and Miguel Santos\n";
                break;
            case 6:
                return 0;
            default:
                return 0;
        }
    } while (choice);
}

int main() {
    Menu();
}
