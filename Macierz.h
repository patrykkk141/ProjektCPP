#pragma once

#include <iostream>
#include <sstream>
#include <string>
#include <cmath>

class Macierz {
public:
    Macierz();
    Macierz(const Macierz &p);
    Macierz(const int wiersze, const int kolumny);
    ~Macierz();
    void ustaw(double liczba);
    void inicjalizuj();
    void inicjalizuj(std::string macierz);

    //********OPERATORY*************
    friend std::ostream &operator<<(std::ostream &wy, const Macierz &p);
    Macierz &operator=(const Macierz &wzor);
    Macierz operator+(const Macierz &wzor);
    Macierz operator-(const Macierz &wzor);
    Macierz operator*(const Macierz &wzor);
    Macierz operator~();
    double operator!();
    Macierz& operator+=(const Macierz& wzor);
    Macierz& operator-=(const Macierz& wzor);

private:
    int liczbaKolumn = 0;
    int liczbaWierszy = 0;
    double **macierz;
    double wyznacznikMacierzy(const Macierz &wzor);
    static Macierz dopelnienieMacierzy(const Macierz &wzor, int numerWiersza);
    Macierz usun(int numerWiersza, int numerKolumny);
    Macierz dopelnienieMacierzy();
};
