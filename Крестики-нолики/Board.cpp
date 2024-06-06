#include "Board.h"
#include <iostream>

Board::Board() : winner(' '), moves(0) {
    reset();
}

void Board::print() const {
    std::cout << "  1 2 3" << std::endl;
    for (int i = 0; i < 3; ++i) {
        std::cout << i + 1 << " ";
        for (int j = 0; j < 3; ++j) {
            if (j != 0) {
                std::cout << "|";
            }
            std::cout << " " << cells[i][j] << " ";
        }
        std::cout << std::endl;
        if (i != 2) {
            std::cout << "  -----" << std::endl;
        }
    }
}

bool Board::makeMove(int row, int col, char symbol) {
    if (cells[row][col] == ' ') {
        cells[row][col] = symbol;
        moves++;
        if (checkWin(symbol)) {
            winner = symbol;
        }
        return true;
    }
    return false;
}

bool Board::checkWin(char symbol) const {
    // Проверка строк
    for (int i = 0; i < 3; ++i) {
        if (cells[i][0] == symbol && cells[i][1] == symbol && cells[i][2] == symbol) {
            return true;
        }
    }

    // Проверка столбцов
    for (int j = 0; j < 3; ++j) {
        if (cells[0][j] == symbol && cells[1][j] == symbol && cells[2][j] == symbol) {
            return true;
        }
    }

    // Проверка диагоналей
    if (cells[0][0] == symbol && cells[1][1] == symbol && cells[2][2] == symbol) {
        return true;
    }
    if (cells[0][2] == symbol && cells[1][1] == symbol && cells[2][0] == symbol) {
        return true;
    }

    return false;
}

bool Board::isFull() const {
    return moves == 9;
}

void Board::reset() {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cells[i][j] = ' ';
        }
    }
    winner = ' ';
    moves = 0;
}

char Board::getWinner() const {
    return winner;
}

int Board::getMoves() const {
    return moves;
}
