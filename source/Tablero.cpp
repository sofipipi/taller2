#include "Tablero.h"
#include <vector>
#include <vector>
using namespace std;



class Tablero {
private:
    vector<vector<int>> matriz;          
    static Tablero* instancia;           

   
    Tablero();

public:
    // Eliminar constructor de copia y operador de asignación
    Tablero(const Tablero&) = delete;
    Tablero& operator=(const Tablero&) = delete;

  
    static Tablero* getInstancia();

    
    vector<vector<int>>& EntregarTablero();

  
    void imprimirTablero();
};

