#include "./libs/jugador_humano.h"
#include "./libs/jugador_cpu.h"
using namespace std;


enum Orientations {
	HOR, VER
};

int main(){
    Tablero p(9, 9);
    Tablero e(9, 9);
    vector<Barco*> barcos_jugador_1;
    vector<Barco*> barcos_enemigo_1;
    for(int i = 1; i < 4; i++){
        barcos_jugador_1.emplace_back(new Barco(i));
    }
    for(int i = 1; i < 4; i++){
        barcos_enemigo_1.emplace_back(new Barco(i));
    }
    Humano player("Jugador 1", &p, barcos_jugador_1);
    CPU cpu("CPU", &e, barcos_enemigo_1);
    player.place_barquitos();
    cpu.place_barquitos();


    string x;
    while(true){
        system("cls");
        player.attack(&e);
        player.update();
        if(cpu.getHasLost()) break;
        cpu.attack(&p);
        cpu.update();
        if(player.getHasLost()) break;
        system("pause");
    }


	return 0;
}