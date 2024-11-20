#pragma once
#include<string>
#include <vector>
using namespace std;

class Tablero {
private:
    vector<vector<int>> matriz;        
    static Tablero* instancia;           

    Tablero();

public:
  
    Tablero(const Tablero&) = delete;
    Tablero& operator=(const Tablero&) = delete;

   
    static Tablero* getInstancia();

    
    vector<vector<int>>& EntregarTablero();

   
    void imprimirTablero();
};


