#include <iostream>
using namespace std;

#include <string>
#include <vector>
#include <random>
#include <ctime>




#include "Ecosistema.h"
#include "Hena.h"
#include "Pasto.h"
#include "Conejo.h"
#include "Lobo.h"
#include "Leon.h"


int main() {
    srand(time(NULL));
    Ecosistema<SerVivo> eco;

    // Poblacion inicial
    eco.agregar(new Hena("Hena1", 40));
    eco.agregar(new Hena("Hena2", 30));
    eco.agregar(new Pasto("Pasto1", 20));
    eco.agregar(new Pasto("Pasto2", 25));
    eco.agregar(new Conejo("Bugs", 30));
    eco.agregar(new Conejo("Bunny", 25));
    eco.agregar(new Lobo("Colmillo", 55));
    eco.agregar(new Leon("Simba", 75));

    int turno = 1;

    while (eco.cantidad() > 0) {
        cout << "TURNO " << turno << endl;
        //apocalipsis aleatorio
        int prob = rand() % 100;  

        if (prob < 10) {  //10% de proobabilidad
            cout << "Un meteorito cayo en la tierra, mueren todos los habitantes" << endl;
            cout << "            _.-^^---....,,--        \n";
            cout << "        _--                  --_    \n";
            cout << "       <                        >)  \n";
            cout << "       |   BOOOOM!!!!!!!         | \n";
            cout << "        \\._                   _./  \n";
            cout << "           ```--. . , ; .--'''     \n";
            cout << "                 | |   |           \n";
            cout << "              .-=||  | |=-.        \n";
            cout << "              `-=#$%&%$#=-'        \n";
            cout << "                 | ;  :|           \n";
            cout << "        _____.,-#%&$@%#&#~,._____  \n\n";

            // Mata a todos los seres vivos
            vector<SerVivo*>& habitantes = eco.getHabitantes();
            for (SerVivo* h : habitantes) {
                delete h;
            }
            habitantes.clear();

            break; 
        }

        eco.mostrarEstado();

        vector<SerVivo*>& habitantes = eco.getHabitantes();

        // Menu: elige el ser vivo con el que quieres actuar
        cout << "Escoge el ser vivo que quieres controlar (0 a " << habitantes.size()-1 << "): ";
        size_t idx; 
        cin >> idx;

        if (idx >= habitantes.size() || !habitantes[idx]->getVivo()) {
            cout << "Opcion no existente o ser muerto. Se salta turno" << endl;
        } else {
            SerVivo* s = habitantes[idx];

            cout << "\nAccion para " << s->getNombre() << " (" << s->getEspecie() << ")\n";
            s->dibujo();
            cout << endl;
            cout << "1) Accionar automatico" << endl;
            cout << "2) Comer" << endl;
            cout << "3) Atacar" << endl;
            cout << "4) Reproducirse" << endl;
            cout << "5) Descansar " << endl;
            cout << "6) Nada" << endl;
            int opcion;
            cin >> opcion;

            switch(opcion) {
                case 1:
                    s->accionar();
                    break;

                case 2: {
                    cout << "Elige indice del ser vivo para comer (0 a " << habitantes.size()-1 << "): ";
                    size_t idx2; cin >> idx2;
                    if (idx2 < habitantes.size() && s->puedeComer(habitantes[idx2])) {
                        s->comer(habitantes[idx2]);
                        delete habitantes[idx2];
                        habitantes.erase(habitantes.begin() + idx2);
                        if (idx2 < idx) idx--;
                    } else {
                        cout << "No puede comer ese ser.\n";
                    }
                    break;
                }

                case 3: {
                    cout << "Elige indice del ser vivo para atacar (0 a " << habitantes.size()-1 << "): ";
                    size_t idx2; cin >> idx2;
                    if (idx2 < habitantes.size() && s->puedeAtacar(habitantes[idx2])) {
                        s->atacar(habitantes[idx2]);
                        if (!habitantes[idx2]->getVivo()) {
                            delete habitantes[idx2];
                            habitantes.erase(habitantes.begin() + idx2);
                            if (idx2 < idx) idx--;
                        }
                    } else {
                        cout << "No puede atacar ese ser.\n";
                    }
                    break;
                }

                case 4: {
                    cout << "Elige indice de pareja para reproducirse (0 a " << habitantes.size()-1 << "): ";
                    size_t idx2; cin >> idx2;
                    if (idx2 < habitantes.size() && *s == *habitantes[idx2] && s->getEnergia() > 30 && habitantes[idx2]->getEnergia() > 30) {
                        SerVivo* cr = *s + *habitantes[idx2];
                        if (cr) {
                            habitantes.push_back(cr);
                            s->setEnergia(s->getEnergia()-30);
                            habitantes[idx2]->setEnergia(habitantes[idx2]->getEnergia()-30);
                            cout << s->getEspecie() << " se reproduce.\n";
                        }
                    } else {
                        cout << "No puede reproducirse con ese ser.\n";
                    }
                    break;
                }

                case 5:
                    s->descansar();
                    break;

                case 6:
                    cout << s->getNombre() << " no hace nada.\n";
                    break;

                default:
                    cout << "Opcion invalida, nada.\n";
                    break;
            }
        }

        // Eliminar muertos
        for (size_t i = 0; i < habitantes.size();) {
            if (!habitantes[i]->getVivo() || habitantes[i]->getEnergia() <= 0) {
                cout << habitantes[i]->getNombre() << " ha muerto.\n";
                cout << "  .----. " << endl;
                cout << " ( x  x )" << endl;
                cout << "  | -- | " << endl;
                cout << "  '----' " << endl;
                cout << endl;
                delete habitantes[i];
                habitantes.erase(habitantes.begin()+i);
            } else ++i;
        }

        turno++;
    }

    cout << "Simulacion finalizada.\n";
    return 0;
}