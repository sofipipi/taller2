#pragma once

#define BOARD_H

#include <vector>
#include <iostream>
using namespace std;

class Tablero {
private:
    vector<std::vector<char>> tablero;
    static const int size = 3;

public:
    Tablero();
    void display() const;
    bool isFull() const;
    bool makeMove(int row, int col, char player);
    bool checkWin(char player) const;
    vector<pair<int, int>> getAvailableMoves() const;
    char getCell(int row, int col) const;
    void resetCell(int row, int col);
};




