#include "Macierz.h"
#include <vector>

Macierz::Macierz() {
    macierz = nullptr;
}

Macierz::Macierz(const int wiersze, const int kolumny) {
    Macierz::liczbaKolumn = kolumny;
    Macierz::liczbaWierszy = wiersze;
    macierz = new double *[liczbaWierszy];
    for (int i = 0; i < liczbaWierszy; i++) {
        macierz[i] = new double[liczbaKolumn];
    }
}

Macierz::Macierz(const Macierz &p) : liczbaKolumn(p.liczbaKolumn), liczbaWierszy(p.liczbaWierszy) {
    this->inicjalizuj();
    for (int i = 0; i < liczbaWierszy; i++) {
        for (int j = 0; j < liczbaKolumn; j++) {
            macierz[i][j] = p.macierz[i][j];
        }
    }
}

Macierz::~Macierz() {
    for(int i=0; i<this->liczbaWierszy; i++){
        delete[] macierz[i];
    }
    delete[] macierz;
}

void Macierz::ustaw(double liczba) {
   this->macierz[0][0]=liczba;
}

void Macierz::inicjalizuj() {
    if (liczbaWierszy < 1 && liczbaKolumn < 1)
        std::cout << "\nZla liczba wierszy lub kolumn!";
    else {
        macierz = new double *[liczbaWierszy];
        for (int i = 0; i < liczbaWierszy; i++) {
            macierz[i] = new double[liczbaKolumn];
        }
    }
}

void Macierz::inicjalizuj(std::string macierz) {
    std::stringstream bufor(macierz);
    std::string wiersz;
    std::vector<std::string> wiersze;
    int liczbaKolumn = 1;
    int liczbaWierszy = 0;

    for (int i = 0; i < macierz.length() && macierz[i] != ';'; i++) {
        if (macierz[i] == ',')
            liczbaKolumn++;
    }
    while (getline(bufor, wiersz, ';')) {
        liczbaWierszy++;
        wiersze.push_back(wiersz);
        int pomLiczbaKolumn = 1;
        for (int i = 0; i < wiersz.length(); i++) {
            if (wiersz[i] == ',')
                pomLiczbaKolumn++;
        }
        if (pomLiczbaKolumn != liczbaKolumn) {
            std::cout << "\nBlad w liczbie kolumn;";
            return void();
        }
    }
    this->liczbaKolumn = liczbaKolumn;
    this->liczbaWierszy = liczbaWierszy;
    this->inicjalizuj();
    // *this=Macierz(liczbaKolumn, liczbaWierszy);

    for (int i = 0; i < liczbaWierszy; i++) {
        std::stringstream buf(wiersze[i]);
        for (int j = 0; j < liczbaKolumn; j++) {
            buf >> this->macierz[i][j];
            buf.ignore();
        }
    }


}

std::ostream &operator<<(std::ostream &wy, const Macierz &p) {
    for (int i = 0; i < p.liczbaWierszy; i++) {
        for (int j = 0; j < p.liczbaKolumn; j++) {
            wy << p.macierz[i][j] << " ";
        }
        wy << "\n";
    }
    return wy;
}

Macierz &Macierz::operator=(const Macierz &wzor) {
    this->liczbaKolumn = wzor.liczbaKolumn;
    this->liczbaWierszy = wzor.liczbaWierszy;
    this->inicjalizuj();
    for (int i = 0; i < liczbaWierszy; i++) {
        for (int j = 0; j < liczbaKolumn; j++) {
            macierz[i][j] = wzor.macierz[i][j];
        }
    }
    return *this;
}

Macierz Macierz::operator+(const Macierz &wzor) {
    if(wzor.liczbaKolumn==1 && wzor.liczbaWierszy==1)
    {
        Macierz wynik(liczbaWierszy, liczbaKolumn);
        for(int i=0; i<liczbaWierszy; i++){
            for(int j=0; j<liczbaKolumn; j++){
                wynik.macierz[i][j]=macierz[i][j]+wzor.macierz[0][0];
            }
        }
        return wynik;
    }
        else if(this->liczbaKolumn==1 && this->liczbaWierszy==1){
        Macierz wynik(wzor.liczbaWierszy, wzor.liczbaKolumn);
        for(int i=0; i<wzor.liczbaWierszy; i++) {
            for (int j = 0; j < wzor.liczbaKolumn; j++) {
                wynik.macierz[i][j] = wzor.macierz[i][j]+this->macierz[0][0];
            }
        }
        return wynik;
    }
    else if (this->liczbaWierszy == wzor.liczbaWierszy && this->liczbaKolumn == wzor.liczbaKolumn) {
        Macierz wynik = *this;
        for (int i = 0; i < liczbaWierszy; i++) {
            for (int j = 0; j < liczbaKolumn; j++) {
                wynik.macierz[i][j] += wzor.macierz[i][j];
            }
        }

        return wynik;
    } else {
        throw std::string("\nNieporpawny rozmiar macierzy przy dodawaniu");
    }
}

Macierz Macierz::operator-(const Macierz &wzor) {
    if(wzor.liczbaKolumn==1 && wzor.liczbaWierszy==1)
    {
        Macierz wynik(liczbaWierszy, liczbaKolumn);
        for(int i=0; i<liczbaWierszy; i++){
            for(int j=0; j<liczbaKolumn; j++){
                wynik.macierz[i][j]=macierz[i][j]-wzor.macierz[0][0];
            }
        }
        return wynik;
    }
   else if(wzor.liczbaKolumn==1 && wzor.liczbaWierszy==1)
    {
        Macierz wynik(liczbaWierszy, liczbaKolumn);
        for(int i=0; i<liczbaWierszy; i++){
            for(int j=0; j<liczbaKolumn; j++){
                wynik.macierz[i][j]=macierz[i][j]-wzor.macierz[0][0];
            }
        }
        return wynik;
    }
    else if (this->liczbaWierszy == wzor.liczbaWierszy && this->liczbaKolumn == wzor.liczbaKolumn) {
        Macierz wynik = *this;
        for (int i = 0; i < liczbaWierszy; i++) {
            for (int j = 0; j < liczbaKolumn; j++) {
                wynik.macierz[i][j] -= wzor.macierz[i][j];
            }
        }
        return wynik;
    } else {
        throw std::string("\nNieporpawny rozmiar macierzy podczas odejmowania");
    }
}


Macierz Macierz::operator*(const Macierz &wzor) {
    if(this->liczbaKolumn==1 && this->liczbaWierszy==1) {
        Macierz wynik(wzor.liczbaWierszy, wzor.liczbaKolumn);
        for (int i = 0; i < wzor.liczbaWierszy; i++) {
            for (int j = 0; j < wzor.liczbaKolumn; j++) {
                wynik.macierz[i][j] = wzor.macierz[i][j] * this->macierz[0][0];
            }
        }
        return wynik;
    }

    else if(wzor.liczbaKolumn==1 && wzor.liczbaWierszy==1)
    {
        Macierz wynik(liczbaWierszy, liczbaKolumn);
        for(int i=0; i<liczbaWierszy; i++){
            for(int j=0; j<liczbaKolumn; j++){
                wynik.macierz[i][j]=macierz[i][j]*wzor.macierz[0][0];
            }
        }
        return wynik;
    }
    else if (liczbaKolumn != wzor.liczbaWierszy) {
        throw std::string("\nNiepoprawne wymiary macierzy podczas mnozenia");
    } else {
        Macierz wynik(liczbaWierszy, wzor.liczbaKolumn);
        for (int i = 0; i < liczbaWierszy; i++) {
            for (int j = 0; j < liczbaKolumn; j++) {
                int suma=0;
                for(int k=0; k<liczbaKolumn; k++){
                suma=suma+macierz[i][k]*wzor.macierz[k][j];
                }
                wynik.macierz[i][j]=suma;
            }
        }
        return wynik;
    }
}

Macierz Macierz::operator~() {
    Macierz wynik(liczbaKolumn, liczbaWierszy);
    for(int i=0; i<liczbaKolumn; i++){
        for(int j=0; j<liczbaWierszy; j++){
            wynik.macierz[i][j]=macierz[j][i];
        }
    }
    return wynik;
}


Macierz Macierz::dopelnienieMacierzy(const Macierz &wzor,  int numerWiersza) {
   Macierz wynik(wzor.liczbaWierszy-1, wzor.liczbaKolumn-1);
    for(int i=0; i<numerWiersza && i<wynik.liczbaWierszy; i++){
        for(int j=0; j<wynik.liczbaWierszy; j++){
            wynik.macierz[i][j]=wzor.macierz[i][j+1];
        }
    }
    for(int i=numerWiersza; i<wynik.liczbaWierszy; i++){
        for(int j=0; j<wynik.liczbaWierszy; j++){
            wynik.macierz[i][j]=wzor.macierz[i+1][j+1];
        }
    }
    return wynik;
}

double Macierz::wyznacznikMacierzy(const Macierz &wzor) {
    if(wzor.liczbaWierszy!=wzor.liczbaKolumn){
        throw std::string("\nWyznacznik mozna liczyc jedynie z macierzy kwadratowej!");
    }else{
        if(wzor.liczbaWierszy==1)
            return macierz[0][0];
        else if(wzor.liczbaWierszy==2){
            return wzor.macierz[0][0]*wzor.macierz[1][1]-wzor.macierz[1][0]*wzor.macierz[0][1];
        }
        else{
            double wyznacznik=0;
            for(int i=0; i<wzor.liczbaWierszy; i++){
                wyznacznik+=wzor.macierz[i][0]*pow(-1,i+1)*wyznacznikMacierzy(dopelnienieMacierzy(wzor,i));
            }
            return wyznacznik;
        }
    }

}

double Macierz::operator!() {
    return wyznacznikMacierzy(*this);
}


Macierz Macierz::usun(const int numerWiersza, const int numerKolumny) {
    Macierz wynik(liczbaWierszy-1,liczbaKolumn-1);
    for(int i=0; i<numerWiersza && i<wynik.liczbaWierszy; i++){
        for(int j=0; j<numerKolumny && j<wynik.liczbaKolumn; j++){
            wynik.macierz[i][j]=macierz[i][j];
        }
    }
    for(int i=0; i<numerWiersza && i<wynik.liczbaWierszy;i++ ){
        for(int j=numerKolumny; j<wynik.liczbaKolumn ; j++){
            wynik.macierz[i][j]=macierz[i][j+1];
        }
    }
    for(int i=numerWiersza; i<wynik.liczbaWierszy; i++){
        for(int j=0; j<numerKolumny && j<wynik.liczbaKolumn; j++){
            wynik.macierz[i][j]=macierz[i+1][j];
        }
    }
    for(int i=numerWiersza; i<wynik.liczbaWierszy; i++){
        for(int j=numerKolumny; j<wynik.liczbaKolumn; j++){
            wynik.macierz[i][j]=macierz[i+1][j+1];
        }
    }
    return wynik;
}

Macierz &Macierz::operator+=(const Macierz &wzor) {
    if(this->liczbaKolumn == 1 && this->liczbaWierszy == 1)
    {
        Macierz wynik=wzor;
        for(int i=0; i<liczbaWierszy; i++){
            for(int j=0; j<liczbaKolumn; j++){
               wynik.macierz[i][j]=wzor.macierz[i][j]+this->macierz[0][0];
            }
        }
        *this=wzor;
        return *this;
    }
    else if(wzor.liczbaKolumn==1 & wzor.liczbaWierszy==1){
        for(int i=0; i<liczbaWierszy; i++){
            for(int j=0; j<liczbaKolumn; j++){
                this->macierz[i][j]+=wzor.macierz[0][0];
            }
        }
        return *this;
    }    else if(this->liczbaKolumn==wzor.liczbaKolumn && this->liczbaWierszy==wzor.liczbaWierszy){
        for(int i=0; i<liczbaWierszy; i++){
            for(int j=0; j<liczbaKolumn; j++){
                this->macierz[i][j]+=wzor.macierz[i][j];
            }
        }
        return *this;
    }else{
        throw std::string("\nNieprawidlowy rozmiar macierzy podczas dodawania");
    }
}

Macierz Macierz::dopelnienieMacierzy() {
    Macierz wynik=*this;
  return *this;
}

Macierz &Macierz::operator-=(const Macierz &wzor) {
    if(this->liczbaKolumn == 1 && this->liczbaWierszy == 1)
    {
        Macierz wynik=wzor;
        for(int i=0; i<liczbaWierszy; i++){
            for(int j=0; j<liczbaKolumn; j++){
                wynik.macierz[i][j]=wzor.macierz[i][j]-this->macierz[0][0];
            }
        }
        *this=wzor;
        return *this;
    }
    else if(wzor.liczbaKolumn==1 & wzor.liczbaWierszy==1){
        for(int i=0; i<liczbaWierszy; i++){
            for(int j=0; j<liczbaKolumn; j++){
                this->macierz[i][j]-=wzor.macierz[0][0];
            }
        }
        return *this;
    }    else if(this->liczbaKolumn==wzor.liczbaKolumn && this->liczbaWierszy==wzor.liczbaWierszy){
        for(int i=0; i<liczbaWierszy; i++){
            for(int j=0; j<liczbaKolumn; j++){
                this->macierz[i][j]-=wzor.macierz[i][j];
            }
        }
        return *this;
    }else{
        throw std::string("\nNieprawidlowy rozmiar macierzy podczas odejmowania");
    }
}
