#include <iostream>
using namespace std;

int Menu() {
    int choice;
    do {
        cout << "\n 0. Ver companhias aéreas \n 1. Ver voos \n 2. Ver aeroportos \n 3. Creditos\n 4. Exit\n\n";
        cin >> choice;
        switch (choice) {
            case 0:
            {
                cout << "SATA, TAP, RYANAIR, EASYJET";
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
