#include <iostream>
#include <vector>
#include "barco.h"
#pragma once

class Tablero{
private:
	vector<vector<int>> grilla_barcos;
	int altura, ancho;
	vector<Barco*> barcos;

public:
	Tablero(int, int);
	bool insert_barco(Barco*, int, int);
	void mostrar();
	void mostrar_enemigo();
	bool hit(int, int);

    int getAltura();
    int getAncho();
};