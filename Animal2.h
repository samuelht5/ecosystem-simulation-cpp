#ifndef Animal_h_
#define Animal_h_

#include "SerVivo.h"

class Animal : public SerVivo{
protected:
    int metabolismo;

public:
    Animal(const string& nombreP, const string& especieP, int energiaP, int metabolismoP);

    virtual void accionar();
    virtual void dibujo() = 0;
};

Animal::Animal(const string& nombreP, const string& especieP, int energiaP, int metabolismoP): SerVivo(nombreP, especieP, energiaP){
    metabolismo = metabolismoP;
}


void Animal::accionar(){
    energia -= metabolismo;
    if(energia <= 0) vivo = false;
}

#endif