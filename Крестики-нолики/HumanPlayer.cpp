#include "HumanPlayer.h"
#include <iostream>

HumanPlayer::HumanPlayer(char symbol) : symbol(symbol) {}

char HumanPlayer::getSymbol() const {
    return symbol;
}

void HumanPlayer::makeMove(Board& board) const {
    int row, col;
    std::cout << "������� ����� ������ (1-3) � ������� (1-3) ��� ������ ����: ";
    std::cin >> row >> col;
    row--; col--; 
    while (row < 0 || row > 2 || col < 0 || col > 2 || !board.makeMove(row, col, symbol)) {
        std::cout << "�������� ���������� ��� ������ ��� ������. ���������� ��� ���: ";
        std::cin >> row >> col;
        row--; col--;
    }
}
