#pragma once

class Board {
public:
    Board();
    void print() const;
    bool makeMove(int row, int col, char symbol);
    bool checkWin(char symbol) const;
    bool isFull() const;
    void reset();
    char getWinner() const;
    int getMoves() const;
private:
    char cells[3][3];
    char winner;
    int moves;
};
