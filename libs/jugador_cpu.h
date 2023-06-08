#include "jugador.h"

using namespace std;

struct hit {
    int x, y;
};
class CPU:public Jugador{
private:
    vector<hit> hits;
public:
    CPU(string nombre, Tablero* tablero, vector<Barco*>);
    void place_barquitos() override;
    void attack(Tablero*) override;
};