#include "Tablero.h"

Tablero::Tablero() : tablero(size, std::vector<char>(size, ' ')) {}

void Tablero::display() const {
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            std::cout << tablero[i][j] << (j < size - 1 ? " | " : "");
        }
        std::cout << "\n";
        if (i < size - 1) std::cout << "---------\n";
    }
}

bool Tablero::isFull() const {
    for (const auto& row : tablero) {
        for (char cell : row) {
            if (cell == ' ') return false;
        }
    }
    return true;
}

bool Tablero::makeMove(int row, int col, char player) {
    if (row >= 0 && row < size && col >= 0 && col < size && tablero[row][col] == ' ') {
        tablero[row][col] = player;
        return true;
    }
    return false;
}

bool Tablero::checkWin(char player) const {

    for (int i = 0; i < size; ++i) {
        if ((tablero[i][0] == player && tablero[i][1] == player && tablero[i][2] == player) ||
            (tablero[0][i] == player && tablero[1][i] == player && tablero[2][i] == player)) {
            return true;
        }
    }

  
    return (tablero[0][0] == player && tablero[1][1] == player && tablero[2][2] == player) ||
           (tablero[0][2] == player && tablero[1][1] == player && tablero[2][0] == player);
}

std::vector<std::pair<int, int>> Tablero::getAvailableMoves() const {
    std::vector<std::pair<int, int>> moves;
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (tablero[i][j] == ' ') {
                moves.emplace_back(i, j);
            }
        }
    }
    return moves;
}

char Tablero::getCell(int row, int col) const {
    return tablero[row][col];
}

void Tablero::resetCell(int row, int col) {
    tablero[row][col] = ' ';
}


