#include <iostream>
#include<string>
#include<vector>
#include "Tablero.h"
using namespace std;

void menu(Tablero* tablero);

int main(){
    cout<<"hola"<<endl;
    Tablero* t = Tablero::getInstancia();
    menu(t);
    return 0;
}

void menu(Tablero* tablero){
    int opcion=0;
    cout<<" Bienvenidos a: TU contra LA MAQUINA"<<endl;
    cout<< "El juego que se realiza es GATO, TRES EN LINEA o TIPTOE"<<endl;
    cout<< " (1) Empezar  (2) Salir"<<endl;
    cin>>opcion;
    if (opcion==1){
        tablero->imprimirTablero();
    }
}

