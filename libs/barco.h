#pragma once
#include <vector>

using namespace std;

class Barco{
private:
	int tamaño{};
	int orientacion{};
	int x{};
	int y{};
    bool sunk{};

public:
    Barco();
	explicit Barco(int);
	
	vector<bool> casillas;
	int getX() const;
	int getY() const;
	void setPos(int, int);
	int getTamaño() const;
	int getOrientacion() const;
	void hit(int casilla);
	void print_casillas();
    void change_orientacion();
    bool isSunk() const;

};