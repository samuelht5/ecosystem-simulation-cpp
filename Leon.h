#ifndef Leon_h_
#define Leon_h_

#include "Animal2.h"
#include "Conejo.h"

class Leon : public Animal{
public:
    Leon(const string& nombreP, int energiaP = 80);

    virtual bool puedeAtacar(SerVivo* otro);
    virtual void atacar(SerVivo* otro);
    virtual SerVivo* reproducirse();
    virtual void dibujo();
};

Leon::Leon(const string& nombreP, int energiaP)
: Animal(nombreP, "Leon", energiaP, 8) {}

bool Leon::puedeAtacar(SerVivo* otro){
    return otro->getEspecie() == "Conejo";
}

void Leon::atacar(SerVivo* otro){
    int dano = 20;
    otro->setEnergia(otro->getEnergia() - dano);
    energia += dano/2;
    cout << nombre << " ataca a " << otro->getNombre() << " y gana " << dano/2 << " de energia.\n";
}

SerVivo* Leon::reproducirse(){
    cout << nombre << " tiene una cria de Leon.\n";
    return new Leon("Cria_Leon", energia/2);
}

void Leon::dibujo(){
    cout << "  ,wWWw," << endl;
    cout << " ( oᴥo )" << endl;
    cout << "  \"  \" " << endl;

}

#endif