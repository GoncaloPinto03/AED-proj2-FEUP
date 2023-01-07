#include "Main.h"

using namespace std;

struct pair_hash {
    template <class T1, class T2>
    std::size_t operator()(const std::pair<T1, T2> &p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);

        return h1 ^ h2;
    }
};

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

    unordered_set<Airport, Airport::hAirport, Airport::eqAirport> airportsSet;
    Graph g(0, false);

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

            airportsSet.insert(airport);

            g.addNode(airport);
        }
        unordered_set<Flight, Flight::hFlight, Flight::eqFlight> flights = readFlights();
        for (auto &i : flights) {
            g.addFlight(i);
        }
    }

    else {
        cout << "ERROR: File Not Open" << '\n';
    }
    input.close();
    return airportsSet;
}

unordered_set<Flight, Flight::hFlight, Flight::eqFlight> Main::readFlights() {

    unordered_set<Flight, Flight::hFlight, Flight::eqFlight> flightsSet;

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


            flightsSet.insert(flight);
        }
    }
    else {
        cout << "ERROR: File Not Open" << '\n';
    }
    input.close();
    return flightsSet;
}
/*
unordered_map<pair<string, string>, Flight, pair_hash> Main::readFlights2() {
    unordered_map<pair<string, string>, Flight, pair_hash> flightsMap;

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

            flightsMap[{source, target}] = flight;
        }
    }
    else {
        cout << "ERROR: File Not Open" << '\n';
    }
    input.close();
    return flightsMap;
}
*/
unordered_set<City, City::hCity, City::eqCity> Main::readCities() {

    unordered_set<City, City::hCity, City::eqCity> citiesSet;

    for (auto &i : readAirports()) {
        City city(i.getCity(), i.getCountry());
        citiesSet.insert(city);
    }
    return citiesSet;
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

void printFlights2(unordered_map<pair<string, string>, Flight, pair_hash> flights){
    for (auto &i : flights) {
        cout << i.second.getSource() << ", " << i.second.getTarget() << ", " << i.second.getAirline() << "\n";
    }
}

void Main::printCities(unordered_set<City, City::hCity, City::eqCity> cities) {
    for (auto &i : cities) {
        cout << i.getName() << ", " << i.getCountry() << "\n";
    }
}



int Menu() {
    Graph g(0, false);
    //unordered_map<pair<string, string>, Flight, pair_hash> flights = readFlights2();
    unordered_set<Flight , Flight::hFlight  , Flight::eqFlight  > flights = Main::readFlights();
    unordered_set<Airport, Airport::hAirport, Airport::eqAirport> airports = Main::readAirports();
    unordered_set<Airline, Airline::hAirline, Airline::eqAirline> airlines = Main::readAirlines();
    unordered_set<City, City::hCity, City::eqCity> cities = Main::readCities();

    int choice;
    do {
        cout << "\n 0. Ver companhias aereas \n 1. Ver voos(Aviso:demora tempo aprox 2min) \n 2. Ver aeroportos \n 3. Ver cidades \n 4. Mostrar percurso mais Rapido entre 2 Locais \n 5. Informacoes de aeroporto \n 6. Creditos\n 7. Exit\n\n";
        cin >> choice;
        switch (choice) {
            case 0:
            {
                Main::printAirlines(airlines);
                break;
            }
            case 1:
            {
                Main::printFlights(flights);
                break;
            }
            case 2:
            {
                Main::printAirports(airports);
                break;
            }
            case 3:
            {
                Main::printCities(cities);
                break;
            }
            case 4:
            {
                string partida, chegada;
                cout << "Código do aeroporto de partida: ";
                cin >> partida;
                cout << "\nCódigo do aeroporto de chegada: ";
                cin >> chegada;

                int src = g.findAirport(partida);
                int dest = g.findAirport(chegada);
                int min = g.minFlights(src, dest);
                cout << "O número mínimo de voos entre os aeroportos " << partida << "e " << chegada << " é de " << min << "." << endl;
                break;
            }
            case 5:
            {
                string aeroporto;
                cout<<"De que aeroporto pretende obter as informaçoes? ";
                cin>> aeroporto;
            }
            case 6:
                cout << "Done by Goncalo Pinto, Miguel Figueiredo and Miguel Santos\n";
                break;
            case 7:
                return 0;
            default:
                return 0;
        }
    } while (choice);
}

int main() {
    Menu();
}
