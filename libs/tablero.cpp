#include "tablero.h"
	
enum Tipo { 
	WATER, SHIP, HIT, MISSED
};
Tablero::Tablero(int altura, int ancho){
	this->altura = altura;
	this->ancho = ancho;

	for(int i = 0; i < altura; i++){
		vector<int> b;
		grilla_barcos.push_back(b);
		for(int j = 0; j < ancho; j++){
			grilla_barcos[i].push_back(	WATER);
		}
	}
}
bool Tablero::insert_barco(Barco* b, int x, int y){
    if ((x + b->getTamaño()) * (1-b->getOrientacion()) > ancho) return false;
    if ((y + b->getTamaño()) * b->getOrientacion() > altura) return false;
    for(int i = 0; i < b->getTamaño(); i++){
        if(b->getOrientacion()){
            if(grilla_barcos[y+i][x] == SHIP) return false;
        }
        else{
            if (grilla_barcos[y][x+i] == SHIP) return false;
        }
    }

	for(int i = 0; i < b->getTamaño(); i++){
		if(b->getOrientacion()){
			grilla_barcos[y+i][x] = SHIP;
		}
		else{
			grilla_barcos[y][x+i] = SHIP;
		}
	}
	b->setPos(x, y);
	barcos.push_back(b);
    return true;
};

void Tablero::mostrar(){
	for(int i = 0; i < altura; i++){
		for(int j = 0; j < ancho; j++){
			if(grilla_barcos[i][j] == SHIP){
				cout<<'X';
				continue;
			}
			if(grilla_barcos[i][j] == HIT){
				cout<<'#';
				continue;
			}

			if(grilla_barcos[i][j] == WATER){
				cout<<'0';
				continue;
			}
			if(grilla_barcos[i][j] == MISSED){
				cout<<'F';
			}
		}
		cout<<endl;
	}
};

void Tablero::mostrar_enemigo(){
	for(int i = 0; i < altura; i++){
		for(int j = 0; j < ancho; j++){
			if(grilla_barcos[i][j] == HIT){
				cout<<'#';
				continue;
			};
			if(grilla_barcos[i][j] == MISSED){
				cout<<'F';
				continue;
			}
			if(grilla_barcos[i][j] != HIT){
				cout<<'0';
				continue;
			};

		
		}

		cout<<endl;
	}
}

bool Tablero::hit(int x, int y){
	if(grilla_barcos[y][x] == SHIP){
		for(auto b : barcos){
			if(b->getOrientacion()){
				if(x >= b->getX() && x <= b->getX()){
					if(y == b->getY()){
						b->hit(b->getX() - x);
					}
				}
			}else{
				if(y >= b->getY() && y <= b->getY()){
					if(x == b->getX()){
                        b->hit(b->getY() - y);
					}
				}
			}
			grilla_barcos[y][x] = HIT;
            return true;
		}
	}
	grilla_barcos[y][x] = MISSED;
	return false;
}

int Tablero::getAltura() {
    return altura;
}

int Tablero::getAncho() {
    return ancho;
}