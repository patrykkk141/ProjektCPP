#include "Interfejs.h"

Interfejs::Interfejs() {
    wejscie = "";
}

Interfejs::~Interfejs() {

}

void Interfejs::CommandLineInterface() {
    do {
        error=false;
        czyscStos();
        std::cin.clear();
        listaStringow.clear();
        getline(std::cin, wejscie);
        size_t szukanaZmienna = wejscie.find("=");

        if (szukanaZmienna == std::string::npos) {
            Macierz wynik;
            std::string wyrazenieWOnp = odwrotnaNotacjaPolska.zamianaNaONP(wejscie);
            std::string tmp;
            std::stringstream bufor(wyrazenieWOnp);
            while (getline(bufor, tmp, ' ')) {
                if (sprawdzLiczbe(tmp)) {
                    double wartosc=0;
                    try {
                        wartosc = std::stod(tmp);
                    } catch (std::invalid_argument) {
                        std::cout << "\nBlad podczas parsowania";
                    }
                    Macierz liczba(1, 1);
                    liczba.ustaw(wartosc);
                    stosMacierzy.push(liczba);
                } else if (tmp == "+") {
                    try {
                        wynik = stosMacierzy.top();
                        stosMacierzy.pop();
                        wynik +=stosMacierzy.top();
                        stosMacierzy.pop();
                    } catch (std::string str) {
                        std::cout << str;
                        error=true;
                       break;
                    }
                    stosMacierzy.push(wynik);
                }else if (tmp == "*") {
                    try {
                        Macierz pom=stosMacierzy.top();
                        stosMacierzy.pop();
                        wynik=stosMacierzy.top();
                        stosMacierzy.pop();
                        wynik = wynik*pom;

                    } catch (std::string str) {
                        std::cout << str;
                        error=true;
                        break;
                    }
                    stosMacierzy.push(wynik);
                }
                else if (tmp == "-") {
                    try {
                        wynik = stosMacierzy.top();
                        stosMacierzy.pop();
                        wynik = stosMacierzy.top()-wynik;
                        stosMacierzy.pop();
                    } catch (std::string str) {
                        std::cout << str;
                        error=true;
                        break;
                    }
                    stosMacierzy.push(wynik);
                }
                else {
                try{
                    czyZmiennaIstnieje(tmp);
                }catch (std::string exc){
                    std::cout<<exc;
                    error=true;
                    break;
                }
                }
            }
            if(error){
                continue;
            }
            else if (stosMacierzy.size() > 0) {
                std::cout << stosMacierzy.top();
                stosMacierzy.pop();
            }

        } else {
            dzielWyrazenie(wejscie);
            if (!sprawdzZmienna(listaStringow[0])) {
                std::cout << "\nNiepoprawna nazwa zmiennej";
                continue;
            }

            if (!sprawdzMacierz(listaStringow[1])) {
                std::cout << "\nBlad w macierzy";
                continue;
            }
            Macierz macierz;
            listaStringow[1].erase(0, 1);
            listaStringow[1].erase(listaStringow[1].length() - 1, 1);
            macierz.inicjalizuj(listaStringow[1]);
            zmienne[listaStringow[0]] = macierz;



        }
    } while (wejscie != "exit");
}

void Interfejs::dzielWyrazenie(const std::string wejscie) {
    std::stringstream bufor(wejscie);
    std::string tmp;
    while (std::getline(bufor, tmp, '=')) {
        listaStringow.push_back(tmp);
    }
}

bool Interfejs::sprawdzZmienna(const std::string nazwaZmiennej) {
    std::regex wzorZmiennej("[a-zA-Z]*");
    return std::regex_match(nazwaZmiennej, wzorZmiennej);
}

bool Interfejs::sprawdzMacierz(const std::string wzorMacierzy) {
    std::regex poprawnyWzorMacierzy("\\[(-?\\d+(\\.\\d+)?[,|;])*(-?\\d+(\\.\\d+)?)\\]");
    return std::regex_match(wzorMacierzy, poprawnyWzorMacierzy);
}

bool Interfejs::sprawdzLiczbe(const std::string liczba) {
    std::regex wzorLiczby("-?\\d+(\\.\\d+)?");
    return std::regex_match(liczba, wzorLiczby);
}

void Interfejs::czyscStos() {
    while (stosMacierzy.size() > 0) {
        stosMacierzy.pop();
    }

}

void Interfejs::czyZmiennaIstnieje(std::string zmienna) {
    int licznik = 0;
    licznik = zmienne.count(zmienna);
    if (licznik == 0) {
        throw std::string("\nNieznana zmienna");
    } else {
        stosMacierzy.push(zmienne[zmienna]);
    }
}



