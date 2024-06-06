#include "AIPlayer.h"
#include <algorithm> 

AIPlayer::AIPlayer(char symbol) : symbol(symbol) {}

char AIPlayer::getSymbol() const {
    return symbol;
}

void AIPlayer::makeMove(Board& board) const {
    int bestScore = -1000;
    int bestRow = -1;
    int bestCol = -1;

    for (int row = 0; row < 3; ++row) {
        for (int col = 0; col < 3; ++col) {
            if (board.makeMove(row, col, symbol)) {
                int score = minimax(board, 0, false);
                board.makeMove(row, col, ' '); 
                if (score > bestScore) {
                    bestScore = score;
                    bestRow = row;
                    bestCol = col;
                }
            }
        }
    }

    board.makeMove(bestRow, bestCol, symbol);
}

int AIPlayer::minimax(Board& board, int depth, bool isMaximizing) const {
    char opponentSymbol = (symbol == 'X') ? 'O' : 'X';

    if (board.checkWin(symbol)) {
        return 10 - depth;
    }
    if (board.checkWin(opponentSymbol)) {
        return depth - 10;
    }
    if (board.isFull()) {
        return 0;
    }

    if (isMaximizing) {
        int bestScore = -1000;
        for (int row = 0; row < 3; ++row) {
            for (int col = 0; col < 3; ++col) {
                if (board.makeMove(row, col, symbol)) {
                    int score = minimax(board, depth + 1, false);
                    board.makeMove(row, col, ' '); 
                    bestScore = std::max(bestScore, score);
                }
            }
        }
        return bestScore;
    }
    else {
        int bestScore = 1000;
        for (int row = 0; row < 3; ++row) {
            for (int col = 0; col < 3; ++col) {
                if (board.makeMove(row, col, opponentSymbol)) {
                    int score = minimax(board, depth + 1, true);
                    board.makeMove(row, col, ' '); 
                    bestScore = std::min(bestScore, score);
                }
            }
        }
        return bestScore;
    }
}
