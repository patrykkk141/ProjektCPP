class StosZnakow {
public:
    StosZnakow();
    ~StosZnakow();
    void push(const char znak);
    char pop();
    int rozmiar() const;
    char sprawdzWierzcholek() const ;
private:
    int wierzcholek;
    char stos[10];

};

