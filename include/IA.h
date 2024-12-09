#pragma once

#include "Tablero.h"
#include <limits>
using namespace std;
class IA {
public:
    pair<int, int> getBestMove(Tablero& board, char iaPlayer, char humanPlayer);

private:
    int minimax(Tablero& board, int depth, bool isMaximizing, char iaPlayer, char humanPlayer, int alpha, int beta);
};


