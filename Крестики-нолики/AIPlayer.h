#pragma once

#include "Player.h"
#include "Board.h"

class AIPlayer : public Player {
public:
    AIPlayer(char symbol = 'O');
    char getSymbol() const override;
    void makeMove(Board& board) const override;
private:
    char symbol;

    int minimax(Board& board, int depth, bool isMaximizing) const;
};
