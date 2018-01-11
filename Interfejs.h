#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <sstream>
#include <regex>
#include <cctype>
#include <stack>
#include "Macierz.h"
#include "ONP.h"


class Interfejs {
public:
    Interfejs();
    ~Interfejs();
    void CommandLineInterface();
private:
    bool error;
    std::stack<Macierz> stosMacierzy;
    std::string wejscie;
    std::vector<std::string> listaStringow;
    std::map<std::string, Macierz> zmienne;
    void dzielWyrazenie(const std::string wejscie);
    void czyscStos();
    ONP odwrotnaNotacjaPolska;
    void czyZmiennaIstnieje(const std::string zmienna);
    void liczbaNaMacierz(const std::string liczba);
    void liczbaNaMacierz(const double liczba);

    ///****Sprawdzanie Wyrazen Regularnych
    bool sprawdzZmienna(const std::string nazwaZmiennej);
    bool sprawdzMacierz(const std::string wzorMacierzy);
    bool sprawdzLiczbe(const std::string liczba);


};

