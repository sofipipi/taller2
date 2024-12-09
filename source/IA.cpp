#include "IA.h"
using namespace std;
pair<int, int> IA::getBestMove(Tablero& board, char iaPlayer, char serVivo) {
    int bestScore = numeric_limits<int>::min();
    pair<int, int> bestMove = {-1, -1};

    for (const auto& move : board.getAvailableMoves()) {
        board.makeMove(move.first, move.second, iaPlayer);
        int score = minimax(board, 0, false, iaPlayer, serVivo, numeric_limits<int>::min(), numeric_limits<int>::max());
        board.resetCell(move.first, move.second);

        if (score > bestScore) {
            bestScore = score;
            bestMove = move;
        }
    }
    return bestMove;
}

int IA::minimax(Tablero& board, int depth, bool isMaximizing, char iaPlayer, char serSintiente, int alpha, int beta) {
    if (board.checkWin(iaPlayer)) return 10 - depth;
    if (board.checkWin(serSintiente)) return depth - 10;
    if (board.isFull()) return 0;

    if (isMaximizing) {
        int maxEval = std::numeric_limits<int>::min();
        for (const auto& move : board.getAvailableMoves()) {
            board.makeMove(move.first, move.second, iaPlayer);
            int eval = minimax(board, depth + 1, false, iaPlayer, serSintiente, alpha, beta);
            board.resetCell(move.first, move.second);
            maxEval = max(maxEval, eval);
            alpha = max(alpha, eval);
            if (beta <= alpha) break;
        }
        return maxEval;
    } else {
        int minEval = numeric_limits<int>::max();
        for (const auto& move : board.getAvailableMoves()) {
            board.makeMove(move.first, move.second, serSintiente);
            int eval = minimax(board, depth + 1, true, iaPlayer, serSintiente, alpha, beta);
            board.resetCell(move.first, move.second);
            minEval = min(minEval, eval);
            beta = min(beta, eval);
            if (beta <= alpha) break;
        }
        return minEval;
    }
}
