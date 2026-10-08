#ifndef SerVivo_h_
#define SerVivo_h_

#include <iostream>
#include <string>
using namespace std;

class SerVivo{
protected:
    string nombre;
    string especie;
    int energia;
    bool vivo;

public:
    SerVivo(const string& nombreP, const string& especieP, int energiaP);

    // Métodos de acceso
    const string& getNombre();
    const string& getEspecie();
    int getEnergia() const {return energia;}
    bool getVivo() const {return vivo;}

    // Métodos de modificación
    void setEnergia(int energiaP);

    // Métodos virtuales
    virtual void accionar() = 0;
    virtual SerVivo* reproducirse() = 0;
    virtual bool puedeComer(SerVivo* otro) { (void)otro; return false; }
    virtual void comer(SerVivo* otro) { (void)otro; }
    virtual bool puedeAtacar(SerVivo* otro) { (void)otro; return false; }
    virtual void atacar(SerVivo* otro) { (void)otro; }
    virtual void dibujo() = 0;
    void descansar();

    bool operator==(const SerVivo& otro) const { return especie == otro.especie; }
    SerVivo* operator+(SerVivo& otro) { if (*this == otro) return reproducirse(); return nullptr; }

    virtual void mostrar() const;
};

// Implementación
SerVivo::SerVivo(const string& nombreP, const string& especieP, int energiaP){
    nombre = nombreP;
    especie = especieP;
    energia = energiaP;
    vivo = true;
}

void SerVivo::setEnergia(int energiaP){
    energia = energiaP;
    if(energia <= 0) vivo = false;
}

void SerVivo::descansar(){
    energia += 5;
    cout << nombre << " descansa y gana 5 de energia." << endl;
}

void SerVivo::mostrar() const{
    cout << especie << " '" << nombre << "' [E:" << energia << (vivo ? ", Vivo" : ", Muerto") << "]" << endl;
}

const string& SerVivo::getNombre(){ return nombre; }
const string& SerVivo::getEspecie(){ return especie; }

#endif