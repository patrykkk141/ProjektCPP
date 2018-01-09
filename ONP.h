#include "StosZnakow.h"
#include <string>

class ONP {
public:
    ONP();
    ~ONP();
    std::string zamianaNaONP(const std::string wyrazenie);
private:
    StosZnakow stos;
    std::string onp;
    int priorytetOperatora(const char znak);
    void dodajOperator(std::string wyrazenie, int i);
};

