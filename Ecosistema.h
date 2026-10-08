#ifndef Ecosistema_h_
#define Ecosistema_h_

#include <iostream>
#include <vector>
#include <string>

using namespace std;

#include "SerVivo.h"

template<typename T>
class Ecosistema{
private:
    vector<T*> habitantes;

public:
    Ecosistema() {}

    void agregar(T* s);
    size_t cantidad() const;
    vector<T*>& getHabitantes();
    void mostrarEstado() const;
};

template<typename T>
void Ecosistema<T>::agregar(T* s){
    habitantes.push_back(s);
}

template<typename T>
size_t Ecosistema<T>::cantidad() const{
    return habitantes.size();
}

template<typename T>
vector<T*>& Ecosistema<T>::getHabitantes(){
    return habitantes;
}

template<typename T>
void Ecosistema<T>::mostrarEstado() const{
    cout << "--- Estado del ecosistema ---\n";
    cout << "Cantidad de habitantes: " << habitantes.size() << "\n";
    if (habitantes.size() == 0){
        cout << "Ecosistema vacio.\n";
        return;
    }

    int totalEnergia = 0;
    for (size_t i = 0; i < habitantes.size(); ++i){
        totalEnergia += habitantes[i]->getEnergia();
        cout << i << ") ";          
        habitantes[i]->mostrar();
    }

    double promedio = static_cast<double>(totalEnergia)/habitantes.size();
    cout << "Energia promedio: " << promedio << "\n";

    vector<string> especiesUnicas;
    vector<int> cuenta;
    for (size_t i = 0; i < habitantes.size(); ++i){
        string sp = habitantes[i]->getEspecie();
        bool encontrado = false;
        for (size_t j = 0; j < especiesUnicas.size(); ++j){
            if (especiesUnicas[j] == sp){
                cuenta[j]++;
                encontrado = true;
                break;
            }
        }
        if (!encontrado){
            especiesUnicas.push_back(sp);
            cuenta.push_back(1);
        }
    }

    int maxc = 0; string dominante;
    for (size_t i = 0; i < especiesUnicas.size(); ++i){
        if (cuenta[i] > maxc){
            maxc = cuenta[i];
            dominante = especiesUnicas[i];
        }
    }

    cout << "Especie dominante: " << dominante << " (" << maxc << " individuos)\n";
    cout << "----------------------------\n";
}

#endif