#include "jugador_cpu.h"

void CPU::place_barquitos() {

    Barco* b;
    int x, y;
    bool change;
    for(auto & barco : barcos){
        b = barco;
        change = rand() % 2;
        if (change == 1) b->change_orientacion();
        do{
            x = rand() % (tablero->getAncho() + 1);
            y = rand() % (tablero->getAltura() + 1);
        }while(!tablero->insert_barco(b, x, y));

    }
    tablero->mostrar();
}

void CPU::attack(Tablero *enemigo) {

    int x, y;
    while(true){
        x = rand() % (tablero->getAncho());
        y = rand() % (tablero->getAltura());
        for(auto &hit : hits){
            if(hit.x == x && hit.y == y){
               continue;
            }
        }
        break;
    };
    enemigo->hit(x, y);

    cout<<"TE ATACARON!"<<endl;
    for(int i = 0; i < enemigo->getAncho(); i++) cout<<"=";
    cout<<endl;
    enemigo->mostrar();

}

CPU::CPU(string nombre, Tablero *tablero, vector<Barco*> barcos) : Jugador(nombre, tablero, barcos) {

}
