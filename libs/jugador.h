#include <iostream>
#include <string>
#include "tablero.h"
#pragma once

using namespace std;
class Jugador{
protected:
    string nombre;
    Tablero *tablero;
    vector<Barco*> barcos;
    bool has_lost;
public:
    Jugador(string, Tablero*, vector<Barco*>);
    void setNombre(string);
    string getNombre();
    void lost();
    bool getHasLost();
    virtual void place_barquitos() = 0;
    virtual void attack(Tablero *) = 0;
    void update();

};