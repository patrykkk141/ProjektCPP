#include <iostream>
#include "Interfejs.h"

using namespace std;


int main() {

    cout<<"***KALKULATOR MACIERZOWY***"
            "\nOperatory: "
            "\n+ - Dodawanie (liczba lub macierz)"
            "\n- - Odejmowanie (liczba lub macierz) "
            "\n* - Mnozenie (liczba lub macierz) "
            "\n! - Macierz transponowana (operator lewostronny)"
            "\n~ - Wyznczanik macierzy (operator lewostronny)"
            "\n@ - Macierz dopelnien algebraicznych (operator lewostronny) "
            "\n^ - Macierz odwrotna (operator lewostronny)";

    Interfejs intf;
    intf.CommandLineInterface();

    return 0;
}
