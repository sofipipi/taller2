#include <iostream>
#include<string>
#include<vector>
#include <random>
#include <sstream>
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
    random_device rd; 
    mt19937 gen(rd()); 
    uniform_int_distribution<> distrib(1, 2);
    int numeroAleatorio = distrib(gen);
    if (opcion==1){
      
        cout<<"Este es el tablero actual"<<endl;
        cout<<tablero->imprimirTablero()<< endl;
        cout<<"                    "<<endl;
        cout<< "El jugador "<<numeroAleatorio<<" comienza"<<endl;
    }
}

