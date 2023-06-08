#include "jugador.h"

using namespace std;
class Humano:public Jugador{
public:
    Humano(string nombre, Tablero* tablero, vector<Barco*>);
    void place_barquitos() override;
    void attack(Tablero*) override;
};