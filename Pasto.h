#ifndef Pasto_h_
#define Pasto_h_

#include "Planta.h"

class Pasto : public Planta{
public:
    Pasto(const string& nombreP, int energiaP = 25);

    virtual SerVivo* reproducirse();
    virtual void dibujo();
};

Pasto::Pasto(const string& nombreP, int energiaP)
: Planta(nombreP, "Pasto", energiaP, 1) {}

SerVivo* Pasto::reproducirse(){
    cout << nombre << " genera un nuevo Pasto.\n";
    return new Pasto("Pasto_Hijo", energia/2);
}

void Pasto::dibujo(){
    cout << " ||  | || | |" << endl;
    cout << " || || || |||" << endl;
}

#endif