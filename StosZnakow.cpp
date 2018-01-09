#include "StosZnakow.h"
#include <iostream>

StosZnakow::StosZnakow() {
    wierzcholek=0;
}

StosZnakow::~StosZnakow() {

}

void StosZnakow::push(const char znak) {
    if(wierzcholek<10){
        stos[wierzcholek]=znak;
        wierzcholek++;
    } else{
        std::cout<<"\nPrzepelnienie bufora stosu znakow!";
    }
}

char StosZnakow::pop() {
    if(wierzcholek<0)
        std::cout<<"\nStos znakow jest pusty";
    else{
        return stos[--wierzcholek];
    }
}

int StosZnakow::rozmiar() const {
    return wierzcholek;
}

char StosZnakow::sprawdzWierzcholek() const {
    if (wierzcholek<0)
        return '\n';
    else
        return stos[wierzcholek-1];
}
