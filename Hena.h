#ifndef Hena_h_
#define Hena_h_

#include "Planta.h"

class Hena : public Planta{
public:
    Hena(const string& nombreP, int energiaP = 40);

    virtual SerVivo* reproducirse();
    virtual void dibujo();
};

Hena::Hena(const string& nombreP, int energiaP)
: Planta(nombreP, "Hena", energiaP, 3) {}

SerVivo* Hena::reproducirse(){
    cout << nombre << " genera una nueva Hena.\n";
    return new Hena("Hena_Hija", energia/2);
}

void Hena::dibujo(){
    cout << "  /\\_/\\ " << endl;
    cout << " ( ´ᴥ` )" << endl;
    cout << "  /   \\" << endl;

}

#endif