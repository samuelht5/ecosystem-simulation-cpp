#ifndef Planta_h_
#define Planta_h_

#include "SerVivo.h"

class Planta : public SerVivo{
protected:
    int crecimiento;

public:
    Planta(const string& nombreP, const string& especieP, int energiaP, int crecimientoP);

    virtual void accionar();
    virtual void dibujo() = 0;
};

Planta::Planta(const string& nombreP, const string& especieP, int energiaP, int crecimientoP)
: SerVivo(nombreP, especieP, energiaP), crecimiento(crecimientoP) {}

void Planta::accionar(){
    energia += crecimiento;
}

#endif