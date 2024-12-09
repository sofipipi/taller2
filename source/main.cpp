#include "Tablero.h"
#include "IA.h"
using namespace std;
int main() {
    Tablero board;
    IA ia;
    char humanPlayer = 'X', aiPlayer = 'O';
    bool isHumanTurn = true;

    cout << "Juego del gato \n";
    board.display();

    while (!board.isFull() && !board.checkWin(humanPlayer) && !board.checkWin(aiPlayer)) {
        if (isHumanTurn) {
            int row, col;
            cout << "Tu turno (X). Ingresa fila y columna con una separacion entre cada uno (1 2): ";
            cin >> row >> col;

            if (!board.makeMove(row, col, humanPlayer)) {
                cout << "Movimiento inválido. Intenta de nuevo.\n";
                continue;
            }

        if (cin.fail() || row < 0 || row > 2 || col < 0 || col > 2 || !board.makeMove(row, col, humanPlayer)) {
            cin.clear();
            cin.ignore(numeric_limits<std::streamsize>::max(), '\n'); 
            cout << "Entrada inválida. Intenta de nuevo.\n";
        } else {
            break; 
        }
        } else {
            cout << "Turno de la IA (O)...\n";
            auto bestMove = ia.getBestMove(board, aiPlayer, humanPlayer);
            board.makeMove(bestMove.first, bestMove.second, aiPlayer);
        }

        board.display();
        isHumanTurn = !isHumanTurn;
    }

    if (board.checkWin(humanPlayer)) {
        cout << "¡Ganaste!\n";
    } else if (board.checkWin(aiPlayer)) {
        cout << "¡La IA ganó!\n";
    } else {
        cout << "Es un empate.\n";
    }

    return 0;
}


