#include "jugador_humano.h"

void Humano::place_barquitos() {
    int i = 0;
    for(auto b : barcos){
        cout<< "Barco "<<++i<<endl;
        cout<< "====="<<endl;
        b->print_casillas();
        cout<<endl;
        cout<< "====="<<endl;
    }
    system("pause");
    system("cls");

    cout<<"Es hora de colocar los barquitos en la grilla!"<<endl;
    tablero->mostrar();

    system("pause");
    system("cls");
    int x, y;
    bool incorrect, placed;
    Barco* b;
    for(i = 0; i < barcos.size(); i++){
        b = barcos[i];
        do{

            cout<<"Barquito: "<< endl;
            cout<<"====="<<endl;
            b->print_casillas();
            cout<<endl;
            system("pause");
            system("cls");

            cout<<"Donde desea ingresar el barco " << i+1 <<"?"<<endl;
            do{
                cout<<"X: "<<endl;
                cin>>x;
                incorrect = x < 0 || x >= tablero->getAncho();
                if(incorrect){
                    cout<<"El valor de x debe estar entre 0 y "<<tablero->getAncho() - 1<<endl;
                }
            }while(incorrect);


            do{
                cout<<"Y: "<<endl;
                cin>>y;
                incorrect = y < 0 || y >= tablero->getAltura();
                if(incorrect){
                    cout<<"El valor de y debe estar entre 0 y "<<tablero->getAltura() - 1<<endl;
                }
            }while(incorrect);

            if(b->getTamaño() > 1){
                int opcion;
                cout<<"Desea cambiar la orientacion??"<<endl;
                cout<<"Orientacion actual: ";
                b->getOrientacion() ? cout<<"VER" : cout<<"HOR";
                cout<<endl;
                cout<<"Cambiar orientacion?"<<endl;
                cout<<"1. SI"<<endl;
                cout<<"2. NO"<<endl;
                do{
                    cin>>opcion;
                    incorrect = opcion > 2 || opcion < 1;
                    if (opcion == 1) b->change_orientacion();
                    if (incorrect) cout<<"Ingrese una opcion entre 1 y 2"<<endl;
                } while(incorrect);

            }
            placed = tablero->insert_barco(b, x, y);
            if (!placed) {
                cout << "Su barquito solapa con otro barco, o se va de la grilla" << endl;
                system("pause");
                system("cls");
            };

            tablero->mostrar();
            system("pause");
            system("cls");
        }while(!placed);


    }
    cout<<"=========="<<endl;
    cout<<"Su tablero final quedo: "<<endl;
    tablero->mostrar();
}

void Humano::attack(Tablero *enemigo) {
    system("cls");
    cout<<"HORA DE ATACAR"<<endl;
    for(int i = 0; i<enemigo->getAncho(); i++) cout<<"=";
    cout<<endl;
    enemigo->mostrar_enemigo();
    cout<<"Donde desea disparar?"<<endl;

    int x, y;
    bool incorrect;
    do{
        cout<<"X: "<<endl;
        cin>>x;
        incorrect = x < 0 || x >= enemigo->getAncho();
        if(incorrect){
            cout<<"El valor de x debe estar entre 0 y "<<enemigo->getAncho() - 1<<endl;
        }

    }while(incorrect);


    do{
        cout<<"Y: "<<endl;
        cin>>y;
        incorrect = y < 0 || y >= enemigo->getAltura();
        if(incorrect){
            cout<<"El valor de y debe estar entre 0 y "<<enemigo->getAltura() - 1<<endl;
        }
    }while(incorrect);

    enemigo->hit(x, y);

    system("cls");
    for(int i = 0; i<enemigo->getAncho(); i++) cout<<"=";
    cout<<endl;
    enemigo->mostrar_enemigo();
    system("pause");
}

Humano::Humano(string nombre, Tablero *tablero, vector<Barco*> barcos) : Jugador(nombre, tablero, barcos) {

}
