#include "jugador.h"


Jugador::Jugador(string nombre, Tablero *tablero, vector<Barco*> barcos) {
    this->nombre = nombre;
    this->tablero = tablero;
    this->barcos = barcos;
    this->has_lost = false;
}

void Jugador::setNombre(string nombre) {
    this->nombre = nombre;
}

string Jugador::getNombre() {
    return nombre;
}

void Jugador::lost() {
    has_lost = true;
}

bool Jugador::getHasLost() {
    return has_lost;
}

void Jugador::update() {
    for(auto b : barcos){
        if(!b->isSunk()) return;
    }
    lost();
}

