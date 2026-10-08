#ifndef Lobo_h_
#define Lobo_h_

#include "Animal2.h"
#include "Conejo.h"

class Lobo : public Animal{
public:
    Lobo(const string& nombreP, int energiaP = 60);

    virtual bool puedeAtacar(SerVivo* otro);
    virtual void atacar(SerVivo* otro);
    virtual SerVivo* reproducirse();
    virtual void dibujo();
};

Lobo::Lobo(const string& nombreP, int energiaP)
: Animal(nombreP, "Lobo", energiaP, 5) {}

bool Lobo::puedeAtacar(SerVivo* otro){
    return otro->getEspecie() == "Conejo";
}

void Lobo::atacar(SerVivo* otro){
    int dano = 15;
    otro->setEnergia(otro->getEnergia() - dano);
    energia += dano/2;
    cout << nombre << " ataca a " << otro->getNombre() << " y gana " << dano/2 << " de energia.\n";
}

SerVivo* Lobo::reproducirse(){
    cout << nombre << " engendra un lobezno.\n";
    return new Lobo("Lobezno", energia/2);
}

void Lobo::dibujo(){
    cout << " /\\_/\\ " << endl;
    cout << " ( 0w0 )" << endl;
    cout << " /  ^  \\" << endl;

}

#endif