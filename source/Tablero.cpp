#include "Tablero.h"
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

// Inicialización de la instancia estática
Tablero* Tablero::instancia = nullptr;

Tablero::Tablero() {
    // Inicializar la matriz 3x3 con ceros (tablero vacío)
    matriz = vector<vector<int>>(3, vector<int>(3, 0));
}

Tablero* Tablero::getInstancia() {
    if (instancia == nullptr) {
        instancia = new Tablero();
    }
    return instancia;
}

vector<vector<int>>& Tablero::EntregarTablero() {
    return matriz;
}

string Tablero::imprimirTablero() {
    ostringstream tableroStr;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (matriz[i][j] == 0)
                tableroStr << ". "; // 0 es espacio vacío
            else if (matriz[i][j] == 1)
                tableroStr << "X "; // 1 es X
            else
                tableroStr << "O "; // 2 es O
        }
        tableroStr << "\n";
    }
    return tableroStr.str();
}


