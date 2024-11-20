#pragma once
#include<string>
#include <vector>
#include <sstream>
using namespace std;

class Tablero {
private:
    vector<vector<int>> matriz;        
    static Tablero* instancia;           

    // Constructor privado
    Tablero();

public:
    // Eliminar constructor de copia y operador de asignación
    Tablero(const Tablero&) = delete;
    Tablero& operator=(const Tablero&) = delete;

    // Método para obtener la instancia única de Tablero
    static Tablero* getInstancia();

    // Método para obtener la referencia a la matriz
    vector<vector<int>>& EntregarTablero();

    // Método para imprimir el tablero
    string imprimirTablero();
};



