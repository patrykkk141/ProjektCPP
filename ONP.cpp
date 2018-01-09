
#include "ONP.h"

ONP::ONP() {
    onp="";
}

ONP::~ONP() {

}

int ONP::priorytetOperatora(const char znak) {
    switch (znak)
    {
        case '(': return 0;
        case ')': return 1;
        case '+': return 1;
        case '-': return 1;
        case '*': return 2;
        case '!': return 3;
        case '~': return 3;
        case '^': return 3;
        default : return 0;
    }
}

std::string ONP::zamianaNaONP(const std::string wyrazenie) {
    onp="";
    int licz=0;
    int liczbaZnakow=wyrazenie.length();
    for(int i=0; i<liczbaZnakow; i++){
        while(isalnum(wyrazenie[i])){
            onp+=wyrazenie[i];
            i++;
        }
        switch(wyrazenie[i])
        {
            case '(':
                stos.push(wyrazenie[i]);
                break;
            case ')':
                licz=0;
                onp+=" ";
                while(stos.sprawdzWierzcholek()!='(' && stos.rozmiar()>0){
                    onp+=stos.pop();
                    onp+=" ";
                    licz++;
                }
                if(licz>0)
                    onp.erase(onp.length()-1, 1);
                if(stos.rozmiar()>0)
                    stos.pop();
                break;
            case '+':
               dodajOperator(wyrazenie, i);
                break;
            case '-':
                dodajOperator(wyrazenie, i);
                break;
            case '*':
                dodajOperator(wyrazenie, i);
                break;
            case '~':
                dodajOperator(wyrazenie, i);
                break;
            case '!':
                dodajOperator(wyrazenie, i);
                break;
            default:
                continue;
        }
    }
    onp+=" ";
    while(stos.rozmiar()>0)    {
        onp+=stos.pop();
        onp+=" ";
    }
    return onp;
}

void ONP::dodajOperator(std::string wyrazenie, int i) {
    onp+=" ";
    if(priorytetOperatora(wyrazenie[i])>priorytetOperatora(stos.sprawdzWierzcholek())){
        stos.push(wyrazenie[i]);
    }else{
        while(priorytetOperatora(wyrazenie[i])<=priorytetOperatora(stos.sprawdzWierzcholek()) || stos.rozmiar()>0){
            if(stos.sprawdzWierzcholek()=='(' && stos.rozmiar()>0)
            {
                stos.pop();
                break;
            }
            onp+=stos.pop();
            onp+=" ";
        }
        stos.push(wyrazenie[i]);
    }
}


