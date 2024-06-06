#include "HumanPlayer.h"
#include <iostream>

HumanPlayer::HumanPlayer(char symbol) : symbol(symbol) {}

char HumanPlayer::getSymbol() const {
    return symbol;
}

void HumanPlayer::makeMove(Board& board) const {
    int row, col;
    std::cout << "Введите номер строки (1-3) и столбца (1-3) для вашего хода: ";
    std::cin >> row >> col;
    row--; col--; 
    while (row < 0 || row > 2 || col < 0 || col > 2 || !board.makeMove(row, col, symbol)) {
        std::cout << "Неверные координаты или клетка уже занята. Попробуйте еще раз: ";
        std::cin >> row >> col;
        row--; col--;
    }
}
