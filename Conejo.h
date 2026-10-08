#ifndef Conejo_h_
#define Conejo_h_

#include "Animal2.h"
#include "Hena.h"
#include "Pasto.h"

class Conejo : public Animal{
public:
    Conejo(const string& nombreP, int energiaP = 30);

    virtual void accionar();
    virtual bool puedeComer(SerVivo* otro);
    virtual void comer(SerVivo* otro);
    virtual SerVivo* reproducirse();
    virtual void dibujo();
};

Conejo::Conejo(const string& nombreP, int energiaP): Animal(nombreP, "Conejo", energiaP, 2){

}

void Conejo::accionar(){ Animal::accionar(); }

bool Conejo::puedeComer(SerVivo* otro){
    string sp = otro->getEspecie();
    return (sp == "Hena" || sp == "Pasto");
}

void Conejo::comer(SerVivo* otro){
    int energiaGanada = otro->getEnergia()/3 + 5;
    energia += energiaGanada;
    cout << nombre << " come " << otro->getEspecie() << " y gana " << energiaGanada << " de energia.\n";
}

SerVivo* Conejo::reproducirse(){
    cout << nombre << " tiene una cria.\n";
    return new Conejo("Cria_Conejo", energia/2);
}

void Conejo::dibujo(){
    cout << " (\\_/)" << endl;
    cout << " ( •_•)" << endl;
    cout << " / >o" << endl;
}

#endif