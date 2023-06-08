#include "./barco.h"
#include <iostream>

vector<char> symbols{'0', 'X'};

enum Orientations {
	HOR, VER
};

Barco::Barco()= default;
Barco::Barco(int tamaño){
    this->tamaño = tamaño;
    this->orientacion = HOR;
    for(int i = 0; i < tamaño; i++){
        casillas.push_back(false);
    }
    sunk = false;
}

void Barco::print_casillas(){
		for(int i = 0; i < tamaño; i++){
			cout<<symbols[casillas[i]];
			if(orientacion){
				cout<<endl;
			}
		}
	}

void Barco::hit(int casilla){
	this->casillas[casilla] = true;
    for(bool c : this->casillas){
        if(!c) return;
    }
    sunk = true;
}

int Barco::getTamaño() const{
	return tamaño;
}

int Barco::getOrientacion() const{
	return orientacion;
}

void Barco::setPos(int x, int y){
	this->x = x;
	this->y = y;
}

int Barco::getX() const{
	return x;
}

int Barco::getY() const{
	return y;
}

void Barco::change_orientacion() {
    orientacion == 0 ? orientacion = 1 : orientacion = 0;
}

bool Barco::isSunk() const {
    return sunk;
}
